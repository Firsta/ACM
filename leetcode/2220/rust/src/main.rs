pub fn min_bit_flips(start: i32, goal: i32) -> i32 {
    let mut start = start;
    let mut goal = goal;
    let mut ans = 0;
    while start > 0 || goal > 0 {
        let a = start % 2;
        let b = goal % 2;
        if a != b {
            ans += 1;
        }
        start /= 2;
        goal /= 2;
    }
    ans
}

fn main() {
    assert_eq!(min_bit_flips(10, 7), 3);
}
