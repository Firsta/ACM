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

    fn clear(&mut self, x: usize) {
        self.p[x] = x;
    }
}

pub fn find_all_people(n: i32, meetings: Vec<Vec<i32>>, first_person: i32) -> Vec<i32> {
    let mut meetings = meetings.clone();
    meetings.sort_by(|a, b| a[2].cmp(&b[2]));

    let mut i = 0;

    let n = n as usize;
    let f = first_person as usize;

    let m = meetings.len();

    let mut us = UnionSet::new(n);
    us.union(0, f);

    while i < m {
        let mut j = i;

        while j < m && meetings[j][2] == meetings[i][2] {
            us.union(meetings[j][0] as usize, meetings[j][1] as usize);

            j += 1;
        }

        for k in i..j {
            let a = meetings[k][0] as usize;
            let b = meetings[k][1] as usize;

            if !us.same(a, 0) {
                us.clear(a);
                us.clear(b);
            }
        }

        i = j;
    }

    let mut result = Vec::new();

    for i in 0..n {
        if us.same(0, i) {
            result.push(i as i32);
        }
    }

    result
}

fn main() {
    assert_eq!(
        find_all_people(6, vec![vec![1, 2, 5], vec![2, 3, 8], vec![1, 5, 10]], 1),
        vec![0, 1, 2, 3, 5],
    );
}
