pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
    (nums.into_iter().fold(0, |x, n| x ^ n) ^ k).count_ones() as i32
}

fn main() {
    assert_eq!(min_operations(vec![2, 1, 3, 4], 1), 2);
}
