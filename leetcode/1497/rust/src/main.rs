use std::collections::HashMap;

pub fn can_arrange(arr: Vec<i32>, k: i32) -> bool {
    let mut m = HashMap::new();
    for a in arr.into_iter() {
        let r = if a < 0 {
            ((-a / k + 1) * k + a) % k
        } else {
            a % k
        };

        m.entry(r).and_modify(|e| *e += 1).or_insert(1);
    }

    // println!("{:?}", m);
    for (&kk, &vv) in m.iter() {
        let r = (k - kk) % k;
        if r == kk {
            if vv % 2 != 0 {
                return false;
            }
        } else {
            match m.get(&r) {
                None => return false,
                Some(x) => {
                    if *x != vv {
                        return false;
                    }
                }
            }
        }
    }

    true
}
fn main() {
    assert_eq!(can_arrange(vec![1, 2, 3, 4, 5, 10, 6, 7, 8, 9], 5), true);
    assert_eq!(can_arrange(vec![1, 2, 3, 4, 5, 6], 7), true);
    assert_eq!(can_arrange(vec![1, 2, 3, 4, 5, 6], 10), false);
    assert_eq!(can_arrange(vec![-1, 1, -2, 2, -3, 3, -4, 4], 3), true);
}
