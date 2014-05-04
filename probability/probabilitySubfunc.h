/**
 * @file probabilitySubfunc.h
 * @brief probability subfunction.h
 *
 */

#ifndef PROBABILITYSUBFUNC_H_
#define PROBABILITYSUBFUNC_H_

#include "../preprocessor/preprocessor.h"
#include "../mersenne_twister/mt_random.h"
#include "probabilityDefine.h"
#include "probabilityType.h"

unsigned int MaingameProM[3][15][7] = {
#ifdef MAIN_PRO_VER_A
		                                   /***GL SMALL ***/
										   {{64, 2,10,21,2,1,0},// 82%
											{56, 6,20,15,2,1,0},// 84%
											{64,10,10,10,6,1,0},// 86%
											{59, 0,19,19,2,0,1},// 88%
											{60, 4,20,10,2,3,1},// 90%
											{58, 8, 8,18,4,3,0},// 92%
											{67, 5,10,10,4,3,1},// 94%
											{47, 8,19,23,0,2,1},// 96%
											{67, 1, 9,14,3,2,2},// 98%
											{57,15,10,10,4,3,1},//100%
											{63, 9,10,10,3,3,2},//102%
											{48, 5,14,24,5,3,1},//104%
											{45, 7,22,14,6,5,1},//106%
											{60, 7,10,13,4,4,2},//108%
											{46, 9,18,18,2,5,2} //110%
										    },

										    /***GL MID ***/
										   {{70, 0,15,15,0,0,0},// 70%
											{77,15, 4, 2,1,1,0},// 75%
											{65, 1,14,16,2,2,0},// 80%
											{54, 8,18,18,1,1,0},// 85%
											{60, 4,20,10,2,3,1},// 90%
											{65, 8, 8, 8,7,4,1},// 92%
											{57, 0,11,26,3,2,1},// 94%
											{73, 7, 6, 7,3,2,2},// 96%
											{54, 7,14,20,0,3,2},// 98%
											{60,13, 8, 8,8,2,1},//100%
											{51, 6,14,18,3,6,2},//103%
											{65, 8,12, 8,2,2,3},//107%
											{54, 9,12,16,3,4,2},//110%
											{48,16,15,10,5,4,2},//115%
											{42,11,18,18,3,4,4} //125%
										    },

										    /***GL BIG ***/
										   {{73, 0,13,13,1,0,0},// 70%
											{80,13, 3, 2,1,1,0},// 72%
											{70, 0,10,19,1,0,0},// 74%
											{64, 2,18,15,0,1,0},// 76%
											{71,14, 7, 6,2,0,0},// 78%
											{70,10, 9, 8,2,1,0},// 80%
											{65, 4,15,14,0,1,1},// 85%
											{55, 5,19,19,1,0,1},// 90%
											{64, 8,13, 8,4,2,1},// 95%
											{50, 6,26,14,0,1,3},//100%
											{62, 8, 8,12,4,4,2},//106%
											{45, 5,18,20,5,5,2},//114%
											{54, 9, 9,13,6,6,3},//123%
											{49, 2,15,21,4,4,5},//133%
											{34, 9,19,19,6,9,4} //144%
										    }
#else
#ifdef MAIN_PRO_VER_B
			                                   /***GL SMALL ***/
											   {{64,13,10,13,0,0,0},// 82%
												{60,14,13,13,0,0,0},// 84%
												{59,15,17, 8,1,0,0},// 86%
												{56,16,17,10,0,1,0},// 88%
												{73, 0,10,10,5,0,2},// 90%
												{60,13,14,11,0,1,1},// 92%
												{56,12,12,15,4,1,0},// 94%
												{63, 5,12, 3,3,5,2},// 96%
												{58,10,10,17,2,2,1},// 98%
												{60,13, 0,10,7,6,1},//100%
												{55,11,14,12,4,3,1},//102%
												{52,10,24, 2,7,4,1},//104%
												{45,16,19, 9,6,4,1},//106%
												{47,13,14,15,5,5,1},//108%
												{50,14,14,10,5,5,2} //110%
											    },

											    /***GL MID ***/
											   {{76, 0,12,12,0,0,0},// 70%
												{68,20, 8, 3,1,0,0},// 75%
												{66,15, 7,10,1,1,0},// 80%
												{59,11,16,13,0,1,0},// 85%
												{73, 0,10,10,5,0,2},// 90%
												{60,13,15, 0,7,5,0},// 92%
												{66,10, 0,18,3,2,1},// 94%
												{63, 5,12, 3,3,3,2},// 96%
												{65, 0,15, 9,5,5,1},// 98%
												{60,13, 0,10,7,6,1},//100%
												{58,10,12, 7,6,6,1},//103%
												{57, 5,13,14,5,4,2},//107%
												{52, 8, 8,15,8,8,1},//110%
												{50,10, 8,16,9,5,2},//115%
												{45,11,11,13,9,9,2} //125%
											    },

											    /***GL BIG ***/
											   {{76, 8,10, 8,0,0,0},// 72%
												{68,20, 8, 3,1,0,0},// 75%
												{70,13, 8, 8,0,1,0},// 78%
												{64,14,10,10,1,1,0},// 81%
												{74, 8, 0,15,1,1,1},// 84%
												{64,10,10,12,2,2,0},// 87%
												{73, 0,10,10,5,0,2},// 90%
												{66, 8, 8, 9,4,4,1},// 93%
												{63, 5,12, 3,3,5,2},// 96%
												{63, 6, 6,15,4,5,1},//100%
												{55, 0,14,15,1,5,2},//105%
												{52,10, 9,14,8,6,1},//110%
												{45,12,16,10,9,7,1},//115%
												{47,10,11,16,8,6,2},//122%
												{39,11,16,16,8,7,3} //132%
											    }
#endif
#endif
                                                                                                                             };/**< Main game probability mapping table */

unsigned int MaingameProDownM[5][7] = {
#ifdef MAIN_PRO_VER_A
											{73, 0,13,13, 1, 0, 0},//72%
											{72, 2,10,15, 1, 0, 0},//74%
											{67, 2,18,12, 0, 1, 0},//76%
											{65, 9,12,12, 1, 1, 0},//78%
											{71, 9, 9, 9, 0, 1, 1},//80%
#else
#ifdef MAIN_PRO_VER_B
											{68,25, 6, 1, 0, 0, 0},//76%
											{67,17,15, 0, 1, 0, 0},//79%
											{67,16,12, 4, 0, 1, 0},//82%
											{66,12,10,10, 1, 1, 0},//85%
											{68,10,10,10, 0, 1, 1},//88%
#endif
#endif
};/**< Main game pull down probability mapping table */

