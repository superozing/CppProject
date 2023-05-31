#pragma once

#include <string>
#include <assert.h>

class Book
{
private:
	std::string	m_name;
	std::string	m_author;
	int			m_price;
	int			m_page;
	int			m_id;
	int			m_categorize;

	int			m_sStock;

	int			m_sTotalSellCount;
	int			m_sTotalIncome;




public: // 책 정보 관리 함수:

	// 책 정보 반환
	std::string getBookName();
	std::string getBookAuthor();
	int			getPrice();
	int			getPage();
	int			getBookID(); // bookID는 setter함수를 없애서 bookID가 바뀔 경우를 방지
	int			getCategorize();


	// 책 정보 수정
	int			setName(std::string _bookName);
	int 		setAuthor(std::string _authorName);
	int 		setPrice(int _price);
	int 		setPage(int _pageCount);
	int			setCategorize(int _categorizeNum);

public: // 책 재고 관리 함수:
	
	// 책 재고 정보 반환
	int			getStock();
	int			getTotalSellCount();
	int			getTotalIncome();

	// 책 재고 정보 수정
	int			setStock(int _stock);
	int			setAddSubStock(int _addSubStock);

	// 판매 함수
	int			sellBook();

public:	// 책 정보 전체 출력
	void		bookInfo();	


	Book();
	Book(std::string _bookName, std::string _bookAuthor, int _price, int _page, int _categorize, int _bookStock);
	~Book();
};

