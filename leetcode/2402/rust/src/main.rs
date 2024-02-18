use std::cmp::Ordering;
use std::cmp::Reverse;
use std::collections::BinaryHeap;

#[derive(Eq, Debug)]
struct Item {
    room_id: usize,
    meeting_end_time: i64,
}

impl Ord for Item {
    fn cmp(&self, other: &Self) -> Ordering {
        let time_order = other.meeting_end_time.cmp(&self.meeting_end_time);
        if time_order == Ordering::Equal {
            // If meeting_end_time is equal, compare by room_id in descending order
            other.room_id.cmp(&self.room_id)
        } else {
            time_order
        }
    }
}

impl PartialOrd for Item {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl PartialEq for Item {
    fn eq(&self, other: &Self) -> bool {
        self.room_id == other.room_id && self.meeting_end_time == other.meeting_end_time
    }
}

pub fn most_booked(n: i32, meetings: Vec<Vec<i32>>) -> i32 {
    let mut meetings = meetings.clone();
    meetings.sort_by(|a, b| a[0].cmp(&b[0]));

    let n = n as usize;

    let mut heap: BinaryHeap<Item> = BinaryHeap::with_capacity(n);

    let mut available_room = BinaryHeap::with_capacity(n);
    for i in 0..n {
        available_room.push(Reverse(i));
    }

    let mut cnt = vec![0; n];

    for m in meetings.iter() {
        while heap.peek().is_some() && heap.peek().unwrap().meeting_end_time <= m[0] as i64 {
            available_room.push(Reverse(heap.pop().unwrap().room_id));
        }

        if heap.len() < n {
            let room_id = available_room.pop().unwrap().0;
            cnt[room_id] += 1;

            heap.push(Item {
                room_id,
                meeting_end_time: m[1] as i64,
            });
        } else {
            let p = heap.pop().unwrap();
            let meeting_duration = m[1] - m[0];

            cnt[p.room_id] += 1;

            heap.push(Item {
                room_id: p.room_id,
                meeting_end_time: p.meeting_end_time + meeting_duration as i64,
            });
        }
        // println!("{:?}", heap);
    }

    let mut result = 0;
    for (i, &c) in cnt.iter().enumerate() {
        if c > cnt[result] {
            result = i;
        }
    }
    result as i32
}

fn main() {
    let v: Vec<Vec<i32>> = vec![vec![1, 20], vec![2, 10], vec![3, 5], vec![4, 9], vec![6, 8]];
    assert_eq!(most_booked(3, v), 1);
}
