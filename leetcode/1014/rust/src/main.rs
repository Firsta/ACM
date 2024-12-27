pub fn max_score_sightseeing_pair(values: Vec<i32>) -> i32 {
    let n = values.len();
    let mut dp = values[0];
    let mut ans = 0;
    for i in 1..n {
        dp = std::cmp::max(dp - 1, values[i - 1] - 1);
        ans = std::cmp::max(ans, values[i] + dp);
    }
    ans
}

fn main() {
    assert_eq!(max_score_sightseeing_pair(vec![8, 1, 5, 2, 6]), 11);
    assert_eq!(max_score_sightseeing_pair(vec![1, 2]), 2);
}
