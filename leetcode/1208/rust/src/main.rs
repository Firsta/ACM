use std::collections::VecDeque;

pub fn equal_substring(s: String, t: String, max_cost: i32) -> i32 {
    let mut v = Vec::new();
    let n = s.len();

    for i in 0..n {
        v.push((s.as_bytes()[i] as i32 - t.as_bytes()[i] as i32).abs());
    }

    // println!("{:?}", v);

    let mut cost = 0;
    let mut q = VecDeque::new();
    let mut ans = 0;

    for i in 0..n {
        q.push_back(v[i]);
        cost += v[i];
        while cost > max_cost {
            let p = q.pop_front().unwrap();
            cost -= p;
        }
        ans = std::cmp::max(ans, q.len());
    }

    ans as i32
}

fn main() {
    assert_eq!(
        equal_substring("abcd".to_string(), "bcdf".to_string(), 3),
        3
    );
}
