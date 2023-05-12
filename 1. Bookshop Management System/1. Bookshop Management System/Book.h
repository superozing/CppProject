#pragma once
#include <iostream>
#include <string>
#include <assert.h>
#include <vector>

using namespace std;

enum bookCategorize
{
	총류, 철학, 종교, 사회과학, 자연과학,
	기술과학, 예술, 언어, 문학, 역사
};






class Book
{
private:
	string	m_name;
	string	m_author;
	int		m_price;
	int		m_page;
	int		m_id;
	int		m_categorize;

	int		ms_bookStock;
	int		ms_sellCount;

	int		ms_Income;

public: // 책 정보 관리 함수:

	// 책 정보 반환
	string bookName();
	string bookAuthor();
	int	price();
	int page();
	int bookID();
	int categorize();


	// 책 정보 수정
	void setName(string _bookName);
	void setAuthor(string _authorName);
	void setPrice(int _price);
	void setPage(int _pageCount);
	void setCategorize(int _categorizeNum);



public: // 책 재고 관리 함수:
	
	// 책 재고 정보 반환
	int s_bookStock();
	int s_sellCount();
	int s_todaySell();

	// 책 재고 정보 수정
	void s_updateStock(int _stock);
	void s_addSubStock(int _addSubStock);

	// 판매 함수
	void s_sell();

public:	// 책 정보 전체 출력
	void bookInfo();	


	Book();
	Book(string _bookName, string _bookAuthor, int _price, int _page, int _categorize, int _bookStock);
	~Book();
};