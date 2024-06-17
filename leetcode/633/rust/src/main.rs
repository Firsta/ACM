pub fn judge_square_sum(c: i32) -> bool {
    let u = (c as f64).sqrt() as i32;
    for i in 0..=u {
        // println!("{}", i);
        let r = c - i * i;
        let s = (r as f64).sqrt() as i32;
        if s * s == r {
            return true;
        }
    }
    false
}

fn main() {
    assert_eq!(judge_square_sum(5), true);
    assert_eq!(judge_square_sum(3), false);
    assert_eq!(judge_square_sum(0), true);
}
