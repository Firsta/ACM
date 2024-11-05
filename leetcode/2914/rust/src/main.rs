pub fn min_changes(s: String) -> i32 {
    let n = s.len();
    let mut ans = 0;
    for i in 0..n / 2 {
        let ss = &s[i * 2..=i * 2 + 1];
        match ss {
            "01" | "10" => ans += 1,
            _ => (),
        }
    }

    ans
}

fn main() {
    assert_eq!(min_changes("1001".to_string()), 2);
    assert_eq!(min_changes("10".to_string()), 1);
    assert_eq!(min_changes("0000".to_string()), 0);
}
