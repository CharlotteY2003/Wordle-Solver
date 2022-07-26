#include "Guess.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <exception>

Guess::Guess(std::vector<std::string> guess_pool, std::vector<std::string> secret_pool) {
    guess_pool_ = guess_pool;
    secret_pool_ = secret_pool;
}


bool Guess::inVector(std::string obj, std::vector<std::string> vec) {
    for (int i = 0; i < (int) vec.size(); i++) {
        if (obj == vec[i]) {
            return true;
        }
    }
    return false;
}
//iterates through entire guess pool
//for each possible guess, iterate through entire secret pool
//records number of steps it takes for guess to deduce secret in vector avgs
//in each guess's avg, finds the worst number of steps and the average number of steps across all secrets
//records it in record vector
//after all of guesses have had number of steps found out, find guess with minimum worst number of steps
//if multiple guesses with min worst, look for min avgs
//return guess that fits said above criteria
std::pair<std::string, std::pair<int, double>> Guess::FindBestGuess(std::vector<std::string> guess_pool, std::vector<std::string> secret_pool) {
    /*std::cout << "contents of secret pool:";
    for (int i = 0; i < (int) secret_pool.size(); i++) {
        std::cout << " " << secret_pool[i];
    }
    std::cout << std::endl; */
    //std::cout << "--------------------------------------------------------" << std::endl;
    
    if (secret_pool.size() == 1) { //if there is only 1 secret in secret pool and that secret is in the guess pool, return it
        // if (!(inVector(secret_pool[0], guess_pool))) {
        //     throw std::runtime_error("Not in guess pool");
        // } else {
            //return secret_pool[0];
            return std::make_pair(secret_pool[0], std::make_pair(1, 1)); //?
        //}
    } 
    
    if (secret_pool.size() == 2) {
            // If there are only 2 secrets in secret pool, return the 1st one as the best guess
            // (it doesn't really matter which one) with max #steps = 2 (if the secret is the
            // other one) and avg #steps = 1.5.
            return std::make_pair(secret_pool[0], std::make_pair(2, 1.5));
       }

     std::map<std::string, std::pair<int, double>> record_;
       
    for (int i = 0; i < (int) guess_pool.size(); i++) {
        std::vector<int> avgs;
        //std::cout << " findBest loop guess: " << guess_pool[i] << std::endl;
        for (int j = 0; j < (int) secret_pool.size(); j++) {
            //std::cout << "secret:" << secret_pool[i] << std::endl;
           // w = Wordle(secret_pool[j]); //initialize secret_pool
           // w.CheckGuess(guess_pool[i]); //initiate design format for that specific secret and guess
            int num_steps = GetNumberOfSteps(guess_pool, guess_pool[i], secret_pool[j], secret_pool);
            avgs.push_back(num_steps); //log into some record keeping system for number of steps of each guess for each secret
           // w.ResetDesign();
        }
        
        int worst = avgs[0];
        double total = 0; 
    
        for (int i = 0; i < (int) avgs.size(); i++) {
            if (avgs[i] > worst) {
            worst = avgs[i];
            }
            total += avgs[i];
        }
        record_[guess_pool[i]] = std::make_pair(worst, total / (int) avgs.size()); //record vector holds all (worst, avg) steps of all guesses in guess_pool
    }
    
    /*std::cout << "contents of record_:" << std::endl;
    for (auto x : record_) {
        std::cout << x.first << " - (" << x.second.first << ", " << x.second.second << ")" << std::endl;
    } */
    
    int best_index = 0;
    for (int i = 0; i < (int) guess_pool_.size(); i++) {
        std::pair<int, double> curr = record_[guess_pool_[i]];
        std::pair<int, double> best = record_[guess_pool_[best_index]];
        if (curr.first < best.first || (curr.first == best.first && curr.second < best.second)) {
            best_index = i;
        }
    }
    
    //std::cout << "best guess: " << guess_pool_[best_index] << " worst: " << record_[guess_pool_[best_index]].first << "avg: " << record_[guess_pool_[best_index]].second << std::endl;
    return std::make_pair(guess_pool_[best_index], record_[guess_pool_[best_index]]);
}

