pub fn find_duplicate(nums: Vec<i32>) -> i32 {
    let mut cnt = vec![0; nums.len() - 1];
    for n in nums.iter() {
        cnt[*n as usize - 1] += 1;
    }
    for (i, x) in cnt.iter().enumerate() {
        if *x > 1 {
            return (i + 1) as i32;
        }
    }
    0
}

fn main() {
    assert_eq!(find_duplicate(vec![3, 1, 3, 4, 2]), 3);
    assert_eq!(find_duplicate(vec![1, 3, 4, 2, 2]), 2);
    assert_eq!(find_duplicate(vec![3, 3, 3, 3, 3]), 3);
}
