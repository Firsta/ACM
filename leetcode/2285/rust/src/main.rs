pub fn maximum_importance(n: i32, roads: Vec<Vec<i32>>) -> i64 {
    let n = n as usize;
    let mut l = vec![0; n];

    for r in roads.into_iter() {
        l[r[0] as usize] += 1;
        l[r[1] as usize] += 1;
    }

    l.sort();
    let mut ans = 0i64;
    for i in (1..=n).rev() {
        ans += i as i64 * l[i - 1] as i64;
    }

    ans
}

fn main() {
    assert_eq!(
        maximum_importance(
            5,
            vec![
                vec![0, 1],
                vec![1, 2],
                vec![2, 3],
                vec![0, 2],
                vec![1, 3],
                vec![2, 4]
            ]
        ),
        43
    );
}
