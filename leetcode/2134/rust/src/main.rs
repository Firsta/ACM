pub fn min_swaps(nums: Vec<i32>) -> i32 {
    let one_count = nums.iter().filter(|x| **x == 1).count();
    if one_count == 0 {
        return 0;
    }

    let n = nums.len();
    let mut tail = (n + 1 - one_count) % n;

    let mut cur_one_count = 0;
    for i in 0..one_count {
        if nums[(tail + i) % n] == 1 {
            cur_one_count += 1;
        }
    }

    let mut ans = one_count - cur_one_count;
    for head in 1..n {
        if nums[head] == 1 {
            cur_one_count += 1;
        }
        if nums[tail] == 1 {
            cur_one_count -= 1;
        }
        tail = (tail + 1) % n;

        ans = std::cmp::min(ans, one_count - cur_one_count);
    }

    ans as i32
}
fn main() {
    assert_eq!(min_swaps(vec![0, 1, 0, 1, 1, 0, 0]), 1);
    assert_eq!(min_swaps(vec![0, 1, 1, 1, 0, 0, 1, 1, 0]), 2);
    assert_eq!(min_swaps(vec![1, 1, 0, 0, 1]), 0);
}
