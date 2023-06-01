#include "Book.h"
#include "json.hpp"
#include <vector>
#include <iostream>
#include <fstream>


// using 키워드 사용
using json = nlohmann::json; 
using namespace std;

const int	INVALID_ID	= -1;
const int	VALID_ID	= 1;

// 전역 함수를 정의합니다: 
int  mainScreen(vector<Book*>& bookList);

void selectFunction(vector<Book*>& bookList);
void BookMode(Book* _book);
void informationMode(Book* _book);
void stockMode(Book* _book);
	
void selectBookList(const vector<Book*>& bookList);
	
void addBook(vector<Book*>& bookList);
void deleteBook(vector<Book*>& bookList);

void readBooklistFile(json& data, std::vector<Book*>& bookList, Book*& bookBuffer);
void saveBooklistFile(std::vector<Book*>& bookList, json& jBookBuffer, json& jBookList);

/////////////////////////////////////////////////////////////////////////////////////////////
// main() 함수를 정의합니다:
int main()
{
	// whlie 안의 mainscreen이 반복될지 말지를 정하는 keepLooping 
	bool	keepLooping		= true;	
	
	// 책을 보관할 벡터 bookList
	vector<Book*> bookList;

	// 책의 정보를 들고있다가 bookList에 넣기 위한 변수인 bookBuffer
	Book*	bookBuffer	= {};

	// json 데이터 입출력 변수
	json	data;
	json	jsonBookList;
	json	jsonBookBuffer;


	// booklist.json에서 데이터 읽어오기
	readBooklistFile(data, bookList, bookBuffer);

	// main()함수가 종료되지 않게 하기 위한 반복자. 절대 건들지 마세요.
	while (keepLooping) keepLooping = mainScreen(bookList); 

	// booklist.json에  데이터 저장하기
	saveBooklistFile(bookList, jsonBookBuffer, jsonBookList);

	// 종료 이후 heab 공간 해제, bookList지우기
	for (Book* pbook : bookList) delete pbook;
	bookList.clear();

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
void saveBooklistFile(std::vector<Book*>& bookList, json& jBookBuffer, json& jBookList)
{
	for (const auto& pBook : bookList)
	{
		jBookBuffer["m_name"] = pBook->getBookName();
		jBookBuffer["m_author"] = pBook->getBookAuthor();
		jBookBuffer["m_price"] = pBook->getPrice();
		jBookBuffer["m_page"] = pBook->getPage();
		jBookBuffer["m_categorize"] = pBook->getCategorize();
		jBookBuffer["m_sStock"] = pBook->getStock();

		jBookList.push_back(jBookBuffer);
	}

	cout << jBookList << endl;

	ofstream oFile("bookdata.json");

	if (oFile.is_open())
	{
		oFile << jBookList.dump(4); // 들여쓰기를 포함한 형식으로 데이터를 파일에 쓰기
		oFile.close(); // 파일 닫기
		std::cout << "JSON data has been successfully written to a file." << std::endl;
	}
	else
	{
		std::cerr << "cannot open file." << std::endl;
	}
}

void readBooklistFile(json& data, std::vector<Book*>& bookList, Book*& bookBuffer)
{
	// bookdata.json에서 json객체 읽어오기
	ifstream iFile("bookdata.json");

	if (!(iFile.is_open())) std::cerr << "cannot open file." << std::endl;

	iFile >> data;

	for (const auto& pd : data)
	{
		bookList.push_back(bookBuffer = new Book(pd["m_name"], pd["m_author"], pd["m_price"], pd["m_page"], pd["m_categorize"], pd["m_sStock"]));
	}

	std::cout << "JSON 데이터를 정상적으로 읽어왔습니다." << std::endl;
	iFile.close(); // 파일 닫기
}


void informationMode(Book* _book)
{
	string	fs = "";
	int		fi = 0;
	int		selector = 0;
	_book->bookInfo();

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
		if (INVALID_ID == _book->setName(fs)) return;
		_book->setName(fs);
		cout << endl;
		break;
	case 2:
		cout << "Book name: ";
		cout << _book->getBookName();
		cout << endl;
		break;
	case 3:
		cout << "set author name: ";
		cin >> fs;
		if (INVALID_ID == _book->setAuthor(fs)) return;
		_book->setAuthor(fs);
		cout << endl;
		break;
	case 4:
		cout << "author name: ";
		cout << _book->getBookAuthor();
		cout << endl;
		break;
	case 5:
		cout << "set book price: ";
		cin >> fi;
		if (INVALID_ID == _book->setPrice(fi)) return;
		_book->setPrice(fi);
		cout << endl;
		break;
	case 6:
		cout << "Book price: ";
		cout << _book->getPrice();
		cout << endl;
		break;
	case 7:
		cout << "set book page: ";
		cin >> fi;
		if (INVALID_ID == _book->setPage(fi)) return;
		_book->setPage(fi);
		cout << endl;
		break;
	case 8:
		cout << "Book page: ";
		cout << _book->getPage();
		cout << endl;
		break;
	case 9:
		cout << "set categorize: ";
		cin >> fi;
		if (INVALID_ID == _book->setCategorize(fi)) return;
		_book->setCategorize(fi);
		cout << endl;
		break;
	case 10:
		cout << "Book categorize: ";
		cout << _book->getCategorize();
		cout << endl;
		break;
	case 11:
		cout << "Book ID: ";
		cout << _book->getBookID();
		cout << endl;
		break;
	case 12:
		_book->bookInfo();
		cout << endl;
		break;
	default:
		break;
	}
}

