#define WIN_X (256)
#define WIN_Y (240)

enum COURCE
{
    START,
    WORLD,
};
int Scene = COURCE::START;

#include <DxLib.h>
#include "Picture.h"
#include "Sub.h"
#include "Title.h"

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR IpCmdLine,
    _In_ int nShowCmd)
{
    ChangeWindowMode(TRUE);
    DxLib_Init();

    /*Windowèâä˙âª*/
    SetWindowText("DRAGON QUEST");
    SetGraphMode(WIN_X, WIN_Y, 32);
    SetBackgroundColor(255, 255, 255);
    SetDrawScreen(DX_SCREEN_BACK);
    SetWindowSize(1024, 960);

    Picture.Load();
    Color.Load();
    Font.Load();

    while (ScreenFlip() == 0 &&
        ClearDrawScreen &&
        ProcessMessage() == 0 &&
        GetKey() == 0 &&
        Key[KEY_INPUT_ESCAPE] == 0
        )
    {
        switch (Scene)
        {
        case COURCE::START:
            Title.Draw();
            break;
        case COURCE::WORLD:

            break;
        };
    }

    DxLib_End();
    return 0;
}