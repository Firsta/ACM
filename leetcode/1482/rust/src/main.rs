use std::vec;

fn ok(bloom_day: &Vec<i32>, mid: i32, m: i32, k: i32) -> bool {
    let mut con = 0;
    let mut bouquet = 0;

    for &d in bloom_day.iter() {
        if d <= mid {
            con += 1;
            if con == k {
                bouquet += 1;
                con = 0;
            }
        } else {
            con = 0;
        }
    }

    bouquet >= m
}

pub fn min_days(bloom_day: Vec<i32>, m: i32, k: i32) -> i32 {
    let n = bloom_day.len();

    if m * k > n as i32 {
        return -1;
    }

    let mut l = 0;
    let mut r = bloom_day.iter().max().unwrap().clone();
    while r - l > 1 {
        let mid = (l + r) / 2;
        // println!("{} {} {}", l, r, mid);

        if ok(&bloom_day, mid, m, k) {
            // println!("{}", mid);
            r = mid;
        } else {
            l = mid;
        }
    }

    if ok(&bloom_day, r, m, k) {
        r
    } else {
        -1
    }
}

fn main() {
    assert_eq!(min_days(vec![7, 7, 7, 7, 12, 7, 7], 2, 3), 12);
}
