pub fn make_good(s: String) -> String {
    let mut v = Vec::new();
    for c in s.chars() {
        match v.last() {
            Some(t) => match c.is_ascii_uppercase() {
                true => {
                    if *t == c.to_ascii_lowercase() {
                        v.pop();
                    } else {
                        v.push(c);
                    }
                }
                false => {
                    if *t == c.to_ascii_uppercase() {
                        v.pop();
                    } else {
                        v.push(c);
                    }
                }
            },
            None => {
                v.push(c);
            }
        }
    }
    v.into_iter().collect()
}

fn main() {
    assert_eq!(make_good("leEeetcode".to_string()), "leetcode".to_string());
    assert_eq!(make_good("abBAcC".to_string()), "".to_string());
    assert_eq!(make_good("s".to_string()), "s".to_string());
}
