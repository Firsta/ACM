pub fn append_characters(s: String, t: String) -> i32 {
    let mut j = 0;
    for i in 0..s.len() {
        if s.as_bytes()[i] == t.as_bytes()[j] {
            j += 1;
            if j == t.len() {
                return 0;
            }
        }
    }

    (t.len() - j) as i32
}

fn main() {
    assert_eq!(
        append_characters("coaching".to_string(), "coding".to_string()),
        4
    );
}
