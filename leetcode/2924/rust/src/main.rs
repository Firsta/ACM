pub fn find_champion(n: i32, edges: Vec<Vec<i32>>) -> i32 {
    let n = n as usize;
    let mut v = vec![0; n];
    for e in edges {
        v[e[1] as usize] += 1;
    }
    if v.iter().filter(|x| **x == 0).count() > 1 {
        -1
    } else {
        v.iter().enumerate().find(|x| *x.1 == 0).unwrap().0 as i32
    }
}

fn main() {
    assert_eq!(find_champion(3, vec![vec![0, 1], vec![1, 2]]), 0);
    assert_eq!(
        find_champion(4, vec![vec![0, 2], vec![1, 3], vec![1, 2]]),
        -1
    );
}
