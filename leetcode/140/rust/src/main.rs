use std::collections::HashSet;

pub fn word_break(s: String, word_dict: Vec<String>) -> Vec<String> {
    let words: HashSet<String> = HashSet::from_iter(word_dict.into_iter());

    let n = s.len();
    let mut ans = Vec::new();
    for i in 0..2i32.pow(n as u32 - 1) {
        let mut v = Vec::new();

        let mut p = 0;
        for j in 0..n - 1 {
            if (1 << j) & i != 0 {
                v.push(s[p..j + 1].to_string());
                p = j + 1;
            }
        }
        v.push(s[p..].to_string());

        // println!("{:?}", v);
        let mut ok = true;
        for w in v.iter() {
            if !words.contains(w) {
                ok = false;
                break;
            }
        }
        if ok {
            ans.push(v.join(" "));
        }
    }

    ans
}

fn main() {
    assert_eq!(
        word_break(
            "catsanddog".to_string(),
            vec![
                "cat".to_string(),
                "cats".to_string(),
                "and".to_string(),
                "sand".to_string(),
                "dog".to_string()
            ]
        ),
        vec!["cat sand dog".to_string(), "cats and dog".to_string()]
    );
}
