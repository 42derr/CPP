#include <iostream>
#include <fstream>

std::string replaceLine(std::string line, const std::string &stringOne, const std::string &stringTwo)
{
    size_t found = line.find(stringOne);

    while (found != std::string::npos)
    {
        line = line.substr(0, found) + stringTwo + line.substr(found + stringOne.length());
        found = line.find(stringOne, found + stringTwo.length());
    }
    return line;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "./replace filename string1 string2" << std::endl;
        return (1);
    }

    std::string fileName = argv[1];
    std::string stringOne = argv[2];
    std::string stringTwo = argv[3];
    std::string replacedFileName = fileName + ".replace";

    if (fileName.empty() || stringOne.empty())
    {
        std::cout << "Arguments can't be empty string " << std::endl;
        return (1);
    }

    std::ifstream infile(argv[1]);
    
    if (!infile) {
        std::perror("Error opening infile");
        return (1);
    }

    std::ofstream outfile(replacedFileName.c_str());
    if (!outfile) {
        infile.close();
        std::perror("Error opening outfile");
        return (1);
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::string replacedString =  replaceLine(line, stringOne, stringTwo);
        outfile << replacedString << std::endl;
    }

    infile.close();
    outfile.close();
    return (0);
}
