/****************************************************************************************** 
 *  Chili DirectX Framework Version 12.04.24                                              * 
 *  Game.h                                                                                *
 *  Copyright 2012 PlanetChili.net                                                        *
 *                                                                                        *
 *  This file is part of The Chili DirectX Framework.                                     *
 *                                                                                        *
 *  The Chili DirectX Framework is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by                  *
 *  the Free Software Foundation, either version 3 of the License, or                     *
 *  (at your option) any later version.                                                   *
 *                                                                                        *
 *  The Chili DirectX Framework is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of                        *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         *
 *  GNU General Public License for more details.                                          *
 *                                                                                        *
 *  You should have received a copy of the GNU General Public License                     *
 *  along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "D3DGraphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Sound.h"
#include "Timer.h"

#define MAX_LASERS 100
#define MAX_ENEMIES 1
#define SCREENWIDTH 800
#define SCREENHEIGHT 600

class Game
{
public:
    Game( HWND hWnd,const KeyboardServer& kServer,const MouseServer& mServer );
    ~Game();
    void Go();
private:
    enum GAME_ITEM
    {
        LASER,
        ENEMY
    };

    enum RGB_COLOR
    {
        E_RED = 0,
        E_GREEN = 1,
        E_BLUE = 2
    };

    struct Global_Laser{
        int          level;
        const int    level1_speed = 250;
        const int    level2_speed = 375;
        const int    level3_speed = 600;
        char         multiple;
        unsigned int speed;
        int          width;
        int          height;
        int          count;
    };

    struct Global_Enemy{
        unsigned char level1_color[ 3 ] = { 158,156,114 };
        unsigned char level2_color[ 3 ] = { 0,255,255 };
        unsigned char level3_color[ 3 ] = { 86,188,84 };
        unsigned char level4_color[ 3 ] = { 79,87,193 };
        unsigned char color[ 3 ];
        const char    level1_hp = 3;
        const char    level2_hp = 10;
        const char    level3_hp = 20;
        const char    level4_hp = 50;
        const char    level5_hp = 100;
        const char    level6_hp = 200;
        int           level;
        int           count;
        int           wait_count;
        int           wait_time;
        int           width;
        int           height;
        int           speed;
    };
    
    struct Laser{
        float x[ MAX_LASERS ];
        int   y[ MAX_LASERS ];
    };

    struct Enemy
    {
        int           x;
        int           y;
        int           hp;
        unsigned char color[ 3 ];
    };

    struct MGame{
        int       score;
        const int score_x = 600;
        const int score_y = 566;
        bool      is_over;
        char      level;
        const int level1 = 0;
        const int level2 = 10;
        const int level3 = 20;
        const int level4 = 30;
        const int level5 = 40;
        const int level6 = 50;
        const int digit_width = 20;
        /*
            const int       score_number_widths[ 9 ] = {15,7,15,15,16,15,16,16,16,16}
            0_width = 15;
            0_height = 24;
            1_width = 7;
            1_height = 24;
            2_width = 15;
            2_height = 24;
            3_width = 15;
            3_height = 24;
            4_width = 16;
            4_height = 24;
            5_width = 15;
            5_height = 24;
            6_width = 16;
            6_height = 24;
            7_width = 16;
            7_height = 24;
            8_width = 16;
            8_height = 24;
            9_width = 16;
            9_height = 24;
        */
    };

    struct Ship{
        int          x;
        const int    y = 569;
        int          width;
        int          height;
        unsigned int speed;
    };

private:
    void ComposeFrame();
    /********************************/
    /*  User Functions              */

    void Draw_Score( int x,int y );
    void Draw_Digit( int digit, int x,int y );
    void Draw_Ship( int x,int y );
    void Draw_Laser( int x,int y );
    void Draw_Laser_Diagonal( float x,int y,char* direction );
    void Draw_Enemy(int x, int y,
        unsigned char red,
        unsigned char green,
        unsigned char blue);
    void Deploy_Enemy();

    void Update_Laser( float delta_time );
    void Update_Enemy( float delta_time );
    void Update_Keyboard_Input( float delta_time );
    void Update_Progression();
    void Null_Mem(int index, GAME_ITEM item);
    void Restart_Game();

    void Int_To_String( unsigned int num, char* chars, int buff_length );
    void Reverse_String( char* pChar );
    // void Set_PxPy();

    /********************************/
private:
    D3DGraphics gfx;
    KeyboardClient kbd;
    MouseClient mouse;
    DSound audio;
    /********************************/
    /*  User Variables              */
        
    Timer timer;
    // int px, py, radius;
    Global_Laser  global_laser;
    Global_Enemy  global_enemy;
    Laser         laser[ MAX_LASERS ];
    Enemy         enemy[ MAX_ENEMIES ];

    MGame game;

    Ship ship;

    bool      up_is_pressed;
    bool      enter_is_pressed;
    /********************************/
};