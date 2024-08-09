pub fn num_magic_squares_inside(grid: Vec<Vec<i32>>) -> i32 {
    let m = grid.len() as i32;
    let n = grid[0].len() as i32;

    if m < 3 || n < 3 {
        0
    } else {
        let mut ans = 0;
        for i in 1..m - 1 {
            for j in 1..n - 1 {
                let mut cnt = vec![0; 9];
                for d in [
                    (-1, -1),
                    (-1, 0),
                    (-1, 1),
                    (0, -1),
                    (0, 0),
                    (0, 1),
                    (1, -1),
                    (1, 0),
                    (1, 1),
                ] {
                    let t = grid[(i + d.0) as usize][(j + d.1) as usize];
                    if t < 1 || t > 9 {
                        continue;
                    } else {
                        cnt[(t - 1) as usize] += 1;
                    }
                }
                if cnt.into_iter().filter(|x| *x != 1).count() > 0 {
                    continue;
                }

                let ts = grid[(i - 1) as usize][(j - 1) as usize]
                    + grid[(i - 1) as usize][(j) as usize]
                    + grid[(i - 1) as usize][(j + 1) as usize];
                let mut ok = true;
                for s in [
                    [(0, -1), (0, 0), (0, 1)],
                    [(1, -1), (1, 0), (1, 1)],
                    [(-1, -1), (0, -1), (1, -1)],
                    [(-1, 0), (0, 0), (1, 0)],
                    [(-1, 1), (0, 1), (1, 1)],
                    [(-1, -1), (0, 0), (1, 1)],
                    [(-1, 1), (0, 0), (1, -1)],
                ] {
                    let t = grid[(i + s[0].0) as usize][(j + s[0].1) as usize]
                        + grid[(i + s[1].0) as usize][(j + s[1].1) as usize]
                        + grid[(i + s[2].0) as usize][(j + s[2].1) as usize];
                    if t != ts {
                        ok = false;
                        break;
                    }
                }
                if ok {
                    ans += 1;
                }
            }
        }
        ans
    }
}
fn main() {
    assert_eq!(
        num_magic_squares_inside(vec![vec![4, 3, 8, 4], vec![9, 5, 1, 9], vec![2, 7, 6, 2]]),
        1
    );
}
