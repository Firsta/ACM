pub fn count_seniors(details: Vec<String>) -> i32 {
    details
        .into_iter()
        .map(|x| x[11..13].parse::<u8>().unwrap())
        .filter(|age| *age > 60)
        .count() as i32
}

fn main() {
    assert_eq!(
        count_seniors(vec![
            "7868190130M7522".to_string(),
            "5303914400F9211".to_string(),
            "9273338290F4010".to_string()
        ]),
        2
    );
}
