pub fn find_duplicates(mut nums: Vec<i32>) -> Vec<i32> {
    let mut result = Vec::new();
    for i in 0..nums.len() {
        let idx = (nums[i].abs() - 1) as usize;
        if nums[idx] < 0 {
            result.push(idx as i32 + 1);
        } else {
            nums[idx] = -nums[idx];
        }
    }
    result
}

fn main() {
    assert_eq!(find_duplicates(vec![4, 3, 2, 7, 8, 2, 3, 1]), vec![2, 3]);
    assert_eq!(find_duplicates(vec![1, 1, 2]), vec![1]);
    assert_eq!(find_duplicates(vec![1]), Vec::<i32>::new());
}
