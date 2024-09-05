pub fn missing_rolls(rolls: Vec<i32>, mean: i32, n: i32) -> Vec<i32> {
    let m = rolls.len() as i32;
    let s = (m + n) * mean;
    let ms: i32 = rolls.iter().sum();
    let r = s - ms;
    if r < n || r > n * 6 {
        Vec::new()
    } else {
        let mut b = 1;
        for i in 1..=6 {
            if r / i >= n {
                b = i;
            } else {
                break;
            }
        }
        let mut ans = vec![b; n as usize];
        let mut rr = r - b * n;
        for i in 0..n as usize {
            let d = std::cmp::min(6 - ans[i], rr);
            ans[i] += d;
            rr -= d;
        }
        ans
    }
}

fn main() {
    assert_eq!(missing_rolls(vec![3, 2, 4, 3], 4, 2), vec![6, 6]);
    assert_eq!(missing_rolls(vec![1, 5, 6], 3, 4), vec![3, 2, 2, 2]);
    assert_eq!(missing_rolls(vec![1, 2, 3, 4], 6, 4), vec![]);
}
