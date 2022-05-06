/*
COMMIT: encerra a transação salvando permanentemente todas as alterações realizadas durante a transação.
ROLLBACK: encerra a transação descartando permanentemente todas as alterações realizadas durante a transação.
ALTERAÇÕES(updates, deletes, inserts)
PROMISES: são uma abstração utilizada para representar fluxos de ações em código assíncrono, sendo um objeto que representa o resultado
de uma operação assíncrona, podendo este resultado ser bem sucedido(gerado pela chamada da função RESOLVE e que desencadeia a chamada 
do método THEN) ou mal sucedido(gerado pela chamada da função REJECT e que desencadeia a chamada do método CATCH).
*/

function isUserTooYoung(id, callback){
    openDatabase(function(db){
        getCollection(db, 'users', function(col){
            find(col, {'id' : id}, function(result){
                result.filter(function(user){
                    callback(user.age < cutoffAge)
                })
            })
        })
    })
}

function isUserTooYoung(id){
    return openDatabase(db)
        .then(getCollection)
        .then(find.bind(null, {'id' : id}))
        .then(function(user){
            return user.age < cutoffAge;
        });
}

/*
Quando a promessa é criada, assume-se imediatamente o estado PENDING. Eventualmente, a promessa pode ser "finalizada", passando para
FULLFILLED(resolvida com algum valor) ou REJECTED(rejeitada com algum erro), quando esté em um desses estados a promessa está em
SETTLED(finalizadas). Só podem ocorrer uma única vez visto que são estados finais e não podem retornar para pending.
ASYNC: é uma anotação que pode ser utilizada para marcar funções como assíncronas, podendo utilizar o operador AWAIT. O uso do
ASYNC/AWAIT dão aparência de sincronismo, uma vez que, dentro da função assíncrona, o await bloqueia a execução até que a promessa seja
settled.
*/

const s = new Date().getSeconds();

setTimeout(function () {
    console.log("Ran after" + (new Date().getSeconds() - s) + " seconds");
}, 500);

while (true) {
    if (new Date().getSeconds() - s >= 2) {
        console.log("Good, looped for 2 seconds");
        break;
    }
}

/*
As chamadas de funções criam uma pilha de frames(quadros) PILHA - STACK
Os objetos são alocados em um ACERVO - HEAP
O runtime do js contém uma fila de mensagens, que é uma lista de mensagens a serem processadas. Cda mensagem é associada a uma função,
que é chamada para lidar com a mensagem.
Em algum ponto durante o EVENT LOOP, o runtime começa a manipular as mensagens na fila, começando pela mais antiga. Para fazer isso, a
mensagem é removida da fila e sua função correspondente é chamada com a mensagem como um parâmentro de input(entrada). Como de costume,
chamar uma função cria um novo frame(quadro) na pilha para uso dessa função.
*/

(function () {
    console.log("this is the start");

    setTimeout(function cb() {
        console.log("Callback 1: this is a msg from call back");
    });

    console.log("this is just a message");

    setTimeout(function cb1() {
        console.log("Callback 2: this is a msg from call back");
    }, 0);

    console.log("this is the end");
})();

/*
SEÇÃO CRÍTICA: objeto de usuário usado para permitir a execução de apenas um encadeamento ativo de muitos outros em um processo.
Os outros threads não selecionados são colocados no modo de suspensão.
LOCK: uma variável cujo valor permite ou nega a entrada em uma região crítica.
SEMÁFORO: usado para permitir a execução de apenas um encadeamento ativo de muitos outros, entre diferentes processos.
*/