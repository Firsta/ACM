pub fn word_subsets(words1: Vec<String>, words2: Vec<String>) -> Vec<String> {
    let mut cnt2 = vec![0; 26];
    for w in words2 {
        let mut tc = vec![0; 26];
        for c in w.chars() {
            tc[c as usize - 'a' as usize] += 1;
        }
        for i in 0..26 {
            cnt2[i] = std::cmp::max(cnt2[i], tc[i]);
        }
    }

    let mut ans = Vec::new();
    for w in words1 {
        let mut tc = vec![0; 26];
        for c in w.chars() {
            tc[c as usize - 'a' as usize] += 1;
        }
        let mut ok = true;
        for i in 0..26 {
            if tc[i] < cnt2[i] {
                ok = false;
            }
        }
        if ok {
            ans.push(w);
        }
    }
    ans
}

fn main() {
    assert_eq!(
        word_subsets(
            vec![
                "amazon".to_string(),
                "apple".to_string(),
                "facebook".to_string(),
                "google".to_string(),
                "leetcode".to_string()
            ],
            vec!["e".to_string(), "o".to_string()]
        ),
        vec![
            "facebook".to_string(),
            "google".to_string(),
            "leetcode".to_string()
        ]
    );
}
