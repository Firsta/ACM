pub fn frequency_sort(s: String) -> String {
    let mut v = Vec::new();
    for i in 0..256usize {
        v.push((i, 0usize));
    }
    for c in s.chars() {
        let i = c as usize - '0' as usize;
        v[i].1 += 1;
    }

    v.sort_by(|a, b| b.1.cmp(&a.1));
    let v: Vec<&(usize, usize)> = v.iter().filter(|&x| x.1 > 0).collect();
    let mut result = String::new();
    for t in v.iter() {
        let c = ('0' as u8 + t.0 as u8) as char;
        result.push_str(&c.to_string().repeat(t.1));
    }
    result
}

fn main() {
    println!("{}", frequency_sort("tree".to_string()));
}
