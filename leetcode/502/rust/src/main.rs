use std::collections::BinaryHeap;

#[derive(Debug)]
struct Project {
    profit: i32,
    capital: i32,
}

pub fn find_maximized_capital(k: i32, w: i32, profits: Vec<i32>, capital: Vec<i32>) -> i32 {
    let mut projects = Vec::new();
    for i in 0..profits.len() {
        projects.push(Project {
            profit: profits[i],
            capital: capital[i],
        });
    }
    projects.sort_by(|a, b| a.capital.cmp(&b.capital));
    // println!("{:?}", projects);

    let mut w = w;
    let mut h = BinaryHeap::new();
    let mut c = 0;
    let mut i = 0;

    loop {
        while i < projects.len() && projects[i].capital <= w {
            h.push(projects[i].profit);
            i += 1;
        }
        if h.peek().is_none() {
            break;
        }
        w += h.pop().unwrap();
        c += 1;
        if c == k {
            break;
        }
    }

    w
}

fn main() {
    assert_eq!(
        find_maximized_capital(2, 0, vec![1, 2, 3], vec![0, 1, 1]),
        4
    );
}
