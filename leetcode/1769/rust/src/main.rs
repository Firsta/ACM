pub fn min_operations(boxes: String) -> Vec<i32> {
    let mut boxes: Vec<char> = boxes.chars().collect();

    let mut dp1 = vec![0; boxes.len()];
    let mut one_cnt = 0;
    for i in 0..boxes.len() {
        if i >= 1 {
            dp1[i] = one_cnt + dp1[i - 1];
        }
        if boxes[i] == '1' {
            one_cnt += 1
        }
    }
    boxes.reverse();

    // println!("{dp1:?}");

    let mut dp2 = vec![0; boxes.len()];
    one_cnt = 0;
    for i in 0..boxes.len() {
        if i >= 1 {
            dp2[i] = one_cnt + dp2[i - 1];
        }
        if boxes[i] == '1' {
            one_cnt += 1
        }
    }
    // println!("{boxes:?} {dp2:?}");

    dp2.reverse();

    boxes.reverse();
    boxes
        .into_iter()
        .enumerate()
        .map(|(idx, _)| dp1[idx] + dp2[idx])
        .collect()
}

fn main() {
    assert_eq!(min_operations("110".to_string()), vec![1, 1, 3]);
    assert_eq!(
        min_operations("001011".to_string()),
        vec![11, 8, 5, 4, 3, 4]
    );
}
