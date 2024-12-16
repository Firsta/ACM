use std::cmp::Reverse;

pub fn get_final_state(nums: Vec<i32>, k: i32, multiplier: i32) -> Vec<i32> {
    let mut h = std::collections::BinaryHeap::new();
    for (idx, num) in nums.iter().enumerate() {
        h.push(Reverse((*num, idx)));
    }
    for _ in 0..k {
        let t = h.pop().unwrap();
        h.push(Reverse((t.0 .0 * multiplier, t.0 .1)));
    }
    let mut nums = nums;
    for hh in h {
        nums[hh.0 .1] = hh.0 .0;
    }
    nums
}

fn main() {
    assert_eq!(
        get_final_state(vec![2, 1, 3, 5, 6], 5, 2),
        vec![8, 4, 6, 5, 6]
    );
}
