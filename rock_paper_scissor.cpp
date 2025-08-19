#include <iostream>
#include <ctime>
using namespace std;

char getUserChoice(void);
char getComputerChoice(void);
char getWinner(char player, char computer);

int main() {
	int userPoints = 0;
	int compPoints = 0;


	cout << "Welcome to Rock Paper scissors Game" << endl;
	cout << "score 10 points to win" << endl;

	while(userPoints < 5 && compPoints < 5) {

		char player = getUserChoice();
		char computer = getComputerChoice();

		char result = getWinner(player, computer);

		if(result == 'u') {
			userPoints += 1;
		} else if(result == 'c') {
			compPoints += 1;
		}

        cout << "Your score: " << userPoints << " | Computer score: " << compPoints << endl;
        cout << "***********************************" << endl;
	}
	
	if (userPoints == 5) {
        cout << "🎉 You Win the Game!" << endl;
    } else {
        cout << "💻 Computer Wins the Game. Better luck next time!" << endl;
    }
	cout << "***********************************" << endl;

	return 0;
}

char getUserChoice(void) {
	char user;
	do {
		cout << "Enter your choice: " << endl;
		cout << "r for rock" << endl;
		cout << "p for paper" << endl;
		cout << "s for scissors" << endl;
		cin >> user;
		if(user!='r' && user!='p' && user!='s') {
			cout << "Enter either 'r', 'p' or 's'" << endl;
		}
	} while(user!='r' && user!='p' && user!='s');

	return user;
}

char getComputerChoice(void) {
	int num;
	char comp;
	srand(time(0));
	num = rand() % 3 + 1;
	switch(num) {
	case 1:
		return 'r';
	case 2:
		return 'p';
	case 3:
		return 's';
	default:
		return 'r';
	}
}

char getWinner(char player, char computer) {
    cout << "You chose: " << player << ", Computer chose: " << computer << endl;
    
	if(player == computer) {
		cout << "It's a draw!" << endl;
		return 'x';
	}
	else if(player == 'r' && computer == 'p' || 
	        player == 'p' && computer == 's' || 
	        player == 's' && computer == 'r'){
		cout << "1 point for Computer" << endl;
		return 'c';
	}
	else if(player == 'r' && computer == 's' ||
	        player == 'p' && computer == 'r' ||
	        player == 's' && computer == 'p'){
		cout << "1 point for You!" << endl;
		return 'u';
	}else {
		cout << "Undefined Result" << endl;
		return 'y';
	}
}

