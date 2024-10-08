#include <DxLib.h>




#include "Picture.h"
#include "Sub.h"
#include "Title.h"
#include "GlassStage.h"
#include "SoilStage.h"
#include "HeroCat.h"
#include "BossRat.h"
#include "NPC.h"
#include "BattleStage.h"
#include "Scene.h"
#include "ENDScene.h"




#define WINDOW_SIZE_WID 960
#define WINDOW_SIZE_HIG 640


int Scene;

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR IpCmdLine,
    _In_ int nShowCmd)
{
    ChangeWindowMode(TRUE);
    DxLib_Init();

    /*Window初期化*/
    SetWindowText("2d RPG");
    SetGraphMode(WINDOW_SIZE_WID, WINDOW_SIZE_HIG, 32);
    SetBackgroundColor(255, 255, 255);
    SetDrawScreen(DX_SCREEN_BACK);
    
    Scene = COURCE::START;
    //関数を呼び込む

    
    Picture.Load();
    Color.Load();
    Font.Load();
    GlassStage.Read();
    SoilStage.Read();
    //猫ちゃん
    CatSysInitProc();
    CatInitProc();
    CatMoveProc();
    //ねずみ
    RatInitProc();
    RatSysInitProc();
    //NPC
    HumanSysInitProc();
    HumanInitProc();
    //バトルシーン
    B_RatSysInitProc();
    B_RatInitProc();
    B_RatUpdateProc(); 

    //終了画面
    EndSysInit();
    EndUpdate();
    
    
    
    

   
   
    




    //ループを回す
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
            Title.TitleInit();
            Title.Draw();
            break;


        case COURCE::SOILMAP:
            SoilStage.Draw();
            CatDraw();
            CatMoveProc();
            RatDraw();
            HumanDraw();
            HumanUpdateProc();
           

            break;

        case COURCE::BATTLE:
            B_RatDraw();
            B_RatView();
            B_RatUpdateProc();

            break;




        case COURCE::GLASSMAP:
            GlassStage.Draw();
            CatDraw();
            CatMoveProc();
            RatDraw();
            HumanDraw2();
            HumanUpdateProc();
            

            
            break;


        case COURCE::END:
           
            EndDraw();
            break;

        };
    }

    DxLib_End();
    return 0;
}