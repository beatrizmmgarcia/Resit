#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include "game.h"
using namespace std;

Pieces p1("        /\\     \n       |  |    \n       |  |    \n       |  |    \n       |  |    \n      /____\\      \n ", 0, 200);
Pieces p2("     |    |    \n      |    |    \n      |    |     \n      |____|      \n", 0, 100);
Pieces p3("     /|    |\\    \n    / |    | \\     \n   /__|____|__\\  \n  ", 0, 300);
Pieces p4("    /_\\/_\\   \n ", 0, 50);


int missing_pieces = 4, balance = 0;


void menu();




void open_ship()
{
    system("CLS");
    cout << "You are now on your ship! \n Your goal is to complete all the missing pieces in order to reach Mars! \nYou have " << missing_pieces << " more pieces to collect from the shop! The missing pieces are RED\nPress 9 to go to the MENU\n";
    int val;
    p1.output();
    p2.output();
    p3.output();
    p4.output();
    cin >> val;
    if (val == 9){
        menu();
    }
    if (missing_pieces == 0){
            system ("CLS");
            cout << "You're done" << endl;
            char ok {};
            cin >> ok ;
        }
}



void open_shop()
{

    system("CLS");
    cout << "You are now in the shop! Your balance is " << balance << ".\nIn order to win more money go play minigames.\nPress 9 to go to the MENU\n";
    if (p1.completed == 0)
        cout << p1.shape << "PRICE: " << p1.price << "\n PRESS 1 TO BUY\n\n";

    if (p2.completed == 0)
        cout << p2.shape << "PRICE: " << p2.price << "\n PRESS 2 TO BUY\n\n";

    if (p3.completed == 0)
        cout << p3.shape << "PRICE: " << p3.price << "\n PRESS 3 TO BUY\n\n";

    if (p4.completed == 0)
        cout << p4.shape << "PRICE: " << p4.price << "\n PRESS 4 TO BUY\n";

    int val;
    cin >> val;



    if (val == 1)
    {
        if (balance >= p1.price)
        {
            p1.completed = 1;
            cout << "You purchased piece no. 1\n";

            balance = balance - p1.price;
            missing_pieces = missing_pieces -1;
        }
        else
            cout << "YOU DON'T HAVE ENOUGH MONEY";
        cin >> val;
    }

    if (val == 2)
    {
        if (balance >= p2.price)
        {
            p2.completed = 1;
            cout << "You purchased piece no. 2\n";

            balance = balance - p2.price;
            missing_pieces = missing_pieces -1;
        }
        else
            cout << "YOU DON'T HAVE ENOUGH MONEY";
        cin >> val;
    }

    if (val == 3)
    {
        if (balance >= p3.price)
        {
            p3.completed = 1;
            cout << "You purchased piece no. 3\n";
            balance = balance - p3.price;
            missing_pieces = missing_pieces -1;
        }
        else
            cout << "YOU DON'T HAVE ENOUGH MONEY";
        cin >> val;
    }

    if (val == 4)
    {
        if (balance >= p4.price)
        {
            p4.completed = 1;
            cout << "You purchased piece no. 4\n";
            balance = balance - p4.price;
            missing_pieces = missing_pieces -1;
        }
        else
            cout << "YOU DON'T HAVE ENOUGH MONEY";
        cin >> val;
    }

    if (val == 9)
        menu();



}



//TICTACTOE Beggining

int diagonalCheck(int v[])
{
    if (v[1] == v[5] && v[5] == v[9])
        return v[1];
    if (v[3] == v[5] && v[3] == v[7])
        return v[3];
    return 0;
}

int horizontalCheck(int v[])
{
    if (v[1] == v[4] && v[4] == v[7])
        return v[1];
    if (v[2] == v[5] && v[5] == v[8])
        return v[2];
    if (v[3] == v[6] && v[6] == v[9])
        return v[3];
    return 0;
}

