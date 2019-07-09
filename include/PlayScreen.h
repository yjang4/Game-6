#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include <Basic.h>
#include <Button.h>
#include <Player.h>
#include <fstream>
#include <string>
#include <sstream>
#include <TileMap.h>

class PlayScreen : public Drawable
{
    public:
        PlayScreen();
        virtual void draw(RenderTarget& target, RenderStates states) const;
        void update();
        void loadMap(string filename);
    private:
        string getMapType(string filename);
        Player player;
        vector<TileMap> mapVec;
};

#endif // PLAYSCREEN_H
