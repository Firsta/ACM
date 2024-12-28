pub fn max_sum_of_three_subarrays(nums: Vec<i32>, k: i32) -> Vec<i32> {
    let n = nums.len();
    let k = k as usize;
    let mut dp = vec![vec![(0, Vec::new()); 4]; n];
    {
        for i in 0..k {
            dp[k - 1][1].0 += nums[i];
        }
        dp[k - 1][1].1.push(0);
    }

    // println!("{dp:?} {}", k);

    for i in k..n {
        let t = nums[i + 1 - k..=i].iter().sum();

        dp[i][1] = dp[i - 1][1].clone();
        if dp[i - 1][1].0 < t {
            dp[i][1] = (t, vec![i + 1 - k])
        };

        dp[i][2] = dp[i - 1][2].clone();
        if dp[i - k][1].0 > 0 && t + dp[i - k][1].0 > dp[i][2].0 {
            dp[i][2] = dp[i - k][1].clone();
            dp[i][2].0 += t;
            dp[i][2].1.push(i + 1 - k);
        }

        dp[i][3] = dp[i - 1][3].clone();
        if dp[i - k][2].0 > 0 && t + dp[i - k][2].0 > dp[i][3].0 {
            dp[i][3] = dp[i - k][2].clone();
            dp[i][3].0 += t;
            dp[i][3].1.push(i + 1 - k);
        }
        // println!("{} {:?}", i, dp[i]);
    }

    // println!("{dp:?}");
    // println!("{} {:?}", n - 1 - 2, dp[n - 1 - 2][2]);

    dp[n - 1][3].1.iter().map(|x| *x as i32).collect()
}

fn main() {
    assert_eq!(
        max_sum_of_three_subarrays(vec![1, 2, 1, 2, 6, 7, 5, 1], 2),
        vec![0, 3, 5]
    );
    assert_eq!(
        max_sum_of_three_subarrays(vec![1, 2, 1, 2, 1, 2, 1, 2, 1], 2),
        vec![0, 2, 4]
    );
}
