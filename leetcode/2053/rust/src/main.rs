use std::collections::HashMap;

pub fn kth_distinct(arr: Vec<String>, k: i32) -> String {
    let k = k as usize;

    let mut m = HashMap::new();
    for s in arr.iter() {
        m.entry(s.clone())
            .and_modify(|e| *e = true)
            .or_insert(false);
    }

    let mut cnt = 0;
    for s in arr.into_iter() {
        if let Some(x) = m.get(&s) {
            if *x == false {
                cnt += 1;
                if cnt == k {
                    return s.clone();
                }
            }
        }
    }

    "".to_string()
}

fn main() {
    assert_eq!(
        kth_distinct(
            vec![
                "d".to_string(),
                "b".to_string(),
                "c".to_string(),
                "b".to_string(),
                "c".to_string(),
                "a".to_string()
            ],
            2
        ),
        "a".to_string()
    );
}
