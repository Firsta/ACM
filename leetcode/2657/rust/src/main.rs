pub fn find_the_prefix_common_array(a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {
    let n = a.len();
    let mut p1 = vec![false; n];
    let mut p2 = p1.clone();
    let mut ans = Vec::new();
    let mut cnt = 0;
    for i in 0..n {
        if p2[a[i] as usize - 1] {
            cnt += 1;
        }
        p1[a[i] as usize - 1] = true;
        if p1[b[i] as usize - 1] {
            cnt += 1;
        }
        p2[b[i] as usize - 1] = true;

        ans.push(cnt);
    }
    ans
}

fn main() {
    assert_eq!(
        find_the_prefix_common_array(vec![1, 3, 2, 4], vec![3, 1, 2, 4]),
        vec![0, 2, 3, 4]
    );
    assert_eq!(
        find_the_prefix_common_array(vec![1, 2, 3, 4], vec![1, 2, 3, 4]),
        vec![1, 2, 3, 4]
    );
    assert_eq!(
        find_the_prefix_common_array(vec![2, 3, 1], vec![3, 1, 2]),
        vec![0, 1, 3]
    );
}
