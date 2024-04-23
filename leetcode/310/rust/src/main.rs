use std::collections::VecDeque;

pub fn find_min_height_trees(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
    let n = n as usize;

    if n == 1 {
        return vec![0];
    }

    let mut graph: Vec<Vec<usize>> = vec![Vec::new(); n];
    let mut ind = vec![0; n];

    for edge in edges.into_iter() {
        let (a, b) = (edge[0] as usize, edge[1] as usize);

        ind[a] += 1;
        ind[b] += 1;

        graph[a].push(b);
        graph[b].push(a);
    }

    let mut q = VecDeque::new();
    for i in 0..n {
        if ind[i] == 1 {
            q.push_back(i);
        }
    }

    let mut removed = 0;
    while n - removed > 2 {
        let len = q.len();
        removed += len;
        for _ in 0..len {
            let top = q.pop_front().unwrap();
            for adj in graph[top].iter() {
                ind[*adj] -= 1;
                if ind[*adj] == 1 {
                    q.push_back(*adj);
                }
            }
        }
    }

    q.into_iter().map(|x| x as i32).collect::<Vec<i32>>()
}

fn main() {
    assert_eq!(
        find_min_height_trees(4, vec![vec![1, 0], vec![1, 2], vec![1, 3]]),
        vec![1]
    );
    assert_eq!(
        find_min_height_trees(
            6,
            vec![vec![3, 0], vec![3, 1], vec![3, 2], vec![3, 4], vec![5, 4]]
        ),
        vec![3, 4]
    );
    assert_eq!(find_min_height_trees(1, vec![]), vec![0]);
    assert_eq!(find_min_height_trees(2, vec![vec![0, 1]]), vec![0, 1]);
}
