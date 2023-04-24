#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
using namespace std;

int string_to_int(string price)			// function to convert string to integer
{
	int new_price = 0, c = 1;

	for (int i = price.size() - 1; i >= 0; i--)
	{
		new_price += c * (price[i] - '0');

		c *= 10;
	}

	return new_price;
}

//******************************	Start of Book struct	*************************

const int arrsize = 10000;		// max size to the books 
int fantasy_num , mystery_num , romance_num , non_fiction_num , science_fiction_num ; // number of books in each array (section)
int fantasycounter = 0, mysterycounter = 0, romancecounter = 0, non_fictioncounter = 0, science_fictioncounter = 0;

struct book
{
	string title;
	string author;
	string description;
	string type;
	string status;
	string price;
	string numofpages;
	string review;

} fantasy[arrsize], mystery[arrsize], romance[arrsize], non_fiction[arrsize], science_fiction[arrsize];

vector <pair<string, int>>cart_vector;

//******************************	End of Book struct	*************************
//******************************	Start of transitions	*************************
void file_to_fantasy()
//converting file to the fantasy struct
{
	string line;
	int index;
	ifstream file("fantasy.txt");

	if (file.is_open()) {
		for (int i = 0; i < fantasy_num; i++) {
			index = 0;
			fantasycounter++;
			while (getline(file, line))
			{
				if (index == 0)    fantasy[i].title = line;
				else if (index == 1)    fantasy[i].author = line;
				else if (index == 2)    fantasy[i].description = line;
				else if (index == 3)    fantasy[i].type = line;
				else if (index == 4)    fantasy[i].status = line;
				else if (index == 5)    fantasy[i].price = line;
				else if (index == 6)    fantasy[i].numofpages = line;
				else if (index == 7)    fantasy[i].review = line;
				index++;
				if (line == "##") { fantasycounter++; break; }
				if (index == 8)		break;
			}
		}
	}
	file.close();
}

void file_to_mystery()
//converting file to the mystery struct
{
	string line;
	int index;
	ifstream file("mystery.txt");

	if (file.is_open()) {
		for (int i = 0; i < mystery_num; i++) {
			index = 0;
			mysterycounter++;
			while (getline(file, line))
			{
				if (index == 0)    mystery[i].title = line;
				else if (index == 1)    mystery[i].author = line;
				else if (index == 2)    mystery[i].description = line;
				else if (index == 3)    mystery[i].type = line;
				else if (index == 4)    mystery[i].status = line;
				else if (index == 5)    mystery[i].price = line;
				else if (index == 6)    mystery[i].numofpages = line;
				else if (index == 7)    mystery[i].review = line;
				index++;
				if (line == "##") { mysterycounter++; break; }
				if (index == 8)	break;
			}
		}
	}

	file.close();
}

void file_to_romance()
//converting file to the romance struct
{
	string line;
	int index;
	ifstream file("romance.txt");

	if (file.is_open()) {
		for (int i = 0; i < romance_num; i++) {
			index = 0;
			romancecounter++;
			while (getline(file, line))
			{
				if (index == 0)    romance[i].title = line;
				else if (index == 1)    romance[i].author = line;
				else if (index == 2)    romance[i].description = line;
				else if (index == 3)    romance[i].type = line;
				else if (index == 4)    romance[i].status = line;
				else if (index == 5)    romance[i].price = line;
				else if (index == 6)    romance[i].numofpages = line;
				else if (index == 7)    romance[i].review = line;
				index++;
				if (line == "##") { romancecounter++; break; }
				if (index == 8)	break;
			}
		}
	}

	file.close();
}

void file_to_non_fiction()
//converting file to the non fiction struct
{
	string line;
	int index;
	ifstream file("nonfiction.txt");

	if (file.is_open()) {
		for (int i = 0; i < non_fiction_num; i++) {
			index = 0;
			non_fictioncounter++;
			while (getline(file, line))
			{
				if (index == 0)    non_fiction[i].title = line;
				else if (index == 1)    non_fiction[i].author = line;
				else if (index == 2)    non_fiction[i].description = line;
				else if (index == 3)    non_fiction[i].type = line;
				else if (index == 4)    non_fiction[i].status = line;
				else if (index == 5)    non_fiction[i].price = line;
				else if (index == 6)    non_fiction[i].numofpages = line;
				else if (index == 7)    non_fiction[i].review = line;
				index++;
				if (index == 8)	break;
				if (line == "##") { non_fictioncounter++; break; }
				
			}
		}
	}
	file.close();
}

