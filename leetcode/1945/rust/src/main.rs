pub fn get_lucky(s: String, k: i32) -> i32 {
    let mut d = Vec::new();
    for c in s.chars() {
        let n = c as i32 - 'a' as i32 + 1;
        if n >= 10 {
            d.push(n / 10);
            d.push(n % 10);
        } else {
            d.push(n);
        }
    }
    for i in 0..k {
        let mut s = d.iter().sum();

        if i == k - 1 {
            return s;
        }
        let mut nd = Vec::new();
        while s > 0 {
            nd.push(s % 10);
            s /= 10;
        }
        // println!("{:?} {:?} {:?}", s, d, nd);

        nd.reverse();
        d = nd;
    }

    0
}
fn main() {
    assert_eq!(get_lucky("leetcode".to_string(), 2), 6);
}
