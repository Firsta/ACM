use std::collections::HashSet;

pub fn min_extra_char(s: String, dictionary: Vec<String>) -> i32 {
    let dictionary: HashSet<String> = dictionary.into_iter().collect();

    let n = s.len();
    let mut dp = vec![vec![5000; n]; n];

    for l in 1..=n {
        for i in 0..n - l + 1 {
            if dictionary.contains(&s[i..=i + l - 1].to_string()) {
                dp[i][i + l - 1] = 0;
            } else {
                dp[i][i + l - 1] = l;
                for j in i..=i + l - 1 {
                    dp[i][i + l - 1] = std::cmp::min(
                        dp[i][i + l - 1],
                        dp[i][j]
                            + if j == i + l - 1 {
                                0
                            } else {
                                dp[j + 1][i + l - 1]
                            },
                    );
                }
            }
        }
    }

    // println!("{:?}", dp);

    dp[0][n - 1] as i32
}

fn main() {
    assert_eq!(
        min_extra_char(
            "sayhelloworld".to_string(),
            vec!["hello".to_string(), "world".to_string()]
        ),
        3
    );
    assert_eq!(
        min_extra_char(
            "leetscode".to_string(),
            vec![
                "leet".to_string(),
                "code".to_string(),
                "leetcode".to_string()
            ]
        ),
        1
    );
    assert_eq!(
        min_extra_char(
            "kevlplxozaizdhxoimmraiakbak".to_string(),
            vec![
                "yv".to_string(),
                "bmab".to_string(),
                "hv".to_string(),
                "bnsll".to_string(),
                "mra".to_string(),
                "jjqf".to_string(),
                "g".to_string(),
                "aiyzi".to_string(),
                "ip".to_string(),
                "pfctr".to_string(),
                "flr".to_string(),
                "ybbcl".to_string(),
                "biu".to_string(),
                "ke".to_string(),
                "lpl".to_string(),
                "iak".to_string(),
                "pirua".to_string(),
                "ilhqd".to_string(),
                "zdhx".to_string(),
                "fux".to_string(),
                "xaw".to_string(),
                "pdfvt".to_string(),
                "xf".to_string(),
                "t".to_string(),
                "wq".to_string(),
                "r".to_string(),
                "cgmud".to_string(),
                "aokas".to_string(),
                "xv".to_string(),
                "jf".to_string(),
                "cyys".to_string(),
                "wcaz".to_string(),
                "rvegf".to_string(),
                "ysg".to_string(),
                "xo".to_string(),
                "uwb".to_string(),
                "lw".to_string(),
                "okgk".to_string(),
                "vbmi".to_string(),
                "v".to_string(),
                "mvo".to_string(),
                "fxyx".to_string(),
                "ad".to_string(),
                "e".to_string()
            ]
        ),
        9
    );
}
