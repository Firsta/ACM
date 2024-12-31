pub fn mincost_tickets(days: Vec<i32>, costs: Vec<i32>) -> i32 {
    let n = days.len();
    let mut dp = vec![std::i32::MAX; n];
    let mut i7 = 0;
    let mut i30 = 0;
    for i in 0..n {
        if i > 0 {
            dp[i] = std::cmp::min(dp[i], dp[i - 1] + costs[0]);
        } else {
            dp[i] = costs[0];
        }
        while days[i] - days[i7] >= 7 {
            i7 += 1;
        }
        if i7 > 0 {
            dp[i] = std::cmp::min(dp[i], dp[i7 - 1] + costs[1]);
        } else {
            dp[i] = std::cmp::min(dp[i], costs[1]);
        }
        while days[i] - days[i30] >= 30 {
            i30 += 1;
        }
        if i30 > 0 {
            dp[i] = std::cmp::min(dp[i], dp[i30 - 1] + costs[2]);
        } else {
            dp[i] = std::cmp::min(dp[i], costs[2]);
        }
    }
    // println!("{:?}", dp);
    dp[n - 1]
}

fn main() {
    assert_eq!(mincost_tickets(vec![1, 4, 6, 7, 8, 20], vec![2, 7, 15]), 11);
}
