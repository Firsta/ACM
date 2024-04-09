use std::collections::VecDeque;

pub fn time_required_to_buy(tickets: Vec<i32>, k: i32) -> i32 {
    let mut q = VecDeque::from(
        tickets
            .into_iter()
            .enumerate()
            .collect::<Vec<(usize, i32)>>(),
    );

    let mut result = 0;

    loop {
        let mut t = q.pop_front().unwrap();
        t.1 -= 1;
        result += 1;
        if t.1 == 0 {
            if t.0 == k as usize {
                return result;
            }
        } else {
            q.push_back(t);
        }
    }
}

fn main() {
    assert_eq!(time_required_to_buy(vec![2, 3, 2], 2), 6);
    assert_eq!(time_required_to_buy(vec![5, 1, 1, 1], 0), 8);
}
