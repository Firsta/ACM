pub fn can_be_equal(target: Vec<i32>, arr: Vec<i32>) -> bool {
    let mut v = vec![0; 1000];
    for t in target.into_iter() {
        v[t as usize - 1] += 1;
    }
    for t in arr.into_iter() {
        v[t as usize - 1] -= 1;
    }
    for vv in v.into_iter() {
        if vv != 0 {
            return false;
        }
    }
    true
}
fn main() {
    assert_eq!(can_be_equal(vec![1, 2, 3, 4], vec![2, 4, 1, 3]), true);
}
