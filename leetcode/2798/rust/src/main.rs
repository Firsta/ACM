pub fn number_of_employees_who_met_target(hours: Vec<i32>, target: i32) -> i32 {
    hours.into_iter().filter(|x| *x >= target).count() as i32
}

fn main() {
    assert_eq!(
        number_of_employees_who_met_target(vec![0, 1, 2, 3, 4], 2),
        3
    );
}
