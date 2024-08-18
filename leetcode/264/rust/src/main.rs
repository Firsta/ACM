use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashSet};

pub fn nth_ugly_number(n: i32) -> i32 {
    let mut h = BinaryHeap::new();
    let mut inserted = HashSet::new();
    h.push(Reverse(1 as i64));
    inserted.insert(1i64);

    let mut ans = 0i64;
    for _ in 0..n {
        ans = h.pop().unwrap().0;
        let v = [ans * 2, ans * 3, ans * 5];
        for vv in v {
            if !inserted.contains(&vv) {
                h.push(Reverse(vv));
                inserted.insert(vv);
            }
        }
    }

    ans as i32
}

fn main() {
    assert_eq!(nth_ugly_number(1690), 2123366400);
}
