pub fn longest_diverse_string(a: i32, b: i32, c: i32) -> String {
    let mut h = std::collections::BinaryHeap::new();

    if a > 0 {
        h.push((a, 'a'));
    }
    if b > 0 {
        h.push((b, 'b'));
    }
    if c > 0 {
        h.push((c, 'c'));
    }

    let mut ans = Vec::new();

    while !h.is_empty() {
        let mut t = h.pop().unwrap();
        if ans.len() >= 2 && ans[ans.len() - 1] == ans[ans.len() - 2] && ans[ans.len() - 1] == t.1 {
            if h.is_empty() {
                break;
            } else {
                let mut t = h.pop().unwrap();
                ans.push(t.1);
                t.0 -= 1;
                if t.0 > 0 {
                    h.push(t);
                }
            }
        } else {
            ans.push(t.1);
            t.0 -= 1;
        }
        if t.0 > 0 {
            h.push(t);
        }
    }

    ans.into_iter().collect::<String>()
}

fn main() {
    assert_eq!(longest_diverse_string(1, 4, 5), "ccbcbcbcba".to_string());
}
