pub fn check_if_exist(arr: Vec<i32>) -> bool {
    let zc = arr.iter().filter(|x| **x == 0).count();
    if zc > 1 {
        return true;
    }
    let m: std::collections::HashSet<i32> = std::collections::HashSet::from_iter(arr);
    for mm in m.iter() {
        if *mm != 0 && m.contains(&(*mm * 2)) {
            return true;
        }
    }

    false
}
fn main() {
    assert_eq!(check_if_exist(vec![10, 2, 5, 3]), true);
    assert_eq!(check_if_exist(vec![3, 1, 7, 11]), false);
    assert_eq!(check_if_exist(vec![0, 0]), true);
    assert_eq!(check_if_exist(vec![-2, 0, 10, -19, 4, 6, -8]), false);
}
