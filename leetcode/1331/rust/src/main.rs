pub fn array_rank_transform(arr: Vec<i32>) -> Vec<i32> {
    let mut t: Vec<(usize, i32)> = arr.into_iter().enumerate().collect();
    t.sort_by(|a, b| a.1.cmp(&b.1));
    let mut ans = vec![0; t.len()];
    let mut last = None;
    let mut rank = 0;
    for tt in t.into_iter() {
        if last.is_none() || last.unwrap() != tt.1 {
            rank += 1;
        }
        last = Some(tt.1);
        ans[tt.0] = rank;
    }
    ans
}

fn main() {
    assert_eq!(array_rank_transform(vec![40, 10, 20, 30]), vec![4, 1, 2, 3]);
}
