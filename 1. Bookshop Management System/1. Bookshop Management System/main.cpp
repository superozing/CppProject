// #include "Book.h"
#include <stdio.h>

enum bookCategorize
{
	총류 = 0,
	철학,
	종교,
	사회과학,
	자연과학,
	기술과학,
	예술,
	언어,
	문학,
	역사
};

int main()
{	
	//Book* B1 = new Book("InMyPJH","PJH",99999,999,000,10);

	//cout << "Bookshop Management" << endl << "***PROGRAM***" << endl;
	//cout << "0. Book selection" << endl;
	//cout << "1. Sell Book" << endl;
	//cout << "2. " << endl;
	enum bookCategorize cb = 총류;
	printf("%d \n", (int)cb);
	return 0;
}
