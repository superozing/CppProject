#pragma once
#include <iostream>
#include <string>
#include <assert.h>
#include <map>

using namespace std;

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

public: // å ���� ���� �Լ�:

	// å ���� ��ȯ
	string bookName();
	string bookAuthor();
	int	price();
	int page();
	int bookID();

	bc = ����;

	// å ���� ��ȯ - ���
	int bookStock();
	int sellCount();

	// å ���� ����
	void reBookName(string _BookName);
	void reBookAuthor(string _AuthorName);
	void rePrice(int _price);
	void rePage(int _pageCount);
	void reCategorize(int _CategorizeNUM);



public: // å ��� ���� �Լ�:
	void stockOfBook();

public:	// å ���� ��ü ���
	void BookINFO();	
	//////////////////////////

	Book();
	Book(string _bookName, string _bookAuthor, int _price, int _page, int _categorize, int _bookStock);
	~Book();
};