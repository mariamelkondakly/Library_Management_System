#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int arrsize = 10000;
int fantasy_num = 10, mystery_num = 11, romance_num = 10, non_fiction_num = 10, science_fiction_num = 10;
int fantasycounter = 0, mysterycounter = 0, romancecounter = 0, non_fictioncounter = 0, science_fictioncounter = 0;

//array size of books
//type is whether book is digital, paperback or hardcover

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
				else if (index == 2)    fantasy[i].discription = line;
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
				else if (index == 2)    mystery[i].discription = line;
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
				else if (index == 2)    romance[i].discription = line;
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
				else if (index == 2)    non_fiction[i].discription = line;
				else if (index == 3)    non_fiction[i].type = line;
				else if (index == 4)    non_fiction[i].status = line;
				else if (index == 5)    non_fiction[i].price = line;
				else if (index == 6)    non_fiction[i].numofpages = line;
				else if (index == 7)    non_fiction[i].review = line;
				index++;
				if (line == "##") { non_fictioncounter++; break; }
				if (index == 8)	break;
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
				else if (index == 2)    science_fiction[i].discription = line;
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
			else if (j == 2) file << fantasy[i].discription << endl;
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
			else if (j == 2) file << mystery[i].discription << endl;
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
			else if (j == 2) file << romance[i].discription << endl;
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
			else if (j == 2) file << non_fiction[i].discription << endl;
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
			else if (j == 2) file << science_fiction[i].discription << endl;
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

void editbook(book& edit)
{
	int choice;
	char x;

	cout << "Do you want to edit information for this book   ";
	cin >> x;
	if (x == 'y' || x == 'Y')
	{
		do{
			
			cout << "1: edit auther name\n\n";
			cout << "2: edit discription\n\n";
			cout << "3: edit type\n\n";
			cout << "4: edit status\n\n";
			cout << "5: edit price\n\n";
			cout << "6: edit number of pages\n\n";
			cout << "7: edit review\n\n";
			cout << "0: back\n\n";
			cin >> choice;

			switch (choice)
			{
			case 1:cout << "enter new author name";
				cin.ignore();
				getline(cin, edit.author);
				break;
			case 2:cout << "enter new discription";
				getline(cin, edit.discription);
				break;
			case 3:cout << "enter new type";
				getline(cin, edit.type);
				break;
			case 4: cout << "enter new status";
				getline(cin, edit.status);
				break;
			case 5:cout << "enter new price";
				getline(cin, edit.price);
				break;
			case 6:cout << "enter new num of pages";
				getline(cin, edit.numofpages);
				break;
			case 7:cout << "enter new review";
				cin.ignore();
				getline(cin, edit.review);
				break;
			}
		} while (choice != 0);
	}

	else if (x == 'n' || x == 'N')
		return;

	else
	{
		cout << " invalid choice\n\n";
		editbook(edit);
	}
}

void select_book(int section_num) // showing the data of a specified book
{
	int num_book;
	char x;
	cout << "Please Enter the number of the book : ";
	cin >> num_book;
	cout << endl;
	if (section_num == 1)
	{
		cout << "Author name : " << fantasy[num_book-1].author << endl << endl;
		cout << "The discription :" << fantasy[num_book-1].discription << endl << endl;
		cout << "The type of the book : " << fantasy[num_book-1].type << endl << endl;
		cout << "The status of the book : " << fantasy[num_book-1].status << endl << endl;
		cout << "The price : " << fantasy[num_book-1].price << endl << endl;
		cout << "Number of pages : " << fantasy[num_book-1].numofpages << endl << endl;
		cout << "The rate of the book : " << fantasy[num_book-1].review << endl << endl;

		editbook(fantasy[num_book]);
	}

	else if (section_num == 2)
	{
		cout << "Author name : " << mystery[num_book - 1].author << endl << endl;
		cout << "The discription :" << mystery[num_book - 1].discription << endl << endl;
		cout << "The type of the book : " << mystery[num_book - 1].type << endl << endl;
		cout << "The status of the book : " << mystery[num_book - 1].status << endl << endl;
		cout << "The price : " << mystery[num_book - 1].price << endl << endl;
		cout << "Number of pages : " << mystery[num_book - 1].numofpages << endl << endl;
		cout << "The rate of the book : " << mystery[num_book - 1].review << endl << endl;
		editbook(mystery[num_book]);
	}

	else if (section_num == 3)
	{
		cout << "Author name : " << romance[num_book - 1].author << endl << endl;
		cout << "The discription :" << romance[num_book - 1].discription << endl << endl;
		cout << "The type of the book : " << romance[num_book - 1].type << endl << endl;
		cout << "The status of the book : " << romance[num_book - 1].status << endl << endl;
		cout << "The price : " << romance[num_book - 1].price << endl << endl;
		cout << "Number of pages : " << romance[num_book - 1].numofpages << endl << endl;
		cout << "The rate of the book : " << romance[num_book - 1].review << endl << endl;
		editbook(romance[num_book]);
	}

	else if (section_num == 4)
	{
		cout << "Author name : " << non_fiction[num_book - 1].author << endl << endl;
		cout << "The discription :" << non_fiction[num_book - 1].discription << endl << endl;
		cout << "The type of the book : " << non_fiction[num_book - 1].type << endl << endl;
		cout << "The status of the book : " << non_fiction[num_book - 1].status << endl;
		cout << "The price : " << non_fiction[num_book - 1].price << endl << endl;
		cout << "Number of pages : " << non_fiction[num_book - 1].numofpages << endl << endl;
		cout << "The rate of the book : " << non_fiction[num_book - 1].review << endl << endl;
		editbook(non_fiction[num_book]);
	}

	else if (section_num == 5)
	{
		cout << "Author name : " << science_fiction[num_book - 1].author << endl << endl;
		cout << "The discription :" << science_fiction[num_book - 1].discription << endl << endl;
		cout << "The type of the book : " << science_fiction[num_book - 1].type << endl << endl;
		cout << "The status of the book : " << science_fiction[num_book - 1].status << endl << endl;
		cout << "The price : " << science_fiction[num_book - 1].price << endl << endl;
		cout << "Number of pages : " << science_fiction[num_book - 1].numofpages << endl << endl;
		cout << "The rate of the book : " << science_fiction[num_book - 1].review << endl << endl;
		editbook(science_fiction[num_book]);
	}


}

void sections()
{
	int section_num;

	cout << "1 - Fantasy\n" << "2 - Mystery\n" << "3 - Romantic\n" << "4 - Non fiction\n" << "5 - Scientific fiction\n";

	cout << "Please enter the number of the section : ";

	cin >> section_num;

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
		cout << "Invalid Section\n";
		sections();
	}

	select_book(section_num);

}


/*void addbook() {
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
}*/




int main()
{
	files_to_struct();
	sections();
	structs_to_files();
	return 0;
}
