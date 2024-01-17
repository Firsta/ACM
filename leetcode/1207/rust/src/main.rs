use std::collections::{HashMap, HashSet};

pub fn unique_occurrences(arr: Vec<i32>) -> bool {
    let mut m = HashMap::new();
    for x in arr.iter() {
        m.entry(x).and_modify(|e| *e += 1).or_insert(1);
    }
    let mut s = HashSet::new();
    for c in m.values() {
        if s.contains(c) {
            return false;
        } else {
            s.insert(c);
        }
    }
    true
}

fn main() {
    println!(
        "{}",
        unique_occurrences(vec![-3, 0, 1, -3, 1, 1, 1, -3, 10, 0])
    );
}
