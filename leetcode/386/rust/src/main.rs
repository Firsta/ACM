pub fn lexical_order(n: i32) -> Vec<i32> {
    fn dfs(n: i32, base: i32, v: &mut Vec<i32>, first: bool) {
        if first {
            for i in 1..=9 {
                let t = base + i;
                if t <= n {
                    v.push(base + i);
                    dfs(n, t * 10, v, false);
                }
            }
        } else {
            for i in 0..=9 {
                let t = base + i;
                if t <= n {
                    v.push(base + i);
                    dfs(n, t * 10, v, false);
                }
            }
        }
    }

    let mut ans = Default::default();
    dfs(n, 0, &mut ans, true);
    ans
}

fn main() {
    assert_eq!(
        lexical_order(13),
        vec![1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]
    );
}
