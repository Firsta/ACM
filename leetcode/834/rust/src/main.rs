pub fn sum_of_distances_in_tree(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
    let n = n as usize;

    // Build a graph
    let mut graph = vec![Vec::<usize>::new(); n];
    for edge in edges.into_iter() {
        graph[edge[0] as usize].push(edge[1] as usize);
        graph[edge[1] as usize].push(edge[0] as usize);
    }
    // println!("{:?}", graph);

    // subtree_node_count
    let mut snc = vec![0usize; n];
    let mut done = vec![false; n];
    fn dfs0(graph: &[Vec<usize>], current_node: usize, done: &mut Vec<bool>, snc: &mut Vec<usize>) {
        done[current_node] = true;
        for &to in graph[current_node].iter() {
            if !done[to] {
                dfs0(graph, to, done, snc);
                snc[current_node] += snc[to];
            }
        }
        snc[current_node] += 1;
    }
    dfs0(&graph, 0, &mut done, &mut snc);
    // println!("snc: {:?}", snc);

    // subtree_root_to_other_nodes_distance
    let mut srtond = vec![0usize; n];
    let mut done = vec![false; n];
    fn dfs1(
        graph: &[Vec<usize>],
        current_node: usize,
        done: &mut Vec<bool>,
        srtond: &mut Vec<usize>,
        snc: &[usize],
    ) {
        done[current_node] = true;
        for &to in graph[current_node].iter() {
            if !done[to] {
                dfs1(graph, to, done, srtond, snc);
                srtond[current_node] += snc[to] + srtond[to];
            }
        }
    }
    dfs1(&graph, 0, &mut done, &mut srtond, &snc);
    // println!("srtond: {:?}", srtond);

    let mut ans = vec![0usize; n];
    ans[0] = srtond[0];
    let mut done = vec![false; n];
    fn dfs3(
        graph: &[Vec<usize>],
        current_node: usize,
        done: &mut Vec<bool>,
        snc: &[usize],
        ans: &mut Vec<usize>,
        father: Option<usize>,
    ) {
        done[current_node] = true;
        if let Some(f) = father {
            ans[current_node] = snc.len() - snc[current_node] + ans[f] - snc[current_node];
        }
        for &to in graph[current_node].iter() {
            if !done[to] {
                dfs3(graph, to, done, snc, ans, Some(current_node));
            }
        }
    }
    dfs3(&graph, 0, &mut done, &snc, &mut ans, None);

    ans.into_iter().map(|x| x as i32).collect()
}

fn main() {
    assert_eq!(
        sum_of_distances_in_tree(
            6,
            vec![vec![0, 1], vec![0, 2], vec![2, 3], vec![2, 4], vec![2, 5]]
        ),
        vec![8, 12, 6, 10, 10, 10]
    );
    assert_eq!(sum_of_distances_in_tree(1, Vec::new()), vec![0]);
    assert_eq!(sum_of_distances_in_tree(2, vec![vec![1, 0]]), vec![1, 1]);
}
