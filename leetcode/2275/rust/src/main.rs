pub fn largest_combination(candidates: Vec<i32>) -> i32 {
    let mut bit = vec![0; 32];
    for c in candidates {
        let mut c = c;
        let mut b = 0;
        while c > 0 {
            if c % 2 == 1 {
                bit[b] += 1;
            }
            c /= 2;
            b += 1;
        }
    }
    bit.into_iter().max().unwrap()
}

fn main() {
    assert_eq!(largest_combination(vec![16, 17, 71, 62, 12, 24, 14]), 4);
}
