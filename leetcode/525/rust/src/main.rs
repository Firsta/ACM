use std::collections::HashMap;

pub fn find_max_length(nums: Vec<i32>) -> i32 {
    let mut cnt = 0;
    let mut m = HashMap::new();
    m.insert(0, 0);

    let mut result = 0;
    for (i, &n) in nums.iter().enumerate() {
        if n == 0 {
            cnt -= 1;
        } else {
            cnt += 1;
        }
        // println!("{}", cnt);
        if m.contains_key(&cnt) {
            // println!("x");
            result = std::cmp::max(result, (i - m.get(&cnt).unwrap() + 1) as i32);
        } else {
            m.insert(cnt, i + 1);
        }
    }

    result
}

fn main() {
    assert_eq!(find_max_length(vec![0, 1]), 2);
    assert_eq!(find_max_length(vec![0, 1, 0]), 2);
    assert_eq!(find_max_length(vec![1, 1]), 0);
}