//Gets number of steps for specific guess  - aka worst case scenerio via best logical Guess
//First narrow downs secret_pool based on guess
//Then decides best new guess with new secret pool
//returns 1 + the number of steps of the new guess with the new secret pool as the number of steps
int Guess::GetNumberOfSteps(std::vector<std::string> guess_pool, std::string guess, std::string secret, std::vector<std::string> secret_pool) {
    //std::cout << "secret:" << secret << " guess: " << guess << std::endl;
    if (guess == secret) {
        //std::cout << "guess: " << guess << " -  " << 1 << std::endl;
        return 1;
    }
    
    w = Wordle(secret); //initialize secret_pool
    w.CheckGuess(guess); //initiate design format for that specific secret and guess
    
    //otherwise
    std::vector<std::string> new_sc = NarrowDownVector(secret_pool);
    w.ResetDesign();
    if (secret_pool.size() == new_sc.size()) { //if the new secret pool is the same as the previous, return extremely large value that rules out as best guess
        //std::cout << guess << " -  " << 1000000 << std::endl;
         //std::cout << "contents of secret pool after NarrowDownVector:"; //NarrowDownVector may be problem
    /*for (int i = 0; i < (int) secret_pool.size(); i++) {
        std::cout << " " << secret_pool[i];
    }
    std::cout << std::endl; */
        return 1000000;
    } 
    std::pair<std::string, std::pair<int, double>> result = FindBestGuess(guess_pool, new_sc); //recursive function
    std::string new_guess = result.first;
    int n = 1 + GetNumberOfSteps(guess_pool, new_guess, secret, new_sc); //recursive function
    //std::cout <<"guess: " << guess << " number of steps -  " << n << std::endl;
    return n;
}

//Narrows down secret pool, only containing vector with possible words in secret pool that follow the guidlines of
//green, yellow, and gray
//returns new secret pool
std::vector<std::string> Guess::NarrowDownVector(std::vector<std::string> secret_pool) {
   // w = Wordle("steam"); //only use for testing NarrowDownVector() ONLY
   // w.CheckGuess("steak");
    //std::cout << "w's guess: " << w.getGuess()[4] << std::endl;
    /*std::cout << "Green: ";
        for (int i = 0; i < 5; i++) {
            std::cout << w.GetGreen()[i] << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Yellow: ";
        for (int i = 0; i < 5; i++) {
            std::cout << w.GetYellow()[i] << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Gray: ";
        for (int i = 0; i < 5; i++) {
            std::cout << w.GetGray()[i] << " ";
        }
    std::cout << std::endl; */
    std::vector<std::string> final;
    
    for (int i = 0; i < (int) secret_pool.size(); i++) {
        //std::cout << "guess pool: " << secret_pool[i] << " Matches Green: " << MatchesGreen(secret_pool[i]) << " Matches Yellow: " << MatchesYellow(secret_pool[i]) << " Matches Gray:" << MatchesGray(secret_pool[i]) << std::endl;
    
        if (MatchesGray(secret_pool[i]) && MatchesGreen(secret_pool[i]) && MatchesYellow(secret_pool[i])) {
            final.push_back(secret_pool[i]);
        }
    } 
    
    return final;
    
}

bool Guess::MatchesGray(std::string input) { //returns true if no letters that match with gray
    // w = Wordle("steam"); //delete later
    // w.CheckGuess(input);
    std::vector<char> gray = w.GetGray();

    std::vector<char> secret_vec(input.begin(), input.end());
    
    
    for (int i = 0; i < (int) gray.size(); i++) { // why is  && gray[i] != '_' causing problems?
        //std::cout << "input: " << input << " " << guess_vec[i] << " vs. " << gray[i] << std::endl;
        if (gray[i] != '_') {
            if (secret_vec[i] == gray[i]) { //gray[i] = hold "bbbbb", guess[vec] = hold "aaaaa"
                return false;
            }
        }
    }
    return true;
}