int verticalCheck(int v[])
{
    if (v[1] == v[2] && v[2] == v[3])
        return v[1];
    if (v[4] == v[5] && v[5] == v[6])
        return v[4];
    if (v[7] == v[8] && v[8] == v[9])
        return v[7];
    return 0;
}

void printTable(int v[])
{
    for (int i = 1; i <= 9; i++)
    {
        cout << v[i] << " | ";
        if (i % 3 == 0)
            cout << '\n' << "-----------" << '\n';
    }
}

void open_tictactoe()
{
    system("CLS");
    int p, comp, i, win = 0;
    int table[10];
    for (i = 1; i <= 9; i++)
        table[i] = 0;
    cout << "INSTRUCTIONS: \n You are no.1. The computer is no.2. \n In order to place your sign inside a box, press the number of the box. \n The numbering starts from 1 to 9. Left to right. Up to down. \n GOOD LUCK! \n \n ";
    printTable(table);


    while (win == 0)
    {
        cin >> p;
        table[p] = 1;

        system("CLS");
        printTable(table);


        do
        {
            comp = 1 + rand() % 9;
        } while (table[comp] != 0);

        table[comp] = 2;
        system("CLS");
        printTable(table);

      if (diagonalCheck(table) != 0)
            win = diagonalCheck(table);
        else
        {
            if (verticalCheck(table) != 0)
                win = verticalCheck(table);
            else
            {
                if (horizontalCheck(table) != 0)
                    win = horizontalCheck(table);
                else
                {
                    win = 3;
                }


            }
        }
    }


    if (win == 2 )
        {
        cout << "You Lost!" << endl;
        cout << "Your current balance is:" << balance << endl;
        cout << "1-Main Menu" << endl;
        cout << "2-Play Again" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            menu();
        }
        if (choice == 2) {
            open_tictactoe();
        }
   }

    if (win == 1)
    {

        system("CLS");

        cout << "You've won!"<<'\n';
        balance = (balance + 20);
        cout << "Your current balance is:" << balance << endl;
        cout << "1-Main Menu" << endl;
        cout << "2-Play Again" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            menu();
        }
        if (choice == 2) {
            open_tictactoe();
        }

    }

    if (win == 3)
    {

        system("CLS");

        cout << "You've both lost!"<<'\n';
        balance = (balance + 20);
        cout << "Your current balance is:" << balance << endl;
        cout << "1-Main Menu" << endl;
        cout << "2-Play Again" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            menu();
        }
        if (choice == 2) {
            open_tictactoe();
        }

    }


}

//END TICTACTOE



