pub fn max_depth(s: String) -> i32 {
    let mut v = Vec::new();

    let mut result = 0;
    for c in s.chars() {
        if c == ')' {
            let d = v.pop().unwrap();
            if v.is_empty() {
                result = std::cmp::max(result, d);
            } else {
                let n = v.len();
                let x = v[n - 1];
                v[n - 1] = std::cmp::max(x, d + 1);
            }
        } else if c == '(' {
            v.push(1);
        }
    }

    result
}

fn main() {
    assert_eq!(max_depth("(1+(2*3)+((8)/4))+1".to_string()), 3);
    assert_eq!(max_depth("(1)+((2))+(((3)))".to_string()), 3);
    assert_eq!(max_depth("()(()())".to_string()), 2);
}
