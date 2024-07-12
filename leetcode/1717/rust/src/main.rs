pub fn maximum_gain(s: String, x: i32, y: i32) -> i32 {
    let mut x = x;
    let mut y = y;

    let s = if x > y {
        std::mem::swap(&mut x, &mut y);
        s.chars()
            .into_iter()
            .map(|c| match c {
                'a' => 'b',
                'b' => 'a',
                _ => c,
            })
            .collect()
    } else {
        s
    };

    let mut ans = 0;
    let mut st1 = Vec::new();
    for c in s.chars() {
        if c == 'a' {
            if let Some(t) = st1.last() {
                if *t == 'b' {
                    st1.pop();
                    ans += y;
                    continue;
                }
            }
        }
        st1.push(c);
    }

    let mut st2 = Vec::new();
    for c in st1.into_iter() {
        if c == 'b' {
            if let Some(t) = st2.last() {
                if *t == 'a' {
                    st2.pop();
                    ans += x;
                    continue;
                }
            }
        }
        st2.push(c);
    }

    ans
}

fn main() {
    assert_eq!(
        maximum_gain(
            "aabbabkbbbfvybssbtaobaaaabataaadabbbmakgabbaoapbbbbobaabvqhbbzbbkapabaavbbeghacabamdpaaqbqabbjbababmbakbaabajabasaabbwabrbbaabbafubayaazbbbaababbaaha".to_string(),
            1926,
            4320
        ), 112374);
}
