#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <cmath>
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

char shiftChar(char c, int rshift)
{
	int sum;
	if (isalpha(c))
	{
		sum = (int)c + rshift;
		if (isupper(c)) // upper case letter (65-90)
		{
			return char(65 + ((sum % 65) % 26));
		}
		else // lower case letter (97-122)
		{
			return char(97 + ((sum % 97) % 26));
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
	std::vector<double> letter_freq = {8.12, 1.49, 2.71, 4.32, 12.02, 2.30, 2.03, 5.92, 7.31, 0.10, 0.69, 3.98, 2.61, 6.95, 7.68, 1.82, 0.11, 6.02, 6.28, 9.10, 2.88, 1.11, 2.09, 0.17, 2.11, 0.07}; // A-Z frequency for English text
	std::vector<double> string_freq;
	double compare_dist = 0.0;
	double best_dist = 312;
	int best_shift = -1;
	for (int i=1; i<26; i++)
	{
		string_freq = get_string_freq(encrypted_string, i);
		compare_dist = distance(letter_freq, string_freq);
		if (compare_dist < best_dist)
		{
			best_dist = compare_dist;
			best_shift = i;
		}
	}
	return decryptCaesar(encrypted_string, best_shift);
}

double freq(std::string str, int c)
{
	int count = 0;
	for (int i=0; i<str.length(); i++)
	{
		if ((str[i]==c) || (str[i]==(c+32)))
		{
			count++;
		}		
	}
	return (double)count/(double)str.length();
}

std::vector<double> get_string_freq(std::string str, int rshift)
{
	std::vector<double> frequency(26, 0);
	std::string shifted_str = decryptCaesar(str, rshift);
	int start = 'A';
	for (int i=0; i<26; i++)
	{
		frequency.at(i) = freq(shifted_str, start) * 100.0;
		start++;
	}
	return frequency;
}

double distance(std::vector<double> letter, std::vector<double> string)
{
	double sub = 0;
	double total_sum = 0;
	for (int i=0; i<26; i++)
	{
		sub = letter.at(i) - string.at(i);
		total_sum += pow(sub, 2);
	}
	return sqrt(total_sum);
}
