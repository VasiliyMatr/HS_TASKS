
#include <iostream>

#include "core.hh"

int main( int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout <<
            "Wrong number of args." << std::endl <<
            "Usage: " << argv[0] << " <file to exec>" << std::endl;

        return -1;
    }

    CPUSimulation::Core core{};

    CPUSimulation::loadStatus_t loadStatus = core.load (argv[1]);
    if (loadStatus != CPUSimulation::loadStatus_t::OK)
    {
        std::cout <<
            "Error with file load." << std::endl <<
            "Error code: " << static_cast<int> (loadStatus) << std::endl;

        return -1;
    }

    CPUSimulation::execStatus_t execStatus = core.exec ();
    std::cout <<
        "Program finished with code: " << static_cast<int> (execStatus) << std::endl;

    core.dumpState ();

    return 0;
}