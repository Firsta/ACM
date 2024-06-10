pub fn height_checker(heights: Vec<i32>) -> i32 {
    let mut h = heights.clone();
    h.sort();

    let mut ans = 0;
    for i in 0..heights.len() {
        if h[i] != heights[i] {
            ans += 1;
        }
    }

    ans
}

fn main() {
    assert_eq!(height_checker(vec![1, 1, 4, 2, 1, 3]), 3);
}
