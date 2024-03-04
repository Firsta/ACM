pub fn bag_of_tokens_score(tokens: Vec<i32>, power: i32) -> i32 {
    let n = tokens.len();

    let mut tokens = tokens;
    tokens.sort();

    let mut i = 0;
    let mut j = n;

    let mut power = power;

    let mut answer = 0;
    let mut score = 0;
    while i < j {
        let mut c = false;
        while i < j && tokens[i] <= power {
            power -= tokens[i];
            score += 1;
            i += 1;
            c = true;
        }

        if !c {
            break;
        }

        answer = std::cmp::max(answer, score);

        if j > i + 1 && score > 0 {
            score -= 1;
            power += tokens[j - 1];
            j -= 1;
        }
    }

    answer
}

fn main() {
    assert_eq!(bag_of_tokens_score(vec![100], 50), 0);
    assert_eq!(bag_of_tokens_score(vec![200, 100], 150), 1);
    assert_eq!(bag_of_tokens_score(vec![100, 200, 300, 400], 200), 2);
    assert_eq!(bag_of_tokens_score(vec![33, 4, 28, 24, 96], 35), 3);
}