void file_to_science_fiction()
//converting file to the science fiction struct
{
	string line;
	int index;
	ifstream file("science_fiction.txt");

	if (file.is_open()) {
		for (int i = 0; i < science_fiction_num; i++) {
			index = 0;
			science_fictioncounter++;
			while (getline(file, line))
			{
				if (index == 0)    science_fiction[i].title = line;
				else if (index == 1)    science_fiction[i].author = line;
				else if (index == 2)    science_fiction[i].description = line;
				else if (index == 3)    science_fiction[i].type = line;
				else if (index == 4)    science_fiction[i].status = line;
				else if (index == 5)    science_fiction[i].price = line;
				else if (index == 6)    science_fiction[i].numofpages = line;
				else if (index == 7)    science_fiction[i].review = line;
				index++;
				if (line == "##") { science_fictioncounter++; break; }
				if (index == 8)	break;
			}
		}
	}

	file.close();
}

void struct_to_fantasy()
{
	ofstream file;
	file.open("fantasy.txt");

	for (int i = 0; i < fantasy_num; i++)
	{

		for (int j = 0; j < 8; j++)
		{
			if (j == 0) file << fantasy[i].title << endl;
			else if (j == 1) file << fantasy[i].author << endl;
			else if (j == 2) file << fantasy[i].description << endl;
			else if (j == 3) file << fantasy[i].type << endl;
			else if (j == 4) file << fantasy[i].status << endl;
			else if (j == 5) file << fantasy[i].price << endl;
			else if (j == 6) file << fantasy[i].numofpages << endl;
			else if (j == 7) file << fantasy[i].review << endl;
		}
	}
	file << "##";
	file.close();
}

void struct_to_mystery()
{
	ofstream file;
	file.open("mystery.txt");

	for (int i = 0; i < mystery_num; i++)
	{

		for (int j = 0; j < 8; j++)
		{
			if (j == 0) file << mystery[i].title << endl;
			else if (j == 1) file << mystery[i].author << endl;
			else if (j == 2) file << mystery[i].description << endl;
			else if (j == 3) file << mystery[i].type << endl;
			else if (j == 4) file << mystery[i].status << endl;
			else if (j == 5) file << mystery[i].price << endl;
			else if (j == 6) file << mystery[i].numofpages << endl;
			else if (j == 7) file << mystery[i].review << endl;
		}
	}
	file << "##";
	file.close();
}

void struct_to_romantic()
{
	ofstream file;
	file.open("romance.txt");

	for (int i = 0; i < romance_num; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j == 0) file << romance[i].title << endl;
			else if (j == 1) file << romance[i].author << endl;
			else if (j == 2) file << romance[i].description << endl;
			else if (j == 3) file << romance[i].type << endl;
			else if (j == 4) file << romance[i].status << endl;
			else if (j == 5) file << romance[i].price << endl;
			else if (j == 6) file << romance[i].numofpages << endl;
			else if (j == 7) file << romance[i].review << endl;
		}
	}
	file << "##";
	file.close();
}

void struct_to_non_fiction()
{
	ofstream file;
	file.open("non_fiction.txt");

	for (int i = 0; i < non_fiction_num; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j == 0) file << non_fiction[i].title << endl;
			else if (j == 1) file << non_fiction[i].author << endl;
			else if (j == 2) file << non_fiction[i].description << endl;
			else if (j == 3) file << non_fiction[i].type << endl;
			else if (j == 4) file << non_fiction[i].status << endl;
			else if (j == 5) file << non_fiction[i].price << endl;
			else if (j == 6) file << non_fiction[i].numofpages << endl;
			else if (j == 7) file << non_fiction[i].review << endl;
		}
	}
	file << "##";
	file.close();
}

