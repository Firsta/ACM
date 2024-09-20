pub fn shortest_palindrome(s: String) -> String {
    if s.is_empty() {
        return Default::default();
    }
    let s = {
        let mut ss = String::new();

        let n = s.len();
        for (idx, c) in s.chars().enumerate() {
            ss.push(c);
            if idx != n - 1 {
                ss.push('#');
            }
        }
        ss
    };

    let n = s.len();

    const P: i32 = 131;

    let mut p = 0;

    let mut h1 = vec![0];
    for c in s.chars() {
        p = p * P + c as i32;
        h1.push(p);
    }

    let s = s.chars().rev().collect::<String>();

    p = 0;
    let mut h2 = vec![0];
    for c in s.chars() {
        p = p * P + c as i32;
        h2.push(p);
    }

    let mut ans = 0;
    for l in 1..n {
        if l * 2 + 1 > n {
            break;
        }
        if h1[l] == h2[n - 1 - l] - h2[n - 1 - l - l] * P.pow(l as u32) {
            ans = l;
        }
    }

    let mut front = s[0..n - 2 * ans - 1].to_string();

    let s = s.chars().rev().collect::<String>();

    front.push_str(&s);

    front.replace("#", "")
}

fn main() {
    assert_eq!(
        shortest_palindrome("babbbabbaba".to_string()),
        "ababbabbbabbaba".to_string()
    );
}
