pub fn partition(s: String) -> Vec<Vec<String>> {
    fn is_pa(s: &String) -> bool {
        // println!("{}", s);
        let c = s.len() / 2;
        for i in 0..c {
            let c1 = s.as_bytes()[i] as char;
            let c2 = s.as_bytes()[s.len() - i - 1] as char;
            // println!("{} {}", c1, c2);
            if c1 != c2 {
                return false;
            }
        }
        true
    }

    let pn = s.len() - 1;
    let mut ans = Vec::new();
    for i in 0..2_i32.pow(pn as u32) {
        let mut p = 0usize;
        let mut v = Vec::new();
        let mut f = true;
        for j in 0..pn {
            if i & (1 << j) > 0 {
                let ss = s[p..j + 1].to_string();
                if !is_pa(&ss) {
                    f = false;
                    break;
                }
                v.push(ss);
                p = j + 1;
            }
        }
        if f {
            let ss = s[p..].to_string();
            if is_pa(&ss) {
                v.push(s[p..].to_string());
                ans.push(v);
            }
        }
    }

    ans
}

fn main() {
    assert_eq!(
        partition("aab".to_string()),
        vec![
            vec!["a".to_string(), "a".to_string(), "b".to_string()],
            vec!["aa".to_string(), "b".to_string()]
        ]
    );
    assert_eq!(partition("a".to_string()), vec![vec!["a".to_string()]]);
}
