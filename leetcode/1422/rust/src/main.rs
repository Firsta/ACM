use std::cmp::max;

pub fn max_score_0(s: String) -> i32 {
    let mut one = s.chars().filter(|x| *x == '1').count();

    let mut zero = 0;
    let mut result = 0;
    for (i, c) in s.chars().enumerate() {
        if c == '0' {
            zero += 1;
        } else {
            one -= 1;
        }
        if i < s.len() - 1 {
            result = max(result, zero + one);
        }
    }
    result as i32
}

pub fn max_score(s: String) -> i32 {
    let one = s.chars().filter(|x| *x == '1').count();

    let mut zero = 0;
    let mut result = 0;
    for (i, c) in s.chars().enumerate() {
        if c == '0' {
            zero += 1;
        }
        if i < s.len() - 1 {
            result = max(result, zero + one - (i + 1 - zero));
        }
    }
    result as i32
}

fn main() {
    assert_eq!(max_score("011101".to_string()), 5);
    assert_eq!(max_score("1111".to_string()), 3);
}
