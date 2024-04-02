use std::collections::HashMap;
use std::collections::HashSet;

pub fn is_isomorphic(s: String, t: String) -> bool {
    let mut m = HashMap::new();
    let mut set = HashSet::new();

    let n = s.len();

    for i in 0..n {
        let c1 = s.as_bytes()[i] as char;
        let c2 = t.as_bytes()[i] as char;

        match m.get(&c1) {
            Some(c) => {
                if *c != c2 {
                    return false;
                }
            }
            None => {
                if set.contains(&c2) {
                    return false;
                }
                m.insert(c1, c2);
                set.insert(c2);
            }
        }
    }

    true
}

fn main() {
    assert_eq!(is_isomorphic("egg".to_string(), "add".to_string()), true);
    assert_eq!(
        is_isomorphic("paper".to_string(), "title".to_string()),
        true
    );
    assert_eq!(is_isomorphic("foo".to_string(), "bar".to_string()), false);
}