//returns true if has guess has all letters in green
//if each non "_" in green has the same letter at the same index of guess -> pass
bool Guess::MatchesGreen(std::string input) { 
    std::vector<char> green = w.GetGreen();
    std::vector<char> secret_vec(input.begin(), input.end());
    for (int i = 0; i < (int) green.size(); i++) {
        if (green[i] != '_') {
            if (green[i] != secret_vec[i]) {
                return false;
            }
        }
    }
    return true;
}
//returns true if has guess has all letters and non-matching indices in yellow
//if each non "_" in green has the same letter at the same index of guess -> pass
bool Guess::MatchesYellow(std::string input) {
    std::vector<char> yellow = w.GetYellow();
    std::vector<char> secret_vec(input.begin(), input.end());
    
    for (int i = 0; i < (int) yellow.size(); i++) {
        if (yellow[i] != '_') {
            if (std::find(secret_vec.begin(), secret_vec.end(), yellow[i]) == secret_vec.end() || yellow[i] == secret_vec[i]) {
                return false;
            }
        }
        
    }
    return true;
}

// std::string Guess::FindBestGuess() {
//     std::string best_guess;
//     for (int i = 0; i < (int) guess_pool_.size(); i++) {
//         record_[guess_pool_[i]] = AttemptsPerGuess(guess_pool_[i]);
//     }
    
//     for (auto& x: record_) {
//         std::cout << "guess: " << x.first << " worst: " << x.second.first << " average: " << x.second.second << std::endl;
//     }
    
//     std::vector<std::string> guesses = FindMinWorst();
    
//     for (int i = 0; i < (int) guesses.size(); i++) {
//         std::cout << guesses[i] << ", " << record_[guesses[i]].first << std::endl;
//     }
    
//     if ((int) guesses.size() > 1) {
//         //compare averages
//         int min_index = 0;
//         for (int i = 1; i < (int) guesses.size(); i++) {
//             if (record_[guesses[i]].second < record_[guesses[min_index]].second) {
//                 min_index = i;
//             }
//         }
//         best_guess = guesses[min_index];
//     } else {
//         best_guess = guesses[0];
//     }
    
//     return best_guess;
// }

/*std::vector<std::string> Guess::FindMinWorst() {
    int min_worst = 1000;
    std::vector<std::string> guesses;
    
    for (auto& x: record_) {
        std::string guess = x.first;
        std::pair<int, double> val = x.second;
        
         if (val.first == min_worst) {
            guesses.push_back(guess);
        }
        
        if (val.first < min_worst) {
            min_worst = val.first;
            guesses.clear();
            guesses.push_back(guess);
        } 
    }
    return guesses;
} */

/*
std::pair<int, double> Guess::AttemptsPerGuess(std::string guess) {
    std::vector<int> avgs;
    
    //for every secret element, calculate # guesses it can take before finding secret word, then add to average vector
    for (int i = 0; i < (int) secret_pool_.size(); i++) {
        w = Wordle(secret_pool_[i]);
        w.CheckGuess(guess);
        
        std::vector<std::string> final = NarrowDownVector(); //start of modified code
        if (final.size() == 1 && guess.compare(secret_pool_[i]) == 0) {
            avgs.push_back(1);
        } else {
             avgs.push_back(NarrowDownVector().size() + 1);
        } //end of modified code
        
        w.ResetDesign();
    }
    
    int worst = avgs[0];
    double total = 0; 
    
    for (int i = 0; i < (int) avgs.size(); i++) {
        if (avgs[i] > worst) {
            worst = avgs[i];
        }
        total += avgs[i];
    }
    return std::make_pair(worst, total / (int) avgs.size());
} */