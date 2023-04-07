#include <iostream>
#include<string>
using namespace std;
struct book
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
int main()
{
	addbook();
	editbook();
	return 0;
}

