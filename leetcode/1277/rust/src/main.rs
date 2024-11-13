pub fn count_squares(matrix: Vec<Vec<i32>>) -> i32 {
    let m = matrix.len();
    let n = matrix[0].len();

    let mut ans = 0;
    for i in 0..m {
        for j in 0..n {
            let max_l = std::cmp::min(m - i, n - j);
            for l in 1..=max_l {
                let mut all_one = true;
                for ii in i..i + l {
                    for jj in j..j + l {
                        if matrix[ii][jj] == 0 {
                            all_one = false;
                            break;
                        }
                    }
                    if !all_one {
                        break;
                    }
                }
                if all_one {
                    ans += 1;
                } else {
                    break;
                }
            }
        }
    }

    ans
}

fn main() {
    assert_eq!(
        count_squares(vec![vec![0, 1, 1, 1], vec![1, 1, 1, 1], vec![0, 1, 1, 1]]),
        15
    );
}
