pub fn relative_sort_array(arr1: Vec<i32>, arr2: Vec<i32>) -> Vec<i32> {
    let mut v = vec![0; 1001];

    for a in arr1.into_iter() {
        v[a as usize] += 1;
    }

    let mut ans = Vec::new();
    for a in arr2.into_iter() {
        for _ in 0..v[a as usize] {
            ans.push(a);
        }
        v[a as usize] = 0;
    }

    for i in 0..1001 {
        for _ in 0..v[i] {
            ans.push(i as i32);
        }
    }

    ans
}

fn main() {
    assert_eq!(
        relative_sort_array(
            vec![2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19],
            vec![2, 1, 4, 3, 9, 6]
        ),
        vec![2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19]
    );
}
