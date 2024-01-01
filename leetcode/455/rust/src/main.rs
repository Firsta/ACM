pub fn find_content_children(g: Vec<i32>, s: Vec<i32>) -> i32 {
    let mut gg = g.clone();
    let mut ss = s.clone();
    
    gg.sort();
    ss.sort();
    
    let mut gi = 0;
    let mut si = 0;
    
    while gi < g.len() {
        while si < ss.len() && gg[gi] > ss[si] {
            si += 1;
        }
        if si == ss.len() {
            break;
        } else {
            gi += 1;
            si += 1;
        }
    }
    
    gi as i32
}

fn main() {
    println!("{}", find_content_children(vec![1,2,3], vec![1, 1]));
}
