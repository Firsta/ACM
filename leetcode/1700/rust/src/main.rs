pub fn count_students(students: Vec<i32>, sandwiches: Vec<i32>) -> i32 {
    let mut one_students = students.iter().filter(|&x| *x == 1).count();
    let mut zero_students = students.len() - one_students;

    for s in sandwiches.iter() {
        match s {
            1 => {
                if one_students > 0 {
                    one_students -= 1;
                } else {
                    return zero_students as i32;
                }
            }
            0 => {
                if zero_students > 0 {
                    zero_students -= 1;
                } else {
                    return one_students as i32;
                }
            }
            _ => (),
        }

        // println!("{} {}", zero_students, one_students);
    }

    (zero_students + one_students) as i32
}

fn main() {
    assert_eq!(count_students(vec![1, 1, 0, 0], vec![0, 1, 0, 1]), 0);
    assert_eq!(
        count_students(vec![1, 1, 1, 0, 0, 1], vec![1, 0, 0, 0, 1, 1]),
        3
    );
}
