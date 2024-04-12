pub fn trap(height: Vec<i32>) -> i32 {
    let n = height.len();

    let mut left = vec![0; n];
    left[0] = height[0];
    for i in 1..height.len() {
        left[i] = std::cmp::max(height[i], left[i - 1]);
    }
    // println!("{:?}", left);

    let mut right = vec![0; n];
    right[n - 1] = height[n - 1];
    for i in (0..n - 1).rev() {
        right[i] = std::cmp::max(height[i], right[i + 1]);
    }
    // println!("{:?}", right);

    let mut result = 0;
    for i in 0..n {
        let t = std::cmp::min(left[i], right[i]);
        if t > height[i] {
            result += t - height[i];
        }
        // println!("{} {} {}", i, t, result);
    }

    result
}

fn main() {
    assert_eq!(trap(vec![0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]), 6);
    assert_eq!(trap(vec![4, 2, 0, 3, 2, 5]), 9);
}
