pub fn minimum_diameter_after_merge(edges1: Vec<Vec<i32>>, edges2: Vec<Vec<i32>>) -> i32 {
    fn dfs(
        g: &Vec<Vec<usize>>,
        cur: usize,
        father: Option<usize>,
        depths: &mut Vec<usize>,
        cur_depth: usize,
    ) {
        depths[cur] = cur_depth;

        for &dst in g[cur as usize].iter() {
            if father.is_none() || dst != father.unwrap() {
                dfs(g, dst, Some(cur), depths, cur_depth + 1);
            }
        }
    }

    let d1 = {
        let node_cnt = edges1.len() + 1;
        let mut g = vec![Vec::new(); node_cnt];
        for e in edges1 {
            g[e[0] as usize].push(e[1] as usize);
            g[e[1] as usize].push(e[0] as usize);
        }

        let mut depths = vec![0; node_cnt];
        dfs(&g, 0, None, &mut depths, 0);
        // println!("{depths:?}");

        let mut fathest = 0;
        for (idx, depth) in depths.iter().enumerate() {
            if *depth > depths[fathest] {
                fathest = idx;
            }
        }
        // println!("{fathest}");

        let mut depths = vec![0; node_cnt];
        dfs(&g, fathest, None, &mut depths, 0);
        // println!("{depths:?}");

        depths.iter().max().unwrap().clone()
    };

    let d2 = {
        let node_cnt = edges2.len() + 1;
        let mut g = vec![Vec::new(); node_cnt];
        for e in edges2 {
            g[e[0] as usize].push(e[1] as usize);
            g[e[1] as usize].push(e[0] as usize);
        }

        let mut depths = vec![0; node_cnt];
        dfs(&g, 0, None, &mut depths, 0);
        // println!("{depths:?}");

        let mut fathest = 0;
        for (idx, depth) in depths.iter().enumerate() {
            if *depth > depths[fathest] {
                fathest = idx;
            }
        }
        // println!("{fathest}");

        let mut depths = vec![0; node_cnt];
        dfs(&g, fathest, None, &mut depths, 0);
        // println!("{depths:?}");

        depths.iter().max().unwrap().clone()
    };

    // println!("{} {}", d1, d2);
    let dd1 = if d1 % 2 == 0 { d1 / 2 } else { d1 / 2 + 1 };
    let dd2 = if d2 % 2 == 0 { d2 / 2 } else { d2 / 2 + 1 };

    std::cmp::max(d1, std::cmp::max(d2, dd1 + dd2 + 1)) as i32
}

fn main() {
    assert_eq!(
        minimum_diameter_after_merge(vec![vec![0, 1], vec![0, 2], vec![0, 3]], vec![vec![0, 1]]),
        3
    );
    assert_eq!(
        minimum_diameter_after_merge(
            vec![
                vec![0, 1],
                vec![0, 2],
                vec![0, 3],
                vec![2, 4],
                vec![2, 5],
                vec![3, 6],
                vec![2, 7]
            ],
            vec![
                vec![0, 1],
                vec![0, 2],
                vec![0, 3],
                vec![2, 4],
                vec![2, 5],
                vec![3, 6],
                vec![2, 7]
            ]
        ),
        5
    );
    assert_eq!(
        minimum_diameter_after_merge(Vec::new(), vec![vec![0, 1], vec![1, 2]]),
        2
    );
    assert_eq!(
        minimum_diameter_after_merge(
            vec![
                vec![0, 1],
                vec![2, 0],
                vec![3, 2],
                vec![3, 6],
                vec![8, 7],
                vec![4, 8],
                vec![5, 4],
                vec![3, 5],
                vec![3, 9]
            ],
            vec![vec![0, 1], vec![0, 2], vec![0, 3]]
        ),
        7
    );
}
