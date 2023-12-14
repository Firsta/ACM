pub fn ones_minus_zeros(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let m = grid.len();
    let n = grid[0].len();
    let mut diff = vec![vec![0; n]; m];
    for i in 0..m {
        let mut l = 0;
        for j in 0..n {
            if grid[i][j] == 0 {
                l -= 1;
            } else {
                l += 1;
            }
        }
        for j in 0..n {
            diff[i][j] = l;
        }
    }
    for j in 0..n {
        let mut l = 0;
        for i in 0..m {
            if grid[i][j] == 0 {
                l -= 1;
            } else {
                l += 1;
            }
        }
        for i in 0..m {
            diff[i][j] += l;
        }
    }
    diff
}

fn main() {
    println!("{:?}", ones_minus_zeros(vec![vec![0,1,1], vec![1,0,1], vec![0,0,1]]));
}
