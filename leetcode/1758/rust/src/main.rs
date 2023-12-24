use std::cmp::min;

pub fn min_operations(s: String) -> i32 {
    let mut tail0 = 0;
    let mut tail1 = 0;
    for c in s.chars() {
        if c == '1' {
            let tmp = tail0;
            tail0 = tail1 + 1;
            tail1 = tmp;
        } else {
            let tmp = tail1;
            // println!("{}", tmp);
            tail1 = tail0 + 1;
            // println!("{}", tmp);
            tail0 = tmp;
        }
        // println!("{} {}", tail0, tail1);
    }
    min(tail0, tail1)
}

fn main() {
    println!("{}", min_operations("0100".to_string()));
}
