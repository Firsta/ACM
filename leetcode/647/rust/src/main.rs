pub trait CharAt {
    fn char_at(&self, i: usize) -> char;
}

impl CharAt for String {
    fn char_at(&self, i: usize) -> char {
        self.as_bytes()[i] as char
    }
}

pub fn count_substrings(s: String) -> i32 {
    let mut result = 0;
    let mut dp: Vec<Vec<usize>> = Vec::new();
    for i in 0..s.len() {
        let mut v = Vec::new();
        v.push(i);

        let ci = s.char_at(i);

        if i > 0 {
            if ci == s.char_at(i - 1) {
                v.push(i - 1);
            }
            for &p in dp[i - 1].iter() {
                if p > 0 && ci == s.char_at(p - 1) {
                    v.push(p - 1);
                }
            }
        }
        result += v.len() as i32;
        dp.push(v);
    }

    result
}

fn main() {
    println!("{}", count_substrings("aaa".to_string()));
}
