#include <grepFile.h>
#include <grepCore.h>

std::vector<std::string> *loadFile(std::string filePath)
{
    // Stores all the file lines
    static std::vector<std::string> fileLines;

    // Loads the file
    std::ifstream loadedFile(filePath);

    if (!loadedFile.good())
    {
        return nullptr;
    }

    // Loops through the lines and adds them to the vector
    std::string line;
    while(std::getline(loadedFile, line))
    {
        fileLines.push_back(line);
    }

    loadedFile.close();

    return &fileLines;
}