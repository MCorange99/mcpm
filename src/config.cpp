
#include "config.h"


using namespace std;
class Config {
public:
    int       version;
    string    mirror;
    bool      color;
};
        
        
void loadConfig() {
    Config config;
    ifstream fin("config.conf");
    string line;
    while (getline(fin, line)) {
        istringstream sin(line.substr(line.find("=") + 1));
        if (line.find("version") != -1)
            sin >> config.version;
        else if (line.find("mirror") != -1)
            sin >> config.mirror;
        else if (line.find("color") != -1)
            sin >> config.color;
        }
}
