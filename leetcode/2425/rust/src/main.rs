pub fn xor_all_nums(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
    let mut ans = 0;
    if nums2.len() % 2 == 1 {
        for &n in nums1.iter() {
            ans ^= n;
        }
    }
    if nums1.len() % 2 == 1 {
        for &n in nums2.iter() {
            ans ^= n;
        }
    }
    ans
}

fn main() {
    assert_eq!(xor_all_nums(vec![2, 1, 3], vec![10, 2, 5, 0]), 13);
}
