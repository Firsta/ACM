pub fn num_steps(s: String) -> i32 {
    let mut zero = 0;
    let mut one = 0;
    for c in s.chars() {
        if c == '1' {
            one += 1;
        } else {
            zero += 1;
        }
    }

    if one == 1 {
        zero
    } else {
        let mut tail_zero = 0;
        for i in (0..s.len()).rev() {
            if s.as_bytes()[i] as char == '0' {
                tail_zero += 1;
            } else {
                break;
            }
        }

        zero - tail_zero + 1 + s.len() as i32
    }
}

fn main() {
    assert_eq!(num_steps("1101".to_string()), 6);
    assert_eq!(num_steps("10".to_string()), 1);
    assert_eq!(num_steps("1".to_string()), 0);
}
