pub fn close_strings(word1: String, word2: String) -> bool {
    if word1.len() == word2.len() {
        let mut c1 = vec![0; 26];
        for c in word1.chars() {
            c1[c as usize - 'a' as usize] += 1;
        }
        let mut c2 = vec![0; 26];
        for c in word2.chars() {
            c2[c as usize - 'a' as usize] += 1;
        }
        
        for i in 0..c1.len() {
            if (c1[i] > 0) != (c2[i] > 0) {
                return false;
            }
        }

        for cc1 in c1.iter() {
            if *cc1 > 0 {
                match c2.iter().position(|&x| x == *cc1) {
                    None => {
                        return false;
                    },
                    Some(idx) => {
                        c2[idx] = 0;
                    }
                }
            }
        }
        
        for cc2 in c2.iter() {
            if *cc2 > 0 {
                return false;
            }
        }
        
        true
    } else {
        false
    }
}

fn main() {
    println!("{}", close_strings("abc".to_string(), "bca".to_string()));
}
