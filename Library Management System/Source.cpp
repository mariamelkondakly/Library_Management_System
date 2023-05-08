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
	string countity;

} fantasy[arrsize], mystery[arrsize], romance[arrsize], non_fiction[arrsize], science_fiction[arrsize];

struct person
{
	string usertype;
	string username;
	string password;
};
int users = 0;
person information[arrsize];

vector <pair<int, int>>cart_vector;

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
				else if (index == 8)     fantasy[i].countity = line;
				index++;
				if (line == "##") { break; }
				if (index == 9)		break;
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
				else if (index == 8)    mystery[i].countity = line;
				index++;
				if (line == "##") { break; }
				if (index == 9)	break;
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
				else if (index == 8)    romance[i].countity = line;
				index++;
				if (line == "##") {break; }
				if (index == 9)	break;
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
				else if (index == 8)    non_fiction[i].countity = line;
				index++;
				if (line == "##") {
				 break;}
				if (index == 9)	break;
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
				else if (index == 8)     science_fiction[i].countity = line;
				index++;
				if (line == "##") { break; }
				if (index == 9)	break;
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
		file << fantasy[i].title << endl;
		file << fantasy[i].author << endl;
		file << fantasy[i].description << endl;
		file << fantasy[i].type << endl;
		file << fantasy[i].status << endl;
		file << fantasy[i].price << endl;
		file << fantasy[i].numofpages << endl;
		file << fantasy[i].review << endl;
		file << fantasy[i].countity << endl;
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
		file << mystery[i].title << endl;
		file << mystery[i].author << endl;
		file << mystery[i].description << endl;
		file << mystery[i].type << endl;
		file << mystery[i].status << endl;
		file << mystery[i].price << endl;
		file << mystery[i].numofpages << endl;
		file << mystery[i].review << endl;
		file << mystery[i].countity << endl;
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
		file << romance[i].title << endl;
		file << romance[i].author << endl;
		file << romance[i].description << endl;
		file << romance[i].type << endl;
		file << romance[i].status << endl;
		file << romance[i].price << endl;
		file << romance[i].numofpages << endl;
		file << romance[i].review << endl;
		file << romance[i].countity << endl;
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
		file << non_fiction[i].title << endl;
		file << non_fiction[i].author << endl;
		file << non_fiction[i].description << endl;
		file << non_fiction[i].type << endl;
		file << non_fiction[i].status << endl;
		file << non_fiction[i].price << endl;
		file << non_fiction[i].numofpages << endl;
		file << non_fiction[i].review << endl;
		file << non_fiction[i].countity << endl;
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
		file << science_fiction[i].title << endl;
		file << science_fiction[i].author << endl;
		file << science_fiction[i].description << endl;
		file << science_fiction[i].type << endl;
		file << science_fiction[i].status << endl;
		file << science_fiction[i].price << endl;
		file << science_fiction[i].numofpages << endl;
		file << science_fiction[i].review << endl;
		file << science_fiction[i].countity << endl;
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

void file_to_information()
{
	string userType, user_name, password_;
	ifstream read("ourfile.txt");
	while (getline(read, userType))
	{
		getline(read, user_name);
		getline(read, password_);
		information[users].usertype = userType;
		information[users].username = user_name;
		information[users].password = password_;
		users++;
	}
}

void information_to_file()
{
	ofstream read("ourfile.txt");
	for (int i = 0; i < users; i++)
	read << information[i].usertype << endl << information[i].username << endl << information[i].password << endl;
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
	file_to_information();
	file_to_counter();
	files_to_struct();
	welcome();
	information_to_file();
	structs_to_files();
	counetr_to_file();
	return 0;
}

//******************************	Start of welcome / login / register / logout  *************************

