pub fn is_anagram(s: String, t: String) -> bool {
    let mut c = vec![0; 26];
    for cc in s.chars() {
        c[cc as usize - 'a' as usize] += 1;
    }
    for cc in t.chars() {
        c[cc as usize - 'a' as usize] -= 1;
    }
    for i in 0..26 {
        if c[i] != 0 {
            return false;
        }
    }
    true
}

fn main() {
    println!("{}", is_anagram("anagram".to_string(), "nagaram".to_string()));
}
