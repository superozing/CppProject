// #include "Book.h"
#include <stdio.h>

enum bookCategorize
{
	�ѷ� = 0,
	ö��,
	����,
	��ȸ����,
	�ڿ�����,
	�������,
	����,
	���,
	����,
	����
};

int main()
{	
	//Book* B1 = new Book("InMyPJH","PJH",99999,999,000,10);

	//cout << "Bookshop Management" << endl << "***PROGRAM***" << endl;
	//cout << "0. Book selection" << endl;
	//cout << "1. Sell Book" << endl;
	//cout << "2. " << endl;
	enum bookCategorize cb = �ѷ�;
	printf("%d \n", (int)cb);
	return 0;
}
