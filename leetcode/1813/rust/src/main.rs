pub fn are_sentences_similar(sentence1: String, sentence2: String) -> bool {
    let s1: Vec<&str> = sentence1.split(" ").collect();
    let s2: Vec<&str> = sentence2.split(" ").collect();

    fn foo(short: Vec<&str>, long: Vec<&str>) -> bool {
        let mut i = 0;
        while i < short.len() && short[i] == long[i] {
            i += 1;
        }
        if i == short.len() {
            return true;
        }

        let mut j = 0;
        while j < short.len() && short[short.len() - 1 - j] == long[long.len() - 1 - j] {
            j += 1;
        }

        // println!("{} {}", i, j);
        i + j >= short.len()
    }
    if s1.len() > s2.len() {
        foo(s2, s1)
    } else {
        foo(s1, s2)
    }
}

fn main() {
    assert_eq!(
        are_sentences_similar("A A AAa".to_string(), "A AAa".to_string()),
        true
    );
}
