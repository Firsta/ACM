pub fn max_points(points: Vec<Vec<i32>>) -> i64 {
    let m = points.len();
    let n = points[0].len();

    let mut dp: Vec<i64> = points[0].iter().map(|x| x.clone() as i64).collect();
    for i in 1..m {
        let mut m = -1i64;
        let mut ndp = vec![-1i64; n];
        for j in 0..n {
            m = std::cmp::max(m - 1, dp[j]);
            ndp[j] = std::cmp::max(ndp[j], m + points[i][j] as i64);
        }
        m = -1;
        for j in (0..n).rev() {
            m = std::cmp::max(m - 1, dp[j]);
            ndp[j] = std::cmp::max(ndp[j], m + points[i][j] as i64);
        }
        dp = ndp;
    }
    dp.into_iter().max().unwrap()
}

fn main() {
    assert_eq!(
        max_points(vec![vec![1, 2, 3], vec![1, 5, 1], vec![3, 1, 1]]),
        9
    );
    assert_eq!(max_points(vec![vec![1, 5], vec![2, 3], vec![4, 2]]), 11);
}
