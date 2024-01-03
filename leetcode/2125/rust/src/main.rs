pub fn number_of_beams(bank: Vec<String>) -> i32 {
    let mut result = 0;
    let mut f = 0;
    for s in bank.iter() {
        let t = s.chars().filter(|c| *c == '1').count();
        if t > 0 {
            result += f * t;
            f = t;
        }
    }
    result as i32
}

fn main() {
    println!("{}", number_of_beams(vec!["011001".to_string(), "000000".to_string(), "010100".to_string(), "001000".to_string()]));
}