void struct_to_scientific_fiction()
{
	ofstream file;
	file.open("science_fiction.txt");

	for (int i = 0; i < science_fiction_num; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j == 0) file << science_fiction[i].title << endl;
			else if (j == 1) file << science_fiction[i].author << endl;
			else if (j == 2) file << science_fiction[i].description << endl;
			else if (j == 3) file << science_fiction[i].type << endl;
			else if (j == 4) file << science_fiction[i].status << endl;
			else if (j == 5) file << science_fiction[i].price << endl;
			else if (j == 6) file << science_fiction[i].numofpages << endl;
			else if (j == 7) file << science_fiction[i].review << endl;
		}
	}
	file << "##";
	file.close();
}

void files_to_struct() {
	file_to_fantasy();
	file_to_mystery();
	file_to_romance();
	file_to_non_fiction();
	file_to_science_fiction();
}

void structs_to_files()
{
	struct_to_fantasy();
	struct_to_mystery();
	struct_to_romantic();
	struct_to_non_fiction();
	struct_to_scientific_fiction();
}

void file_to_counter()
{
	ifstream file("bookssize.txt");
	int i = 0;
	string line;
	while (getline(file, line))
	{
		if (i == 0) { fantasy_num = string_to_int(line); }
		else if (i == 1) { mystery_num = string_to_int(line); }
		else if (i == 2) { romance_num = string_to_int(line); }
		else if (i == 3) { non_fiction_num = string_to_int(line); }
		else if (i == 4) { science_fiction_num = string_to_int(line); }
		i++;
	}

	file.close();
}

void counetr_to_file()
{
	ofstream file("bookssize.txt");
	file << fantasy_num << endl << mystery_num << endl << romance_num << endl;
	file << non_fiction_num << endl << science_fiction_num << endl;
	file.close();
}

//******************************	 End of transitions		*************************
int welcome();
void registerUser(bool isAdmin);
void isLoggedIn();
void logout();
void editbook(book& Book_to_Edit);
int select_book(int section_num);
int sections();
void user_sequence();
void admin_options();
void addbook(int section_num);
void add_to_cart(int section_num, int num_book);
void delete_cart(int book_num);
void cart();

int main()
{
	file_to_counter();
	files_to_struct();
	welcome();
	structs_to_files();
	counetr_to_file();
	return 0;
}

//******************************	Start of welcome / login / register / logout  *************************

int welcome()
{
	int Admin_User, choice;
	cout << "\t\t----------		Welcome to 6Ms library		----------" << "\n\n";
	cout << "1: Login\n2: Register\n\nYour choice: ";			cin >> choice;
	if (choice == 1)
	{
		isLoggedIn();
		return 1;
	}
	else if (choice == 2)
	{
		cout << "1-Admin\n2-User\n\nYour choice: ";				cin >> Admin_User;
		if (Admin_User == 1) {
			registerUser(true);				// true means that he is admin 
		}
		else if (Admin_User == 2) {
			registerUser(false);			// false means that he is not admin ,is a user
		}
		else {
			cout << "\t\tInvalid input , please try again.\n\n";
			welcome();
		}
		return 2;
	}
	else
	{
		cout << "\t\tInvalid input. Please enter 1 or 2 .\n\n" ;
		welcome();
	}
}

void registerUser(bool isAdmin)		// register takes boolen value to check if it is a user or admin
{
	string username, password, userType, user_name, password_;
	cout << "\nSelect a username: ";			cin >> username;

	char ch;
	cout << "Enter your password: ";
	while ((ch = _getch()) != '\r') {		// Read password character by character
		cout << '*';
		password += ch;
	}
	ifstream read("ourfile.txt");
	while (getline(read, userType))
	{
		getline(read, user_name);
		getline(read, password_);
		if (username == user_name) {
			cout << "\n\t\tThis username has already been used , Please choose another \n\n";
			registerUser(isAdmin);
		}
	}
	ofstream outfile;
	outfile.open("ourfile.txt", ios::app); // Change file open mode to append
	if (outfile.is_open())
	{
		if (isAdmin) {
			outfile << "admin" << endl;
		}
		else {
			outfile << "user" << endl;
		}
		outfile << username << endl << password << endl;
		cout << "\n\t\tRegistration completed\n";
		cout << "\n\t\tLog in \n";
		isLoggedIn();
	}
	outfile.close();
}

