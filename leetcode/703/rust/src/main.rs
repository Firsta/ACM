use std::cmp::Reverse;
use std::collections::BinaryHeap;

struct KthLargest {
    h: BinaryHeap<Reverse<i32>>,
    k: usize,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl KthLargest {
    fn new(k: i32, nums: Vec<i32>) -> Self {
        let mut t = Self {
            h: BinaryHeap::new(),
            k: k as usize,
        };
        for n in nums.into_iter() {
            t.add(n);
        }
        t
    }

    fn add(&mut self, val: i32) -> i32 {
        self.h.push(Reverse(val));
        while self.h.len() > self.k {
            self.h.pop();
        }
        self.h.peek().unwrap().0
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * let obj = KthLargest::new(k, nums);
 * let ret_1: i32 = obj.add(val);
 */

fn main() {
    let mut k = KthLargest::new(3, vec![4, 5, 8, 2]);
    assert_eq!(k.add(3), 4);
    assert_eq!(k.add(5), 5);
    assert_eq!(k.add(10), 5);
    assert_eq!(k.add(9), 8);
    assert_eq!(k.add(4), 8);
}
