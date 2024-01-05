pub fn length_of_lis(nums: Vec<i32>) -> i32 {
    let mut dp = Vec::new();
    for n in nums.iter() {
        let p = dp.partition_point(|&x| x < n);
        if p == dp.len() {
            dp.push(n);
        } else {
            dp[p] = std::cmp::min(dp[p], n);
        }
    }
    dp.len() as i32
}

fn main() {
    println!("{}", length_of_lis(vec![10,9,2,5,3,7,101,18]));
}
