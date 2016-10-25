// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле


#include "tbitfield.h"

TBitField::TBitField(int len)
{
	if (len < 0) throw "length is negative";
	BitLen = len;
	MemLen = (len+31) >> 5;
	pMem = new TELEM [MemLen];
	if (pMem != 0)
		for (int i = 0; i < MemLen; i++)
			pMem[i] = 0;
	
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM [MemLen];
	if (pMem != 0)
		for (int i = 0; i < MemLen; i++)
			pMem[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
	delete [] pMem;
	pMem = NULL;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	return n >> 5;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	TELEM tmp = 1;
	return tmp << (n % 32);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	if ((n > -1)&&(n < BitLen))
	{
	int i = GetMemIndex(n);
	pMem[i] = pMem[i] | GetMemMask(n);
	}
	else throw "sb negative or large index";
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if ((n > -1)&&(n < BitLen))
	{
	int i = GetMemIndex(n);
	pMem[i] = pMem[i] & ~GetMemMask(n);
	}
	else throw "clrb negative or large index";
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	if ((n > -1)&&(n < BitLen))
	{int i = GetMemIndex(n);
	return (pMem[i] & GetMemMask(n)) >> (n % 16);
	}
	else throw "gb negative or large index";
	return 0;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
  return 0;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
}

TBitField TBitField::operator~(void) // отрицание
{
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
}
