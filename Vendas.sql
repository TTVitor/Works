CREATE DATABASE IF NOT EXISTS vendas;
# id, nome, UF
CREATE TABLE IF NOT EXISTS clientes(
	id INT UNSIGNED NOT NULL,
    nome VARCHAR(100) NOT NULL,
    endereco VARCHAR (200),
    cidade VARCHAR (50), 
    cep CHAR(9),
    uf CHAR (2) ,
    cnpj CHAR(14) NOT NULL UNIQUE,
    ie VARCHAR (30),
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS vendedores(
	id INT UNSIGNED NOT NULL,
	nome VARCHAR(100) NOT NULL,
	salario DECIMAL (10, 2) NOT NULL,
	faixa_comissao ENUM ('A', 'B', 'C') NOT NULL,
	PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS pedidos(
	id INT UNSIGNED NOT NULL,
    prazo_entrega INT UNSIGNED NOT NULL,
    id_cliente INT NOT NULL,
    id_vendedor INT NOT NULL,
     PRIMARY KEY (id),
     FOREIGN KEY (id_cliente) REFERENCES clientes (id),
     FOREIGN KEY (id_vendedor) REFERENCES vendedores (id)
);

CREATE TABLE IF NOT EXISTS produtos(
	id INT UNSIGNED NOT NULL,
    unidade_produto VARCHAR(100) NOT NULL,
    descricao_produto VARCHAR (100) NOT NULL,
    valor_uni DECIMAL (3,2) NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS itens_pedidos(
    id_pedido INT NOT NULL,
    id_produto INT NOT NULL,
    quantidade INT UNSIGNED NOT NULL,
	FOREIGN KEY (id_pedido) REFERENCES pedidos (id),
    FOREIGN KEY (id_produto) REFERENCES produtos (id),
	PRIMARY KEY (id_pedido, id_produto)
);

INSERT INTO clientes VALUES
(720, "Ana", "Rua 17 n. 19", "Niterói", 24358310, "RJ", 12113231000134, 2134),
(870, "Flávio", "Av. Pres. Vargas 10", "São Paulo", 22763931, "SP", 2253412693879, 4631),
(110, "Jorge", "Rua Caiapo 13", "Curitiba", 30078500, "PR", 1451276498349, NULL),
(222, "Lúcia", "Rua Itabira 123 Loja 9", "Belo Horizonte", 22124391, "MG", 2831521393488, 2985),
(830, "Maurício", "Av. Paulista 1236 sl 2345", "São Paulo", 3012683, "SP", 3281698574656, 9343),
(130, "Edmar", "Rua da Praia sn", "Salvador", 30079300, "BA", 234632842349, 7121),
(410, "Rodolfo", "Largo da Lapa 27 sobrado", "Rio de Janeiro", 30078900, "RJ", 1283512823469, 7431),
(20, "Beth", "Av. Climério 45", "São Paulo", 25679300, "SP", 3248512673268, 9280),
(157, "Paulo", "Tv. Moraes c/3", "Londrina", NULL, "PR", 328482233242, 1923),
(180, "Lívio", "Av. Beira Mar n. 1256", "Florianópolis", 30077500, "SC", 1273657123474, NULL),
(260, "Susana", "Rua Lopes Mendes 12", "Niterói", 30046500, "RJ", 217635712329, 2530),
(290, "Renato", "Rua Meireles 123 bl. 2 sl. 345", "São Paulo", 30225900, "SP", 1327657112314, 1820),
(390, "Sebastião", "Rua da Igreja 10", "Uberaba", 30438700, "MG", 321765472133, 9071),
(234, "José", "Quadra 3 bl. 3 sl. 1003", "Brasília", 22841650, "DF", 2176357612323, 2931); 

INSERT INTO vendedores VALUES
(209, "José", 1.800, 'C'),
(111, "Carlos", 2.490, 'A'),
(11, "João", 2.780, 'C'),
(240, "Antônio", 9.500, 'C'),
(720, "Felipe", 4.600, 'A'),
(213, "Jonas", 2.300, 'A'),
(101, "João", 2.650, 'C'),
(310, "Josias", 870, 'B'),
(250, "Maurício", 2.930, 'B');

INSERT INTO pedidos VALUES
(121, 20, 410, 209),
(97, 20, 720, 101),
(101, 15, 720, 101),
(137, 20, 720, 720),
(148, 20 , 720, 101),
(189, 15, 870, 213),
(104, 30, 110, 101),
(203, 30, 830, 250),
(98, 20, 410, 209),
(143, 30, 20, 111),
(105, 15, 180, 240),
(111, 20, 260, 240),
(103, 20, 260, 11),
(91, 20, 260, 11), 
(138, 20, 260, 11),
(108, 15, 290, 310),
(119, 30, 390, 250),
(127, 10, 410, 11);

INSERT INTO produtos VALUES
(25, "KG", "Queijo", 0.97),
(31, "BAR", "Chocolate", 0.87),
(78, "L", "Vinho", 2),
(22, "M", "Linho", 0.11),
(30, "SAC", "Açúcar", 0.3),
(53, "M", "Linha", 1.8),
(13, "G", "Ouro", 6.18),
(45, "M", "Madeira", 0.25),
(87, "M", "Cano", 1.97),
(77, "M", "Papel", 1.05);

INSERT INTO itens_pedidos VALUES
(121, 25, 10),
(121, 31, 35),
(97, 77, 20),
(101, 31, 9),
(101, 78, 18),
(101, 13, 5),
(98, 77, 5),
(148, 45, 8),
(148, 31, 7),
(148, 77, 3),
(148, 25, 10),
(148, 78, 30),
(104, 53, 32),
(203, 31, 6),
(189, 78, 45),
(143, 31, 20),
(143, 78, 10),
(105, 78, 10),
(111, 25, 10),
(111, 78, 70),
(103, 53, 37),
(91, 77, 40),
(138, 22, 10),
(138, 77, 35),
(138, 53, 18),
(108, 13, 17),
(119, 77, 40),
(119, 13, 6),
(119, 22, 10),
(119, 53, 43),
(137, 13, 8);