use std::cmp::Ordering;
use std::collections::{BinaryHeap, HashSet};

#[derive(Copy, Clone, Debug, Eq, PartialEq)]
struct F {
    ui: usize,
    u: i32,

    di: usize,
    d: i32,
}

impl Ord for F {
    fn cmp(&self, other: &Self) -> Ordering {
        (self.d * other.u).cmp(&(self.u * other.d))
    }
}

impl PartialOrd for F {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

pub fn kth_smallest_prime_fraction(arr: Vec<i32>, k: i32) -> Vec<i32> {
    let mut heap = BinaryHeap::new();
    let mut done = HashSet::new();

    let n = arr.len();
    heap.push(F {
        ui: 0,
        u: arr[0],
        di: n - 1,
        d: arr[n - 1],
    });
    done.insert((0usize, n - 1));

    let mut k = k as usize;
    while !heap.is_empty() {
        // println!("{:?}", heap);
        let p = heap.pop().unwrap();
        k -= 1;
        if k == 0 {
            return vec![p.u, p.d];
        } else if p.ui + 1 < p.di {
            if !done.contains(&(p.ui + 1, p.di)) {
                heap.push(F {
                    ui: p.ui + 1,
                    u: arr[p.ui + 1],
                    di: p.di,
                    d: p.d,
                });
                done.insert((p.ui + 1, p.di));
            }

            if !done.contains(&(p.ui, p.di - 1)) {
                heap.push(F {
                    ui: p.ui,
                    u: p.u,
                    di: p.di - 1,
                    d: arr[p.di - 1],
                });
                done.insert((p.ui, p.di - 1));
            }
        }
    }

    Vec::<i32>::new()
}

fn main() {
    assert_eq!(kth_smallest_prime_fraction(vec![1, 2, 3, 5], 3), vec![2, 5]);
    assert_eq!(kth_smallest_prime_fraction(vec![1, 7], 1), vec![1, 7]);

    assert_eq!(
        kth_smallest_prime_fraction(vec![1, 7, 23, 29, 47], 8),
        vec![23, 47]
    );
}
