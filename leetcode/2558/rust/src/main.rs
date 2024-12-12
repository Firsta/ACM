use std::collections::BinaryHeap;

pub fn pick_gifts(gifts: Vec<i32>, k: i32) -> i64 {
    let gifts: Vec<i64> = gifts.into_iter().map(|x| x as i64).collect();
    let mut h = BinaryHeap::from(gifts);
    for _ in 0..k {
        let t = h.pop().unwrap();
        h.push((t as f64).sqrt().floor() as i64);
    }
    h.into_iter().sum()
}

fn main() {
    assert_eq!(pick_gifts(vec![25, 64, 9, 4, 100], 4), 29);
}
