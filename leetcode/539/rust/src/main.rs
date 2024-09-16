pub fn find_min_difference(time_points: Vec<String>) -> i32 {
    let mut ms = time_points
        .into_iter()
        .map(|x| x[0..2].parse::<i32>().unwrap() * 60 + x[3..].parse::<i32>().unwrap())
        .collect::<Vec<i32>>();

    ms.sort();

    let mut diff = std::i32::MAX;
    for i in 0..ms.len() {
        if i < ms.len() - 1 {
            diff = std::cmp::min(diff, ms[i + 1] - ms[i]);
        } else {
            diff = std::cmp::min(diff, 60 * 24 - (ms[i] - ms[0]));
        }
    }

    diff
}

fn main() {
    assert_eq!(
        find_min_difference(vec!["23:59".to_string(), "00:00".to_string()]),
        1
    );
}
