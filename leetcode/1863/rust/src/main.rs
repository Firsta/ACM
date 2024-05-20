pub fn subset_xor_sum(nums: Vec<i32>) -> i32 {
    let n = nums.len();

    let mut ans = 0;
    for i in 0..2_i32.pow(n as u32) {
        let mut t = 0;
        for j in 0..n {
            if (1 << j) & i != 0 {
                t ^= nums[j];
            }
        }
        ans += t;
    }

    ans
}

fn main() {
    assert_eq!(subset_xor_sum(vec![3, 4, 5, 6, 7, 8]), 480);
}
