#include "Book.h"

using namespace std;

void informationMode(int& selector, Book* _book)
{
	string	fs = "";
	int		fi = 0;
	selector = 0;
	cout << "1. set book name" << endl;
	cout << "2. print book name" << endl << endl;

	cout << "3. set author name" << endl;
	cout << "4. print author name" << endl << endl;

	cout << "5. set price" << endl;
	cout << "6. print price" << endl << endl;

	cout << "7. set page" << endl;
	cout << "8. print page" << endl << endl;

	cout << "9. set Categorize" << endl;
	cout << "10. print Categorize" << endl;
	cout << "11. print bookID" << endl << endl;

	cout << "12. print all info " << endl << endl;

	cout << "else. main menu " << endl << endl;

	cout << "select funcion number: ";
	cin >> selector;
	system("cls");
	switch (selector)
	{
	case 1:
		cout << "set book name: ";
		cin >> fs;
		_book->setName(fs);

		break;
	case 2:
		cout << "Book name: ";
		cout << _book->bookName();
		break;
	case 3:
		cout << "set author name: ";
		cin >> fs;
		_book->setAuthor(fs);
		break;
	case 4:
		cout << "author name: ";
		cout << _book->bookAuthor();
		break;
	case 5:
		cout << "set book price: ";
		cin >> fi;
		_book->setPrice(fi);
		break;
	case 6:
		cout << "Book price: ";
		cout << _book->price();
		break;
	case 7:
		cout << "set book page: ";
		cin >> fi;
		_book->setPage(fi);
		break;
	case 8:
		cout << "Book page: ";
		cout << _book->page();
		break;
	case 9:
		cout << "set categorize: ";
		cin >> fi;
		_book->setCategorize(fi);
		break;
	case 10:
		cout << "Book categorize: ";
		cout << _book->categorize();
		break;
	case 11:
		cout << "Book ID: ";
		cout << _book->bookID();
		break;
	case 12:
		_book->bookInfo();
		break;
	default:
		break;
	}
}

void stockMode(int& selector, Book* _book)
{
	string	fs = "";
	int		fi = 0;
	selector = 0;
	cout << "1. print book Stock" << endl;
	cout << "2. update book Stock" << endl;
	cout << "3. add-sub book Stock" << endl << endl;

	cout << "4. print sellCount" << endl << endl;

	cout << "else. main menu" << endl << endl;

	cout << "select funcion number: ";
	cin >> selector;
	system("cls");
	switch (selector)
	{
	case 1:
		cout << "Book stock: ";
		cout << _book->s_bookStock();
		break;
	case 2:
		cout << "set book stock: ";
		cin >> fi;
		_book->s_updateStock(fi);
		break;
	case 3:
		cout << " add-sub book stock: ";
		cin >> fi;
		_book->s_addSubStock(fi);
		break;
	case 4:
		cout << "Book sellCount: ";
		cout << _book->s_sellCount();
		break;
	default:
		break;
	}
}

void BookMode(Book* _book)
{
	int selector = 0;
	_book->bookInfo();

	selector = 0;
	cout << endl << "1. Information" << endl;
	cout << "2. stock" << endl;
	cout << "3. SELL BOOK " << endl;
	cout << "else. main menu" << endl << endl;
	cout << "select funcion number: ";
	cin >> selector;
	system("cls");
	switch (selector)
	{
	case 1:
		system("cls");
		informationMode(selector, _book);
		break;
	case 2:
		system("cls");
		stockMode(selector, _book);
		break;
	case 3:
		system("cls");
		_book->s_sell();
		break;
	default:
		break;
	}
		
}

int main()
{	
	Book* b1 = new Book("InMyPJH", "PJH", 7500, 210, 0, 10);
	Book* b2 = new Book("Fuck You PJH", "PZH", 9000, 300, 500, 10);
	Book* b3 = new Book("InMyPJH2","PJH",7500,210,100,10);

	int selector = 0;

	while (true)
	{
		selector = 0;
		
		cout << "**********Bookshop Management System**********" << endl;
		cout << "- Today --------------------------------------" << endl;
		cout << "sell count : " << itodaySell << endl;
		cout << "income     : " << itodayIncome << endl << endl;

		cout << "- BOOK LIST ----------------------------------" << endl;
		cout << "1. InMyPJH" << endl;
		cout << "2. Fuck You PJH" << endl;
		cout << "3. InMyPJH2" << endl;
		cout << "select book number: ";
		cin >> selector;
		system("cls");
		switch (selector)
		{
		case 1:
			BookMode(b1);
			break;
		case 2:
			BookMode(b2);
			break;
		case 3:
			BookMode(b3);
			break;
		}
		system("cls");
		if (!(1 == (int)selector || 2 == (int)selector || 3 == (int)selector))
			cout << "problem: You need select number 1~3" << endl << endl;
	}
	
	return 0;
}
