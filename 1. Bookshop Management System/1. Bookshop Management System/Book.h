#pragma once
#include <iostream>
#include <string>
#include <assert.h>
#include <map>

using namespace std;

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

class Book
{
private:
	string	m_bookName;
	string	m_bookAuthor;
	int		m_price;
	int		m_page;
	int		m_bookID;

	int		m_bookStock;
	int		m_sellCount;
	enum bookCategorize bc;

	// static int m_arrID[10];

public: // 책 정보 관리 함수:

	// 책 정보 반환
	string bookName();
	string bookAuthor();
	int	price();
	int page();
	int bookID();

	bc = 역사;

	// 책 정보 반환 - 재고
	int bookStock();
	int sellCount();

	// 책 정보 수정
	void reBookName(string _BookName);
	void reBookAuthor(string _AuthorName);
	void rePrice(int _price);
	void rePage(int _pageCount);
	void reCategorize(int _CategorizeNUM);



public: // 책 재고 관리 함수:
	void stockOfBook();

public:	// 책 정보 전체 출력
	void BookINFO();	
	//////////////////////////

	Book();
	Book(string _bookName, string _bookAuthor, int _price, int _page, int _categorize, int _bookStock);
	~Book();
};