use std::collections::HashMap;

pub fn find_farmland(land: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    fn dfs(
        land: &Vec<Vec<i32>>,
        x: usize,
        y: usize,
        left_top_x: usize,
        left_top_y: usize,
        group: &mut Vec<Vec<Option<(usize, usize)>>>,
    ) {
        group[x][y] = Some((left_top_x, left_top_y));
        for (dx, dy) in [(1, 0), (-1, 0), (0, 1), (0, -1)] {
            let new_x = x as i32 + dx;
            let new_y = y as i32 + dy;

            if 0 <= new_x
                && new_x < land.len() as i32
                && 0 <= new_y
                && new_y < land[0].len() as i32
                && land[new_x as usize][new_y as usize] == 1
                && group[new_x as usize][new_y as usize].is_none()
            {
                dfs(
                    land,
                    new_x as usize,
                    new_y as usize,
                    left_top_x,
                    left_top_y,
                    group,
                );
            }
        }
    }

    let m = land.len();
    let n = land[0].len();

    let mut group = vec![vec![None; n]; m];
    for x in 0..m {
        for y in 0..n {
            if land[x][y] == 1 && group[x][y].is_none() {
                dfs(&land, x, y, x, y, &mut group);
            }
        }
    }

    // println!("{:?}", group);

    let mut mm: HashMap<(usize, usize), (usize, usize)> = HashMap::new();
    for curr_x in 0..m {
        for curr_y in 0..n {
            if let Some((left_top_x, left_top_y)) = group[curr_x][curr_y] {
                mm.entry((left_top_x, left_top_y))
                    .and_modify(|e| {
                        if curr_x > e.0 || curr_y > e.1 {
                            *e = (curr_x, curr_y);
                        }
                    })
                    .or_insert((curr_x, curr_y));
            }
        }
    }

    let mut ans = Vec::new();
    for (k, v) in mm.into_iter() {
        ans.push(vec![k.0 as i32, k.1 as i32, v.0 as i32, v.1 as i32]);
    }
    ans
}

fn main() {
    assert_eq!(
        find_farmland(vec![vec![1, 0, 0], vec![0, 1, 1], vec![0, 1, 1]]),
        vec![vec![0, 0, 0, 0], vec![1, 1, 2, 2]]
    );
    assert_eq!(
        find_farmland(vec![vec![1, 1], vec![1, 1]]),
        vec![vec![0, 0, 1, 1]]
    );
    assert!(find_farmland(vec![vec![0]]).is_empty());
}
