pub fn transpose(matrix: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut result = Vec::new();
    let m = matrix.len();
    let n = matrix[0].len();
    for i in 0..n {
        result.push(Vec::new());
        for j in 0..m {
            result[i].push(matrix[j][i]);
        }
    }
    result
}

fn main() {
    println!("{:?}", transpose(vec![vec![1,2,3], vec![4,5,6], vec![7,8,9]]));
}
