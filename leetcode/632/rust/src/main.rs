pub fn smallest_range(nums: Vec<Vec<i32>>) -> Vec<i32> {
    let n_cnt = nums.len();

    let mut v = Vec::new();
    for (idx, num) in nums.into_iter().enumerate() {
        for n in num.into_iter() {
            v.push((n, idx));
        }
    }
    v.sort();
    // println!("{:?}", v);

    let mut l = 0;
    let mut ss = std::collections::HashMap::new();
    let mut ans = None;

    for r in 0..v.len() {
        ss.entry(v[r].1).and_modify(|e| *e += 1).or_insert(1);
        if ss.len() == n_cnt {
            // println!("before: {} {}", l, r);
            while ss.len() == n_cnt && l <= r {
                ans = match ans {
                    None => Some((v[l].0, v[r].0)),
                    Some(ans) => {
                        if ans.1 - ans.0 > v[r].0 - v[l].0 {
                            Some((v[l].0, v[r].0))
                        } else {
                            Some(ans)
                        }
                    }
                };
                let now = *ss.get(&v[l].1).unwrap();
                if now == 1 {
                    ss.remove(&v[l].1);
                } else {
                    ss.insert(v[l].1, now - 1);
                }
                l += 1;
            }
            // println!("after: {} {}", l, r);
        }
    }

    // println!("{:?}", ans);
    let ans = ans.unwrap();

    vec![ans.0, ans.1]
}

fn main() {
    assert_eq!(
        smallest_range(vec![
            vec![4, 10, 15, 24, 26],
            vec![0, 9, 12, 20],
            vec![5, 18, 22, 30]
        ]),
        vec![20, 24]
    );
}
