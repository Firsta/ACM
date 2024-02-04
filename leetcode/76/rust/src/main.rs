use std::collections::hash_map::Entry;
use std::collections::HashMap;
use std::collections::HashSet;

pub fn min_window(s: String, t: String) -> String {
    let mut tm = HashMap::new();
    let mut ts = HashSet::new();

    for c in t.chars() {
        tm.entry(c).and_modify(|e| *e += 1).or_insert(1);
        ts.insert(c);
    }

    // println!("{:?} {:?}", tm, ts);

    let mut i = 0;
    let mut j = 0;

    let mut r = None;

    let mut sm = HashMap::new();

    loop {
        while j < s.len() && !tm.is_empty() {
            let c = s.as_bytes()[j] as char;

            if let Entry::Occupied(mut o) = tm.entry(c) {
                let m = o.get_mut();
                if *m == 1 {
                    o.remove_entry();
                } else {
                    *m -= 1;
                }
            } else if ts.contains(&c) {
                sm.entry(c).and_modify(|e| *e += 1).or_insert(1);
            }

            j += 1;
        }

        // println!("{:?} {:?}", tm, sm);

        if !tm.is_empty() {
            break;
        }

        while i < j && tm.is_empty() {
            let c = s.as_bytes()[i] as char;

            if let Entry::Occupied(mut o) = sm.entry(c) {
                let m = o.get_mut();
                if *m == 1 {
                    o.remove_entry();
                } else {
                    *m -= 1;
                }
            } else if ts.contains(&c) {
                tm.entry(c).and_modify(|e| *e += 1).or_insert(1);
            }

            // println!("{:?} {:?} {:?}", tm, sm, ts);

            i += 1;
        }

        // println!("{} {}", i, j);

        match r {
            None => {
                r = Some((i, j));
            }
            Some(rv) => {
                if rv.1 - rv.0 > j - i {
                    r = Some((i, j));
                }
            }
        }

        if j >= s.len() {
            break;
        }
    }

    match r {
        None => "".to_string(),
        Some((i, j)) => (&s[i - 1..j]).to_string(),
    }
}

fn main() {
    println!(
        "{}",
        min_window("ADOBECODEBANC".to_string(), "ABC".to_string())
    );
}
