pub fn count_sub_islands(grid1: Vec<Vec<i32>>, grid2: Vec<Vec<i32>>) -> i32 {
    fn dfs(
        grid1: &Vec<Vec<i32>>,
        grid2: &Vec<Vec<i32>>,
        visited: &mut Vec<Vec<bool>>,
        x: i32,
        y: i32,
    ) -> bool {
        let m = grid1.len() as i32;
        let n = grid1[0].len() as i32;

        visited[x as usize][y as usize] = true;

        let mut sub = grid1[x as usize][y as usize] == 1;

        for (dx, dy) in [(0, 1), (0, -1), (1, 0), (-1, 0)] {
            let new_x = x + dx;
            let new_y = y + dy;
            if 0 <= new_x
                && new_x < m
                && 0 <= new_y
                && new_y < n
                && !visited[new_x as usize][new_y as usize]
                && grid2[new_x as usize][new_y as usize] == 1
            {
                sub = sub & dfs(grid1, grid2, visited, new_x, new_y);
            }
        }

        sub
    }

    let m = grid1.len();
    let n = grid1[0].len();

    let mut visited = vec![vec![false; n]; m];

    let mut ans = 0;
    for x in 0..m {
        for y in 0..n {
            if !visited[x][y]
                && grid2[x][y] == 1
                && dfs(&grid1, &grid2, &mut visited, x as i32, y as i32)
            {
                // println!("{} {}", x, y);
                ans += 1;
            }
        }
    }

    ans
}

fn main() {
    assert_eq!(
        count_sub_islands(
            vec![
                vec![1, 1, 1, 0, 0],
                vec![0, 1, 1, 1, 1],
                vec![0, 0, 0, 0, 0],
                vec![1, 0, 0, 0, 0],
                vec![1, 1, 0, 1, 1]
            ],
            vec![
                vec![1, 1, 1, 0, 0],
                vec![0, 0, 1, 1, 1],
                vec![0, 1, 0, 0, 0],
                vec![1, 0, 1, 1, 0],
                vec![0, 1, 0, 1, 0]
            ]
        ),
        3
    );
}
