fn dfs(
    board: &Vec<Vec<char>>,
    x: i32,
    y: i32,
    word: &String,
    word_idx: usize,
    proccessed: &mut Vec<Vec<bool>>,
) -> bool {
    if word.as_bytes()[word_idx] as char == board[x as usize][y as usize] {
        if word_idx == word.len() - 1 {
            return true;
        }
        let m = board.len();
        let n = board[0].len();

        proccessed[x as usize][y as usize] = true;
        for (dx, dy) in vec![(0, -1), (0, 1), (1, 0), (-1, 0)] {
            let next_x = x + dx;
            let next_y = y + dy;
            if next_x >= 0 && next_x < m as i32 && next_y >= 0 && next_y < n as i32 {
                if !proccessed[next_x as usize][next_y as usize] {
                    if dfs(&board, next_x, next_y, &word, word_idx + 1, proccessed) {
                        return true;
                    }
                }
            }
        }
        proccessed[x as usize][y as usize] = false;

        false
    } else {
        false
    }
}

pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
    let m = board.len();
    let n = board[0].len();

    let mut proccessed = vec![vec![false; n]; m];
    for i in 0..m {
        for j in 0..n {
            if dfs(&board, i as i32, j as i32, &word, 0, &mut proccessed) {
                return true;
            }
        }
    }

    false
}

fn main() {
    assert_eq!(
        exist(
            vec![
                vec!['A', 'B', 'C', 'E'],
                vec!['S', 'F', 'C', 'S'],
                vec!['A', 'D', 'E', 'E']
            ],
            "ABCCED".to_string()
        ),
        true
    );
    assert_eq!(
        exist(
            vec![
                vec!['A', 'B', 'C', 'E'],
                vec!['S', 'F', 'C', 'S'],
                vec!['A', 'D', 'E', 'E']
            ],
            "SEE".to_string()
        ),
        true
    );
    assert_eq!(
        exist(
            vec![
                vec!['A', 'B', 'C', 'E'],
                vec!['S', 'F', 'C', 'S'],
                vec!['A', 'D', 'E', 'E']
            ],
            "ABCB".to_string()
        ),
        false
    );
}
