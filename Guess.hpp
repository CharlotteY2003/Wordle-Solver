#ifndef GUESS_HPP
#define GUESS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <utility>  
#include "wordle.hpp"
//#include "wordle.cc"

class Guess {
    //take average and worst case scenerio of all attempts per guess in each secret word (3 cases per guess)
    public:
        Guess(std::vector<std::string> guess_pool, std::vector<std::string> secret_pool);
        std::pair<std::string, std::pair<int, double>> FindBestGuess(std::vector<std::string> guess_pool, std::vector<std::string> secret_pool);
        std::pair<int, double> AttemptsPerGuess(std::string guess);
        std::vector<std::string> FindMinWorst();
        std::vector<std::string> NarrowDownVector(std::vector<std::string> secret_pool);
        bool MatchesGray(std::string input);
        bool MatchesGreen(std::string input);
        bool MatchesYellow(std::string input);
        int GetNumberOfSteps(std::vector<std::string> guess_pool, std::string guess, std::string secret, std::vector<std::string> secret_pool);
        bool inVector(std::string obj, std::vector<std::string> vec);
    private:
        Wordle w;
        std::vector<std::string> guess_pool_;
        std::vector<std::string> secret_pool_;
        //std::map<std::string, std::pair<int, double>> record_; //guess - worst, average
    
};
#endif