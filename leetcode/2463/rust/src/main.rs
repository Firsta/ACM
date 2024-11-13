pub fn minimum_total_distance(robot: Vec<i32>, factory: Vec<Vec<i32>>) -> i64 {
    let mut robot: Vec<i64> = robot.into_iter().map(|x| x as i64).collect();
    robot.sort();
    let mut factory: Vec<i64> = factory
        .into_iter()
        .map(|x| {
            let mut v = Vec::new();
            for _ in 0..x[1] {
                v.push(x[0] as i64);
            }
            v
        })
        .flatten()
        .collect();
    factory.sort();

    let mut dp = vec![vec![None; factory.len()]; robot.len()];

    fn foo(
        ri: usize,
        fi: usize,
        robot: &Vec<i64>,
        factory: &Vec<i64>,
        dp: &mut Vec<Vec<Option<Option<i64>>>>,
    ) -> Option<i64> {
        let r = if ri >= robot.len() {
            Some(0)
        } else if fi >= factory.len() {
            None
        } else {
            if let Some(r) = dp[ri][fi] {
                r
            } else {
                let r = {
                    let a = foo(ri + 1, fi + 1, robot, factory, dp);
                    let b = foo(ri, fi + 1, robot, factory, dp);
                    match a {
                        Some(a) => match b {
                            None => Some(a + (robot[ri] - factory[fi]).abs()),
                            Some(b) => Some(std::cmp::min(a + (robot[ri] - factory[fi]).abs(), b)),
                        },
                        None => match b {
                            None => None,
                            Some(b) => Some(b),
                        },
                    }
                };
                dp[ri][fi] = Some(r);
                r
            }
        };

        // println!("{} {} {:?}", ri, fi, r);

        r
    }

    foo(0, 0, &robot, &factory, &mut dp).unwrap()
}

fn main() {
    assert_eq!(
        minimum_total_distance(vec![1, -1], vec![vec![-2, 1], vec![2, 1]]),
        2
    );
}
