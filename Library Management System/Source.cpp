#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int arrsize = 10000;
int fantasy = 9;
int mystery = 10;
int int romance = 9;

//array size of books
//type is whether book is digital, paperback or hardcover

void file_to_fantasy()
//converting file to the fantasy struct
{
	string line;
	int index;
	ifstream file("Fantasy.txt");

	if (file.is_open()) {
		for (int i = 0; i < 2; i++) {
			index = 0;
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
				if (index == 8)	break;
			}
		}
	}
}

void file_to_mystery()
//converting file to the mystery struct
{
	string line;
	int index;
	ifstream file("Mystery.txt");

	if (file.is_open()) {
		for (int i = 0; i < 2; i++) {
			index = 0;
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
				if (index == 8)	break;
			}
		}
	}
}

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


int main()
{
	books_to_struct();
	cout << fantasy[1].title << "\n\n";
	return 0;
}


