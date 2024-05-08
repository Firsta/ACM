pub fn find_relative_ranks(score: Vec<i32>) -> Vec<String> {
    let mut sorted = score.clone();
    sorted.sort();
    // println!("{:?}", sorted);

    let mut ans = Vec::new();
    let n = score.len();
    for s in score.into_iter() {
        let idx = n - sorted.binary_search(&s).unwrap();

        ans.push(match idx {
            1 => "Gold Medal".to_string(),
            2 => "Silver Medal".to_string(),
            3 => "Bronze Medal".to_string(),
            _ => idx.to_string(),
        });
    }
    ans
}

fn main() {
    assert_eq!(
        find_relative_ranks(vec![10, 3, 8, 9, 4]),
        vec![
            "Gold Medal".to_string(),
            "5".to_string(),
            "Bronze Medal".to_string(),
            "Silver Medal".to_string(),
            "4".to_string()
        ]
    );
}
