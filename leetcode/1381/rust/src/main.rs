struct CustomStack {
    v: Vec<i32>,
    max_size: usize,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl CustomStack {
    fn new(max_size: i32) -> Self {
        Self {
            v: Vec::with_capacity(max_size as usize),
            max_size: max_size as usize,
        }
    }

    fn push(&mut self, x: i32) {
        if self.v.len() < self.max_size {
            self.v.push(x);
        }
    }

    fn pop(&mut self) -> i32 {
        self.v.pop().unwrap_or(-1)
    }

    fn increment(&mut self, k: i32, val: i32) {
        let k = k as usize;
        let l = self.v.len();
        for it in self.v[0..std::cmp::min(k, l)].iter_mut() {
            *it += val;
        }
    }
}

fn main() {
    let mut s = CustomStack::new(3);
    s.push(1);
    s.push(2);
    assert_eq!(s.pop(), 2);
    s.push(2);
    s.push(3);
    s.push(4);
    s.increment(5, 100);
    s.increment(2, 100);
    assert_eq!(s.pop(), 103);
    assert_eq!(s.pop(), 202);
    assert_eq!(s.pop(), 201);
    assert_eq!(s.pop(), -1);
}
