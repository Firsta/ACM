pub fn magnificent_sets(n: i32, edges: Vec<Vec<i32>>) -> i32 {
    let n = n as usize;
    let mut g = vec![Vec::<usize>::new(); n + 1];
    for e in edges {
        g[e[0] as usize].push(e[1] as usize);
        g[e[1] as usize].push(e[0] as usize);
    }
    fn dfs(cur: usize, g: &Vec<Vec<usize>>, done: &mut Vec<bool>, group: &mut Vec<usize>) {
        group.push(cur);
        done[cur] = true;
        for &next in g[cur].iter() {
            if !done[next] {
                dfs(next, g, done, group);
            }
        }
    }
    let mut done = vec![false; n + 1];

    let mut ans = 0;
    for i in 1..=n {
        if !done[i] {
            let mut group = Vec::new();
            dfs(i, &g, &mut done, &mut group);
            // println!("{:?}", group);
            let mut max_divide = 0;
            for &start in group.iter() {
                let mut q = std::collections::VecDeque::new();
                let mut color_cnt = 1;
                q.push_back((start, 1));
                let mut colors = vec![None; n + 1];
                colors[start] = Some(1);

                // println!("start: {}", start);
                while !q.is_empty() {
                    let (p, color) = q.pop_front().unwrap();
                    // println!("{} {}", p, color);

                    for &next in g[p].iter() {
                        // println!("{}", next);
                        match colors[next] {
                            None => {
                                colors[next] = Some(color + 1);
                                color_cnt = std::cmp::max(color_cnt, color + 1);
                                q.push_back((next, color + 1));
                            }
                            Some(next_color) => {
                                // println!("{} {}", next, next_color);

                                if next_color != color - 1 && next_color != color + 1 {
                                    return -1;
                                }
                            }
                        }
                    }
                }
                max_divide = std::cmp::max(max_divide, color_cnt);
            }
            ans += max_divide;
        }
    }

    ans
}

fn main() {
    assert_eq!(
        magnificent_sets(
            6,
            vec![
                vec![1, 2],
                vec![1, 4],
                vec![1, 5],
                vec![2, 6],
                vec![2, 3],
                vec![4, 6]
            ]
        ),
        4
    );

    assert_eq!(
        magnificent_sets(3, vec![vec![1, 2], vec![2, 3], vec![3, 1]]),
        -1
    );
}
