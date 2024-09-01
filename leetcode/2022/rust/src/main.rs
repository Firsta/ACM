pub fn construct2_d_array(original: Vec<i32>, m: i32, n: i32) -> Vec<Vec<i32>> {
    let m = m as usize;
    let n = n as usize;

    if original.len() != m * n {
        Vec::new()
    } else {
        let mut ans = Vec::new();
        for i in 0..m {
            ans.push(Vec::new());
            for j in 0..n {
                // println!("{} {}", i, j);
                ans[i].push(original[i * n + j]);
            }
        }
        ans
    }
}

fn main() {
    assert_eq!(
        construct2_d_array(vec![1, 2, 3, 4], 2, 2),
        vec![vec![1, 2], vec![3, 4]]
    );
    assert_eq!(construct2_d_array(vec![1, 2, 3], 1, 3), vec![vec![1, 2, 3]]);
    assert!(construct2_d_array(vec![1, 2], 1, 1).is_empty());
}
