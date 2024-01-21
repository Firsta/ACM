use std::cmp::max;

pub fn rob(nums: Vec<i32>) -> i32 {
    let mut dp = Vec::new();
    let mut result = 0;
    for i in 0..nums.len() {
        let mut t = 0;
        if i > 1 {
            t = max(t, dp[i - 2]);
        }
        if i > 2 {
            t = max(t, dp[i - 3]);
        }
        t += nums[i];
        dp.push(t);
        result = max(result, t);
    }
    result
}

fn main() {
    println!("{}", rob(vec![2,7,9,3,1]));
}