void stockMode(Book* _book)
{
	string	fs			= "";
	int		fi			= 0;
	int		selector	= 0;

	_book->bookInfo();

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
		cout << _book->getStock();
		cout << endl;
		break;
	case 2:
		cout << "set book stock: ";
		cin >> fi;
		if (INVALID_ID == _book->setStock(fi)) return;
		_book->setStock(fi);
		cout << endl;
		break;
	case 3:
		cout << " add-sub book stock: ";
		cin >> fi;
		if (INVALID_ID == _book->setAddSubStock(fi)) return;
		_book->setAddSubStock(fi);
		cout << endl;
		break;
	case 4:
		cout << "Book sellCount: ";
		cout << _book->getTotalSellCount();
		cout << endl;
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
		informationMode(_book);
		break;
	case 2:
		system("cls");
		stockMode(_book);
		break;
	case 3:
		system("cls");
		_book->sellBook();
		break;
	default:
		break;
	}

}

void selectBookList(const vector<Book*>& bookList)
{
	int		selector	= 0;
	Book*	book		= {};

	system("cls");
	cout << "- BOOK LIST ----------------------------------" << endl;
	for (int i = 0; i < bookList.size(); ++i)
		cout << i + 1 << ". " << bookList[i]->getBookName() << endl;
	cout << endl << "0. main menu" << endl;

	cout << "select book number: ";
	cin >> selector;
	system("cls");

	if (selector == 0)
		return;
	else if (selector <1 || selector>bookList.size())
		cout << "problem: You need select number 1~" << bookList.size() << endl << endl;
	else
	{
		book = bookList[--selector];
		BookMode(book);
	}
}

void addBook(vector<Book*>& bookList)
{
	int		check	= 0;
	while (true)
	{
		cout << "Are you sure you want to make a book? (yes: 1, no: 0) :";
		cin >> check;
		if (check == 1)
			break;
		else if (check == 0)
			return;
	}
	Book*	book	= new Book();
	string	fs		= "";
	int		fi		= 0;
	
	cout << "Categorize(Enter in 100 units): ";
	cin >> fi;
	fi = book->setCategorize(fi);
	if (fi != 1) return;

	cout << "Book name: ";
	cin >> fs;
	book->setName(fs);

	cout << "Book Author: ";
	cin >> fs; 
	book->setAuthor(fs);

	cout << "Price: ";
	cin >> fi;
	book->setPrice(fi);

	cout << "Pages: ";
	cin >> fi;
	book->setPage(fi);

	bookList.push_back(book);

}


void deleteBook(vector<Book*>& bookList)
{
	int		check = 1;
	while (check)
	{
		cout << "Are you sure you want to DELETE A BOOK? (yes: 1, no: 0) :";
		cin >> check;
		if (check == 1)
			break;
		else if (check == 0)
			return;
	}
	cout << "Enter the book ID of the book you want to delete correctly :";
	cin >> check;
	for (int i = 0; i < bookList.size(); ++i)
	{
		if (check == bookList[i]->getBookID())
		{
			vector<Book*>::iterator it = bookList.begin() + i;
			cout << "The book with the following title has been deleted: " 
				<< bookList[i]->getBookName() << endl;
			bookList.erase(it);
			return;
		}
	}
	cout << "problem: You must enter a valid bookID." << endl;

	
}

void selectFunction(vector<Book*>& bookList)
{
	int selector = 1;
	selector = 0;
	cout << "- Funcion ------------------------------------" << endl;
	cout << "1. add Book" << endl;
	cout << "2. delete Book" << endl;
	cout << endl << "0. main menu" << endl;
	cout << "select number: ";
	cin >> selector;
	system("cls");
	switch (selector)
	{
	case 1:
		addBook(bookList);
		break;
	case 2:
		deleteBook(bookList);
		break;
	case 0:
		return;
	default:
		break;
	}
}



int mainScreen(vector<Book*>& bookList)
{
	int selector	= 0;
	int	totalSell	= 0; 
	int totalIncome = 0;

	for (const auto& pBook : bookList)//int i = 0; i < bookList.size(); ++i)
	{
		totalSell += pBook->getTotalSellCount();
		totalIncome += pBook->getTotalIncome();
	}

	cout << "**********Bookshop Management System**********" << endl;
	cout << "- Today --------------------------------------" << endl;
	cout << "sell count : " << totalSell << endl;
	cout << "income     : " << totalIncome << endl << endl;
	cout << "- Menu ---------------------------------------" << endl;
	cout << "1. bookList" << endl;
	cout << "2. function" << endl << endl;

	cout << "0. Exit program" << endl << endl;

	cout << "select number: ";
	cin >> selector;

	system("cls");
	switch (selector)
	{
	case 1:
		selectBookList(bookList);
		break;
	case 2:
		selectFunction(bookList);
		break;
	case 0:
		cout << "Save and exit book data." << endl << "You did a great job today." << endl << endl;
		return 0;
	default:
		break;
	}

	return 1;
}
