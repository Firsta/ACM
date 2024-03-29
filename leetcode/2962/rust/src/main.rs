pub fn count_subarrays(nums: Vec<i32>, k: i32) -> i64 {
    let mmax = nums.iter().max().unwrap();
    let mut result = 0i64;

    let mut k = k;
    let mut left = 0;
    for right in 0..nums.len() {
        if nums[right] == *mmax {
            k -= 1;
        }

        while k == 0 {
            if nums[left] == *mmax {
                k += 1;
            }
            left += 1;
        }

        result += left as i64;
    }

    result
}

fn main() {
    assert_eq!(count_subarrays(vec![1, 3, 2, 3, 3], 2), 6);
    assert_eq!(count_subarrays(vec![1, 4, 2, 1], 3), 0);
}
