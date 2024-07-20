pub fn restore_matrix(row_sum: Vec<i32>, col_sum: Vec<i32>) -> Vec<Vec<i32>> {
    let m = row_sum.len();
    let n = col_sum.len();

    let mut i = 0;
    let mut j = 0;

    let mut row_sum = row_sum;
    let mut col_sum = col_sum;

    let mut ans = vec![vec![0; n]; m];
    while i < m && j < n {
        if row_sum[i] < col_sum[j] {
            ans[i][j] = row_sum[i];
            col_sum[j] -= row_sum[i];
            i += 1;
        } else {
            ans[i][j] = col_sum[j];
            row_sum[i] -= col_sum[j];
            j += 1;
        }
        // println!("{} {} {:?}", i, j, ans);
    }

    ans
}

fn test(row_sum: Vec<i32>, col_sum: Vec<i32>, ans: Vec<Vec<i32>>) {
    assert_eq!(ans.len(), row_sum.len());
    assert_eq!(ans[0].len(), col_sum.len());
    let mut r = vec![0; row_sum.len()];
    let mut c = vec![0; col_sum.len()];
    for i in 0..ans.len() {
        for j in 0..ans[0].len() {
            r[i] += ans[i][j];
            c[j] += ans[i][j];
        }
    }
    assert_eq!(row_sum, r);
    assert_eq!(col_sum, c);
}

fn judge(row_sum: Vec<i32>, col_sum: Vec<i32>) {
    let ans = restore_matrix(row_sum.clone(), col_sum.clone());
    test(row_sum, col_sum, ans);
}

fn main() {
    judge(vec![3, 8], vec![4, 7]);
    judge(vec![5, 7, 10], vec![8, 6, 8]);
}
