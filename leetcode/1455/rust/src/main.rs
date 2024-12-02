pub fn is_prefix_of_word(sentence: String, search_word: String) -> i32 {
    for (idx, word) in sentence.split(" ").enumerate() {
        if let Some(i) = word.find(&search_word) {
            if i == 0 {
                return (idx + 1) as i32;
            }
        }
    }
    -1
}

fn main() {
    assert_eq!(
        is_prefix_of_word("hellohello hellohellohello".to_string(), "ell".to_string()),
        -1
    );
}
