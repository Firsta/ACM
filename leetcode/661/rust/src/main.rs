pub fn image_smoother(img: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let m = img.len();
    let n = img[0].len();

    let mut result = Vec::new();

    for i in 0..m {
        result.push(Vec::new());
        for j in 0..n {
            let mut cell_count = 1;
            let mut total = img[i][j];
            if i >= 1 {
                total += img[i - 1][j];
                cell_count += 1;
                if j >= 1 {
                    total += img[i - 1][j - 1];
                    cell_count += 1;
                }
                if j + 1 < n {
                    total += img[i - 1][j + 1];
                    cell_count += 1;
                }
            }
            if j >= 1 {
                total += img[i][j - 1];
                cell_count += 1;
            }
            if j + 1 < n {
                total += img[i][j + 1];
                cell_count += 1;
            }
            if i + 1 < m {
                total += img[i + 1][j];
                cell_count += 1;
                if j >= 1 {
                    total += img[i + 1][j - 1];
                    cell_count += 1;
                }
                if j + 1 < n {
                    total += img[i + 1][j + 1];
                    cell_count += 1;
                }
            }
            result[i].push(total / cell_count);
        }
    }
    result
}

fn main() {
    println!("{:?}", image_smoother(vec![vec![100, 200, 100], vec![200, 50, 200], vec![100, 200, 100]]));
}
