#include <grepCore.h>
#include <standalone.h>
#include <grepFile.h>

void grepMain(int argc, char *argv[])
{
    // The program will function as shown in the increment 1
    if (argc == 1) 
    {
        standaloneStringFinder();
    }
    else if (argc == 3)
    {
        std::vector<std::string> *matchingLines = findFromLines(argv[1], loadFile(argv[2]));
        printVector(*matchingLines);
    }
    else if (argc == 4) 
    {
        
    }
    else
    {
        std::cout << "Too many arguments";
    }
}

void printVector(std::vector<std::string> &vector)
{
    for (std::string item : vector)
    {
        std::cout << item << std::endl;
    }
}

// Returns either true or false if the keyString is/is not in mainString
bool foundInString(std::string &mainString, std::string &keyString)
{
    return (mainString.find(keyString) != std::string::npos);
}

// Surprised this worked like it did in my head
int findStringPos(std::string &mainString, std::string &keyString)
{   
    int keyStringIterator = 0;

    // Goes through the string letter by letter if the letters match
    for (int i = 0; i < mainString.length(); i++)
    {
        if (mainString[i] == keyString[keyStringIterator])
        {
            if (keyStringIterator == keyString.length() - 1)
            {
                return i - keyStringIterator; // Return the pos
            }
            keyStringIterator++;
        }
        else
        {
            keyStringIterator = 0;
        }
    }

    // Shouldn't really happen unless my code is ass
    // -1 would mean no match was found, but this code is only run if foundInString return true
    return -1;
}

// Searches multiple lines that we get from a file
std::vector<std::string> *findFromLines(std::string keyString, std::vector<std::string> *lines)
{
    // Stores all the matching file lines
    static std::vector<std::string> matchingLines;
    
    for (std::string line : *lines)
    {
        if (foundInString(line, keyString))
        {
            matchingLines.push_back(line);
        }
    }
    
    return &matchingLines;
}