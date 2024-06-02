pub fn reverse_string(s: &mut Vec<char>) {
    s.reverse();
}
fn main() {
    let mut s = vec!['h', 'e', 'l', 'l', 'o'];
    reverse_string(&mut s);
    assert_eq!(s, vec!['o', 'l', 'l', 'e', 'h']);
}
