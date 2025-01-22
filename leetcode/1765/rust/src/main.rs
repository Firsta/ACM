pub fn highest_peak(is_water: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let m = is_water.len();
    let n = is_water[0].len();
    let mut ans = vec![vec![std::i32::MAX; n]; m];
    let mut q = std::collections::VecDeque::new();
    for i in 0..m {
        for j in 0..n {
            if is_water[i][j] == 1 {
                q.push_back((i, j, 0));
                ans[i][j] = 0;
            }
        }
    }
    while !q.is_empty() {
        let t = q.pop_front().unwrap();
        for (dx, dy) in [(0, 1), (0, -1), (1, 0), (-1, 0)] {
            let x = t.0 as i32 + dx;
            let y = t.1 as i32 + dy;
            if 0 <= x
                && x < m as i32
                && 0 <= y
                && y < n as i32
                && t.2 + 1 < ans[x as usize][y as usize]
            {
                ans[x as usize][y as usize] = t.2 + 1;
                q.push_back((x as usize, y as usize, t.2 + 1));
            }
        }
    }
    ans
}

fn main() {
    assert_eq!(
        highest_peak(vec![vec![0, 1], vec![0, 0]]),
        vec![vec![1, 0], vec![2, 1]]
    );
}
