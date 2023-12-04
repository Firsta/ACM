use core::cmp::max;

pub fn largest_good_integer(num: String) -> String {
    let mut result:i32 = -1;
    for i in 0..num.len() - 2 {
        let a = num.chars().nth(i).unwrap();
        let b = num.chars().nth(i + 1).unwrap();
        let c = num.chars().nth(i + 2).unwrap();

        if a == b && b == c {
            result = max(result, a as i32 - '0' as i32);
        }
    }
    match result {
        -1 => "".to_string(),
        0 => "000".to_string(),
        _ => (result * 100 + result * 10 + result).to_string()
    }
}

fn main() {
    println!("{}", largest_good_integer("2300019".to_string()));
}
