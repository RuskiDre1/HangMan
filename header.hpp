/*
 * Header.h
 * Main header file for function
 * definitions
 * 
*/
#include <iostream>
#include <string>
using namespace std;

class hangMan
{
    public:
        hangMan();
        ~hangMan();
    
        int run();
        int display_intro();
        int random_gen();



    protected:
    

};

bool again();   // Function to repeat again