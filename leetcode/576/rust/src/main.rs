pub fn find_paths(m: i32, n: i32, max_move: i32, start_row: i32, start_column: i32) -> i32 {
    let m = m as usize;
    let n = n as usize;
    let max_move = max_move as usize;
    let start_row = start_row as usize;
    let start_column = start_column as usize;

    let mm = 10i32.pow(9) + 7;

    let mut dp = vec![vec![vec![0; n + 2]; m + 2]; max_move + 1];
    for i in 1..=n {
        dp[0][0][i] = 1;
        dp[0][m + 1][i] = 1;
    }
    for i in 1..=m {
        dp[0][i][0] = 1;
        dp[0][i][n + 1] = 1;
    }
    for i in 1..=max_move {
        for j in 1..=m {
            for k in 1..=n {
                dp[i][j][k] = dp[i - 1][j - 1][k];
                dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % mm;
                dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j + 1][k]) % mm;
                dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k + 1]) % mm;
            }
        }
    }
    /*
    for i in 0..=max_move {
        println!("-------");
        println!("{:?}", dp[i]);
    }
    */

    let mut result = 0;
    for i in 1..=max_move {
        result = (result + dp[i][start_row + 1][start_column + 1]) % mm;
    }
    result
}

fn main() {
    println!("{}", find_paths(1, 3, 3, 0, 1));
}
