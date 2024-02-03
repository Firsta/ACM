pub fn max_sum_after_partitioning(arr: Vec<i32>, k: i32) -> i32 {
    let n = arr.len();
    let mut dp = vec![0; n + 1];
    for i in 1..=n {
        let mut mm = 0;
        for j in 1..=std::cmp::min(i, k as usize) {
            // println!("{} {}", i, j);
            mm = std::cmp::max(mm, arr[i - j]);
            dp[i] = std::cmp::max(dp[i], mm * j as i32 + dp[i - j as usize]);
        }
    }
    // println!("{:?}", dp);
    dp[n]
}

fn main() {
    println!(
        "{}",
        max_sum_after_partitioning(vec![1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3], 4)
    );
}
