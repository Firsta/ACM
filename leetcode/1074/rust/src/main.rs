pub fn num_submatrix_sum_target(matrix: Vec<Vec<i32>>, target: i32) -> i32 {
    let m = matrix.len();
    let n = matrix[0].len();
    let mut dp = vec![vec![vec![vec![0; n + 1]; m + 1]; n + 1]; m + 1];
    let mut result = 0;

    // println!("{} {}", m, n);
    /*
    for x in 1..=m {
        for y in 1..=n {
            dp[x][y][x][y] = matrix[x - 1][y - 1];
        }
    }
    */

    for x in 1..=m {
        for y2 in 1..=n {
            dp[x][1][x][y2] = dp[x][1][x][y2 - 1] + matrix[x - 1][y2 - 1];
        }
    }

    for y in 1..=n {
        for x2 in 1..=m {
            dp[1][y][x2][y] = dp[1][y][x2 - 1][y] + matrix[x2 - 1][y - 1];
        }
    }

    for x2 in 1..=m {
        for y2 in 1..=n {
            dp[1][1][x2][y2] = dp[1][1][x2 - 1][y2 - 1] + dp[1][y2][x2][y2] + dp[x2][1][x2][y2]
                - matrix[x2 - 1][y2 - 1];
        }
    }

    for x1 in 1..=m {
        for y1 in 1..=n {
            for x2 in x1..=m {
                for y2 in y1..=n {
                    let t = dp[1][1][x2][y2] - dp[1][1][x1 - 1][y2] - dp[1][1][x2][y1 - 1]
                        + dp[1][1][x1 - 1][y1 - 1];
                    if t == target {
                        result += 1;
                    }
                }
            }
        }
    }
    result
}

fn main() {
    println!(
        "{}",
        num_submatrix_sum_target(vec![vec![1, -1], vec![-1, 1]], 0)
    );
}