int welcome()
{
	int Admin_User, choice;
	cout << "\t\t----------		Welcome to 6Ms library		----------" << "\n\n";
	cout << "1: Login\n2: Register\n3: Edit information\n\nYour choice: ";			cin >> choice; cout << endl;
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

	else if (choice == 3)
	{
		string s;
		bool c = 0;
		cout << "1 :Edit username\n2 :Edit password\n\n";
		cout << "Please enter your choice : "; cin >> choice; cout << endl;
		if (choice == 1)
		{
			cout << "Please enter your last username : "; cin >> s; cout << endl;
			for (int i = 0; i < users; i++)
			{
				if (s == information[i].username)
				{
					cout << "Please enter your new username : "; 
					cin >> s; information[i].username = s;
					cout << endl;
					c = 1;
					break;
				}
			}

			if (c == 0)
			cout << "The username is not existed\n\n";
		}

		else if (choice == 2)
		{
			cout << "Please enter your last password : "; cin >> s; cout << endl;
			for (int i = 0; i < users; i++)
			{
				if (s == information[i].password)
				{
					cout << "Please enter your new password : ";
					cin >> s; 
					information[i].password = s;
					cout << endl;
					c = 1;
					break;
				}
			}

			if (c == 0)
			cout << "The password is not existed\n\n";
		}
		
		else 
		cout << "Invalid Input!\n\n";

		information_to_file();
		welcome();
	}

	else
	{
		cout << "\t\tInvalid input. Please enter 1 or 2 or 3.\n\n" ;
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
		cout << "\t9: edit countity\n";
		cout << "\t0: back\n\n";

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
		case 9:cout << "\nEnter new countity : ";
			cin.ignore();
			getline(cin, Book_to_Edit.countity);
			break;
		}

		if(choice != 0)
		cout << "\n\t\tDo you want to edit any other details in this book? (0 to quit editing) \n\n";

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
		cout << "\nEnter countity : ";
		getline(cin, fantasy[fantasy_num].countity);
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
		cout << "\nEnter countity : ";
		getline(cin, mystery[mystery_num].countity);
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
		cout << "\nEnter countity : ";
		getline(cin, romance[romance_num].countity);
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
		cout << "\nEnter countity : ";
		getline(cin, non_fiction[non_fiction_num].countity);
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
		cout << "\nEnter countity : ";
		getline(cin, science_fiction[science_fiction_num].countity);
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
						user_sequence();
						break;
					}
					else if (user_choice2 == 2) {
						user_sequence(); break;
					}
					else {
						cout << "\n\t\tInvalid choice! please try again\n\n";
					}
				}

			}
			else if (user_choice == 2) {
				cart();	
				user_sequence();
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
		cout << "\nIt's your options\n\n";
		cout << "\n1 : add new book\n2 : access books\n3 : Return to home\n\n";			
		cout << "Please choose an option : ";  cin >> choices1; cout << endl;

		if (choices1 == 1)
		{
			addbook(section_num);
			structs_to_files();
			counetr_to_file();
			cout << "\n\t\tSuccessfully added \n\n";
			admin_options();
			break;
		}
		else if (choices1 == 2)
		{
			book_num = select_book(section_num);

			while (true)
			{
				cout << "\nIt's your options\n\n";
				cout << "1 : edit book \n2 : Delete book \n3: return homepage\n\n";
				cout << "Please choose an option : "; cin >> choices2; cout << endl;
				if (choices2 == 1)
				{
					if (section_num == 1)
					editbook(fantasy[book_num - 1]);
						
					else if (section_num == 2)
					editbook(mystery[book_num - 1]);
					
					else if (section_num == 3)
					editbook(romance[book_num - 1]);
					
					else if (section_num == 4)
					editbook(non_fiction[book_num - 1]);
						
					
					else if (section_num == 5)
				    editbook(science_fiction[book_num - 1]);

					structs_to_files();
					admin_options();
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
					continue;
				}
			}
		}
		else if (choices1 == 3) {
			admin_options();
		}
		else
		{
			cout << "\n\t\tInvalid choice! please try again.\n\n";
			continue;
		}
		break;
	}
}

//******************************	Start cart  		*************************

void add_to_cart(int section_num, int num_book)
{
	bool exist = 0; // to check if the book is available or not

	for (int i = 0; i < cart_vector.size(); i++)
	{
		if (cart_vector[i].first == section_num && cart_vector[i].second == num_book)
		{
			cout << "The book is already added to the cart \n\n";
			return;
		}

	}

	if (section_num == 1)
	{
		if (fantasy[num_book - 1].status == "Unavailable" || fantasy[num_book - 1].status == "unavailable")
			exist = 1;
	}

	else if (section_num == 2)
	{
		if (mystery[num_book - 1].status == "Unavailable" || mystery[num_book - 1].status == "unavailable")
			exist = 1;
	}

	else if (section_num == 3)
	{
		if (romance[num_book - 1].status == "Unavailable" || romance[num_book - 1].status == "unavailable")
		exist = 1;
	}

	else if (section_num == 4)
	{	
		if (non_fiction[num_book - 1].status == "Unavailable" || non_fiction[num_book - 1].status == "unavailable")
			exist = 1;
	}

	else if (section_num == 5)
	{
		if (science_fiction[num_book - 1].status == "Unavailable" || science_fiction[num_book - 1].status == "unavailable")
			exist = 1;
	}

	if (!exist)
	{
		cout << "\n\t\tSuccessfully added !\n\n";
		cart_vector.push_back({ section_num,num_book });
	}
	else
		cout << "\t\tThe book is not available !\n\n";
}

