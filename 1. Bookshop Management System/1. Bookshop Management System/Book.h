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
	int			getStock();
	int			getTotalSellCount();
	int			getTotalIncome();

	// å ��� ���� ����
	int			setStock(int _stock);
	int			setAddSubStock(int _addSubStock);

	// �Ǹ� �Լ�
	int			sellBook();

public:	// å ���� ��ü ���
	void		bookInfo();	


	Book();
	Book(std::string _bookName, std::string _bookAuthor, int _price, int _page, int _categorize, int _bookStock);
	~Book();
};

