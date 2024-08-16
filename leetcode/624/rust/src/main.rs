pub fn max_distance(arrays: Vec<Vec<i32>>) -> i32 {
    let mut min_num = None;
    let mut second_min_num = None;

    for (i, a) in arrays.iter().enumerate() {
        match min_num {
            None => {
                min_num = Some((i, a[0]));
            }
            Some(m) => {
                if a[0] <= m.1 {
                    second_min_num = min_num.clone();
                    min_num = Some((i, a[0]));
                } else {
                    match second_min_num {
                        None => {
                            second_min_num = Some((i, a[0]));
                        }
                        Some(m) => {
                            if a[0] < m.1 {
                                second_min_num = Some((i, a[0]));
                            }
                        }
                    }
                }
            }
        }
    }

    let mut ans = std::i32::MIN;
    for (i, a) in arrays.iter().enumerate() {
        if i == min_num.unwrap().0 {
            ans = std::cmp::max(ans, a.last().unwrap() - second_min_num.unwrap().1);
        } else {
            ans = std::cmp::max(ans, a.last().unwrap() - min_num.unwrap().1);
        }
    }

    // println!("{:?} {:?}", min_num, second_min_num);

    ans
}

fn main() {
    assert_eq!(
        max_distance(vec![vec![1, 2, 3], vec![4, 5], vec![1, 2, 3]]),
        4
    );
    assert_eq!(max_distance(vec![vec![1], vec![1]]), 0);
}
