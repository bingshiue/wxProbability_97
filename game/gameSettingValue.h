/**
 * @file gameSettingValue.h
 * @brief Declare game setting value.
 *
 */

#ifndef GAMESETTINGVALUE_H_
#define GAMESETTINGVALUE_H_

#include "../preprocessor/preprocessor.h"
#include "../probability/probabilityEnum.h"
#include "gameEnum.h"

#define word unsigned int/**< */
#define byte unsigned char/**< */

/************************ System Setting ***************************/
/**
 * Coin value.
 */
const word coin_value_tab[6] = { 1, 5, 10, 20, 50, 100 };
/**
 * Key In/Out.
 */
const word creditin_coin_tab[6] = { 10, 50, 100, 200, 500, 1000 };
/**
 * Max Bet.
 */
const word maxbet_tab[15] = { 8,16,24,32,40,48,64,80,160,240,320,400,480,640,800 };
/**
 * Minimal Bet.
 */
const byte minbet_tab[1] = { 1 };
/**
 * Hoper Max Pay.
 */
const word hpmaxpay_tab[6] = { 1000, 2000, 3000, 4000, 5000, Disable };
/**
 * Credit up limit.
 */
const word credituplimit_tab[7] = { 1000, 2000, 3000, 4000, 5000, 10000, Disable };
/**
 * Credit In Limit.
 */
const word creditinlimit_tab[10] = { 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000 };
/**
 * Double up game credit up limit.
 */
const word dduplimit_tab[10] = { 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000 };
/**
 * Double up game return kind.
 */
const byte ddkind_tab[2] = { DDownKind_Standard, DDownKind_Auto };
/**
 * Double up game kind.
 */
const byte ddtype_tab[4] = { DDown_None, DDown_OneTime, DDown_Half, DDown_Over100000 };
/**
 * Game level.
 */
const byte gamelevel_tab[3] = { Game_Level_Small, Game_Level_Mid, Game_Level_Big };
/**
 * Quick collect.
 */
const byte qc_tab[2] = { QuickCollect_OFF, QuickCollect_ON };
/**
 * Spin speed.
 */
const byte reel_speed_tab[3] = { Reel_Spin_Speed_Slow, Reel_Spin_Speed_Normal, Reel_Spin_Speed_Fast };
/**
 * Color of Frame.
 */
const byte frame_color_tab[6] = { Frame_Color_White, Frame_Color_Yellow, Frame_Color_Green, Frame_Color_Blue, Frame_Color_Purple, Frame_Color_Pink };
/**
 * Color of BackGround.
 */
const byte screen_color_tab[6] = { Screen_Color_Black, Screen_Color_Brown, Screen_Color_Green, Screen_Color_Light_Green, Screen_Color_Blue, Screen_Color_Purple };
/**
 * Key in/out function.
 */
const byte keyinout_func_tab[2] = { KeyInOut_Func_OFF, KeyInOut_Func_ON };
/**
 * Coin acceptor enable/disable.
 */
const byte coin_acceptor_tab[2] = { Disable,Enable };
/**
 * Bill acceptor enable/disable.
 */
const byte bill_acceptor_tab[2] = { Disable,Enable };
/**
 * Coin-In Limit.
 */
const word coin_in_limit_tab[7] = { 1000,2000,3000,4000,5000,10000,Disable };
/**
 * Key-In Limit.
 */
const word key_in_limit_tab[7]  = { 1000,2000,3000,4000,5000,10000,Disable };
/*
 * Bet Unit.
 */
const word bet_unit_tab[9] = { 1,2,4,8,10,20,40,80,100 };
/**
 * Hopper Setting.
 */
const byte hopper_setting_tab[2]= { hopper_NO,hopper_NC };

/********************** Probability Setting ************************/
/**
 * Main game probability.
 */
const float gamepro_tab[7] = { 96, 96.5, 97, 97.5, 98, 98.5, 99 };
/**
 * Double game probability.
 */
const float ddpro_tab[7] = { 96, 96.5, 97, 97.5, 98, 98.5, 99 };
/**
 * JP1 Default Value.
 */
const word jp1_default_tab[6] = { 1000, 2000, 3000, 5000, 8000, 10000 };
/**
 * JP2 Default Value.
 */
const word jp2_default_tab[6] = { 500, 1000, 2000, 3000, 4000, 5000 };
/**
 * JP3 Default Value.
 */
const word jp3_default_tab[6] = { 250, 500, 1000, 1500, 2000, 2500 };
/**
 * JP1 Max Value.
 */
const word jp1_maximum_tab[10] = { 3000, 5000, 6000, 8000, 10000, 12000, 15000,
		20000, 25000, 30000 };
/**
 * JP2 Max Value.
 */
const word jp2_maximum_tab[9] = { 2000, 3000, 4000, 5000, 6000, 7000, 8000,
		9000, 10000 };
/**
 * JP3 Max Value.
 */
const word jp3_maximum_tab[5] = { 1000, 2000, 3000, 4000, 5000 };

/************************* Bonus Setting  **************************/
/**
 * MainGame JokerOver4  On/Off Setting.
 */
const byte slot_5joker_tab[2] = { Bonu_Type_OFF, Bonu_Type_ON };
/**
 * MainGame Blue7Over6  On/Off Setting.
 */
const byte slot_blue7_tab[2] = { Bonu_Type_OFF, Bonu_Type_ON };
/**
 * MainGame Red7Over6   On/Off Setting.
 */
const byte slot_red7_tab[2] = { Bonu_Type_OFF, Bonu_Type_ON };
/**
 * MainGame Bar3Over6  On/Off Setting.
 */
const byte slot_bar7_tab[2] = { Bonu_Type_OFF, Bonu_Type_ON };
/**
 * Double Down Joker X3 On/Off Setting.
 */
const byte dd_3joker_tab[2] = { Bonu_Type_OFF, Bonu_Type_ON };
/**
 * Double Down 7 and Blue 7 X3(including Joker) On/Off Setting.
 */
const byte dd_blue7_tab[2] = { Bonu_Type_OFF, Bonu_Type_ON };

/************************ Connect Setting **************************/
/**
 * Link function on/off.
 */
const byte link_func_tab[2] = { Link_Function_OFF, Link_Function_ON };
/**
 * Link ID.
 */
const byte link_id_tab[20] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		16, 17, 18, 19, 20, 21 };
/**
 * Max link count.
 */
const byte max_id_tab[18] = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

/************************** Time Setting ***************************/
/**
 * hour.
 */
const byte hour_tab[24] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
		15, 16, 17, 18, 19, 20, 21, 22, 23 };
/**
 * minute.
 */
const byte minutes_tab[60] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
		14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
		32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
		50, 51, 52, 53, 54, 55, 56, 57, 58, 59 };
/**
 * week.
 */
const byte week_tab[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
/**
 * date.
 */
const byte date_tab[32] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
		15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 };
/**
 * month.
 */
const byte month_tab[13] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
/**
 * year.
 */
const byte year_tab[100] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
		15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
		33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
		51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68,
		69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86,
		87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99 };

#endif /* GAMESETTINGVALUE_H_ */
