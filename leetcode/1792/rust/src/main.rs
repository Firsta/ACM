#[derive(PartialEq, Eq)]
struct Item {
    p: i32,
    d: i32,
}

impl Ord for Item {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        self.partial_cmp(other).unwrap()
    }
}

impl PartialOrd for Item {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        let a =
            (other.p as f64 + 1.0) / (other.d as f64 + 1.0) - (other.p as f64) / (other.d as f64);
        let b = (self.p as f64 + 1.0) / (self.d as f64 + 1.0) - (self.p as f64) / (self.d as f64);
        b.partial_cmp(&a)
    }
}

use std::collections::BinaryHeap;

pub fn max_average_ratio(classes: Vec<Vec<i32>>, extra_students: i32) -> f64 {
    let mut m = BinaryHeap::new();
    for c in classes {
        m.push(Item { p: c[0], d: c[1] });
    }

    for _ in 0..extra_students {
        let t = m.pop().unwrap();
        m.push(Item {
            p: t.p + 1,
            d: t.d + 1,
        })
    }

    let mut ans = 0.0;
    for i in m.iter() {
        ans += (i.p as f64) / (i.d as f64);
    }
    ans / (m.len() as f64)
}

fn main() {
    assert_eq!(
        max_average_ratio(vec![vec![1, 2], vec![3, 5], vec![2, 2]], 2),
        0.7833333333333333
    );
}
