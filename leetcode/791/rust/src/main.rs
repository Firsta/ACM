pub fn custom_sort_string(order: String, s: String) -> String {
    let mut cnt = vec![0usize; order.len()];
    let mut result = String::new();
    for cs in s.chars() {
        let mut find = false;
        for (idx, co) in order.chars().enumerate() {
            // println!("{} {}", co, cs);
            if co == cs {
                cnt[idx] += 1;
                find = true;
                break;
            }
        }
        if !find {
            result.push(cs);
        }
    }

    for i in 0..cnt.len() {
        for _j in 0..cnt[i] {
            result.push(order.as_bytes()[i] as char);
        }
    }

    result
}

fn main() {
    assert_eq!(
        custom_sort_string("cba".to_string(), "abcd".to_string()),
        "dcba".to_string()
    );
    assert_eq!(
        custom_sort_string("bcafg".to_string(), "abcd".to_string()),
        "dbca".to_string()
    );
}
