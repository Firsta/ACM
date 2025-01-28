pub fn find_max_fish(grid: Vec<Vec<i32>>) -> i32 {
    fn dfs(grid: &Vec<Vec<i32>>, done: &mut Vec<Vec<bool>>, sum: &mut i32, x: i32, y: i32) {
        *sum += grid[x as usize][y as usize];
        done[x as usize][y as usize] = true;
        for (dx, dy) in [(0, 1), (0, -1), (1, 0), (-1, 0)] {
            let nx = x + dx;
            let ny = y + dy;
            if 0 <= nx
                && nx < grid.len() as i32
                && 0 <= ny
                && ny < grid[0].len() as i32
                && !done[nx as usize][ny as usize]
                && grid[nx as usize][ny as usize] > 0
            {
                dfs(grid, done, sum, nx, ny);
            }
        }
    }

    let mut done = vec![vec![false; grid[0].len()]; grid.len()];
    let mut ans = 0;
    for i in 0..grid.len() {
        for j in 0..grid[0].len() {
            if !done[i][j] && grid[i][j] > 0 {
                let mut sum = 0;
                dfs(&grid, &mut done, &mut sum, i as i32, j as i32);
                ans = std::cmp::max(ans, sum);
            }
        }
    }
    ans
}

fn main() {
    assert_eq!(
        find_max_fish(vec![
            vec![0, 2, 1, 0],
            vec![4, 0, 0, 3],
            vec![1, 0, 0, 4],
            vec![0, 3, 2, 0]
        ]),
        7
    );
    assert_eq!(
        find_max_fish(vec![
            vec![1, 0, 0, 0],
            vec![0, 0, 0, 0],
            vec![0, 0, 0, 0],
            vec![0, 0, 0, 1]
        ]),
        1
    );
}
