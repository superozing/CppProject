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

	int			ms_bookStock;
	int			ms_sellCount;

	int			ms_Income;




public: // å ���� ���� �Լ�:

	// å ���� ��ȯ
	std::string getBookName();
	std::string getBookAuthor();
	int			getPrice();
	int			getPage();
	int			getBookID(); // bookID�� setter�Լ��� ���ּ� bookID�� �ٲ� ��츦 ����
	int			getCategorize();


	// å ���� ����
	int			setName(std::string _bookName);
	int 		setAuthor(std::string _authorName);
	int 		setPrice(int _price);
	int 		setPage(int _pageCount);
	int			setCategorize(int _categorizeNum);

public: // å ��� ���� �Լ�:
	
	// å ��� ���� ��ȯ
	int			s_bookStock();
	int			s_sellCount();
	int			s_todaySell();

	// å ��� ���� ����
	int		s_updateStock(int _stock);
	int			s_addSubStock(int _addSubStock);

	// �Ǹ� �Լ�
	int			s_sell();

public:	// å ���� ��ü ���
	void		bookInfo();	


	Book();
	Book(std::string _bookName, std::string _bookAuthor, int _price, int _page, int _categorize, int _bookStock);
	~Book();
};