fn ok(n: &i32, quantities: &Vec<i32>, mmax: &i32) -> bool {
    let mut n = *n;
    for q in quantities.iter() {
        n -= q / mmax + if q % mmax == 0 { 0 } else { 1 };
    }
    n >= 0
}

pub fn minimized_maximum(n: i32, quantities: Vec<i32>) -> i32 {
    let mut l = 0;
    let mut r = quantities.iter().max().unwrap().clone();
    while l + 1 < r {
        let m = (l + r) / 2;
        if ok(&n, &quantities, &m) {
            r = m;
        } else {
            l = m;
        }
    }

    r
}

fn main() {
    assert_eq!(minimized_maximum(6, vec![11, 6]), 3);
    assert_eq!(minimized_maximum(7, vec![15, 10, 10]), 5);
    assert_eq!(minimized_maximum(1, vec![100000]), 100000);
    assert_eq!(minimized_maximum(2, vec![5, 7]), 7);
}
