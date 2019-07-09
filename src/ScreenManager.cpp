#include "ScreenManager.h"

ScreenManager::ScreenManager()
{
    GD::gm["stage"] = 1;
}
void ScreenManager::draw(RenderTarget& target, RenderStates states) const
{
    switch((int)GD::gm["stage"])
    {
        case 0:
            target.draw(mainScreen, states);
            break;
        case 1:
            target.draw(playScreen, states);
            break;

        default:
            break;
    }
}
void ScreenManager::update()
{
    switch((int)GD::gm["stage"])
    {
        case 0:
            mainScreen.update();
            break;
        case 1:
            playScreen.update();
            break;

        default:
            break;
    }


}

