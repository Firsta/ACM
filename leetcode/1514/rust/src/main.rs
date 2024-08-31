use std::cmp::Ordering;
use std::collections::BinaryHeap;

#[derive(PartialOrd, PartialEq, Copy, Clone)]
struct MyF64(f64);

impl Eq for MyF64 {}

/* impl Ord for MyF64 {
    fn cmp(&self, other: &Self) -> Ordering {
        if let Some(ordering) = self.partial_cmp(other) {
            ordering
        } else {
            // Choose what to do with NaNs, for example:
            Ordering::Less
        }
    }
}
 */

#[derive(Copy, Clone, Eq, PartialEq)]
struct State {
    prob: MyF64,
    position: usize,
}

// The priority queue depends on `Ord`.
// Explicitly implement the trait so the queue becomes a min-heap
// instead of a max-heap.
impl Ord for State {
    fn cmp(&self, other: &Self) -> Ordering {
        // Notice that we flip the ordering on costs.
        // In case of a tie we compare positions - this step is necessary
        // to make implementations of `PartialEq` and `Ord` consistent.
        self.prob.partial_cmp(&other.prob).unwrap()
    }
}

// `PartialOrd` needs to be implemented as well.
impl PartialOrd for State {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

// Each node is represented as a `usize`, for a shorter implementation.
#[derive(Clone)]
struct Edge {
    node: usize,
    prob: f64,
}

// Dijkstra's shortest path algorithm.

// Start at `start` and use `dist` to track the current shortest distance
// to each node. This implementation isn't memory-efficient as it may leave duplicate
// nodes in the queue. It also uses `usize::MAX` as a sentinel value,
// for a simpler implementation.
fn shortest_path(adj_list: &Vec<Vec<Edge>>, start: usize, goal: usize) -> Option<f64> {
    // dist[node] = current shortest distance from `start` to `node`
    let mut dist: Vec<_> = (0..adj_list.len()).map(|_| 0.0).collect();

    let mut heap = BinaryHeap::new();

    // We're at `start`, with a zero cost
    dist[start] = 0.0;
    heap.push(State {
        prob: MyF64(1.0),
        position: start,
    });

    // Examine the frontier with lower cost nodes first (min-heap)
    while let Some(State { prob, position }) = heap.pop() {
        // Alternatively we could have continued to find all shortest paths
        if position == goal {
            return Some(prob.0);
        }

        // Important as we may have already found a better way
        if prob.0 < dist[position] {
            continue;
        }

        // For each node we can reach, see if we can find a way with
        // a lower cost going through this node
        for edge in &adj_list[position] {
            let next = State {
                prob: MyF64(prob.0 * edge.prob),
                position: edge.node,
            };

            // If so, add it to the frontier and continue
            if next.prob.0 > dist[next.position] {
                heap.push(next);
                // Relaxation, we have now found a better way
                dist[next.position] = next.prob.0;
            }
        }
    }

    // Goal not reachable
    None
}

pub fn max_probability(
    n: i32,
    edges: Vec<Vec<i32>>,
    succ_prob: Vec<f64>,
    start_node: i32,
    end_node: i32,
) -> f64 {
    let n = n as usize;
    let mut es = vec![Vec::<Edge>::new(); n];
    for i in 0..edges.len() {
        es[edges[i][0] as usize].push(Edge {
            node: edges[i][1] as usize,
            prob: succ_prob[i],
        });
        es[edges[i][1] as usize].push(Edge {
            node: edges[i][0] as usize,
            prob: succ_prob[i],
        });
    }
    shortest_path(&es, start_node as usize, end_node as usize).unwrap_or_default()
}

fn main() {
    assert!(
        (max_probability(
            3,
            vec![vec![0, 1], vec![1, 2], vec![0, 2]],
            vec![0.5, 0.5, 0.2],
            0,
            2
        ) - 0.25)
            .abs()
            < 0.00001
    );
    assert!(
        (max_probability(
            3,
            vec![vec![0, 1], vec![1, 2], vec![0, 2]],
            vec![0.5, 0.5, 0.3],
            0,
            2
        ) - 0.3)
            .abs()
            < 0.00001
    );
    assert!((max_probability(3, vec![vec![0, 1]], vec![0.5], 0, 2) - 0.0).abs() < 0.00001);
}
