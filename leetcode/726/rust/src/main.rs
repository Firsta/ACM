use std::collections::BTreeMap;

#[derive(Debug, Clone)]
enum State {
    Init,
    LeftParen,
    RightParen,
    AtomLiteral(String),
    CountAtom(String, u32),
    CountSyn(u32),
}

#[derive(Debug)]
struct Parser {
    state: State,
    st: Vec<BTreeMap<String, u32>>,
}

use State::*;

impl Parser {
    fn new() -> Self {
        Self {
            state: Init,
            st: Vec::new(),
        }
    }

    fn last_map(&mut self) -> &mut BTreeMap<String, u32> {
        self.st.last_mut().unwrap()
    }

    fn push_map(&mut self) {
        self.st.push(BTreeMap::new());
    }

    fn add_atom(&mut self, atom: String, cnt: u32) {
        self.last_map()
            .entry(atom.clone())
            .and_modify(|e| *e += cnt)
            .or_insert(cnt);
    }

    fn merge_map(&mut self, factor: u32) {
        if self.st.len() == 1 {
            return;
        }

        let p = self.st.pop().unwrap();
        for (k, v) in p.into_iter() {
            self.add_atom(k, v * factor);
        }
    }

    pub fn ans(&self) -> String {
        let mut ans = String::new();
        assert_eq!(self.st.len(), 1);
        let l = self.st.last().unwrap();
        for (k, v) in l.iter() {
            ans.push_str(k);
            if *v > 1 {
                ans.push_str(&v.to_string());
            }
        }

        ans
    }

    pub fn handle(&mut self, c: char) {
        let s = self.state.clone();
        self.state = match s {
            Init => {
                if c.is_ascii_lowercase() {
                    panic!();
                } else if c.is_ascii_uppercase() {
                    AtomLiteral(c.to_string())
                } else if c == '(' {
                    self.push_map();
                    LeftParen
                } else if c == ')' {
                    panic!()
                } else {
                    assert!(c.is_digit(10));
                    panic!();
                }
            },
            LeftParen => {
                if c.is_ascii_lowercase() {
                    panic!();
                } else if c.is_ascii_uppercase() {
                    AtomLiteral(c.to_string())
                } else if c == '(' {
                    self.push_map();
                    LeftParen
                } else if c == ')' {
                    self.st.pop();
                    RightParen
                } else {
                    assert!(c.is_digit(10));
                    panic!();
                }
            },
            RightParen/* ) */ => {
                if c.is_ascii_lowercase() {
                    panic!();
                } else if c.is_ascii_uppercase() {
                    self.merge_map(1);
                    AtomLiteral(c.to_string())
                } else if c == '(' {
                    self.merge_map(1);
                    LeftParen
                } else if c == ')' {
                    self.merge_map(1);
                    RightParen
                } else {
                    assert!(c.is_digit(10));
                    CountSyn(c.to_digit(10).unwrap())
                }
            },
            AtomLiteral(atom) => {
                if c.is_ascii_lowercase() {
                    let mut atom = atom.clone();
                    atom.push(c);
                    AtomLiteral(atom)
                } else if c.is_ascii_uppercase() {
                    self.add_atom(atom, 1);
                    AtomLiteral(c.to_string())
                } else if c == '(' {
                    self.add_atom(atom, 1);
                    self.st.push(BTreeMap::new());
                    LeftParen
                } else if c == ')' {
                    self.add_atom(atom, 1);
                    RightParen
                } else {
                    assert!(c.is_digit(10));
                    CountAtom(atom.clone(), c.to_digit(10).unwrap())
                }
            },
            CountAtom(atom, cnt) => {
                if c.is_ascii_lowercase() {
                    panic!();
                } else if c.is_ascii_uppercase() {
                    self.add_atom(atom, cnt);
                    AtomLiteral(c.to_string())
                } else if c == '(' {
                    self.add_atom(atom, cnt);
                    self.push_map();
                    LeftParen
                } else if c == ')' {
                    self.add_atom(atom, cnt);
                    RightParen
                } else {
                    assert!(c.is_digit(10));
                    CountAtom(atom.clone(), cnt * 10 + c.to_digit(10).unwrap())
                }
            },
            CountSyn(cnt) => {
                if c.is_ascii_lowercase() {
                    panic!();
                } else if c.is_ascii_uppercase() {
                    self.merge_map(cnt);
                    AtomLiteral(c.to_string())
                } else if c == '(' {
                    self.merge_map(cnt);
                    self.push_map();
                    LeftParen
                } else if c == ')' {
                    self.merge_map(cnt);
                    RightParen
                } else {
                    assert!(c.is_digit(10));
                    CountSyn(cnt * 10 + c.to_digit(10).unwrap())
                }
            }
        }
    }
}

pub fn count_of_atoms(formula: String) -> String {
    let mut f = "(".to_string();
    f.push_str(&formula);
    f.push(')');

    let mut parser = Parser::new();
    for c in f.chars() {
        parser.handle(c);
        // println!("{}", c);
        // println!("{:?}", parser);
    }

    parser.ans()
}

fn main() {
    assert_eq!(count_of_atoms("Mg(H2O)N".to_string()), "H2MgNO".to_string());
    assert_eq!(count_of_atoms("H2O".to_string()), "H2O".to_string());
    assert_eq!(count_of_atoms("Mg(OH)2".to_string()), "H2MgO2".to_string());
    assert_eq!(
        count_of_atoms("K4(ON(SO3)2)2".to_string()),
        "K4N2O14S4".to_string()
    );
}
