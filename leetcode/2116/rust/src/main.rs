pub fn can_be_valid(s: String, locked: String) -> bool {
    if s.len() % 2 == 1 {
        false
    } else {
        let mut open = Vec::new();
        let mut unlocked = Vec::new();
        for (idx, c) in s.chars().enumerate() {
            if locked.as_bytes()[idx] as char == '0' {
                unlocked.push(idx);
            } else {
                if c == ')' {
                    if !open.is_empty() {
                        open.pop();
                    } else if !unlocked.is_empty() {
                        unlocked.pop();
                    } else {
                        return false;
                    }
                } else {
                    open.push(idx);
                }
            }
        }

        while !open.is_empty() {
            if unlocked.is_empty() || unlocked.last().unwrap() < open.last().unwrap() {
                return false;
            } else {
                open.pop();
                unlocked.pop();
            }
        }

        unlocked.len() % 2 == 0
    }
}

fn main() {
    assert_eq!(
        can_be_valid(
            "())()))()(()(((())(()()))))((((()())(())".to_string(),
            "1011101100010001001011000000110010100101".to_string()
        ),
        true
    );
    assert_eq!(
        can_be_valid(
            "((()(()()))()((()()))))()((()(()".to_string(),
            "10111100100101001110100010001001".to_string()
        ),
        true
    );
    assert_eq!(
        can_be_valid("))()))".to_string(), "010100".to_string()),
        true
    );
    assert_eq!(can_be_valid("()()".to_string(), "0000".to_string()), true);
    assert_eq!(can_be_valid(")".to_string(), "0".to_string()), false);
}
