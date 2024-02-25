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

pub fn can_traverse_all_pairs(nums: Vec<i32>) -> bool {
    if nums.len() == 1 {
        return true;
    }
    let max_val = 100001usize;
    let mut ec = vec![0; max_val];
    for i in 2..max_val {
        if ec[i] == 0 {
            let mut j = i;
            while j < max_val {
                ec[j] = i;
                j += i;
            }
        }
    }

    let mut us = UnionSet::new(max_val);

    for &n in nums.iter() {
        let n = n as usize;
        let mut m = n;
        while m > 1 {
            let f = ec[m];
            // println!("{} {}", n, f);
            us.union(f, n);
            while m % f == 0 {
                m /= f;
            }
        }
    }

    let base = nums[0] as usize;
    for &n in nums.iter() {
        if n == 1 {
            return false;
        } else if !us.same(base, n as usize) {
            return false;
        }
    }

    true
}

fn main() {
    assert_eq!(can_traverse_all_pairs(vec![2, 3, 6]), true);
    assert_eq!(can_traverse_all_pairs(vec![1, 1]), false);
    assert_eq!(can_traverse_all_pairs(vec![1]), true);
    assert_eq!(can_traverse_all_pairs(vec![3, 9, 5]), false);
}