int open_hangman()
{
    system("CLS");
    char start{};
    cout << "   SPACE HANGMAN   " << endl;
    cout << " __________________" << endl;
    cout << " |         |       " << endl;
    cout << " |         *       " << endl;
    cout << " |         O      Guess the following " << endl;
    cout << " |         |      word and save yourself " << endl;
    cout << " |        /|\\     " << endl;
    cout << " |       / | \\        (10 credits) " << endl;
    cout << " |        / \\     " << endl;
    cout << " |       /   \\    " << endl;
    cout << " |                 " << endl;
    cout << " |_________________" << endl;
    cout << " Press Any Key To Begin" << endl;
    cin >> start;


    //VARIABLE DECLARATION

    int OPP{ 6 }; // NR OF OPPORTUNITIES
    string Wlist[49];
    string word;
    int RNum;
    char Letter;
    bool RLetter = false;


    //END OF VARIABLE DECLARATION

    //GENERATE WORD

    srand(time(NULL)); // Will randomly generate a seed
    ifstream RWord; // Variable reading
    RWord.open("RESIT.txt"); // Words will be picked from this File

    //CREATION OF A FOR LOOP THAT GOES THROUGH THE WHOLE LIST

    for (int i = 0; i < 49; i++) {
        RWord >> Wlist[i]; // "Transfers" the list of words to the array
                                                                                             // cout<< wordlist [i] << endl;
    }
    RNum = rand() % 50; // Generates a Random number from 0 - 49
    word = Wlist[RNum]; // Puts the Random num to the item of the array and uses it as word
                                                                                             // cout << word << endl;
    RWord.close(); // Memory Saving Purposes

    string HWord(word.length(), '*'); // Replacement of the letters with an asterisk
                                                                                              //cout<< HWord << endl;



    while (OPP >= 0) {
        RLetter = false;

        cout << HWord << endl;
        cout << "Number of Guesses Left:" << OPP << endl;
        cout << " Enter Letters to Discover The Hidden Word:";
        cin >> Letter;

        for (int i = 0; i < HWord.length(); i++) { // Goes through the whole word
            if (word[i] == Letter) {  //If found in any position of the word
                HWord[i] = Letter; // Exchanges asterisk with the actual letter
                RLetter = true;
            }
        }
        if (word == HWord) {
            system("CLS");
            cout << "You've Found The Right Word! \n" << HWord << endl;
            balance = (balance + 10);
            cout << "Your current balance is:" << balance << endl;
            cout << "1-Main Menu" << endl;
            cout << "2-Play Again" << endl;
            int choice;
            cin >> choice;
            if (choice == 1) {
                menu();
            }
            if (choice == 2) {
                open_hangman();
            }
            break;

        }
        if (RLetter == false) {
            OPP = OPP - 1;
            cout << "Wrong Guess" << endl;
        }
        switch (OPP) {
        case 6: {
            cout << " __________________" << endl;
            cout << " |         |       " << endl;
            cout << " |         *       " << endl;
            cout << " |                 " << endl;
            cout << " |                 " << endl;
            cout << " |                 " << endl;
            cout << " |                 " << endl;
            cout << " |                 " << endl;
            cout << " |                 " << endl;
            cout << " |                 " << endl;
            cout << " |_________________" << endl;

            break;
        }


        case 5: {
            cout << " __________________" << endl;
            cout << " |         |       " << endl;
            cout << " |         *       " << endl;
            cout << " |         O       " << endl;
            cout << " |                 " << endl;
            cout << " |                 " << endl;
            cout << " |                 " << endl;
            cout << " |                 " << endl;
            cout << " |                 " << endl;
            cout << " |                 " << endl;
            cout << " |_________________" << endl;

            break;
        }


        case 4: {
            cout << " __________________" << endl;
            cout << " |         |       " << endl;
            cout << " |         *       " << endl;
            cout << " |         O       " << endl;
            cout << " |         |       " << endl;
            cout << " |         |       " << endl;
            cout << " |         |       " << endl;
            cout << " |                 " << endl;
            cout << " |                 " << endl;
            cout << " |                 " << endl;
            cout << " |_________________" << endl;

            break;
        }


        case 3: {
            cout << " __________________" << endl;
            cout << " |         |       " << endl;
            cout << " |         *       " << endl;
            cout << " |         O       " << endl;
            cout << " |         |       " << endl;
            cout << " |         |\\     " << endl;
            cout << " |         | \\    " << endl;
            cout << " |                 " << endl;
            cout << " |                 " << endl;
            cout << " |                 " << endl;
            cout << " |_________________" << endl;

            break;
        }


        case 2: {
            cout << " __________________" << endl;
            cout << " |         |       " << endl;
            cout << " |         *       " << endl;
            cout << " |         O       " << endl;
            cout << " |         |       " << endl;
            cout << " |        /|\\     " << endl;
            cout << " |       / | \\    " << endl;
            cout << " |                 " << endl;
            cout << " |                 " << endl;
            cout << " |                 " << endl;
            cout << " |_________________" << endl;

            break;
        }


        case 1: {
            cout << " __________________" << endl;
            cout << " |         |       " << endl;
            cout << " |         *       " << endl;
            cout << " |         O       " << endl;
            cout << " |         |       " << endl;
            cout << " |        /|\\     " << endl;
            cout << " |       / | \\    " << endl;
            cout << " |          \\     " << endl;
            cout << " |           \\    " << endl;
            cout << " |                 " << endl;
            cout << " |_________________" << endl;

            break;
        }


        case 0: {
            cout << " __________________" << endl;
            cout << " |         |       " << endl;
            cout << " |         *       " << endl;
            cout << " |         O       " << endl;
            cout << " |         |       " << endl;
            cout << " |        /|\\     " << endl;
            cout << " |       / | \\    " << endl;
            cout << " |        / \\     " << endl;
            cout << " |       /   \\    " << endl;
            cout << " |                 " << endl;
            cout << " |_________________" << endl;

            OPP = -1; // Buffer in case something goes wrong
            cout << "You've Lost" << endl;
            cout << "1- Menu" << endl;
            cout << "2- Try again" << endl;
            int choice;
            cin >> choice;
            if (choice == 1) {
                menu();
            }
            if (choice == 2) {
                open_hangman();
            }
            if (choice != 1 || choice != 2) {
                cout << "Error: Going back to main menu" << endl;
                menu();
            }
            break;

        }

        }

    }
    return 0;


}





