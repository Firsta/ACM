use std::collections::HashMap;

pub fn foo(nums: &Vec<i32>, k: i32) -> i32 {
    let mut m = HashMap::new();
    let mut left = 0;
    let mut result = 0;

    for right in 0..nums.len() {
        m.entry(nums[right]).and_modify(|e| *e += 1).or_insert(1);

        while m.len() > k as usize {
            m.entry(nums[left]).and_modify(|e| *e -= 1);
            if *m.get(&nums[left]).unwrap() == 0 {
                m.remove(&nums[left]);
            }
            left += 1;
        }

        result += right - left + 1;
    }

    result as i32
}

pub fn subarrays_with_k_distinct(nums: Vec<i32>, k: i32) -> i32 {
    foo(&nums, k) - foo(&nums, k - 1)
}

fn main() {
    assert_eq!(subarrays_with_k_distinct(vec![1, 2, 1, 2, 3], 2), 7);
    assert_eq!(subarrays_with_k_distinct(vec![1, 2, 1, 3, 4], 3), 3);
}
