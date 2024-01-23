pub fn max_length(arr: Vec<String>) -> i32 {
    let mut bs = Vec::new();
    let mut can = Vec::new();
    for s in arr.iter() {
        let mut b = 0;
        let mut ok = true;
        for c in s.chars() {
            let n = c as u8 - 'a' as u8;
            if b & (1 << n) > 0 {
                ok = false;
                break;
            }
            b |= 1 << n;
        }
        if ok {
            can.push(s);
            bs.push(b);
        }
    }
    // println!("{:?}", bs);
    let mut result = 0i32;
    let n = 2u32.pow(can.len() as u32);
    for i in 0..n {
        let mut w = 0;
        let mut k = 0;
        let mut l = 0;
        let mut ok = true;
        let mut c = i;
        while c > 0 {
            if c % 2 == 1 {
                // choose can k
                if w & bs[k] > 0 {
                    ok = false;
                    break;
                } else {
                    w |= bs[k];
                    l += can[k].len() as i32;
                }
            }
            c /= 2;
            k += 1;
        }
        if ok {
            // println!("{}", i);
            result = std::cmp::max(result, l);
        }
    }
    result
}

fn main() {
    println!(
        "{}",
        max_length(vec!["un".to_string(), "iq".to_string(), "ue".to_string()])
    );
}
