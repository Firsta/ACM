use std::cmp::Ordering;
use std::collections::BinaryHeap;

#[derive(Copy, Clone, Debug, Eq, PartialEq)]
struct Worker {
    quality: i32,
    wage: i32,
}

impl Worker {
    fn ratio(&self) -> f64 {
        self.wage as f64 / self.quality as f64
    }
}

impl Ord for Worker {
    fn cmp(&self, other: &Self) -> Ordering {
        self.partial_cmp(&other).unwrap()
    }
}

impl PartialOrd for Worker {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        self.ratio().partial_cmp(&other.ratio())
    }
}

struct MyQueue {
    q: BinaryHeap<i32>,
    sum: i32,
    max_len: usize,
}

impl MyQueue {
    fn new(max_len: usize) -> Self {
        Self {
            q: BinaryHeap::new(),
            sum: 0,
            max_len,
        }
    }

    fn push_then_trim(&mut self, quality: i32) {
        self.push(quality);
        self.trim();
    }

    fn push(&mut self, quality: i32) {
        self.q.push(quality);
        self.sum += quality;
    }

    fn trim(&mut self) {
        while self.q.len() > self.max_len {
            self.sum -= self.q.pop().unwrap();
        }
    }

    fn len(&self) -> usize {
        self.q.len()
    }
}

pub fn mincost_to_hire_workers(quality: Vec<i32>, wage: Vec<i32>, k: i32) -> f64 {
    let n = quality.len();

    let mut workers = Vec::new();
    for i in 0..n {
        workers.push(Worker {
            quality: quality[i],
            wage: wage[i],
        });
    }
    workers.sort();

    let k = k as usize;
    let mut q = MyQueue::new(k);

    let mut ans = std::f64::MAX;
    for i in 0..n {
        q.push_then_trim(workers[i].quality);
        if q.len() == k {
            ans = ans.min(q.sum as f64 * workers[i].ratio());
        }
    }

    ans
}

fn main() {
    assert_eq!(
        mincost_to_hire_workers(vec![10, 20, 5], vec![70, 50, 30], 2),
        105.00000
    );
    assert_eq!(
        mincost_to_hire_workers(vec![3, 1, 10, 10, 1], vec![4, 8, 2, 2, 7], 3),
        30.666666666666664
    );
    assert_eq!(
        mincost_to_hire_workers(
            vec![5, 19, 29, 59, 31, 7, 51, 99, 47, 40, 24, 20, 98, 41, 42, 81, 92, 55, 85, 51],
            vec![
                459, 419, 105, 419, 459, 3, 362, 465, 253, 219, 134, 113, 267, 156, 284, 298, 41,
                343, 69, 138
            ],
            16
        ),
        5837.593220338983
    );
}
