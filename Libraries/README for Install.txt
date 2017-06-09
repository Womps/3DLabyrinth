Allez dans le dossier de microsoft visual studio puis allez dans VC.

Dans ce dossier vous avez les dossiers lib et include.

Copiez les dossiers lib et include déjà préparé dans ceux de visual studio. (Le dossier bin sera à mettre avec vos executables).

Configuration de visual studio.

Utilisez les libs suivantes
SDL2.lib;SDL2main.lib;SDL2_image.lib;glew32.lib;opengl32.lib;assimp-vc120-mt.lib;

Donnez comme point d'entrée une fenêtre
Propriété -> Editeur de lien -> Systeme -> Sous Systeme -> Windows

0 OpenGL est un projet déjà configuré