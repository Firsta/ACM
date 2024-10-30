pub fn minimum_mountain_removals(nums: Vec<i32>) -> i32 {
    let n = nums.len();
    let mut dp1 = vec![1; n];
    for i in 0..n {
        for j in 0..i {
            if nums[i] > nums[j] {
                dp1[i] = std::cmp::max(dp1[i], dp1[j] + 1);
            }
        }
    }

    let mut dp2 = vec![1; n];
    for i in (0..n).rev() {
        for j in (i + 1..n).rev() {
            if nums[i] > nums[j] {
                dp2[i] = std::cmp::max(dp2[i], dp2[j] + 1);
            }
        }
    }

    let mut ans = 1;
    for i in 0..n {
        if dp1[i] != 1 && dp2[i] != 1 {
            ans = std::cmp::max(ans, dp1[i] + dp2[i] - 1);
        }
    }
    (n - ans) as i32
}

fn main() {
    assert_eq!(minimum_mountain_removals(vec![2, 1, 1, 5, 6, 2, 3, 1]), 3);
    assert_eq!(
        minimum_mountain_removals(vec![9, 8, 1, 7, 6, 5, 4, 3, 2, 1]),
        2
    );
}
