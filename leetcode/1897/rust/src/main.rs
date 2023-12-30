pub fn make_equal(words: Vec<String>) -> bool {
    let mut cc = vec![0; 26];
    for word in words.iter() {
        for c in word.chars() {
            cc[c as usize - 'a' as usize] += 1;
        }
    }
    for c in cc.iter() {
        if c % words.len() != 0 {
            return false;
        }
    }
    return true;
}

fn main() {
    println!("{}", make_equal(vec!["abc".to_string(), "aabc".to_string(), "bc".to_string()]));
}
