pub fn find_length_of_shortest_subarray(arr: Vec<i32>) -> i32 {
    let n = arr.len();
    if n == 1 {
        return 0;
    }
    let mut i = 0;
    while i < n - 1 && arr[i] <= arr[i + 1] {
        i += 1;
    }

    if i == n - 1 {
        return 0;
    }

    let mut j = n - 1;
    while j >= 1 && arr[j - 1] <= arr[j] {
        j -= 1;
    }

    // println!("{:?} {:?} {} {}", &arr[0..=i], &arr[j..], i, n - j);

    let mut ans = std::cmp::min(n - i - 1, j);
    for k in 0..=i {
        let p = arr[j..].partition_point(|x| *x < arr[k]);
        // println!("{} {}", k + 1, n - j - p);
        ans = std::cmp::min(ans, n - (k + 1 + n - j - p));
    }

    ans as i32
}

fn main() {
    assert_eq!(
        find_length_of_shortest_subarray(vec![1, 2, 3, 10, 4, 2, 3, 5]),
        3
    );
    assert_eq!(find_length_of_shortest_subarray(vec![5, 4, 3, 2, 1]), 4);
    assert_eq!(find_length_of_shortest_subarray(vec![1, 2, 3]), 0);
    assert_eq!(
        find_length_of_shortest_subarray(vec![6, 3, 10, 11, 15, 20, 13, 3, 18, 12]),
        8
    );
}
