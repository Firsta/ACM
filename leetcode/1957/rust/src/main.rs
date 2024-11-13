pub fn make_fancy_string(s: String) -> String {
    if s.len() <= 2 {
        s
    } else {
        let s: Vec<char> = s.chars().collect();
        let mut ans = vec![s[0], s[1]];
        for i in 2..s.len() {
            // println!("{:?}", ans);
            if s[i] == ans[ans.len() - 1] && ans[ans.len() - 1] == ans[ans.len() - 2] {
                continue;
            } else {
                ans.push(s[i]);
            }
        }
        ans.into_iter().collect()
    }
}

fn main() {
    assert_eq!(
        make_fancy_string("leeetcode".to_string()),
        "leetcode".to_string()
    );
}
