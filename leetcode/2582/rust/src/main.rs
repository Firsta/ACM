pub fn pass_the_pillow(n: i32, time: i32) -> i32 {
    if time / (n - 1) % 2 == 0 {
        time % (n - 1) + 1
    } else {
        n - time % (n - 1)
    }
}

fn main() {
    assert_eq!(pass_the_pillow(4, 5), 2);
    assert_eq!(pass_the_pillow(3, 2), 3);
}
