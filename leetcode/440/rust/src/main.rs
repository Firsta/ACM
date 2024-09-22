pub fn find_kth_number_0(n: i32, k: i32) -> i32 {
    fn dfs(n: i32, cur: Option<i32>, k: &mut i32) -> Option<i32> {
        match cur {
            None => {
                for i in 1..=9 {
                    let r = dfs(n, Some(i), k);
                    if r.is_some() {
                        return r;
                    }
                }
                None
            }
            Some(cur) => {
                if cur > n {
                    None
                } else {
                    if *k == 1 {
                        Some(cur)
                    } else {
                        *k -= 1;
                        for i in 0..=9 {
                            let r = dfs(n, Some(cur * 10 + i), k);
                            if r.is_some() {
                                return r;
                            }
                        }
                        None
                    }
                }
            }
        }
    }

    let mut k = k;
    dfs(n, None, &mut k).unwrap()
}

fn decimal_len(n: i32) -> i32 {
    let mut d = 1;
    let mut t = 0;
    while n / d > 0 {
        d *= 10;
        t += 1
    }
    t
}

fn l_count(l: i32) -> i32 {
    let mut ans = 0;
    let mut d = 1;
    for _ in 0..l {
        ans += d;
        d *= 10;
    }
    ans
}

fn prefix(n: i32, l: i32) -> i32 {
    let delta = decimal_len(n) - l;
    let mut n = n;
    for _ in 0..delta {
        n /= 10;
    }
    n
}

pub fn find_kth_number(n: i32, k: i32) -> i32 {
    fn dfs(n: i32, cur: i32, k: &mut i32) -> i32 {
        // println!("dfs: {} {} {}", n, cur, *k);

        if cur != 0 {
            if *k == 1 {
                return cur;
            }
            *k -= 1;
        }
        let l = if cur == 0 { 1 } else { 0 };

        for i in l..=9 {
            let next_cur = cur * 10 + i;
            let n_prefix = prefix(n, decimal_len(next_cur));
            // println!("next_cur: {}, n_prefix: {}", next_cur, n_prefix);
            let delta = decimal_len(n) - decimal_len(next_cur);
            if delta == 0 {
                if next_cur == n {
                    return next_cur;
                }
            }
            if next_cur < n_prefix {
                let subtree_size = l_count(delta + 1);
                if subtree_size >= *k {
                    return dfs(n, next_cur, k);
                } else {
                    *k -= subtree_size;
                }
            } else if next_cur == n_prefix {
                let subtree_size = l_count(delta) + (n % (10_i32.pow(delta as u32))) + 1;
                /* if next_cur == 1 {
                    println!(
                        "subtree_size: {}, delta: {}, {}, {} {} {}",
                        subtree_size,
                        delta,
                        10_i32.pow(delta as u32),
                        l_count(delta),
                        n % 10_i32.pow(delta as u32),
                        l_count(delta) + n % 10_i32.pow(delta as u32)
                    );
                } */
                if subtree_size >= *k {
                    return dfs(n, next_cur, k);
                } else {
                    *k -= subtree_size;
                }
            } else {
                let subtree_size = l_count(delta);
                if subtree_size >= *k {
                    return dfs(n, next_cur, k);
                } else {
                    *k -= subtree_size;
                }
            }
        }
        panic!()
    }

    let mut k = k;
    dfs(n, 0, &mut k)
}

fn main() {
    assert_eq!(decimal_len(100), 3);
    assert_eq!(l_count(1), 1);
    assert_eq!(prefix(13, 1), 1);
    assert_eq!(prefix(130, 2), 13);

    assert_eq!(find_kth_number(13, 2), 10);
    assert_eq!(find_kth_number(1, 1), 1);

    println!("expected: {}", find_kth_number_0(1234, 777));
    assert_eq!(find_kth_number(1234, 777), find_kth_number_0(1234, 777));
}
