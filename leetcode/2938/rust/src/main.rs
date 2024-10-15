pub fn minimum_steps(s: String) -> i64 {
    let n = s.len();
    let white_cnt = s.chars().filter(|c| *c == '0').count();
    let mut black_to_move = Vec::new();
    for i in 0..white_cnt {
        let c = s.as_bytes()[i] as char;
        if c == '1' {
            black_to_move.push(i);
        }
    }
    let mut ans = 0i64;
    for i in white_cnt..n {
        let c = s.as_bytes()[i] as char;
        if c == '0' {
            ans += (i - black_to_move.pop().unwrap()) as i64;
        }
    }

    ans
}

fn main() {
    assert_eq!(minimum_steps("101".to_string()), 1);
}
