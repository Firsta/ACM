pub fn find_center(edges: Vec<Vec<i32>>) -> i32 {
    let mina = std::cmp::min(edges[0][0], edges[0][1]);
    let minb = std::cmp::min(edges[1][0], edges[1][1]);

    if mina == minb {
        mina
    } else {
        edges[0][0] + edges[0][1] - mina
    }
}

fn main() {
    assert_eq!(find_center(vec![vec![1, 2], vec![2, 3], vec![4, 2]]), 2);
}
