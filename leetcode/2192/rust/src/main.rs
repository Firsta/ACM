use std::collections::BTreeSet;
use std::collections::HashSet;
use std::collections::VecDeque;

pub fn get_ancestors(n: i32, edges: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let n = n as usize;
    let mut g = vec![Vec::<usize>::new(); n];
    let mut ine = vec![0; n];

    for e in edges.into_iter() {
        g[e[0] as usize].push(e[1] as usize);
        ine[e[1] as usize] += 1;
    }

    let mut q = VecDeque::new();
    let mut ans = vec![BTreeSet::<i32>::new(); n];
    for i in 0..n {
        if ine[i] == 0 {
            q.push_back(i);
        }
    }

    while !q.is_empty() {
        let mut q2 = VecDeque::new();
        let mut inserted = HashSet::new();
        for from in q.into_iter() {
            for &d in g[from].iter() {
                let l = ans[from].clone();
                ans[d].extend(l);
                ans[d].insert(from as i32);
                if !inserted.contains(&d) {
                    q2.push_back(d);
                    inserted.insert(d);
                }
            }
        }
        q = q2;
    }

    ans.into_iter().map(|x| Vec::from_iter(x)).collect()
}

fn main() {
    assert_eq!(
        get_ancestors(
            8,
            vec![
                vec![0, 3],
                vec![0, 4],
                vec![1, 3],
                vec![2, 4],
                vec![2, 7],
                vec![3, 5],
                vec![3, 6],
                vec![3, 7],
                vec![4, 6]
            ]
        ),
        vec![
            vec![],
            vec![],
            vec![],
            vec![0, 1],
            vec![0, 2],
            vec![0, 1, 3],
            vec![0, 1, 2, 3, 4],
            vec![0, 1, 2, 3]
        ]
    );
}
