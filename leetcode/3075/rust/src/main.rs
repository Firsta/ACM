pub fn maximum_happiness_sum(happiness: Vec<i32>, k: i32) -> i64 {
    let mut happiness = happiness;
    happiness.sort_by(|a, b| b.cmp(&a));

    let mut ans = 0i64;
    for i in 0..k as usize {
        ans += std::cmp::max(0i64, happiness[i] as i64 - i as i64);
    }

    ans
}

fn main() {
    assert_eq!(maximum_happiness_sum(vec![1, 2, 3], 2), 4);
}
