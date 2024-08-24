fn from_half(h: i64, even: bool) -> i64 {
    format!("{}{}", h, {
        let hs = h.to_string();
        let ol = if even { hs.len() } else { hs.len() - 1 };
        let o = &hs[0..ol];
        // println!("{}", o);
        o.chars().rev().collect::<String>()
    })
    .parse::<i64>()
    .unwrap()
}

pub fn nearest_palindromic(n: String) -> String {
    if n.len() == 1 {
        (n.parse::<i32>().unwrap() - 1).to_string()
    } else {
        let nn = n.parse::<i64>().unwrap();

        let mut c = Vec::new();
        c.push(
            (0..n.len() - 1)
                .map(|_| "9")
                .collect::<String>()
                .parse::<i64>()
                .unwrap(),
        );

        let h = n[0..(n.len() + 1) / 2].to_string().parse::<i64>().unwrap();
        let even = n.len() % 2 == 0;
        c.push(from_half(h, even));
        c.push(from_half(h - 1, even));
        c.push(from_half(h + 1, even));
        c.push(10i64.pow(n.len() as u32) + 1);

        // println!("{:?}", c);

        let mut ans = 0;
        let mut min_d = std::i64::MAX;

        for cc in c.into_iter() {
            if cc != nn {
                let d = (cc - nn).abs();
                if d == min_d && cc < ans {
                    ans = cc;
                } else if d < min_d {
                    ans = cc;
                    min_d = d;
                }
            }
        }

        ans.to_string()
    }
}

fn main() {
    assert_eq!(nearest_palindromic("123".to_string()), "121".to_string());
    assert_eq!(nearest_palindromic("99".to_string()), "101".to_string());
}
