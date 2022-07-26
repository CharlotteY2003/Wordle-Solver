#ifndef WORDLE_HPP
#define WORDLE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <fstream>

class Wordle {
    public:
        Wordle();
        Wordle(std::string secret_word);
        void ConvertToVec(std::string input);
        void CheckGuess(std::string input);
        bool CharInVec(char letter, std::vector<char> vec);
        bool StringInVec(std::string word, std::vector<std::string> vec);
        void AddGreen(int index);
        void AddYellow(int index);
        void AddGray(int index);
        void AddArray(std::vector<char>& vec, int size, int index);
        bool IsRealWord(std::string input);
        std::vector<char> GetGreen();
        std::vector<char> GetYellow();
        std::vector<char> GetGray();
        std::vector<char> GetSecretWord();
        std::map<const char, int> GetCountMap();
        void ResetDesign();
        std::vector<char> getGuess();
        //void ToCSV(std::string file);
        std::vector<std::string> GetWords();
        
    private:
        std::vector<char> secret_word;
        std::vector<std::string> words;
        std::vector<char> guess = {'_', '_', '_', '_', '_'};
        std::map<const char, int> count_map;
        int total_guesses = 0;
        std::vector<char> green = {'_', '_', '_', '_', '_'};
        std::vector<char> yellow = {'_', '_', '_', '_', '_'};
        std::vector<char> gray = {'_', '_', '_', '_', '_'};
        
        
};
#endif