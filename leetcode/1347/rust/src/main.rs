pub fn min_steps(s: String, t: String) -> i32 {
    let mut v = vec![0; 26];
    for c in s.chars() {
        v[c as usize - 'a' as usize] += 1;
    }
    for c in t.chars() {
        if v[c as usize - 'a' as usize] > 0 {
            v[c as usize - 'a' as usize] -= 1;
        }
    }
    v.iter().sum()
}

fn main() {
    println!("{}", min_steps("anagram".to_string(), "mangaar".to_string()));
}
