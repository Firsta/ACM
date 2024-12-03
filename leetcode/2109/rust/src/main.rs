pub fn add_spaces(s: String, spaces: Vec<i32>) -> String {
    let mut ans = String::new();
    let mut spi = 0usize;
    for (idx, c) in s.chars().enumerate() {
        if spi < spaces.len() && spaces[spi] as usize == idx {
            ans.push(' ');
            spi += 1;
        }
        ans.push(c);
    }
    ans
}

fn main() {
    assert_eq!(
        add_spaces("LeetcodeHelpsMeLearn".to_string(), vec![8, 13, 15]),
        "Leetcode Helps Me Learn".to_string()
    );
}
