#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <MainScreen.h>
#include <PlayScreen.h>


class ScreenManager : public Drawable
{
    public:
        ScreenManager();
        virtual void draw(RenderTarget& target, RenderStates states) const;
        void update();

    private:

        MainScreen mainScreen;
        PlayScreen playScreen;
};

#endif // SCREENMANAGER_H
