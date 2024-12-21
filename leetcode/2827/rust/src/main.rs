pub fn max_k_divisible_components(n: i32, edges: Vec<Vec<i32>>, values: Vec<i32>, k: i32) -> i32 {
    let n = n as usize;
    if n == 1 {
        return 1;
    }
    let mut g = vec![std::collections::HashSet::<usize>::new(); n];
    for e in edges {
        g[e[0] as usize].insert(e[1] as usize);
        g[e[1] as usize].insert(e[0] as usize);
    }
    let mut leafs = Vec::new();
    for (idx, gg) in g.iter().enumerate() {
        if gg.len() == 1 && idx != 0 {
            leafs.push(idx);
        }
    }
    let mut ans = 0;
    let mut values: Vec<i64> = values.into_iter().map(|x| x as i64).collect();
    while !leafs.is_empty() {
        let leaf = leafs.pop().unwrap();
        let mut parent = 0;
        for p in g[leaf].iter() {
            parent = *p;
        }
        if values[leaf] % k as i64 == 0 {
            ans += 1;
        } else {
            values[parent] += values[leaf];
        }
        g[parent].remove(&leaf);
        if g[parent].len() == 1 && parent != 0 {
            leafs.push(parent);
        }
    }

    ans + 1
}

fn main() {
    assert_eq!(
        max_k_divisible_components(
            5,
            vec![vec![0, 2], vec![1, 2], vec![1, 3], vec![2, 4]],
            vec![1, 8, 1, 4, 4],
            6
        ),
        2
    );
    assert_eq!(
        max_k_divisible_components(
            7,
            vec![
                vec![0, 1],
                vec![0, 2],
                vec![1, 3],
                vec![1, 4],
                vec![2, 5],
                vec![2, 6]
            ],
            vec![3, 0, 6, 1, 5, 2, 1],
            3,
        ),
        3
    );
    assert_eq!(
        max_k_divisible_components(
            7,
            vec![
                vec![0, 1],
                vec![0, 2],
                vec![1, 3],
                vec![1, 4],
                vec![2, 5],
                vec![2, 6]
            ],
            vec![
                1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000
            ],
            7
        ),
        1
    );
}
