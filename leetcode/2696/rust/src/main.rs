pub fn min_length(s: String) -> i32 {
    let mut st = Vec::new();
    for c in s.chars() {
        if c == 'B' && st.last().is_some() && *st.last().unwrap() == 'A' {
            st.pop();
        } else if c == 'D' && st.last().is_some() && *st.last().unwrap() == 'C' {
            st.pop();
        } else {
            st.push(c);
        }
    }
    st.len() as i32
}

fn main() {
    assert_eq!(min_length("ABFCACDB".to_string()), 2);
}
