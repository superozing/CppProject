#include "Book.h"

// 책 정보 반환
string	Book::bookName()	{ return m_bookName; }
string	Book::bookAuthor()	{ return m_bookAuthor; }
int		Book::price()		{ return m_price; }
int		Book::page()		{ return m_page; }
int		Book::bookID()		{ return m_bookID; }

// 책 정보 반환 - 재고
int		Book::bookStock()	{ return m_bookStock; }
int		Book::sellCount()	{ return m_sellCount; }

// 책 정보 수정
void	Book::reBookName(string _BookName)		{ m_bookName	= _BookName; }
void	Book::reBookAuthor(string _AuthorName)  { m_bookAuthor	= _AuthorName; }
void	Book::rePrice(int _price)				{ m_price		= _price; }
void	Book::rePage(int _pageCount)			{ m_page		= _pageCount; }
void	Book::reCategorize(int _CategorizeCount) 
{
	if (0 <= _CategorizeCount && 9 >= _CategorizeCount)
		m_bookID = m_bookID - (m_bookID / 100) * 100 + _CategorizeCount * 100;
	else
		cout << "********UnacceptableCategoryValues********" << endl;
}

// 책의 정보 출력
void Book::BookINFO()
{
	// 1. bookName 출력
	if ("__notFound" != m_bookName) 
		cout << "BookName  : " << m_bookName << endl;
	else 
		cout << "BookName  : \"Not set\"" << endl;
	
	// 2. pageCount 출력
	if (-1 != m_page) 
		cout << "Pages     : " << m_page << endl;
	else 
		cout << "Pages     : \"Not set\"" << endl;
			
	// 3. categorize 출력
	switch (m_bookID/100)
	{
	case 0:
		cout << "Categorize: 총류" << endl;
		break;	
	case 1:
		cout << "Categorize: 철학" << endl;
		break;
	case 2:
		cout << "Categorize: 종교" << endl;
		break;
	case 3:
		cout << "Categorize: 사회과학" << endl;
		break;
	case 4:
		cout << "Categorize: 자연과학" << endl;
		break;
	case 5:
		cout << "Categorize: 기술과학" << endl;
		break;
	case 6:
		cout << "Categorize: 예술" << endl;
		break;
	case 7:
		cout << "Categorize: 언어" << endl;
		break;
	case 8:
		cout << "Categorize: 문학" << endl;
		break;
	case 9:
		cout << "Categorize: 역사" << endl;
		break;
	case -1:
		cout << "Categorize: \"Not set\"" << endl;
		break;
	default:
		cout << "Assert" << endl;
		assert(nullptr);
	}
	cout << endl;
}

/////////////////////////////////////////////////////////
// 생성자, 소멸자
Book::Book()
	: m_bookName("__notFound")
	, m_bookAuthor("__notFound")
	, m_price(-1)
	, m_page(-1)
	, m_bookID(-1)

	, m_bookStock(0)
	, m_sellCount(0)
{
}

Book::Book(string _bookName, string _bookAuthor, int _price, int _page, int _categorize, int _bookStock)
	: m_bookName("__notFound")
	, m_bookAuthor("__notFound")
	, m_price(_price)
	, m_page(_page)
	, m_bookID(NULL)

	, m_bookStock(_bookStock)
	, m_sellCount(0)
{
	switch (_categorize)
	{
	case 000:
		m_bookID = _categorize + m_arrID[0]++;
		break;
	case 100:
		m_bookID = _categorize + m_arrID[1]++;
		break;
	case 200:
		m_bookID = _categorize + m_arrID[2]++;
		break;
	case 300:
		m_bookID = _categorize + m_arrID[3]++;
		break;
	case 400:
		m_bookID = _categorize + m_arrID[4]++;
		break;
	case 500:
		m_bookID = _categorize + m_arrID[5]++;
		break;
	case 600:
		m_bookID = _categorize + m_arrID[6]++;
		break;
	case 700:
		m_bookID = _categorize + m_arrID[7]++;
		break;
	case 800:
		m_bookID = _categorize + m_arrID[8]++;
		break;
	case 900:
		m_bookID = _categorize + m_arrID[9]++;
		break;
	default:
		cout << "********ExactCategoryAndBookIDNotSet********" << endl;
		m_bookID = -1;
	}

}

Book::~Book()
{
}

