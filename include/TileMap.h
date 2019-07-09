#ifndef TILEMAP_H
#define TILEMAP_H

#include <Basic.h>
class TileMap : public Drawable, public Transformable
{
    public:
        bool load(const std::string& tileset, Vector2u tileSize, const vector<int> &tiles,
                  unsigned int width, unsigned int height, string mapType);

    private:
        virtual void draw(RenderTarget& target, RenderStates states) const;

        VertexArray m_vertices;
        Texture m_tileset;
};
#endif // TILEMAP_H
