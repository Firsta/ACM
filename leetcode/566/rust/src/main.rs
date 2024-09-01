pub fn matrix_reshape(mat: Vec<Vec<i32>>, r: i32, c: i32) -> Vec<Vec<i32>> {
    let r = r as usize;
    let c = c as usize;

    let m = mat.len();
    let n = mat[0].len();

    if r * c != m * n {
        mat
    } else {
        let mut ans = Vec::new();
        for i in 0..r {
            ans.push(Vec::new());
            for j in 0..c {
                let t = i * c + j;
                ans[i].push(mat[t / n][t % n]);
            }
        }
        ans
    }
}

fn main() {
    assert_eq!(
        matrix_reshape(vec![vec![1, 2], vec![3, 4]], 1, 4),
        vec![vec![1, 2, 3, 4]]
    );
}
