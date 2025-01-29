use std::collections::HashMap;

pub fn find_redundant_connection(edges: Vec<Vec<i32>>) -> Vec<i32> {
    let n = edges.len();
    let mut g = vec![Vec::<usize>::new(); n + 1];
    let mut m = HashMap::new();
    for (i, e) in edges.iter().enumerate() {
        g[e[0] as usize].push(e[1] as usize);
        g[e[1] as usize].push(e[0] as usize);
        m.insert((e[0] as usize, e[1] as usize), i);
    }

    fn find_loop(
        cur: usize,
        g: &Vec<Vec<usize>>,
        done: &mut Vec<bool>,
        path: &mut Vec<usize>,
        loop_path: &mut Vec<usize>,
    ) -> bool {
        done[cur] = true;
        let pre = path.last().cloned();

        path.push(cur);
        // println!("{:?}", path);
        for &child in g[cur].iter() {
            if Some(child) != pre {
                // println!("cur: {} child: {} {:?}", cur, child, pre);

                if done[child] {
                    // loop find
                    // println!("loop find child: {} {:?}", child, pre);

                    for i in 0..path.len() {
                        if path[i] == child {
                            *loop_path = path[i..].iter().map(|x| *x).collect();
                        }
                    }
                    return true;
                } else {
                    if find_loop(child, g, done, path, loop_path) {
                        return true;
                    }
                }
            }
        }
        path.pop();
        false
    }

    let mut done = vec![false; n + 1];
    let mut path = Vec::new();
    let mut loop_path = Vec::new();

    find_loop(1, &g, &mut done, &mut path, &mut loop_path);

    // println!("loop_path: {:?}", loop_path);

    let mut ans = None;
    let mut idx = None;
    for i in 0..loop_path.len() {
        let a = loop_path[i];
        let b = loop_path[(i + 1) % loop_path.len()];
        let e = (std::cmp::min(a, b), std::cmp::max(a, b));
        match ans {
            None => {
                ans = Some(e);
                idx = Some(m.get(&e).unwrap());
            }
            Some(_) => {
                let ii = m.get(&e).unwrap();
                if ii > idx.unwrap() {
                    ans = Some(e);
                    idx = Some(ii);
                }
            }
        }
    }

    edges[*idx.unwrap()].clone()
}

// 2-7-8
//  \5

fn main() {
    assert_eq!(
        find_redundant_connection(vec![vec![1, 2], vec![1, 3], vec![2, 3]]),
        vec![2, 3]
    );
    assert_eq!(
        find_redundant_connection(vec![
            vec![1, 2],
            vec![2, 3],
            vec![3, 4],
            vec![1, 4],
            vec![1, 5]
        ]),
        vec![1, 4]
    );
    assert_eq!(
        find_redundant_connection(vec![
            vec![2, 7],
            vec![7, 8],
            vec![3, 6],
            vec![2, 5],
            vec![6, 8],
            vec![4, 8],
            vec![2, 8],
            vec![1, 8],
            vec![7, 10],
            vec![3, 9]
        ]),
        vec![2, 8]
    );
}
