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