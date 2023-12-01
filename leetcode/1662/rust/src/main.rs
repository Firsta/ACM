pub fn array_strings_are_equal(word1: Vec<String>, word2: Vec<String>) -> bool {
    word1.join("").eq(&word2.join(""))
}

fn main() {
    println!("{}", array_strings_are_equal(vec!["ab".to_string(), "c".to_string()], vec!["a".to_string(), "bc".to_string()]));
}
