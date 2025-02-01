pub fn is_array_special(nums: Vec<i32>) -> bool {
    let mut pre = None;
    for n in nums {
        if let Some(p) = pre.as_ref() {
            if *p == n % 2 {
                return false;
            }
        }
        pre = Some(n % 2);
    }
    true
}

fn main() {
    assert_eq!(is_array_special(vec![1]), true);
}
