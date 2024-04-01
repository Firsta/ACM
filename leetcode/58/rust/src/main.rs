pub fn length_of_last_word(s: String) -> i32 {
    let mut i = (s.len() - 1) as i32;
    while (s.as_bytes()[i as usize] as char) == ' ' {
        i -= 1;
    }

    let mut ans = 0;
    while i >= 0 && (s.as_bytes()[i as usize] as char) != ' ' {
        i -= 1;
        ans += 1;
    }

    // println!("{}", i);
    ans
}

fn main() {
    assert_eq!(length_of_last_word("Hello World".to_string()), 5);
    assert_eq!(
        length_of_last_word("   fly me   to   the moon  ".to_string()),
        4
    );
    assert_eq!(length_of_last_word("luffy is still joyboy".to_string()), 6);
}
