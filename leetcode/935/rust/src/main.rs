pub fn knight_dialer(n: i32) -> i32 {
    let mut dp = [1; 10];
    let m = 7 + i32::pow(10, 9);
    // println!("{:?}", dp);
    for _i in 0..n - 1 {
        dp = [
            (dp[4] + dp[6]) % m,
            (dp[6] + dp[8]) % m,
            (dp[7] + dp[9]) % m,
            (dp[4] + dp[8]) % m,
            ((dp[0] + dp[3]) % m + dp[9]) % m,
            0,
            ((dp[0] + dp[1]) % m + dp[7]) % m,
            (dp[2] + dp[6]) % m,
            (dp[1] + dp[3]) % m,
            (dp[2] + dp[4]) % m,
        ];
    }
    // println!("{:?}", dp);
    dp.into_iter().reduce(|a, b| (a + b) % m).unwrap()
}

fn main() {
    println!("{}", knight_dialer(3131));
}

