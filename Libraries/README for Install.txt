Allez dans le dossier de microsoft visual studio puis allez dans VC.

Dans ce dossier vous avez les dossiers lib et include.

Copiez les dossiers lib et include d�j� pr�par� dans ceux de visual studio. (Le dossier bin sera � mettre avec vos executables).

Configuration de visual studio.

Utilisez les libs suivantes
SDL2.lib;SDL2main.lib;SDL2_image.lib;glew32.lib;opengl32.lib;assimp-vc120-mt.lib;

Donnez comme point d'entr�e une fen�tre
Propri�t� -> Editeur de lien -> Systeme -> Sous Systeme -> Windows

0 OpenGL est un projet d�j� configur