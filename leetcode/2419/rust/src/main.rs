pub fn longest_subarray(nums: Vec<i32>) -> i32 {
    let m = nums.iter().max().unwrap().clone();

    let mut ans = 0;
    let mut t = 0;
    for n in nums {
        if n == m {
            t += 1;
            ans = std::cmp::max(ans, t);
        } else {
            t = 0;
        }
    }
    ans
}

fn main() {
    assert_eq!(longest_subarray(vec![1, 2, 3, 3, 2, 2]), 2);
}
