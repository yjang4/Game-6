#include "GlobalData.h"

RenderWindow GD::window;
Font GD::font;
Event GD::event;
stack<SoundBuffer> GD::bufferStack;
map<string, Sound> GD::sm;
Music GD::music;
map<string, float> GD::gm;
map<string, vector<Vector2f>> GD::tm;

void GD::createGD()
{
    font.loadFromFile("arial.ttf");
    gm["screenX"] = 1000;
    gm["screenY"] = 800;
    gm["offset"] = 32;
    window.create(VideoMode(gm["screenX"], gm["screenY"]), "Game");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    setMusic("music/caketown.ogg");
    loadAllSounds();


}
GD::GD()
{
    cout << "WARNING: CREATING GD OBJECT" << endl;
}
void GD::loadSound(string filename, string index)
{
    SoundBuffer buffer;
    buffer.loadFromFile(filename);
    bufferStack.push(buffer);
    Sound sound;
    sound.setBuffer(bufferStack.top());
    sm[index] = sound;
}
void GD::loadAllSounds()
{
    loadSound("sound/select.wav", "select");
    loadSound("sound/touch.wav", "touch");
}
void GD::setMusic(string filename)
{
    music.openFromFile(filename);
    music.play();
}
void GD::showGM()
{
    map<string, float>::iterator it;
    for(it = gm.begin(); it != gm.end(); it ++)
    {
        cout << it -> first << " " << it -> second << endl;
    }
}
