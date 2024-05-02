pub fn find_max_k(nums: Vec<i32>) -> i32 {
    let mut vn = vec![false; 1001];
    for &num in nums.iter() {
        if num < 0 {
            vn[num.abs() as usize] = true;
        }
    }

    let mut ans = -1;
    for &num in nums.iter() {
        if num > 0 && vn[num as usize] {
            ans = std::cmp::max(ans, num);
        }
    }

    ans
}

fn main() {
    assert_eq!(find_max_k(vec![-1, 2, -3, 3]), 3);
    assert_eq!(find_max_k(vec![-1, 10, 6, 7, -7, 1]), 7);
    assert_eq!(find_max_k(vec![-10, 8, 6, 7, -2, -3]), -1);
}
