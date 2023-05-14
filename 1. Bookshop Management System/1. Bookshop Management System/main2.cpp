#include "CArr.h"
#include "Book.h"

int main()
{
	Carr<Book> carr;

	carr.push_back(Book("PJH", "shin min seo", 10000, 20, 100, 10));

	Book Bdata = carr[0];

	cout << Bdata.bookAuthor() << endl;
	Bdata.setAuthor("PJHJH");
	cout << Bdata.bookAuthor() << endl;


	return 0;
}