void isLoggedIn()
{
	bool found = false;
	string username, password, userType, user_name, password_;		//user_name & password_ variables to read from file 
	cout << "\nEnter the username: ";		cin >> username;
	cout << "Enter the password: ";
	char ch;
	while ((ch = _getch()) != '\r') {	// Read password character by character

		cout << '*';
		password += ch; // Add character to the password string
	}

	cout << endl;
	ifstream read("ourfile.txt");
	while (getline(read, userType))
	{
		getline(read, user_name);
		getline(read, password_);
		if (user_name == username && password_ == password && userType == "admin")
		{
			cout << "\n\t\tSuccessfully logged in as an admin!\n";
			admin_options();
			found = true;
			break;
		}
		else if (user_name == username && password_ == password && userType == "user")
		{
			cout << "\n\t\tSuccessfully logged in as a user!\n";
			user_sequence();
			found = true;
			break;
		}
		else
		{
			continue;
		}
	}
	if (!found){
		cout << "\n\t\tInvalid username or password \n\n";
		isLoggedIn();
	}
}

void logout() {
	welcome();
}

//******************************	End of welcome / login / register / logout	*************************
//******************************	Start Edit / add / delete book					*************************

void editbook(book& Book_to_Edit)
{
	int choice;
	do {
		cout << "\t1: edit title\n";
		cout << "\t2: edit author name\n";
		cout << "\t3: edit description\n";
		cout << "\t4: edit type\n";
		cout << "\t5: edit status\n";
		cout << "\t6: edit price\n";
		cout << "\t7: edit number of pages\n";
		cout << "\t8: edit review\n";
		cout << "\t0: back\n";

		cout << "Choose the detail you want to edit : ";		cin >> choice;

		switch (choice)
		{
		case 1:cout << "\nEnter new title : ";
			cin.ignore();
			getline(cin, Book_to_Edit.title);
			break;
		case 2:cout << "\nEnter new author name : ";
			cin.ignore();
			getline(cin, Book_to_Edit.author);
			break;
		case 3:cout << "\nEnter new description : ";
			cin.ignore();
			getline(cin, Book_to_Edit.description);
			break;
		case 4:cout << "\nEnter new type : ";
			cin.ignore();
			getline(cin, Book_to_Edit.type);
			break;
		case 5: cout << "\nEnter new status : ";
			cin.ignore();
			getline(cin, Book_to_Edit.status);
			break;
		case 6:cout << "\nEnter new price : ";
			cin.ignore();
			getline(cin, Book_to_Edit.price);
			break;
		case 7:cout << "\nEnter new num of pages : ";
			cin.ignore();
			getline(cin, Book_to_Edit.numofpages);
			break;
		case 8:cout << "\nEnter new review : ";
			cin.ignore();
			getline(cin, Book_to_Edit.review);
			break;
		}

		cout << "\n\t\tDo you want to edit any other details in this book? (0 to quit editing) \n";

	} while (choice != 0);
}

