pub fn parse_bool_expr(expression: String) -> bool {
    let mut st = Vec::new();
    for c in expression.chars() {
        match c {
            ')' => {
                let mut v = Vec::new();
                while *st.last().unwrap() != '(' {
                    v.push(st.pop().unwrap());
                }

                st.pop();

                let b = match st.pop().unwrap() {
                    '&' => v
                        .into_iter()
                        .map(|x| match x {
                            'f' => false,
                            't' => true,
                            _ => panic!(),
                        })
                        .fold(true, |f, c| f && c),
                    '|' => v
                        .into_iter()
                        .map(|x| match x {
                            'f' => false,
                            't' => true,
                            _ => panic!(),
                        })
                        .fold(false, |f, c| f || c),
                    '!' => {
                        assert!(v.len() == 1);
                        match v[0] {
                            't' => false,
                            'f' => true,
                            _ => panic!(),
                        }
                    }
                    _ => panic!(),
                };

                st.push(if b { 't' } else { 'f' });
            }
            ',' => (),
            'f' | 't' | '(' | '|' | '&' | '!' => st.push(c),
            _ => panic!(),
        }
    }

    match st[0] {
        'f' => false,
        't' => true,
        _ => panic!(),
    }
}

fn main() {
    assert_eq!(parse_bool_expr("&(|(f))".to_string()), false);
    assert_eq!(parse_bool_expr("!(&(f,t))".to_string()), true);
}
