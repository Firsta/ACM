pub fn count_characters(words: Vec<String>, chars: String) -> i32 {
    let mut chars_counts = vec![0; 26];
    for c in chars.chars() {
        chars_counts[c as usize - 'a' as usize] += 1;
    }

    let mut result = 0;
    for word in words {
        let mut local_chars_map = chars_counts.clone();
        let mut ok = true;
        for c in word.chars() {
            if local_chars_map[c as usize - 'a' as usize] == 0 {
                ok = false;
                break;
            } else {
                local_chars_map[c as usize - 'a' as usize] -= 1;
            }
        }
        if ok {
            result += word.len();
        }
    }

    result as i32
}

fn main() {
    println!("{}", count_characters(vec!["cat".to_string(),"bt".to_string(),"hat".to_string(),"tree".to_string()], "atach".to_string()));
}