unsigned int MaingameProUpM[5][7]  = {
#ifdef MAIN_PRO_VER_A
											{45, 7,22,14, 6, 5, 1},//105%
											{46, 9,18,18, 2, 5, 2},//110%
											{48,11,15,15, 5, 4, 2},//115%
											{55, 9,10,12, 6, 5, 3},//120%
											{42,11,18,18, 3, 4, 4},//125%
#else
#ifdef MAIN_PRO_VER_B
											{55,10,10,12, 6, 6, 1},//105%
											{48,12,11,15, 7, 6, 1},//110%
											{48,10,15,10, 8, 8, 1},//115%
											{44,12,14,15, 7, 6, 2},//120%
											{48,11,11,10, 9, 9, 2},//125%
#endif
#endif
};/**< Main game pull up probability mapping table */

unsigned int LinkMaingameProM[3][5][15] = {
		                                        //GL SMALL
												{
													{//94%
													  gl_s_pro_90_82, gl_s_pro_90_84, gl_s_pro_90_86, gl_s_pro_90_88, gl_s_pro_90_90,
													  gl_s_pro_90_92, gl_s_pro_90_94, gl_s_pro_90_96, gl_s_pro_90_98, gl_s_pro_90_100,
													  gl_s_pro_90_102,gl_s_pro_90_104,gl_s_pro_90_106,gl_s_pro_90_108,gl_s_pro_90_110
													},
													{//95%
													  gl_s_pro_91_82, gl_s_pro_91_84, gl_s_pro_91_86, gl_s_pro_91_88, gl_s_pro_91_90,
													  gl_s_pro_91_92, gl_s_pro_91_94, gl_s_pro_91_96, gl_s_pro_91_98, gl_s_pro_91_100,
													  gl_s_pro_91_102,gl_s_pro_91_104,gl_s_pro_91_106,gl_s_pro_91_108,gl_s_pro_91_110
													},
													{//96%
													  gl_s_pro_92_82, gl_s_pro_92_84, gl_s_pro_92_86, gl_s_pro_92_88, gl_s_pro_92_90,
													  gl_s_pro_92_92, gl_s_pro_92_94, gl_s_pro_92_96, gl_s_pro_92_98, gl_s_pro_92_100,
													  gl_s_pro_92_102,gl_s_pro_92_104,gl_s_pro_92_106,gl_s_pro_92_108,gl_s_pro_92_110
													},
													{//97%
													  gl_s_pro_93_82, gl_s_pro_93_84, gl_s_pro_93_86, gl_s_pro_93_88, gl_s_pro_93_90,
													  gl_s_pro_93_92, gl_s_pro_93_94, gl_s_pro_93_96, gl_s_pro_93_98, gl_s_pro_93_100,
													  gl_s_pro_93_102,gl_s_pro_93_104,gl_s_pro_93_106,gl_s_pro_93_108,gl_s_pro_93_110
													},
													{//98%
													  gl_s_pro_94_82, gl_s_pro_94_84, gl_s_pro_94_86, gl_s_pro_94_88, gl_s_pro_94_90,
													  gl_s_pro_94_92, gl_s_pro_94_94, gl_s_pro_94_96, gl_s_pro_94_98, gl_s_pro_94_100,
													  gl_s_pro_94_102,gl_s_pro_94_104,gl_s_pro_94_106,gl_s_pro_94_108,gl_s_pro_94_110
													}
												},
												//GL MID
												{
													{//94%
														gl_m_pro_90_70, gl_m_pro_90_75, gl_m_pro_90_80, gl_m_pro_90_85, gl_m_pro_90_90,
														gl_m_pro_90_92, gl_m_pro_90_94, gl_m_pro_90_96, gl_m_pro_90_98, gl_m_pro_90_100,
														gl_m_pro_90_103,gl_m_pro_90_107,gl_m_pro_90_110,gl_m_pro_90_115,gl_m_pro_90_125
													},
													{//95%
														gl_m_pro_91_70, gl_m_pro_91_75, gl_m_pro_91_80, gl_m_pro_91_85, gl_m_pro_91_90,
														gl_m_pro_91_92, gl_m_pro_91_94, gl_m_pro_91_96, gl_m_pro_91_98, gl_m_pro_91_100,
														gl_m_pro_91_103,gl_m_pro_91_107,gl_m_pro_91_110,gl_m_pro_91_115,gl_m_pro_91_125
													},
													{//96%
														gl_m_pro_92_70, gl_m_pro_92_75, gl_m_pro_92_80, gl_m_pro_92_85, gl_m_pro_92_90,
														gl_m_pro_92_92, gl_m_pro_92_94, gl_m_pro_92_96, gl_m_pro_92_98, gl_m_pro_92_100,
														gl_m_pro_92_103,gl_m_pro_92_107,gl_m_pro_92_110,gl_m_pro_92_115,gl_m_pro_92_125
													},
													{//97%
														gl_m_pro_93_70, gl_m_pro_93_75, gl_m_pro_93_80, gl_m_pro_93_85, gl_m_pro_93_90,
														gl_m_pro_93_92, gl_m_pro_93_94, gl_m_pro_93_96, gl_m_pro_93_98, gl_m_pro_93_100,
														gl_m_pro_93_103,gl_m_pro_93_107,gl_m_pro_93_110,gl_m_pro_93_115,gl_m_pro_93_125
													},
													{//98%
														gl_m_pro_94_70, gl_m_pro_94_75, gl_m_pro_94_80, gl_m_pro_94_85, gl_m_pro_94_90,
														gl_m_pro_94_92, gl_m_pro_94_94, gl_m_pro_94_96, gl_m_pro_94_98, gl_m_pro_94_100,
														gl_m_pro_94_103,gl_m_pro_94_107,gl_m_pro_94_110,gl_m_pro_94_115,gl_m_pro_94_125
													}
												},
												//GL BIG
												{
													{//94%
														gl_b_pro_90_70, gl_b_pro_90_72, gl_b_pro_90_74, gl_b_pro_90_76, gl_b_pro_90_78,
														gl_b_pro_90_80, gl_b_pro_90_85, gl_b_pro_90_90, gl_b_pro_90_95, gl_b_pro_90_100,
														gl_b_pro_90_106,gl_b_pro_90_114,gl_b_pro_90_123,gl_b_pro_90_133,gl_b_pro_90_144
													},
													{//95%
														gl_b_pro_91_70, gl_b_pro_91_72, gl_b_pro_91_74, gl_b_pro_91_76, gl_b_pro_91_78,
														gl_b_pro_91_80, gl_b_pro_91_85, gl_b_pro_91_90, gl_b_pro_91_95, gl_b_pro_91_100,
														gl_b_pro_91_106,gl_b_pro_91_114,gl_b_pro_91_123,gl_b_pro_91_133,gl_b_pro_91_144
													},
													{//96%
														gl_b_pro_92_70, gl_b_pro_92_72, gl_b_pro_92_74, gl_b_pro_92_76, gl_b_pro_92_78,
														gl_b_pro_92_80, gl_b_pro_92_85, gl_b_pro_92_90, gl_b_pro_92_95, gl_b_pro_92_100,
														gl_b_pro_92_106,gl_b_pro_92_114,gl_b_pro_92_123,gl_b_pro_92_133,gl_b_pro_92_144
													},
													{//97%
														gl_b_pro_93_70, gl_b_pro_93_72, gl_b_pro_93_74, gl_b_pro_93_76, gl_b_pro_93_78,
														gl_b_pro_93_80, gl_b_pro_93_85, gl_b_pro_93_90, gl_b_pro_93_95, gl_b_pro_93_100,
														gl_b_pro_93_106,gl_b_pro_93_114,gl_b_pro_93_123,gl_b_pro_93_133,gl_b_pro_93_144
													},
													{//98%
														gl_b_pro_94_70, gl_b_pro_94_72, gl_b_pro_94_74, gl_b_pro_94_76, gl_b_pro_94_78,
														gl_b_pro_94_80, gl_b_pro_94_85, gl_b_pro_94_90, gl_b_pro_94_95, gl_b_pro_94_100,
														gl_b_pro_94_106,gl_b_pro_94_114,gl_b_pro_94_123,gl_b_pro_94_133,gl_b_pro_94_144
													}
												},
};/**< Main game probability mapping table(Linking) */


