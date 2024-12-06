use std::collections::HashSet;

pub fn max_count(banned: Vec<i32>, n: i32, max_sum: i32) -> i32 {
    let banned: HashSet<i32> = HashSet::from_iter(banned);
    let mut sum = 0;
    let mut ans = 0;
    for i in 1..=n {
        if !banned.contains(&i) {
            sum += i;
            if sum <= max_sum {
                ans += 1;
            }
        }
    }
    ans
}

fn main() {
    assert_eq!(max_count(vec![1, 6, 5], 5, 6), 2);
}
