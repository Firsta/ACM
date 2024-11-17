use std::{cmp::Reverse, collections::BinaryHeap};

pub fn shortest_subarray(nums: Vec<i32>, k: i32) -> i32 {
    let mut h = BinaryHeap::new();
    let mut sum = 0;
    h.push(Reverse((0, -1)));
    let mut ans = 100010;
    for i in 0..nums.len() {
        sum += nums[i];
        while h.peek().is_some() && sum - h.peek().unwrap().0 .0 >= k {
            ans = std::cmp::min(ans, i as i32 - h.peek().unwrap().0 .1);
            h.pop();
        }
        h.push(Reverse((sum, i as i32)));
    }

    if ans == 100010 {
        -1
    } else {
        ans
    }
}

fn main() {
    assert_eq!(shortest_subarray(vec![1], 1), 1);
    assert_eq!(shortest_subarray(vec![1, 2], 4), -1);
    assert_eq!(shortest_subarray(vec![2, -1, 2], 3), 3);
    assert_eq!(shortest_subarray(vec![17, 85, 93, -45, -21], 150), 2);
    assert_eq!(
        shortest_subarray(vec![44, -25, 75, -50, -38, -42, -32, -6, -40, -47], 19),
        1
    );
}
