pub fn maximum_beauty(items: Vec<Vec<i32>>, queries: Vec<i32>) -> Vec<i32> {
    let mut items = items.clone();
    items.sort_by(|a, b| a[0].cmp(&b[0]));

    let mut max = 0;
    for i in items.iter_mut() {
        if i[1] > max {
            max = i[1];
        }
        i[1] = max;
    }

    queries
        .into_iter()
        .map(|x| {
            if x < items[0][0] {
                0
            } else {
                if x >= items[items.len() - 1][0] {
                    items[items.len() - 1][1]
                } else {
                    let i = items.partition_point(|t| t[0] <= x);
                    items[i - 1][1]
                }
            }
        })
        .collect()
}

fn main() {
    assert_eq!(
        maximum_beauty(
            vec![vec![1, 2], vec![3, 2], vec![2, 4], vec![5, 6], vec![3, 5]],
            vec![1, 2, 3, 4, 5, 6]
        ),
        vec![2, 4, 5, 5, 6, 6]
    );
}
