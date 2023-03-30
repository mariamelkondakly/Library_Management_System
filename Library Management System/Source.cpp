#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int arrsize = 10000;
int fantasy_num = 9;
int mystery_num = 10;
int romance_num = 9;
int non_fiction_num = 9;
int science_fiction_num = 9;

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
	ifstream file("mystery.txt");

	if (file.is_open()) {
		for (int i = 0; i < mystery_num; i++) {
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
				else if (index == 2)    romance[i].discription = line;
				else if (index == 3)    romance[i].type = line;
				else if (index == 4)    romance[i].status = line;
				else if (index == 5)    romance[i].price = line;
				else if (index == 6)    romance[i].numofpages = line;
				else if (index == 7)    romance[i].review = line;
				index++;
				if (index == 8)	break;
			}
		}
	}
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
				else if (index == 2)    non_fiction[i].discription = line;
				else if (index == 3)    non_fiction[i].type = line;
				else if (index == 4)    non_fiction[i].status = line;
				else if (index == 5)    non_fiction[i].price = line;
				else if (index == 6)    non_fiction[i].numofpages = line;
				else if (index == 7)    non_fiction[i].review = line;
				index++;
				if (index == 8)	break;
			}
		}
	}
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
				else if (index == 2)    science_fiction[i].discription = line;
				else if (index == 3)    science_fiction[i].type = line;
				else if (index == 4)    science_fiction[i].status = line;
				else if (index == 5)    science_fiction[i].price = line;
				else if (index == 6)    science_fiction[i].numofpages = line;
				else if (index == 7)    science_fiction[i].review = line;
				index++;
				if (index == 8)	break;
			}
		}
	}
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


int main()
{
	files_to_struct();
	cout << romance[0].title << "\n\n";
	return 0;
}


