use std::collections::VecDeque;

pub fn find_the_winner(n: i32, k: i32) -> i32 {
    let mut q = VecDeque::new();
    q.reserve(n as usize);

    for i in 1..=n {
        q.push_back(i);
    }

    let mut cnt = 0;
    while q.len() > 1 {
        let p = q.pop_front().unwrap();
        cnt += 1;
        if cnt % k == 0 {
            cnt = 0;
        } else {
            q.push_back(p);
        }
    }

    q[0]
}

fn main() {
    assert_eq!(find_the_winner(5, 2), 3);
}
