pub fn find_disappeared_numbers(nums: Vec<i32>) -> Vec<i32> {
    let mut nums = nums;
    for i in 0..nums.len() {
        let n = (nums[i].abs() - 1) as usize;
        // println!("{} {}", i, n);
        nums[n] = -nums[n].abs();
    }

    let mut result = Vec::new();
    for (idx, &n) in nums.iter().enumerate() {
        if n > 0 {
            result.push(idx as i32 + 1);
        }
    }

    result
}

fn main() {
    assert_eq!(
        find_disappeared_numbers(vec![4, 3, 2, 7, 8, 2, 3, 1]),
        vec![5, 6]
    );
    assert_eq!(find_disappeared_numbers(vec![1, 1]), vec![2]);
}
