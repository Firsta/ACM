use std::collections::HashMap;

pub fn first_complete_index(arr: Vec<i32>, mat: Vec<Vec<i32>>) -> i32 {
    let mut n_to_idx = HashMap::new();
    for (idx, n) in arr.iter().enumerate() {
        n_to_idx.insert(n, idx);
    }
    let m = mat.len();
    let n = mat[0].len();
    let mut row_max_idx = vec![0; m];
    let mut col_max_idx = vec![0; n];

    for i in 0..m {
        for j in 0..n {
            let idx = *n_to_idx.get(&mat[i][j]).unwrap();
            row_max_idx[i] = std::cmp::max(row_max_idx[i], idx);
            col_max_idx[j] = std::cmp::max(col_max_idx[j], idx);
        }
    }

    // println!("{row_max_idx:?} {col_max_idx:?}");

    std::cmp::min(
        *row_max_idx.iter().min().unwrap(),
        *col_max_idx.iter().min().unwrap(),
    ) as i32
}

fn main() {
    assert_eq!(
        first_complete_index(vec![1, 3, 4, 2], vec![vec![1, 4], vec![2, 3]]),
        2
    );
    assert_eq!(
        first_complete_index(
            vec![2, 8, 7, 4, 1, 3, 5, 6, 9],
            vec![vec![3, 2, 5], vec![1, 4, 6], vec![8, 7, 9]]
        ),
        3
    );
}
