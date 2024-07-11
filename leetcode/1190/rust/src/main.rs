pub fn reverse_parentheses(s: String) -> String {
    let n = s.len();
    let mut stack = Vec::new();
    let mut pair = vec![0; n];
    for (idx, c) in s.chars().enumerate() {
        if c == '(' {
            stack.push(idx);
        } else if c == ')' {
            let m = stack.pop().unwrap();
            pair[idx] = m;
            pair[m] = idx
        }
    }

    let mut ans = String::new();

    let mut cur_idx = 0;
    let mut direction = 1;
    while cur_idx < n {
        let c = s.as_bytes()[cur_idx] as char;
        if c == '(' || c == ')' {
            cur_idx = pair[cur_idx];
            direction = -direction;
        } else {
            ans.push(c);
        }

        if direction == 1 {
            cur_idx += 1;
        } else {
            cur_idx -= 1;
        }
    }

    ans
}

fn main() {
    assert_eq!(
        reverse_parentheses("(u(love)i)".to_string()),
        "iloveu".to_string()
    );
}
