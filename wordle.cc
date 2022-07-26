#include "wordle.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <stdlib.h>
#include <fstream>


Wordle::Wordle() {
    std::ifstream ifs{"corncob5.txt"};
    
    for (std::string line; std::getline(ifs, line); line = '\n') {
        words.push_back(line);
    }
    
    int index = rand() % words.size();
    ConvertToVec(words[index]);
    
    for (int i = 0; i < 5; i++) {
        if (count_map.count(secret_word[i]) > 0) {
            count_map[secret_word[i]] = count_map[secret_word[i]]++;
        } else {
            count_map[secret_word[i]] = 1;
        }
    }
 }
Wordle::Wordle(std::string word) {
    std::ifstream ifs{"corncob5.txt"};
    
    for (std::string line; std::getline(ifs, line); line = '\n') {
        words.push_back(line);
    }
    
    ConvertToVec(word);
    //initialize count map
    for (int i = 0; i < 5; i++) {
        if (count_map.count(secret_word[i]) > 0) {
            count_map[secret_word[i]] = count_map[secret_word[i]] + 1;
        } else {
            count_map[secret_word[i]] = 1;
        }
    }
}
void Wordle::ConvertToVec(std::string input) {
    char arr[input.length()]; //can change to 5
    strcpy(arr, input.c_str());
    for (size_t i = 0; i < 5; i++) {
        secret_word.push_back(arr[i]);
    }
}
void Wordle::CheckGuess(std::string input) {
    //std::cout << green[0] << std::endl;
    // char arr[input.length()]; //can change to 5
    // strcpy(arr, input.c_str());
    // for (size_t i = 0; i < arr.size(); i++) {
    //     guess.push_back(arr[i]);
    // }
    
    // guess should already be a real word and initialized
    
    std::vector<char> vec; //delete chunk later
    char arr[input.length()];
    strcpy(arr, input.c_str());
    for (size_t i = 0; i < 5; i++) {
        //guess.push_back(arr[i]);
        guess[i] = arr[i];
    }
    
    std::map<const char, int> curr_map;
    
    for (int i = 0; i < 5; i++) {
        if (curr_map.count(guess[i]) > 0) {
            curr_map[guess[i]] = curr_map[guess[i]] + 1;
        } else {
            curr_map[guess[i]] = 1;
        }
        //std::cout << "index i : " << i << " " << curr_map.count('e') << std::endl;
    }
    
    // std::cout << curr_map['e'] << std::endl;
    // std::cout <<count_map['e'] << std::endl;
    
    for (int i = 0; i < 5; i++) {
        if (guess[i] == secret_word[i]) {
            //AddGreen(i);
            AddArray(green, 5, i);
        } else if (CharInVec(guess[i], secret_word) && curr_map[guess[i]] <= count_map[guess[i]]) {
            //AddYellow(i);
            AddArray(yellow, 5, i);
            curr_map[guess[i]] = curr_map[guess[i]] + 1;
        } else {
            //AddGray(i);
            AddArray(gray, 5, i);
        }
    }
}

bool Wordle::CharInVec(char letter, std::vector<char> vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        if (letter == vec[i]) {
            return true;
        }
    }
    return false;
}
void Wordle::AddGreen(int index) {
    green[index] = guess[index];
}
void Wordle::AddYellow(int index) {
    yellow[index] = guess[index];
}
void Wordle::AddGray(int index) {
    gray[index] = guess[index];
}

bool Wordle::IsRealWord(std::string input) {
    if (!StringInVec(input, words)) {
        return false;
    }
    
    std::vector<char> vec;
    char arr[input.length()];
    strcpy(arr, input.c_str());
    for (size_t i = 0; i < 5; i++) {
        //guess.push_back(arr[i]);
        guess[i] = arr[i];
    }
    // for (int i = 0; i < 5; i++) {
    //     if (!CharInVec(guess[i], words)) { //changed
    //         return false;
    //     }
    // }
    return true;
}

std::vector<char> Wordle::GetGreen() {
    return green;
}

std::vector<char> Wordle::GetYellow() {
    return yellow;
}

std::vector<char> Wordle::GetGray() {
    return gray;
}

std::vector<char> Wordle::GetSecretWord() {
    return secret_word;
}

void Wordle::ResetDesign() {
    green = {'_', '_', '_', '_', '_'};
    yellow = {'_', '_', '_', '_', '_'};
    gray = {'_', '_', '_', '_', '_'};
    guess = {'_', '_', '_', '_', '_'};
}

std::map<const char, int> Wordle::GetCountMap() {
    return count_map;
}

std::vector<std::string> Wordle::GetWords() {
    return words;
}

bool Wordle::StringInVec(std::string word, std::vector<std::string> vec) {
    //std::cout << vec[0] << "=" << word << std::endl;
    // std::cout << vec[0].length() << std::endl;
    // std::cout << vec[0].substr(0,5) << std::endl;
    // std::cout << vec[0] << std::endl;
    for (int i = 0; i < (int) vec.size(); i++) {
        
        vec[i] = vec[i].substr(0,5);
        //std::cout << vec[i] << std::endl;
        // std::cout << vec[i] << std::endl;
       
        if (vec[i] == word) {
            return true;
        }
    }
    return false;
}

void Wordle::AddArray(std::vector<char>& vec, int size, int index) {
    vec[index] = guess[index];
}

 std::vector<char> Wordle::getGuess() {
     return guess;
 }