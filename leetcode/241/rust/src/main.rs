pub fn diff_ways_to_compute(expression: String) -> Vec<i32> {
    fn dfs(exp: &str, l: usize, r: usize, dp: &mut Vec<Vec<Vec<i32>>>) {
        if dp[l][r].is_empty() {
            let mut ans = Vec::new();

            let mut find_op = false;
            for i in l..=r {
                let c = exp.as_bytes()[i] as char;
                if c == '+' {
                    dfs(exp, l, i - 1, dp);
                    dfs(exp, i + 1, r, dp);
                    let ls = &dp[l][i - 1];
                    let rs = &dp[i + 1][r];
                    for ln in ls.iter() {
                        for rn in rs.iter() {
                            ans.push((*ln) + (*rn));
                        }
                    }
                    find_op = true;
                } else if c == '-' {
                    dfs(exp, l, i - 1, dp);
                    dfs(exp, i + 1, r, dp);
                    let ls = &dp[l][i - 1];
                    let rs = &dp[i + 1][r];
                    for ln in ls.iter() {
                        for rn in rs.iter() {
                            ans.push((*ln) - (*rn));
                        }
                    }
                    find_op = true;
                } else if c == '*' {
                    dfs(exp, l, i - 1, dp);
                    dfs(exp, i + 1, r, dp);
                    let ls = &dp[l][i - 1];
                    let rs = &dp[i + 1][r];
                    for ln in ls.iter() {
                        for rn in rs.iter() {
                            ans.push((*ln) * (*rn));
                        }
                    }
                    find_op = true;
                }
            }
            if !find_op {
                ans.push(exp[l..=r].parse::<i32>().unwrap().clone());
            }
            dp[l][r] = ans;
        }
    }

    let n = expression.len();
    let mut dp = vec![vec![Vec::new(); n]; n];

    dfs(&expression, 0, n - 1, &mut dp);

    dp[0][n - 1].clone().into_iter().collect()
}

fn main() {
    assert_eq!(
        diff_ways_to_compute("2*3-4*5".to_string()),
        vec![-34, -10, -14, -10, 10]
    );
}
