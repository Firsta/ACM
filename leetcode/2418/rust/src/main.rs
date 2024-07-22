pub fn sort_people(names: Vec<String>, heights: Vec<i32>) -> Vec<String> {
    let mut v = Vec::new();
    for (i, name) in names.into_iter().enumerate() {
        v.push((name, heights[i]));
    }

    v.sort_by(|x, y| y.1.cmp(&x.1));

    v.into_iter().map(|x| x.0).collect()
}

fn main() {
    assert_eq!(
        sort_people(
            vec!["Mary".to_string(), "John".to_string(), "Emma".to_string()],
            vec![180, 165, 170]
        ),
        vec!["Mary".to_string(), "Emma".to_string(), "John".to_string()]
    );
    assert_eq!(
        sort_people(
            vec!["Alice".to_string(), "Bob".to_string(), "Bob".to_string()],
            vec![155, 185, 150]
        ),
        vec!["Bob".to_string(), "Alice".to_string(), "Bob".to_string()]
    );
}
