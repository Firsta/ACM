use std::cmp::Ordering;
use std::collections::BinaryHeap;

#[derive(Copy, Clone, Eq, PartialEq)]
struct State {
    cost: usize,
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
        other
            .cost
            .cmp(&self.cost)
            .then_with(|| self.position.cmp(&other.position))
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
    cost: usize,
}

// Dijkstra's shortest path algorithm.

// Start at `start` and use `dist` to track the current shortest distance
// to each node. This implementation isn't memory-efficient as it may leave duplicate
// nodes in the queue. It also uses `usize::MAX` as a sentinel value,
// for a simpler implementation.
fn shortest_path(edges: &[Vec<i32>], n: usize, start: usize, goal: usize) -> Option<usize> {
    let mut adj_list = vec![Vec::<Edge>::new(); n];

    for e in edges.iter() {
        if e[2] != -1 {
            adj_list[e[0] as usize].push(Edge {
                node: e[1] as usize,
                cost: e[2] as usize,
            });

            adj_list[e[1] as usize].push(Edge {
                node: e[0] as usize,
                cost: e[2] as usize,
            });
        }
    }

    // dist[node] = current shortest distance from `start` to `node`
    let mut dist: Vec<_> = (0..adj_list.len()).map(|_| usize::MAX).collect();

    let mut heap = BinaryHeap::new();

    // We're at `start`, with a zero cost
    dist[start] = 0;
    heap.push(State {
        cost: 0,
        position: start,
    });

    // Examine the frontier with lower cost nodes first (min-heap)
    while let Some(State { cost, position }) = heap.pop() {
        // Alternatively we could have continued to find all shortest paths
        if position == goal {
            return Some(cost);
        }

        // Important as we may have already found a better way
        if cost > dist[position] {
            continue;
        }

        // For each node we can reach, see if we can find a way with
        // a lower cost going through this node
        for edge in &adj_list[position] {
            let next = State {
                cost: cost + edge.cost,
                position: edge.node,
            };

            // If so, add it to the frontier and continue
            if next.cost < dist[next.position] {
                heap.push(next);
                // Relaxation, we have now found a better way
                dist[next.position] = next.cost;
            }
        }
    }

    // Goal not reachable
    None
}

pub fn modified_graph_edges(
    n: i32,
    edges: Vec<Vec<i32>>,
    source: i32,
    destination: i32,
    target: i32,
) -> Vec<Vec<i32>> {
    let n = n as usize;
    let start = source as usize;
    let goal = destination as usize;

    let p = shortest_path(&edges, n, start, goal);

    let target = target as usize;

    if p.is_some() && p.unwrap() < target {
        return Vec::new();
    }

    let mut ok = false;

    if p.is_some() && p.unwrap() == target {
        ok = true;
    }

    let mut edges = edges;

    for i in 0..edges.len() {
        if edges[i][2] == -1 {
            if ok {
                edges[i][2] = std::i32::MAX / 2;
            } else {
                edges[i][2] = 1;
                let p = shortest_path(&edges, n, start, goal);
                if p.is_some() && p.unwrap() <= target {
                    edges[i][2] += (target - p.unwrap()) as i32;
                    ok = true;
                }
            }
        }
    }

    if ok {
        edges
    } else {
        Vec::new()
    }
}

fn main() {
    let edges = modified_graph_edges(
        5,
        vec![
            vec![1, 4, 1],
            vec![2, 4, -1],
            vec![3, 0, 2],
            vec![0, 4, -1],
            vec![1, 3, 10],
            vec![1, 0, 10],
        ],
        0,
        2,
        15,
    );
    assert_eq!(shortest_path(&edges, 5, 0, 2), Some(15));
}