void delete_cart(int book_num)
{
	cart_vector.erase(cart_vector.begin()+book_num);
	cout << "\n\t\tSuccessfully deleted ! \n";
}

void cart()
{
	int total_price = 0;
	string choice;
	cout << "\n";
	if (!cart_vector.size())
	{
		cout << "The cart is empty \n\n";
		return;
	}

	for (int i = 0; i < cart_vector.size(); i++)
	{
		int book_num = cart_vector[i].second,price;

		cout << "#Book " << i + 1 << "\t\t";

		if (cart_vector[i].first == 1)
		{
			price = string_to_int(fantasy[book_num - 1].price);
			cout << "name : " << fantasy[book_num - 1].title << "\t\t" << "price : " << price << "$\n\n";
		}

		else if (cart_vector[i].first == 2)
		{
		    price = string_to_int(mystery[book_num - 1].price);
			cout << "name : " << mystery[book_num - 1].title << "\t\t" << "price : " << price << "$\n\n";
		}

		else if (cart_vector[i].first == 3)
		{
			price = string_to_int(romance[book_num - 1].price);
			cout << "name : " << romance[book_num - 1].title << "\t\t" << "price : " << price << "$\n\n";
		}

		else if (cart_vector[i].first == 4)
		{
			 price = string_to_int(non_fiction[book_num - 1].price);
			cout << "name : " << non_fiction[book_num - 1].title << "\t\t" << "price : " << price << "$\n\n";
		}

		else if (cart_vector[i].first == 5)
		{
		    price = string_to_int(science_fiction[book_num - 1].price);
			cout << "name : " << science_fiction[book_num - 1].title << "\t\t" << "price : " << price << "$\n\n";
		}

		total_price += price;
	}


	cout << "\n\tThe total price is : " << total_price << "$\n\n";
	
	while (true)
	{
		string s;
		int book_num;
		cout << "Do you want to delete a book from the cart?\n\n";
		cout << "Please enter yes or no : "; cin >> s; cout << endl;
		if (s == "Yes" || s == "yes")
		{
			cout << "Please enter the number of the book : ";
			cin >> book_num; cout << endl;
			delete_cart(book_num - 1);
		}

		else if (s == "No" || s == "no")
		break;

		else
		{
			cout << "Invalid Choice!\n\n";
			continue;
		}
	}

	while (true)
	{
		cout << "Do you want to check out from the cart ?\n\n";
		cout << "Please enter yes or no : ";
		cin >> choice; cout << endl;
		if (choice == "Yes" || choice == "yes")
		{
			for (int i = 0; i < cart_vector.size(); i++)
			{
				int book_num = cart_vector[i].second,countity;
				if (cart_vector[i].first == 1)
				{
					countity = string_to_int(fantasy[book_num - 1].countity);
					countity--;
					if (!countity)
					fantasy[book_num-1].status = "Unavailable";
					fantasy[book_num - 1].countity = to_string(countity);
				}
				
				else if (cart_vector[i].first == 2)
				{
					countity = string_to_int(mystery[book_num - 1].countity);
					countity--;
					if (!countity)
					mystery[book_num-1].status = "Unavailable";
					mystery[book_num - 1].countity = to_string(countity);
				}

				else if (cart_vector[i].first == 3)
				{
					countity = string_to_int(romance[book_num - 1].countity);
					countity--;
					if (!countity)
					romance[book_num-1].status = "Unavailable";
					romance[book_num - 1].countity = to_string(countity);
				}

				else if (cart_vector[i].first == 4)
				{
					countity = string_to_int(non_fiction[book_num - 1].countity);
					countity--;
					if (!countity)
					non_fiction[book_num-1].status = "Unavailable";
					non_fiction[book_num - 1].countity = to_string(countity);
				}

				else if (cart_vector[i].first == 5)
				{
					countity = string_to_int(science_fiction[book_num - 1].countity);
					countity--;
					if (!countity)
				    science_fiction[book_num-1].status = "Unavailable";
					science_fiction[book_num - 1].countity = to_string(countity);
				}


			}
			cart_vector.clear();
			structs_to_files();
			cout << "Successfully checked out !\n\n";
			return;
		}

		else if (choice == "No" || choice == "no")
		return;
		
		else
		{
			cout << "Invalid choice!\n\n";
			continue;
		}

	}
}

//******************************	End cart			*************************