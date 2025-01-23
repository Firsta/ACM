pub fn count_servers(grid: Vec<Vec<i32>>) -> i32 {
    let m = grid.len();
    let n = grid[0].len();
    let mut row_cnt = vec![0; m];
    let mut col_cnt = vec![0; n];
    let mut sum = 0;
    for i in 0..m {
        for j in 0..n {
            if grid[i][j] == 1 {
                row_cnt[i] += 1;
                col_cnt[j] += 1;
                sum += 1;
            }
        }
    }
    let mut cnt = 0;
    for i in 0..m {
        if row_cnt[i] == 1 {
            for j in 0..n {
                if grid[i][j] == 1 && col_cnt[j] == 1 {
                    cnt += 1;
                }
            }
        }
    }
    sum - cnt
}

fn main() {
    assert_eq!(count_servers(vec![vec![1, 0], vec![0, 1]]), 0);
    assert_eq!(count_servers(vec![vec![1, 0], vec![1, 1]]), 3);
    assert_eq!(
        count_servers(vec![
            vec![1, 1, 0, 0],
            vec![0, 0, 1, 0],
            vec![0, 0, 1, 0],
            vec![0, 0, 0, 1]
        ]),
        4
    );
}
