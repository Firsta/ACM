use std::collections::HashSet;

pub fn find_winners(matches: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut zero = HashSet::new();
    let mut one = HashSet::new();
    let mut more = HashSet::new();
    
    for t in matches.iter() {
        if !zero.contains(&t[0]) && !one.contains(&t[0]) && !more.contains(&t[0]) {
            zero.insert(t[0]);
        }
        if zero.contains(&t[1]) {
            zero.remove(&t[1]);
            one.insert(t[1]);
        } else if one.contains(&t[1]) {
            one.remove(&t[1]);
            more.insert(t[1]);
        } else if !more.contains(&t[1]) {
            one.insert(t[1]);
        }
    }
    
    let mut a = zero.into_iter().collect::<Vec<_>>();
    a.sort();
    let mut b = one.into_iter().collect::<Vec<_>>();
    b.sort();
    vec![a, b]
}

fn main() {
    println!("{:?}", find_winners(vec![vec![2,3], vec![1,3], vec![5,4], vec![6,4]]));
}
