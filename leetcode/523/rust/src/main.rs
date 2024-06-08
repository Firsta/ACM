use std::collections::HashMap;

pub fn check_subarray_sum(nums: Vec<i32>, k: i32) -> bool {
    let mut m = HashMap::new();
    m.insert(0, -1);

    let mut prefix_sum = 0;
    for (i, n) in nums.into_iter().enumerate() {
        let i = i as i32;

        prefix_sum += n;
        let md = prefix_sum % k;

        match m.get(&md) {
            None => {
                m.insert(md, i);
            }
            Some(j) => {
                if i - j >= 2 {
                    return true;
                }
            }
        }
    }

    false
}

fn main() {
    assert_eq!(check_subarray_sum(vec![23, 2, 4, 6, 7], 6), true);
    assert_eq!(check_subarray_sum(vec![23, 2, 6, 4, 7], 6), true);
    assert_eq!(check_subarray_sum(vec![23, 2, 6, 4, 7], 13), false);
}
