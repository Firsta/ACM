pub fn num_islands(grid: Vec<Vec<char>>) -> i32 {
    fn dfs(x: usize, y: usize, grid: &Vec<Vec<char>>, proccessed: &mut Vec<Vec<bool>>) {
        proccessed[x][y] = true;

        let m = grid.len();
        let n = grid[0].len();

        for (dx, dy) in [(1, 0), (-1, 0), (0, 1), (0, -1)] {
            let xx = x as i32 + dx;
            let yy = y as i32 + dy;
            if xx >= 0
                && xx < m as i32
                && yy >= 0
                && yy < n as i32
                && grid[xx as usize][yy as usize] == '1'
                && !proccessed[xx as usize][yy as usize]
            {
                dfs(xx as usize, yy as usize, grid, proccessed);
            }
        }
    }

    let m = grid.len();
    let n = grid[0].len();

    let mut proccessed = vec![vec![false; n]; m];

    let mut ans = 0;
    for x in 0..m {
        for y in 0..n {
            if grid[x][y] == '1' && !proccessed[x][y] {
                ans += 1;
                dfs(x, y, &grid, &mut proccessed);
            }
        }
    }

    ans
}

fn main() {
    assert_eq!(
        num_islands(vec![
            vec!['1', '1', '1', '1', '0'],
            vec!['1', '1', '0', '1', '0'],
            vec!['1', '1', '0', '0', '0'],
            vec!['0', '0', '0', '0', '0']
        ]),
        1
    );
    assert_eq!(
        num_islands(vec![
            vec!['1', '1', '0', '0', '0'],
            vec!['1', '1', '0', '0', '0'],
            vec!['0', '0', '1', '0', '0'],
            vec!['0', '0', '0', '1', '1']
        ]),
        3
    );
}
