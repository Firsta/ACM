use std::collections::HashMap;

pub fn robot_sim(commands: Vec<i32>, obstacles: Vec<Vec<i32>>) -> i32 {
    let mut cur = (0, 0);
    let mut dir = 0;

    let mut horizon_obstacles = HashMap::<i32, Vec<i32>>::new();
    let mut vertical_obstacles = HashMap::<i32, Vec<i32>>::new();
    for o in obstacles.into_iter() {
        let x = o[0];
        let y = o[1];
        horizon_obstacles
            .entry(y)
            .and_modify(|e| {
                e.push(x);
            })
            .or_insert(vec![x]);
        vertical_obstacles
            .entry(x)
            .and_modify(|e| {
                e.push(y);
            })
            .or_insert(vec![y]);
    }

    for (_, val) in horizon_obstacles.iter_mut() {
        val.sort();
    }

    for (_, val) in vertical_obstacles.iter_mut() {
        val.sort();
    }

    // println!("{:?} {:?}", horizon_obstacles, vertical_obstacles);

    let mut ans = 0;

    for c in commands.iter() {
        // println!("{:?}", cur);
        match c {
            -1 => {
                dir = (dir + 1) % 4;
            }
            -2 => {
                dir = (dir + 3) % 4;
            }
            _ => {
                if dir == 0 /* north */ && vertical_obstacles.contains_key(&cur.0) {
                    let obstacles = vertical_obstacles.get(&cur.0).unwrap();
                    if cur.1 >= *obstacles.last().unwrap() {
                        cur.1 += c;
                    } else {
                        let i = obstacles.partition_point(|&x| x <= cur.1);
                        cur.1 = std::cmp::min(obstacles[i] - 1, cur.1 + c);
                    }
                } else if dir == 2 /* south */ && vertical_obstacles.contains_key(&cur.0) {
                    let obstacles = vertical_obstacles.get(&cur.0).unwrap();
                    if cur.1 <= *obstacles.first().unwrap() {
                        cur.1 -= c;
                    } else {
                        let i = obstacles.partition_point(|&x| x < cur.1);
                        cur.1 = std::cmp::max(obstacles[i - 1] + 1, cur.1 - c);
                    }
                } else if dir == 1 /* east */ && horizon_obstacles.contains_key(&cur.1) {
                    let obstacles = horizon_obstacles.get(&cur.1).unwrap();
                    if cur.0 >= *obstacles.last().unwrap() {
                        cur.0 += c;
                    } else {
                        let i = obstacles.partition_point(|&x| x <= cur.0);
                        cur.0 = std::cmp::min(obstacles[i] - 1, cur.0 + c);
                    }
                } else if dir == 3 /* west */ && horizon_obstacles.contains_key(&cur.1) {
                    let obstacles = horizon_obstacles.get(&cur.1).unwrap();
                    if cur.0 <= *obstacles.first().unwrap() {
                        cur.0 -= c;
                    } else {
                        let i = obstacles.partition_point(|&x| x < cur.0);
                        cur.0 = std::cmp::max(obstacles[i - 1] + 1, cur.0 - c);
                    }
                } else {
                    match dir {
                        0 => {
                            cur.1 += c;
                        }
                        1 => {
                            cur.0 += c;
                        }
                        2 => {
                            cur.1 -= c;
                        }
                        3 => {
                            cur.0 -= c;
                        }
                        _ => {
                            panic!();
                        }
                    }
                }
            }
        }

        ans = std::cmp::max(ans, cur.0 * cur.0 + cur.1 * cur.1);
    }

    ans
}

fn main() {
    assert_eq!(robot_sim(vec![4, -1, 3], vec![]), 25);
    assert_eq!(robot_sim(vec![4, -1, 4, -2, 4], vec![vec![2, 4]]), 65);
    assert_eq!(robot_sim(vec![6, -1, -1, 6], vec![]), 36);
    assert_eq!(robot_sim(vec![4, -1, 4, -2, 4], vec![vec![0, 0]]), 80);
    assert_eq!(
        robot_sim(
            vec![-2, 8, 3, 7, -1],
            vec![
                vec![-4, -1],
                vec![1, -1],
                vec![1, 4],
                vec![5, 0],
                vec![4, 5],
                vec![-2, -1],
                vec![2, -5],
                vec![5, 1],
                vec![-3, -1],
                vec![5, -3]
            ]
        ),
        324
    );
    assert_eq!(
        robot_sim(
            vec![2, -1, 8, -1, 6],
            vec![
                vec![1, 5],
                vec![-5, -5],
                vec![0, 4],
                vec![-1, -1],
                vec![4, 5],
                vec![-5, -3],
                vec![-2, 1],
                vec![-2, -5],
                vec![0, 5],
                vec![0, -1]
            ]
        ),
        80
    );
}
