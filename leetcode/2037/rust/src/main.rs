pub fn min_moves_to_seat(seats: Vec<i32>, students: Vec<i32>) -> i32 {
    let mut seats = seats;
    seats.sort();

    let mut students = students;
    students.sort();

    let mut ans = 0;
    for i in 0..seats.len() {
        ans += (seats[i] - students[i]).abs();
    }

    ans
}

fn main() {
    assert_eq!(min_moves_to_seat(vec![3, 1, 5], vec![2, 7, 4]), 4);
}
