pub fn prefix_count(words: Vec<String>, pref: String) -> i32 {
    words
        .into_iter()
        .filter(|w| w.len() >= pref.len() && w[0..pref.len()] == pref)
        .count() as i32
}

fn main() {
    assert_eq!(
        prefix_count(
            vec![
                "pay".to_string(),
                "attention".to_string(),
                "practice".to_string(),
                "attend".to_string()
            ],
            "at".to_string()
        ),
        2
    );
}
