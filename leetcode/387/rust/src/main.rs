pub fn first_uniq_char(s: String) -> i32 {
    let mut cnt = vec![0; 26];
    let mut fo = vec![None; 26];
    for (i, c) in s.chars().enumerate() {
        let l = c as usize - 'a' as usize;
        cnt[l] += 1;
        if fo[l].is_none() {
            fo[l] = Some(i);
        }
    }
    let mut result = 100010;
    for (i, &c) in cnt.iter().enumerate() {
        if c == 1 {
            result = std::cmp::min(result, fo[i].unwrap());
        }
    }

    if result == 100010 {
        -1
    } else {
        result as i32
    }
}

fn main() {
    println!("{}", first_uniq_char("loveleetcode".to_string()));
}
