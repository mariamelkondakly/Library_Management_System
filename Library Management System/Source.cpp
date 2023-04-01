#include <iostream>
#include<string>
using namespace std;
const int arrsize = 10000;
char answer = 'y';
int number, section = 0, number_of_books = 0; int answers;
void empty() {
    cout << "\033[2J\033[1;1H";
};

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
int check(int number, char answer) {
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
    return number_of_books;

};
int main() {
    int section;
    cout << "which section,would you like to choose?" << endl << "1.fantasy\n" << "2.mystery\n" << "3.romance\n" << "4.non_fiction\n" << "5.science_fiction\n";
    cin >> section;
    switch (section) {
    case 1:
        check(number, answer);
        break;
    case 2:
        check(number, answer);
        break;
    case 3:
        check(number, answer);
        break;
    case 4:
        check(number, answer);
        break;
    case 5:
        check(number, answer);
        break;

    }
    cout << "would you like to :" << endl << "1.see your cart" << endl << "2.go back to your home page";
    cin >> answers;
    if (answers == 1) {
        empty();
        for (int i = 0; i < number_of_books; i++) {
            cout << "book" << i + 1 << ':' << reader[i].title << endl;
            cout << "price:" << reader[i].price;
        }


    }
    else if (answer == 2) {
        empty();
        //menu

    }


    return 0;
}