pub fn compressed_string(word: String) -> String {
    let mut cur = None;
    let mut ans = String::new();
    for c in word.chars() {
        match cur {
            None => {
                cur = Some((1, c));
            }
            Some((cnt, l)) => {
                if l == c && cnt < 9 {
                    cur = Some((cnt + 1, l));
                } else {
                    ans.push_str(&cnt.to_string());
                    ans.push(l);
                    cur = Some((1, c));
                }
            }
        }
    }

    if let Some((cnt, l)) = cur {
        ans.push_str(&cnt.to_string());
        ans.push(l);
    }

    ans
}

fn main() {
    assert_eq!(
        compressed_string("abcde".to_string()),
        "1a1b1c1d1e".to_string()
    );
    assert_eq!(
        compressed_string("aaaaaaaaaaaaaabb".to_string()),
        "9a5a2b".to_string()
    );
}
