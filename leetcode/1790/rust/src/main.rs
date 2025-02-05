pub fn are_almost_equal(s1: String, s2: String) -> bool {
    if s1 == s2 {
        return true;
    }
    let mut diff1 = Vec::new();
    let mut diff2 = Vec::new();

    for idx in 0..s1.len() {
        let c1 = s1.as_bytes()[idx] as char;
        let c2 = s2.as_bytes()[idx] as char;
        if c1 != c2 {
            if diff1.len() == 2 {
                return false;
            }
            diff1.push(c1);
            diff2.push(c2);
        }
    }
    if diff1.len() != 2 {
        return false;
    }
    diff1[0] == diff2[1] && diff1[1] == diff2[0]
}

fn main() {
    assert_eq!(
        are_almost_equal("bank".to_string(), "kanb".to_string()),
        true
    );
}
