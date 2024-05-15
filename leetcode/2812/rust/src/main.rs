use std::collections::VecDeque;

pub fn maximum_safeness_factor(grid: Vec<Vec<i32>>) -> i32 {
    let n = grid.len();

    let mut d = vec![vec![std::i32::MAX; n]; n];
    let mut done = vec![vec![false; n]; n];

    let mut q = VecDeque::new();
    for i in 0..n {
        for j in 0..n {
            if grid[i][j] == 1 {
                d[i][j] = 0;
                q.push_back((i, j, 0));
                done[i][j] = true;
            }
        }
    }

    while let Some(t) = q.pop_front() {
        for (di, dj) in [(0, 1), (0, -1), (1, 0), (-1, 0)] {
            let new_i = t.0 as i32 + di;
            let new_j = t.1 as i32 + dj;

            if 0 <= new_i
                && new_i < n as i32
                && 0 <= new_j
                && new_j < n as i32
                && !done[new_i as usize][new_j as usize]
            {
                let new_i = new_i as usize;
                let new_j = new_j as usize;
                d[new_i][new_j] = std::cmp::min(d[new_i][new_j], t.2 + 1);
                q.push_back((new_i, new_j, t.2 + 1));
                done[new_i][new_j] = true;
            }
        }
    }

    let mut r = *(d.iter().flatten().max().unwrap());
    // println!("{:?} {}", d, r);

    let mut l = 0;

    fn has_path(min_d: i32, d: &Vec<Vec<i32>>) -> bool {
        if d[0][0] < min_d {
            return false;
        }
        let mut q = VecDeque::new();
        q.push_back((0, 0));

        let n = d.len();

        let mut done = vec![vec![false; n]; n];
        done[0][0] = true;

        while let Some(t) = q.pop_front() {
            for (di, dj) in [(0, 1), (0, -1), (1, 0), (-1, 0)] {
                let new_i = t.0 as i32 + di;
                let new_j = t.1 as i32 + dj;

                if 0 <= new_i
                    && new_i < n as i32
                    && 0 <= new_j
                    && new_j < n as i32
                    && !done[new_i as usize][new_j as usize]
                    && d[new_i as usize][new_j as usize] >= min_d
                {
                    let new_i = new_i as usize;
                    let new_j = new_j as usize;

                    q.push_back((new_i, new_j));
                    done[new_i][new_j] = true;
                }
            }
        }

        done[n - 1][n - 1]
    }

    while r - l > 1 {
        // println!("{} {}", l, r);
        let mid = (l + r) / 2;
        if has_path(mid, &d) {
            l = mid;
        } else {
            r = mid;
        }
    }

    if has_path(r, &d) {
        r
    } else {
        l
    }
}

fn main() {
    assert_eq!(
        maximum_safeness_factor(vec![
            vec![0, 0, 0, 1],
            vec![0, 0, 0, 0],
            vec![0, 0, 0, 0],
            vec![1, 0, 0, 0]
        ]),
        2
    );
}
