// Lab_08_1.cpp 
// < Базарник Максим > 
// Лабораторна робота № 8.1 
// Варіант 1
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int Count(char* str, int i)
{
	if (strlen(str) < 2)
		return 0;
	if (str[i + 1] != 0)
		if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n'))
			return 1 + Count(str, i + 1);
		else
			return Count(str, i + 1);
	else
		return 0;
}

char* Change(char* dest, const char* str, char* t, int i)
{
	if (str[i + 1] != 0)
	{
		if (str[i] == 'n' && str[i + 1] == 'o')
		{
			strcat(t, "***");
			return Change(dest, str, t + 3, i + 2);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, i);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}

int main()
{
	char str[128];

	cout << "Enter string: ";
	cin.getline(str, 128);

	cout << "String contained " << Count(str, 0) << " groups of 'no' or 'on'" << endl;

	char* dest1 = new char[256];
	dest1[0] = '\0';

	char* dest2;
	dest2 = Change(dest1, str, dest1, 0);

	cout << "Modified string (param) : " << dest1 << endl;
	cout << "Modified string (result): " << dest2 << endl;

	return 0;
}
