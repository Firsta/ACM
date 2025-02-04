pub fn eventual_safe_nodes(graph: Vec<Vec<i32>>) -> Vec<i32> {
    let n = graph.len();
    let mut in_stack = vec![false; n];
    let mut done = vec![false; n];
    fn dfs(
        cur: usize,
        graph: &Vec<Vec<i32>>,
        in_stack: &mut Vec<bool>,
        done: &mut Vec<bool>,
    ) -> bool {
        if in_stack[cur] {
            return true;
        }
        if done[cur] {
            return false;
        }
    }
}

fn main() {
    println!("Hello world!");
}
