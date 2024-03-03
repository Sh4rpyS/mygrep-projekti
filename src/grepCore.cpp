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
    // The program does not use a file, but does use options
    else if (argc == 2)
    {
        standaloneStringFinder(stripOptions(argv[1]));
    }
    // The program uses a file, a keyword, but no options
    else if (argc == 3)
    {
        std::vector<std::string> *lines = loadFile(argv[2]);

        if (lines == nullptr) 
        {
            return;
        }

        bool matches = checkLines(argv[1], lines);
        
        if (!matches)
        {
            std::cout << std::endl << "No references of " << argv[1] << " were found in " << argv[2] << ".";
        }
    }
    // Same as previously, but this time the program uses options
    else if (argc == 4) 
    {
        std::vector<std::string> *lines = loadFile(argv[3]);

        if (lines == nullptr) 
        {
            return;
        }

        bool matches = checkLines(argv[2], lines, stripOptions(argv[1]));

        if (!matches)
        {
            std::cout << std::endl << "No references of " << argv[2] << " were found in " << argv[3] << ".";
        }
    }
    else
    {
        std::cout << "Too many arguments";
    }
}

// Returns either true or false if the keyString is/is not in mainString
bool foundInString(const std::string &mainString, const std::string &keyString, const bool reversed)
{
    if (reversed) 
    {
        return (mainString.find(keyString) == std::string::npos);
    }
    return (mainString.find(keyString) != std::string::npos);
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
    
    std::string keyStringModified = keyString;

    // Check if the i (ignore upper/lowercase) option is used
    if (i)
    {
        // Changes keyString to be lowercase, so any previous differences will be eliminated
        std::transform(keyStringModified.begin(), keyStringModified.end(), keyStringModified.begin(), ::tolower);
    }

    // Goes through line by line
    int lineNumber = 1;
    for (std::string line : *lines)
    {
        // Check if the i (ignore upper/lowercase) option is used
        if (i)
        {
            // Changes the line to be lowercase, so any previous differences will be eliminated
            std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        }

        // foundInString also reverses the return if r (reverse search) was enabled
        if (foundInString(line, keyStringModified, r))
        {
            // Check if the l (show line numbering) option is used
            if (l)
            {
                std::cout << lineNumber << ":";
            }
            std::cout << line << std::endl;
            matchingLines.push_back(line);
        }

        lineNumber++;
    }

    // Check if the o (occurences) option is used
    if (o)
    {
        std::cout << std::endl << "Occurences of lines containing '" << keyString << "': " << matchingLines.size();
    }
    
    return matchingLines.size() > 0;
}