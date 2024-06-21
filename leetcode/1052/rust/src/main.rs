use std::collections::VecDeque;

#[derive(Debug)]
struct NotStatisfiedCustomer {
    when: i32,
    cnt: i32,
}

pub fn max_satisfied(customers: Vec<i32>, grumpy: Vec<i32>, minutes: i32) -> i32 {
    let mut not_statisfied_customers = Vec::new();
    let n = customers.len();
    let mut grumpy_all = 0;
    for i in 0..n {
        if grumpy[i] == 1 {
            not_statisfied_customers.push(NotStatisfiedCustomer {
                when: i as i32,
                cnt: customers[i],
            });
            grumpy_all += customers[i];
        }
    }

    let all: i32 = customers.iter().sum();

    // println!("{:?} {}", not_statisfied_customers, all);

    let mut q: VecDeque<NotStatisfiedCustomer> = VecDeque::new();
    let mut max_eliminated = 0;
    let mut eliminated = 0;
    for c in not_statisfied_customers.into_iter() {
        while let Some(f) = q.front() {
            if c.when - f.when >= minutes {
                eliminated -= f.cnt;
                q.pop_front();
            } else {
                break;
            }
        }
        eliminated += c.cnt;
        q.push_back(c);

        // println!("{:?}", q);

        max_eliminated = std::cmp::max(eliminated, max_eliminated);
    }

    all - grumpy_all + max_eliminated
}

fn main() {
    assert_eq!(
        max_satisfied(
            vec![1, 0, 1, 2, 1, 1, 7, 5],
            vec![0, 1, 0, 1, 0, 1, 0, 1],
            3
        ),
        16
    );
}
