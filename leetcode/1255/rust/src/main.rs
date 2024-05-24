pub fn max_score_words(words: Vec<String>, letters: Vec<char>, score: Vec<i32>) -> i32 {
    let n = words.len();
    let mut cnt = vec![0; 26];
    for l in letters.into_iter() {
        cnt[l as usize - 'a' as usize] += 1;
    }

    let mut ans = 0;
    for i in 0..2_i32.pow(n as u32) {
        let mut picked = Vec::new();
        for j in 0..n {
            if (1 << j) & i != 0 {
                picked.push(words[j].clone());
            }
        }

        let mut s = 0;
        let mut cnt = cnt.clone();
        let mut ok = true;
        for w in picked.iter() {
            for c in w.chars() {
                let c = c as usize - 'a' as usize;
                if cnt[c] == 0 {
                    ok = false;
                    break;
                } else {
                    cnt[c] -= 1;
                    s += score[c];
                }
            }
        }
        // println!("{:?} {}", picked, s);
        if ok && s > ans {
            ans = s;
        }
    }

    ans
}

fn main() {
    assert_eq!(
        max_score_words(
            vec![
                "dog".to_string(),
                "cat".to_string(),
                "dad".to_string(),
                "good".to_string()
            ],
            vec!['a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'],
            vec![1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        ),
        23
    );
}
