use std::collections::VecDeque;

pub fn min_k_bit_flips(nums: Vec<i32>, k: i32) -> i32 {
    let mut q = VecDeque::new();

    let mut ans = 0;

    let k = k as usize;

    let l = nums.len();

    for (idx, n) in nums.into_iter().enumerate() {
        match q.front() {
            Some(x) => {
                if idx >= k && *x <= idx - k {
                    q.pop_front();
                }
            }
            _ => (),
        }

        if n % 2 == (q.len() as i32) % 2 {
            if idx + k > l {
                return -1;
            }
            q.push_back(idx);
            ans += 1;
        }
    }

    ans
}

fn main() {
    assert_eq!(min_k_bit_flips(vec![0, 0, 0, 1, 0, 1, 1, 0], 3), 3);
}
