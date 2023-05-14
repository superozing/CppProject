#pragma once
#include <assert.h>

template <typename T>
class Carr
{
private:
	T*	m_pData;
	int		m_iCount;
	int		m_iMaxCount;

public:
	void push_back(const T& _Data); // 훨씬 큰 데이터(예를 들어서 Book클래스 객체)의 경우 주소 값을 받아오는 것이 훨씬 효율적임
	void resize(int _iResizeCount);

	T& operator[](int _idx);

public:
	Carr();
	~Carr();

};

template <typename T>
void Carr<T>::push_back(const T& _Data)
{
	if (m_iMaxCount = m_iCount)
		resize(m_iMaxCount * 2);

	m_pData[m_iCount] = _Data;
	++m_iCount;
}

template <typename T>
void Carr<T>::resize(int _iResizeCount)
{
	if (m_iMaxCount > _iResizeCount)
		assert(nullptr);

	T* newArr = new T[_iResizeCount];

	for (int i = 0; i < m_iCount; ++i)
		newArr[i] = m_pData[i];

	delete[] m_pData;
	m_pData = newArr;
}
template <typename T>
T& Carr<T>::operator[](int _idx) { return m_pData[_idx]; }

template <typename T>
Carr<T>::Carr()
	:m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[m_iMaxCount];
}

template <typename T>
Carr<T>::~Carr()
{
	delete[] m_pData;
}
