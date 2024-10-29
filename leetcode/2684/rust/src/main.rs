pub fn max_moves(grid: Vec<Vec<i32>>) -> i32 {
    let m = grid.len();
    let n = grid[0].len();
    let mut dp = vec![vec![None; n]; m];
    for i in 0..m {
        dp[i][0] = Some(0);
    }
    for j in 1..n {
        for i in 0..m {
            for d in [-1, 0, 1] {
                let t = i as i32 + d;
                if 0 <= t && t < m as i32 {
                    if let Some(pre) = dp[t as usize][j - 1] {
                        if grid[t as usize][j - 1] < grid[i][j] {
                            match dp[i][j] {
                                None => dp[i][j] = Some(pre + 1),
                                Some(c) => {
                                    if c < pre + 1 {
                                        dp[i][j] = Some(pre + 1);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    let mut ans = 0;
    for i in 0..m {
        for j in 0..n {
            if let Some(x) = dp[i][j] {
                ans = std::cmp::max(ans, x);
            }
        }
    }
    ans
}

fn main() {
    assert_eq!(
        max_moves(vec![
            vec![187, 167, 209, 251, 152, 236, 263, 128, 135],
            vec![267, 249, 251, 285, 73, 204, 70, 207, 74],
            vec![189, 159, 235, 66, 84, 89, 153, 111, 189],
            vec![120, 81, 210, 7, 2, 231, 92, 128, 218],
            vec![193, 131, 244, 293, 284, 175, 226, 205, 245]
        ]),
        3
    );
}
