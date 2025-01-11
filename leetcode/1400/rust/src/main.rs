pub fn can_construct(s: String, k: i32) -> bool {
    let k = k as usize;
    if s.len() < k {
        false
    } else if s.len() == k {
        true
    } else {
        let mut cnt = vec![0; 26];
        for c in s.chars() {
            cnt[c as usize - 'a' as usize] += 1;
        }
        let mut odd = 0;
        for i in 0..26 {
            if cnt[i] % 2 != 0 {
                odd += 1;
            }
        }
        if odd > k {
            false
        } else {
            let rest = k - odd;
            if s.len() - odd >= rest {
                true
            } else {
                false
            }
        }
    }
}

fn main() {
    assert_eq!(can_construct("ibzkwaxxaggkiwjbeysz".to_string(), 15), true);
}
