fn ok(p: &Vec<i32>, m: i32, mid: i32) -> bool {
    let mut last = p[0];
    let mut put = 1;

    for i in 1..p.len() {
        if p[i] - last >= mid {
            put += 1;
            last = p[i];
            if put >= m {
                return true;
            }
        }
    }

    false
}

pub fn max_distance(position: Vec<i32>, m: i32) -> i32 {
    let mut position = position;
    position.sort();

    let n = position.len();

    let mut l = 0;
    let mut r = position[n - 1] - position[0] + 1;

    while r - l > 1 {
        let mid = (r - l) / 2 + l;
        if ok(&position, m, mid) {
            l = mid;
        } else {
            r = mid;
        }
    }

    l
}

fn main() {
    assert_eq!(max_distance(vec![1, 2, 3, 4, 7], 3), 3);
    assert_eq!(max_distance(vec![5, 4, 3, 2, 1, 1000000000], 2), 999999999);
}
