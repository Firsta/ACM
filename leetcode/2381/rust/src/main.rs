pub fn shifting_letters(s: String, shifts: Vec<Vec<i32>>) -> String {
    let mut cs: Vec<char> = s.chars().collect();
    let mut p = vec![0; s.len()];
    for shift in shifts {
        let delta = if shift[2] == 1 { 1 } else { -1 };
        p[shift[0] as usize] += delta;
        if shift[1] as usize != s.len() - 1 {
            p[shift[1] as usize + 1] -= delta;
        }
    }
    // println!("{:?}", p);
    let mut d = 0i32;
    for i in 0..s.len() {
        d += p[i];
        // println!("{}", d);
        let mut t = cs[i] as usize - 'a' as usize;
        if d >= 0 {
            t = (t + d as usize) % 26;
        } else {
            let mut tt = (-d) as usize;
            tt %= 26;
            t = (t + 26 - tt) % 26;
        }
        cs[i] = (t + 'a' as usize) as u8 as char;
    }
    cs.into_iter().collect()
}

fn main() {
    assert_eq!(
        shifting_letters(
            "abc".to_string(),
            vec![vec![0, 1, 0], vec![1, 2, 1], vec![0, 2, 1]]
        ),
        "ace".to_string()
    );
}
