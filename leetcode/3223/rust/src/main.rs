pub fn minimum_length(s: String) -> i32 {
    let mut cnt = vec![0; 26];
    for c in s.chars() {
        cnt[c as usize - 'a' as usize] += 1;
    }
    // println!("{:?}", cnt);
    let mut ans = 0;
    for i in 0..26 {
        if cnt[i] > 0 {
            ans += if cnt[i] % 2 == 1 { 1 } else { 2 }
        }
    }
    ans
}

fn main() {
    assert_eq!(minimum_length("abaacbcbb".to_string()), 5);
}
