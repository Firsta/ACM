pub fn find_the_city(n: i32, edges: Vec<Vec<i32>>, distance_threshold: i32) -> i32 {
    let n = n as usize;
    let mut dp = vec![vec![vec![None; n + 1]; n + 1]; n + 1];
    for e in edges.into_iter() {
        let a = (e[0] + 1) as usize;
        let b = (e[1] + 1) as usize;

        dp[0][a][b] = Some(e[2]);
        dp[0][b][a] = Some(e[2]);
    }

    for i in 1..=n {
        dp[0][i][i] = Some(0);
    }

    // println!("{:?}", dp[0]);

    for k in 1..=n {
        for i in 1..=n {
            for j in 1..=n {
                dp[k][i][j] = dp[k - 1][i][j];

                let pa = dp[k - 1][i][k];
                let pb = dp[k - 1][k][j];

                if pa.is_some() && pb.is_some() {
                    let np = pa.unwrap() + pb.unwrap();
                    let v = match dp[k][i][j] {
                        None => Some(np),
                        Some(op) => Some(std::cmp::min(op, np)),
                    };
                    dp[k][i][j] = v;
                }
            }
        }
        // println!("{:?}", dp[k]);
    }

    // println!("{:?}", dp[n]);

    let mut ans = n + 1;
    let mut mmin = n + 1;
    for i in (1..=n).rev() {
        let mut ok = 0;
        for j in 1..=n {
            if dp[n][i][j].is_some() && dp[n][i][j].unwrap() <= distance_threshold {
                ok += 1;
            }
        }

        if ok < mmin {
            mmin = ok;
            ans = i - 1;
        }
    }

    ans as i32
}

fn main() {
    assert_eq!(
        find_the_city(
            4,
            vec![vec![0, 1, 3], vec![1, 2, 1], vec![1, 3, 4], vec![2, 3, 1]],
            4
        ),
        3
    );
}
