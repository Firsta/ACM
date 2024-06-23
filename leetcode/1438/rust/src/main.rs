use std::collections::{BTreeMap, VecDeque};

pub fn longest_subarray(nums: Vec<i32>, limit: i32) -> i32 {
    let mut m = BTreeMap::new();
    let mut q = VecDeque::new();

    let mut ans = 0;
    for n in nums.into_iter() {
        q.push_back(n);
        m.entry(n).and_modify(|e| *e += 1).or_insert(1);
        // println!("{:?} {:?}", q, m);

        while !m.is_empty()
            && *m.last_entry().unwrap().key() - *m.first_entry().unwrap().key() > limit
        {
            let d = q.pop_front().unwrap();
            let c = m.get(&d).unwrap().clone();
            if c == 1 {
                m.remove(&d);
            } else {
                m.insert(d, c - 1);
            }
        }

        ans = std::cmp::max(ans, q.len());
    }

    ans as i32
}

fn main() {
    assert_eq!(longest_subarray(vec![8, 2, 4, 7], 4), 2);
    assert_eq!(longest_subarray(vec![10, 1, 2, 4, 7, 2], 5), 4);
    assert_eq!(longest_subarray(vec![4, 2, 2, 2, 4, 4, 2, 2], 0), 3);
}
