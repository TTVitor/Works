use rpg;

-- recupera a lista de Deus exibindos as informaçãos referentes a domínio, índole, religião e origem sobre o mesmo
SELECT d.nome, i.nome, r.nome, o.nome FROM deus AS dg INNER JOIN dominio AS d ON dg.dominio = d.id
INNER JOIN indole AS i ON dg.indole = i.id INNER JOIN religiao AS r ON dg.religiao = r.id
INNER JOIN origem AS o ON dg.origem = o.id;

-- recupera a lista de cidade exibindo as informações referentes a religião e o tipo de localidade
SELECT r.nome, tl.nome FROM cidade AS c INNER JOIN religiao AS r ON c.religiao = r.id
INNER JOIN tipo_localidade AS tl ON c.localidade = tl.id;

-- recupera a lista de personagem trazendo as informações referentes ao tipo sanguínio, cidade e arquétipo do personagem
SELECT s.nome, c.nome, a.nome FROM personagem AS p INNER JOIN tipo_sangue AS s ON p.sangue = s.id
INNER JOIN cidade AS c ON p.cidade = c.id INNER JOIN arquetipo AS a ON p.arquetipo = a.id;

-- recupera o total calculado do poder referente a junção do poder de cada personagem 
SELECT COUNT(poder) AS QtdPoder FROM personagem_poder;


-- recupera a lista de personagem exibindo seus nomes, poderes e os elementos a quais pertencem
SELECT personagem.nome, poder.nome, elemento.nome, poder_elemento.quantidade 
FROM personagem INNER JOIN personagem_poder ON personagem_poder.personagem = personagem.id
INNER JOIN poder ON personagem_poder.poder = poder.id 
INNER JOIN poder_elemento ON poder_elemento.poder = poder.id
INNER JOIN elemento ON poder_elemento.elemento = elemento.id
ORDER BY personagem.nome;


-- recupera a lista de itens que são armas e não armas e seus respecitvos elementos
SELECT item.nome, arma.tipo, tipo_item.nome, elemento.nome
FROM elemento INNER JOIN arma ON arma.elemento = elemento.id
RIGHT JOIN item ON item.id = arma.item
INNER JOIN tipo_item ON tipo_item.id = item.tipo_item;


-- recupera a lista de intes referentes aos personagens do RPG e suas respectivas raças
SELECT personagem.nome, raca.nome
FROM personagem_raca INNER JOIN personagem ON personagem_raca.personagem = personagem.id
INNER JOIN raca ON personagem_raca.raca = raca.id;

-- recupera a lista de itens referentes a data e horário das partidas do RPG de Mesa
SELECT id AS Partida, data_game, hora FROM data_jogo;