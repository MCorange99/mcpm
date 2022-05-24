#include <fstream>
#include <sstream>


using namespace std;
namespace cfg{
    class Config {
    public:
        int       version;
        string    mirror;
        bool      color;
    };
    void loadConfig();
}
