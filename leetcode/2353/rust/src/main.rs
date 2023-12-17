use std::collections::BTreeSet;
use std::collections::HashMap;
use std::cmp::Ordering;

#[derive(Eq, PartialEq)]
struct FoodRating {
    food: String,
    rating: i32,
}

impl PartialOrd for FoodRating {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Ord for FoodRating {
    fn cmp(&self, other: &Self) -> Ordering {
        match self.rating.cmp(&other.rating) {
            Ordering::Less => Ordering::Less,
            Ordering::Greater => Ordering::Greater,
            Ordering::Equal => {
                match self.food.cmp(&other.food) {
                    Ordering::Less => Ordering::Greater,
                    Ordering::Greater => Ordering::Less,
                    Ordering::Equal => Ordering::Equal,
                }
            }
        }
    }
}

struct FoodRatings {
    food_to_cuisine: HashMap<String/*food*/, String/*cuisine*/>,
    food_to_rating: HashMap<String/*food*/, i32/*cuisine*/>,
    cuisine_maps: HashMap<String/*cuisine*/, BTreeSet<FoodRating>>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl FoodRatings {
    fn new(foods: Vec<String>, cuisines: Vec<String>, ratings: Vec<i32>) -> Self {
        let mut result = FoodRatings {
            food_to_cuisine: HashMap::new(),
            food_to_rating: HashMap::new(),
            cuisine_maps: HashMap::new(),
        };
        for i in 0..foods.len() {
            result.food_to_cuisine.insert(foods[i].clone(), cuisines[i].clone());
            result.food_to_rating.insert(foods[i].clone(), ratings[i]);
            
            if result.cuisine_maps.get(&cuisines[i]).is_none() {
                result.cuisine_maps.insert(cuisines[i].clone(), BTreeSet::new());
            }
            result.cuisine_maps
                .get_mut(&cuisines[i]).unwrap()
                .insert(FoodRating {food: foods[i].clone(), rating: ratings[i]});
        }
        result
    }

    fn change_rating(&mut self, food: String, new_rating: i32) {
        let old_rating = self.food_to_rating.get(&food).unwrap();
        let item = FoodRating {food: food.clone(), rating: *old_rating};

        let cuisine = self.food_to_cuisine.get(&food).unwrap();
    
        let m = self.cuisine_maps.get_mut(cuisine).unwrap();
        m.remove(&item);
        m.insert(FoodRating{food: food.clone(), rating: new_rating});

        self.food_to_rating.insert(food, new_rating);
    }

    fn highest_rated(&self, cuisine: String) -> String {
        self.cuisine_maps.get(&cuisine).unwrap().iter().next_back().unwrap().food.clone()
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * let obj = FoodRatings::new(foods, cuisines, ratings);
 * obj.change_rating(food, newRating);
 * let ret_2: String = obj.highest_rated(cuisine);
 */

fn main() {
    let mut frs = FoodRatings::new(
        vec!["kimchi".to_string(), "miso".to_string(), "sushi".to_string(), "moussaka".to_string(), "ramen".to_string(), "bulgogi".to_string()],
        vec!["korean".to_string(), "japanese".to_string(), "japanese".to_string(), "greek".to_string(), "japanese".to_string(), "korean".to_string()],
        vec![9, 12, 8, 15, 14, 7],
    );
    assert!(frs.highest_rated("korean".to_string()) == "kimchi".to_string());
    assert!(frs.highest_rated("japanese".to_string()) == "ramen".to_string());
    frs.change_rating("sushi".to_string(), 16);
    assert!(frs.highest_rated("japanese".to_string()) == "sushi".to_string());
    frs.change_rating("ramen".to_string(), 16);
    assert!(frs.highest_rated("japanese".to_string()) == "ramen".to_string());
}
