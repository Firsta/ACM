pub fn maximum_odd_binary_number(s: String) -> String {
    let (mut one_count, mut zero_count) = (0, 0);

    for c in s.chars() {
        if c == '1' {
            one_count += 1;
        } else {
            zero_count += 1;
        }
    }

    one_count -= 1;
    let mut result = String::new();
    while one_count > 0 {
        result.push_str("1");
        one_count -= 1;
    }
    while zero_count > 0 {
        result.push_str("0");
        zero_count -= 1;
    }
    result.push_str("1");
    result
}

fn main() {
    assert_eq!(
        maximum_odd_binary_number("010".to_string()),
        "001".to_string()
    );
    assert_eq!(
        maximum_odd_binary_number("0101".to_string()),
        "1001".to_string()
    );
}
