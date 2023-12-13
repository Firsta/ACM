pub fn num_special(mat: Vec<Vec<i32>>) -> i32 {
    let mut excluded = vec![false; mat.len()];
    let mut result = 0;
    for i in 0..mat.len() {
        let mut line_sum = 0;
        for j in 0..mat[0].len() {
            if mat[i][j] == 1 {
                line_sum += 1;
            }
        }
        if line_sum > 1 {
            excluded[i] = true;
        } else if line_sum == 1 {
            result += 1;
        }
    }
    
    for j in 0..mat[0].len() {
        let mut line_sum = 0;
        let mut ex = 0;
        for i in 0..mat.len() {
            if mat[i][j] == 1 {
                line_sum += 1;
                if excluded[i] {
                    ex += 1;
                }
            }
        }
        if line_sum > 1 {
            result = result - line_sum + ex;
        }
    }
    result
}

fn main() {
    println!("{}", num_special(vec![vec![1,0,0], vec![0,0,1], vec![1,0,0]]));
}
