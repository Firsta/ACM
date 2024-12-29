pub fn num_ways(words: Vec<String>, target: String) -> i32 {
    let wn = words[0].len();
    let mut freq = vec![vec![0; 26]; wn];

    for i in 0..wn {
        for w in words.iter() {
            let idx = w.chars().nth(i).unwrap() as usize - 'a' as usize;
            freq[i][idx] += 1;
        }
    }

    let tn = target.len();
    let mut dp = vec![vec![0; wn + 1]; tn + 1];

    fn calc(x: i32, y: i32) -> i32 {
        if y == 0 {
            0
        } else {
            if y % 2 == 0 {
                calc(x, y / 2) * 2 % (10i32.pow(9) + 7)
            } else {
                if y == 1 {
                    x
                } else {
                    (calc(x, y - 1) + x) % (10i32.pow(9) + 7)
                }
            }
        }
    }
    for (idx, c) in target.chars().enumerate() {
        for j in 0..wn {
            if idx == 0 {
                dp[idx + 1][j + 1] = dp[idx + 1][j] + freq[j][c as usize - 'a' as usize];
            } else {
                let t = calc(dp[idx][j], freq[j][c as usize - 'a' as usize]);
                dp[idx + 1][j + 1] = (dp[idx + 1][j] + t) % (10i32.pow(9) + 7);
            }
        }
        // println!("{:?}", dp);
    }
    dp[tn][wn]
}

fn main() {
    assert_eq!(
        num_ways(
            vec!["acca".to_string(), "bbbb".to_string(), "caca".to_string()],
            "aba".to_string()
        ),
        6
    );
    assert_eq!(
        num_ways(
            vec!["abba".to_string(), "baab".to_string()],
            "bab".to_string()
        ),
        4
    );
}
