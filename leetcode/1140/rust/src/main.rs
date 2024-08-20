pub fn stone_game_ii(piles: Vec<i32>) -> i32 {
    let n = piles.len();

    let mut sum = 0;
    let mut suffix_sums = Vec::new();
    for i in (0..n).rev() {
        sum += piles[i];
        suffix_sums.push(sum);
    }
    suffix_sums.reverse();

    fn max_stones(suffix_sums: &Vec<i32>, idx: usize, m: usize, dp: &mut Vec<Vec<i32>>) -> i32 {
        if idx + 2 * m >= suffix_sums.len() {
            suffix_sums[idx]
        } else if dp[idx][m] != -1 {
            dp[idx][m]
        } else {
            let min_max = (1..=2 * m)
                .map(|p| max_stones(suffix_sums, idx + p, std::cmp::max(p, m), dp))
                .min()
                .unwrap();
            dp[idx][m] = suffix_sums[idx] - min_max;
            dp[idx][m]
        }
    }

    let mut dp = vec![vec![-1; n]; n];

    max_stones(&suffix_sums, 0, 1, &mut dp)
}

fn main() {
    assert_eq!(stone_game_ii(vec![2, 7, 9, 4, 4]), 10);
}
