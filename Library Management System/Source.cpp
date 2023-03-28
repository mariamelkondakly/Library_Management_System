#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int arrsize = 10; 

//array size of books
//type is whether book is digital, paperback or hardcover

struct book
{
	string title;
	string author;
	string discription;
	string type;
	string status;
	float price;
	int numofpages;
	float review;

} fantasy[arrsize], action[arrsize], romcom[arrsize], nonfiction[arrsize], scifi[arrsize];

int main()
{
	fantasy[0] = { "Red Queen", "Victoria Aveyard"," ", "hardcover", "available", 7.98, 388, 4.02 };
	cout << fantasy[0].title;
}
