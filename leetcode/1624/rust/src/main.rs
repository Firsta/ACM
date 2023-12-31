pub fn max_length_between_equal_characters(s: String) -> i32 {
    let mut left = vec![None; 26];
    let mut result = -1;
    for i in 0..s.len() {
        let ii = s.as_bytes()[i] as usize - 'a' as usize;
        match left[ii] {
            None => {
                left[ii] = Some(i);
            },
            Some(l) => {
                result = std::cmp::max(result, (i - l - 1) as i32);
            }
        }
    }
    result
}

fn main() {
    println!("{}", max_length_between_equal_characters("aa".to_string()));
}
