pub fn repeat_limited_string(s: String, repeat_limit: i32) -> String {
    let mut m = std::collections::HashMap::new();
    for c in s.chars() {
        m.entry(c).and_modify(|e| *e += 1).or_insert(1);
    }
    let mut v: Vec<(char, i32)> = m.into_iter().collect();
    v.sort_by(|a, b| b.0.cmp(&a.0));
    let mut i = 0;
    let mut j = 1;
    let mut ans = String::new();
    // println!("{:?}", v);

    let mut cnt = 0;
    loop {
        ans.push(v[i].0);
        v[i].1 -= 1;
        cnt += 1;
        if v[i].1 == 0 {
            while i < v.len() && v[i].1 == 0 {
                i += 1;
            }
            cnt = 0;
            if i == v.len() {
                break;
            }
            if i == j {
                j += 1;
            }
        } else {
            if cnt == repeat_limit {
                if j < v.len() {
                    ans.push(v[j].0);
                    v[j].1 -= 1;
                    if v[j].1 == 0 {
                        j += 1;
                    }
                    cnt = 0;
                } else {
                    break;
                }
            }
        }

        // println!("{:?}", v);
    }

    ans
}

fn main() {
    assert_eq!(
        repeat_limited_string("cczazcc".to_string(), 3),
        "zzcccac".to_string()
    );
    assert_eq!(
        repeat_limited_string("aababab".to_string(), 2),
        "bbabaa".to_string()
    );
    assert_eq!(
        repeat_limited_string("yxxvvvuusrrqqppopponliihgfeeddcbba".to_string(), 2),
        "yxxvvuvusrrqqppopponliihgfeeddcbba".to_string()
    );
}
