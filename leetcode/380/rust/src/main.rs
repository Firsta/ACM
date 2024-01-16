use rand::seq::SliceRandom;
use std::collections::HashMap;

struct RandomizedSet {
    m: HashMap<i32, usize>,
    v: Vec<i32>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedSet {

    fn new() -> Self {
        RandomizedSet {
            m: HashMap::new(),
            v: Vec::new(),
        }
    }
    
    fn insert(&mut self, val: i32) -> bool {
        // println!("insert: {:?} {:?}", self.m, self.v);
        
        match self.m.get(&val) {
            None => {
                self.v.push(val);
                self.m.insert(val, self.v.len() - 1);
                true
            },
            Some(_) => {
                false
            }
        }
    }
    
    fn remove(&mut self, val: i32) -> bool {
        // println!("remove: {:?} {:?}", self.m, self.v);
        
        match self.m.get(&val) {
            None => false,
            Some(&pos) => {
                self.v.swap_remove(pos);
                if pos < self.v.len() {
                    self.m.insert(self.v[pos], pos);
                }
                self.m.remove(&val);
                true
            }
        }
    }
    
    fn get_random(&self) -> i32 {
        self.v.choose(&mut rand::thread_rng()).unwrap().clone()
    }
}

fn main() {
    let mut x = RandomizedSet::new();
    assert_eq!(x.insert(3), true);
    assert_eq!(x.insert(3), false);
    assert_eq!(x.get_random(), 3);
    assert_eq!(x.get_random(), 3);
    assert_eq!(x.insert(1), true);
    assert_eq!(x.remove(3), true);
    assert_eq!(x.get_random(), 1);
    assert_eq!(x.get_random(), 1);
    assert_eq!(x.insert(0), true);
    assert_eq!(x.insert(0), false);
}
