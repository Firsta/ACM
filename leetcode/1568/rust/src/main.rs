fn zero(grid: &Vec<Vec<i32>>) -> bool {
    fn dfs(i: i32, j: i32, grid: &Vec<Vec<i32>>, visited: &mut Vec<Vec<bool>>) {
        // println!("{} {}", i, j);
        visited[i as usize][j as usize] = true;
        let m = grid.len() as i32;
        let n = grid[0].len() as i32;
        for d in [(-1, 0), (0, -1), (0, 1), (1, 0)] {
            let ni = i + d.0;
            let nj = j + d.1;
            // println!("ni: {}  nj: {}", ni, nj);
            if 0 <= ni
                && ni < m
                && 0 <= nj
                && nj < n
                && !visited[ni as usize][nj as usize]
                && grid[ni as usize][nj as usize] == 1
            {
                dfs(ni, nj, grid, visited);
            }
        }
    }

    let m = grid.len();
    let n = grid[0].len();

    let mut visited = vec![vec![false; n]; m];
    let mut found_one = false;
    for i in 0..m {
        for j in 0..n {
            if grid[i][j] == 1 && !visited[i][j] {
                if found_one {
                    return true;
                } else {
                    found_one = true;
                    dfs(i as i32, j as i32, &grid, &mut visited);
                }
            }
        }
    }
    // println!("{:?}", visited);
    if !found_one {
        true
    } else {
        false
    }
}

fn one(grid: &Vec<Vec<i32>>) -> bool {
    fn dfs(i: i32, j: i32, grid: &Vec<Vec<i32>>, is_out: &mut Vec<Vec<bool>>) {
        is_out[i as usize][j as usize] = true;

        let m = grid.len() as i32;
        let n = grid[0].len() as i32;

        for d in [
            (-1, -1),
            (-1, 0),
            (-1, 1),
            (0, -1),
            (0, 1),
            (1, -1),
            (1, 0),
            (1, 1),
        ] {
            let ni = i + d.0;
            let nj = j + d.1;
            if 0 <= ni
                && ni < m
                && 0 <= nj
                && nj < n
                && grid[ni as usize][nj as usize] == 0
                && !is_out[ni as usize][nj as usize]
            {
                dfs(ni, nj, grid, is_out);
            }
        }
    }

    let m = grid.len();
    let n = grid[0].len();

    let mut is_out = vec![vec![false; n]; m];
    dfs(0, 0, &grid, &mut is_out);
    // println!("{:?}", is_out);

    for i in 0..m as i32 {
        for j in 0..n as i32 {
            if grid[i as usize][j as usize] == 1 {
                let ds = [
                    (-1, -1),
                    (-1, 0),
                    (-1, 1),
                    (0, 1),
                    (1, 1),
                    (1, 0),
                    (1, -1),
                    (0, -1),
                ];
                for a in 0..8 {
                    for b in a + 1..8 {
                        if is_out[(i + ds[a].0) as usize][(j + ds[a].1) as usize]
                            && is_out[(i + ds[b].0) as usize][(j + ds[b].1) as usize]
                        {
                            let mut oka = false;
                            let mut okb = false;
                            for k in 0..8 {
                                if grid[(i + ds[k].0) as usize][(j + ds[k].1) as usize] == 1 {
                                    if a < k && k < b {
                                        oka = true;
                                    } else {
                                        okb = true;
                                    }
                                }
                            }
                            if oka && okb {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    false
}

fn count_adj(grid: &Vec<Vec<i32>>) -> i32 {
    let m = grid.len();
    let n = grid[0].len();

    let mut ans = 4;
    for i in 0..m {
        for j in 0..n {
            if grid[i][j] == 1 {
                let i = i as i32;
                let j = j as i32;
                let mut ajc = 0;
                for d in [(-1, 0), (0, -1), (0, 1), (1, 0)] {
                    let ni = i + d.0;
                    let nj = j + d.1;
                    if 0 <= ni
                        && ni < m as i32
                        && 0 <= nj
                        && nj < n as i32
                        && grid[ni as usize][nj as usize] == 1
                    {
                        ajc += 1;
                    }
                }
                ans = std::cmp::min(ans, ajc);
            }
        }
    }

    ans
}

pub fn min_days(grid: Vec<Vec<i32>>) -> i32 {
    let m = grid.len();
    let n = grid[0].len();

    let mut one_cnt = 0;
    for i in 0..grid.len() {
        for j in 0..grid[0].len() {
            if grid[i][j] == 1 {
                one_cnt += 1;
            }
        }
    }
    if one_cnt == 1 {
        return 1;
    } else if one_cnt == 2 && m * n == 2 {
        return 2;
    }

    let mut new_grid = vec![vec![0; n + 2]; m + 2];
    for i in 0..m + 2 {
        for j in 0..n + 2 {
            if i == 0 || j == 0 || i == m + 1 || j == n + 1 {
                new_grid[i][j] = 0;
            } else {
                new_grid[i][j] = grid[i - 1][j - 1];
            }
        }
    }

    let grid = new_grid;

    if zero(&grid) {
        0
    } else if one_cnt == 2 {
        2
    } else if one(&grid) {
        1
    } else {
        count_adj(&grid)
    }
}

fn main() {
    assert_eq!(
        min_days(vec![vec![0, 1, 1, 0], vec![0, 1, 1, 0], vec![0, 0, 0, 0]]),
        2
    );
    assert_eq!(min_days(vec![vec![1, 1]]), 2);
    assert_eq!(min_days(vec![vec![1, 0], vec![0, 1]]), 0);
    assert_eq!(min_days(vec![vec![1, 1], vec![1, 0]]), 1);
    assert_eq!(
        min_days(vec![vec![1, 1, 0], vec![1, 1, 1], vec![0, 1, 1]]),
        1
    );
    assert_eq!(
        min_days(vec![
            vec![1, 1, 1, 1, 1],
            vec![1, 0, 0, 1, 1],
            vec![1, 1, 1, 0, 0],
            vec![1, 1, 1, 1, 1],
            vec![1, 1, 1, 1, 1]
        ]),
        1
    );
    assert_eq!(
        min_days(vec![vec![0, 0, 0, 0], vec![0, 1, 1, 0], vec![0, 0, 0, 0]]),
        2
    )
}
