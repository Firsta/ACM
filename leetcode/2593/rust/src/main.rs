use std::{cmp::Reverse, collections::BinaryHeap};

pub fn find_score(nums: Vec<i32>) -> i64 {
    let n = nums.len();
    let mut marked = vec![false; n];

    let mut h = BinaryHeap::new();
    for (idx, n) in nums.into_iter().enumerate() {
        h.push(Reverse((n, idx)));
    }

    let mut ans = 0;
    while !h.is_empty() {
        let t = h.pop().unwrap();
        if !marked[t.0 .1] {
            ans += t.0 .0 as i64;
            marked[t.0 .1] = true;
            if t.0 .1 > 0 {
                marked[t.0 .1 - 1] = true;
            }
            if t.0 .1 < n - 1 {
                marked[t.0 .1 + 1] = true;
            }
        }
    }
    ans
}
fn main() {
    assert_eq!(find_score(vec![2, 1, 3, 4, 5, 2]), 7);
    assert_eq!(find_score(vec![2, 3, 5, 1, 3, 2]), 5);
}