// Line award type odds mapping table
unsigned int  LineBingoTypeM[9] = { 0, 4, 10, 20, 40, 50, 100, 200, 1000 };/**< Line award odds mapping table */

// Line award type odds mapping table (97 type)
unsigned int  LineAwardTypeOddsMapping[13] = {
		// none
		0,
		// one cherry straight
		2,
		// two cherry straight
		5,
		// three cherry straight
		10,
		// orange straight
		10,
		// mix bar straight
		10,
		// mango straight
		14,
		// bell straight
		18,
		// watermelon straight
		20,
		// bar yellow straight
		30,
		// bar red straight
		50,
		// bar blue straight
		70,
		// seven straight
		//80,
		// wild straight
		100
};
//
unsigned long SideBingoTypeM[8][7] = {   //ANY3   //ANY4   //ANY5   //ANY6   //ANY7   //ANY8   //ANY9
		                                 {      0,       0,       0,       0,       0,       0,     26   },//Item Blank
		                                 {      0,       0,       0,       4,       8,      20,    100   },//Item Any Bar
		                                 {      0,       4,       8,      30,     200,    1000,   2000   },//Item One Bar
		                                 {      0,       6,      20,      80,     500,    2500,   5000   },//Item Two Bar
		                                 {      0,      10,      50,     200,    1000,    5000,  10000   },//Item Three Bar
		                                 {      4,      10,      50,     250,    2500,   12500,  25000   },//Item Any  7
		                                 {      8,      20,     100,     500,    5000,   25000,  50000   },//Item Red  7
		                                 {     12,      50,     250,    1000,   10000,   50000, 100000   },//Item Blue 7
                                                                                                                            };/**< Side item award odds mapping table */

unsigned long FullFrameAwardTypeMapping[11][10] = {
		                                 //0   //1   //2   //3   //4   //5   //6   //7   //8   //9
		                                {  0,    0,    0,    0,    0,    0,    0,    0,    0,    20 },//All fruit
		                                {  0,    0,    0,    0,    0,    0,    0,    0,    0,    50 },//All any bar
		                                {  0,    0,    0,    0,    0,    0,    0,    0,    0,    25 },//All orange
		                                {  0,    0,    0,    0,    0,    0,    0,    0,    0,    50 },//All mango
		                                {  0,    0,    0,    0,    0,    0,    0,    0,    0,    75 },//All bell
		                                {  0,    0,    0,    0,    0,    0,    0,    0,    0,   125 },//All watermelon
		                                {  0,    0,    0,    0,    0,    0,    0,    0,    0,   400 },//All bar yellow
		                                {  0,    0,    0,    0,    0,    0,    0,    0,    0,   800 },//All cherry
		                                {  0,    0,    0,    0,    0,    0,    0,    0,    0,  1000 },//All bar red
		                                {  0,    0,    0,    0,    0,    0,    0,    0,    0,  2500 },//All bar blue
		                                //{  0,    0,    2,    5,   20,   40,   60,   80,  100,   200 },//All seven
		                                {  0,    0,    0,  100,  200,  400,  800, 1000, 2000,  4000 },//All ???
																															};
//
unsigned int  DoUpM[6][2]   = {   //Do  //Don't
								{   90,   10},
								{   80,   20},
								{   70,   30},
								{   60,   40},
								{   50,   50},
								{  100,    0}
};/**< Pull up probability mapping table */
//
unsigned int  DoDownM[6][2] = {   //Do  //Don't
								{   90,   10},
								{   80,   20},
								{   70,   30},
								{   60,   40},
								{   50,   50},
								{  100,    0},
};/**< Pull down probability mapping table */

/**
 * @brief Frame probability type fixed 1.
 * @param mt Mersenne twister algorithm instance
 * @param pctrl Probability controller
 * @retval Item type
 * @author SHIE-BINGSHIUE
 * @date 2010-09-10
 */
