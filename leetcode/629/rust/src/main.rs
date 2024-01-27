pub fn k_inverse_pairs(n: i32, k: i32) -> i32 {
    let k = k as usize;
    let n = n as usize;

    let mut dp = vec![vec![0; k + 1]; n + 1];
    dp[0][0] = 1;
    let mm = 10i32.pow(9) + 7;
    for i in 1..=n {
        let c = i * (i - 1) / 2;
        for j in 0..=std::cmp::min(c, k) {
            for p in 0..=std::cmp::min(i - 1, j) {
                // println!("{} {} {} {:?}", i, j, p, dp);
                dp[i][j] = (dp[i][j] + dp[i - 1][j - p]) % mm;
            }
        }
    }
    // println!("{:?}", dp);
    dp[n][k]
}

fn main() {
    println!("{}", k_inverse_pairs(3, 1));
}
