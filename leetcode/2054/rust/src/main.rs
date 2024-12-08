use std::collections::HashMap;

pub fn max_two_events(events: Vec<Vec<i32>>) -> i32 {
    let mut events = events;
    events.sort_by(|a, b| a[0].cmp(&b[0]));

    let mut m = HashMap::new();
    let mut mmax = 0;
    for i in (0..events.len()).rev() {
        mmax = std::cmp::max(mmax, events[i][2]);
        m.entry(&events[i][0])
            .and_modify(|e| {
                if mmax > *e {
                    *e = mmax;
                }
            })
            .or_insert(mmax);
    }
    let mut v = Vec::new();
    for i in (0..events.len()).rev() {
        v.push((events[i][0], m.get(&events[i][0]).unwrap().clone()));
    }
    v.reverse();

    // println!("{:?}", v);
    let mut ans = 0;
    for e in events {
        let end = e[1];
        let mut t = e[2];
        if end < v.last().unwrap().0 {
            let p = v.partition_point(|x| x.0 <= end);
            t += v[p].1;
        }
        ans = std::cmp::max(ans, t);
    }

    ans
}

fn main() {
    assert_eq!(
        max_two_events(vec![vec![1, 3, 2], vec![4, 5, 2], vec![2, 4, 3]]),
        4
    );
    assert_eq!(
        max_two_events(vec![vec![1, 3, 2], vec![4, 5, 2], vec![1, 5, 5]]),
        5
    );
    assert_eq!(
        max_two_events(vec![vec![1, 5, 3], vec![1, 5, 1], vec![6, 6, 5]]),
        8
    );
    assert_eq!(
        max_two_events(vec![
            vec![66, 97, 90],
            vec![98, 98, 68],
            vec![38, 49, 63],
            vec![91, 100, 42],
            vec![92, 100, 22],
            vec![1, 77, 50],
            vec![64, 72, 97]
        ]),
        165
    );
}
