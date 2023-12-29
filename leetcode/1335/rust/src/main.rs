use std::{
    convert::TryFrom,
    cmp::{
        min,
        max,
    },
};

pub fn min_difficulty(job_difficulty: Vec<i32>, d: i32) -> i32 {
    let m = job_difficulty.len();
    let n = usize::try_from(d).unwrap();
    
    const INVALID: i32 = -1;
    if m < n {
        INVALID
    } else {
        let mut dp = vec![vec![INVALID; n + 1]; m + 1];

        dp[0][0] = 0;
        for i in 1..=m {
            for j in 1..=min(i, n) {
                let mut d = 0;
                dp[i][j] = i32::MAX;
                for k in (1..=i).rev() {
                    d = max(d, job_difficulty[k - 1]);
                    if dp[k - 1][j - 1] != INVALID {
                        dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + d);
                    }
                }
            }
            // println!("{:?}", dp);
        }

        dp[m][n]
    }
}

fn main() {
    println!("{}", min_difficulty(vec![6,5,4,3,2,1], 2));
}
