use std::collections::HashMap;

pub fn max_equal_rows_after_flips(matrix: Vec<Vec<i32>>) -> i32 {
    let mut m = HashMap::new();
    for i in 0..matrix.len() {
        m.entry(&matrix[i])
            .and_modify(|e| {
                *e += 1;
            })
            .or_insert(1);
    }
    let mut ans = 0;
    for (k, v) in m.iter() {
        let mm: Vec<i32> = k.iter().map(|x| 1 - x).collect();
        ans = std::cmp::max(ans, *v + m.get(&mm).unwrap_or_else(|| &0));
    }
    ans
}

fn main() {
    assert_eq!(max_equal_rows_after_flips(vec![vec![0, 1], vec![1, 1]]), 1);
    assert_eq!(max_equal_rows_after_flips(vec![vec![0, 1], vec![1, 0]]), 2);
    assert_eq!(
        max_equal_rows_after_flips(vec![vec![0, 0, 0], vec![0, 0, 1], vec![1, 1, 0]]),
        2
    );
}
