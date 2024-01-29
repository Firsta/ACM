struct MyQueue {
    stack0: Vec<i32>,
    stack1: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyQueue {
    fn new() -> Self {
        MyQueue {
            stack0: Vec::new(),
            stack1: Vec::new(),
        }
    }

    fn push(&mut self, x: i32) {
        self.stack0.push(x);
    }

    fn pop(&mut self) -> i32 {
        if self.stack1.is_empty() {
            while !self.stack0.is_empty() {
                self.stack1.push(self.stack0.pop().unwrap());
            }
        }
        self.stack1.pop().unwrap()
    }

    fn peek(&mut self) -> i32 {
        if self.stack1.is_empty() {
            while !self.stack0.is_empty() {
                self.stack1.push(self.stack0.pop().unwrap());
            }
        }
        self.stack1.last().unwrap().clone()
    }

    fn empty(&self) -> bool {
        self.stack0.is_empty() && self.stack1.is_empty()
    }
}

fn main() {
    let mut q = MyQueue::new();
    q.push(1);
    q.push(2);
    assert_eq!(q.peek(), 1);
    assert_eq!(q.pop(), 1);
    assert_eq!(q.empty(), false);
}
