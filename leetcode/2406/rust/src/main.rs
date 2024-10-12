pub fn min_groups(intervals: Vec<Vec<i32>>) -> i32 {
    let mut events = Vec::new();
    for i in intervals.into_iter() {
        events.push((i[0], 1));
        events.push((i[1], -1));
    }
    events.sort_by(|a, b| {
        if a.0 == b.0 {
            b.1.cmp(&a.1)
        } else {
            a.0.cmp(&b.0)
        }
    });

    let mut ans = 0;
    let mut c = 0;
    for e in events.into_iter() {
        c += e.1;
        ans = std::cmp::max(ans, c);
    }

    ans
}

fn main() {
    assert_eq!(
        min_groups(vec![
            vec![5, 10],
            vec![6, 8],
            vec![1, 5],
            vec![2, 3],
            vec![1, 10]
        ]),
        3
    );
}
