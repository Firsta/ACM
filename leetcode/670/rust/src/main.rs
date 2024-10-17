pub fn maximum_swap(num: i32) -> i32 {
    let mut d1 = Vec::new();
    let mut num = num;
    while num > 0 {
        d1.push(num % 10);
        num /= 10;
    }
    d1.reverse();

    let mut d2 = d1.clone();
    d2.sort_by(|a, b| b.cmp(&a));

    for i in 0..d1.len() {
        if d1[i] != d2[i] {
            let mut dst = 0;
            let mut m = -1;
            for j in i + 1..d1.len() {
                if d1[j] >= m {
                    m = d1[j];
                    dst = j;
                }
            }
            let t = d1[i];
            d1[i] = d1[dst];
            d1[dst] = t;

            break;
        }
    }

    let mut ans = 0;
    for i in 0..d1.len() {
        ans = ans * 10 + d1[i];
    }
    return ans;
}

fn main() {
    assert_eq!(maximum_swap(98368), 98863);
}