void addbook(int section_num) {
	if (section_num == 1) {
		cout << "\nEnter book title : ";
		cin.ignore();
		getline(cin, fantasy[fantasy_num].title);
		cout << "\nEnter author name  : ";
		getline(cin, fantasy[fantasy_num].author);
		cout << "\nEnter the description  :  ";
		getline(cin, fantasy[fantasy_num].description);
		cout << "\nEnter the type  :  ";
		getline(cin, fantasy[fantasy_num].type);
		cout << "\nEnter the status  :  ";
		getline(cin, fantasy[fantasy_num].status);
		cout << "\nEnter price  :  ";
		cin >> fantasy[fantasy_num].price;
		cout << "\nEnter number of pages  :  ";
		cin >> fantasy[fantasy_num].numofpages;
		cin.ignore();
		cout << "\nEnter review : ";
		getline(cin, fantasy[fantasy_num].review);
		fantasy_num++;
	}
	else if (section_num == 2 ){
		cout << "\nEnter book title : ";
		cin.ignore();
		getline(cin, mystery[mystery_num].title);
		cout << "\nEnter author name  : ";
		getline(cin, mystery[mystery_num].author);
		cout << "\nEnter the description  :  ";
		getline(cin, mystery[mystery_num].description);
		cout << "\nEnter the type  :  ";
		getline(cin, mystery[mystery_num].type);
		cout << "\nEnter the status  :  ";
		getline(cin, mystery[mystery_num].status);
		cout << "\nEnter price  :  ";
		cin >> mystery[mystery_num].price;
		cout << "\nEnter number of pages  :  ";
		cin >> mystery[mystery_num].numofpages;
		cin.ignore();
		cout << "\nEnter review : ";
		getline(cin, mystery[mystery_num].review);
		mystery_num++;
	}
	else if (section_num == 3) {
		cout << "\nEnter book title : ";
		cin.ignore();
		getline(cin, romance[romance_num].title);
		cout << "\nEnter author name  : ";
		getline(cin, romance[romance_num].author);
		cout << "\nEnter the description  :  ";
		getline(cin, romance[romance_num].description);
		cout << "\nEnter the type  :  ";
		getline(cin, romance[romance_num].type);
		cout << "\nEnter the status  :  ";
		getline(cin, romance[romance_num].status);
		cout << "\nEnter price  :  ";
		cin >> romance[romance_num].price;
		cout << "\nEnter number of pages  :  ";
		cin >> romance[romance_num].numofpages;
		cin.ignore();
		cout << "\nEnter review : ";
		getline(cin, romance[romance_num].review);
		romance_num++;
	}
	else if (section_num == 4) {
		cout << "\nEnter book title : ";
		cin.ignore();
		getline(cin, non_fiction[non_fiction_num].title);
		cout << "\nEnter author name  : ";
		getline(cin, non_fiction[non_fiction_num].author);
		cout << "\nEnter the description  :  ";
		getline(cin, non_fiction[non_fiction_num].description);
		cout << "\nEnter the type  :  ";
		getline(cin, non_fiction[non_fiction_num].type);
		cout << "\nEnter the status  :  ";
		getline(cin, non_fiction[non_fiction_num].status);
		cout << "\nEnter price  :  ";
		cin >> non_fiction[non_fiction_num].price;
		cout << "\nEnter number of pages  :  ";
		cin >> non_fiction[non_fiction_num].numofpages;
		cin.ignore();
		cout << "\nEnter review : ";
		getline(cin, non_fiction[non_fiction_num].review);
		non_fiction_num++;
	}
	else if (section_num == 5) {
		cout << "\nEnter book title : ";
		cin.ignore();
		getline(cin, science_fiction[science_fiction_num].title);
		cout << "\nEnter author name  : ";
		getline(cin, science_fiction[science_fiction_num].author);
		cout << "\nEnter the description  :  ";
		getline(cin, science_fiction[science_fiction_num].description);
		cout << "\nEnter the type  :  ";
		getline(cin, science_fiction[science_fiction_num].type);
		cout << "\nEnter the status  :  ";
		getline(cin, science_fiction[science_fiction_num].status);
		cout << "\nEnter price  :  ";
		cin >> science_fiction[science_fiction_num].price;
		cout << "\nEnter number of pages  :  ";
		cin >> science_fiction[science_fiction_num].numofpages;
		cin.ignore();
		cout << "\nEnter review : ";
		getline(cin, science_fiction[science_fiction_num].review);
		science_fiction_num++;
	}
}

void delete_book(int section_index, int book_index) {
	if (section_index == 0)
	{
		for (int i = book_index; i < fantasy_num - 1; i++) {
			fantasy[i] = fantasy[i + 1];    
		}
		fantasy_num--;
	}
	else if (section_index == 1)
	{
		for (int i = book_index; i < mystery_num - 1; i++) {
			mystery[i] = mystery[i + 1];
		}
		mystery_num--;
	}
	else if (section_index == 2)
	{
		for (int i = book_index; i < romance_num - 1; i++) {
			romance[i] = romance[i + 1];
		}
		romance_num--;
	}
	else if (section_index == 3)
	{
		for (int i = book_index; i < non_fiction_num - 1; i++) {
			non_fiction[i] = non_fiction[i + 1];
		}
		non_fiction_num--;
	}
	else if (section_index == 4)
	{
		for (int i = book_index; i < science_fiction_num - 1; i++) {
			science_fiction[i] = science_fiction[i + 1];
		}
		science_fiction_num--;
	}
}

