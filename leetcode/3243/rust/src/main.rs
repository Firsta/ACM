use std::collections::VecDeque;

pub fn shortest_distance_after_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
    let n = n as usize;
    let mut dp = Vec::new();
    let mut g = Vec::new();

    for i in 0..n {
        dp.push(i);
        if i != n - 1 {
            g.push(vec![i + 1]);
        } else {
            g.push(Vec::new());
        }
    }

    let mut ans = Vec::new();
    for query in queries {
        g[query[0] as usize].push(query[1] as usize);
        let mut q = VecDeque::new();
        q.push_back(query[0] as usize);
        while !q.is_empty() {
            // println!("{:?}", q);
            let t = q.pop_front().unwrap();
            for &n in g[t].iter() {
                if dp[t] + 1 < dp[n] {
                    dp[n] = dp[t] + 1;
                    q.push_back(n);
                }
            }
        }
        ans.push(dp[n - 1]);
    }

    ans.into_iter().map(|x| x as i32).collect()
}

fn main() {
    assert_eq!(
        shortest_distance_after_queries(5, vec![vec![2, 4], vec![0, 2], vec![0, 4]]),
        vec![3, 2, 1]
    );
    assert_eq!(
        shortest_distance_after_queries(4, vec![vec![0, 3], vec![0, 2]]),
        vec![1, 1]
    );
}
