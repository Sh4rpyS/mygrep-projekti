#include <iostream>

#include <grepCore.h>
#include <standalone.h>

void grepMain(int argc, char *argv[])
{
    std::vector<std::string> *arguments = validateArguments(argc, argv);

    // The program will function as shown in the increment 1
    if (arguments == nullptr) 
    {
        standaloneStringFinder();
    }

}

std::vector<std::string> *validateArguments(int argc, char *argv[])
{
    // The program will function as shown in the increment 1
    if (argc == 1) 
    {
        return nullptr;
    }

    std::vector<std::string> arguments = {};

    // i = 1 ignores the name of the binary
    for (int i = 1; i < argc; i++) {
        // Check what the argument is
        if (argv[i][0] == '-') {

        } 

        // No dash would indicate that the argument is either a file or a string
        else
        {
            
        }
    }

    return &arguments;
}