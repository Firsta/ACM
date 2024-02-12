use std::cmp::max;

pub fn cherry_pickup(grid: Vec<Vec<i32>>) -> i32 {
    let n = grid.len();
    let m = grid[0].len();

    let mut dp = vec![vec![vec![-1; m]; m]; 2];

    dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1];

    for i in 0..n - 1 {
        for j in 0..m {
            for k in 0..m {
                if dp[i % 2][j][k] != -1 {
                    // println!("{} {} {} {}", i, j, k, dp[i][j][k]);

                    let jl = if j == 0 { 0 } else { j - 1 };
                    let ju = if j == m - 1 { m - 1 } else { j + 1 };

                    let kl = if k == 0 { 0 } else { k - 1 };
                    let ku = if k == m - 1 { m - 1 } else { k + 1 };

                    for jj in jl..=ju {
                        for kk in kl..=ku {
                            // println!("{} {}", jj, kk);
                            let plus = if jj == kk {
                                grid[i + 1][jj]
                            } else {
                                grid[i + 1][jj] + grid[i + 1][kk]
                            };
                            dp[(i + 1) % 2][jj][kk] =
                                max(dp[(i + 1) % 2][jj][kk], dp[i % 2][j][k] + plus);
                            // println!("{} {} {} {}", i + 1, jj, kk, dp[i + 1][jj][kk]);
                        }
                    }
                }
            }
        }
    }

    let mut result = -1;
    for j in 0..m {
        for k in 0..m {
            if dp[(n - 1) % 2][j][k] > result {
                result = dp[(n - 1) % 2][j][k];
            }
        }
    }
    result
}

fn main() {
    println!(
        "{}",
        cherry_pickup(vec![
            vec![3, 1, 1],
            vec![2, 5, 1],
            vec![1, 5, 5],
            vec![2, 1, 1]
        ])
    );
}
