#include <iostream>
#include<string>
using namespace std;
const int arrsize = 10000;
int fantasy_num = 10, mystery_num = 11, romance_num = 10, non_fiction_num = 10, science_fiction_num = 10;
struct book
{
	string title;
	string author;
	string discription;
	string type;
	string status;
	string price;
	string numofpages;
	string review;

} fantasy[arrsize], mystery[arrsize], romance[arrsize], non_fiction[arrsize], science_fiction[arrsize];

struct delete_book
{
	string author;
	string discription;
	string type;
	string status;
	int price;
	int numofpages;
	string review;

}book;

void addbook() {
	cout << "enter authorname  : ";
	getline(cin, book.author);
	cout << "enter the discription  :  ";
	getline(cin, book.discription);
	cout << "enter the type  :  ";
	cin >> book.type;
	cout << "enter the status  :  ";
	getline(cin, book.status);
	cout << "enter price  :  ";
	cin >> book.price;
	cout << "enter numper of pages  :  ";
	cin >> book.numofpages;
	cin.ignore();
	cout << "enter review";
	getline(cin, book.review);
}


void editbook()
{
	int choice;
	do
	{
		cout << "1: edit auther name";
		cout << "2: edit discription";
		cout << "3: edit type";
		cout << "4: edit status";
		cout << "5: edit price";
		cout << "6: edit numper of pages";
		cout << "7: edit review";
		cout << "0: back";
		cin >> choice;

		switch (choice)
		{
		case 1:cout << "enter new author name";
			cin.ignore();
			getline(cin, book.author);
			break;
		case 2:cout << "enter new discription";
			getline(cin, book.discription);
			break;
		case 3:cout << "enter new type";
			getline(cin, book.type);
			break;
		case 4: cout << "enter new status";
			getline(cin, book.status);
			break;
		case 5:cout << "enter new price";
			cin >> book.price;
			break;
		case 6:cout << "enter new num of pages";
			cin >> book.numofpages;
			break;
		case 7:cout << "enter new review";
			cin.ignore();
			getline(cin, book.review);
			break;
		}

	} while (choice != 0);

}


void options()
{
	int choices;
	do
	{
		cout << "1 : add new book";
		cout << "2 : edit book ";
		cout << "0: return homepage";
		cin >> choices;
		switch (choices)
		{
		case 1: addbook();
			break;
		case 2: editbook();
			break;
		}

	} while (choices != 0);

}

void delete_book(int section_index, int book_index) {
	if (section_index == 0) {
		for (int i = book_index;i < fantasy_num - 1;i++) {
			fantasy[i] = fantasy[i + 1];
		}
		fantasy_num--;
	}
	else if(section_index == 1)
	{  
		for (int i = book_index;i < mystery_num - 1;i++) {
			mystery[i] = mystery[i + 1];
		}
		mystery_num--;
	}
	else if (section_index == 2)
	{
		for (int i = book_index;i < romance_num - 1;i++) {
			romance[i] = romance[i + 1];
		}
		romance_num--;
	}
	else if (section_index == 3)
	{
		for (int i = book_index;i < non_fiction_num - 1;i++) {
			non_fiction[i] = non_fiction[i + 1];
		}
		non_fiction_num--;
	}
	else if (section_index == 4)
	{
		for (int i = book_index;i < science_fiction_num - 1;i++) {
			science_fiction[i] = science_fiction[i + 1];
		}
		science_fiction_num--;
	}
}


int main()
{
	addbook();
	editbook();
	return 0;
}

