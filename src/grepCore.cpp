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
        bool matches = checkLines(argv[1], loadFile(argv[2]));
        
        if (!matches)
        {
            std::cout << "No references of " << argv[1] << " were found in " << argv[2] << ".";
        }
    }
    else if (argc == 4) 
    {
        bool matches = checkLines(argv[2], loadFile(argv[3]), stripOptions(argv[1]));
        
        if (!matches)
        {
            std::cout << "No references of " << argv[2] << " were found in " << argv[3] << ".";
        }
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
bool foundInString(const std::string &mainString, const std::string &keyString)
{
    return (mainString.find(keyString) != std::string::npos);
}

// Surprised this worked like it did in my head
int findStringPos(const std::string &mainString, const std::string &keyString)
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

// Gets rid of the "-o" so and just returns the options
std::string stripOptions(std::string options)
{
    return options.substr(2, options.length() - 2);
}

// Searches multiple lines that we get from a file
bool checkLines(std::string keyString, std::vector<std::string> *lines, std::string options)
{
    // Reusing the foundInString code lol
    bool o = foundInString(options, "o");
    bool l = foundInString(options, "l");
    bool r = foundInString(options, "r");
    bool i = foundInString(options, "i");

    // Stores all the matching file lines
    std::vector<std::string> matchingLines;
    
    // Goes through line by line
    int lineNumber = 1;
    for (std::string line : *lines)
    {
        if (foundInString(line, keyString))
        {
            if (l)
            {
                std::cout << lineNumber << ": ";
            }
            std::cout << line << std::endl;
            matchingLines.push_back(line);
        }

        lineNumber++;
    }

    if (o)
    {
        std::cout << std::endl << "Occurences of lines containing '" << keyString << "': " << matchingLines.size();
    }
    
    return matchingLines.size() > 0;
}