use std::collections::{HashMap, HashSet};

pub fn largest_island(grid: Vec<Vec<i32>>) -> i32 {
    let m = grid.len();
    let n = grid[0].len();

    let mut grid_group = vec![vec![None; n]; m];
    let mut group_cnt = 0usize;
    fn dfs(
        x: usize,
        y: usize,
        grid_group: &mut Vec<Vec<Option<usize>>>,
        grid: &Vec<Vec<i32>>,
        group_i: usize,
        node_cnt: &mut usize,
    ) {
        grid_group[x][y] = Some(group_i);
        *node_cnt += 1;
        let m = grid.len() as i32;
        let n = grid[0].len() as i32;
        for (dx, dy) in [(0, 1), (0, -1), (1, 0), (-1, 0)] {
            let nx = x as i32 + dx;
            let ny = y as i32 + dy;
            if 0 <= nx
                && nx < m
                && 0 <= ny
                && ny < n
                && grid_group[nx as usize][ny as usize].is_none()
                && grid[nx as usize][ny as usize] == 1
            {
                dfs(
                    nx as usize,
                    ny as usize,
                    grid_group,
                    grid,
                    group_i,
                    node_cnt,
                );
            }
        }
    }
    let mut ans = 0;
    let mut group_to_cnt = HashMap::new();
    for i in 0..m {
        for j in 0..n {
            if grid[i][j] == 1 && grid_group[i][j].is_none() {
                let mut node_cnt = 0;
                dfs(i, j, &mut grid_group, &grid, group_cnt, &mut node_cnt);
                group_to_cnt.insert(group_cnt.clone(), node_cnt);
                ans = std::cmp::max(ans, node_cnt);
                group_cnt += 1;
            }
        }
    }

    for x in 0..m {
        for y in 0..n {
            if grid[x][y] == 0 {
                let mut cnt = 1;
                let mut s = HashSet::new();
                for (dx, dy) in [(0, 1), (0, -1), (1, 0), (-1, 0)] {
                    let nx = x as i32 + dx;
                    let ny = y as i32 + dy;
                    if 0 <= nx && nx < m as i32 && 0 <= ny && ny < n as i32 {
                        if let Some(g) = grid_group[nx as usize][ny as usize] {
                            if !s.contains(&g) {
                                s.insert(g);
                                cnt += group_to_cnt.get(&g).unwrap();
                            }
                        }
                    }
                }
                ans = std::cmp::max(ans, cnt);
            }
        }
    }

    ans as i32
}

fn main() {
    assert_eq!(largest_island(vec![vec![1, 0], vec![0, 1]]), 3);
    assert_eq!(largest_island(vec![vec![1, 1], vec![1, 0]]), 4);
    assert_eq!(largest_island(vec![vec![1, 1], vec![1, 1]]), 4);
}
