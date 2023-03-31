#include <iostream>
#include<string>
using namespace std;
const int arrsize = 10000;

struct cart
{
    string title;
    float price;
}reader[100];

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
int main() {
    char answer = 'y';
    int number, section = 0, number_of_books = 0;
    if (section == 1)
        do {
            cin >> number;  // number = index + 1 of books in certain array
            number_of_books++;
            cout << "do you want to add another book? y/n \t";
            cin >> answer;
            if (answer == 'n' || answer == 'N')
                break;
            else if (answer == 'y' || answer == 'Y')
                continue;
            else
                cout << "invalid option";
        } while (answer != 'n');
        cout << " you chose" << number_of_books << "books";

        return 0;
}