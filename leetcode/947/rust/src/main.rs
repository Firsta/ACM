#[derive(Clone, Debug)]
struct UnionSet {
    p: Vec<i32>,
    c: usize,
}

impl UnionSet {
    fn new(n: usize) -> UnionSet {
        let mut p = vec![0; n];
        for i in 0..n {
            p[i] = -1;
        }
        UnionSet { p, c: 0 }
    }

    fn find(&mut self, x: i32) -> i32 {
        if self.p[x as usize] == -1 {
            self.c += 1;
            self.p[x as usize] = x;
            x
        } else if self.p[x as usize] == x {
            x
        } else {
            self.p[x as usize] = self.find(self.p[x as usize]);
            self.p[x as usize]
        }
    }

    fn union(&mut self, x: i32, y: i32) {
        let px = self.find(x);
        let py = self.find(y);

        if px != py {
            self.p[px as usize] = py;
            self.c -= 1;
        }
    }
}

pub fn remove_stones(stones: Vec<Vec<i32>>) -> i32 {
    let mut us = UnionSet::new(20010);
    let n = stones.len();
    for s in stones {
        us.union(s[0], s[1] + 10001);
        // println!("{}", us.c);
    }
    (n - us.c) as i32
}

fn main() {
    assert_eq!(
        remove_stones(vec![
            vec![5, 9],
            vec![9, 0],
            vec![0, 0],
            vec![7, 0],
            vec![4, 3],
            vec![8, 5],
            vec![5, 8],
            vec![1, 1],
            vec![0, 6],
            vec![7, 5],
            vec![1, 6],
            vec![1, 9],
            vec![9, 4],
            vec![2, 8],
            vec![1, 3],
            vec![4, 2],
            vec![2, 5],
            vec![4, 1],
            vec![0, 2],
            vec![6, 5]
        ]),
        19
    );
    assert_eq!(
        remove_stones(vec![
            vec![3, 2],
            vec![3, 1],
            vec![4, 4],
            vec![1, 1],
            vec![0, 2],
            vec![4, 0]
        ]),
        4
    );
    assert_eq!(
        remove_stones(vec![
            vec![0, 0],
            vec![0, 1],
            vec![1, 0],
            vec![1, 2],
            vec![2, 1],
            vec![2, 2]
        ]),
        5
    );
    assert_eq!(
        remove_stones(vec![
            vec![0, 0],
            vec![0, 2],
            vec![1, 1],
            vec![2, 0],
            vec![2, 2]
        ]),
        3
    );
    assert_eq!(remove_stones(vec![vec![0, 0]]), 0);
}
