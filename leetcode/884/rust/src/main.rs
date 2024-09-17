pub fn uncommon_from_sentences(s1: String, s2: String) -> Vec<String> {
    let mut s1 = s1;
    s1.push(' ');
    s1.push_str(&s2);
    let x = s1.split(" ").collect::<Vec<&str>>();

    let mut h = std::collections::HashMap::new();
    for xx in x {
        h.entry(xx).and_modify(|e| *e += 1).or_insert(1);
    }

    let mut ans = Vec::new();
    for (k, v) in h.iter() {
        if *v == 1 {
            ans.push(k.to_string());
        }
    }
    ans
}

fn main() {
    assert_eq!(
        uncommon_from_sentences(
            "this apple is sweet".to_string(),
            "this apple is sour".to_string()
        ),
        vec!["sweet".to_string(), "sour".to_string()]
    );
}
