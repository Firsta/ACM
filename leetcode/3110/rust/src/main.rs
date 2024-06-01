pub fn score_of_string(s: String) -> i32 {
    let n = s.len();

    let mut ans = 0;
    for i in 0..n - 1 {
        ans += ((s.as_bytes()[i] as i32) - (s.as_bytes()[i + 1] as i32)).abs();
    }

    ans as i32
}

fn main() {
    assert_eq!(score_of_string("hello".to_string()), 13);
}
