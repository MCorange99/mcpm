//const { exec } = require("child_process");

const util = require('util');
const exec = util.promisify(require('child_process').exec);

const parseOptions = (options, argv) => {
	if(argv[0].startsWith("-")){
			if(argv.includes("--help")){
				options.help = true;
				}
			if(argv.includes("-h")){
				options.help = true;
				}
			if(argv.includes("-S")){
				options.install = true;
				}
			if(argv.includes("--install")){
				options.install = true;
				}
			if(argv.includes("-R")){
				options.uninst = true;
				}
			if(argv.includes("--remove")){
				options.uninst = true;
				}
			if(argv.includes("-Q")){
				options.query = true;
				}
			if(argv.includes("--query")){
				options.query = true;
				}
			if(argv.includes("-u")){
				options.fupdate = true;
				}
			if(argv.includes("--update")){
				options.fupdate = true;
				}
			if(argv.includes("-y")){
				options.sync = true;
				}
			if(argv.includes("--sync")){
				options.sync = true;
				}
			if(argv.includes("--ls_opt")){
				options.ls_opt = true;
				}
		} else {
			options.help = true;
		}
		return options;
}

// async function runCmd(cmd){
// 	 return new Promise(function(resolve, reject){
// 	await exec(cmd, (error, stdout, stderr) => {
//     if (error) {
//         console.log(`error: ${error.message}`);
//         return 1;
//     }
//     if (stderr) {
//         console.log(`stderr: ${stderr}`);
//         return 1;
//     }
//     console.log(stdout);
// 	});
// 	//return 0;
// 	}
// }


async function runCmd(cmd) {
  try {
    const { stdout, stderr } = await exec(cmd);
    console.log(stdout);
    console.log(stderr);
  } catch (e) {
    console.error(e); // should contain code (exit code) and signal (that caused the termination).
  }
}


module.exports = {
	parseOptions,
	runCmd
}