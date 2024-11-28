use std::cmp::Ordering;
use std::collections::BinaryHeap;

#[derive(Copy, Clone, Eq, PartialEq)]
struct State {
    cost: usize,
    position: (usize, usize),
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

// Dijkstra's shortest path algorithm.

// Start at `start` and use `dist` to track the current shortest distance
// to each node. This implementation isn't memory-efficient as it may leave duplicate
// nodes in the queue. It also uses `usize::MAX` as a sentinel value,
// for a simpler implementation.
fn shortest_path(grid: &Vec<Vec<i32>>) -> Option<usize> {
    // dist[node] = current shortest distance from `start` to `node`
    let m = grid.len();
    let n = grid[0].len();
    let mut dist = vec![vec![usize::MAX; n]; m];

    let mut heap = BinaryHeap::new();

    // We're at `start`, with a zero cost
    dist[0][0] = 0;
    heap.push(State {
        cost: 0,
        position: (0, 0),
    });

    // Examine the frontier with lower cost nodes first (min-heap)
    while let Some(State { cost, position }) = heap.pop() {
        // Alternatively we could have continued to find all shortest paths
        if position == (m - 1, n - 1) {
            return Some(cost);
        }

        // Important as we may have already found a better way
        if cost > dist[position.0][position.1] {
            continue;
        }

        // For each node we can reach, see if we can find a way with
        // a lower cost going through this node
        for (dx, dy) in [(0, 1), (0, -1), (1, 0), (-1, 0)] {
            let nx = dx + position.0 as i32;
            let ny = dy + position.1 as i32;
            if 0 <= nx && nx < m as i32 && 0 <= ny && ny < n as i32 {
                let next = State {
                    cost: cost + grid[nx as usize][ny as usize] as usize,
                    position: (nx as usize, ny as usize),
                };
                if next.cost < dist[nx as usize][ny as usize] {
                    heap.push(next);
                    // Relaxation, we have now found a better way
                    dist[nx as usize][ny as usize] = next.cost;
                }
            }
        }
    }

    // Goal not reachable
    None
}

pub fn minimum_obstacles(grid: Vec<Vec<i32>>) -> i32 {
    shortest_path(&grid).unwrap() as i32
}

fn main() {
    assert_eq!(
        minimum_obstacles(vec![vec![0, 1, 1], vec![1, 1, 0], vec![1, 1, 0]]),
        2
    );
    assert_eq!(
        minimum_obstacles(vec![
            vec![0, 1, 0, 0, 0],
            vec![0, 1, 0, 1, 0],
            vec![0, 0, 0, 1, 0]
        ]),
        0
    );
}
