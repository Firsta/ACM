pub fn count_prefix_suffix_pairs(words: Vec<String>) -> i32 {
    let n = words.len();
    let mut ans = 0;
    for i in 0..n {
        for j in i + 1..n {
            if words[i].len() <= words[j].len()
                && words[j][..words[i].len()] == words[i]
                && words[j][words[j].len() - words[i].len()..] == words[i]
            {
                ans += 1;
            }
        }
    }
    ans
}

fn main() {
    assert_eq!(
        count_prefix_suffix_pairs(vec![
            "a".to_string(),
            "aba".to_string(),
            "ababa".to_string(),
            "aa".to_string()
        ]),
        4
    );
}
