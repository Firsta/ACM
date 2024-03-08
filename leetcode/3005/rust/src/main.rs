pub fn max_frequency_elements(nums: Vec<i32>) -> i32 {
    let mut h = vec![0usize; 101];

    for &num in nums.iter() {
        h[num as usize] += 1;
    }

    let mut m = 0;
    for &n in h.iter() {
        m = std::cmp::max(m, n);
    }

    let mut result = 0;
    for &n in h.iter() {
        if n == m {
            result += n;
        }
    }

    result as i32
}

fn main() {
    assert_eq!(max_frequency_elements(vec![1, 2, 2, 3, 1, 4]), 4);
    assert_eq!(max_frequency_elements(vec![1, 2, 3, 4, 5]), 5);
}
