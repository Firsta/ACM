pub fn is_array_special(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<bool> {
    let mut cnt = 0;
    let mut pre = vec![0];
    for i in 1..nums.len() {
        if nums[i] % 2 == nums[i - 1] % 2 {
            cnt += 1;
        }
        pre.push(cnt);
    }
    let mut ans = Vec::new();
    for q in queries {
        if q[1] - q[0] == 0 {
            ans.push(true);
        } else {
            ans.push(pre[q[1] as usize] == pre[q[0] as usize]);
        }
    }
    ans
}

fn main() {
    assert_eq!(
        is_array_special(vec![3, 4, 1, 2, 6], vec![vec![0, 4]]),
        vec![false]
    );
}
