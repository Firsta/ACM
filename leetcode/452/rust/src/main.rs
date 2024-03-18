pub fn find_min_arrow_shots(points: Vec<Vec<i32>>) -> i32 {
    let mut result = 0;

    let mut points = points;
    points.sort_by(|a, b| a[0].cmp(&b[0]));
    // println!("{:?}", points);

    let mut last_end = None;
    for i in 0..points.len() {
        if last_end.is_none() || points[i][0] > last_end.unwrap() {
            result += 1;
            last_end = Some(points[i][1]);
        } else {
            last_end = Some(std::cmp::min(last_end.unwrap(), points[i][1]))
        }
    }

    result
}

fn main() {
    assert_eq!(
        find_min_arrow_shots(vec![
            vec![3, 9],
            vec![7, 12],
            vec![3, 8],
            vec![6, 8],
            vec![9, 10],
            vec![2, 9],
            vec![0, 9],
            vec![3, 9],
            vec![0, 6],
            vec![2, 8]
        ]),
        2
    );
    assert_eq!(
        find_min_arrow_shots(vec![vec![10, 16], vec![2, 8], vec![1, 6], vec![7, 12]]),
        2
    );
    assert_eq!(
        find_min_arrow_shots(vec![vec![1, 2], vec![3, 4], vec![5, 6], vec![7, 8]]),
        4
    );
    assert_eq!(
        find_min_arrow_shots(vec![vec![1, 2], vec![2, 3], vec![3, 4], vec![4, 5]]),
        2
    );
    assert_eq!(find_min_arrow_shots(vec![vec![-2147483648, 2147483647]]), 1);
}
