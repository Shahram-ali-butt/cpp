#include <iostream>
#include <vector>
#include <limits>
using std::cout, std::cin, std::string, std::endl, std::vector;

void game(vector<string> &questions, vector<vector<string>> &options, vector<char> &key);
void createQuestion(vector<string> &questions, vector<vector<string>> &options, vector<char> &key);

int main(){
    vector<string> questions = {"1. How many days are there in a week? ", 
        "2. How long is a solar cycle? ",
        "3. Which is the largest ocean on Earth? ",
        "4. Did we land on the moon? ",
        "5. Is Earth flat? "};
        
        vector<vector<string>> options = {{"A. 4", "B. 5", "C. 6", "D. 7"},   
        {"A. 356 Days", "B. 365 Days", "C. 366 Days", "D. 376 Days"},
        {"A. Pacific ocean", "B. Indian ocean", "C. Arctic ocean", "D. Atlantic ocean"}, 
        {"A. Yes", "B. No", "C. Maybe", "D. In a movie"},
        {"A. Yes", "B. sometimes", "C. Maybe", "D. Nasa would kill me!"}};
        
        vector<char> key = {'D', 'B', 'A', 'A', 'A'};
    
        char start;
    
    cout << "**  Welcome to the quiz game!  **" << endl;
   
    do{
        cout << "Enter s to start and q to quit: ";
        cin >> start;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (start == 's'){
            game(questions, options, key);
       
        }else if(start == 'q'){
            cout << "You've decided to quit!" << endl;
        }else if(start == 'x'){
            cout << "You've entered the special character to enter a new question!" << endl;
            createQuestion(questions,options,key);
        }else{
            cout << "Invalid input! Try again" << endl;
        }

    }while(start != 's' && start!= 'q');
   
    return 0;
}

void game(vector<string> &questions, vector<vector<string>> &options, vector<char> &key){
    char guess;
    int score = 0;

    int rowsize = (options).size();
    int questionsize = (questions).size();                      
    int colsize = (options)[0].size();

    for(int i = 0; i < questionsize; i++){
        cout << (questions)[i] << endl;
        for(int j = 0; j < colsize; j++){
            cout << (options)[i][j] << endl;
        }
        cout << "Enter your answer (A-D): ";
        cin >> guess;
        guess = toupper(guess);
        if(guess == (key)[i]){    
        cout <<  "Correct!" << endl; 
        score++;    
        }else if(guess!= 'A' && guess!= 'B' && guess!= 'C' && guess!= 'D'){
            cout << "Invalid Input! 1 score would be deducted" << endl;
            score--;
        }else{
            cout << "Wrong! Correct answer was " << (key)[i] << endl;
        }
        cout << "*****************************" << endl;
    }
    
    cout << "********    Result   ********" << endl;
    cout << "Your score is: " << score << " out of " << questionsize << endl;
    cout << "*****************************" << endl;
}

void createQuestion(vector<string> &questions, vector<vector<string>> &options, vector<char> &key){    
    string newquestion;
    string option1, option2, option3, option4;
    vector<string> newRow;
    char newkey;

    cout << "Enter the new question: " << endl;
    cout << "Enter " << ((questions).size() + 1) << ". before the question" << endl; 
    std::getline(cin, newquestion);
    questions.push_back(newquestion);
    
    cout << "Enter the option 1 (Do wrte A.): " << endl;
    std::getline(cin, option1);
    cout << "Enter the option 2 (Do wrte B.): " << endl;
    std::getline(cin, option2);
    cout << "Enter the option 3 (Do wrte C.): " << endl;
    std::getline(cin, option3);
    cout << "Enter the option 4 (Do wrte D.): " << endl;
    std::getline(cin, option4);

    newRow = {option1, option2, option3, option4};
    cout << "Review the options you added. You would be required to specify the correct one." << endl;
    for(string option : newRow){
        cout << option << endl;
    }
    
    options.push_back(newRow);

    cout << "Specify the correct option (A-D): ";
    cin >> newkey;
    newkey = toupper(newkey);
    key.push_back(newkey);

    cout << (questions).back() << endl;
    cout << "You've added the question successfuly!" << endl;
    cout << "**************************************" << endl;
}