void open_memory()
{
    system("CLS");
    char ok{};
    int x = 0, a = 0, p=0;
    cout << "Remember the set of digits and type it after it disappears. For every digit you earn 3 points. GOOD LUCK!\n";
    cin >> ok;
    system ("CLS");

    while (a == x)
    {
        x=x*10+ rand() % 9;
        cout << x;
        Sleep(700);
        system("CLS");
        cout << "Type what you remember" << '\n';
        cin >> a;
        if (x == a)
        {
            cout << "Perfect!Get ready for the next one!\n";
            p++;

        }
        Sleep(700);
        system("CLS");
    }

    cout << "WRONG! The sequence was " << x << '\n' << "You won " << p * 3 << '\n';
    balance = balance + p * 3;
    cout << "Your balance is now " << balance<<'\n';
    cout << "1-Main Menu" << endl;
    cout << "2-Play Again" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        menu();
    }
    if (choice == 2) {
        open_memory();
    }


}





void open_minig()
{

    system("CLS");
    cout << "                         ------------------" << endl;
    cout << "                           MINIGAMES AREA" << endl;
    cout << "      ---------------------------------------------------------" << endl;
    cout << "       In order to win more money you must play the MiniGames" << endl;
    cout << "                    -----------------------------" << endl;
    cout << "                       Press 1 for TIC TAC TOE" << endl ;
    cout << "                         Press 2 for HANGMAN " << endl ;
    cout << "                       Press 3 for Memory Test" << endl;
    cout << "                      Press 9 to go to the MENU\n" << endl;
    int val;
    cin >> val;
    if (val == 9)
        menu();
    else
    {
        if (val == 1)
            open_tictactoe();
        else
        {
            if (val == 2)
                open_hangman();
            else {
                if (val == 3)
                    open_memory();
            }
        }
    }
}





void open_instructions()
{
    system("CLS");
    cout << "                                             Instructions" << endl;
cout<< "                You've just crashed, you lost everything on the trip, including all of your money"<< endl;
cout << "       Throughout the adventure you'll have to play minigames in order to buy your ship parts from the aliens." << endl;
cout << "                                 Complete the 4 parts and you'll be home soon." << endl;
cout<< " 1- Menu" << endl;
int y;
cin >> y;
if (y== 1){
    menu();
}
if (y != 1){
    cout << "Error, wrong command " << endl;

}
}





