use std::collections::{BTreeMap, BTreeSet};

pub fn combination_sum2(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
    let mut m = BTreeMap::<i32, BTreeSet<Vec<i32>>>::new();

    let mut ans = BTreeSet::new();
    for c in candidates.into_iter() {
        let mut to_insert = Vec::new();
        for (k, v) in m.iter() {
            if c + *k <= target {
                let mut t: BTreeSet<Vec<i32>> = v
                    .clone()
                    .into_iter()
                    .map(|x| {
                        let mut x = x.clone();
                        x.push(c);
                        x.sort();
                        x
                    })
                    .collect();
                // println!("{:?} {:?}", v, t);
                if c + *k < target {
                    to_insert.push((c + *k, t));
                } else {
                    ans.append(&mut t);
                }
            }
        }
        if c < target {
            to_insert.push((c, BTreeSet::from([vec![c]])));
        } else if c == target {
            ans.insert(vec![c]);
        }
        for (k, v) in to_insert.into_iter() {
            let mut v = v;
            m.entry(k).and_modify(|e| e.append(&mut v)).or_insert(v);
        }
    }

    Vec::from_iter(ans)
}

fn main() {
    assert_eq!(
        combination_sum2(vec![10, 1, 2, 7, 6, 1, 5], 8),
        vec![vec![1, 1, 6], vec![1, 2, 5], vec![1, 7], vec![2, 6]]
    );
    assert_eq!(
        combination_sum2(vec![2, 5, 2, 1, 2], 5),
        vec![vec![1, 2, 2], vec![5]]
    );
    assert!(combination_sum2(
        vec![1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        27
    )
    .is_empty());
}
