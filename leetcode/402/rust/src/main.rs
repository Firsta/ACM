pub fn remove_kdigits(num: String, k: i32) -> String {
    let mut s = Vec::new();
    let k = k as usize;

    let l = num.len() - k;

    for (i, c) in num.chars().enumerate() {
        let x = c.to_digit(10).unwrap();
        while !s.is_empty() && *s.last().unwrap() > x && num.len() - i > l - s.len() {
            s.pop();
        }
        if s.len() < l {
            s.push(x);
        }
    }
    // println!("{:?}", s);

    let mut i = 0;
    while i < s.len() && s[i] == 0 {
        i += 1;
    }
    // println!("{}", i);

    if i == s.len() {
        0.to_string()
    } else {
        s[i..]
            .iter()
            .map(|x| char::from_digit(*x, 10).unwrap())
            .collect()
    }
}
fn main() {
    assert_eq!(remove_kdigits("1432219".to_string(), 3), "1219".to_string());
    assert_eq!(remove_kdigits("10200".to_string(), 1), "200".to_string());
    assert_eq!(remove_kdigits("10".to_string(), 2), "0".to_string());
}
