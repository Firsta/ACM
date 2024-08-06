pub fn minimum_pushes(word: String) -> i32 {
    let mut cnt = vec![0; 26];
    for c in word.chars() {
        cnt[c as usize - 'a' as usize] += 1;
    }
    cnt.sort_by(|a, b| b.cmp(&a));

    let mut ans = 0;
    for (i, c) in cnt.into_iter().enumerate() {
        ans += (i / 8 + 1) * c;
    }

    ans as i32
}

fn main() {
    assert_eq!(minimum_pushes("aabbccddeeffgghhiiiiii".to_string()), 24);
}
