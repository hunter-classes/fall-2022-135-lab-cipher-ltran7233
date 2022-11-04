#pragma once

char decryptChar(char c, int rshift);
char shiftChar(char c, int rshift);
std::string encryptCaesar(std::string plaintext, int rshift);
std::string decryptCaesar(std::string ciphertext, int rshift);
std::string solve(std::string encrypted_string);
double freq(std::string str, char c);
std::vector<double> get_string_freq(std::string str, int rshift);
double distance(std::vector<double> letter, std::vector<double> string);
