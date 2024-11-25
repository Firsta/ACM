use std::collections::{HashSet, VecDeque};

pub fn sliding_puzzle(board: Vec<Vec<i32>>) -> i32 {
    let mut q = VecDeque::new();
    let mut m = HashSet::new();
    q.push_back((board.clone(), 0));
    m.insert(board);
    fn swap(s: &Vec<Vec<i32>>, pa: (usize, usize), pb: (usize, usize)) -> Vec<Vec<i32>> {
        let mut t = s.clone();
        let tt = t[pa.0][pa.1];
        t[pa.0][pa.1] = t[pb.0][pb.1];
        t[pb.0][pb.1] = tt;
        t
    }
    while !q.is_empty() {
        let (t, step) = q.pop_front().unwrap();
        if t == vec![vec![1, 2, 3], vec![4, 5, 0]] {
            return step;
        }
        let mut x = -1;
        let mut y = -1;
        for i in 0..2 {
            for j in 0..3 {
                if t[i][j] == 0 {
                    x = i as i32;
                    y = j as i32;
                }
            }
        }

        for (dx, dy) in [(1, 0), (-1, 0), (0, 1), (0, -1)] {
            let nx = x + dx;
            let ny = y + dy;
            if 0 <= nx && nx < 2 && 0 <= ny && ny < 3 {
                let next = swap(&t, (x as usize, y as usize), (nx as usize, ny as usize));
                if m.get(&next).is_none() {
                    m.insert(next.clone());
                    q.push_back((next, step + 1));
                }
            }
        }
    }

    -1
}

fn main() {
    assert_eq!(sliding_puzzle(vec![vec![1, 2, 3], vec![4, 0, 5]]), 1);
}
