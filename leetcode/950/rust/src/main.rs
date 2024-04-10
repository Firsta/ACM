use std::collections::VecDeque;

pub fn deck_revealed_increasing(deck: Vec<i32>) -> Vec<i32> {
    let mut deck = deck;
    deck.sort();

    let mut result = vec![0; deck.len()];
    let mut deq = VecDeque::from((0..deck.len()).collect::<Vec<usize>>());

    let mut idx = 0;
    while !deq.is_empty() {
        result[deq.pop_front().unwrap()] = deck[idx];
        idx += 1;
        if !deq.is_empty() {
            let t = deq.pop_front().unwrap();
            deq.push_back(t);
        }
    }

    result
}

fn main() {
    assert_eq!(
        deck_revealed_increasing(vec![17, 13, 11, 2, 3, 5, 7]),
        vec![2, 13, 3, 11, 5, 17, 7]
    );
    assert_eq!(deck_revealed_increasing(vec![1, 1000]), vec![1, 1000]);
}
