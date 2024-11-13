pub fn rotate_string(s: String, goal: String) -> bool {
    if s.len() != goal.len() {
        return false;
    }
    let n = s.len();

    for i in 0..s.len() {
        if &s[i..] == &goal[0..n - i] && &s[0..i] == &goal[n - i..] {
            return true;
        }
    }
    false
}

fn main() {
    assert_eq!(
        rotate_string("abcde".to_string(), "cdeab".to_string()),
        true
    );
}
