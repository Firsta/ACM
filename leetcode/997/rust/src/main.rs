pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32 {
    let mut v = vec![0; n as usize];
    for t in trust {
        v[(t[0] - 1) as usize] -= 1;
        v[(t[1] - 1) as usize] += 1;
    }

    for (idx, vv) in v.iter().enumerate() {
        if *vv == n - 1 {
            return idx as i32 + 1;
        }
    }

    -1
}

fn main() {
    assert_eq!(find_judge(3, vec![vec![1, 3], vec![2, 3], vec![3, 1]]), -1);
    assert_eq!(find_judge(3, vec![vec![1, 3], vec![2, 3]]), 3);
}
