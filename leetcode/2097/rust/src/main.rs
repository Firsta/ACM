use std::collections::{HashMap, VecDeque};

pub fn valid_arrangement(pairs: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut g: HashMap<i32, VecDeque<i32>> = HashMap::new();
    let mut in_degree = HashMap::new();
    let mut out_degree = HashMap::new();

    for pair in pairs.iter() {
        g.entry(pair[0])
            .and_modify(|e| e.push_back(pair[1]))
            .or_insert(VecDeque::from([pair[1]]));
        in_degree
            .entry(pair[1])
            .and_modify(|e| *e += 1)
            .or_insert(1);
        out_degree
            .entry(pair[0])
            .and_modify(|e| *e += 1)
            .or_insert(1);
    }

    let mut start = -1;
    for o in out_degree.iter() {
        if in_degree.get(o.0).cloned().unwrap_or_default() + 1 == *o.1 {
            start = *o.0;
            break;
        }
    }
    if start == -1 {
        start = pairs[0][0];
    }

    let mut stack = Vec::new();
    stack.push(start);

    let mut ret = Vec::new();

    while !stack.is_empty() {
        let node = stack.last().unwrap().clone();
        match g.get_mut(&node) {
            None => {
                ret.push(node);
                stack.pop();
            }
            Some(q) => {
                if q.is_empty() {
                    ret.push(node);
                    stack.pop();
                } else {
                    let next_node = q.pop_front().unwrap();
                    stack.push(next_node);
                }
            }
        }
    }

    ret.reverse();

    let mut ans = Vec::new();
    for i in 0..ret.len() - 1 {
        ans.push(vec![ret[i], ret[i + 1]]);
    }

    ans
}

fn main() {
    assert_eq!(
        valid_arrangement(vec![vec![5, 1], vec![4, 5], vec![11, 9], vec![9, 4]]),
        vec![vec![11, 9], vec![9, 4], vec![4, 5], vec![5, 1]]
    );
}
