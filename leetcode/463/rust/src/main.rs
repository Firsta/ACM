pub fn island_perimeter(grid: Vec<Vec<i32>>) -> i32 {
    let mut ans = 0;

    let m = grid.len();
    let n = grid[0].len();

    for x in 0..m {
        for y in 0..n {
            for (dx, dy) in [(1, 0), (-1, 0), (0, 1), (0, -1)] {
                if grid[x][y] == 1 {
                    let xx = x as i32 + dx;
                    let yy = y as i32 + dy;

                    if xx < 0
                        || xx >= m as i32
                        || yy < 0
                        || yy >= n as i32
                        || grid[xx as usize][yy as usize] == 0
                    {
                        ans += 1;
                    }
                }
            }
        }
    }

    ans
}

fn main() {
    assert_eq!(
        island_perimeter(vec![
            vec![0, 1, 0, 0],
            vec![1, 1, 1, 0],
            vec![0, 1, 0, 0],
            vec![1, 1, 0, 0]
        ]),
        16
    );
    assert_eq!(island_perimeter(vec![vec![1]]), 4);
    assert_eq!(island_perimeter(vec![vec![1, 0]]), 4);
}
