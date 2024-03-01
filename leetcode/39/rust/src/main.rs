pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
    let mut dp = vec![Vec::new(); target as usize + 1];

    let mut candidates = candidates.clone();
    candidates.sort();

    dp[0].push(vec![]);

    for i in 1..=target {
        let mut vv = Vec::new();

        for &c in candidates.iter() {
            if c <= i {
                for v in dp[(i - c) as usize].iter() {
                    let mut nv = v.clone();
                    let pos = nv.binary_search(&c).unwrap_or_else(|e| e);
                    nv.insert(pos, c);

                    let mut is_new = true;
                    for v in vv.iter() {
                        if v == &nv {
                            is_new = false;
                        }
                    }
                    if is_new {
                        vv.push(nv);
                    }
                }
            }
        }

        dp[i as usize] = vv;
    }

    // println!("{:?}", dp);

    dp[target as usize].clone()
}

fn main() {
    assert_eq!(
        combination_sum(vec![2, 3, 6, 7], 7),
        vec![vec![2, 2, 3], vec![7]]
    );
    assert_eq!(
        combination_sum(vec![2, 3, 5], 8),
        vec![vec![2, 2, 2, 2], vec![2, 3, 3], vec![3, 5]]
    );
}
