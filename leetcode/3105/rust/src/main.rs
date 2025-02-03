pub fn longest_monotonic_subarray(nums: Vec<i32>) -> i32 {
    let mut increase = 1;
    let mut decrease = 1;
    let mut ans = 1;
    for i in 1..nums.len() {
        if nums[i] > nums[i - 1] {
            increase += 1;
        } else {
            increase = 1;
        }

        if nums[i] < nums[i - 1] {
            decrease += 1;
        } else {
            decrease = 1;
        }

        ans = std::cmp::max(ans, increase);
        ans = std::cmp::max(ans, decrease);
    }
    ans
}

fn main() {
    assert_eq!(longest_monotonic_subarray(vec![1, 4, 3, 3, 2]), 2);
}