//******************************	End Edit / add / delete book					*************************

int select_book(int section_num)			// showing the data of a specified book
{
	int book_num;
	cout << "\nPlease Enter the number of the book : ";			cin >> book_num;		cout << "\n";
	if ((section_num == 1 && book_num <= fantasy_num) ||
		(section_num == 2 && book_num <= mystery_num) ||
		(section_num == 3 && book_num <= romance_num) ||
		(section_num == 4 && book_num <= non_fiction_num) ||
		(section_num == 5 && book_num <= science_fiction_num)){ 
	if (section_num == 1)
	{
		cout << "Author name : " << fantasy[book_num - 1].author << "\n\n";
		cout << "The description :" << "\n\t\t" << fantasy[book_num - 1].description << "\n\n";
		cout << "The type of the book : " << fantasy[book_num - 1].type << "\n\n";
		cout << "The status of the book : " << fantasy[book_num - 1].status << "\n\n";
		cout << "The price : " << fantasy[book_num - 1].price << "\n\n";
		cout << "Number of pages : " << fantasy[book_num - 1].numofpages << "\n\n";
		cout << "The rate of the book : " << fantasy[book_num - 1].review << "\n\n";
	}
	else if (section_num == 2)
	{
		cout << "Author name : " << mystery[book_num - 1].author << "\n\n";
		cout << "The description :" << "\n\t\t" << mystery[book_num - 1].description << "\n\n";
		cout << "The type of the book : " << mystery[book_num - 1].type << "\n\n";
		cout << "The status of the book : " << mystery[book_num - 1].status << "\n\n";
		cout << "The price : " << mystery[book_num - 1].price << "\n\n";
		cout << "Number of pages : " << mystery[book_num - 1].numofpages << "\n\n";
		cout << "The rate of the book : " << mystery[book_num - 1].review << "\n\n";
	}
	else if (section_num == 3)
	{
		cout << "Author name : " << romance[book_num - 1].author << "\n\n";
		cout << "The description :" << "\n\t\t" << romance[book_num - 1].description << "\n\n";
		cout << "The type of the book : " << romance[book_num - 1].type << "\n\n";
		cout << "The status of the book : " << romance[book_num - 1].status << "\n\n";
		cout << "The price : " << romance[book_num - 1].price << "\n\n";
		cout << "Number of pages : " << romance[book_num - 1].numofpages << "\n\n";
		cout << "The rate of the book : " << romance[book_num - 1].review << "\n\n";
	}
	else if (section_num == 4)
	{
		cout << "Author name : " << non_fiction[book_num - 1].author << "\n\n";
		cout << "The description :" << "\n\t\t" << non_fiction[book_num - 1].description << "\n\n";
		cout << "The type of the book : " << non_fiction[book_num - 1].type << "\n\n";
		cout << "The status of the book : " << non_fiction[book_num - 1].status << "\n\n";
		cout << "The price : " << non_fiction[book_num - 1].price << "\n\n";
		cout << "Number of pages : " << non_fiction[book_num - 1].numofpages << "\n\n";
		cout << "The rate of the book : " << non_fiction[book_num - 1].review << "\n\n";
	}
	else if (section_num == 5)
	{
		cout << "Author name : " << science_fiction[book_num - 1].author << "\n\n";
		cout << "The description :" << "\n\t\t" << science_fiction[book_num - 1].description << "\n\n";
		cout << "The type of the book : " << science_fiction[book_num - 1].type << "\n\n";
		cout << "The status of the book : " << science_fiction[book_num - 1].status << "\n\n";
		cout << "The price : " << science_fiction[book_num - 1].price << "\n\n";
		cout << "Number of pages : " << science_fiction[book_num - 1].numofpages << "\n\n";
		cout << "The rate of the book : " << science_fiction[book_num - 1].review << "\n\n";
	}
	return book_num;
	}
	else {
		cout << "\t\tInvalid choice \n\n";
		select_book(section_num);
	}
}