class beggining {
public :
    void text (){
        char ok {};
    cout << "                                                  SPACE ESCAPE" << endl;
    cout << "          The year is 3005, you were doing zone recognition when your ship broke completely down." << endl;
    cout << "                   Your only solution is to work to fix the ship. You are given options; " << endl;
    cout << "                 You can either play the minigames or accept the deals natives will offer.  " << endl;
    cout <<"                                              Good Luck on your journey" << endl;
    cout << "Press any key to begin" << endl;
    cin >> ok;
    menu();
    }
};





  class RPS{
    public :
    void Alien_Game(){

    srand (time(NULL));
    int BOT = rand () % 3 + 1;
    int USER = 0;
    string USER_OPTION;
    string BOT_OPTION;
    char ok{};
    cout << " 1-Rock \n 2-Paper \n 3-Scissors" <<endl;

    cin >> USER;

       if (USER == 1){
        USER_OPTION = "Rock";
    }
       if (USER == 2){
        USER_OPTION = "Paper";
    }
       if (USER == 3){
        USER_OPTION = "Scissors";
    }
       if (BOT == 1){
        BOT_OPTION = "Rock";
    }
       if (BOT == 2){
        BOT_OPTION = "Paper";
    }
       if (BOT == 3){
        BOT_OPTION = "Scissors";
    }




    if ( USER == BOT ){
        cout << "You chose " << USER_OPTION << ", and I chose " << BOT_OPTION << " so that means it's a draw \n Let's play again!" << endl;
         cin >> ok;
        system ("CLS");
        Alien_Game();


    }
    if (USER == 1 && BOT == 3){
        cout << "You chose " << USER_OPTION << ", And I chose " << BOT_OPTION << ", So that means you win \n " << endl;
        int coins = (balance/3);
        balance = balance + coins;
        cout << "Take your " << coins << " coins... \n You now have " << balance << " coins" << endl;
        cin >> ok;
        menu ();
    }

    if (USER == 2 && BOT == 1){
        cout << "You chose " << USER_OPTION << ", And I chose " << BOT_OPTION << ", So that means you win \n " << endl;
        int coins = (balance/3);
        balance = balance + coins;
        cout << "Take your " << coins << " coins... \n You now have " << balance << ", coins" << endl;
        cin >> ok;
        menu ();
    }

    if (USER == 3 && BOT == 2){
        cout << "You chose " << USER_OPTION << ", And I chose" << BOT_OPTION << ", So that means you win \n " << endl;
        int coins = (balance/3);
        balance = balance + coins;
        cout << "Take your " << coins << " coins... \n You now have " << balance << ", coins" << endl;
        cin >> ok;
        menu ();
    }
    else {
        cout << "You chose " << USER_OPTION << ", And I chose" << BOT_OPTION << ", So that means I win!!! \n " << endl;
        int coins = balance/2;
        balance = balance - coins;
        cout << "Give me your " << coins << " coins... \n You now have " << balance << ", coins" << endl;
        cin >> ok;
        menu ();

    }

    }
    };






class chances {
public:
    void first_alien(){


        system("CLS");
        char ok{};
        cout << "             ,-     -.                     " << endl;
        cout << "            / o       o \\                 " << endl;
        cout << "           /   \     /   \\                " << endl;
        cout << "          /     )-:-(     \\               " << endl;
        cout << "         /     ( 6 6 )     \\              " << endl;
        cout << "        /      \\ : /       \\             " << endl;
        cout << "       /         )=(         \\               Congratulations!       " << endl;
        cout << "      /   o   .--:-:--.   o   \\            You've reached 30 coins      " << endl;
        cout << "     /    I  /  -   -  \\  I    \\          I know how hard it can get, " << endl;
        cout << " .--(    (_}y/\\       /\\y{_)    )--.       so I'm offering you    " << endl;
        cout << "(    :.___l\\/__\\_____/__\\/l___,:  )       20 more for an headsup! " << endl;
        cout << " \\                                /       " << endl;
        cout << "  :-._      o O o O o O o      _,-:        " << endl;
        cout << "      `--\\--.___________.--/--'           " << endl;
        cout << "         |==.___________.==|               " << endl;
        cout << "         `==.___________.=='               " << endl;

        cout << "Press any key to accept" << endl;
        balance = balance + 20;
        cin >> ok;
        menu();


        }




