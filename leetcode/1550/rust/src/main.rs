pub fn three_consecutive_odds(arr: Vec<i32>) -> bool {
    let mut c = 0;
    for a in arr.into_iter() {
        if a % 2 == 1 {
            c += 1;
            if c == 3 {
                return true;
            }
        } else {
            c = 0;
        }
    }
    false
}

fn main() {
    assert_eq!(three_consecutive_odds(vec![2, 6, 4, 1]), false);
    assert_eq!(
        three_consecutive_odds(vec![1, 2, 34, 3, 4, 5, 7, 23, 12]),
        true
    );
}
