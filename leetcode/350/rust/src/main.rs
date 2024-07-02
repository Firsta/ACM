pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
    let mut m = vec![0; 1001];
    for n in nums1.into_iter() {
        m[n as usize] += 1;
    }

    let mut ans = Vec::new();
    for n in nums2.into_iter() {
        if m[n as usize] > 0 {
            ans.push(n);
            m[n as usize] -= 1;
        }
    }

    ans
}

fn main() {
    assert_eq!(intersect(vec![1, 2, 2, 1], vec![2, 2]), vec![2, 2]);
}
