use std::collections::HashMap;

pub fn min_operations(nums: Vec<i32>) -> i32 {
    let mut c = HashMap::new();
    let mut result = 0usize;

    for n in nums.iter() {
        let new_count = match c.get(&n) {
            Some(count) => count + 1,
            None => 1
        };
        c.insert(n, new_count);
    }

    for (_, val) in c.iter() {
        match val {
            1 => {
                return -1;
            },
            2 => {
                result += 1;
            },
            _ => {
                if val % 3 == 0 {
                    result += val / 3
                } else if val % 3 == 1 {
                    result += (val - 4) / 3 + 2;
                } else {
                    result += val / 3 + 1;
                }
            }
        }
    }
    result as i32
}

fn main() {
    println!("{}", min_operations(vec![2,3,3,2,2,4,2,3,4]));
}
