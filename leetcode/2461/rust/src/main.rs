use std::i64;

pub fn maximum_subarray_sum(nums: Vec<i32>, k: i32) -> i64 {
    let k = k as usize;
    let mut sum = 0i64;
    let mut more = 0;
    let mut ans = 0;

    let mut m = std::collections::HashMap::new();
    for i in 0..k {
        sum += nums[i] as i64;
        match m.get(&nums[i]) {
            None => {
                m.insert(nums[i], 1);
            }
            Some(&x) => {
                if x == 1 {
                    more += 1;
                }
                m.insert(nums[i], x + 1);
            }
        }
    }
    if more == 0 {
        ans = sum;
    }
    let n = nums.len();
    for i in 0..n - k {
        sum -= nums[i] as i64;
        sum += nums[i + k] as i64;
        let now = m.get(&nums[i]).unwrap().clone();
        if now == 2 {
            more -= 1;
        }
        m.insert(nums[i], now - 1);
        match m.get(&nums[i + k]) {
            None => {
                m.insert(nums[i + k], 1);
            }
            Some(&x) => {
                if x == 1 {
                    more += 1;
                }
                m.insert(nums[i + k], x + 1);
            }
        }
        if more == 0 {
            ans = std::cmp::max(ans, sum);
        }

        // println!("{:?} {} {}", m, more, sum);
    }

    ans
}

fn main() {
    assert_eq!(maximum_subarray_sum(vec![1, 5, 4, 2, 9, 9, 9], 3), 15);
    assert_eq!(maximum_subarray_sum(vec![4, 4, 4], 3), 0);
}
