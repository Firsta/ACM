pub fn min_falling_path_sum(grid: Vec<Vec<i32>>) -> i32 {
    let m = grid.len();
    let n = grid[0].len();

    let mut dp = vec![vec![std::i32::MAX; n]; 2];

    for i in 0..n {
        dp[0][i] = grid[0][i];
    }

    for i in 1..m {
        for j in 0..n {
            dp[i % 2][j] = std::i32::MAX;
        }
        for j in 0..n {
            for k in 0..n {
                if k != j {
                    dp[i % 2][j] = std::cmp::min(dp[i % 2][j], dp[(i - 1) % 2][k] + grid[i][j]);
                }
            }
        }
    }

    *dp[(m - 1) % 2].iter().min().unwrap()
}

fn main() {
    assert_eq!(
        min_falling_path_sum(vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]]),
        13
    );
    assert_eq!(min_falling_path_sum(vec![vec![7]]), 7);
}