int _FrameProTypeFixed_1(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    unsigned int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_fixed_random_Base);

    if(ram < SCROLL_1_PROBABILITY_STEP_1)
       return ITEM_CHERRY;
    else if(ram >=SCROLL_1_PROBABILITY_STEP_1 && ram <SCROLL_1_PROBABILITY_STEP_2)
       return ITEM_ORANGE;
    else if(ram >=SCROLL_1_PROBABILITY_STEP_2 && ram <SCROLL_1_PROBABILITY_STEP_3)
       return ITEM_MANGO;
    else if(ram >=SCROLL_1_PROBABILITY_STEP_3 && ram <SCROLL_1_PROBABILITY_STEP_4)
       return ITEM_BELL;
    else if(ram >=SCROLL_1_PROBABILITY_STEP_4 && ram <SCROLL_1_PROBABILITY_STEP_5)
       return ITEM_WATERMELON;
    else if(ram >=SCROLL_1_PROBABILITY_STEP_5 && ram <SCROLL_1_PROBABILITY_STEP_6)
       return ITEM_BAR_YELLOW;
    else if(ram >=SCROLL_1_PROBABILITY_STEP_6 && ram <SCROLL_1_PROBABILITY_STEP_7)
       return ITEM_BAR_RED;
    else if(ram >=SCROLL_1_PROBABILITY_STEP_7 && ram <SCROLL_1_PROBABILITY_STEP_8)
       return ITEM_BAR_BLUE;
    else if(ram >=SCROLL_1_PROBABILITY_STEP_8 && ram <SCROLL_1_PROBABILITY_STEP_9)
       return ITEM_WILD;

    //else if(ram >=SCROLL_1_PROBABILITY_STEP_8 && ram <SCROLL_1_PROBABILITY_STEP_9)
       //return ITEM_SEVEN;
    //else if(ram >=SCROLL_1_PROBABILITY_STEP_9 && ram <SCROLL_1_PROBABILITY_STEP_10)
       //return ITEM_WILD;

#if 0
    if(ram < _scoroll_1_pro_fixed_step1)
       return ran_Item_Blank;
    else if(ram >=_scoroll_1_pro_fixed_step1 && ram <_scoroll_1_pro_fixed_step2)
       return ran_Item_One_Bar;
    else if(ram >=_scoroll_1_pro_fixed_step2 && ram <_scoroll_1_pro_fixed_step3)
       return ran_Item_Two_Bar;
    else if(ram >=_scoroll_1_pro_fixed_step3 && ram <_scoroll_1_pro_fixed_step4)
       return ran_Item_Three_Bar;
    else if(ram >=_scoroll_1_pro_fixed_step4 && ram <_scoroll_1_pro_fixed_step5)
       return ran_Item_Red_7;
    else if(ram >=_scoroll_1_pro_fixed_step5 && ram <_scoroll_1_pro_fixed_step6)
       return ran_Item_Blue_7;
    else if(ram >=_scoroll_1_pro_fixed_step6 && ram <_scoroll_1_pro_fixed_step7)
       return ran_Item_Joker;
#endif

	return 0;
}
/**
 * @brief Frame probability type fixed 2.
 * @param mt Mersenne twister algorithm instance
 * @param pctrl Probability controller
 * @retval Item type
 * @author SHIE-BINGSHIUE
 * @date 2010-09-10
 */
int _FrameProTypeFixed_2(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    unsigned int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_fixed_random_Base);

    if(ram < SCROLL_2_PROBABILITY_STEP_1)
       return ITEM_CHERRY;
    else if(ram >=SCROLL_2_PROBABILITY_STEP_1 && ram <SCROLL_2_PROBABILITY_STEP_2)
       return ITEM_ORANGE;
    else if(ram >=SCROLL_2_PROBABILITY_STEP_2 && ram <SCROLL_2_PROBABILITY_STEP_3)
       return ITEM_MANGO;
    else if(ram >=SCROLL_2_PROBABILITY_STEP_3 && ram <SCROLL_2_PROBABILITY_STEP_4)
       return ITEM_BELL;
    else if(ram >=SCROLL_2_PROBABILITY_STEP_4 && ram <SCROLL_2_PROBABILITY_STEP_5)
       return ITEM_WATERMELON;
    else if(ram >=SCROLL_2_PROBABILITY_STEP_5 && ram <SCROLL_2_PROBABILITY_STEP_6)
       return ITEM_BAR_YELLOW;
    else if(ram >=SCROLL_2_PROBABILITY_STEP_6 && ram <SCROLL_2_PROBABILITY_STEP_7)
       return ITEM_BAR_RED;
    else if(ram >=SCROLL_2_PROBABILITY_STEP_7 && ram <SCROLL_2_PROBABILITY_STEP_8)
       return ITEM_BAR_BLUE;
    else if(ram >=SCROLL_2_PROBABILITY_STEP_8 && ram <SCROLL_2_PROBABILITY_STEP_9)
       return ITEM_WILD;

    //else if(ram >=SCROLL_2_PROBABILITY_STEP_8 && ram <SCROLL_2_PROBABILITY_STEP_9)
       //return ITEM_SEVEN;
    //else if(ram >=SCROLL_2_PROBABILITY_STEP_9 && ram <SCROLL_2_PROBABILITY_STEP_10)
       //return ITEM_WILD;

#if 0
    if(ram < _scoroll_2_pro_fixed_step1)
       return ran_Item_Blank;
    else if(ram >=_scoroll_2_pro_fixed_step1 && ram <_scoroll_2_pro_fixed_step2)
       return ran_Item_One_Bar;
    else if(ram >=_scoroll_2_pro_fixed_step2 && ram <_scoroll_2_pro_fixed_step3)
       return ran_Item_Two_Bar;
    else if(ram >=_scoroll_2_pro_fixed_step3 && ram <_scoroll_2_pro_fixed_step4)
       return ran_Item_Three_Bar;
    else if(ram >=_scoroll_2_pro_fixed_step4 && ram <_scoroll_2_pro_fixed_step5)
       return ran_Item_Red_7;
    else if(ram >=_scoroll_2_pro_fixed_step5 && ram <_scoroll_2_pro_fixed_step6)
       return ran_Item_Blue_7;
    else if(ram >=_scoroll_2_pro_fixed_step6 && ram <_scoroll_2_pro_fixed_step7)
       return ran_Item_Joker;
#endif

	return 0;
}
/**
 * @brief Frame probability type fixed 3.
 * @param mt Mersenne twister algorithm instance
 * @param pctrl Probability controller
 * @retval Item type
 * @author SHIE-BINGSHIUE
 * @date 2010-09-10
 */
