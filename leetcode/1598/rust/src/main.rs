pub fn min_operations(logs: Vec<String>) -> i32 {
    let mut d = 0;
    for l in logs.into_iter() {
        if l == "../" {
            d = std::cmp::max(d - 1, 0);
        } else if l != "./" {
            d += 1;
        }
    }

    d
}

fn main() {
    assert_eq!(
        min_operations(vec![
            "d1/".to_string(),
            "d2/".to_string(),
            "../".to_string(),
            "d21/".to_string(),
            "./".to_string()
        ]),
        2
    );
}
