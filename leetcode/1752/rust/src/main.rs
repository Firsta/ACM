pub fn check(nums: Vec<i32>) -> bool {
    let n = nums.len();
    let min = nums.iter().min().unwrap();
    fn ok(begin: usize, nums: &Vec<i32>) -> bool {
        let mut pre = 0;
        let n = nums.len();
        for i in 0..n {
            if nums[(begin + i) % n] < pre {
                return false;
            }
            pre = nums[(begin + i) % n];
        }
        true
    }
    for i in 0..n {
        if nums[i] == *min {
            if ok(i, &nums) {
                return true;
            }
        }
    }
    false
}

fn main() {
    assert_eq!(check(vec![3, 4, 5, 1, 2]), true);
    assert_eq!(check(vec![6, 10, 6]), true);
}
