pub fn spiral_matrix_iii(rows: i32, cols: i32, r_start: i32, c_start: i32) -> Vec<Vec<i32>> {
    let mut ans = Vec::new();

    let max_turn = std::cmp::max(rows, cols) + 1;
    let mut pos = (r_start, c_start);
    for turn in 0..max_turn {
        if 0 <= pos.0 && pos.0 < rows && 0 <= pos.1 && pos.1 < cols {
            ans.push(vec![pos.0, pos.1]);
        }

        for _i in 0..turn * 2 - 1 {
            pos.0 += 1;
            if 0 <= pos.0 && pos.0 < rows && 0 <= pos.1 && pos.1 < cols {
                ans.push(vec![pos.0, pos.1]);
            }
        }

        for _i in 0..turn * 2 {
            pos.1 -= 1;
            if 0 <= pos.0 && pos.0 < rows && 0 <= pos.1 && pos.1 < cols {
                ans.push(vec![pos.0, pos.1]);
            }
        }

        for _i in 0..turn * 2 {
            pos.0 -= 1;
            if 0 <= pos.0 && pos.0 < rows && 0 <= pos.1 && pos.1 < cols {
                ans.push(vec![pos.0, pos.1]);
            }
        }

        for _i in 0..turn * 2 {
            pos.1 += 1;
            if 0 <= pos.0 && pos.0 < rows && 0 <= pos.1 && pos.1 < cols {
                ans.push(vec![pos.0, pos.1]);
            }
        }

        pos.1 += 1;
    }

    ans
}

fn main() {
    assert_eq!(
        spiral_matrix_iii(5, 6, 1, 4),
        vec![
            vec![1, 4],
            vec![1, 5],
            vec![2, 5],
            vec![2, 4],
            vec![2, 3],
            vec![1, 3],
            vec![0, 3],
            vec![0, 4],
            vec![0, 5],
            vec![3, 5],
            vec![3, 4],
            vec![3, 3],
            vec![3, 2],
            vec![2, 2],
            vec![1, 2],
            vec![0, 2],
            vec![4, 5],
            vec![4, 4],
            vec![4, 3],
            vec![4, 2],
            vec![4, 1],
            vec![3, 1],
            vec![2, 1],
            vec![1, 1],
            vec![0, 1],
            vec![4, 0],
            vec![3, 0],
            vec![2, 0],
            vec![1, 0],
            vec![0, 0]
        ]
    );
}
