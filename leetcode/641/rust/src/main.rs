use std::collections::VecDeque;

struct MyCircularDeque {
    q: VecDeque<i32>,
    s: usize,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyCircularDeque {
    fn new(k: i32) -> Self {
        Self {
            q: VecDeque::with_capacity(k as usize),
            s: k as usize,
        }
    }

    fn insert_front(&mut self, value: i32) -> bool {
        if self.is_full() {
            false
        } else {
            self.q.push_front(value);
            true
        }
    }

    fn insert_last(&mut self, value: i32) -> bool {
        if self.is_full() {
            false
        } else {
            self.q.push_back(value);
            true
        }
    }

    fn delete_front(&mut self) -> bool {
        self.q.pop_front().is_some()
    }

    fn delete_last(&mut self) -> bool {
        self.q.pop_back().is_some()
    }

    fn get_front(&self) -> i32 {
        self.q.front().unwrap_or(&-1).clone()
    }

    fn get_rear(&self) -> i32 {
        self.q.back().unwrap_or(&-1).clone()
    }

    fn is_empty(&self) -> bool {
        self.q.is_empty()
    }

    fn is_full(&self) -> bool {
        self.q.len() == self.s
    }
}

fn main() {
    let mut dq = MyCircularDeque::new(3);
    assert!(dq.insert_last(1));
    assert!(dq.insert_last(2));
    assert!(dq.insert_front(3));
    assert!(!dq.insert_front(4));
    assert_eq!(dq.get_rear(), 2);
    assert!(dq.is_full());
    assert!(!dq.is_empty());
    assert!(dq.delete_last());
    assert!(dq.insert_front(4));
    assert_eq!(dq.get_front(), 4);
    assert!(dq.delete_front());
    assert_eq!(dq.get_front(), 3);
}
