var hoursem;
var sal;
var saldia;
var saldosal;
var anoscompl;
var avprev;
var avprevf;
var feriasparc;
var ferias;
var valmes;
var feriasprop;
var consti;
var totaldevido;

var readlineSync = require('readline-sync');
var sal = readlineSync.question('Informe o salario do funcionario: ');
console.log('Salario do funcionario: ' + sal);
var hoursem = readlineSync.question('Informe a quantidade de horas semanais: ')
console.log('Horas semanais: ' + hoursem);
var saldia = sal/30;
console.log('Salario por dia: ' + saldia);
var saldosal = saldia*17;
console.log('Saldo de salario: ' + saldosal);

var anoscompl = readlineSync.question('Informe o total de anos completos trabalhados: ');
console.log('Anos completos totais trabalhados: ' + anoscompl);
var avprev = 30+(3*anoscompl);
var avprevf = avprev*saldia;
console.log('Aviso previo: ' + avprevf);
var feriasparc = sal/3;
var ferias = (saldia*30)+feriasparc;
console.log('Ferias remuneradas: ' + ferias);
var valmes = sal/12;
var feriasprop = readlineSync.question('Informe os meses das ferias proporcionais desde a saida do funcionario: ');
var feriasprop = feriasprop+valmes;
console.log('Ferias proporcionais: ' + feriasprop);
var consti = feriasprop/3;
console.log('Constitucional: ' + consti);
var totaldevido = feriasprop+consti;
console.log('Total devido: ' + totaldevido);

