
#include "cmdOptions.h"

using namespace std;

        char* getCmdOption(char ** begin, char ** end, const string & option){
            
            char ** itr = find(begin, end, option);

            if (itr != end && ++itr != end){
                return *itr;
            }
            return 0;
        }

        bool cmdOptionExists(char** begin, char** end, const string& option){
            return find(begin, end, option) != end;
        }
