#pragma once
#include <iostream>
#include <string>
#include <assert.h>
#include <vector>

using namespace std;

enum bookCategorize
{
	�ѷ�, ö��, ����, ��ȸ����, �ڿ�����,
	�������, ����, ���, ����, ����
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

public: // å ���� ���� �Լ�:

	// å ���� ��ȯ
	string bookName();
	string bookAuthor();
	int	price();
	int page();
	int bookID();
	int categorize();


	// å ���� ����
	void setName(string _bookName);
	void setAuthor(string _authorName);
	void setPrice(int _price);
	void setPage(int _pageCount);
	void setCategorize(int _categorizeNum);



public: // å ��� ���� �Լ�:
	
	// å ��� ���� ��ȯ
	int s_bookStock();
	int s_sellCount();
	int s_todaySell();

	// å ��� ���� ����
	void s_updateStock(int _stock);
	void s_addSubStock(int _addSubStock);

	// �Ǹ� �Լ�
	void s_sell();

public:	// å ���� ��ü ���
	void bookInfo();	


	Book();
	Book(string _bookName, string _bookAuthor, int _price, int _page, int _categorize, int _bookStock);
	~Book();
};