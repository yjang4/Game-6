#ifndef GLOBALDATA_H
#define GLOBALDATA_H

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stack>
using namespace std;
using namespace sf;

class GD
{
    public:
        GD();
        static void createGD();
        static void setMusic(string filename);

        static map<string, float> gm;
        static Font font;
        static RenderWindow window;
        static Event event;

        static Music music;
        static map<string, Sound> sm;

        //static vector<Vector2f> tilePosVec;
        static map<string, vector<Vector2f>> tm;//contains tile positions
        static void showGM();

    private:
        static void loadAllSounds();
        static void loadSound(string filename, string index);

        static stack<SoundBuffer> bufferStack;
};

#endif
