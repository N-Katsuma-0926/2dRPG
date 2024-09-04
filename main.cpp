
enum COURCE
{
    START,
    SOILMAP,
    GLASSMAP,
    
};
int Scene = COURCE::START;

#include <DxLib.h>




#include "Picture.h"
#include "Sub.h"
#include "Title.h"
//#include "player.h"
#include "GlassStage.h"
#include "SoilStage.h"
#include "HeroCat.h"


#define WINDOW_SIZE_WID 960
#define WINDOW_SIZE_HIG 640




int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR IpCmdLine,
    _In_ int nShowCmd)
{
    ChangeWindowMode(TRUE);
    DxLib_Init();

    /*Windowèâä˙âª*/
    SetWindowText("2d RPG");
    SetGraphMode(WINDOW_SIZE_WID, WINDOW_SIZE_HIG, 32);
    SetBackgroundColor(255, 255, 255);
    SetDrawScreen(DX_SCREEN_BACK);
    
    if (CatSysInitProc() == false)return false;
    Picture.Load();
    Color.Load();
    Font.Load();
    GlassStage.Read();
    SoilStage.Read();
    
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
            CatFlg = false;
            break;
        case COURCE::SOILMAP:
            SoilStage.Draw();
            CatDraw();
            break;
        case COURCE::GLASSMAP:
            GlassStage.Draw();
            break;
        
        };
    }

    DxLib_End();
    return 0;
}