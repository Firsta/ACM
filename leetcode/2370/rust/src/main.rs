pub fn longest_ideal_string(s: String, k: i32) -> i32 {
    let mut dp = vec![0; 26];

    for c in s.chars() {
        let idx = c as i32 - 'a' as i32;
        let mut t = 0;
        for i in std::cmp::max(0, idx - k)..=std::cmp::min(25, idx + k) {
            let i = i as usize;
            t = std::cmp::max(t, dp[i] + 1);
        }
        dp[idx as usize] = t;
    }

    dp.into_iter().max().unwrap()
}

fn main() {
    assert_eq!(longest_ideal_string("slddedwfmo".to_string(), 16), 9);
    assert_eq!(longest_ideal_string("acfgbd".to_string(), 2), 4);
    assert_eq!(longest_ideal_string("abcd".to_string(), 3), 4);
}
