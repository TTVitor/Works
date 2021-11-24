drop database if exists rpg;

create database if not exists rpg
default character set utf8 -- uft8 (8-bit Unicode Transformation Format - Pode representar qualquer caracter universal padrão do Unicode, sendo também compatível com o ASCII)
default collate utf8_general_ci;

use rpg;

CREATE TABLE IF NOT EXISTS tipo_sangue (
	id INT NOT NULL UNIQUE,
    nome CHAR(3) NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS tipo_localidade (
	id INT NOT NULL UNIQUE,
    nome VARCHAR(100) NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS indole (
	id INT NOT NULL UNIQUE,
    nome CHAR(3) NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS elemento (
	id INT NOT NULL UNIQUE,
    nome VARCHAR(100) NOT NULL,
    gravidade VARCHAR(100),
    combinacao CHAR(1),
    indole INT,
    PRIMARY KEY (id),
    FOREIGN KEY (indole)
		REFERENCES indole (id)
);

CREATE TABLE IF NOT EXISTS dominio (
	id INT NOT NULL UNIQUE,
    nome VARCHAR(100) NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS religiao (
	id INT NOT NULL UNIQUE,
    nome VARCHAR(100) NOT NULL,
    tipo VARCHAR(100),
    costume VARCHAR(100),
    culto VARCHAR(100),
    elemento INT,
    PRIMARY KEY (id),
    FOREIGN KEY (elemento)
		REFERENCES elemento (id)
);

CREATE TABLE IF NOT EXISTS origem (
	id INT NOT NULL UNIQUE,
    nome VARCHAR(100) NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS deus (
	id INT NOT NULL UNIQUE,
    nome VARCHAR(100) NOT NULL,
    hierarquia VARCHAR(100),
    simbolo VARCHAR(100),
    dominio INT,
    indole INT,
    religiao INT,
    origem INT,
	PRIMARY KEY (id),
    FOREIGN KEY (dominio)
		REFERENCES dominio (id),
	FOREIGN KEY (indole)
		REFERENCES indole (id),
	FOREIGN KEY (religiao)
		REFERENCES religiao (id),
	FOREIGN KEY (origem)
		REFERENCES origem (id)
);

CREATE TABLE IF NOT EXISTS cidade (
	id INT NOT NULL UNIQUE,
    nome VARCHAR(100) NOT NULL,
    regimento VARCHAR(100),
    clima VARCHAR(100),
    temperatura VARCHAR(100),
    localidade INT NOT NULL,
    religiao INT,
    PRIMARY KEY (id),
    FOREIGN KEY (localidade)
		REFERENCES tipo_localidade (id),
	FOREIGN KEY (religiao)
		REFERENCES religiao (id)
);

CREATE TABLE IF NOT EXISTS arquetipo (
	id INT NOT NULL UNIQUE,
    nome VARCHAR(100) NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS personagem (
	id INT NOT NULL UNIQUE,
	nome VARCHAR(100) NOT NULL,
	idade INT,
    sexo CHAR(1),
    sangue INT,
    cidade INT,
    arquetipo INT,
    PRIMARY KEY (id),
    FOREIGN KEY (sangue)
		REFERENCES tipo_sangue (id),
	FOREIGN KEY (cidade)
		REFERENCES cidade (id),
	FOREIGN KEY (arquetipo)
		REFERENCES arquetipo (id)
);

CREATE TABLE IF NOT EXISTS poder (
	id INT NOT NULL UNIQUE,
    nome VARCHAR(100) NOT NULL,
	distancia VARCHAR(100),
    indole INT,
    PRIMARY KEY (id),
    FOREIGN KEY (indole)
		REFERENCES indole (id)
);


CREATE TABLE IF NOT EXISTS poder_elemento (
	poder INT NOT NULL,
    elemento INT NOT NULL,
    quantidade INT NOT NULL,
    PRIMARY KEY(poder, elemento),
    FOREIGN KEY (poder)
		REFERENCES poder (id),
	FOREIGN KEY (elemento)
		REFERENCES elemento (id)
);

CREATE TABLE IF NOT EXISTS personagem_poder (
	personagem INT NOT NULL,
    poder INT NOT NULL,
    PRIMARY KEY (personagem, poder),
    FOREIGN KEY (personagem)
		REFERENCES personagem (id),
	FOREIGN KEY (poder)
		REFERENCES poder (id)
);

CREATE TABLE IF NOT EXISTS raca (
	id INT NOT NULL UNIQUE,
    nome VARCHAR(100) NOT NULL,
    caracteristica VARCHAR(100),
    indole INT,
    PRIMARY KEY (id),
    FOREIGN KEY (indole)
		REFERENCES indole (id)
);

CREATE TABLE IF NOT EXISTS personagem_raca (
	personagem INT NOT NULL,
    raca INT NOT NULL,
    quantidade INT NOT NULL,
    PRIMARY KEY (personagem, raca),
    FOREIGN KEY (personagem)
		REFERENCES personagem (id),
	FOREIGN KEY (raca)
		REFERENCES raca (id)
);

CREATE TABLE IF NOT EXISTS raridade (
	id INT NOT NULL UNIQUE,
    nome VARCHAR(100) NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS tipo_item (
	id INT NOT NULL UNIQUE,
    nome VARCHAR(100) NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS item (
	id INT NOT NULL UNIQUE,
    nome VARCHAR(100) NOT NULL,
    tipo_item INT NOT NULL,
    raridade INT,
    trocavel BOOLEAN,
    PRIMARY KEY (id),
    FOREIGN KEY (raridade)
		REFERENCES raridade (id),
	FOREIGN KEY (tipo_item)
		REFERENCES tipo_item (id)
);

CREATE TABLE IF NOT EXISTS arma (
	item INT NOT NULL UNIQUE,
    elemento INT,
    dano INT,
    fraqueza VARCHAR(100),
    tipo VARCHAR(100),
    alcance VARCHAR(100),
    PRIMARY KEY (item),
    FOREIGN KEY (item)
		REFERENCES item (id),
	FOREIGN KEY (elemento)
		REFERENCES elemento (id)
);

CREATE TABLE IF NOT EXISTS personagem_item (
	personagem INT NOT NULL,
    item INT NOT NULL,
    quantidade INT,
	PRIMARY KEY (personagem, item),
    FOREIGN KEY (personagem)
		REFERENCES personagem (id),
	FOREIGN KEY (item)
		REFERENCES item (id)
);


CREATE TABLE IF NOT EXISTS data_jogo(
	id INT NOT NULL UNIQUE,
    lugar VARCHAR(100) NOT NULL,
    endereco VARCHAR(100) NOT NULL,
    data_game DATE NOT NULL,
    hora TIME NOT NULL,
    PRIMARY KEY (id)
);