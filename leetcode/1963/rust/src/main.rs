pub fn min_swaps(s: String) -> i32 {
    let mut st = Vec::new();
    for c in s.chars() {
        if c == ']' && st.last().is_some() && *st.last().unwrap() == '[' {
            st.pop();
        } else {
            st.push(c);
        }
    } // ]][[ -> [][]
      // ]]][[[ -> ][][][ -> [[][]]
      // ]]]][[[[ ->
    (st.len() / 4 + if st.len() % 4 == 0 { 0 } else { 1 }) as i32
}

fn main() {
    assert_eq!(min_swaps("][][".to_string()), 1);
    assert_eq!(min_swaps("]]][[[".to_string()), 2);
    assert_eq!(min_swaps("[]".to_string()), 0);
}
