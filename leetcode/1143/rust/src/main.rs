use std::cmp::max;

pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
    let m = text1.len();
    let n = text2.len();
    let mut dp = vec![vec![0; n + 1]; m + 1];
    for i in 1..m + 1 {
        for j in 1..n + 1 {
            // println!("{} {} {:?} ", i, j, dp);
            let c1 = text1.as_bytes()[i - 1] as char;
            let c2 = text2.as_bytes()[j - 1] as char;
            let mut t = dp[i - 1][j - 1];
            if c1 == c2 {
                t += 1
            }

            dp[i][j] = max(dp[i][j - 1], max(dp[i - 1][j], t));
        }
    }
    dp[m][n]
}

fn main() {
    println!(
        "{}",
        longest_common_subsequence("abcde".to_string(), "ace".to_string())
    );
}
