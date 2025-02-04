pub fn max_ascending_sum(nums: Vec<i32>) -> i32 {
    let mut s = nums[0];
    let mut ans = s;
    for i in 1..nums.len() {
        if nums[i] > nums[i - 1] {
            s += nums[i];
        } else {
            s = nums[i];
        }
        ans = std::cmp::max(ans, s);
    }
    ans
}

fn main() {
    assert_eq!(max_ascending_sum(vec![10, 20, 30, 5, 10, 50]), 65);
}
