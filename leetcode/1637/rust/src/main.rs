pub fn max_width_of_vertical_area(points: Vec<Vec<i32>>) -> i32 {
    let mut xs = Vec::new();
    for i in points.iter() {
        xs.push(i[0]);
    }
    xs.sort();
    let mut result = -1;
    for i in 0..xs.len() - 1 {
        let k = xs[i + 1] - xs[i];
        if k > result {
            result = k;
        }
    }
    result
}

fn main() {
    println!("{}", max_width_of_vertical_area(vec![vec![8,7], vec![9,9], vec![7,4], vec![9,7]]));
}
