pub fn largest_odd_number(num: String) -> String {
    for (i, c) in num.chars().rev().enumerate() {
        if c.to_digit(10).unwrap() % 2 == 1 {
            return num[..num.len() - i].to_string();
        }
    }
    "".to_string()
}

fn main() {
    println!("{}", largest_odd_number("35427".to_string()));
}
