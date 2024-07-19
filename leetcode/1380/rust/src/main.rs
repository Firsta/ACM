pub fn lucky_numbers(matrix: Vec<Vec<i32>>) -> Vec<i32> {
    let m = matrix.len();
    let n = matrix[0].len();

    let mut mmin = vec![100001; m];
    let mut mmax = vec![0; n];

    for i in 0..m {
        for j in 0..n {
            mmin[i] = std::cmp::min(mmin[i], matrix[i][j]);
            mmax[j] = std::cmp::max(mmax[j], matrix[i][j]);
        }
    }

    // println!("{:?} {:?}", mmin, mmax);

    let mut ans = Vec::new();
    for i in 0..m {
        for j in 0..n {
            if matrix[i][j] == mmin[i] && matrix[i][j] == mmax[j] {
                ans.push(matrix[i][j]);
            }
        }
    }

    ans
}
fn main() {
    assert_eq!(
        lucky_numbers(vec![vec![3, 7, 8], vec![9, 11, 13], vec![15, 16, 17]]),
        vec![15]
    );
    assert_eq!(
        lucky_numbers(vec![
            vec![1, 10, 4, 2],
            vec![9, 3, 8, 7],
            vec![15, 16, 17, 12]
        ]),
        vec![12]
    );
    assert_eq!(lucky_numbers(vec![vec![7, 8], vec![1, 2]]), vec![7]);
}
