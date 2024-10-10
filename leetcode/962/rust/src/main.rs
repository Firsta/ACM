pub fn max_width_ramp(nums: Vec<i32>) -> i32 {
    let mut nums: Vec<(usize, i32)> = nums.into_iter().enumerate().collect();
    nums.sort_by(|a, b| a.1.cmp(&b.1));
    let mut last = None;
    let mut ans = 0;
    for n in nums.iter() {
        last = match last {
            None => Some(n),
            Some(last) => {
                if n.0 < last.0 {
                    Some(n)
                } else {
                    ans = std::cmp::max(ans, n.0 - last.0);
                    Some(last)
                }
            }
        }
    }
    ans as i32
}

fn main() {
    assert_eq!(max_width_ramp(vec![6, 0, 8, 2, 1, 5]), 4);
}
