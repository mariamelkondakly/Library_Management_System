#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int arrsize = 10000; 

//array size of books
//type is whether book is digital, paperback or hardcover

void books_to_struct();

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

void books_to_struct() {
	string line;
	int index;
	ifstream file("books.txt");

	if (file.is_open()) {
		for (int i = 0;i < 2;i++) {
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
