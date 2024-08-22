pub fn find_complement(num: i32) -> i32 {
    (!num << (32 - (num.ilog2() + 1))) >> (32 - (num.ilog2() + 1))
}

fn main() {
    assert_eq!(find_complement(5), 2);
}
