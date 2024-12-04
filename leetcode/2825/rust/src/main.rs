pub fn can_make_subsequence(str1: String, str2: String) -> bool {
    let mut i2 = 0;
    for c in str1.chars() {
        let c2 = str2.as_bytes()[i2] as char;
        // println!("{}", ((c as u8 - 'a' as u8 + 1) % 26 + 'a' as u8) as char);
        if c == c2 || ((c as u8 - 'a' as u8 + 1) % 26 + 'a' as u8) as char == c2 {
            i2 += 1;
            if i2 == str2.len() {
                return true;
            }
        }
    }
    // println!("{}", i2);
    false
}
fn main() {
    assert_eq!(
        can_make_subsequence("abc".to_string(), "ad".to_string()),
        true
    );
    assert_eq!(
        can_make_subsequence("zc".to_string(), "ad".to_string()),
        true
    );
    assert_eq!(
        can_make_subsequence("ab".to_string(), "d".to_string()),
        false
    );
}
