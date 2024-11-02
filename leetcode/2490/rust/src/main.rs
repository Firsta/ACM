pub fn is_circular_sentence(sentence: String) -> bool {
    let words: Vec<Vec<char>> = sentence.split(" ").map(|x| x.chars().collect()).collect();
    let n = words.len();

    // println!("{:?}, {}", words, n);

    if words[0][0] != words[n - 1][words[n - 1].len() - 1] {
        false
    } else {
        for i in 1..n {
            if words[i][0] != words[i - 1][words[i - 1].len() - 1] {
                return false;
            }
        }

        true
    }
}

fn main() {
    assert_eq!(is_circular_sentence("eetcode".to_string()), true);
}
