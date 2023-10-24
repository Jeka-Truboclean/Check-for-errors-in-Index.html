#include <fstream>
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	ifstream is("index.html", ios::in);

	ofstream in("NewIndex.txt", ios::trunc);

	if (!is.is_open())
	{
		cout << "Open file ERROR\n";
	}

	bool ch = 0;
	do
	{
		char character = '\0';

		is.get(character);

		cout << character;

		if (character == '<')
		{
			if (ch == 1)
			{
				cout << "  <-ERROR\n";
				break;
			}
			ch = 1;
		}
		else if (character == '>')
		{
			ch = 0;
		}

		in.put(character);

		Sleep(1);
	} while (!is.eof());

	return 0;
}