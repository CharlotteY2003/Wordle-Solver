/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include "wordle.hpp"
#include <fstream>
#include <vector>
#include "Guess.hpp"
#include <utility>
#include <cmath>
#include <ctime>

int main()
{
    //first case - answer: abcdd and abcde
    // std::vector<std::string> secret_pool1 = {"aaaaa", "bbbbb", "ccccc"}; //first case
    // std::vector<std::string> guess_pool1 = {"aaaaa", "bbbbb", "ccccc", "abcdd", "abcde"};
    // Guess g1 = Guess(guess_pool1, secret_pool1);
    
    //second case - answer: abccc and abcdd
    // std::vector<std::string> secret_pool = {"aaaaa", "abbbb", "abccc", "abcdd"};
    // std::vector<std::string> guess_pool = {"aaaaa", "abbbb", "abccc", "abcdd", "abcde"};
    // Guess g = Guess(guess_pool, secret_pool);
    
    //third case
    // std::vector<std::string> secret_pool3 = {"stead", "steak", "steam"};
    // std::vector<std::string> guess_pool3;
    // std::ifstream ifs{"corncob5.txt"};
    // for (std::string line; std::getline(ifs, line); line = '\n') {
    //     guess_pool3.push_back(line);
    // }
    // Guess g3 = Guess(guess_pool3, secret_pool3);
    
    // std::vector<std::string> gp_test = {"stead", "steak", "steam"};
    // Guess gt = Guess(gp_test, gp_test);
    // std::vector<std::string> final = gt.NarrowDownVector(gp_test);
    // for (int i = 0; i < (int) final.size(); i++) {
    //     std::cout << final[i] << std::endl;
    // }
    
    //fourth case
    // std::vector<std::string> secret_pool4 = {"baste", "paste", "saute", "stead", "steak", "steam", "taste", "waste"};
    // Guess g4 = Guess(guess_pool3, secret_pool4);
    
    //g.NarrowDownVector(); //comment out this one for first case
    //Wordle w = Wordle("ccccc");
    //w.CheckGuess("bbbbb");
    
    // std::pair<std::string, std::pair<int, double>> resultg1 = g1.FindBestGuess(guess_pool1, secret_pool1);
    // std::pair<std::string, std::pair<int, double>> result = g.FindBestGuess(guess_pool, secret_pool);
    // std::pair<std::string, std::pair<int, double>> result3 = g3.FindBestGuess(guess_pool3, secret_pool3);
     //std::pair<std::string, std::pair<int, double>> result4 = g4.FindBestGuess(guess_pool3, secret_pool4);
    
    // std::cout << resultg1.first << " - worst: " << resultg1.second.first << "avg: " << resultg1.second.second << std::endl;
    // std::cout << result.first << " - worst: " << result.second.first << "avg: " << result.second.second << std::endl; //remove comments for first case
    //std::cout << result4.first << " - worst: " << result4.second.first << "avg: " << result4.second.second << std::endl;
    
    //check time functions
    // clock_t time_req;
    
    std::vector<std::string> gp_test = {"stead", "steak", "steam"}; //will this create a shallow copy, when will they get connected?
    Guess g_test = Guess(gp_test, gp_test);
    std::pair<std::string, std::pair<int, double>> g_guess = g_test.FindBestGuess(gp_test, gp_test);
    std::cout << " best guess: " << g_guess.first <<  " - worst: " << g_guess.second.first << "avg: " << g_guess.second.second << std::endl;
    
    // while (gp_test.size() <= guess_pool3.size()) {
    //     time_req = clock();
    //     Guess g_test = Guess(gp_test, secret_pool3);
    //     std::pair<std::string, std::pair<int, double>> g_guess = g_test.FindBestGuess(gp_test, secret_pool3);
    //     time_req = clock() - time_req;
    //     std::cout << "Function duration when guess pool = " << gp_test.size() << ": " << (float)time_req/CLOCKS_PER_SEC << " best guess: " << g_guess.first <<  " - worst: " << g_guess.second.first << "avg: " << g_guess.second.second << std::endl;
    //     int size = gp_test.size() * 2;
    //     for (int i = gp_test.size(); i < size; i++) {
    //         gp_test.push_back(guess_pool3[i]);
    //     }
    // }
    
    //std::string guess = "abccc";
    
    //w.CheckGuess(guess);
        
    //std::cout << "Matches Green: " << g.MatchesGreen(guess) << " " << "Matches Yellow: " << g.MatchesYellow(guess) << " Matches Gray:" << g.MatchesGray(guess) << std::endl;
    
    
    
    
    
    
    //**beginning of interface **//
    
    
    // std::string input;
    // bool solved = false;
    // Wordle w;
    // Wordle test = Wordle();
    
    
    
    // std::cout << "Do you want to enter a secret word? y/n" << std::endl;
    // std::cin >> input;
    // if (input == "y") {
    //     while (input.length() != 5 || !test.IsRealWord(input)) {
    //         std::cout << "Please enter your secret word that is 5 letters long" << std::endl;
    //         std::cin >> input; //check to see if input is a real 5 letter word
    //     }
    //     w = Wordle(input);
    // } else {
    //     w = Wordle();
    // }
    
    // for (int i = 0; i < 100; i++) {
    //     std::cout << std::endl;
    // }
    
    
    // for (int i = 0; i < 6 && !solved; i++) {
    //     std::cout << "Please enter your guess" << std::endl;
    //     std::cin >> input;
    //     //correct input
    //     while (!(w.IsRealWord(input)) || input.length() != 5) {
    //          std::cout << "Please enter your guess" << std::endl;
    //         std::cin >> input;
    //     }
    //     w.CheckGuess(input);
    //     solved = (w.GetGreen() == w.GetSecretWord());
    //     std::cout << "Green: ";
    //     for (int i = 0; i < 5; i++) {
    //         std::cout << w.GetGreen()[i] << " ";
    //     }
    //     std::cout << std::endl;
        
    //     std::cout << "Yellow: ";
    //     for (int i = 0; i < 5; i++) {
    //         std::cout << w.GetYellow()[i] << " ";
    //     }
    //     std::cout << std::endl;
        
    //     std::cout << "Gray: ";
    //     for (int i = 0; i < 5; i++) {
    //         std::cout << w.GetGray()[i] << " ";
    //     }
    //     std::cout << std::endl;
    //     w.ResetDesign();
    // }
    
    // if (solved) {
    //     std::cout << "Congrats! Play again sometime!" << std::endl;
    // } else {
    //     std::string word;
    //     for (int i = 0; i < 5; i++) {
    //         word += w.GetSecretWord()[i];
    //     }
    //     std::cout << "Aww rats! The secret word was " << word << ". Try again next time!" << std::endl;
    // }
    
    
  //** end of interface **//  
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // // Wordle w = Wordle("dicks");
    // std::vector<char> guess = {'b', 'r', 'o', 'a', 'd'};
    // std::vector<char> secret_word = {'d', 'i', 'c', 'k', 's'};
    
    // std::map<const char, int> curr_map;
    
    // for (int i = 0; i < 5; i++) {
    //     if (curr_map.count(guess[i]) > 0) {
    //         curr_map[guess[i]] = curr_map[guess[i]]++;
    //     } else {
    //         curr_map[guess[i]] = 1;
    //     }
    // }
    
    // for (int i = 0; i < 5; i++) {
    //     if (guess[i] == secret_word[i]) {
    //         std::cout << guess[i] << " is green" << std::endl;
    //     } else if (w.CharInVec(guess[i], secret_word)) {
    //         std::cout << guess[i] << " passes yellow" << std::endl;
    //         std:: cout << (curr_map[guess[i]] < w.GetCountMap()[guess[i]]) << std::endl;
    //         std::cout << "curr map is " << curr_map[guess[i]] << std::endl;
    //         std::cout << "count map is " << w.GetCountMap()[guess[i]] << std::endl;
    //         //curr_map[guess[i]] = curr_map[guess[i]]++;
    //     } else {
    //         std::cout << guess[i] << " is gray" << std::endl;
    //     }
    // }
    
     return 0;
}
