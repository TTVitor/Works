use rpg;

SELECT * FROM raridade;

ALTER TABLE raridade
ADD nivel_dificuldade VARCHAR(100) NOT NULL;

ALTER TABLE raridade
MODIFY COLUMN nivel_dificuldade CHAR(5);

ALTER TABLE raridade
DROP COLUMN nivel_dificuldade;

SELECT * FROM raca;

UPDATE raca
SET caracteristica = 'Baixa estatura', indole = 3
WHERE indole = 1;

SELECT * FROM tipo_localidade;

ALTER TABLE tipo_localidade
ADD ano_conquista YEAR NOT NULL;

UPDATE tipo_localidade
SET ano_conquista = 0001
WHERE ano_conquista = 0000;

ALTER TABLE tipo_localidade
DROP COLUMN ano_conquista;

SELECT * FROM personagem;

-- CREATE TABLE IF NOT EXISTS partida (
-- 	id INT NOT NULL UNIQUE,
-- 	inicio_partida DATETIME, 
-- 	fim_partida DATETIME,
-- 	score INT NOT NULL,
-- 	nome VARCHAR (100),
-- 	PRIMARY KEY (id),
-- );

ALTER TABLE personagem
ADD score INT NOT NULL;

-- para ranquear os jogadores por score
CREATE VIEW top_jogadores AS
	SELECT nome, score
	FROM personagem
	WHERE score >= (SELECT AVG(score) FROM personagem);

SELECT * FROM top_jogadores;

GRANT ALL ON *.* TO 'TTVitor'@'localhost' IDENTIFIED BY '12' WITH GRANT OPTION;
SHOW GRANTS FOR TTVitor@localhost;

REVOKE ALL ON *.* FROM TTVitor@localhost;
/*GRANT USAGE ON *.* TO `TTVitor`@`localhost` IDENTIFIED BY PASSWORD '*AA803D048B666A933E512AA53B36C70174A37D1E' WITH GRANT OPTION*/

TRUNCATE TABLE tipo_localidade; -- Nao é possivel pois sua foreign key está sendo referenciada em outras tabelas

CREATE VIEW v caractpersonagem AS
SELECT personagem.nome, poder.nome, elemento.nome, poder_elemento.quantidade 
FROM personagem INNER JOIN personagem_poder ON personagem_poder.personagem = personagem.id
INNER JOIN poder ON personagem_poder.poder = poder.id 
INNER JOIN poder_elemento ON poder_elemento.poder = poder.id
INNER JOIN elemento ON poder_elemento.elemento = elemento.id
ORDER BY personagem.nome;

SHOW GRANTS FOR 'root'@'localhost';

CREATE USER 'ttvitor'@'localhost' IDENTIFIED BY '18';
GRANT ALL ON *-* TO 'ttvitor'@'localhost' WITH GRANT OPTION;
SHOW GRANTS FOR 'ttvitor'@'localhost';

REVOKE ALL, GRANT OPTION FROM 'ttvitor'@'localhost';

GRANT SELECT (nome, cidade, arquetipo), UPDATE (nome, cidade, arquetipo) ON personagem 
WHERE id = 1 TO 'ttvitor'@'localhost';
SHOW GRANTS FOR 'ttvitor'@'localhost';

CREATE USER 'havirium'@'localhost' IDENTIFIED BY '24';
GRANT SELECT (nome, cidade, arquetipo), UPDATE (nome, cidade, arquetipo) ON personagem 
WHERE id = 2 TO 'havirium'@'localhost';
SHOW GRANTS FOR 'havirium'@'localhost';

CREATE USER 'kat'@'localhost' IDENTIFIED BY '66';
GRANT SELECT (nome, cidade, arquetipo), UPDATE (nome, cidade, arquetipo) ON personagem 
WHERE id = 4 TO 'kat'@'localhost';
SHOW GRANTS FOR 'kat'@'localhost';

INSERT INTO personagem VALUES
(5, "Max", 45, 'M', 2, 3, 5);
COMMIT;
ROLLBACK;
START TRANSACTION;

UPDATE indole SET nome = 'DEP' WHERE id = 3;
COMMIT;
ROLLBACK;
START TRANSACTION;

UPDATE arquetipo SET nome = "Assassino" WHERE id = 7;
COMMIT;
ROLLBACK;
START TRANSACTION;

TRIGGER ins_personagem AFTER INSERT ON personagem FOR EACH ROW 
BEGIN
	INSERT INTO personagem VALUES (5, "Aurelion", 1000, 'M',  1, 2 6);
	UPDATE personagem SET cidade = 2 WHERE id = 3;
END

TRIGGER upd_personagem_item AFTER UPDATE ON personagem_item FOR EACH ROW 
BEGIN 
	UPDATE personagem_item SET item = 1 WHERE id = 1;
	INSERT INTO personagem_item VALUES (2, 1, 10);
END

TRIGGER del_data_jogo BEFORE DELETE ON data_jogo
BEGIN
	UPDATE data_jogo SET lugar = "Mesão" WHERE id = 4;
	DELETE TABLE data_jogo;
END 
	