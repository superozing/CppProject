#pragma once
#include "Book.h"


void informationMode(int& selector, Book* _book);

void stockMode(int& selector, Book* _book);

void mainScreen(int& selector, int& totalSell, int& totalIncome, std::vector<Book*>& bookList);
