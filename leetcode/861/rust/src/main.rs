pub fn matrix_score(grid: Vec<Vec<i32>>) -> i32 {
    let (m, n) = (grid.len(), grid[0].len());

    let mut flip_row = vec![false; m];
    let mut flip_col = vec![false; n];

    for i in 0..m {
        if grid[i][0] == 0 {
            flip_row[i] = true;
        }
    }

    for j in 0..n {
        let mut one_cnt = 0;
        for i in 0..m {
            let t = if flip_row[i] {
                1 - grid[i][j]
            } else {
                grid[i][j]
            };
            if t == 1 {
                one_cnt += 1;
            }
        }
        if 2 * one_cnt < m {
            flip_col[j] = true;
        }
    }

    let mut grid = grid;
    for i in 0..m {
        for j in 0..n {
            let mut t = grid[i][j];
            if flip_row[i] {
                t = 1 - t;
            }
            if flip_col[j] {
                t = 1 - t;
            }
            grid[i][j] = t;
        }
    }

    let grid: Vec<Vec<i32>> = grid
        .into_iter()
        .map(|mut arr| {
            arr.reverse();
            arr
        })
        .collect();
    // println!("{:?}", grid);

    let mut ans = 0;
    for i in 0..m {
        let mut t = 0;
        for j in 0..n {
            if grid[i][j] == 1 {
                t += 2_i32.pow(j as u32);
            }
        }
        ans += t;
    }

    ans
}

fn main() {
    assert_eq!(
        matrix_score(vec![vec![0, 0, 1, 1], vec![1, 0, 1, 0], vec![1, 1, 0, 0]]),
        39
    );
    assert_eq!(matrix_score(vec![vec![0]]), 1);
}
