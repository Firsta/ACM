pub fn number_of_ways(corridor: String) -> i32 {
    let mut num = 0;
    let mut seat_count = 0u64;
    let mut count_plant = false;
    let mut plant_count = 0u64;
    for c in corridor.chars() {
        if c == 'S' {
            seat_count += 1;
            if seat_count == 2 {
                if num == 0 {
                    num = 1;
                }
                count_plant = true;
            } else if seat_count == 3 {
                // println!("{} {}", num, plant_count + 1);
                num = (num * (plant_count + 1)) % (u64::pow(10, 9) + 7);

                count_plant = false;
                plant_count = 0;

                seat_count = 1;
            }
        } else if c == 'P' {
            if count_plant {
                plant_count += 1;
            }
        }
    }
    if seat_count == 1 {
        0
    } else {
        num.try_into().unwrap()
    }
}

fn main() {
    println!("{}", number_of_ways("PPPPPPPSPPPSPPPPSPPPSPPPPPSPPPSPPSPPSPPPPPSPSPPPPPSPPSPPPPPSPPSPPSPPPSPPPPSPPPPSPPPPPSPSPPPPSPSPPPSPPPPSPPPPPSPSPPSPPPPSPPSPPSPPSPPPSPPSPSPPSSSS".to_string()));
    // "PPPPPPPSPPPS PPPP SPPPS PPPPP SPPPS PP SPPS PPPPP SPS PPPPP SPPS PPPPP SPPS PP SPPPS PPPP SPPPPS PPPPP SPS PPPP SPS PPP SPPPPS PPPPP SPS PP SPPPPS PP SPPS PP SPPPS PP SPS PP SS  SS"
    // 5 * 6 * 3 * 6 * 6 * 6 * 3 * 5 * 6 * 5 * 4 * 6 * 3 * 3 * 3 * 3 * 3 
}

