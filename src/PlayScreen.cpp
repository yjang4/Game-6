#include "PlayScreen.h"

PlayScreen::PlayScreen()
{
    string filename = "map1/";
    loadMap(filename + "ground.txt");
    loadMap(filename + "ladder.txt");
}
void PlayScreen::draw(RenderTarget& target, RenderStates states) const
{
    vector<TileMap>::const_iterator it;
    for(it = mapVec.begin(); it < mapVec.end(); it ++)
    {
        target.draw(*it, states);

    }

    target.draw(player, states);

}
void PlayScreen::update()
{
    player.update();

}
void PlayScreen::loadMap(string filename)
{
    string finalFileName = "maps/" + filename;
    string textureFileName;
    int offset, c, r;
    vector<int> mapDataVec;
    string mapType = getMapType(filename);

    ifstream infile(finalFileName);
    if(infile.is_open())
    {
        string line;
        getline(infile, line);
        textureFileName = line;
        getline(infile, line);
        offset = stoi(line);
        int it2 = 0;
        while(getline(infile, line))
        {
            stringstream ss(line);
            int n;
            int it = 0;
            while(ss >> n)
            {
                mapDataVec.push_back(n);
                it ++;
            }
            c = it;
            it2 ++;
        }
        r = it2;
        infile.close();
    }
    TileMap map;
    map.load(textureFileName, Vector2u(offset, offset), mapDataVec, c, r, mapType);
    mapVec.push_back(map);
}
string PlayScreen::getMapType(string filename)
{
    string mapTypeTemp = "";
    int tempN = filename.size();
    for(int i = tempN - 1 - 4; i > 0; i --)
    {
        if(filename[i] == '/')
            break;
        mapTypeTemp += filename[i];
    }
    reverse(mapTypeTemp.begin(), mapTypeTemp.end());
    return mapTypeTemp;
}
