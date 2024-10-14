pub fn max_kelements(nums: Vec<i32>, k: i32) -> i64 {
    let mut h = std::collections::BinaryHeap::from(nums);
    let mut ans = 0i64;
    for _ in 0..k {
        let t = h.pop().unwrap();
        ans += t as i64;
        h.push(if t % 3 == 0 { t / 3 } else { t / 3 + 1 });
    }
    ans
}

fn main() {
    assert_eq!(max_kelements(vec![10, 10, 10, 10, 10], 5), 50);
}
