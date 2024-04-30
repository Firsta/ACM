use std::collections::HashMap;

pub fn wonderful_substrings(word: String) -> i64 {
    let mut m = HashMap::new();

    let mut x: i32 = 0;
    let mut ans = 0;
    let mut max_bit_move = 0;

    for c in word.chars() {
        let bit_move = c as u8 - b'a';

        x ^= 1 << bit_move;

        ans += m.get(&x).unwrap_or(&0);

        if x.count_ones() <= 1 {
            ans += 1;
        }

        max_bit_move = std::cmp::max(max_bit_move, bit_move);
        for i in 0..=max_bit_move {
            let k = x ^ (1 << i);
            if let Some(c) = m.get(&k) {
                ans += c;
            }
        }

        m.entry(x).and_modify(|e| *e += 1).or_insert(1);
    }

    ans
}

pub fn wonderful_substrings_b(word: String) -> i64 {
    let mut ans = 0;
    for i in 0..word.len() {
        for j in 0..=i {
            let mut x: i32 = 0;
            for k in j..=i {
                let m = word.as_bytes()[k] - b'a';
                x ^= 1 << m;
            }
            if x.count_ones() <= 1 {
                ans += 1;
            }
        }
        println!("{}", &word[0..=i]);
        println!("{}", ans);
    }
    ans
}

fn main() {
    assert_eq!(
        wonderful_substrings(
            "gecbiifbecadfjifhfaabbfcdfcdbcjhhefhdedjbbbfjaffjdcfbibacgaeihbhfb".to_string(),
        ),
        127
    );
    assert_eq!(wonderful_substrings("aabb".to_string(),), 9);
    assert_eq!(wonderful_substrings("aba".to_string(),), 4);
    assert_eq!(wonderful_substrings("he".to_string(),), 2);
}
