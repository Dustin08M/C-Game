#include <fstream>
#include <iostream>
#include <vector>

int main()
{
	std::vector<auto> value;

	value.push_back(500);
	value.push_back(3.1429);
	value.push_back("Hello World");

	for(auto val : value)
	{
		std::cout << val << std::endl;
	}
	//std::ifstream inFile("Test.txt");
	//if (!inFile)
	//{
	//	std::cerr << "Failed to open file!" << std::endl;
	//	return -1;
	//}
	//std::string line;
	//while (std::getline(inFile, line))
	//{
	//	std::cout << line << std::endl;
	//}
	//inFile.close();
	//return 0;
	return 0;
}