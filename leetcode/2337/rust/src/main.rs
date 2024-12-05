pub fn can_change(start: String, target: String) -> bool {
    if start.chars().filter(|x| *x == 'L').count() != target.chars().filter(|x| *x == 'L').count() {
        return false;
    }

    if start.chars().filter(|x| *x == 'R').count() != target.chars().filter(|x| *x == 'R').count() {
        return false;
    }

    if start.chars().filter(|x| *x != '_').collect::<String>()
        != target.chars().filter(|x| *x != '_').collect::<String>()
    {
        return false;
    }

    {
        let mut i1 = 0;
        for i0 in 0..target.len() {
            if target.as_bytes()[i0] as char == 'L' {
                // println!("{}", i0);

                i1 = std::cmp::max(i0, i1);
                // println!("{}", i1);

                while i1 < start.len() && start.as_bytes()[i1] as char != 'L' {
                    if start.as_bytes()[i1] as char == 'R' {
                        return false;
                    }
                    i1 += 1;
                }
                if i1 == target.len() {
                    return false;
                }
                i1 += 1;
            }
        }
    }

    let start = start.chars().rev().collect::<String>();
    let target = target.chars().rev().collect::<String>();

    // println!("{} {}", start, target);

    {
        let mut i1 = 0;
        for i0 in 0..target.len() {
            if target.as_bytes()[i0] as char == 'R' {
                // println!("{}", i0);
                i1 = std::cmp::max(i0, i1);
                while i1 < start.len() && start.as_bytes()[i1] as char != 'R' {
                    if start.as_bytes()[i1] as char == 'L' {
                        return false;
                    }
                    i1 += 1;
                }
                if i1 == start.len() {
                    return false;
                }
                i1 += 1;
            }
        }
    }

    true
}

fn main() {
    assert_eq!(
        can_change("_L__R__R_".to_string(), "L______RR".to_string()),
        true
    );
    assert_eq!(can_change("R_L_".to_string(), "__LR".to_string()), false);
    assert_eq!(can_change("_R".to_string(), "R_".to_string()), false);
    assert_eq!(can_change("L_L".to_string(), "_LL".to_string()), false);
    assert_eq!(can_change("R__L".to_string(), "_LR_".to_string()), false);
}
