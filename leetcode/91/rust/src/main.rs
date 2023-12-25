pub fn num_decodings(s: String) -> i32 {
    let (mut dp, mut dpp, mut former) = (1, 1, None);
    for c in s.chars() {
        let d = c as u8 - '0' as u8;
        match former {
            None => {
                if d == 0 {
                    return 0;
                }
            },
            Some(f) => {
                if d == 0 {
                    if f == 0 {
                        // 100
                        return 0;
                    } else {
                        let n = f * 10 + d;
                        if n > 20 {
                            // 130
                            return 0;
                        } else {
                            // 120
                            let tmp = dp;
                            dp = dpp;
                            dpp = tmp;
                        }
                    }
                } else {
                    // d > 0
                    if f == 0 {
                        // 101
                        dpp = dp;
                    } else {
                        let n = f * 10 + d;
                        if n <= 26 {
                            // 111
                            // println!("!");
                            let tmp = dp;
                            dp = dp + dpp;
                            dpp = tmp;
                        } else {
                            // 131
                            dpp = dp;
                        }
                    }
                }
            }
        }
        
        former = Some(d);
        // println!("{} {} {:?}", dp, dpp, former);
    }
    dp
}

fn main() {
    println!("{}", num_decodings("123123".to_string()));
}