int sections()
{
	int section_num;

	cout << "\n1 - Fantasy\n" << "2 - Mystery\n" << "3 - Romantic\n" << "4 - Non fiction\n" << "5 - Scientific fiction\n";
	cout << "\nPlease enter the number of the section : ";			cin >> section_num;
	cout << "\n";
	if (section_num == 1)
	{
		for (int i = 0; i < fantasy_num; i++)
			cout << i + 1 << " - " << fantasy[i].title << endl;
	}
	else if (section_num == 2)
	{
		for (int i = 0; i < mystery_num; i++)
			cout << i + 1 << " - " << mystery[i].title << endl;
	}
	else if (section_num == 3)
	{
		for (int i = 0; i < romance_num; i++)
			cout << i + 1 << " - " << romance[i].title << endl;
	}
	else if (section_num == 4)
	{
		for (int i = 0; i < non_fiction_num; i++)
			cout << i + 1 << " - " << non_fiction[i].title << endl;
	}
	else if (section_num == 5)
	{
		for (int i = 0; i < science_fiction_num; i++)
			cout << i + 1 << " - " << science_fiction[i].title << endl;
	}
	else
	{
		cout << "\n\t\tInvalid Section\n\n";
		sections();
	}
	return section_num;
}

void user_sequence() {
	int section_num = sections();
	int book_num = select_book(section_num);
	int user_choice , user_choice2, user_choice3, num_to_delete_from_cart;
		while (true)
		{
			cout << "1- add to cart : \n2-Go to cart : \n3-Return to home : \n\n";		
			cout << "Please choose an option : ";
			cin >> user_choice; cout << endl;
			if (user_choice == 1) {
				add_to_cart(section_num, book_num);
				while (true)
				{
					cout << "\n1-Go to cart : \n2-Return to home : \n";		
					cout << "Please choose an option : ";
					cin >> user_choice2; cout << endl;
					if (user_choice2 == 1) {
						cart();
						break;
					}
					else if (user_choice2 == 2) {
						user_sequence();		break;
					}
					else {
						cout << "\n\t\tInvalid choice! please try again\n\n";
					}
				}
				break;
			}
			else if (user_choice == 2) {
				cart();	
				break;
			}
			else if (user_choice == 3) {
				user_sequence();		break;
			}
			else {
				cout << "\n\t\tInvalid choice! please try again\n\n";
			}
		}
}

void admin_options()
{
	int choices1, choices2, book_num;
	int section_num = sections();
	while (true)
	{
		cout << "\n1 : add new book\n2 : access books\n3 : Return to home\n";			cin >> choices1;
		if (choices1 == 1)
		{
			if (section_num == 1)
			{
				addbook(section_num);
			}
			else if (section_num == 2)
			{
				addbook(section_num);
			}
			else if (section_num == 3)
			{
				addbook(section_num);
			}
			else if (section_num == 4)
			{
				addbook(section_num);
			}
			else if (section_num == 5)
			{
				addbook(section_num);
			}
			structs_to_files();
			counetr_to_file();
			cout << "\n\t\tSuccessfully added \n\n";
			admin_options();
			break;
		}
		else if (choices1 == 2)
		{
			book_num = select_book(section_num);
			cout << "1 : edit book \n2 : Delete book \n3: return homepage\n";
			while (true)
			{
				cin >> choices2;
				if (choices2 == 1)
				{
					if (section_num == 1)
					{
						editbook(fantasy[book_num - 1]);
						admin_options();
					}
					else if (section_num == 2)
					{
						editbook(mystery[book_num - 1]);
						admin_options();
					}
					else if (section_num == 3)
					{
						editbook(romance[book_num - 1]);
						admin_options();
					}
					else if (section_num == 4)
					{
						editbook(non_fiction[book_num - 1]);
						admin_options();
					}
					else if (section_num == 5)
					{
						editbook(science_fiction[book_num - 1]);
						admin_options();
					}
					break;
				}
				else if (choices2 == 2)
				{
					delete_book(section_num - 1, book_num - 1);
					structs_to_files();
					counetr_to_file();
					cout << "\n\t\tSuccessfully deleted \n\n";
					admin_options();
				}
				else if (choices2 == 3)
				{
					admin_options();
				}
				else {
					cout << "\n\t\tInvalid choice! please try again.\n\n";
				}
			}
		}
		else if (choices1 == 3) {
			admin_options();
		}
		else
		{
			cout << "\n\t\tInvalid choice! please try again.\n\n";
			admin_options();
		}
		break;
	}
}

