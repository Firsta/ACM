use std::collections::HashMap;

pub fn build_matrix(
    k: i32,
    row_conditions: Vec<Vec<i32>>,
    col_conditions: Vec<Vec<i32>>,
) -> Vec<Vec<i32>> {
    fn order(k: &usize, conditions: Vec<Vec<i32>>) -> Option<HashMap<usize, usize>> {
        let mut g = vec![Vec::<usize>::new(); *k];
        let mut ind = vec![0; *k];

        for c in conditions.iter() {
            g[(c[0] - 1) as usize].push((c[1] - 1) as usize);
            ind[(c[1] - 1) as usize] += 1;
        }

        let mut v = Vec::new();

        for i in 0..*k {
            if ind[i] == 0 {
                v.push(i);
            }
        }

        let mut order = HashMap::new();
        let mut i = 0;
        while !v.is_empty() {
            let mut t = Vec::new();
            for &s in v.iter() {
                for &d in g[s].iter() {
                    if ind[d] == 0 {
                        return None;
                    }
                    ind[d] -= 1;
                    if ind[d] == 0 {
                        t.push(d);
                    }
                }
                order.insert(s.clone(), i.clone());
                i += 1;
            }

            v = t;
        }

        for j in 0..*k {
            if ind[j] > 0 {
                return None;
            }
            if !order.contains_key(&j) {
                order.insert(j.clone(), i.clone());
                i += 1;
            }
        }

        Some(order)
    }

    let k = k as usize;

    let row_order = order(&k, row_conditions);
    if row_order.is_none() {
        return Vec::new();
    }
    let row_order = row_order.unwrap();

    let col_order = order(&k, col_conditions);
    if col_order.is_none() {
        return Vec::new();
    }
    let col_order = col_order.unwrap();

    let mut ans = vec![vec![0; k]; k];

    // println!("{:?}", ans);

    for i in 0..k {
        ans[row_order[&i]][col_order[&i]] = (i + 1) as i32;
    }

    ans
}
fn main() {
    assert!(build_matrix(
        3,
        vec![vec![1, 2], vec![2, 3], vec![3, 1], vec![2, 3]],
        vec![vec![2, 1]]
    )
    .is_empty(),);
}
