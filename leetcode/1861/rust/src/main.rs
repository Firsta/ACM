pub fn rotate_the_box(b: Vec<Vec<char>>) -> Vec<Vec<char>> {
    let m = b.len();
    let n = b[0].len();

    let mut ans = Vec::new();
    for i in 0..m {
        let mut row = vec!['*'];
        row.append(&mut b[i].clone());
        row.push('*');

        let mut o = row.len() - 1;
        let mut stone_cnt = 0;
        let mut ar = row.clone();
        for i in (0..row.len() - 1).rev() {
            if row[i] == '*' {
                for j in 0..o - i - 1 {
                    if j < stone_cnt {
                        ar[o - 1 - j] = '#';
                    } else {
                        ar[o - 1 - j] = '.';
                    }
                }
                ar[i] = '*';
                o = i;
                stone_cnt = 0;
            } else if row[i] == '#' {
                stone_cnt += 1;
            }
        }
        // println!("{:?}", ar);
        ans.push(ar[1..ar.len() - 1].to_vec());
    }

    let mut ret = vec![vec!['.'; m]; n];
    for i in 0..m {
        for j in 0..n {
            ret[j][m - 1 - i] = ans[i][j];
        }
    }
    // println!("{:?}", ans);

    ret
}

fn main() {
    assert_eq!(
        rotate_the_box(vec![vec!['#', '.', '*', '.'], vec!['#', '#', '*', '.']],),
        vec![
            vec!['#', '.'],
            vec!['#', '#'],
            vec!['*', '*'],
            vec!['.', '.']
        ]
    );
}
