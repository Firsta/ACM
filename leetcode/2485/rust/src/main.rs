pub fn pivot_integer(n: i32) -> i32 {
    let sum = (n + 1) * n / 2;

    let mut c = 0;
    for i in 1..=n {
        if c + i == sum - c {
            return i;
        }

        c += i
    }

    -1
}

fn main() {
    assert_eq!(pivot_integer(8), 6);
    assert_eq!(pivot_integer(1), 1);
    assert_eq!(pivot_integer(4), -1);
}
