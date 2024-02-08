pub fn num_squares(n: i32) -> i32 {
    let n = n as usize;
    let mut dp = vec![10005; n + 1];
    dp[0] = 0;
    for i in 1..=n {
        for j in 1..=i {
            if j * j > i {
                break;
            } else {
                let l = i - j * j;
                if dp[l] != -1 {
                    dp[i] = std::cmp::min(dp[i], dp[l] + 1);
                }
            }
        }
    }
    // println!("{:?}", dp);
    dp[n]
}

fn main() {
    println!("{}", num_squares(13));
}
