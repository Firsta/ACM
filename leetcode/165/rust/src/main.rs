pub fn compare_version(version1: String, version2: String) -> i32 {
    let mut p1: Vec<i32> = version1
        .split(".")
        .map(|s| s.parse::<i32>().unwrap())
        .collect();
    let mut p2: Vec<i32> = version2
        .split(".")
        .map(|s| s.parse::<i32>().unwrap())
        .collect();

    while p1.len() > p2.len() {
        p2.push(0);
    }

    while p1.len() < p2.len() {
        p1.push(0);
    }

    for i in 0..std::cmp::min(p1.len(), p2.len()) {
        if p1[i] != p2[i] {
            return if p1[i] < p2[i] {
                -1
            } else if p1[i] > p2[i] {
                1
            } else {
                0
            };
        }
    }

    0
}

fn main() {
    assert_eq!(compare_version("1.01".to_string(), "1.001".to_string()), 0);
    assert_eq!(compare_version("1.0".to_string(), "1.0.0".to_string()), 0);
    assert_eq!(compare_version("0.1".to_string(), "1.1".to_string()), -1);
}
