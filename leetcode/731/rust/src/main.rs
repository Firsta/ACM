#[derive(Default)]
struct MyCalendarTwo {
    booked: Vec<(i32, i32)>,
    twos: Vec<(i32, i32)>,
}

fn overlap(a: &(i32, i32), b: &(i32, i32)) -> bool {
    (b.0 <= a.0 && a.0 <= b.1)
        || (b.0 <= a.1 && a.1 <= b.1)
        || (a.0 <= b.0 && b.0 <= a.1)
        || (a.0 <= b.1 && b.1 <= a.1)
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyCalendarTwo {
    fn new() -> Self {
        Default::default()
    }

    fn book(&mut self, start: i32, end: i32) -> bool {
        let n = (start, end - 1);

        for t in self.twos.iter() {
            if overlap(&n, &t) {
                return false;
            }
        }

        for b in self.booked.iter() {
            if overlap(&n, &b) {
                self.twos
                    .push((std::cmp::max(n.0, b.0), std::cmp::min(n.1, b.1)));
            }
        }

        self.booked.push(n);

        true
    }
}

fn main() {
    let mut m = MyCalendarTwo::new();
    assert_eq!(m.book(10, 20), true);
    assert_eq!(m.book(50, 60), true);
    assert_eq!(m.book(10, 40), true);
    assert_eq!(m.book(5, 15), false);
    assert_eq!(m.book(5, 10), true);
    assert_eq!(m.book(25, 55), true);
}
