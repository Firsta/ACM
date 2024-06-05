pub fn common_chars(words: Vec<String>) -> Vec<String> {
    let mut c1 = vec![0; 26];
    for c in words[0].chars() {
        c1[c as usize - 'a' as usize] += 1;
    }

    for i in 1..words.len() {
        let w = &words[i];
        let mut c2 = vec![0; 26];
        for c in w.chars() {
            c2[c as usize - 'a' as usize] += 1;
        }

        for i in 0..26 {
            c1[i] = std::cmp::min(c1[i], c2[i]);
        }
    }

    let mut ans = Vec::new();
    for i in 0..26 {
        for _ in 0..c1[i] {
            ans.push(((i as u8 + 'a' as u8) as char).to_string());
        }
    }

    ans
}

fn main() {
    assert_eq!(
        common_chars(vec![
            "bella".to_string(),
            "label".to_string(),
            "roller".to_string()
        ]),
        ["e".to_string(), "l".to_string(), "l".to_string()]
    );
}
