use std::cmp::max;

pub fn largest_submatrix(matrix: Vec<Vec<i32>>) -> i32 {
    let m = matrix.len();
    let n = matrix[0].len();

    let mut result = 0;

    let mut consecutive_counts = vec![0; n];
    for i in 0..m {
        let mut new_consecutive_counts = consecutive_counts.clone();
        for j in 0..n {
            if matrix[i][j] == 1 {
                new_consecutive_counts[j] = consecutive_counts[j] + 1;
            } else {
                new_consecutive_counts[j] = 0
            }
        }
        consecutive_counts = new_consecutive_counts.clone();
        new_consecutive_counts.sort();
        let mut sub_result = 0;
        for (idx, item) in new_consecutive_counts.iter().enumerate() {
            sub_result = max(sub_result, item * (new_consecutive_counts.len() - idx));
        }
        result = max(result, sub_result);
    }

    result as i32
}        

fn main() {
    // let input = vec![vec![0,0,1], vec![1,1,1], vec![1,0,1]];
    // let input = vec![vec![1,0,1,0,1]];
    let input = vec![vec![1,1,0], vec![1,0,1]];
    println!("{}", largest_submatrix(input));
}
