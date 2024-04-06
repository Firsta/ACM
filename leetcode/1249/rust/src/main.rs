use std::collections::HashSet;

pub fn min_remove_to_make_valid(s: String) -> String {
    let mut stack = Vec::new();
    let mut removed = HashSet::new();
    for (idx, c) in s.chars().enumerate() {
        if c == '(' {
            stack.push(idx);
        } else if c == ')' {
            match stack.last() {
                Some(_) => {
                    stack.pop();
                }
                None => {
                    removed.insert(idx);
                }
            }
        }
    }

    for x in stack.iter() {
        removed.insert(*x);
    }

    let mut result = String::new();
    for (idx, c) in s.chars().enumerate() {
        if !removed.contains(&idx) {
            result.push(c);
        }
    }

    result
}

fn main() {
    assert_eq!(
        min_remove_to_make_valid("lee(t(c)o)de)".to_string()),
        "lee(t(c)o)de".to_string()
    );
    assert_eq!(
        min_remove_to_make_valid("a)b(c)d".to_string()),
        "ab(c)d".to_string()
    );
    assert_eq!(min_remove_to_make_valid("))((".to_string()), "".to_string());
}
