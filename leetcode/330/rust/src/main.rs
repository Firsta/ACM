pub fn min_patches(nums: Vec<i32>, n: i32) -> i32 {
    let mut miss = 1i64;
    let mut ans = 0;
    let mut idx = 0;

    while miss <= n as i64 {
        // println!("{}", miss);
        // [0, miss - 1] can be formed
        if idx < nums.len() && nums[idx] as i64 <= miss {
            // [0, miss - 1 + nums[i]] can be formed
            miss += nums[idx] as i64;
            idx += 1;
        } else {
            // Add the missing number
            // [0, miss - 1 + miss] can be formed
            ans += 1;
            miss += miss;
        }
    }

    ans
}

fn main() {
    min_patches(vec![1, 2, 31, 33], 2147483647);
}
