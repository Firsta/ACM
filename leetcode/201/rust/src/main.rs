fn bit_length(num: i64) -> i32 {
    let mut n = 0i32;
    let mut x = 1i64;
    while x <= num {
        x *= 2;
        n += 1;
    }
    n
}

pub fn range_bitwise_and(left: i32, right: i32) -> i32 {
    let bll = bit_length(left as i64);
    let rll = bit_length(right as i64);
    // println!("{} {}", bll, rll);
    if bll != rll {
        0
    } else {
        // 101
        // 111
        let mut result = 0;
        for i in (0..=rll - 1).rev() {
            // println!("{}", i);
            let a = 1 << i;
            if (a & left) == (a & right) {
                result |= a & left;
            } else {
                break;
            }
        }
        result
    }
}

fn main() {
    assert_eq!(range_bitwise_and(2, 2), 2);
    assert_eq!(range_bitwise_and(1, 1), 1);
    assert_eq!(range_bitwise_and(0, 0), 0);
    assert_eq!(range_bitwise_and(5, 7), 4);
    assert_eq!(range_bitwise_and(1, 2147483647), 0);
}
