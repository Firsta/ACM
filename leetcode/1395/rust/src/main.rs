pub fn num_teams(rating: Vec<i32>) -> i32 {
    let n = rating.len();
    let mut ans = 0;
    {
        let mut dp = vec![vec![0; n]; 3];

        for i in 0..n {
            dp[0][i] = 1;
            for j in 0..i {
                if rating[j] < rating[i] {
                    dp[1][i] += dp[0][j];
                    dp[2][i] += dp[1][j];
                }
            }
            ans += dp[2][i];
        }
    }

    {
        let mut dp = vec![vec![0; n]; 3];

        for i in 0..n {
            dp[0][i] = 1;
            for j in 0..i {
                if rating[j] > rating[i] {
                    dp[1][i] += dp[0][j];
                    dp[2][i] += dp[1][j];
                }
            }
            ans += dp[2][i];
        }
    }

    ans
}

fn main() {
    assert_eq!(num_teams(vec![2, 5, 3, 4, 1]), 3);
}
