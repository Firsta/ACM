pub fn tribonacci(n: i32) -> i32 {
    let n = n as usize;

    match n {
        0 => 0,
        1 => 1,
        2 => 1,
        _ => {
            let mut dp = [0, 1, 1];
            for i in 3..=n {
                dp[i % 3] = dp.iter().sum();
            }
            dp[n % 3]
        }
    }
}

fn main() {
    assert_eq!(tribonacci(4), 4);
    assert_eq!(tribonacci(25), 1389537);
}
