use std::collections::HashSet;

pub fn replace_words(dictionary: Vec<String>, sentence: String) -> String {
    let mut s = HashSet::new();

    for d in dictionary.into_iter() {
        s.insert(d);
    }

    let parts = sentence.split(" ");
    let mut ans = Vec::new();
    for part in parts {
        let mut w = part;
        for i in 1..part.len() {
            if s.contains(&part[0..i]) {
                w = &part[0..i];
                break;
            }
        }
        ans.push(w.clone());
    }
    // println!("{:?}", ans);

    ans.join(" ")
}

fn main() {
    assert_eq!(
        replace_words(
            vec!["cat".to_string(), "bat".to_string(), "rat".to_string()],
            "the cattle was rattled by the battery".to_string()
        ),
        "the cat was rat by the bat".to_string()
    );
}
