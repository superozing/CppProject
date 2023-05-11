#include "Book.h"

int Book::todaySellCount = 0;
int Book::todaySellMoney = 0;
int IDBuffer[10] = { 0 };

// 전체 재고 반환
int		Book::todaySell() { return todaySellCount; }
int		Book::todayIncome() { return todaySellMoney; }

// 책 정보 반환
string	Book::bookName()	{ return m_name; }
string	Book::bookAuthor()	{ return m_author; }
int		Book::price()		{ return m_price; }
int		Book::page()		{ return m_page; }
int		Book::bookID()		{ return m_id; }
int		Book::categorize()  { return m_categorize; }
// 책 정보 반환 - 재고
int		Book::s_bookStock()	{ return ms_bookStock; }
int		Book::s_sellCount()	{ return ms_sellCount; }

void Book::s_updateStock(int _stock)
{
	if (0 > _stock)
	{
		cout << "problem: The remaining stock cannot be less than 0." << endl;
		return;
	}
	ms_bookStock = _stock;
	cout << "The stock has been set to " << ms_bookStock << " ." << endl;
}

void Book::s_addSubStock(int _addSubStock)
{
	if (0 > ms_bookStock + _addSubStock)
	{
		cout << "problem: The remaining stock cannot be less than 0." << endl;
		return;
	}
	ms_bookStock += _addSubStock;
	cout << "The stock has been changed by " << _addSubStock << " and set to " << ms_bookStock<< " ." << endl;
}

void Book::s_sell()
{
	if (0 >= ms_bookStock)
	{
		cout << "problem: There is not enough stock to sell." << endl;
		return;
	}
	--ms_bookStock;
	++ms_sellCount;
	++todaySellCount;
	todaySellMoney += m_price;
	cout << "The selling has been completed." << endl;
}

// 책 정보 수정
void	Book::setName(string _BookName)		{ m_name	= _BookName; }
void	Book::setAuthor(string _AuthorName) { m_author	= _AuthorName; }

void	Book::setPrice(int _price)			{ m_price	= _price; }
void	Book::setPage(int _pageCount)		{ m_page	= _pageCount; }
void	Book::setCategorize(int _CategorizeCount) 
{
	if (000 == _CategorizeCount || 100 == _CategorizeCount || 200 == _CategorizeCount || 300 == _CategorizeCount ||
		400 == _CategorizeCount || 500 == _CategorizeCount || 600 == _CategorizeCount || 700 == _CategorizeCount ||
		800 == _CategorizeCount || 900 == _CategorizeCount)
	{
		m_id = _CategorizeCount + IDBuffer[_CategorizeCount / 100];
	}	
	else
		cout << "problem: must be entered in 100 units only." << endl;
}

// 책의 정보 출력
void Book::bookInfo()
{
	cout << endl;
	if ("__notFound" != m_name) 
		cout << "BookName   : " << m_name << endl;
	else 
		cout << "BookName   : \"Not set\"" << endl;

	if ("__notFound" != m_author)
		cout << "BookAuthor : " << m_author << endl;
	else
		cout << "BookAuthor : \"Not set\"" << endl;

	if (-1 != m_page) 
		cout << "Pages      : " << m_page << endl;
	else 
		cout << "Pages      : \"Not set\"" << endl;

	// categorize
	switch (m_id/100)
	{
	case 0:
		cout << "Categorize : 총류" << endl;
		break;	
	case 1:
		cout << "Categorize : 철학" << endl;
		break;
	case 2:
		cout << "Categorize : 종교" << endl;
		break;
	case 3:
		cout << "Categorize : 사회과학" << endl;
		break;
	case 4:
		cout << "Categorize : 자연과학" << endl;
		break;
	case 5:
		cout << "Categorize : 기술과학" << endl;
		break;
	case 6:
		cout << "Categorize : 예술" << endl;
		break;
	case 7:
		cout << "Categorize : 언어" << endl;
		break;
	case 8:
		cout << "Categorize : 문학" << endl;
		break;
	case 9:
		cout << "Categorize : 역사" << endl;
		break;
	case -1:
		cout << "Categorize : \"Not set\"" << endl;
		break;
	default:
		cout << "Assert" << endl;
		assert(nullptr);
	}

	if (m_id < 10)
		cout << "BookID     : 00" << m_id << endl << endl;
	else if (m_id < 100)
		cout << "BookID     : 0" << m_id << endl << endl;
	else
		cout << "BookID     : " << m_id << endl << endl;

	cout << "price      : " << m_price << endl;
	cout << "stock      : " << ms_bookStock << endl;
	cout << "sell count : " << ms_sellCount << endl;

	cout << endl;
}

/////////////////////////////////////////////////////////
// 생성자, 소멸자
Book::Book()
	: m_name("__notFound")
	, m_author("__notFound")
	, m_price(-1)
	, m_page(-1)
	, m_id(-1)

	, ms_bookStock(0)
	, ms_sellCount(0)
{
}

Book::Book(string _bookName, string _bookAuthor, int _price, int _page, int _categorize, int _bookStock)
	: m_name(_bookName)
	, m_author(_bookAuthor)
	, m_price(_price)
	, m_page(_page)
	, m_categorize(_categorize)
	, m_id(NULL)

	, ms_bookStock(_bookStock)
	, ms_sellCount(0)
{
	switch (_categorize)
	{
	case 000:
		m_id = _categorize + IDBuffer[0]++;
		break;
	case 100:
		m_id = _categorize + IDBuffer[1]++;
		break;
	case 200:
		m_id = _categorize + IDBuffer[2]++;
		break;
	case 300:
		m_id = _categorize + IDBuffer[3]++;
		break;
	case 400:
		m_id = _categorize + IDBuffer[4]++;
		break;
	case 500:
		m_id = _categorize + IDBuffer[5]++;
		break;
	case 600:
		m_id = _categorize + IDBuffer[6]++;
		break;
	case 700:
		m_id = _categorize + IDBuffer[7]++;
		break;
	case 800:
		m_id = _categorize + IDBuffer[8]++;
		break;
	case 900:
		m_id = _categorize + IDBuffer[9]++;
		break;
	default:
		cout << "problem: exact category and bookID not set" << endl;
		m_id = -1;
	}

}

Book::~Book()
{
}



