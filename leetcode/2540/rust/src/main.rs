pub fn get_common(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
    let mut i = 0;
    let mut j = 0;

    let n = nums1.len();
    let m = nums2.len();

    while i < n && j < m {
        if nums1[i] == nums2[j] {
            return nums1[i];
        } else if nums1[i] > nums2[j] {
            j += 1;
        } else {
            i += 1;
        }
    }
    -1
}

fn main() {
    assert_eq!(get_common(vec![1, 2, 3], vec![2, 4]), 2);
}