int _FrameProTypeFixed_3(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    unsigned int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_fixed_random_Base);

    if(ram < SCROLL_3_PROBABILITY_STEP_1)
       return ITEM_CHERRY;
    else if(ram >=SCROLL_3_PROBABILITY_STEP_1 && ram <SCROLL_3_PROBABILITY_STEP_2)
       return ITEM_ORANGE;
    else if(ram >=SCROLL_3_PROBABILITY_STEP_2 && ram <SCROLL_3_PROBABILITY_STEP_3)
       return ITEM_MANGO;
    else if(ram >=SCROLL_3_PROBABILITY_STEP_3 && ram <SCROLL_3_PROBABILITY_STEP_4)
       return ITEM_BELL;
    else if(ram >=SCROLL_3_PROBABILITY_STEP_4 && ram <SCROLL_3_PROBABILITY_STEP_5)
       return ITEM_WATERMELON;
    else if(ram >=SCROLL_3_PROBABILITY_STEP_5 && ram <SCROLL_3_PROBABILITY_STEP_6)
       return ITEM_BAR_YELLOW;
    else if(ram >=SCROLL_3_PROBABILITY_STEP_6 && ram <SCROLL_3_PROBABILITY_STEP_7)
       return ITEM_BAR_RED;
    else if(ram >=SCROLL_3_PROBABILITY_STEP_7 && ram <SCROLL_3_PROBABILITY_STEP_8)
       return ITEM_BAR_BLUE;
    else if(ram >=SCROLL_3_PROBABILITY_STEP_8 && ram <SCROLL_3_PROBABILITY_STEP_9)
       return ITEM_WILD;

    //else if(ram >=SCROLL_3_PROBABILITY_STEP_8 && ram <SCROLL_3_PROBABILITY_STEP_9)
       //return ITEM_SEVEN;
    //else if(ram >=SCROLL_3_PROBABILITY_STEP_9 && ram <SCROLL_3_PROBABILITY_STEP_10)
       //return ITEM_WILD;

#if 0
    if(ram < _scoroll_3_pro_fixed_step1)
       return ran_Item_Blank;
    else if(ram >=_scoroll_3_pro_fixed_step1 && ram <_scoroll_3_pro_fixed_step2)
       return ran_Item_One_Bar;
    else if(ram >=_scoroll_3_pro_fixed_step2 && ram <_scoroll_3_pro_fixed_step3)
       return ran_Item_Two_Bar;
    else if(ram >=_scoroll_3_pro_fixed_step3 && ram <_scoroll_3_pro_fixed_step4)
       return ran_Item_Three_Bar;
    else if(ram >=_scoroll_3_pro_fixed_step4 && ram <_scoroll_3_pro_fixed_step5)
       return ran_Item_Red_7;
    else if(ram >=_scoroll_3_pro_fixed_step5 && ram <_scoroll_3_pro_fixed_step6)
       return ran_Item_Blue_7;
    else if(ram >=_scoroll_3_pro_fixed_step6 && ram <_scoroll_3_pro_fixed_step7)
       return ran_Item_Joker;
#endif

	return 0;
}
/**
 * @brief Frame probability type fixed 4.
 * @param mt Mersenne twister algorithm instance
 * @param pctrl Probability controller
 * @retval Item type
 * @author SHIE-BINGSHIUE
 * @date 2010-09-10
 */
int _FrameProTypeFixed_4(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    unsigned int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_fixed_random_Base);

    if(ram < SCROLL_4_PROBABILITY_STEP_1)
       return ITEM_CHERRY;
    else if(ram >=SCROLL_4_PROBABILITY_STEP_1 && ram <SCROLL_4_PROBABILITY_STEP_2)
       return ITEM_ORANGE;
    else if(ram >=SCROLL_4_PROBABILITY_STEP_2 && ram <SCROLL_4_PROBABILITY_STEP_3)
       return ITEM_MANGO;
    else if(ram >=SCROLL_4_PROBABILITY_STEP_3 && ram <SCROLL_4_PROBABILITY_STEP_4)
       return ITEM_BELL;
    else if(ram >=SCROLL_4_PROBABILITY_STEP_4 && ram <SCROLL_4_PROBABILITY_STEP_5)
       return ITEM_WATERMELON;
    else if(ram >=SCROLL_4_PROBABILITY_STEP_5 && ram <SCROLL_4_PROBABILITY_STEP_6)
       return ITEM_BAR_YELLOW;
    else if(ram >=SCROLL_4_PROBABILITY_STEP_6 && ram <SCROLL_4_PROBABILITY_STEP_7)
       return ITEM_BAR_RED;
    else if(ram >=SCROLL_4_PROBABILITY_STEP_7 && ram <SCROLL_4_PROBABILITY_STEP_8)
       return ITEM_BAR_BLUE;
    else if(ram >=SCROLL_4_PROBABILITY_STEP_8 && ram <SCROLL_4_PROBABILITY_STEP_9)
       return ITEM_WILD;


    //else if(ram >=SCROLL_4_PROBABILITY_STEP_8 && ram <SCROLL_4_PROBABILITY_STEP_9)
       //return ITEM_SEVEN;
    //else if(ram >=SCROLL_4_PROBABILITY_STEP_9 && ram <SCROLL_4_PROBABILITY_STEP_10)
       //return ITEM_WILD;

#if 0
    if(ram < _scoroll_4_pro_fixed_step1)
       return ran_Item_Blank;
    else if(ram >=_scoroll_4_pro_fixed_step1 && ram <_scoroll_4_pro_fixed_step2)
       return ran_Item_One_Bar;
    else if(ram >=_scoroll_4_pro_fixed_step2 && ram <_scoroll_4_pro_fixed_step3)
       return ran_Item_Two_Bar;
    else if(ram >=_scoroll_4_pro_fixed_step3 && ram <_scoroll_4_pro_fixed_step4)
       return ran_Item_Three_Bar;
    else if(ram >=_scoroll_4_pro_fixed_step4 && ram <_scoroll_4_pro_fixed_step5)
       return ran_Item_Red_7;
    else if(ram >=_scoroll_4_pro_fixed_step5 && ram <_scoroll_4_pro_fixed_step6)
       return ran_Item_Blue_7;
    else if(ram >=_scoroll_4_pro_fixed_step6 && ram <_scoroll_4_pro_fixed_step7)
       return ran_Item_Joker;
#endif

	return 0;
}
/**
 * @brief Frame probability type fixed 5.
 * @param mt Mersenne twister algorithm instance
 * @param pctrl Probability controller
 * @retval Item type
 * @author SHIE-BINGSHIUE
 * @date 2010-09-10
 */
