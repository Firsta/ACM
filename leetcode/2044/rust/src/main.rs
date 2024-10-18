pub fn count_max_or_subsets(nums: Vec<i32>) -> i32 {
    let n = nums.len() as u32;

    let mut expected = 0;
    for n in nums.iter() {
        expected = expected | *n;
    }

    let mut ans = 0;
    for i in 1..2i32.pow(n) {
        let mut cur = 0;
        for j in 0..n {
            if i & 1 << j > 0 {
                cur = cur | nums[j as usize];
            }
        }
        if cur == expected {
            ans += 1
        }
    }
    ans
}

fn main() {
    assert_eq!(count_max_or_subsets(vec![3, 2, 1, 5]), 6);
    assert_eq!(count_max_or_subsets(vec![2, 2, 2]), 7);
}
