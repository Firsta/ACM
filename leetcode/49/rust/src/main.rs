pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
    fn sort(s: &String) -> String {
        let s_slice: &str = &s[..];

        let mut chars: Vec<char> = s_slice.chars().collect();
        chars.sort_by(|a, b| b.cmp(a));

        let s = String::from_iter(chars);
        s
    }

    let mut v: Vec<(String, usize)> = strs.iter().enumerate().map(|(i, s)| (sort(s), i)).collect();
    v.sort_by(|a, b| a.0.cmp(&b.0));

    let mut former: Option<&String> = None;
    let mut result: Vec<Vec<String>> = Vec::with_capacity(strs.len());
    for vv in v.iter() {
        match former {
            Some(former) => {
                if former.eq(&vv.0) {
                    let l = result.len() - 1;
                    result[l].push(strs[vv.1].clone());
                } else {
                    result.push(vec![strs[vv.1].clone()]);
                }
            }
            None => {
                result.push(vec![strs[vv.1].clone()]);
            }
        }
        former = Some(&vv.0);
    }

    result
}

fn main() {
    println!(
        "{:?}",
        group_anagrams(vec![
            "eat".to_string(),
            "tea".to_string(),
            "tan".to_string(),
            "ate".to_string(),
            "nat".to_string(),
            "bat".to_string()
        ])
    );
}