int _FrameProTypeFixed_5(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    unsigned int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_fixed_random_Base);

    if(ram < SCROLL_5_PROBABILITY_STEP_1)
       return ITEM_CHERRY;
    else if(ram >=SCROLL_5_PROBABILITY_STEP_1 && ram <SCROLL_5_PROBABILITY_STEP_2)
       return ITEM_ORANGE;
    else if(ram >=SCROLL_5_PROBABILITY_STEP_2 && ram <SCROLL_5_PROBABILITY_STEP_3)
       return ITEM_MANGO;
    else if(ram >=SCROLL_5_PROBABILITY_STEP_3 && ram <SCROLL_5_PROBABILITY_STEP_4)
       return ITEM_BELL;
    else if(ram >=SCROLL_5_PROBABILITY_STEP_4 && ram <SCROLL_5_PROBABILITY_STEP_5)
       return ITEM_WATERMELON;
    else if(ram >=SCROLL_5_PROBABILITY_STEP_5 && ram <SCROLL_5_PROBABILITY_STEP_6)
       return ITEM_BAR_YELLOW;
    else if(ram >=SCROLL_5_PROBABILITY_STEP_6 && ram <SCROLL_5_PROBABILITY_STEP_7)
       return ITEM_BAR_RED;
    else if(ram >=SCROLL_5_PROBABILITY_STEP_7 && ram <SCROLL_5_PROBABILITY_STEP_8)
       return ITEM_BAR_BLUE;
    else if(ram >=SCROLL_5_PROBABILITY_STEP_8 && ram <SCROLL_5_PROBABILITY_STEP_9)
       return ITEM_WILD;

    //else if(ram >=SCROLL_5_PROBABILITY_STEP_8 && ram <SCROLL_5_PROBABILITY_STEP_9)
       //return ITEM_SEVEN;
    //else if(ram >=SCROLL_5_PROBABILITY_STEP_9 && ram <SCROLL_5_PROBABILITY_STEP_10)
       //return ITEM_WILD;

#if 0
    if(ram < _scoroll_5_pro_fixed_step1)
       return ran_Item_Blank;
    else if(ram >=_scoroll_5_pro_fixed_step1 && ram <_scoroll_5_pro_fixed_step2)
       return ran_Item_One_Bar;
    else if(ram >=_scoroll_5_pro_fixed_step2 && ram <_scoroll_5_pro_fixed_step3)
       return ran_Item_Two_Bar;
    else if(ram >=_scoroll_5_pro_fixed_step3 && ram <_scoroll_5_pro_fixed_step4)
       return ran_Item_Three_Bar;
    else if(ram >=_scoroll_5_pro_fixed_step4 && ram <_scoroll_5_pro_fixed_step5)
       return ran_Item_Red_7;
    else if(ram >=_scoroll_5_pro_fixed_step5 && ram <_scoroll_5_pro_fixed_step6)
       return ran_Item_Blue_7;
    else if(ram >=_scoroll_5_pro_fixed_step6 && ram <_scoroll_5_pro_fixed_step7)
       return ran_Item_Joker;
#endif

	return 0;
}
/**
 * @brief Frame probability type fixed 6.
 * @param mt Mersenne twister algorithm instance
 * @param pctrl Probability controller
 * @retval Item type
 * @author SHIE-BINGSHIUE
 * @date 2010-09-10
 */
int _FrameProTypeFixed_6(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    unsigned int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_fixed_random_Base);

    if(ram < SCROLL_6_PROBABILITY_STEP_1)
       return ITEM_CHERRY;
    else if(ram >=SCROLL_6_PROBABILITY_STEP_1 && ram <SCROLL_6_PROBABILITY_STEP_2)
       return ITEM_ORANGE;
    else if(ram >=SCROLL_6_PROBABILITY_STEP_2 && ram <SCROLL_6_PROBABILITY_STEP_3)
       return ITEM_MANGO;
    else if(ram >=SCROLL_6_PROBABILITY_STEP_3 && ram <SCROLL_6_PROBABILITY_STEP_4)
       return ITEM_BELL;
    else if(ram >=SCROLL_6_PROBABILITY_STEP_4 && ram <SCROLL_6_PROBABILITY_STEP_5)
       return ITEM_WATERMELON;
    else if(ram >=SCROLL_6_PROBABILITY_STEP_5 && ram <SCROLL_6_PROBABILITY_STEP_6)
       return ITEM_BAR_YELLOW;
    else if(ram >=SCROLL_6_PROBABILITY_STEP_6 && ram <SCROLL_6_PROBABILITY_STEP_7)
       return ITEM_BAR_RED;
    else if(ram >=SCROLL_6_PROBABILITY_STEP_7 && ram <SCROLL_6_PROBABILITY_STEP_8)
       return ITEM_BAR_BLUE;
    else if(ram >=SCROLL_6_PROBABILITY_STEP_8 && ram <SCROLL_6_PROBABILITY_STEP_9)
       return ITEM_WILD;

    //else if(ram >=SCROLL_6_PROBABILITY_STEP_8 && ram <SCROLL_6_PROBABILITY_STEP_9)
       //return ITEM_SEVEN;
    //else if(ram >=SCROLL_6_PROBABILITY_STEP_9 && ram <SCROLL_6_PROBABILITY_STEP_10)
       //return ITEM_WILD;

#if 0
    if(ram < _scoroll_6_pro_fixed_step1)
       return ran_Item_Blank;
    else if(ram >=_scoroll_6_pro_fixed_step1 && ram <_scoroll_6_pro_fixed_step2)
       return ran_Item_One_Bar;
    else if(ram >=_scoroll_6_pro_fixed_step2 && ram <_scoroll_6_pro_fixed_step3)
       return ran_Item_Two_Bar;
    else if(ram >=_scoroll_6_pro_fixed_step3 && ram <_scoroll_6_pro_fixed_step4)
       return ran_Item_Three_Bar;
    else if(ram >=_scoroll_6_pro_fixed_step4 && ram <_scoroll_6_pro_fixed_step5)
       return ran_Item_Red_7;
    else if(ram >=_scoroll_6_pro_fixed_step5 && ram <_scoroll_6_pro_fixed_step6)
       return ran_Item_Blue_7;
    else if(ram >=_scoroll_6_pro_fixed_step6 && ram <_scoroll_6_pro_fixed_step7)
       return ran_Item_Joker;
#endif

	return 0;
}
/**
 * @brief Frame probability type fixed 7.
 * @param mt Mersenne twister algorithm instance
 * @param pctrl Probability controller
 * @retval Item type
 * @author SHIE-BINGSHIUE
 * @date 2010-09-10
 */
