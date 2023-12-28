use std::cmp::min;

pub fn get_length_of_optimal_compression(s: String, k: i32) -> i32 {
    let m = k as usize;
    let mut dp = vec![vec![0; m + 1]; s.len() + 1];
    for i in 1..=s.len() {
        for j in 0..=min(i, m) {
            dp[i][j] = if j > 0 {
                dp[i - 1][j - 1]
            } else {
                110
            };
            let mut need_remove = 0;
            let mut group_count = 0;
            let s_i = s.as_bytes()[i - 1];
            for k in (1..=i).rev() {
                // println!("{} {} {}", i, j, k);
                let s_k = s.as_bytes()[k - 1];
                if s_i == s_k {
                    group_count += 1;
                } else {
                    need_remove += 1;
                }
                if need_remove > j {
                    break;
                } else {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[k - 1][j - need_remove] + match group_count {
                            1 => 1,
                            1..=9 => 2,
                            10..=99 => 3,
                            _ => 4,
                        },
                    );
                }
            }
        }
        // println!("{:?}", dp);
    } 
    dp[s.len()][m]
}

fn main() {
    println!("{}", get_length_of_optimal_compression("aaabcccd".to_string(), 2));
}
