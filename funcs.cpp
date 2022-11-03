#include <iostream>
#include <cctype>
#include <string>
#include "funcs.h"


char decryptChar(char c, int rshift)
{
	int sub;
	if (isalpha(c))
	{
		sub = (int)c - rshift;
		if (isupper(c)) // upper case letter (65-90)
		{
			return char(90 - ((90 % sub) % 26));
		}
		else // lower case letter (97-122)
		{
			return char(122 - ((122 % sub) % 26));
		}
	}
	else
	{
		return c;
	}
}

std::string encryptCaesar(std::string plaintext, int rshift)
{
	std::string str = "";
	for (int i=0; i<plaintext.length(); i++)
	{
		str += shiftChar(plaintext[i], rshift);
	}
	return str;
}

std::string decryptCaesar(std::string ciphertext, int rshift)
{
	std::string str = "";
	for (int i=0; i<ciphertext.length(); i++)
	{
		str += decryptChar(ciphertext[i], rshift);
	}
	return str;
}

std::string solve(std::string encrypted_string)
{
	
}
