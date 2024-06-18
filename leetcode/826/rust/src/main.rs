#[derive(Debug)]
struct Work {
    d: i32,
    p: i32,
}

pub fn max_profit_assignment(difficulty: Vec<i32>, profit: Vec<i32>, worker: Vec<i32>) -> i32 {
    let n = difficulty.len();
    let mut works = Vec::new();
    for i in 0..n {
        works.push(Work {
            d: difficulty[i],
            p: profit[i],
        });
    }

    works.sort_by(|a, b| a.d.cmp(&b.d));

    let mut worker = worker;
    worker.sort();

    let mut max_p = 0;
    let mut works_idx = 0;
    let mut ans = 0;
    for w in worker.into_iter() {
        while works_idx < works.len() && works[works_idx].d <= w {
            max_p = std::cmp::max(max_p, works[works_idx].p);
            works_idx += 1;
        }
        ans += max_p;
    }

    ans
}

fn main() {
    assert_eq!(
        max_profit_assignment(
            vec![2, 4, 6, 8, 10],
            vec![10, 20, 30, 40, 50],
            vec![4, 5, 6, 7]
        ),
        100
    );
}
