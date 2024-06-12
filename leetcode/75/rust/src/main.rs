pub fn sort_colors(nums: &mut Vec<i32>) {
    let mut v = vec![0; 3];

    for &n in nums.iter() {
        v[n as usize] += 1;
    }

    let mut i = 0;
    for j in 0..3 {
        for _ in 0..v[j] {
            nums[i] = j as i32;
            i += 1;
        }
    }
}

fn main() {
    let mut v = vec![2, 0, 2, 1, 1, 0];
    sort_colors(&mut v);
    assert_eq!(v, vec![0, 0, 1, 1, 2, 2]);
}
