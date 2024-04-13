pub fn maximal_rectangle(matrix: Vec<Vec<char>>) -> i32 {
    let m = matrix.len();
    let n = matrix[0].len();

    let mut heights = vec![0; n + 1];
    let mut stack = Vec::new();
    let mut ans = 0;

    for i in 0..m {
        for j in 0..n {
            heights[j] = if matrix[i][j] == '0' {
                0
            } else {
                heights[j] + 1
            };
        }

        // println!("{:?}", heights);

        stack.clear();
        for j in 0..n + 1 {
            while !stack.is_empty() && heights[j] < heights[*stack.last().unwrap()] {
                let top_idx = stack.pop().unwrap();
                let h = heights[top_idx];
                let w = if stack.is_empty() {
                    j
                } else {
                    j - *stack.last().unwrap() - 1
                };
                ans = std::cmp::max(ans, w * h);
            }
            stack.push(j);
            // println!("{:?} {:?} {}", stack, stack.iter().map(|x| heights[*x]).collect::<Vec<usize>>(), ans);
        }
    }

    // println!("{}", ans);

    ans as i32
}

fn main() {
    assert_eq!(
        maximal_rectangle(vec![
            vec!['1', '0', '1', '0', '0'],
            vec!['1', '0', '1', '1', '1'],
            vec!['1', '1', '1', '1', '1'],
            vec!['1', '0', '0', '1', '0']
        ]),
        6
    );

    assert_eq!(maximal_rectangle(vec![vec!['0'],]), 0);
    assert_eq!(maximal_rectangle(vec![vec!['1'],]), 1);
}
