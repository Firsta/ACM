pub fn reverse_prefix(word: String, ch: char) -> String {
    let mut word = word;
    unsafe {
        let b = word.as_bytes_mut();
        let i = b.iter().enumerate().find(|x| *(x.1) == ch as u8);

        if i.is_none() {
            return word;
        }
        // println!("{:?}", i);
        let mut i = i.unwrap().0;
        let mut j = 0;
        while j < i {
            let t = b[j];
            b[j] = b[i];
            b[i] = t;
            j += 1;
            i -= 1;
        }
    }

    word
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
