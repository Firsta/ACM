pub fn minimum_size(nums: Vec<i32>, max_operations: i32) -> i32 {
    fn ok(nums: &Vec<i32>, max_operations: i32, m: i32) -> bool {
        let mut o = max_operations;
        for n in nums.iter() {
            if *n > m {
                o -= *n / m - if n % m == 0 { 1 } else { 0 };
                if o < 0 {
                    return false;
                }
            }
        }
        true
    }
    let mut l = 0;
    let mut r = nums.iter().max().unwrap().clone();
    while r - l > 1 {
        let m = l + (r - l) / 2;
        if ok(&nums, max_operations, m) {
            r = m;
        } else {
            l = m;
        }
    }
    // println!("{} {}", l, r);
    r
}
fn main() {
    assert_eq!(minimum_size(vec![9], 2), 3);
    assert_eq!(minimum_size(vec![2, 4, 8, 2], 4), 2);
}
