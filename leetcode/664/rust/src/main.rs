use std::collections::HashMap;

pub fn strange_printer(s: String) -> i32 {
    fn foo<'a>(s: &'a str, dp: &mut HashMap<&'a str, i32>) -> i32 {
        // println!("{}", s);
        match dp.get(&s) {
            Some(x) => *x,
            None => {
                if s.is_empty() {
                    0
                } else if s.len() == 1 {
                    1
                } else {
                    let c = s.chars().last().unwrap();

                    let mut r = (s.len() - 1) as i32;
                    while r >= 0 && s.chars().nth(r as usize).unwrap() == c {
                        r -= 1;
                    }
                    if r == -1 {
                        return 1;
                    }
                    let mut ans = foo(&s[0..=r as usize], dp) + 1;

                    for l in (0..=r).rev() {
                        if s.chars().nth(l as usize).unwrap() == c {
                            ans = std::cmp::min(
                                ans,
                                foo(&s[0..=l as usize], dp)
                                    + foo(&s[(l + 1) as usize..=r as usize], dp),
                            );
                        }
                    }

                    dp.insert(s, ans);
                    ans
                }
            }
        }
    }

    let mut dp = HashMap::new();
    let ans = foo(&s, &mut dp);
    ans
}

fn main() {
    assert_eq!(
        strange_printer("dddccbdbababaddcbcaabdbdddcccddbbaabddb".to_string()),
        15
    );
}
