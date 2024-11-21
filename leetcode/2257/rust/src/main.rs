use std::collections::HashMap;

pub fn count_unguarded(m: i32, n: i32, guards: Vec<Vec<i32>>, walls: Vec<Vec<i32>>) -> i32 {
    let mut horizon_guards_and_walls: HashMap<i32, Vec<(i32, bool)>> = HashMap::new();
    let mut vertical_guards_and_walls: HashMap<i32, Vec<(i32, bool)>> = HashMap::new();
    for guard in guards.iter() {
        horizon_guards_and_walls
            .entry(guard[0])
            .and_modify(|e| e.push((guard[1].clone(), true)))
            .or_insert(vec![(guard[1].clone(), true)]);
        vertical_guards_and_walls
            .entry(guard[1])
            .and_modify(|e| e.push((guard[0].clone(), true)))
            .or_insert(vec![(guard[0].clone(), true)]);
    }
    for wall in walls.iter() {
        horizon_guards_and_walls
            .entry(wall[0])
            .and_modify(|e| e.push((wall[1].clone(), false)))
            .or_insert(vec![(wall[1].clone(), false)]);
        vertical_guards_and_walls
            .entry(wall[1])
            .and_modify(|e| e.push((wall[0].clone(), false)))
            .or_insert(vec![(wall[0].clone(), false)]);
    }

    for v in horizon_guards_and_walls.values_mut() {
        v.sort_by(|a, b| a.0.cmp(&b.0));
    }

    for v in vertical_guards_and_walls.values_mut() {
        v.sort_by(|a, b| a.0.cmp(&b.0));
    }

    // println!("{:?}", horizon_guards_and_walls,);
    // println!("{:?}", vertical_guards_and_walls);

    let mut ans = m * n;
    for i in 0..m {
        for j in 0..n {
            let mut occupied = if let Some(h) = horizon_guards_and_walls.get(&i) {
                if j < h[0].0 {
                    // if is guard
                    h[0].1
                } else if j > h[h.len() - 1].0 {
                    h[h.len() - 1].1
                } else {
                    let p = h.partition_point(|x| x.0 < j);
                    if h[p].0 == j {
                        true
                    } else {
                        h[p].1 || h[p - 1].1
                    }
                }
            } else {
                false
            };
            occupied = occupied
                | if let Some(v) = vertical_guards_and_walls.get(&j) {
                    if i < v[0].0 {
                        // if is guard
                        v[0].1
                    } else if i > v[v.len() - 1].0 {
                        v[v.len() - 1].1
                    } else {
                        let p = v.partition_point(|x| x.0 < i);
                        if v[p].0 == i {
                            true
                        } else {
                            v[p].1 || v[p - 1].1
                        }
                    }
                } else {
                    false
                };
            if occupied {
                ans -= 1;
            }

            // println!("{} {} {}", i, j, occupied);
        }
    }

    ans
}

fn main() {
    assert_eq!(
        count_unguarded(
            4,
            6,
            vec![vec![0, 0], vec![1, 1], vec![2, 3]],
            vec![vec![0, 1], vec![2, 2], vec![1, 4]]
        ),
        7
    );
    assert_eq!(
        count_unguarded(
            3,
            3,
            vec![vec![1, 1]],
            vec![vec![0, 1], vec![1, 0], vec![2, 1], vec![1, 2]]
        ),
        4
    );
}
