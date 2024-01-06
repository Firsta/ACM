#[derive(Debug)]
struct Item {
    s: i32,
    e: i32,
    p: i32,
}

pub fn job_scheduling(start_time: Vec<i32>, end_time: Vec<i32>, profit: Vec<i32>) -> i32 {
    let mut c = Vec::new();
    for i in 0..start_time.len() {
        c.push(Item {
            s: start_time[i],
            e: end_time[i],
            p: profit[i],
        });
    }
    c.sort_by(|a, b| a.e.cmp(&b.e));
    // println!("{:?}", c);
    let mut dp = Vec::<(i32, i32)>::new();
    // 0: end_time 1: profit
    for i in c.iter() {
        let mut t = (i.e, i.p);
        if dp.len() > 0 {
            let pp = dp.partition_point(|&x| x.0 <= i.s);
            if pp > 0 {
                t.1 = dp[pp - 1].1 + i.p;
            }
            let pp = dp.partition_point(|&x| x.0 <= i.e);
            if pp > 0 {
                if dp[pp - 1].1 > t.1 {
                    t.1 = dp[pp - 1].1;
                }
            }
        }
        dp.push(t);
    }
    dp[dp.len() - 1].1
}

fn main() {
    println!(
        "{}",
        job_scheduling(vec![1, 2, 3, 3], vec![3, 4, 5, 6], vec![50, 10, 40, 70])
    );
}
