#include <iostream>
#include "funcs.h"

int main()
{
	std::cout << solve(encryptCaesar("There are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even slightly believable. If you are going to use a passage of Lorem Ipsum, you need to be sure there isn't anything embarrassing hidden in the middle of text.", 10)) << std::endl; // Lorem Ipsum Text
	return 0;
}
