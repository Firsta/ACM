use std::cmp::Reverse;
use std::collections::BinaryHeap;

pub fn smallest_chair(times: Vec<Vec<i32>>, target_friend: i32) -> i32 {
    let mut times: Vec<(usize, Vec<i32>)> = times.into_iter().enumerate().collect();
    times.sort_by(|a, b| a.1[0].cmp(&b.1[0]));

    let mut h1: BinaryHeap<Reverse<(i32, usize)>> = BinaryHeap::new();
    let mut h2 = BinaryHeap::new();

    let mut ls = -1;

    for (idx, t) in times.into_iter() {
        while h1.peek().is_some() && h1.peek().unwrap().0 .0 <= t[0] {
            h2.push(Reverse(h1.pop().unwrap().0 .1));
        }
        ls = if h2.is_empty() {
            h1.len() as i32
        } else {
            h2.pop().unwrap().0 as i32
        };
        if idx == target_friend as usize {
            return ls;
        }
        h1.push(Reverse((t[1], ls as usize)));
    }

    0
}

fn main() {
    assert_eq!(
        smallest_chair(
            vec![
                vec![24710, 60469],
                vec![25295, 76256],
                vec![11088, 34742],
                vec![92605, 97746],
                vec![68272, 68682],
                vec![44286, 70033],
                vec![88703, 92573],
                vec![37394, 87075],
                vec![47741, 73042],
                vec![5603, 9454],
                vec![88970, 96339],
                vec![62904, 98525],
                vec![42743, 69814],
                vec![28999, 80490],
                vec![76263, 90116],
                vec![78042, 90721],
                vec![27856, 69492],
                vec![20067, 54704],
                vec![72177, 81840],
                vec![34951, 76201],
                vec![59089, 65862],
                vec![61102, 76554],
                vec![32726, 48272],
                vec![57683, 99972],
                vec![74537, 85162],
                vec![88161, 90916],
                vec![50114, 88989],
                vec![5170, 11173],
                vec![87698, 90284],
                vec![78856, 84320],
                vec![14517, 51015],
                vec![30757, 54925],
                vec![28234, 45768],
                vec![73177, 89666]
            ],
            3
        ),
        1
    );
}
