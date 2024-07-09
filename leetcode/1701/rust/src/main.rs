pub fn average_waiting_time(customers: Vec<Vec<i32>>) -> f64 {
    let mut wait = 0i64;
    let mut idle = 0i64;
    let n = customers.len();

    for c in customers.into_iter() {
        let arrival = c[0] as i64;
        let time = c[1] as i64;

        if idle <= arrival {
            wait += time;
            idle = arrival + time;
        } else {
            wait += idle - arrival + time;
            idle = idle + time;
        }
    }

    (wait as f64) / n as f64
}

fn main() {
    assert_eq!(
        average_waiting_time(vec![vec![1, 2], vec![2, 5], vec![4, 3]]),
        5.0
    );
    assert_eq!(
        average_waiting_time(vec![vec![5, 2], vec![5, 4], vec![10, 3], vec![20, 1]]),
        3.25000
    );
}
