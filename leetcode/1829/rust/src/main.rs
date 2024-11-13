pub fn get_maximum_xor(nums: Vec<i32>, maximum_bit: i32) -> Vec<i32> {
    let n = nums.len();
    let mut t = 0;
    let mut ans = Vec::new();
    let tt = 2i32.pow(maximum_bit as u32) - 1;
    for i in 0..n {
        t = t ^ nums[i];
        // println!("{} {}", t, tt);
        ans.push(t ^ tt);
    }
    ans.reverse();
    ans
}

fn main() {
    assert_eq!(get_maximum_xor(vec![0, 1, 1, 3], 2), vec![0, 3, 2, 3]);
    assert_eq!(get_maximum_xor(vec![2, 3, 4, 7], 3), vec![5, 2, 6, 5]);
    assert_eq!(
        get_maximum_xor(vec![0, 1, 2, 2, 5, 7], 3),
        vec![4, 3, 6, 4, 6, 7]
    );
}
