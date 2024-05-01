pub fn reverse_prefix(word: String, ch: char) -> String {
    let mut s = Vec::new();
    let mut ans = String::new();
    let mut reversed = false;
    for c in word.chars() {
        if reversed {
            ans.push(c);
        } else {
            if c == ch {
                ans.push(c);
                while !s.is_empty() {
                    ans.push(s.pop().unwrap());
                }
                reversed = true;
            } else {
                s.push(c);
            }
        }
    }

    if reversed {
        ans
    } else {
        word
    }
}

fn main() {
    assert_eq!(
        reverse_prefix("abcdefd".to_string(), 'd'),
        "dcbaefd".to_string()
    );
    assert_eq!(
        reverse_prefix("xyxzxe".to_string(), 'z'),
        "zxyxxe".to_string()
    );
    assert_eq!(reverse_prefix("abcd".to_string(), 'z'), "abcd".to_string());
}
