#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>


#include "config.h"
#include "cmdOptions.h"

using namespace std;

char version[] = "0.0.0.3";
bool ls_opt = false;
bool help = false;
bool install = false;
bool uninst = false;
bool query = false;
bool fupdate = false;
bool refresh = false;

// struct Config {
//     int       version;
//     string    mirror;
//     bool      color;
// };

// void loadConfig(Config& config) {
//     ifstream fin("config.conf");
//     string line;
//     while (getline(fin, line)) {
//         istringstream sin(line.substr(line.find("=") + 1));
//         if (line.find("version") != -1)
//             sin >> config.version;
//         else if (line.find("mirror") != -1)
//             sin >> config.mirror;
//         else if (line.find("color") != -1)
//             sin >> config.color;
//     }
// }

// char* getCmdOption(char ** begin, char ** end, const string & option)
// {
//     char ** itr = find(begin, end, option);
//     if (itr != end && ++itr != end)
//     {
//         return *itr;
//     }
//     return 0;
// }

// bool cmdOptionExists(char** begin, char** end, const string& option)
// {
//     return find(begin, end, option) != end;
// }

////////////////////////////////////////////////////////

// char cnv_str(string myString){
//     char str[myString.length() + 1] = {};
//     strcpy(str, myString.c_str());
//     return str*;
// }

class Config {
    public:
        int       version;
        string    mirror;
        bool      color;
    };
int credits(){
    printf("==================\n");
    printf("MCPM Version %s\n", version);
    printf("==================\n\n");
    return 0;
}

char suggestHelp(char option[]){
    printf("Unknown options '%s'", option);
    return 0;
}

int fn_install(int argc, char* argv[], string install_str, string mirror){
    char mirrorc[mirror.length() + 1] = {};
        strcpy(mirrorc, mirror.c_str());
    char install_str_c[install_str.length() + 1] = {};
        strcpy(install_str_c, install_str.c_str());

    char command0[1024] = "bash cd ";
    strcat(command0, "/tmp/");
    cout << "Preparing: " << install_str;
    system(command0);
    printf("\n");
    
    char command[1024] = "bash wget ";
    strcat(command, mirrorc);
    strcat(command, install_str_c);
    strcat(command, ".tar.gz");
    cout << "Downloading: " << install_str;
    system(command);
    printf("\n");
    
    char command2[1024] = "bash tar -xzf ";
    strcat(command2, "/tmp/");
    strcat(command2, install_str_c);
    strcat(command2, ".tar.gz");
    cout << "Extracting: " << install_str;
    system(command2);
    printf("\n");
    
    char command3[1024] = "bash cd ";
    strcat(command3, "/tmp/");
    strcat(command3, install_str_c);
    system(command3);
    printf("\n");

    cout << "Installing: " << install_str;
    system("bash make");
    system("bash make install");
    printf("\n");
    return 0;
}

int fn_uninst(int argc, char* argv[], string uninst_str){
    cout << "Removing: " << uninst_str;
    return 0;
}

int fn_query(int argc, char* argv[], string query_str){
    cout << "Querying: %s" <<  query_str;
    return 0;
}

int main(int argc, char* argv[]){

    cfg::Config config;

    credits();
    cfg::loadConfig();
    if (argc < 1){
        printf("For help use -h or --help options.");
    }

    //InputParser input(argc, argv);

    if(cmdOpt::cmdOptionExists(argv, argv+argc, "-h")){
        help = true;
    }
    if(cmdOpt::cmdOptionExists(argv, argv+argc, "--help")){
        help = true;
    }

    if(help) return 0;

    char * install_str = cmdOpt::getCmdOption(argv, argv + argc, "--install");
    if (install_str){
        install = true;
    }
    install_str = cmdOpt::getCmdOption(argv, argv + argc, "-S");
    if (install_str){
        install = true;
    }
    char * uninst_str = cmdOpt::getCmdOption(argv, argv + argc, "--remove");
    if (uninst_str){
        uninst = true;
    }
    uninst_str = cmdOpt::getCmdOption(argv, argv + argc, "-R");
    if (uninst_str){
        uninst = true;
    }
    char * query_str = cmdOpt::getCmdOption(argv, argv + argc, "--query");
    if (query_str){
        query = true;
    }
    query_str = cmdOpt::getCmdOption(argv, argv + argc, "-Q"); 
    if (query_str){
        query = true;
    }    
    if(cmdOpt::cmdOptionExists(argv, argv+argc, "-u")){
        fupdate = true;
    }
    if(cmdOpt::cmdOptionExists(argv, argv+argc, "--update")){
        fupdate = true;
    }
    if(cmdOpt::cmdOptionExists(argv, argv+argc, "-y")){
        refresh = true;
    }
    if(cmdOpt::cmdOptionExists(argv, argv+argc, "--refresh")){
        refresh = true;
    }
    if(cmdOpt::cmdOptionExists(argv, argv+argc, "--ls_opt")){
        ls_opt = true;
    }
    if(ls_opt){
        printf("ls_opt: %s\n", ls_opt ? "true" : "false");
        printf("help: %s\n", help ? "true" : "false");
        printf("install: %s\n", install ? "true" : "false");
        printf("remove: %s\n", uninst ? "true" : "false");
        printf("query: %s\n", query ? "true" : "false");
        printf("full update: %s\n", fupdate ? "true" : "false");
        printf("refresh: %s\n", refresh ? "true" : "false");
            char mirror[config.mirror.length() + 1] = {};
            strcpy(mirror, config.mirror.c_str());
        printf("mirror: %s\n", mirror);
    }

    if(install){
        if (uninst || query) {
            printf("[ERR]: Option 'install' is incompatible with options 'remove', 'query'");
            return 1;
        }
        fn_install(argc, argv, install_str, config.mirror);
    }
    
    if(uninst){
        if (install || query || fupdate || refresh) {
            printf("[ERR]: Option 'remove' is incompatible with options 'install', 'query', 'full update', 'refresh'");
            return 1;
        }
        fn_uninst(argc, argv, uninst_str);
    }

    /*
    bool ls_opt = false;
    bool help = false;
    bool install = false;
    bool uninst = false;
    bool query = false;
    bool fupdate = false;
    bool refresh = false;
    */


    return 0;
}