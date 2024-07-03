pub fn min_difference(nums: Vec<i32>) -> i32 {
    let n = nums.len();
    if n <= 4 {
        0
    } else {
        let mut nums = nums;
        nums.sort();

        let mut ans = std::i32::MAX;
        for l in 0..=3 {
            let lv = nums[l];
            let r = 3 - l;
            let rv = nums[n - 1 - r];
            ans = std::cmp::min(ans, rv - lv);
            // println!("{} {} {} {} {}", ans, l, r, lv, rv);
        }
        ans
    }
}

fn main() {
    assert_eq!(min_difference(vec![5, 3, 2, 4]), 0);
    assert_eq!(min_difference(vec![5, 3, 2, 4, 1]), 1);
}
