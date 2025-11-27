#include<iostream>
#include<ctime>

char ComputerChoice();
char PlayerChoice();
void WinLoseDraw(char computer, char player);
std::string ShowChoice(char c);

int main()
{
    std::string player_repeat;
    char repeat;

    char computer;
    char player;

    srand(time(0));

    std::cout << "          ROCK, PAPER, SCISSORS\n";

    do
    {   
        player = PlayerChoice();
        computer = ComputerChoice();

        std::cout << "Player chose    : " << ShowChoice(player) << '\n';
        std::cout << "Computer chose  : " << ShowChoice(computer) << '\n';

        WinLoseDraw(computer, player);

        do{
            std::cout << "Do you want to play again? (y/n): ";
            std::cin >> player_repeat; 
            repeat = toupper(player_repeat[0]);
        }while(repeat != 'Y' && repeat != 'N');
    }while(repeat == 'Y');

    std::cout << "Thanks for playing!";

    return 0;
}

char ComputerChoice() 
{
    int num = rand() % 3 ;
    const char choices[3] = {'R', 'P', 'S'};
    return choices[num];
}

char PlayerChoice()
{
    std::string player_input;
    while(true)
    {
        std::cout << "*******************************************\n";
        std::cout << "R - Rock   |   P - Paper   |   S - Scissors\n";
        std::cout << "\nYour choice: ";
        
        std::cin >> player_input;

        if (player_input.length() == 1)
        {
            char input = toupper(player_input[0]);
            if (input == 'R' || input == 'P' || input == 'S') return input;
        }
        std::cout << "input invalid! Try Again!\n";
    }
}

void WinLoseDraw(char computer, char player)
{
    if (computer == player)
    {
        std::cout << "IT'S A DRAW!\n";
    }
    else if ((computer == 'R' && player == 'P') ||
             (computer == 'P' && player == 'S') ||
             (computer == 'S' && player == 'R'))
    {
        std::cout << "YOU WIN!\n";
    }
    else
    {
        std::cout << "YOU LOSE!\n";
    }
}

std::string ShowChoice(char c)
{
    if (c == 'R') return "Rock";
    if (c == 'P') return "Paper";
    return "Scissors";
}