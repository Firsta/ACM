pub fn maximum_length(s: String) -> i32 {
    let n = s.len();
    let mut ans = -1;
    for i in 0..26 {
        let c = ('a' as u8 + i) as char;

        for j in 1..=n - 2 {
            let mut ts = String::new();
            for _k in 0..j {
                ts.push(c);
            }
            if s.as_bytes()
                .windows(ts.len())
                .filter(|&w| w == ts.as_bytes())
                .count()
                >= 3
            {
                ans = std::cmp::max(ans, ts.len() as i32);
            }
        }
    }
    ans
}

fn main() {
    assert_eq!(maximum_length("aaaa".to_string()), 2);
}
