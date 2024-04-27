pub fn find_rotate_steps(ring: String, key: String) -> i32 {
    fn count_steps(ai: usize, bi: usize, n: usize) -> usize {
        let mmin = std::cmp::min(ai, bi);
        let mmax = std::cmp::max(ai, bi);
        std::cmp::min(mmax - mmin, mmin + n - mmax)
    }

    let mut dp = vec![std::usize::MAX; ring.len()];

    for (ri, rc) in ring.chars().enumerate() {
        if rc == key.as_bytes()[0] as char {
            dp[ri] = count_steps(ri, 0, ring.len());
        }
    }

    for ki in 1..key.len() {
        let kc = key.as_bytes()[ki] as char;
        let mut new_dp = vec![std::usize::MAX; ring.len()];
        for (ri, rc) in ring.chars().enumerate() {
            if rc == kc {
                for rri in 0..ring.len() {
                    if dp[rri] != std::usize::MAX {
                        new_dp[ri] =
                            std::cmp::min(new_dp[ri], dp[rri] + count_steps(ri, rri, ring.len()));
                    }
                }
            }
        }
        dp = new_dp;
    }

    (dp.iter().min().unwrap() + key.len()) as i32
}

fn main() {
    assert_eq!(
        find_rotate_steps("godding".to_string(), "gd".to_string()),
        4
    );
    assert_eq!(
        find_rotate_steps("godding".to_string(), "godding".to_string()),
        13
    );
}
