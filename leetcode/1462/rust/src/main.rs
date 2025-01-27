pub fn check_if_prerequisite(
    num_courses: i32,
    prerequisites: Vec<Vec<i32>>,
    queries: Vec<Vec<i32>>,
) -> Vec<bool> {
    let n = num_courses as usize;
    let mut to = vec![vec![false; n]; n];
    for p in prerequisites {
        to[p[0] as usize][p[1] as usize] = true;
    }
    for k in 0..n {
        for i in 0..n {
            for j in 0..n {
                if to[i][k] && to[k][j] {
                    to[i][j] = true;
                }
            }
        }
    }
    queries
        .into_iter()
        .map(|x| to[x[0] as usize][x[1] as usize])
        .collect()
}

fn main() {
    assert_eq!(
        check_if_prerequisite(2, vec![vec![1, 0]], vec![vec![0, 1], vec![1, 0]]),
        vec![false, true]
    );
    assert_eq!(
        check_if_prerequisite(2, Vec::new(), vec![vec![1, 0], vec![0, 1]]),
        vec![false, false]
    );
    assert_eq!(
        check_if_prerequisite(
            3,
            vec![vec![1, 2], vec![1, 0], vec![2, 0]],
            vec![vec![1, 0], vec![1, 2]]
        ),
        vec![true, true]
    );
}
