fn is_palindrome(s: &String) -> bool {
    let n = s.len();
    for i in 0..n / 2 {
        if s.as_bytes()[i] != s.as_bytes()[n - i - 1] {
            return false;
        }
    }
    true
}

pub fn first_palindrome(words: Vec<String>) -> String {
    for s in words.iter() {
        if is_palindrome(s) {
            return s.clone();
        }
    }
    "".to_string()
}

fn main() {
    println!(
        "{}",
        first_palindrome(vec!["notapalindrome".to_string(), "racecar".to_string()])
    );
}
