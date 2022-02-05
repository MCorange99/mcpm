#!/usr/bin/env node
// this sets up the args c style
const argv = process.argv;
const node_path = argv.shift();
const script_path = argv.shift();
const argc = argv.length;

// settings:
const utils = require("./src/utils");
const install = require("./src/install");
const remove = require("./src/remove");
const query = require("./src/query");
const fupdate = require("./src/fupdate");
const refresh = require("./src/refresh");


const version = "0.0.0.3";
let options = {
	"ls_opt": false,
	"help": false,
	"install": false,
	"uninst": false,
	"query": false,
	"fupdate": false,
	"refresh": false,
}

function fn_credits(){
console.log("" +
"========================\n" +
`MCPM Version ${version}\n` +
"========================\n" 
)
}

function fn_help(){
console.log("" +
"-h, --help     Print this text.\n" +
"-S, --install  Install package\n" +
"-R, --remove   Uninstall/Remove package.\n" +
"-Q, --query    Query the database for a package.\n" +
"-u, --update   Updates all packages.\n" + 
"-y, --refresh  Update package database.\n" +
"\n"+
"Made by MCorange\n"
)
}

function main(argc, argv){
	fn_credits();

	if (argv[0]) options = utils.parseOptions(options, argv);
	if (!argv[0]) return fn_help();
	if (options.ls_opt) console.log(options);
	if (options.help) return fn_help();
	if (options.install && !options.remove && !options.query) return install(argv[1], argv[2])
	

}; main(argc, argv);

