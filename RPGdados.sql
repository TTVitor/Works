use rpg;

INSERT INTO tipo_sangue VALUES
(1, 'A+'),
(2, 'A-'),
(3, 'B+'),
(4, 'B-'),
(5, 'AB+'),
(6, 'AB-'),
(7, 'O+'),
(8, 'O-');

INSERT INTO tipo_localidade VALUES
(1, "Pântano"),
(2, "Ilha"),
(3, "Floresta"),
(4, "Reino"),
(5, "Submundo"),
(6, "Céu");

INSERT INTO indole VALUES
(1, 'BEM'),
(2, 'MAL'),
(3, 'OUT');

INSERT INTO elemento VALUES
(1, "FOGO", "DESTRUTIVO", 'S', 2),
(2, "ÁGUA", "PACÍFICO", 'S', 1),
(3, "TREVAS", "DESCOMUNAL", 'N', 3),
(4, "LUZ", "SINGELO", 'N', 1),
(5, "VENTO", "AGRESSIVO", 'S', 3),
(6, "TERRA", "PRIMORDIAL", 'S', 2);

INSERT INTO dominio VALUES
(1, "GUERRA"),
(2, "CONHECIMENTO"),
(3, "MORTE"),
(4, "VIDA"),
(5, "ENGANAÇÃO"),
(6, "NATUREZA");

INSERT INTO religiao VALUES
(1, "JAPAWEST", "ANIMISMO", "Cultuar", "Escrever a Forças da Natureza", 3),
(2, "VALNORTH", "DUALISMO", "Festejar", "Sacrifício de Animais", 5),
(3, "CHINGOTH", "MONOTEÍSMO", "Matar", "Beber Sangue", 1),
(4, "MALRUST", "POLITEÍSMO", "Orar", "Disserminar a palavra", 6);

INSERT INTO origem VALUES
(1, "Divindades Maiores"),
(2, "Divindades Menores"),
(3, "Quase Divindades"),
(4, "Semideuses"),
(5, "Titãs"),
(6, "Vestígios");

INSERT INTO deus VALUES
(1, "AMATERASU", "Deusa do Sol", "Katana com Sol", 2, 1, 1, 2),
(2, "VIEGO", "Rei-Deus", "Espada com 3 Pontas", 3, 3, NULL, 1),
(3, "KORD", "Deus da Força", "Espada com Relâmpago cruzando a mão", 6, 1, NULL, NULL),
(4, "FREYA", "Rainha das Valquírias", "Asas Brilhantes", 4, 3, 2, 3);

INSERT INTO cidade VALUES
(1, "Valhalla", "Meritocracia", "Tropical", "Quente", 6, 2),
(2, "Tokusatsu", "Ditadura", "Árido", "Quente", 4, 1),
(3, "Ilhas das Sombras", "Confederação", "Chuvosos", "Frio", 2, NULL);

INSERT INTO arquetipo VALUES
(1, "Arqueiro"),
(2, "Paladino"),
(3, "Guerreiro"),
(4, "Mago"),
(5, "Curandeiro"),
(6, "Necromancer");

INSERT INTO personagem VALUES
(1, "TTVitor", 22, 'M', 1, 2, 6),
(2, "Havirium", 20, 'M', 3, 3, 4),
(3, "Lars", 18, 'F', 8, NULL, 3),
(4, "Kat", 33, 'F', 6, 1, 5);

INSERT INTO poder VALUES
(1, "LIGHTINING SHOT", "LONGA", 3),
(2, "SPIN OF DEAD", "CURTA", 2),
(3, "PUNCH OF FIRE", "MÉDIA", 1),
(4, "HAND OF GOD", "MÉDIA", 3);

INSERT INTO poder_elemento VALUES
(1, 4, 4),
(4, 3, 10),
(3, 1, 2),
(2, 6, 12);

INSERT INTO personagem_poder VALUES
(1, 4),
(1, 1),
(2, 2),
(2, 3),
(3, 1),
(3, 4),
(4, 1),
(4, 2),
(4, 3),
(4, 4);

INSERT INTO raca VALUES
(1, "Elfo", "Orelha pontuda", 1),
(2, "Troll", "Dentes afiados", 2),
(3, "Furry", "Pelos de animais", 3),
(4, "Anão", "Altura muito baixa", 1);

INSERT INTO personagem_raca VALUES
(1, 3, 2),
(2, 2, 1),
(3, 1, 1),
(4, 4, 2);

INSERT INTO raridade VALUES
(1, "COMUM"),
(2, "INCOMUM"),
(3, "RARO"),
(4, "MEGARARO"),
(5, "LENDÁRIO");

INSERT INTO tipo_item VALUES
(1, "Poção"),
(2, "Armadura"),
(3, "Arma"),
(4, "Artefato");

INSERT INTO item VALUES
(1, "Poção de Cura", 1, 1, FALSE),
(2, "Armadura de Espinhos", 2, 4, TRUE),
(3, "Excalibur", 3, 5, FALSE),
(4, "Olho de Tandera", 4, 2, NULL),
(5, "Foice do Exílio", 3, 5, NULL),
(6, "Arco dos Monte Uivantes", 3, 5, TRUE);

INSERT INTO arma VALUES
(3, 4, 100, "TREVAS", "BRANCA", "CURTO"),
(5, 3, 80, "LUZ", "BRANCA", "MÉDIO"),
(6, 5, 300, "TERRA", "LONGO ALCANCE", "LONGO");

INSERT INTO personagem_item VALUES
(1, 5, 1),
(1, 3, 1),
(2, 6, 1),
(3, 1, 6),
(3, 2, 1),
(3, 3, 1),
(3, 4, 2),
(4, 1, 10),
(4, 2, 1),
(4, 6, 1);

INSERT INTO data_jogo VALUES
(1, "Casa", "SHVP, Rua 5, Residencial Athenas", "2021-10-18", "18:00:00"),
(2, "Apartamento", "SHAG, Q.208, Residencial ALL", "2021-12-28", "20:30:00"),
(3, "Online", "Discord, CLUBE DO ANIME", "2021-11-10", "22:00:00"),
(4, "Externo", "SHAG, Rua 25 Sul, Park Style Mall And Residence", "2021-12-06", "16:20:00");