int _FrameProTypeFixed_7(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    unsigned int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_fixed_random_Base);

    if(ram < SCROLL_7_PROBABILITY_STEP_1)
       return ITEM_CHERRY;
    else if(ram >=SCROLL_7_PROBABILITY_STEP_1 && ram <SCROLL_7_PROBABILITY_STEP_2)
       return ITEM_ORANGE;
    else if(ram >=SCROLL_7_PROBABILITY_STEP_2 && ram <SCROLL_7_PROBABILITY_STEP_3)
       return ITEM_MANGO;
    else if(ram >=SCROLL_7_PROBABILITY_STEP_3 && ram <SCROLL_7_PROBABILITY_STEP_4)
       return ITEM_BELL;
    else if(ram >=SCROLL_7_PROBABILITY_STEP_4 && ram <SCROLL_7_PROBABILITY_STEP_5)
       return ITEM_WATERMELON;
    else if(ram >=SCROLL_7_PROBABILITY_STEP_5 && ram <SCROLL_7_PROBABILITY_STEP_6)
       return ITEM_BAR_YELLOW;
    else if(ram >=SCROLL_7_PROBABILITY_STEP_6 && ram <SCROLL_7_PROBABILITY_STEP_7)
       return ITEM_BAR_RED;
    else if(ram >=SCROLL_7_PROBABILITY_STEP_7 && ram <SCROLL_7_PROBABILITY_STEP_8)
       return ITEM_BAR_BLUE;
    else if(ram >=SCROLL_7_PROBABILITY_STEP_8 && ram <SCROLL_7_PROBABILITY_STEP_9)
       return ITEM_WILD;

    //else if(ram >=SCROLL_7_PROBABILITY_STEP_8 && ram <SCROLL_7_PROBABILITY_STEP_9)
       //return ITEM_SEVEN;
    //else if(ram >=SCROLL_7_PROBABILITY_STEP_9 && ram <SCROLL_7_PROBABILITY_STEP_10)
       //return ITEM_WILD;

#if 0

    if(ram < _scoroll_7_pro_fixed_step1)
       return ran_Item_Blank;
    else if(ram >=_scoroll_7_pro_fixed_step1 && ram <_scoroll_7_pro_fixed_step2)
       return ran_Item_One_Bar;
    else if(ram >=_scoroll_7_pro_fixed_step2 && ram <_scoroll_7_pro_fixed_step3)
       return ran_Item_Two_Bar;
    else if(ram >=_scoroll_7_pro_fixed_step3 && ram <_scoroll_7_pro_fixed_step4)
       return ran_Item_Three_Bar;
    else if(ram >=_scoroll_7_pro_fixed_step4 && ram <_scoroll_7_pro_fixed_step5)
       return ran_Item_Red_7;
    else if(ram >=_scoroll_7_pro_fixed_step5 && ram <_scoroll_7_pro_fixed_step6)
       return ran_Item_Blue_7;
    else if(ram >=_scoroll_7_pro_fixed_step6 && ram <_scoroll_7_pro_fixed_step7)
       return ran_Item_Joker;
#endif

	return 0;
}
/**
 * @brief Frame probability type fixed 8.
 * @param mt Mersenne twister algorithm instance
 * @param pctrl Probability controller
 * @retval Item type
 * @author SHIE-BINGSHIUE
 * @date 2010-09-10
 */
int _FrameProTypeFixed_8(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    unsigned int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_fixed_random_Base);

    if(ram < SCROLL_8_PROBABILITY_STEP_1)
       return ITEM_CHERRY;
    else if(ram >=SCROLL_8_PROBABILITY_STEP_1 && ram <SCROLL_8_PROBABILITY_STEP_2)
       return ITEM_ORANGE;
    else if(ram >=SCROLL_8_PROBABILITY_STEP_2 && ram <SCROLL_8_PROBABILITY_STEP_3)
       return ITEM_MANGO;
    else if(ram >=SCROLL_8_PROBABILITY_STEP_3 && ram <SCROLL_8_PROBABILITY_STEP_4)
       return ITEM_BELL;
    else if(ram >=SCROLL_8_PROBABILITY_STEP_4 && ram <SCROLL_8_PROBABILITY_STEP_5)
       return ITEM_WATERMELON;
    else if(ram >=SCROLL_8_PROBABILITY_STEP_5 && ram <SCROLL_8_PROBABILITY_STEP_6)
       return ITEM_BAR_YELLOW;
    else if(ram >=SCROLL_8_PROBABILITY_STEP_6 && ram <SCROLL_8_PROBABILITY_STEP_7)
       return ITEM_BAR_RED;
    else if(ram >=SCROLL_8_PROBABILITY_STEP_7 && ram <SCROLL_8_PROBABILITY_STEP_8)
       return ITEM_BAR_BLUE;
    else if(ram >=SCROLL_8_PROBABILITY_STEP_8 && ram <SCROLL_8_PROBABILITY_STEP_9)
       return ITEM_WILD;

    //else if(ram >=SCROLL_8_PROBABILITY_STEP_8 && ram <SCROLL_8_PROBABILITY_STEP_9)
       //return ITEM_SEVEN;
    //else if(ram >=SCROLL_8_PROBABILITY_STEP_9 && ram <SCROLL_8_PROBABILITY_STEP_10)
       //return ITEM_WILD;

#if 0
    if(ram < _scoroll_8_pro_fixed_step1)
       return ran_Item_Blank;
    else if(ram >=_scoroll_8_pro_fixed_step1 && ram <_scoroll_8_pro_fixed_step2)
       return ran_Item_One_Bar;
    else if(ram >=_scoroll_8_pro_fixed_step2 && ram <_scoroll_8_pro_fixed_step3)
       return ran_Item_Two_Bar;
    else if(ram >=_scoroll_8_pro_fixed_step3 && ram <_scoroll_8_pro_fixed_step4)
       return ran_Item_Three_Bar;
    else if(ram >=_scoroll_8_pro_fixed_step4 && ram <_scoroll_8_pro_fixed_step5)
       return ran_Item_Red_7;
    else if(ram >=_scoroll_8_pro_fixed_step5 && ram <_scoroll_8_pro_fixed_step6)
       return ran_Item_Blue_7;
    else if(ram >=_scoroll_8_pro_fixed_step6 && ram <_scoroll_8_pro_fixed_step7)
       return ran_Item_Joker;
#endif

	return 0;
}
/**
 * @brief Frame probability type mutable.
 * @param mt Mersenne twister algorithm instance
 * @param pctrl Probability controller
 * @retval Item type
 * @author SHIE-BINGSHIUE
 * @date 2010-09-10
 */

