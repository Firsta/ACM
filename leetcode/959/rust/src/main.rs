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

pub fn regions_by_slashes(grid: Vec<String>) -> i32 {
    let n = grid.len();

    let mut u = UnionSet::new(n * 2 * n);

    for i in 0..n {
        for j in 0..n - 1 {
            let c1 = grid[i].as_bytes()[j] as char;
            let g1_l = i * 2 * n + j;
            let g1_r = i * 2 * n + n + j;
            if c1 == ' ' {
                u.union(g1_l, g1_r);
            }

            let c2 = grid[i].as_bytes()[j + 1] as char;
            let g2_l = i * 2 * n + j + 1;
            let g2_r = i * 2 * n + n + j + 1;
            if c2 == ' ' {
                u.union(g2_l, g2_r);
            }

            u.union(g1_r, g2_l);
        }
    }
    for j in 0..n {
        for i in 0..n - 1 {
            let c1 = grid[i].as_bytes()[j] as char;
            let g1_l = i * 2 * n + j;
            let g1_r = i * 2 * n + n + j;

            let c2 = grid[i + 1].as_bytes()[j] as char;
            let g2_l = (i + 1) * 2 * n + j;
            let g2_r = (i + 1) * 2 * n + n + j;

            match (c1, c2) {
                ('/', '/') => u.union(g1_r, g2_l),
                ('/', '\\') => u.union(g1_r, g2_r),
                ('/', ' ') => u.union(g1_r, g2_r),
                ('\\', '/') => u.union(g1_l, g2_l),
                ('\\', '\\') => u.union(g1_l, g2_r),
                ('\\', ' ') => u.union(g1_l, g2_r),
                (' ', '/') => u.union(g1_l, g2_l),
                (' ', '\\') => u.union(g1_r, g2_r),
                (' ', ' ') => u.union(g1_l, g2_r),
                _ => panic!(),
            };
        }
    }

    (0..n * 2 * n)
        .map(|x| u.find(x))
        .collect::<std::collections::HashSet<usize>>()
        .len() as i32
}
fn main() {
    assert_eq!(
        regions_by_slashes(vec!["/\\".to_string(), "\\/".to_string()]),
        5
    );
}
