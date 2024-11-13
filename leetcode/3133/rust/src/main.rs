pub fn min_end(n: i32, x: i32) -> i64 {
    let mut n = n - 1;
    let mut x = x;
    let mut v = Vec::new();
    loop {
        match x % 2 {
            0 => {
                v.push(n % 2);
                n /= 2;
            }
            1 => {
                v.push(1);
            }
            _ => panic!(),
        }
        x /= 2;
        if x == 0 && n == 0 {
            break;
        }
    }

    let mut ans = 0;
    for i in (0..v.len()).rev() {
        ans = ans * 2 + v[i] as i64;
    }
    ans
}

fn main() {
    assert_eq!(min_end(3, 4), 6);
    assert_eq!(min_end(2, 7), 15);
}
