#include "Book.h"
#include <iostream>
#include "main2.cpp"


int					IDBuffer[10] = { 0 };

// 책 정보 반환
std::string	Book::getBookName()		{ return m_name; }
std::string	Book::getBookAuthor()	{ return m_author; }
int			Book::getPrice()		{ return m_price; }
int			Book::getPage()			{ return m_page; }
int			Book::getBookID()		{ return m_id; }
int			Book::getCategorize()	{ return m_categorize; }

// 책 정보 반환 - 재고
int			Book::s_bookStock()		{ return ms_bookStock; }
int			Book::s_sellCount()		{ return ms_sellCount; }
// 전체 재고 반환
int			Book::s_todaySell()		{ return ms_Income; }

int Book::s_updateStock(int _stock)
{
	if (0 > _stock)
	{
		std::cout << "problem: The remaining stock cannot be less than 0." << std::endl;
		return INVALID_ID;
	}
	ms_bookStock = _stock;
	std::cout << "The stock has been set to " << ms_bookStock << " ." << std::endl;
	return VALID_ID;
}

int Book::s_addSubStock(int _addSubStock)
{
	if (0 > ms_bookStock + _addSubStock)
	{
		std::cout << "problem: The remaining stock cannot be less than 0." << std::endl;
		return INVALID_ID;
	}
	ms_bookStock += _addSubStock;
	std::cout << "The stock has been changed by " << _addSubStock 
		<< " and set to " << ms_bookStock<< " ." << std::endl;
	return VALID_ID;
}

int Book::s_sell()
{
	if (0 >= ms_bookStock)
	{
		std::cout << "problem: There is not enough stock to sell." << std::endl;
		return INVALID_ID;
	}
	--ms_bookStock;
	++ms_sellCount;
	ms_Income += m_price;
	std::cout << "The selling has been completed." << std::endl;
	return VALID_ID;
}

// 책 정보 수정
int Book::setName(std::string _BookName)		
{
	if (_BookName.size() <= 100 && _BookName.size() >= 1)
	{
		this->m_name = _BookName;
		return VALID_ID;
	}
	else
	{
		std::cout << "problem: You can enter up to 100 characters" << std::endl;
		return INVALID_ID;
	}
}

int Book::setAuthor(std::string _AuthorName)	
{
	if (_AuthorName.size() <= 100 && _AuthorName.size() >= 1)
	{
		this->m_author	= _AuthorName;
		return VALID_ID;
	}
	else
	{
		std::cout << "problem: You can enter up to 100 characters" << std::endl;
		return INVALID_ID;
	}
}

int Book::setPrice(int _price)					
{ 	
	if (_price <= 1000000 && _price >= 1)
	{
		this->m_price	= _price; 
		return VALID_ID;
	}
	else
	{
		std::cout << "problem: Can only be entered from 1 to 1000000" << std::endl;
		return INVALID_ID;
	}
}

int Book::setPage(int _pageCount)				
{
	if (_pageCount <= 99999 && _pageCount >= 1)
	{
		this->m_page = _pageCount;
		return VALID_ID;
	}
	else
	{
		std::cout << "problem: Can only be entered from 1 to 99999" << std::endl;
		return INVALID_ID;
	}
}

int	Book::setCategorize(int _CategorizeCount)
{
	if (000 == _CategorizeCount || 100 == _CategorizeCount || 200 == _CategorizeCount || 300 == _CategorizeCount ||
		400 == _CategorizeCount || 500 == _CategorizeCount || 600 == _CategorizeCount || 700 == _CategorizeCount ||
		800 == _CategorizeCount || 900 == _CategorizeCount)
	{
		m_id = _CategorizeCount + IDBuffer[_CategorizeCount / 100];
		return VALID_ID;
	}
	else
	{
		std::cout << "problem: must be entered in 100 units only." << std::endl;
		return INVALID_ID;
	}
}

// 책의 정보 출력
void Book::bookInfo()
{
	std::cout << std::endl;
	if ("__notFound" != m_name) 
		std::cout << "BookName   : " << m_name << std::endl;
	else 
		std::cout << "BookName   : \"Not set\"" << std::endl;

	if ("__notFound" != m_author)
		std::cout << "BookAuthor : " << m_author << std::endl;
	else
		std::cout << "BookAuthor : \"Not set\"" << std::endl;

	if (INVALID_ID != m_page)
		std::cout << "Pages      : " << m_page << std::endl;
	else 
		std::cout << "Pages      : \"Not set\"" << std::endl;

	// categorize
	switch (m_id/100)
	{
	case 0:
		std::cout << "Categorize : 총류" << std::endl;
		break;	
	case 1:
		std::cout << "Categorize : 철학" << std::endl;
		break;
	case 2:
		std::cout << "Categorize : 종교" << std::endl;
		break;
	case 3:
		std::cout << "Categorize : 사회과학" << std::endl;
		break;
	case 4:
		std::cout << "Categorize : 자연과학" << std::endl;
		break;
	case 5:
		std::cout << "Categorize : 기술과학" << std::endl;
		break;
	case 6:
		std::cout << "Categorize : 예술" << std::endl;
		break;
	case 7:
		std::cout << "Categorize : 언어" << std::endl;
		break;
	case 8:
		std::cout << "Categorize : 문학" << std::endl;
		break;
	case 9:
		std::cout << "Categorize : 역사" << std::endl;
		break;
	case INVALID_ID:
		std::cout << "Categorize : \"Not set\"" << std::endl;
		break;
	default:
		std::cout << "Assert" << std::endl;
		assert(nullptr);
	}
	if (INVALID_ID != m_page)
	{
		if (m_id < 10)
			std::cout << "BookID     : 00" << m_id << std::endl << std::endl;
		else if (m_id < 100)
			std::cout << "BookID     : 0" << m_id << std::endl << std::endl;
		else
			std::cout << "BookID     : " << m_id << std::endl << std::endl;
	}
	else
		std::cout << "BookID     : \"Not set\"" << std::endl << std::endl;

	if (INVALID_ID != m_page)
		std::cout << "price      : " << m_price << std::endl;
	else
		std::cout << "price      : \"Not set\"" << std::endl;

	if (INVALID_ID != m_page)
		std::cout << "stock      : " << ms_bookStock << std::endl;
	else
		std::cout << "stock      : \"Not set\"" << std::endl;

	if (INVALID_ID != m_page)
		std::cout << "sell count : " << ms_sellCount << std::endl;
	else
		std::cout << "sell count : \"Not set\"" << std::endl;

	std::cout << std::endl;
}

/////////////////////////////////////////////////////////
// 생성자, 소멸자
Book::Book()
	: m_name("__notFound")
	, m_author("__notFound")
	, m_price(INVALID_ID)
	, m_page(INVALID_ID)
	, m_categorize(INVALID_ID)
	, m_id(INVALID_ID)
	, ms_Income(INVALID_ID)
	, ms_bookStock(INVALID_ID)
	, ms_sellCount(INVALID_ID)
{
}

Book::Book(std::string _bookName, std::string _bookAuthor, int _price, int _page, int _categorize, int _bookStock)
	: m_name(_bookName)
	, m_author(_bookAuthor)
	, m_price(_price)
	, m_page(_page)
	, m_categorize(_categorize)
	, m_id(NULL)
	, ms_Income(INVALID_ID)

	, ms_bookStock(_bookStock)
	, ms_sellCount(INVALID_ID)
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
		std::cout << "problem: exact category and bookID not set" << std::endl;
		m_id = INVALID_ID;
	}

}

Book::~Book()
{
}



