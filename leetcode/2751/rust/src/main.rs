#[derive(Debug)]
struct Robot {
    position: i32,
    health: i32,
    direction: char,
    i_x: usize,
}

pub fn survived_robots_healths(
    positions: Vec<i32>,
    healths: Vec<i32>,
    directions: String,
) -> Vec<i32> {
    let mut robots = Vec::new();

    let n = positions.len();
    for i in 0..n {
        robots.push(Robot {
            position: positions[i],
            health: healths[i],
            direction: directions.as_bytes()[i] as char,
            i_x: i,
        })
    }
    robots.sort_by(|a, b| a.position.cmp(&b.position));

    let mut st: Vec<Robot> = Vec::new();
    for r in robots.into_iter() {
        let mut cur = Some(r);

        loop {
            let pop = st.last().is_some()
                && cur.is_some()
                && cur.as_ref().unwrap().direction == 'L'
                && st.last().unwrap().direction == 'R';
            if pop {
                let top = st.pop().unwrap();
                let curr = cur.unwrap();

                use std::cmp::Ordering::*;
                cur = match top.health.cmp(&curr.health) {
                    Greater => Some(Robot {
                        health: top.health - 1,
                        ..top
                    }),
                    Less => Some(Robot {
                        health: curr.health - 1,
                        ..curr
                    }),
                    Equal => None,
                }
            }

            if !pop || cur.is_none() {
                break;
            }
        }

        if let Some(cur) = cur {
            st.push(cur);
        }
    }

    st.sort_by(|a, b| a.i_x.cmp(&b.i_x));
    st.into_iter().map(|x| x.health).collect()
}

fn main() {
    assert_eq!(
        survived_robots_healths(
            vec![5, 4, 3, 2, 1],
            vec![2, 17, 9, 15, 10],
            "RRRRR".to_string()
        ),
        vec![2, 17, 9, 15, 10]
    );
    assert_eq!(
        survived_robots_healths(vec![3, 5, 2, 6], vec![10, 10, 15, 12], "RLRL".to_string()),
        vec![14]
    );
    assert_eq!(
        survived_robots_healths(vec![1, 2, 5, 6], vec![10, 10, 11, 11], "RLRL".to_string()),
        vec![]
    );
}
