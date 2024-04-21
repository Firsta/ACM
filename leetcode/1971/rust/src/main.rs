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
}

struct Solution;

impl Solution {
    pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool {
        let mut us = UnionSet::new(n as usize);

        for edge in edges.iter() {
            us.union(edge[0] as usize, edge[1] as usize);
        }

        us.find(source as usize) == us.find(destination as usize)
    }
}

fn main() {
    assert_eq!(
        Solution::valid_path(
            6,
            vec![vec![0, 1], vec![0, 2], vec![3, 5], vec![5, 4], vec![4, 3]],
            0,
            5
        ),
        false
    );
}
