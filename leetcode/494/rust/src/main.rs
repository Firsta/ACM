pub fn find_target_sum_ways(nums: Vec<i32>, target: i32) -> i32 {
    let n = nums.len();
    let mut ans = 0;
    for i in 0..(1 << n) {
        // println!("{}", i);
        let mut sum = 0;
        for j in 0..n {
            if ((1 << j) & i) > 0 {
                sum += nums[j];
            } else {
                sum -= nums[j];
            }
        }
        // println!("{}", sum);
        if sum == target {
            ans += 1;
        }
    }
    ans
}

fn main() {
    assert_eq!(find_target_sum_ways(vec![1, 1, 1, 1, 1], 3), 5);
    assert_eq!(find_target_sum_ways(vec![1], 1), 1);
}
