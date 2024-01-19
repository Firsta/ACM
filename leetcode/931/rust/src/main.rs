use std::cmp::min;

pub fn min_falling_path_sum(matrix: Vec<Vec<i32>>) -> i32 {
    let n = matrix.len();
    let m = matrix[0].len();
    let mut dp = Vec::new();
    for i in 0..n {
        dp.push(vec![0; m]);
        for j in 0..m {
            if i == 0 {
                dp[i][j] = matrix[i][j];
            } else {
                dp[i][j] = dp[i - 1][j];
                if j > 0 {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }

                if j < m - 1 {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
                }

                dp[i][j] += matrix[i][j];
            }
        }
    }

    *dp[n - 1].iter().min().unwrap()
}

fn main() {
    println!(
        "{}",
        min_falling_path_sum(vec![vec![-19, 57], vec![-40, -5]])
    );
}
