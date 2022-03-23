#pragma once
#include <iostream>
#include <Windows.h>


#include "Xorstr.h"





HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int k;

enum Colors
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	PURPLE,
	YELLOW,
	WHITE
};




class CPrinta
{
public:
	const char* SetWhite()
	{
		SetConsoleTextAttribute(h, 15);
		return "";
	}
	const char* SetGreen()
	{
		SetConsoleTextAttribute(h, 10);
		return "";
	}
	const char* SetBlue()
	{
		SetConsoleTextAttribute(h, 9);
		return "";
	}
	const char* SetPurple()
	{
		SetConsoleTextAttribute(h, 13);
		return "";
	}
	const char* SetRed()
	{
		SetConsoleTextAttribute(h, 4);
		return "";
	}

	void Arrow(int color)
	{
		SetConsoleTextAttribute(h, color);
		std::cout << xorstr("-> ");
		SetWhite();
	}
	void Title(const char* text)
	{
		std::cout << std::endl;
		SetPurple();
		std::cout << xorstr("    ") << text << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	void OK(const char* text)
	{
		SetWhite();
		std::cout << xorstr(" [");
		SetGreen();
		std::cout << xorstr("+");
		SetWhite();
		std::cout << xorstr("] ");
		std::cout << text << std::endl;
		SetWhite();
	}
	void Input(const char* text)
	{
		SetWhite();
		std::cout << xorstr(" [ ");
		SetBlue();
		std::cout << xorstr("->");
		SetWhite();
		std::cout << xorstr(" ] ");
		std::cout << text << "";
		std::cout << std::endl;
		SetWhite();
	}
	void Loading(const char* text)
	{
		SetWhite();
		std::cout << xorstr(" [");
		SetPurple();
		std::cout << xorstr("<-->");
		SetWhite();
		std::cout << xorstr("] ");
		std::cout << text << std::endl;
		SetWhite();

	}
	void Fail(const char* text)
	{
		SetWhite();
		std::cout << xorstr(" [");
		SetRed();
		std::cout << xorstr("-");
		SetWhite();
		std::cout << xorstr("] ");
		std::cout << text << std::endl;
		SetWhite();
	}

	void Print(const char* text)
	{
		std::cout << text << std::endl;
	}
	void PrintCol(const char* text, int color)
	{
		SetConsoleTextAttribute(h, color);
		std::cout << text;
	}
	void Custom(std::string symbol, int symbolColor, const char* text, int textColor)
	{
		SetWhite();
		std::cout << xorstr(" [ ");
		SetConsoleTextAttribute(h, symbolColor);
		std::cout << symbol;
		SetWhite();
		std::cout << xorstr(" ] ");
		SetConsoleTextAttribute(h, textColor);
		std::cout << text << std::endl;
	}
	void Rainbow(std::string text)
	{
		for (int i = 0; i < text.length(); i++)
		{
			k > 14 ? k = 1 : k++;
			SetConsoleTextAttribute(h, k);
			std::cout << text.at(i);
		}

	}

	void Endl()
	{
		std::cout << std::endl;
	}
}Printa;
