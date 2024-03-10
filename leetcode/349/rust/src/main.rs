pub fn intersection(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
    let mut v1 = vec![false; 1001];
    let mut v2 = vec![false; 1001];

    for &n in nums1.iter() {
        v1[n as usize] = true;
    }
    for &n in nums2.iter() {
        v2[n as usize] = true;
    }

    let mut result = Vec::new();
    for i in 0..=1000 {
        if v1[i] && v2[i] {
            result.push(i as i32);
        }
    }

    result
}

fn main() {
    assert_eq!(intersection(vec![1, 2, 2, 1], vec![2, 2]), vec![2]);
    assert_eq!(intersection(vec![4, 9, 5], vec![9, 4, 9, 8, 4]), vec![4, 9]);
}
