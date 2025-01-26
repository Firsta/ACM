pub fn maximum_invitations(favorite: Vec<i32>) -> i32 {
    let favorite: Vec<usize> = favorite.into_iter().map(|x| x as usize).collect();
    let n = favorite.len();
    let mut done = vec![false; n];
    let mut ans = 0usize;
    for i in 0..n {
        if !done[i] {
            let mut i = i;
            let mut cycle = Vec::new();
            while !done[i] {
                cycle.push(i);
                done[i] = true;
                i = favorite[i];
            }
            for (k, v) in cycle.iter().enumerate() {
                if *v == i {
                    ans = std::cmp::max(ans, cycle.len() - k);
                }
            }
        }
    }

    // Topologic sort
    let mut ind = vec![0; n];
    for i in 0..n {
        ind[favorite[i]] += 1;
    }
    let mut q = std::collections::VecDeque::new();
    let mut depth = vec![1; n];
    for i in 0..n {
        if ind[i] == 0 {
            q.push_back(i);
            depth[i] = 1;
        }
    }

    let mut ans1 = 0;
    while !q.is_empty() {
        let t = q.pop_front().unwrap();
        let n = favorite[t];
        depth[n] = std::cmp::max(depth[n], depth[t] + 1);
        ind[n] -= 1;
        if ind[n] == 0 {
            q.push_back(n);
        }
    }
    for i in 0..n {
        if i == favorite[favorite[i]] {
            ans1 += depth[i];
        }
    }
    // println!("{} {:?}", ans1, depth);

    std::cmp::max(ans, ans1) as i32
}

fn main() {
    assert_eq!(maximum_invitations(vec![2, 2, 1, 2]), 3);
    assert_eq!(maximum_invitations(vec![1, 2, 0]), 3);
    assert_eq!(maximum_invitations(vec![3, 0, 1, 4, 1]), 4);
}
