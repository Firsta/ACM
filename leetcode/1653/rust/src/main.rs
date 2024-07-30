pub fn minimum_deletions(s: String) -> i32 {
    let mut dp = 0;
    let mut b_count = 0;

    for c in s.chars() {
        if c == 'b' {
            dp = dp;
            b_count += 1;
        } else {
            dp = std::cmp::min(dp + 1, b_count);
        }
    }

    dp
}

fn main() {
    assert_eq!(minimum_deletions("aababbab".to_string()), 2);
}
