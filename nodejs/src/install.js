const { parseOptions, runCmd } = require("./utils");
const inquirer = require("inquirer");
const { createSpinner } = require("nanospinner");
const download = require('download');
const instalLoc = "/home/mcorange/Documents"

module.exports = async function install(name="test-package", version="latest") {
	// check in database if package exists
	if (true) {
		const confirm = await inquirer.prompt({
			name: 'confirm',
			type: 'confirm',
			message: `Are you sure you want to install ${name}?`,
			default(){
				return true;
			}
		});

		if (confirm) {

			const sleep = (ms = 1000) => new Promise((r) => setTimeout(r, ms));

			const spinner = createSpinner(`Removing files from old installation\n`).start();
			await runCmd(`rm -rfv ${instalLoc}/${name}-${version}.tar.gz ${instalLoc}/${name}-${version}`)
			spinner.update({text: `Downloading ${name}-${version}.tar.gz\n`})
			await download(`https://mcorange.tk/mcpc/packages/${name}-${version}.tar.gz`, `${instalLoc}/`).catch((err) => {
				return spinner.error({text: `Failed downloading package ${name}`})
			})
			sleep(500);
			console.log('Done!')

			spinner.update({text: `Successfully downloaded package ${name}-${version}.tar.gz\n`})
			
			spinner.update({text: `Making directory ${name}-${version} and uncompressing ${name}-${version}.tar.gz\n`})
			await runCmd(`mkdir -p ${instalLoc}/${name}-${version} && tar -xzf ${instalLoc}/${name}-${version}.tar.gz -C ${instalLoc}/${name}-${version}`);
			//await runCmd(`cp -rv ./packages/${name}-${version}/ ${instalLoc}/`)
			spinner.update({text: `Installing package ${name}-${version}\n`})
			await runCmd(`make -C ${instalLoc}/${name}-${version}`)
			await runCmd(`make install -C ${instalLoc}/${name}-${version}`).then(() => {
				return spinner.success({text: `Installed package ${name}-${version}`});
			})
			return 0;
		}
	} else {

	}
}