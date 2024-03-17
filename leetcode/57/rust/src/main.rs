pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
    let mut new_interval = new_interval;
    let mut result = Vec::new();
    let mut pushed = false;

    for i in intervals.iter() {
        if !pushed {
            if new_interval[0] >= i[0] && new_interval[0] <= i[1]
                || new_interval[1] >= i[0] && new_interval[1] <= i[1]
                || i[0] >= new_interval[0] && i[0] <= new_interval[1]
                || i[1] >= new_interval[0] && i[1] <= new_interval[1]
            {
                new_interval[0] = std::cmp::min(new_interval[0], i[0]);
                new_interval[1] = std::cmp::max(new_interval[1], i[1]);
                continue;
            } else {
                if i[0] > new_interval[0] {
                    result.push(new_interval.clone());
                    result.push(i.clone());
                    pushed = true;
                } else {
                    result.push(i.clone());
                }
            }
        } else {
            result.push(i.clone());
        }
    }

    if !pushed {
        result.push(new_interval.clone());
    }

    result
}

fn main() {
    assert_eq!(
        insert(vec![vec![1, 3], vec![6, 9]], vec![2, 5]),
        vec![vec![1, 5], vec![6, 9]]
    );
    assert_eq!(
        insert(
            vec![
                vec![1, 2],
                vec![3, 5],
                vec![6, 7],
                vec![8, 10],
                vec![12, 16]
            ],
            vec![4, 8]
        ),
        vec![vec![1, 2], vec![3, 10], vec![12, 16]]
    );
}
