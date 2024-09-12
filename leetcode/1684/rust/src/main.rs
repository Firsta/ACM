pub fn count_consistent_strings(allowed: String, words: Vec<String>) -> i32 {
    let mut m = vec![false; 26];
    for c in allowed.chars() {
        m[c as usize - 'a' as usize] = true;
    }
    words
        .into_iter()
        .map(|w| {
            let mut mm = vec![false; 26];
            for c in w.chars() {
                mm[c as usize - 'a' as usize] = true;
            }
            for (idx, c) in mm.into_iter().enumerate() {
                if c && !m[idx] {
                    return 0;
                }
            }
            1
        })
        .sum()
}

fn main() {
    assert_eq!(
        count_consistent_strings(
            "abc".to_string(),
            vec![
                "a".to_string(),
                "b".to_string(),
                "c".to_string(),
                "ab".to_string(),
                "ac".to_string(),
                "bc".to_string(),
                "abc".to_string()
            ]
        ),
        7
    );
}
