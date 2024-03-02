#include <standalone.h>

void standaloneStringFinder()
{
    std::string mainString;
    std::string keyWord;

    std::cout << "Give a string from which to search for: ";
    std::getline(std::cin, mainString);

    std::cout << "Give search string: ";
    std::getline(std::cin, keyWord);

    // Checks if the string is found to make my garbo code not run even if the keyword is not in the string
    if (foundInString(mainString, keyWord))
    {
        int pos = findStringPos(mainString, keyWord);
        std::cout << std::endl << "'" << keyWord << "' found in '" << mainString << "' in position " << pos;
    }
    else
    {
        std::cout << std::endl << "'" << keyWord << "' NOT found in '" << mainString << "'";
    }
}

// Returns either true or false if the keyWord is/is not in mainString
bool foundInString(std::string &mainString, std::string &keyWord)
{
    return (mainString.find(keyWord) != std::string::npos);
}

// Surprised this worked like it did in my head
int findStringPos(std::string &mainString, std::string &keyWord)
{   
    int keyWordIterator = 0;

    // Goes through the string letter by letter if the letters match
    for (int i = 0; i < mainString.length(); i++)
    {
        if (keyWordIterator == keyWord.length())
        {
            return i - keyWordIterator;
        }

        if (mainString[i] == keyWord[keyWordIterator])
        {
            keyWordIterator++;
        }
        else
        {
            keyWordIterator = 0;
        }
    }

    return -1; // Shouldn't really happen unless my code is ass
}