use std::cmp::min;

pub fn min_time_to_visit_all_points(points: Vec<Vec<i32>>) -> i32 {
    let mut result = 0;
    let mut last_p: Option<&Vec<i32>> = None;
    for p in points.iter() {
        if let Some(last_p) = last_p {
            let x_diff = (last_p[0] - p[0]).abs();
            let y_diff = (last_p[1] - p[1]).abs();
            result += min(x_diff, y_diff) + (x_diff - y_diff).abs();
        }
        last_p = Some(p);
    }
    result
}

fn main() {
    println!("{}", min_time_to_visit_all_points(vec![vec![1,1], vec![3,4], vec![-1,0]]));
}

