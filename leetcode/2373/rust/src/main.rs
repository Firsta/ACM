pub fn largest_local(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let (m, n) = (grid.len(), grid[0].len());

    let mut tv = Vec::new();

    for i in 0..m {
        tv.push(Vec::new());
        for j in 1..n - 1 {
            tv[i].push(std::cmp::max(
                std::cmp::max(grid[i][j], grid[i][j - 1]),
                grid[i][j + 1],
            ));
        }
    }
    // println!("{:?}", tv);

    let mut ans = vec![vec![0; n - 2]; m - 2];
    for j in 0..n - 2 {
        for i in 1..m - 1 {
            ans[i - 1][j] = std::cmp::max(std::cmp::max(tv[i][j], tv[i - 1][j]), tv[i + 1][j]);
        }
    }

    ans
}

pub fn largest_local_0(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let (m, n) = (grid.len(), grid[0].len());

    let mut ans = Vec::new();
    for i in 1..m - 1 {
        ans.push(Vec::new());
        for j in 1..n - 1 {
            let mut t = grid[i][j];
            for dx in [-1, 0, 1] {
                for dy in [-1, 0, 1] {
                    let x = (i as i32 + dx) as usize;
                    let y = (j as i32 + dy) as usize;
                    t = std::cmp::max(t, grid[x][y]);
                }
            }
            ans[i - 1].push(t);
        }
    }
    ans
}

fn main() {
    assert_eq!(
        largest_local_0(vec![
            vec![1, 1, 1, 1, 1],
            vec![1, 1, 1, 1, 1],
            vec![1, 1, 2, 1, 1],
            vec![1, 1, 1, 1, 1],
            vec![1, 1, 1, 1, 1]
        ]),
        vec![vec![2, 2, 2], vec![2, 2, 2], vec![2, 2, 2]]
    );
}
