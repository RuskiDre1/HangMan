/*
 * hangMan.cpp
 * Main cpp file for defining functions for
 * header.h file
 * 
*/

#include "header.hpp"
#include "colors.hpp"
#include <cstdlib>


hangMan::hangMan(): guess(7)
{}
hangMan::~hangMan()
{
    //  vector clear
}
int hangMan::run_improper(char x)
{
    error.push_back(x);
    return 0;
}
int hangMan::run_improper()
{
    if(error.size() < 1 )
        return 1;
    for(char i : error)
        cout << i << " ";
    return 0;
}

int hangMan::run_stand(bool act)
{
    if(guess == 7)
    {
        cout << red_fg;
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
    }
    else if(guess == 6)
    {
        cout << red_fg;
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
    }
    else if(guess == 5)
    {
        cout << red_fg;
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<"  |   | \n";
        cout<<"      | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
    }
    else if(guess == 4)
    {
        cout << red_fg;
        cout    <<"  +---+ \n";
        cout    <<"  |   | \n";
        cout    <<"  O   | \n";
        cout    <<" /|   | \n";
        cout    <<"      | \n";
        cout    <<"      | \n";
        cout    <<" ========= \n";
    }
    else if(guess==3)
    {
    cout << red_fg;
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
    }                 
    else if(guess==2)
    {
        cout << red_fg;
        cout<<"  +---+ \n";
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<" /|\\  | \n";
        cout<<" /    | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
    }
    else if(guess==1)
    {
        cout << red_fg;
        cout<<"  +---+ \n" ;
        cout<<"  |   | \n";
        cout<<"  O   | \n";
        cout<<" /|\\  | \n";
        cout<<" / \\  | \n";
        cout<<"      | \n";
        cout<<" ========= \n";
    }
    cout << reset;
    return 0;
}
int hangMan::word_selector()
{
    int num = rand() % vect.size() + 1;     // v2 in the range 1 to 100
    
    /*cout << "selected is: " << num << endl << "size is " << vect[num-1].size() << endl
        << "word is: " << vect[num-1] << endl;
    */

    word = vect[num-1];
    int size = word.length();

    word_char = new char [size];

    return 0;
}
int hangMan::run_question()
{

    if(right.size() == word.length())
    {
        cout <<green_fg<<"WINNER WINNER CHICKEN DINNER ! ! !" <<reset<< endl;
        return 2;
    }
    for(char i : word)
    {   
        bool check = false;
        for(char x : right)
        {
            if(i == x)
                check = true;   
        }

        if(check)
            cout << " "<< i <<" ";
        else
            cout <<" _ ";
    }

    cout << green_fg << endl << "\nATTEMPTS: " << guess 
        << reset << red_fg << "\tINCORRECT: " << reset; run_improper();
    cout << endl << "Enter Guess: ";
    char x; cin >> x; x = toupper(x); cin.ignore(100, '\n');
    

    bool check = false;
    for(char i: word)
    {
        if(x == i)
        {
            right.push_back(x);
            check = true;  
        }
    }

    if (!check)
    {
        error.push_back(x);
        --guess;
        
    }
    if(guess < 1)
    {
        cout <<red_fg<<"LOSER LOSER LOSER ! ! !" <<reset<< endl;
    }    

    return 0;
}
int hangMan::run()
{
    insert_words();
    word_selector();
    int attempts = 0;
    bool win = false;
    do
    {
        system("clear");
        display_intro();
        run_stand(0);
        if(run_question() == 2)
            win = true;

    }while(guess > 0 && !win);
    
    return 0;
}
int hangMan::insert_words()
{
    if(insert_words(vect))
        return 0;
    return 1;
}

void hangMan::display_intro()
{
    cout << blue_fg;
    cout <<
    "##     ##  #########  ##     ##  #########  ##     ##  #########  ##     ## \n"
    "##     ##  ##     ##  ###    ##  ##         ###   ###  ##     ##  ###    ## \n"
    "##     ##  ##     ##  ## #   ##  ##         ## # # ##  ##     ##  ## #   ## \n"
    "#########  #########  ##  #  ##  ##   ####  ##  ## ##  #########  ##  #  ## \n"
    "##     ##  ##     ##  ##   # ##  ##     ##  ##     ##  ##     ##  ##   # ## \n"
    "##     ##  ##     ##  ##     ##  ##     ##  ##     ##  ##     ##  ##     ## \n"
    "##     ##  ##     ##  ##     ##  #########  ##     ##  ##     ##  ##     ## \n" << endl;
    cout << reset << endl;
    
}

int hangMan::insert_words(vector<string>& vect)
{
    vect.push_back("FLORIDA");
    vect.push_back("ALASKA");
    vect.push_back("CALIFORNIA");
    vect.push_back("IOWA");
    vect.push_back("OREGON");
    vect.push_back("Rhode Island");
    vect.push_back("TEXAS");
    vect.push_back("UTAH");
    vect.push_back("VERMONT");
    vect.push_back("VIRGINIA");
    vect.push_back("WASHINGTON");
    vect.push_back("WISCONSIN");
    vect.push_back("OREGON");
    vect.push_back("PENNSYLVANIA");
    vect.push_back("CONNECTICUT");
    



    /*cout << "QUICK DISPLAY" << endl;

    for (string x : vect)
        cout << x << " ";
    */
    

    return 0;
}

int hangMan::random_gen()
{
    return 0;
}

bool again()
{
    cout << "WOULD YOU LIKE TO PLAY AGAIN? (Y/N) : ";
    char ans;   cin >> ans; cin.ignore(100,'\n');
    if(toupper(ans) == 'Y')
        return true;
    return false;
}

