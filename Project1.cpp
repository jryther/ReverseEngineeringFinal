#include <iostream>
#include <sstream>
#include <iomanip>

int IntInputValidation(int min, int max) { // Added to increase security
	int input_integer;
	std::string string_number;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, string_number); //get string input
	std::stringstream convert(string_number); //turns the string into a stream

	//checks for complete conversion to integer and checks for minimum and maximum value
	if (convert >> input_integer &&
		!(convert >> string_number) &&
		input_integer >= min &&
		input_integer <= max) {

		return input_integer;
	}
	else if (input_integer < min) {
		std::cout << "Input less than expected" << std::endl;
	}
	else if (input_integer > max) {
		std::cout << "Input greater than expected" << std::endl;
	}

	return NULL;
}

std::string StringInputValidation() { // Added to increase security
	char user_input[21];
	
	if (std::cin.rdbuf()->in_avail() > 0) { //Checks input buffer to see if there are any characters
		std::cin.ignore(1000, '\n');
	}

	std::cin.get(user_input, 21); // Places the first 21 characters of the stream into the char array.  Last char is null character.

	if (std::cin.rdbuf()->in_avail() > 1) { //Checks input buffer to see if there are remaining characters
		std::cout << "Character limit of 21 exceeded" << std::endl; // Prints statement that an overflow would have occurred if all chars were read.
		return "";
	}
	else return user_input;
}

int CheckUserPermissionAccess() {
	std::string username = "";
	std::string password = "";

	while (true) { // While loop added to keep taking input until valid submission is obtained
		std::cout << "Enter your username: \n";
		username = StringInputValidation(); // String input validation
		if (username != "") {
			break;
		}
	}

	while (true) { // While loop added to keep taking input until valid submission is obtained
		std::cout << "Enter your password: \n";
		password = StringInputValidation(); // String input validation added
		if (password != "") {
			break;
		}
	}


	if (password == "123") {
		return 1;
	}
	else {
		return 2;
	}
}

void DisplayInfo(int& num1, int& num2, int& num3, int& num4, int& num5) {

	std::cout << "Client's Name    Service Selected (1 = Brokerage, 2 = Retirement)" << "\n";
	std::cout << "1. " << "Bob Jones" << " selected option " << num1 << "\n";
	std::cout << "2. " << "Sarah Davis" << " selected option " << num2 << "\n";
	std::cout << "3. " << "Amy Friendly" << " selected option " << num3<< "\n";
	std::cout << "4. " << "Johnny Smith" << " selected option " << num4 << "\n";
	std::cout << "5. " << "Carol Spears" << " selected option " << num5 << "\n";

	return;
}

void ChangeCustomerChoice(int& num1, int& num2, int& num3, int& num4, int& num5) {
	int changechoice = NULL;
	int newservice = NULL;

	std::cout << "Enter the number of the client that you wish to change\n";
	changechoice = IntInputValidation(1, 5); // Integer input validation added
	if (changechoice == NULL) {
		return;
	}

	std::cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)\n";
	newservice = IntInputValidation(1, 2); // Integer input validation added
	if (newservice == NULL) {
		return;
	}

	if (changechoice == 1) {
		num1 = newservice;
	}
	else if (changechoice == 2) {
		num2 = newservice;
	}
	else if (changechoice == 3) {
		num3 = newservice;
	}
	else if (changechoice == 4) {
		num4 = newservice;
	}
	else if (changechoice == 5) {
		num5 = newservice;
	}
	return;
}


int main() {

	int answer = NULL, choice = NULL;
	int num1 = 1, num2 = 2, num3 = 1, num4 = 1, num5 = 2;
	int loginCounter = 0;
	
	std::cout << "Created by: Josh Ryther\n" << "Hello! Welcome to our Investment Company\n";

	while (answer != 1) {
		if (loginCounter > 2) { // Login counter added to limit number of attempts to 3
			std::cout << "Maximum number of attempts reached.  Program terminating." << std::endl;
			return 0;
		}
		answer = CheckUserPermissionAccess();
		if (answer == 1) {
			break;
		}
		else {
			std::cout << "Invalid Password. Please try again\n";
			loginCounter ++;
		}
	}

	while (choice != 3) {
		std::cout << "What would you like to do?\n";
		std::cout << "DISPLAY the client list (enter 1)\n";
		std::cout << "CHANGE a client's choice (enter 2)\n";
		std::cout << "Exit the program.. (enter 3)\n";
		choice = IntInputValidation(1, 3); // Input validation added
		std::cout << "You chose " << choice << "\n";

		if (choice == 1) {
			DisplayInfo(num1, num2, num3, num4, num5);
		}
		else if (choice == 2) {
			ChangeCustomerChoice(num1, num2, num3, num4, num5);
		}
		else if (choice == 3) {
			return 1;
		}

	}


}