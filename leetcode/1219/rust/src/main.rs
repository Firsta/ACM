pub fn get_maximum_gold(grid: Vec<Vec<i32>>) -> i32 {
    fn dfs(
        grid: &Vec<Vec<i32>>,
        cur_i: i32,
        cur_j: i32,
        done: &mut Vec<Vec<bool>>,
        cur_gold: &mut i32,
        max_gold: &mut i32,
    ) {
        // println!("{} {}", cur_i, cur_j);

        *cur_gold += grid[cur_i as usize][cur_j as usize];
        *max_gold = std::cmp::max(*max_gold, *cur_gold);

        done[cur_i as usize][cur_j as usize] = true;

        for (di, dj) in [(0, 1), (0, -1), (1, 0), (-1, 0)] {
            let new_i = di + cur_i;
            let new_j = dj + cur_j;
            if 0 <= new_i
                && new_i < grid.len() as i32
                && 0 <= new_j
                && new_j < grid[0].len() as i32
                && !done[new_i as usize][new_j as usize]
                && grid[new_i as usize][new_j as usize] != 0
            {
                dfs(grid, new_i, new_j, done, cur_gold, max_gold);
            }
        }

        done[cur_i as usize][cur_j as usize] = false;
        *cur_gold -= grid[cur_i as usize][cur_j as usize];
    }

    let mut max_gold = 0;
    for i in 0..grid.len() {
        for j in 0..grid[0].len() {
            let mut cur_gold = 0;
            let mut done = vec![vec![false; grid[0].len()]; grid.len()];
            dfs(
                &grid,
                i as i32,
                j as i32,
                &mut done,
                &mut cur_gold,
                &mut max_gold,
            );
        }
    }
    max_gold
}

fn main() {
    assert_eq!(
        get_maximum_gold(vec![vec![0, 6, 0], vec![5, 8, 7], vec![0, 9, 0]]),
        24
    );
}
