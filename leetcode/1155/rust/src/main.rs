pub fn num_rolls_to_target(n: i32, k: i32, target: i32) -> i32 {
    let mut dp = vec![vec![0usize; (target + k) as usize + 1]; n as usize + 1];
    // println!("{:?}", dp);
    for i in 1..k + 1 {
        dp[1][i as usize] = 1;
    }
    // println!("{:?}", dp);
    for i in 2..(n as usize + 1) {
        // println!("i: {}", i);
        for j in 1..(target as usize + 1) {
            // println!("j: {}", j);
            if dp[i - 1][j] > 0 {
                for kk in 1..(k as usize + 1) {
                    dp[i][j + kk] = (dp[i][j + kk] + dp[i - 1][j]) % (10usize.pow(9) + 7);
                }
            }
        }
    }
    dp[n as usize][target as usize] as i32
}

fn main() {
    println!("{}", num_rolls_to_target(30, 30, 500));
}