//******************************	Start cart  		*************************

void add_to_cart(int section_num, int num_book)
{
	int price;
	bool exist = 0; // to check if the book is available or not

	if (section_num == 1)
	{
		price = string_to_int(fantasy[num_book - 1].price);
		if (fantasy[num_book - 1].status == "Unavailable" || fantasy[num_book - 1].status == "unavailable")
			exist = 1;
		else
		cart_vector.push_back({ fantasy[num_book - 1].title , price });
	}

	else if (section_num == 2)
	{
		price = string_to_int(mystery[num_book - 1].price);
		if (mystery[num_book - 1].status == "Unavailable" || mystery[num_book - 1].status == "unavailable")
			exist = 1;
		else
		cart_vector.push_back({ mystery[num_book - 1].title , price });
	}

	else if (section_num == 3)
	{
		price = string_to_int(romance[num_book - 1].price);
		if (romance[num_book - 1].status == "Unavailable" || romance[num_book - 1].status == "unavailable")
			exist = 1;
		else
		cart_vector.push_back({ romance[num_book - 1].title , price });
	}

	else if (section_num == 4)
	{
		price = string_to_int(non_fiction[num_book - 1].price);
		if (non_fiction[num_book - 1].status == "Unavailable" || non_fiction[num_book - 1].status == "unavailable")
			exist = 1;
		else
		cart_vector.push_back({ non_fiction[num_book - 1].title , price });
	}

	else if (section_num == 5)
	{
		price = string_to_int(science_fiction[num_book - 1].price);
		if (science_fiction[num_book - 1].status == "Unavailable" || science_fiction[num_book - 1].status == "unavailable")
			exist = 1;
		else
		cart_vector.push_back({ science_fiction[num_book - 1].title , price });
	}

	if (!exist)
		cout << "\n\t\tSuccessfully added !\n\n";
	else
		cout << "\t\tThe book is not available !\n\n";
}

void delete_cart(int book_num)
{
	cart_vector.erase(cart_vector.begin()+book_num-1);
	cout << "\n\t\tSuccessfully deleted ! \n";
}

void cart()
{
	int total_price = 0;
	int user_choice3, num_to_delete_from_cart;
	cout << "\n";
	if (!cart_vector.size()) 
	{
		cout << "The cart is empty \n\n";
		return;
	}

	else {
		for (int i = 0; i < cart_vector.size(); i++)
		{
			total_price += cart_vector[i].second;
			cout << "Book #" << i + 1 << "\t name : " << cart_vector[i].first << "\t price : " << cart_vector[i].second << "$\n\n";
		}
		cout << "\n\tThe total price is : " << total_price << "$\n\n";
		while (true)
		{
			cout << "\n1-Delete from cart :\n2-Checkout : \n3-Return to home : \n\nPlease choose an option : ";		cin >> user_choice3; cout << endl;
			if (user_choice3 == 1) {
				cout << "\nWhich book do you want to delete : ";		cin >> num_to_delete_from_cart;
				if (num_to_delete_from_cart <= cart_vector.size() && num_to_delete_from_cart > 0) {
					delete_cart(num_to_delete_from_cart);
					cart();
					continue;
				}
				else
				{
					cout << "\n\t\tInvalid choice !\n\n";		continue;
				}
				cart();
				break;
			}
			else if (user_choice3 == 2) {
				cart_vector.clear();
				cout << "Successfully checked out !\n\n";
			}
			else if (user_choice3 == 3) {
				user_sequence();		break;
			}
			else {
				cout << "\n\t\tInvalid choice! please try again\n\n";
			}
		}
	}
}

//******************************	End cart			*************************