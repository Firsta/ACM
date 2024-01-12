use std::collections::HashSet;

pub fn halves_are_alike(s: String) -> bool {
    let vowels = HashSet::from(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);
        
    let mut count = 0;
    for c in s[0..s.len() / 2].chars() {
        if vowels.contains(&c) {
            count += 1;
        }
    }
    
    for c in s[s.len() / 2..].chars() {
        if vowels.contains(&c) {
            count -= 1;
        }
    }
    
    count == 0
}

fn main() {
    println!("{}", halves_are_alike("AbCdEfGh".to_string()));
}