int _FrameProTypeMutable(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    unsigned int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_Mutable_random_Base);

    switch(pctrl->_status){
     case status_normal:

         if(ram < (MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][0]) * 100)
 		   return ran_Item_Blank;
 		else if(ram >=(MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][0]) * 100 &&
 				 ram < (MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][1]) * 100)
 		   return ran_Item_One_Bar;
 		else if(ram >=(MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][1]) * 100 &&
 				 ram < (MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][2]) * 100)
 		   return ran_Item_Two_Bar;
 		else if(ram >=(MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][2]) * 100 &&
 				 ram < (MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][2]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][3]) * 100 )
 		   return ran_Item_Three_Bar;
 		else if(ram >=(MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][2]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][3]) * 100 &&
 				 ram < (MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][2]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][3]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][4]) * 100)
 		   return ran_Item_Red_7;
 		else if(ram >=(MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][2]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][3]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][4]) * 100 &&
 				 ram < (MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][2]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][3]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][4]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][5]) * 100)
 		   return ran_Item_Blue_7;
 		else if(ram >=(MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][2]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][3]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][4]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][5]) * 100 &&
 				 ram < (MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][2]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][3]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][4]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][5]+MaingameProM[*(pctrl->_glSetting)][pctrl->__normalM[pctrl->_indexOfRunning%15]][6]) * 100)
 		   return ran_Item_Joker;

         break;

     case status_up:

         if(ram < (MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][0]) * 100)
 		   return ran_Item_Blank;
 		else if(ram >=(MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][0]) * 100 &&
 				 ram < (MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][0]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][1]) * 100)
 		   return ran_Item_One_Bar;
 		else if(ram >=(MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][0]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][1]) * 100 &&
 				 ram < (MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][0]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][1]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][2]) * 100)
 		   return ran_Item_Two_Bar;
 		else if(ram >=(MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][0]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][1]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][2]) * 100 &&
 				 ram < (MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][0]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][1]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][2]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][3]) * 100 )
 		   return ran_Item_Three_Bar;
 		else if(ram >=(MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][0]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][1]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][2]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][3]) * 100 &&
 				 ram < (MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][0]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][1]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][2]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][3]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][4]) * 100)
 		   return ran_Item_Red_7;
 		else if(ram >=(MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][0]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][1]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][2]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][3]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][4]) * 100 &&
 				 ram < (MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][0]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][1]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][2]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][3]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][4]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][5]) * 100)
 		   return ran_Item_Blue_7;
 		else if(ram >=(MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][0]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][1]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][2]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][3]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][4]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][5]) * 100 &&
 				 ram < (MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][0]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][1]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][2]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][3]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][4]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][5]+MaingameProUpM[pctrl->__upM[pctrl->_indexOfRunning]][6]) * 100)
 		   return ran_Item_Joker;

     	break;

     case status_down:

         if(ram < (MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][0]) * 100)
 		   return ran_Item_Blank;
 		else if(ram >=(MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][0]) * 100 &&
 				 ram < (MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][0]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][1]) * 100)
 		   return ran_Item_One_Bar;
 		else if(ram >=(MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][0]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][1]) * 100 &&
 				 ram < (MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][0]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][1]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][2]) * 100)
 		   return ran_Item_Two_Bar;
 		else if(ram >=(MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][0]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][1]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][2]) * 100 &&
 				 ram < (MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][0]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][1]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][2]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][3]) * 100 )
 		   return ran_Item_Three_Bar;
 		else if(ram >=(MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][0]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][1]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][2]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][3]) * 100 &&
 				 ram < (MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][0]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][1]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][2]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][3]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][4]) * 100)
 		   return ran_Item_Red_7;
 		else if(ram >=(MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][0]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][1]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][2]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][3]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][4]) * 100 &&
 				 ram < (MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][0]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][1]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][2]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][3]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][4]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][5]) * 100)
 		   return ran_Item_Blue_7;
 		else if(ram >=(MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][0]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][1]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][2]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][3]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][4]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][5]) * 100 &&
 				 ram < (MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][0]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][1]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][2]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][3]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][4]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][5]+MaingameProDownM[pctrl->__downM[pctrl->_indexOfRunning]][6]) * 100)
 		   return ran_Item_Joker;

     	break;

     case status_link:

         if(ram < (MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][0]) * 100)
 		   return ran_Item_Blank;
 		else if(ram >=(MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][0]) * 100 &&
 				 ram < (MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][1]) * 100)
 		   return ran_Item_One_Bar;
 		else if(ram >=(MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][1]) * 100 &&
 				 ram < (MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][2]) * 100)
 		   return ran_Item_Two_Bar;
 		else if(ram >=(MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][2]) * 100 &&
 				 ram < (MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][2]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][3]) * 100 )
 		   return ran_Item_Three_Bar;
 		else if(ram >=(MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][2]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][3]) * 100 &&
 				 ram < (MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][2]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][3]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][4]) * 100)
 		   return ran_Item_Red_7;
 		else if(ram >=(MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][2]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][3]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][4]) * 100 &&
 				 ram < (MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][2]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][3]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][4]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][5]) * 100)
 		   return ran_Item_Blue_7;
 		else if(ram >=(MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][2]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][3]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][4]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][5]) * 100 &&
 				 ram < (MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][0]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][1]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][2]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][3]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][4]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][5]+MaingameProM[*(pctrl->_glSetting_link)][pctrl->__linkM[pctrl->_indexOfRunning%15]][6]) * 100)
 		   return ran_Item_Joker;

         break;

     default:
     	break;
     }

 	return 0;
}

#if TEST_MAIN_GAME_COMPUTE_SCORE==1
/**
 * @brief For test frame's probability.
 *
 * @param mt Pointer to MTSYSTEM
 * @param pctrl Pointer to PROBABILITYCONTROL
 *
 * @author SHIE-BINGSHIUE
 * @date 2010-08-17
 */
int _FrameProTypeTest(MTSYSTEM* mt,PROBABILITYCONTROL* pctrl){
    unsigned int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_Mutable_random_Base);

    if(ram < 2000)
       return ran_Item_Blank;
    else if(ram >=2000 && ram <5000)
       return ran_Item_One_Bar;
    else if(ram >=5000 && ram <6000)
       return ran_Item_Two_Bar;
    else if(ram >=6000 && ram <7000)
       return ran_Item_Three_Bar;
    else if(ram >=7000 && ram <8000)
       return ran_Item_Red_7;
    else if(ram >=8000 && ram <9000)
       return ran_Item_Blue_7;
    else if(ram >=9000 && ram <10000)
       return ran_Item_Joker;

	return 0;

}
#endif


#endif /* PROBABILITYSUBFUNC_H_ */
