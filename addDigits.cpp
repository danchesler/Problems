// practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//Given a non-negative integer 'num', repeatedly add all its digits until the result only has one digit
//Ex: num = 38, 3 + 8 = 11 then 1 + 1 = 2, 2 only has one digit so return

//Separating an int into individual numbers


int addDigits1(int num)
{
	if (num > 99 || num < 0)
	{
		cout << "Only non-negative numbers less than 100" << endl;
		return 0;
	}
	if (num < 10)
	{
		return num;
	}
	string str_num;
	stringstream ss;
	int sum = 0, num1 = 0, num2 = 0;
	ss << num;
	str_num = ss.str();
	num1 = str_num[0] - 48;
	num2 = str_num[1] - 48;
	sum = num1 + num2;
	if (sum < 10)
	{
		return num;
	}
	else
	{
		num = addDigits1(sum);
	}
	return num;
}

int addDigits2(int num)
{
	if (num > 99 || num < 0)
	{
		cout << "Only non-negative numbers less than 100" << endl;
		return 0;
	}
	else if (num < 10)
	{
		return num;
	}

	int sum, num1, num2;
	while (num > 9)
	{
		num1 = num / 10;
		num2 = num % 10;
		sum = num1 + num2;
		if (sum < 10)
		{
			return num;
		}
		else
		{
			num = sum;
		}
	}

	return num;
}

int main()
{
	cout << addDigits2(86) << endl;
	//cout << addDigits1(11) << endl;

	return 1;
}

