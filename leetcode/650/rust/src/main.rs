pub fn min_steps(n: i32) -> i32 {
    fn dfs(n: i32, dp: &mut Vec<i32>) -> i32 {
        if dp[n as usize] != -1 {
            dp[n as usize]
        } else {
            dp[n as usize] = n;
            for i in 2..n {
                if n % i == 0 {
                    dp[n as usize] = std::cmp::min(dp[n as usize], dfs(i, dp) + n / i);
                }
            }
            dp[n as usize]
        }
    }

    let mut dp = vec![-1; n as usize + 1];
    dp[1] = 0;
    let ans = dfs(n, &mut dp);
    ans
}

fn main() {
    assert_eq!(min_steps(999), 46);
}
