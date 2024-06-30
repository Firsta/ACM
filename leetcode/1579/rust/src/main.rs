#[derive(Clone, Debug)]
struct UnionSet {
    p: Vec<usize>,
}

impl UnionSet {
    fn new(n: usize) -> UnionSet {
        let mut v = vec![0usize; n];
        for i in 0..n {
            v[i] = i;
        }
        UnionSet { p: v }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.p[x] == x {
            x
        } else {
            self.p[x] = self.find(self.p[x]);
            self.p[x]
        }
    }

    fn union(&mut self, x: usize, y: usize) {
        let px = self.find(x);
        let py = self.find(y);

        self.p[px] = py;
    }

    fn same(&mut self, x: usize, y: usize) -> bool {
        self.find(x) == self.find(y)
    }

    fn all_same(&mut self) -> bool {
        for i in 1..self.p.len() {
            if !self.same(0, i) {
                return false;
            }
        }
        true
    }
}

pub fn max_num_edges_to_remove(n: i32, edges: Vec<Vec<i32>>) -> i32 {
    let mut edge_count = 0;

    let n = n as usize;

    let mut type_3_s = UnionSet::new(n);
    for e in edges.iter() {
        if e[0] == 3 {
            let from = (e[1] - 1) as usize;
            let to = (e[2] - 1) as usize;

            if !type_3_s.same(from, to) {
                type_3_s.union(from, to);
                edge_count += 1;
            }
        }
    }
    // println!("{:?}", type_3_s);

    let mut type_1_s = type_3_s.clone();
    for e in edges.iter() {
        if e[0] == 1 {
            let from = (e[1] - 1) as usize;
            let to = (e[2] - 1) as usize;

            if !type_1_s.same(from, to) {
                type_1_s.union(from, to);
                edge_count += 1;
            }
        }
    }
    // println!("{:?}", type_1_s);

    let mut type_2_s = type_3_s.clone();
    for e in edges.iter() {
        if e[0] == 2 {
            let from = (e[1] - 1) as usize;
            let to = (e[2] - 1) as usize;

            if !type_2_s.same(from, to) {
                type_2_s.union(from, to);
                edge_count += 1;
            }
        }
    }

    if !type_1_s.all_same() || !type_2_s.all_same() {
        -1
    } else {
        (edges.len() - edge_count) as i32
    }
}

fn main() {
    assert_eq!(
        max_num_edges_to_remove(
            4,
            vec![
                vec![3, 1, 2],
                vec![3, 2, 3],
                vec![1, 1, 3],
                vec![1, 2, 4],
                vec![1, 1, 2],
                vec![2, 3, 4]
            ]
        ),
        2
    );
    assert_eq!(
        max_num_edges_to_remove(4, vec![vec![3, 2, 3], vec![1, 1, 2], vec![2, 3, 4]]),
        -1
    );
    assert_eq!(
        max_num_edges_to_remove(
            4,
            vec![vec![3, 1, 2], vec![3, 3, 4], vec![1, 1, 3], vec![2, 2, 4]]
        ),
        0
    );
}
