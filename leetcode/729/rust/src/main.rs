struct MyCalendar {
    booked: Vec<(i32, i32)>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyCalendar {
    fn new() -> Self {
        Self {
            booked: Default::default(),
        }
    }

    fn book(&mut self, start: i32, end: i32) -> bool {
        let end = end - 1;
        for b in self.booked.iter() {
            if (b.0 <= start && start <= b.1)
                || (b.0 <= end && end <= b.1)
                || (start <= b.0 && b.0 <= end)
                || (start <= b.1 && b.1 <= end)
            {
                return false;
            }
        }
        self.booked.push((start, end));
        true
    }
}

fn main() {
    let mut c = MyCalendar::new();
    assert_eq!(c.book(10, 20), true);
    assert_eq!(c.book(15, 25), false);
    assert_eq!(c.book(20, 30), true);
}
