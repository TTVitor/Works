var chalk = require('chalk')
var readlineSync = require('readline-sync');

var name = readlineSync.question('Nome: ');
console.log('Nome informado: ' + name + '!');

console.log(chalk.red(name));
