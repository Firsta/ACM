pub fn xor_queries(arr: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
    let mut p = Vec::new();
    let mut s = 0;
    p.push(s);
    for a in arr {
        s ^= a;
        p.push(s);
    }

    queries
        .into_iter()
        .map(|x| {
            let l = x[0] as usize;
            let r = x[1] as usize + 1;
            p[l] ^ p[r]
        })
        .collect()
}

fn main() {
    assert_eq!(
        xor_queries(
            vec![1, 3, 4, 8],
            vec![vec![0, 1], vec![1, 2], vec![0, 3], vec![3, 3]]
        ),
        vec![2, 7, 14, 8]
    );
    assert_eq!(
        xor_queries(
            vec![4, 8, 2, 10],
            vec![vec![2, 3], vec![1, 3], vec![0, 0], vec![0, 3]]
        ),
        vec![8, 0, 4, 4]
    );
}
