pub fn maximum_value_sum(nums: Vec<i32>, k: i32, edges: Vec<Vec<i32>>) -> i64 {
    let nums: Vec<i64> = nums.into_iter().map(|x| x.into()).collect();

    let n = nums.len();

    let mut ans = nums.iter().sum();

    let mut deltas: Vec<i64> = nums.into_iter().map(|x| (x ^ k as i64) - x).collect();
    // println!("{:?}", deltas);
    deltas.sort_by(|a, b| b.cmp(&a));

    let mut i = 0usize;
    while i + 1 < n && deltas[i] + deltas[i + 1] > 0 {
        ans += deltas[i] + deltas[i + 1];
        i += 2;
    }

    ans
}

fn main() {
    assert_eq!(
        maximum_value_sum(vec![1, 2, 1], 3, vec![vec![0, 1], vec![0, 2]]),
        6
    );
}
