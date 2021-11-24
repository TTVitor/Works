drop database if exists vendas; -- excluir database

create database if not exists vendas
default character set utf8 -- uft8 (8-bit Unicode Transformation Format - Pode representar qualquer caracter universal padrão do Unicode, sendo também compatível com o ASCII)
default collate utf8_general_ci;

use vendas;-- selecionar banco de dados
/*
Outros comandos:
show database; -- lista os banco de dados criados
show tables;  -- lista as tabelas do database
describe ou desc "nome da tabela"; -- descreve os itens da tabela
*/

CREATE TABLE IF NOT EXISTS clientes ( -- criar tabela
    id INT NOT NULL,
    nome VARCHAR(100) NOT NULL,
    endereco VARCHAR(200),
    cidade VARCHAR(50),
    cep CHAR(8),
    uf CHAR(2),
    cnpj VARCHAR(20) NOT NULL UNIQUE,
    ie varchar (30),
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS vendedores (
    id INT NOT NULL,
    nome VARCHAR(100) NOT NULL,
    salario DECIMAL(7 , 2 ) NOT NULL,
    faixa_comissao ENUM('A', 'B', 'C'),
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS pedidos (
    id INT NOT NULL,
    prazo_entrega INT UNSIGNED NOT NULL,
    id_cliente INT NOT NULL,
    id_vendedor INT NOT NULL,
    PRIMARY KEY (id),
    FOREIGN KEY (id_cliente)
        REFERENCES clientes (id),
    FOREIGN KEY (id_vendedor)
        REFERENCES vendedores (id)
);

CREATE TABLE IF NOT EXISTS produtos (
    id INT NOT NULL,
    unidade VARCHAR(5) NOT NULL,
    descricao VARCHAR(100) NOT NULL UNIQUE,
    valor_unitario DECIMAL(4 , 2 ),
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS itens_pedido (
    id_pedido INT NOT NULL,
    id_produto INT NOT NULL,
    quantidade INT UNSIGNED NOT NULL,
    PRIMARY KEY (id_pedido , id_produto), -- chave primária composta  
    FOREIGN KEY (id_pedido)
        REFERENCES pedidos (id),
    FOREIGN KEY (id_produto)
        REFERENCES produtos (id)
);

INSERT INTO clientes VALUES 
(720, "Ana" , "Rua 17 n. 19", "Niteroi", 24358310, "RJ", 12113231000134, 2134),
(870, "Flavio" , "Av. Pres. Vargas 10", "Sao Paulo", 2276393, "SP", 2253412693879, 4631),
(110, "Jorge" , "Rua Caiapo 13", "Curitiba", 30078500, "PR", 1451276498349, NULL),
(222, "Lucia" , "Rua Itabira 123 Loja 9", "Belo Horizonte", 2212439, "MG", 2831521393488, 2985),
(830, "Mauricio" , "Av. Paulista 1236 sl 2345", "Sao Paulo", 3012683, "SP", 3281698574656, 9343),
(130, "Edmar" , "Rua da Praia sn", "Salvador", 30079300, "BA", 234632842349, 7121),
(410, "Rodolfo" , "Largo da Lapa 27 sobrado", "Rio de Janeiro", 30078900, "RJ", 1283512823469, 7431),
(20, "Beth" , "Av. Climerio 45", "Sao Paulo", 25679300, "SP", 3248512673268, 9280),
(157, "Paulo" , "Tv, Moraes c/3", "Londrina", NULL, "PR", 328482233242, 1923),
(180, "Livio", "Av. Beira Mar n. 1256", "Florianopolis", 30077500, "SC", 1273657123474,NULL),
(260, "Susana", "Rua Lopes Mendes 12", "Niteroi", 30046500, "RJ", 217635712329, 2530),
(290, "Renato", "Rua Meireles 123 bl.2 sl. 345", "Sao Paulo", 30225900, "SP", 1327657112314, 1820),
(390, "Sebastiao", "Rua da Igreja 10", "Uberaba", 30438700, "MG",  321765472133, 9071),
(234, "Jose", "Quadra 3 bl. 3 st. 1003", "Brasilia", 22841650, "DF", 2176357612323, 293);

INSERT INTO vendedores VALUES 
(209, "José", 1800, 'C'),
(111, "Carlos", 2490, 'A'),
(11, "João", 2780, 'C'),
(240, "Antônio", 9500, 'C'),
(720, "Felipe", 4600, 'A'),
(213, "Jonas", 2300, 'A'),
(101, "João", 2650, 'C'),
(310, "Josias", 870, 'B'),
(250, "Maurício", 2930, 'B');

INSERT INTO produtos VALUES 
(25, "Kg", "Queijo", 0.97),
(31, "BAR", "Chocolate", 0.87),
(78, "L", "Vinho", 2),
(22, "M", "Linho", 0.11),
(30, "SAC", "Açúcar", 0.3),
(53, "M", "Linha", 1.8),
(13, "G", "Ouro", 6.18),
(45, "M", "Madeira", 0.25),
(87, "M", "Cano", 1.97),
(77, "M", "Papel", 1.05);

INSERT INTO pedidos VALUES
(121,20,410,209),
(97,20,720,101),
(101,15,720,101),
(137,20,720,720),
(148,20,720,101),
(189,15,870,213),
(104,30,110,101),
(203,30,830,250),
(98,20,410,209),
(143,30,20,111),
(105,15,180,240),
(111,20,260,240),
(103,20,260,11),
(91,20,260,11),
(138,20,260,11),
(108,15,290,310),
(119,30,390,250),
(127,10,410,11);

INSERT INTO itens_pedido VALUES 
(97, 22, 31),
(98, 25, 77),
(101, 30, 31),
(103, 31, 78),
(104, 45, 13),
(105, 53, 77),
(108, 77, 45),
(111, 78, 31),
(119, 87, 77),
(121, 13, 25),
(127, 22, 78),
(137, 25, 53),
(138, 30, 31),
(143, 31, 78),
(148, 45, 31),
(189, 53, 78),
(203, 77, 78),
(91, 78, 25),
(97, 87, 78),
(98, 13, 53),
(101, 22, 77),
(103, 13, 22),
(104, 30, 77),
(105, 31, 53),
(108, 45, 13),
(119, 13, 77),
(121, 53, 13),
(127, 13, 22),
(137, 45, 53),
(138, 13, 13);

ALTER TABLE clientes
ADD email VARCHAR (100) UNIQUE;

ALTER TABLE clientes
MODIFY cidade VARCHAR (200);

ALTER TABLE clientes
DROP email;

SELECT descricao, unidade, valor_unitario FROM produtos;

SELECT * FROM vendedores;

SELECT cnpj, nome, endereco FROM clientes;

SELECT DISTINCT cidade FROM clientes;

SELECT DISTINCT cidade, uf FROM clientes;

SELECT nome FROM clientes WHERE cidade = "Niterói";

SELECT descricao FROM produtos WHERE unidade = 'M' AND valor_unitario = 1.05;

SELECT id, descricao, valor_unitario FROM produtos WHERE valor_unitario BETWEEN 0.32 AND 2.00;

SELECT id, descricao, valor_unitario FROM produtos WHERE valor_unitario NOT BETWEEN 0.32 AND 2.00;

SELECT nome FROM clientes WHERE nome BETWEEN "Ana" AND "Jorge" ORDER BY nome;

SELECT nome, faixa_comissao FROM vendedores WHERE faixa_comissao = 'A' OR 'B';

SELECT nome, ie FROM clientes WHERE ie IS NULL;

SELECT nome, ie FROM clientes WHERE ie IS NOT NULL;

SELECT * FROM vendedores LIMIT 2;

SELECT descricao FROM produtos WHERE descricao LIKE 'Q%';

SELECT nome FROM vendedores WHERE nome NOT LIKE 'Jo%';

SELECT descricao FROM produtos WHERE descricao LIKE '%o';

SELECT nome, salario FROM vendedores WHERE salario < 2000 ORDER BY salario ASC;

SELECT nome FROM vendedores WHERE nome NOT LIKE 'Jo%' ORDER BY nome DESC;

SELECT COUNT(id) AS QtdClientes FROM clientes;

SELECT COUNT(ie) AS QtdClientesIE FROM clientes;

SELECT COUNT(id) AS QtdProdutosMenorCinquenta FROM produtos WHERE valor_unitario < 0.5;

SELECT AVG(salario) AS MedSalario FROM vendedores;

SELECT AVG(valor_unitario) AS MedValorUni FROM produtos WHERE unidade = 'M';

SELECT SUM(salario) AS SomaSalario FROM vendedores;

SELECT SUM(salario) AS SomaSalario FROM vendedores WHERE faixa_comissao = 'A';

SELECT nome, salario, salario * 1.75 + 120 AS SalarioAtual FROM vendedores WHERE faixa_comissao = 'C' ORDER BY nome DESC;

SELECT * FROM pedidos INNER JOIN clientes;

SELECT * FROM pedidos INNER JOIN clientes;
SELECT * FROM clientes INNER JOIN pedidos;

SELECT ip.id_pedido, p.descricao, ip.quantidade
FROM itens_pedido AS ip
INNER JOIN produtos AS p ON ip.id_produto = p.id
WHERE ip.quantidade > 35
GROUP BY descricao
ORDER BY descricao;

SELECT * 
FROM pedidos 
INNER JOIN clientes ON pedidos.id_cliente = clientes.id
INNER JOIN vendedores ON pedidos.id_vendedor = vendedores.id;

-- Listar a quantidade de itens vendidos por produto ordenados de forma crescente
SELECT ip.quantidade, p.descricao FROM itens_pedido AS ip INNER JOIN produtos AS p ON ip.id_produto = p.id
ORDER BY descricao;

-- Listar todos os pedidos realizados, exibindo o nome dos clientes
SELECT ped.id, c.nome FROM pedidos AS ped INNER JOIN clientes AS c ON ped.id_cliente = c.id
ORDER BY c.nome;

-- Listar todos os pedidos realizados, exibindo o nome dos vendedores
SELECT ped.id, v.nome FROM pedidos AS ped INNER JOIN vendedores AS v on ped.id_vendedor = v.id
ORDER BY v.nome;

-- Listar todos os pedidos realizados, exibindo o nome dos vendedores e clientes, ordenados por prazo de entrega
SELECT ped.id, ped.prazo_entrega, c.nome, v.nome
FROM pedidos AS ped
INNER JOIN clientes AS c ON ped.id_cliente = c.id
INNER JOIN vendedores AS v ON ped.id_vendedor = v.id
ORDER BY ped.prazo_entrega;

-- Listar o id e prazo de entrega dos pedidos realizados pela cliente 'Susana', incluindo o nome do vendedor
SELECT ped.id, ped.prazo_entrega, c.nome, v.nome
FROM pedidos AS ped
INNER JOIN clientes AS c ON ped.id_cliente = c.id
INNER JOIN vendedores AS v ON ped.id_vendedor = v.id
WHERE c.nome = "Susana";

-- Listar o prazo_entrega mínima para cada cliente, apresentando nome do cliente (agrupado), ordenados por prazo máximo
SELECT MIN(ped.prazo_entrega), c.nome
FROM pedidos AS ped
INNER JOIN clientes AS c ON ped.id_cliente = c.id
GROUP BY c.nome
ORDER BY MAX(ped.prazo_entrega);

-- Listar os clientes e vendedores com prazo de entrega entre 10 e 20 dias e ordene por prazo de entrega. O nome do campo deve ser alterado para nomeCliente e nomeVendedor
SELECT ped.prazo_entrega, c.nome AS nomeCliente, v.nome AS nomeVendedor
FROM pedidos AS ped
INNER JOIN clientes AS c ON ped.id_cliente = c.id
INNER JOIN vendedores AS v ON ped.id_vendedor = v.id
WHERE ped.prazo_entrega >= 10 AND ped.prazo_entrega <= 20
ORDER BY ped.prazo_entrega;

-- Listar cliente e média de prazo para entrega, considerando apenas os clientes com prazo acima de 10 dia 
SELECT AVG(ped.prazo_entrega), c.nome
FROM pedidos AS ped
INNER JOIN clientes AS c ON ped.id_cliente = c.id
WHERE ped.prazo_entrega > 10
GROUP BY c.nome
ORDER BY c.nome;

-- Ao final, apresente somente os clientes cuja média é superior a 15 dias 
-- Ordene por prazo máximo
SELECT AVG(ped.prazo_entrega), c.nome
FROM pedidos AS ped
INNER JOIN clientes AS c ON ped.id_cliente = c.id
WHERE ped.prazo_entrega > 10
GROUP BY c.nome HAVING AVG(ped.prazo_entrega) > 15
ORDER BY MAX(ped.prazo_entrega);

-- Listar os nomes dos produtos com quantidade somada, 
-- porém, considerando apenas os itens com quantidade inferior a 30.
-- Ao final, apresente apenas os itens cuja soma é superior a 40

SELECT p.descricao, SUM(ip.quantidade)
FROM produtos AS p
INNER JOIN itens_pedido AS ip ON p.id = ip.id_produto
WHERE ip.quantidade < 30
GROUP BY p.descricao HAVING SUM(ip.quantidade) > 40;

-- Listar o nome do cliente, nome do vendedor, o id do pedido e os produtos comprados. Ordenar por cliente. 
SELECT c.nome AS nomeCliente, ped.id, v.nome AS nomeVendedor, p.descricao
FROM pedidos AS ped
INNER JOIN clientes AS c ON ped.id_cliente = c.id
INNER JOIN vendedores AS v ON ped.id_vendedor = v.id
INNER JOIN itens_pedido AS ip ON ped.id = ip.id_pedido
INNER JOIN produtos AS p ON ip.id_produto = p.id
ORDER BY c.nome, ped.id;

-- Listar os nomes dos clientes que compraram 'Vinho'
SELECT DISTINCT c.nome
FROM pedidos AS ped
INNER JOIN clientes AS c ON ped.id_cliente = c.id
INNER JOIN itens_pedido AS ip ON ped.id = ip.id_pedido
INNER JOIN produtos AS p ON ip.id_produto = p.id
WHERE p.descricao = "Vinho"
ORDER BY c.nome;

-- Listar os nomes dos vendedores que venderam 'Vinho'
SELECT DISTINCT v.nome
FROM pedidos AS ped
INNER JOIN vendedores AS v ON ped.id_vendedor = v.id
INNER JOIN itens_pedido AS ip ON ped.id = ip.id_pedido
INNER JOIN produtos AS p ON ip.id_produto = p.id
WHERE p.descricao = "Vinho"
ORDER BY v.nome;

-- Listar qual a quantidade de 'Vinho' vendida pelos vendedores, ordenar por quantidade. 
SELECT DISTINCT v.nome, ip.quantidade
FROM pedidos AS ped
INNER JOIN vendedores AS v ON ped.id_vendedor = v.id
INNER JOIN itens_pedido AS ip ON ped.id = ip.id_pedido
INNER JOIN produtos AS p ON ip.id_produto = p.id
WHERE p.descricao = "Vinho"
ORDER BY ip.quantidade;

INSERT INTO produtos VALUES
(44, "KG", "Carne", 21);

-- Listar os pedidos, com o nome dos produtos, mas também os produtos que não constam da lista de pedidos
SELECT ped.id, p.descricao
FROM pedidos AS ped
INNER JOIN itens_pedido AS ip ON ped.id = ip.id_pedido
RIGHT JOIN produtos AS p ON ip.id_produto = p.id
ORDER BY p.descricao, ped.id;

SELECT COUNT(ped.id), p.descricao, c.nome, SUM(ip.quantidade)
FROM pedidos AS ped
INNER JOIN clientes AS c ON ped.id_cliente = c.id
INNER JOIN itens_pedido AS ip ON ped.id = ip.id_pedido
INNER JOIN produtos AS p ON ip.id_produto = p.id
WHERE p.descricao = "Ouro"
GROUP BY c.nome;
