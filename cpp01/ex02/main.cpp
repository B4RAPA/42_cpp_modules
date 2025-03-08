#include "iostream"

int main(void)
{
	std::string myString = "HI THIS IS BRAIN";
	std::string* stringPTR = &myString;
	std::string& stringREF = myString;

	std::cout << "myString:  " << &myString << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;

	std::cout << "myString:  " << myString << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;

	return (0);
}