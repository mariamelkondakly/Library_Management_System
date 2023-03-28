#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int arrsize = 10000000; 

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

}
