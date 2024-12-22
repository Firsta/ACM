pub fn leftmost_building_queries(heights: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
    let mut ans = vec![-1; queries.len()];
    let mut to_do = vec![Vec::new(); heights.len()];
    for (idx, query) in queries.into_iter().enumerate() {
        let left = std::cmp::min(query[0], query[1]);
        let right = std::cmp::max(query[0], query[1]);
        if left == right {
            ans[idx] = left;
        } else {
            if heights[right as usize] > heights[left as usize] {
                ans[idx] = right;
            } else {
                to_do[right as usize].push((heights[left as usize], idx));
            }
        }
    }
    if to_do.is_empty() {
        return ans;
    }

    // println!("{:?}", to_do);

    let mut ms: Vec<(i32, usize)> = Vec::new();
    for i in (0..heights.len()).rev() {
        if !ms.is_empty() {
            for (height, idx) in to_do[i].iter() {
                if *height < ms.first().unwrap().0 {
                    let p = ms.partition_point(|x| x.0 > *height);
                    ans[*idx] = ms[p - 1].1 as i32;
                }
            }
        }
        while !ms.is_empty() && ms.last().unwrap().0 < heights[i] {
            ms.pop();
        }
        ms.push((heights[i], i));
    }

    ans
}

fn main() {
    assert_eq!(
        leftmost_building_queries(
            vec![6, 4, 8, 5, 2, 7],
            vec![vec![0, 1], vec![0, 3], vec![2, 4], vec![3, 4], vec![2, 2]]
        ),
        vec![2, 5, -1, 5, 2]
    );
}
