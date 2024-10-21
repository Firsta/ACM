use std::collections::HashSet;

pub fn max_unique_split(s: String) -> i32 {
    fn dfs(set: &mut HashSet<String>, s: &str, ans: &mut i32) {
        if s.is_empty() {
            *ans = std::cmp::max(*ans, set.len() as i32);
        } else {
            for i in 0..s.len() {
                let ss = s[0..i + 1].to_string();
                if !set.contains(&ss) {
                    set.insert(ss.clone());
                    dfs(set, &s[i + 1..], ans);
                    set.remove(&ss);
                }
            }
        }
    }

    let mut ans = 0;
    let mut set = HashSet::new();
    dfs(&mut set, &s, &mut ans);
    ans
}

fn main() {
    assert_eq!(max_unique_split("ababccc".to_string()), 5);
    assert_eq!(max_unique_split("aba".to_string()), 2);
    assert_eq!(max_unique_split("aa".to_string()), 1);
}
