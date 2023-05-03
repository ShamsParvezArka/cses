use std::io;

fn main() {
    let mut input: String = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let mut count: i32 = 0;

    loop {
        let mut raw: Vec<u32> = input.trim()
                                     .chars()
                                     .map(|x| x.to_digit(10).unwrap())
                                     .collect();
        raw.sort();
        let min: u32 = raw.iter()
                          .fold(0, |acc, e| acc * 10 + e);
        raw.reverse();
        let max: u32 = raw.iter()
                          .fold(0, |acc, e| acc * 10 + e);

        if max - min == 6174 {
            count = count + 1;
            break;
        }
        input = (max - min).to_string();
        count = count + 1;
    }

    println!("{}", count);
}

