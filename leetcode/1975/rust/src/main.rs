pub fn max_matrix_sum(matrix: Vec<Vec<i32>>) -> i64 {
    let m = matrix.len();
    let n = matrix[0].len();
    let mut nc = 0;
    let mut nn = Vec::new();
    let mut ans = 0i64;
    for i in 0..m {
        for j in 0..n {
            if matrix[i][j] < 0 {
                nc += 1;
                ans += -matrix[i][j] as i64;
            } else {
                ans += matrix[i][j] as i64;
            }
            nn.push(matrix[i][j].abs());
        }
    }
    if nc % 2 == 0 {
        ans
    } else {
        nn.sort();
        ans -= 2 * nn[0] as i64;
        ans
    }
}

fn main() {
    assert_eq!(max_matrix_sum(vec![vec![1, -1], vec![-1, 1]]), 4);
    assert_eq!(
        max_matrix_sum(vec![vec![1, 2, 3], vec![-1, -2, -3], vec![1, 2, 3]]),
        16
    );
}
