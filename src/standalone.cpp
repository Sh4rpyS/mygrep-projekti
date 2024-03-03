#include <standalone.h>
#include <grepCore.h>

void standaloneStringFinder()
{
    std::string mainString;
    std::string keyString;

    std::cout << "Give a string from which to search for: ";
    std::getline(std::cin, mainString);

    std::cout << "Give search string: ";
    std::getline(std::cin, keyString);

    // Checks if the string is found to make my garbo code not run even if the keyString is not in the string
    if (foundInString(mainString, keyString)) // True
    {
        int pos = findStringPos(mainString, keyString);
        std::cout << std::endl << "'" << keyString << "' found in '" << mainString << "' in position " << pos;
    }
    else // False
    {
        std::cout << std::endl << "'" << keyString << "' NOT found in '" << mainString << "'";
    }
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