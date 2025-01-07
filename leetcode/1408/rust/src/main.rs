pub fn string_matching(words: Vec<String>) -> Vec<String> {
    let mut words = words;
    words.sort_by(|a, b| b.len().cmp(&a.len()));

    let mut ans = Vec::new();
    for i in 0..words.len() {
        for j in 0..i {
            if words[j].contains(&words[i]) {
                ans.push(words[i].clone());
                break;
            }
        }
    }
    ans
}

fn main() {
    assert_eq!(
        string_matching(vec![
            "mass".to_string(),
            "as".to_string(),
            "hero".to_string(),
            "superhero".to_string()
        ]),
        vec!["hero".to_string(), "as".to_string()]
    );
}
