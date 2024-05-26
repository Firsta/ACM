const M: i32 = 10i32.pow(9) + 7;

pub fn check_record(n: i32) -> i32 {
    if n == 1 {
        return 3;
    } else if n == 2 {
        return 8;
    }
    let n = n as usize;

    let mut dp = vec![vec![vec![0; 3]; 2]; 2];

    dp[0][1][0] = 3;
    dp[0][1][1] = 1;
    dp[0][1][2] = 0;
    dp[0][0][0] = 2;
    dp[0][0][1] = 1;
    dp[0][0][2] = 1;

    for i in 3..=n {
        let now = i % 2;
        let last = 1 - now;
        dp[now][0][0] = ((dp[last][0][0] + dp[last][0][1]) % M + dp[last][0][2]) % M;
        dp[now][0][1] = dp[last][0][0];
        dp[now][0][2] = dp[last][0][1];
        dp[now][1][0] = (((((dp[last][0][0] + dp[last][0][1]) % M + dp[last][0][2]) % M + // a at the end
                dp[last][1][0]) % M + // p at the end
                dp[last][1][1]) % M + // p at the end
                dp[last][1][2])
            % M; // p at the end
        dp[now][1][1] = dp[last][1][0]; // l at the end
        dp[now][1][2] = dp[last][1][1]; // l at the end
    }

    // println!("{:?}", dp[n]);
    let mut ans = 0;
    for i in 0..2 {
        for j in 0..3 {
            ans = (ans + dp[n % 2][i][j]) % M;
        }
    }

    ans
}
fn main() {
    assert_eq!(check_record(10101), 183236316);
    assert_eq!(check_record(2), 8);
    assert_eq!(check_record(1), 3);
}
