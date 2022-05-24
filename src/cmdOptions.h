#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

namespace cmdOpt{
    char* getCmdOption(char ** begin, char ** end, const string & option);
    bool cmdOptionExists(char** begin, char** end, const string& option);
}
    