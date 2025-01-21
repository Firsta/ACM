pub fn grid_game(grid: Vec<Vec<i32>>) -> i64 {
    let n = grid[0].len();

    let mut ss = vec![0i64; n];
    let mut sum = 0i64;
    for i in (0..n).rev() {
        sum += grid[0][i] as i64;
        ss[i] = sum;
    }

    let mut ps = vec![0i64; n];
    let mut sum = 0i64;
    for i in 0..n {
        sum += grid[1][i] as i64;
        ps[i] = sum;
    }

    let mut ans = std::i64::MAX;
    for down in 0..n {
        let t = std::cmp::max(
            ps[down] - grid[1][down] as i64,
            ss[down] - grid[0][down] as i64,
        );
        ans = std::cmp::min(ans, t);
    }
    ans
}

fn main() {
    assert_eq!(grid_game(vec![vec![2, 5, 4], vec![1, 5, 1]]), 4);
    assert_eq!(grid_game(vec![vec![3, 3, 1], vec![8, 5, 2]]), 4);
    assert_eq!(grid_game(vec![vec![1, 3, 1, 15], vec![1, 3, 3, 1]]), 7);
}
