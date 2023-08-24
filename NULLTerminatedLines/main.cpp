#include <iostream>
#include <Windows.h>
using namespace std;

int string_length(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

char* to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
		if (str[i] >= 'а' && str[i] <= 'я') str[i] -= 32;
	}
	return str;
}

char* to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
		if (str[i] >= 'А' && str[i] <= 'Я') str[i] += 32;
	}
	return str;
}

char* shrink(char str[])
{
	char* result = new char[string_length(str)];
	for (int i = 0, j = 0; str[j]; i++)
	{
		if (str[i] == 32 && str[i - 1] == 32) continue;
		result[j++] = str[i];
	}
	return result;
}

bool is_palindrome(char str[])
{
	int pairs = string_length(str) / 2;
	int last = string_length(str) - 1;
	for (int i = 0; i < pairs; i++)
	{
		if (str[i] == str[last])
		{
			last--;
			continue;
		}
		else return false;
	}
	return true;
}

void main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	//char str[] = "Hello";
	const int size = 100;
	char str[size] = {};
	cout << "Введите строку: ";
	SetConsoleCP(1251);
	cin.getline(str, size);
	SetConsoleCP(866);

	/*for (int i = 0; i < 256; i++)
	{
		cout << i << "\t" << (char)i << endl;
	}*/

	cout << to_upper(str) << endl;
	cout << to_lower(str) << endl;
	char* str2 = shrink(str);
	cout << str2 << endl;
	delete[] str2;

	bool a = is_palindrome(str);
	cout << a;

}