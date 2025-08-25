#include <iostream>
#include <ctime>
#include <limits>
using std::cout, std::cin, std::string, std::endl;

void drawBoard(char *spaces);
void firstPlayerMove(char *spaces, char player);
void secondPlayerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkPvsP(char *spaces, char firstPlayer, char secondPlayer);
bool checkPvsC(char *spaces, char firstPlayer, char computer);
bool checkTie(char *spaces);
int gameChoise();
char symbolChoise();

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char firstPlayer;
    char secondPlayer;
    char computer;
    bool running = true;
    int gameMode;

    cout << "\n***** Welcome to the game of Tick Tak toe! ******" << endl;
    gameMode = gameChoise();
    firstPlayer = symbolChoise();
    
    (firstPlayer == 'X') ? secondPlayer = 'O': secondPlayer = 'X';
    computer = secondPlayer;

    if(gameMode == 1){
        drawBoard(spaces);
        do{
            firstPlayerMove(spaces, firstPlayer);
            drawBoard(spaces);
    
            if (checkPvsC(spaces, firstPlayer, computer))
            {
                cout << "\nThanks for playing!" << endl;
                running = false;
                break;
            }
            else if(checkTie(spaces)){
                cout << "\nThanks for playing!" << endl;
                running = false;
                break;
            }
            
            computerMove(spaces, computer);
            drawBoard(spaces);
    
            if (checkPvsC(spaces, firstPlayer, computer))
            {
                cout << "\nThanks for playing!" << endl;
                running = false;
                break;
            }
            else if(checkTie(spaces)){
                cout << "\nThanks for playing!" << endl;
                running = false;
                break;
            }
        }while(running);
    }else{
        drawBoard(spaces);
        do{
            firstPlayerMove(spaces, firstPlayer);
            drawBoard(spaces);
    
            if (checkPvsP(spaces, firstPlayer, secondPlayer))
            {
                cout << "\nThanks for playing!" << endl;
                running = false;
                break;
            }
            else if(checkTie(spaces)){
                cout << "\nThanks for playing!" << endl;
                running = false;
                break;
            }
            
            secondPlayerMove(spaces, secondPlayer);
            drawBoard(spaces);
    
            if (checkPvsP(spaces, firstPlayer, secondPlayer))
            {
                cout << "\nThanks for playing!" << endl;
                running = false;
                break;
            }
            else if(checkTie(spaces)){
                cout << "\nThanks for playing!" << endl;
                running = false;
                break;
            }
        }while(running);
    }


    return 0;
}

void drawBoard(char *spaces)
{

    // Local Board

    cout << "\n";
    cout << "     |     |     " << "\n";
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << "\n";
    cout << "_____|_____|_____" << "\n";
    cout << "     |     |     " << "\n";
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << "\n";
    cout << "_____|_____|_____" << "\n";
    cout << "     |     |     " << "\n";
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << "\n";
    cout << "     |     |     " << "\n";
    cout << "\n";

    // Online board

    // cout << "\n";
    // cout << "     |     |     " << "\n";
    // cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << "\n";
    // cout << "     |     |     " << "\n";
    // cout << "------------------" << "\n";
    // cout << "     |     |     " << "\n";
    // cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << "\n";
    // cout << "     |     |     " << "\n";
    // cout << "------------------" << "\n";
    // cout << "     |     |     " << "\n";
    // cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << "\n";
    // cout << "     |     |     " << "\n";
    // cout << "\n";
}

void firstPlayerMove(char *spaces, char player)
{
    int box;
    std::cout << "First player's turn!\n";

    while (true)
    {
        cout << "Enter position you want to mark (1-9): ";
        cin >> box;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Validate input range
        if (box < 1 || box > 9) {
            std::cout << "Invalid input. Please enter a number between (1-9).\n";
            continue;
        }

        box--; // Convert to 0-based index

        // Check if the space is empty
        if (spaces[box] == ' ') {
            spaces[box] = player;
            break;
        } else {
            std::cout << "That space is already taken. Try again.\n";
        }
    }
}

