pub fn maximum_beauty(nums: Vec<i32>, k: i32) -> i32 {
    let mut cnt = vec![0; 300010];
    for n in nums {
        cnt[(n + 100000 - k) as usize] += 1;
        cnt[(n + 100000 + k + 1) as usize] -= 1;
    }
    let mut c = 0;
    let mut ans = 0;
    for i in 0..300010 {
        c += cnt[i];
        ans = std::cmp::max(ans, c);
    }
    ans
}

fn main() {
    assert_eq!(maximum_beauty(vec![4, 6, 1, 2], 2), 3);
    assert_eq!(maximum_beauty(vec![1, 1, 1, 1], 10), 4);
}
