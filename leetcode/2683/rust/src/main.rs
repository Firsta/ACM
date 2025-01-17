pub fn does_valid_array_exist(derived: Vec<i32>) -> bool {
    if derived.len() == 1 {
        return derived[0] == 0;
    }
    let mut same = derived[0] == 0;
    for i in 1..derived.len() - 1 {
        if derived[i] == 1 {
            same = !same;
        }
    }
    // println!("{}", same);
    (derived[derived.len() - 1] == 0) == same
}

fn main() {
    assert_eq!(does_valid_array_exist(vec![1, 1, 0]), true);
    assert_eq!(does_valid_array_exist(vec![1, 1]), true);
    assert_eq!(does_valid_array_exist(vec![1, 0]), false);
    assert_eq!(does_valid_array_exist(vec![1]), false);
}
