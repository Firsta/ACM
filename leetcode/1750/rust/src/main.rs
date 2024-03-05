pub fn minimum_length(s: String) -> i32 {
    let n = s.len();

    let mut i = 0;
    let mut j = n - 1;

    while i < j {
        let a = s.as_bytes()[i];
        let b = s.as_bytes()[j];

        if a != b {
            break;
        }

        let c = s.as_bytes()[i];

        while s.as_bytes()[i] == c && i < j {
            i += 1;
        }

        while s.as_bytes()[j] == c && i <= j {
            j -= 1;
        }
    }

    (j + 1 - i) as i32
}

fn main() {
    assert_eq!(minimum_length("ca".to_string()), 2);
    assert_eq!(minimum_length("cabaabac".to_string()), 0);
    assert_eq!(minimum_length("aabccabba".to_string()), 3);
    assert_eq!(minimum_length("a".to_string()), 1);
    assert_eq!(minimum_length("aa".to_string()), 0);
}
