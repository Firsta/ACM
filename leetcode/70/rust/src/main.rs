pub fn climb_stairs(n: i32) -> i32 {
    if n == 1 {
        1
    } else if n == 2 {
        2
    } else {
        let mut a = 1;
        let mut b = 2;

        let mut lc = n - 2;
        while lc > 0 {
            let tmp = b;
            b = a + b;
            a = tmp;
            lc -= 1;
        }
        b
    }
}

fn main() {
    println!("{}", climb_stairs(3));
}
