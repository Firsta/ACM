pub fn smallest_even_multiple(n: i32) -> i32 {
    if n % 2 == 0 {
        n
    } else {
        n * 2
    }
}

fn main() {
    assert_eq!(smallest_even_multiple(6), 6);
    assert_eq!(smallest_even_multiple(5), 10);
}
