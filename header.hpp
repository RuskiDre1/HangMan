/*
 * Header.h
 * Main header file for function
 * definitions
 * 
*/
#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class hangMan
{
    public:
        hangMan();
        ~hangMan();
    
        int run();
        void display_intro();
        int random_gen();
        int insert_words();
        int run_stand(bool act);
        int lose_check();
        int word_selector();
        int run_improper();
        int run_improper(char);
        int run_question();

    protected:
        int insert_words(vector<string>& vect);
        vector<string> vect;
        vector<char> error;
        vector<char>right;
        char * word_char = NULL;
        int guess = 0;
        string word;
};

bool again();   // Function to repeat again

/*******/
