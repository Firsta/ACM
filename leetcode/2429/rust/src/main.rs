pub fn minimize_xor(num1: i32, num2: i32) -> i32 {
    let mut one_cnt = 0;
    let mut t = num2;
    while t > 0 {
        one_cnt += t % 2;
        t /= 2;
    }
    let mut bs1 = Vec::new();
    let mut t = num1;
    while t > 0 {
        bs1.push(t % 2);
        t /= 2;
    }
    bs1.reverse();
    // println!("{bs1:?}");
    let mut set = vec![false; bs1.len()];
    for i in 0..bs1.len() {
        if one_cnt > 0 {
            if bs1[i] == 1 {
                bs1[i] = 0;
                one_cnt -= 1;
                set[i] = true;
            }
        } else {
            break;
        }
    }
    for i in (0..bs1.len()).rev() {
        if one_cnt > 0 && !set[i] {
            one_cnt -= 1;
            bs1[i] = 1;
        }
    }
    // println!("{bs1:?}");

    let mut ans = 0;

    while one_cnt > 0 {
        ans = ans * 2 + 1;
        one_cnt -= 1;
    }
    for i in 0..bs1.len() {
        ans = ans * 2 + bs1[i];
    }
    // println!("{}", ans);
    ans ^ num1
}

fn main() {
    assert_eq!(minimize_xor(3, 5), 3);
    assert_eq!(minimize_xor(1, 12), 3);
}
