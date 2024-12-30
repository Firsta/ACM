pub fn count_good_strings(low: i32, high: i32, zero: i32, one: i32) -> i32 {
    let low = low as usize;
    let high = high as usize;
    let zero = zero as usize;
    let one = one as usize;

    let mut dp = vec![0; high + 1];
    dp[zero] += 1;
    dp[one] += 1;
    for i in 1..=high {
        if i >= zero {
            dp[i] += dp[i - zero];
        }
        dp[i] %= 10i32.pow(9) + 7;

        if i >= one {
            dp[i] += dp[i - one];
        }
        dp[i] %= 10i32.pow(9) + 7;
    }

    let mut ans = 0;
    for i in low..=high {
        ans = (ans + dp[i]) % (10i32.pow(9) + 7);
    }
    ans
}

fn main() {
    assert_eq!(count_good_strings(3, 3, 1, 1), 8);
}
