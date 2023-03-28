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
	fantasy[0] = { "Red Queen", "Victoria Aveyard"
					,"The Reds are commoners, ruled by a Silver elite in possession of god-like superpowers. And to Mare Barrow, a seventeen-year-old Red girl from the poverty-stricken Stilts, it seems like nothing will ever change.\n\nThat is until she finds herself working in the Silver Palace. Here, surrounded by the people she hates the most, Mare discovers that, despite her red blood, she possesses a deadly power of her own. One that threatens to destroy the balance of power.\n\nFearful of Mare's potential, the Silvers hide her in plain view, declaring her a long-lost Silver princess, now engaged to a Silver prince. Despite knowing that one misstep would mean her death, Mare works silently to help the Red Guard, a militant resistance group, and bring down the Silver regime.\n\nBut this is a world of betrayal and lies, and Mare has entered a dangerous dance—Reds against Silvers, prince against prince, and Mare against her own heart.\n\n"
					, "hardcover", "available", 7.98, 388, 4.02 };
	cout << fantasy[0].discription;
}
