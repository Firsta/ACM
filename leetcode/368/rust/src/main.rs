pub fn largest_divisible_subset(nums: Vec<i32>) -> Vec<i32> {
    let n = nums.len();
    let mut nums = nums.clone();
    let mut dp = vec![(1, None); n];
    nums.sort();
    let mut m = 1;
    let mut mi = 0;
    for i in 0..n {
        for j in 0..i {
            if nums[i] % nums[j] == 0 && (dp[j].0 + 1) > dp[i].0 {
                dp[i] = (dp[j].0 + 1, Some(j));
                if dp[i].0 > m {
                    m = dp[i].0;
                    mi = i;
                }
            }
        }
    }
    let mut result = Vec::new();
    result.push(nums[mi]);
    while dp[mi].1.is_some() {
        mi = dp[mi].1.unwrap();
        result.push(nums[mi]);
    }
    result
}

fn main() {
    println!("{:?}", largest_divisible_subset(vec![1, 2, 4, 8]));
}
