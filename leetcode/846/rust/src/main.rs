use std::collections::HashMap;

pub fn is_n_straight_hand(hand: Vec<i32>, group_size: i32) -> bool {
    if hand.len() % (group_size as usize) != 0 {
        return false;
    }

    let mut m = HashMap::new();
    for &h in hand.iter() {
        m.entry(h).and_modify(|e| *e += 1).or_insert(1);
    }

    for h in hand.into_iter() {
        let mut start = h;
        while m.get(&(start - 1)).is_some() {
            start -= 1;
        }

        while start <= h {
            while m.get(&start).is_some() {
                for i in start..start + group_size {
                    let mut delete = false;
                    match m.get_mut(&i) {
                        None => {
                            return false;
                        }
                        Some(cnt) => {
                            if *cnt == 1 {
                                delete = true;
                            } else {
                                *cnt -= 1;
                            }
                        }
                    }
                    if delete {
                        m.remove(&i);
                    }
                }
            }
            start += 1;
        }
    }

    true
}

fn main() {
    assert_eq!(is_n_straight_hand(vec![1, 2, 3, 6, 2, 3, 4, 7, 8], 3), true);
    assert_eq!(is_n_straight_hand(vec![1, 2, 3, 4, 5], 4), false);
}
