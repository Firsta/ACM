use std::collections::HashSet;

pub fn vowel_strings(words: Vec<String>, queries: Vec<Vec<i32>>) -> Vec<i32> {
    let mut cnt = 0;
    let vowels = HashSet::from(['a', 'e', 'i', 'o', 'u']);
    let mut cnts = vec![0];
    for w in words {
        if vowels.contains(&w.chars().nth(0).unwrap())
            && vowels.contains(&w.chars().last().unwrap())
        {
            cnt += 1;
        }
        cnts.push(cnt);
    }
    queries
        .iter()
        .map(|x| {
            let l = x[0] as usize;
            let r = x[1] as usize;
            (cnts[r + 1] - cnts[l]) as i32
        })
        .collect()
}

fn main() {
    assert_eq!(
        vowel_strings(
            vec![
                "aba".to_string(),
                "bcb".to_string(),
                "ece".to_string(),
                "aa".to_string(),
                "e".to_string()
            ],
            vec![vec![0, 2], vec![1, 4], vec![1, 1]]
        ),
        vec![2, 3, 0]
    );
}
