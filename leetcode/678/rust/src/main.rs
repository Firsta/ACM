pub fn check_valid_string(s: String) -> bool {
    let mut stack_p = Vec::new();
    let mut stack_s = Vec::new();
    for (idx, c) in s.chars().enumerate() {
        match c {
            '(' => {
                stack_p.push(idx);
            }
            ')' => {
                if stack_p.is_empty() && stack_s.is_empty() {
                    return false;
                } else if !stack_p.is_empty() {
                    stack_p.pop();
                } else if !stack_s.is_empty() {
                    stack_s.pop();
                }
            }
            '*' => {
                stack_s.push(idx);
            }
            _ => (),
        }
    }

    while let Some(&idx_p) = stack_p.last() {
        match stack_s.last() {
            None => {
                return false;
            }
            Some(&idx_s) => {
                if idx_s > idx_p {
                    stack_p.pop();
                    stack_s.pop();
                } else {
                    return false;
                }
            }
        }
    }
    return true;
}

fn main() {
    assert_eq!(check_valid_string("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())".to_string()), false);
    assert_eq!(check_valid_string("()".to_string()), true);
    assert_eq!(check_valid_string("(*)".to_string()), true);
    assert_eq!(check_valid_string("(*))".to_string()), true);
}
