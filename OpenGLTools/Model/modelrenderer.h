#ifndef MODELRENDERER_H
#define MODELRENDERER_H

#include "modelimporter.h"

/* Cette classe permet de dessiner un modèle texturé à l'écran
	Elle contient 3 tableaux qui font tout trois la taille correspondant au nombre de Mesh total
	Les trois tableaux sont donc relatif à un mesh en particulier, on y trouvera
		Le VAO
		Le VBO / IBO */
class ModelRenderer
{
public:
    ModelRenderer(std::string const &path, TextureRepository &textureRepository);

    void draw(bool takeCareAboutMaterials, GLint colorLocation = 0, GLint useTextureLocation = 0);

    ~ModelRenderer();

private:
    ModelImporter mModelImporter;
    std::vector<GLuint> mVaos;
    std::vector<GLuint> mVbos;
    std::vector<GLuint> mIbos;

	/* Configure le VBO, l'IBO, et le VAO */
    void configureVbo();
    void configureIbo();
    void configureVao();
};

#endif // MODELRENDERER_H
