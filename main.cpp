/*
 * Main.cpp
 * Main cpp file for initiating
 * program
 * 
*/
#include "header.hpp"
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

int main()
{
        do{
        system("clear");
        hangMan game;
        //game.display_intro();
        game.run();

        //insert a reloading game

    }while(again());

    return 0;
}