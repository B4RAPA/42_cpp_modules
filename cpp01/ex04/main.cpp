#include <string>
#include <ostream>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
		return (-1);
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream file(argv[1]);
	std::ofstream outfile("out.txt");
	if (!file.is_open())
	{
		std::cerr << "Error opening the file" << std::endl;
		return (1);
	}
	std::string line;	
	while (std::getline(file, line))
	{
		size_t pos = line.find(s1);
		while(pos != std::string::npos)
		{	
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1);
		}
		outfile << line << std::endl;
	}
	return 0;
}