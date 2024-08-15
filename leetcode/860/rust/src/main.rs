pub fn lemonade_change(bills: Vec<i32>) -> bool {
    let mut m = vec![0; 2];
    for b in bills.into_iter() {
        match b {
            5 => m[0] += 1,
            10 => {
                if m[0] == 0 {
                    return false;
                } else {
                    m[0] -= 1;
                    m[1] += 1;
                }
            }
            _ => {
                if m[0] >= 1 && m[1] >= 1 {
                    m[0] -= 1;
                    m[1] -= 1;
                } else if m[0] >= 3 {
                    m[0] -= 3;
                } else {
                    return false;
                }
            }
        }
    }
    true
}
fn main() {
    assert_eq!(lemonade_change(vec![5, 5, 5, 10, 20]), true);
    assert_eq!(lemonade_change(vec![5, 5, 10, 10, 20]), false);
}
