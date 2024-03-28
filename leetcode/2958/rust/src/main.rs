use std::collections::HashMap;

pub fn max_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
    let mut m = HashMap::new();

    let k = k as usize;

    let mut ec = 0;
    let mut left = 0;
    let mut result = 0;
    for right in 0..nums.len() {
        let num = nums[right] as usize;
        let x = m.entry(num).and_modify(|x| *x += 1).or_insert(1);
        // println!("{}", x);
        if *x > k {
            ec += 1;
        }
        while ec > 0 && left <= right {
            let num = nums[left] as usize;
            m.entry(num).and_modify(|x| *x -= 1);
            if m[&num] >= k {
                ec -= 1;
            }
            left += 1;
        }
        result = std::cmp::max(result, right as i32 - left as i32 + 1);
    }

    result as i32
}

fn main() {
    assert_eq!(max_subarray_length(vec![1, 2, 3, 1, 2, 3, 1, 2], 2), 6);
    assert_eq!(max_subarray_length(vec![1, 2, 1, 2, 1, 2, 1, 2], 1), 2);
    assert_eq!(max_subarray_length(vec![5, 5, 5, 5, 5, 5, 5], 4), 4);
}