        void second_alien(){

            system ("CLS");

        cout << "             (o)    (o)            " << endl;
        cout << "               \\    /             " << endl;
        cout << "      /\\       \\  /              " << endl;
        cout << "      ||         ----                     200 coins ugh..." << endl;
        cout << "      ||        /(o) \\                I'll give you to choose " << endl;
        cout << "      ||       (  <   )             You can either Rock, Paper, Scissors me " << endl;
        cout << "      ||       \\ -- /           and if you win I'll give you 1/3 of what you " << endl;
        cout << "   /|_||_|\\__(--====--)                      have already,  " << endl;
        cout << "     (|_______\\======/\\ \\[[/   but if you lose, I'm taking 1/2 of what you have." << endl;
        cout << "      ||         (--) \\ \\/ /     Or you can just run with what you have, and " << endl;
        cout << "                 /  \\  \\_-/      win your ship money with the small games. " << endl;
        cout << "                |====|                        So what'll be? " << endl;
        cout << "               (  /\\  )           " << endl;
        cout << "                |  )(  |            " << endl;
        cout << "                [  ][  ]            " << endl;
        cout << "                _||  ||_            " << endl;
        cout << "               (   ][   )           " << endl;


        int alien;
        cout << "Press 1 to go back to menu or 2 to accept" << endl;
        cin >> alien;
        if (alien == 1) {
            menu();
        }
        if (alien == 2) {
             RPS beg;
            beg.Alien_Game();
        }

    }




        void third_alien(){

            system ("CLS");
            char ok {};
            int flip;

       cout << "         .--.   |V|       " << endl;
       cout << "        /    \\ _| /      " << endl;
       cout << "        q .. p \\ /      I see you are almost buying the last piece of your ship " << endl;
       cout << "         \--/  //            I hate to say this, but I'm the decider.  " << endl;
       cout << "        __||__//     I'm going to flip a coin, if its Heads, I'm taking half of what you have, " << endl;
       cout << "       /.    _/                  if its tails... well, I'll just let you live " << endl;
       cout << "      // \\  /            " << endl;
       cout << "     //   ||              " << endl;
       cout << "     \\  /  \\            " << endl;
       cout << "      )\|    |            " << endl;
       cout << "     / || || |            " << endl;
       cout << "    |/\\| || |            " << endl;
       cout << "        | || |            " << endl;
       cout << "        \ || /            " << endl;
       cout << "      __/ || \\__         " << endl;
       cout << "    \\____/\____/         " << endl;

         cin >> ok ;
         flip = rand() % 2;
         if (flip == 1){
            cout << "well.. heads, you know what it means" << endl;;
         balance = balance - (balance/2);
         cin >> ok;
         cout << "I hope you have a better luck next time we encounter" << endl;
         cout << "You now have " << balance << " coins" << endl;
         cin >> ok;
         menu();
         }

         if (flip == 2){
            cout << "So lucky... Just move along" << endl;
            cin >> ok;
            menu();
         }
        }

};







void menu()
{
     if (missing_pieces == 0){
            system ("CLS");
            cout << "You're done" << endl;
            char ok {};
            cin >> ok ;
        }

    if (balance == 30){
       chances stops;
       stops.first_alien();
    }

    if (balance == 200){
       chances stops;
       stops.second_alien();
    }

    if (balance == 300){
     chances stops;
       stops.third_alien();
    }


    system("CLS");
    int value;
    cout << "       ------------------------------\n" << endl;
    string a = "          Press 1 for SHIP\n          Press 2 for SHOP\n          Press 3 for MINIGAMES\n          Press 4 for INSTRUCTIONS\n\n";
    cout << a;
    cout << "       ------------------------------" << endl;
    cin >> value;
    if (value == 1)
        open_ship();
    else
    {
        if (value == 2)
            open_shop();
        else
        {
            if (value == 3)
                open_minig();
                else
                    {
                    if (value == 4)
                    open_instructions();
                    else
                    {
                    cout << "UNRECOGNISED COMMAND! WARNING! PLEASE INSERT 1,2 OR 3!";
                    }

                    }
        }
    }



}







int main() {


    beggining start;
    start.text();




    return 0;
}



