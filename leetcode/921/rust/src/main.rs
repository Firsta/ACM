pub fn min_add_to_make_valid(s: String) -> i32 {
    let mut st = Vec::new();
    for c in s.chars() {
        if c == ')' && st.last().is_some() && *st.last().unwrap() == '(' {
            st.pop();
        } else {
            st.push(c);
        }
    }
    st.len() as i32
}

fn main() {
    assert_eq!(min_add_to_make_valid("())".to_string()), 1);
    assert_eq!(min_add_to_make_valid("(((".to_string()), 3);
}
