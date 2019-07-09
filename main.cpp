#include <Basic.h>
#include <ScreenManager.h>
#include <TileMap.h>

int main()
{
    GD::createGD();
    ScreenManager sm;

    while (GD::window.isOpen())
    {
        sm.update();
        while (GD::window.pollEvent(GD::event))
        {
            if(GD::event.type == Event::Closed)
                    GD::window.close();
        }

        GD::window.clear(Color(6,85,53));
        GD::window.draw(sm);
        GD::window.display();
    }
    return 0;
}