void secondPlayerMove(char *spaces, char player)
{
    int box;

    std::cout << "Second player's turn!\n";

    while (true)
    {
        std::cout << "Enter position you want to mark (1-9): ";
        std::cin >> box;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
 
        // Validate input range
        if (box < 1 || box > 9) {
            std::cout << "Invalid input. Please enter a number between (1-9).\n";
            continue;
        }

        box--; // Convert to 0-based index

        // Check if the space is empty
        if (spaces[box] == ' ') {
            spaces[box] = player;
            break;
        } else {
            std::cout << "That space is already taken. Try again.\n";
        }
    }
}

void computerMove(char *spaces, char computer)
{
    int box;
    bool checked = false;
    srand(time(0));
    box = (rand() % 9);
    cout << "Computer's turn!" << "\n";
    box--;
    do
    {
        if (spaces[box] != ' ')
        {
            box = (rand() % 9);
        }
        else
        {
            spaces[box] = computer;
            checked = true;
            cout << "Computer choose box #" << ++box << "\n";
        }
    } while (checked == false);
}

bool checkPvsP(char *spaces, char firstPlayer, char secondPlayer)
{
    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        cout << ((spaces[0] == firstPlayer)? "First Player won!" : "Second player won!\n");
        return true;
    }
    else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
        cout << ((spaces[3] == firstPlayer)? "First Player won!" : "Second player won!\n");
        return true;
    }
    else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
        cout << ((spaces[6] == firstPlayer)? "First Player won!" : "Second player won!\n");
        return true;
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
        cout << ((spaces[0] == firstPlayer)? "First Player won!" : "Second player won!\n");
        return true;
    }
    else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
        cout << ((spaces[1] == firstPlayer)? "First Player won!" : "Second player won!\n");
        return true;
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
        cout << ((spaces[2] == firstPlayer)? "First Player won!" : "Second player won!\n");
        return true;
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
        cout << ((spaces[0] == firstPlayer)? "First Player won!" : "Second player won!\n");
        return true;
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
        cout << ((spaces[2] == firstPlayer)? "First Player won!" : "Second player won!\n");
        return true;
    }
    else{
        return false;
    }
}

bool checkPvsC(char *spaces, char firstPlayer, char computer)
{
    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        cout << ((spaces[0] == firstPlayer)? "You won!" : "Computer won!");
        return true;
    }
    else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
        cout << ((spaces[3] == firstPlayer)? "You won!" : "Computer won!");
        return true;
    }
    else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
        cout << ((spaces[6] == firstPlayer)? "You won!" : "Computer won!");
        return true;
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
        cout << ((spaces[0] == firstPlayer)? "You won!" : "Computer won!");
        return true;
    }
    else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
        cout << ((spaces[1] == firstPlayer)? "You won!" : "Computer won!");
        return true;
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
        cout << ((spaces[2] == firstPlayer)? "You won!" : "Computer won!");
        return true;
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
        cout << ((spaces[0] == firstPlayer)? "You won!" : "Computer won!");
        return true;
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
        cout << ((spaces[2] == firstPlayer)? "You won!" : "Computer won!");
        return true;
    }
    else{
        return false;
    }
}

bool checkTie(char *spaces)
{
    for(int i = 0; i <= 8; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    cout << "It's a Tie!" << endl;
    return true;
}

int gameChoise(){
    int choise;
    cout << "Enter 1 to play against Computer and 2 to play against a friend: ";
    do{
        cin >> choise;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(choise != 1 && choise != 2){
            cout << "Invalid Input! Enter 1 or 2: ";
            continue;
        }

    }while(choise != 1 && choise != 2);
    return choise;
}

char symbolChoise(){
    int choise;
    cout << "Choose your symbol (1 or 2)\n";
    cout << "1. X\n";
    cout << "2. O\n";
    do{
        cin >> choise;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(choise != 1 && choise != 2){
            cout << "Invalid Input! Enter 1 or 2: ";
            continue;
        }
    }while(choise != 1 && choise != 2);

    return (choise == 1) ? 'X' : 'O';
}



