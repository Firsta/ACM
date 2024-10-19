pub fn find_kth_bit(n: i32, k: i32) -> char {
    /*
    0
    0 1 1
    011 1 001
    0111001 1 0110001
    */
    if n == 1 {
        return '0';
    }
    let cnt = 2i32.pow(n as u32) - 1;
    if k == cnt / 2 + 1 {
        '1'
    } else if k < cnt / 2 + 1 {
        find_kth_bit(n - 1, k)
    } else {
        let c = find_kth_bit(n - 1, cnt - k + 1);
        if c == '1' {
            '0'
        } else {
            '1'
        }
    }
}

fn main() {
    assert_eq!(find_kth_bit(1, 1), '0');
    assert_eq!(find_kth_bit(3, 1), '0');
    assert_eq!(find_kth_bit(4, 11), '1');
}
