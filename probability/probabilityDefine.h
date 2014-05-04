/**
 * @file probabilityDefine.h
 * @brief Probability Define.
 *
 */

#ifndef PROBABILITYDEFINE_H_
#define PROBABILITYDEFINE_H_

#include "../preprocessor/preprocessor.h"

/*** Genuine Compute Score Style or Not ***/
#ifdef Genuine_Compute_Score
	#define HaveMixCheckBar(J,A,B,C)   (J>0)  ? true : true/**< Check have Mix BAR */

	#define HaveMixCheck7(J,A,B)       (J>0)  ? true : true/**< Check have Mix 7 */
#else
	#define HaveMixCheckBar(J,A,B,C)   (J>0)  ? true : \
									    (A==0) ? (B==0) ? false : (C==0) ? false : true  :  \
									    (B==0) ? (C==0) ? false : true : true/**< Check have Mix BAR */

	#define HaveMixCheck7(J,A,B)       (J>0)  ? true : \
									    (A&&B) ? true : false/**< Check have Mix 7 */
#endif

#define DEF_DAWARD_TYPE_X0  0
#define DEF_DAWARD_TYPE_X2  1
#define DEF_DAWARD_TYPE_X4  2
#define DEF_DAWARD_TYPE_X6  3

#define DEF_DPRO_STEP_1  6000
#define DEF_DPRO_STEP_2  3700
#define DEF_DPRO_STEP_3   250
#define DEF_DPRO_STEP_4    50

#define DEF_DCONTINUE      50

//Frame Item Define
#define Item_Blank_1           0/**< frame's indicator of Blank 1 */
#define Item_Blank_2           1/**< frame's indicator of Blank 2 */
#define Item_Blank_3           2/**< frame's indicator of Blank 3 */
#define Item_Blank_4           3/**< frame's indicator of Blank 4 */
#define Item_Blank_5           4/**< frame's indicator of Blank 5 */
#define Item_Blank_6           5/**< frame's indicator of Blank 6 */
#define Item_One_Bar           6/**< frame's indicator of One Bar */
#define Item_Two_Bar           7/**< frame's indicator of Two Bar */
#define Item_Three_Bar         8/**< frame's indicator of Three Bar */
#define Item_Red_7             9/**< frame's indicator of Red 7 */
#define Item_Blue_7           10/**< frame's indicator of Blue 7 */
#define Item_Joker            11/**< frame's indicator of Joker */
//

/**< Frame Item Define(97 type) */
#define ITEM_UNKNOW              0
#define ITEM_CHERRY              1
#define ITEM_ORANGE              2
#define ITEM_MANGO               3
#define ITEM_BELL                4
#define ITEM_WATERMELON          5
#define ITEM_BAR_YELLOW          6
#define ITEM_BAR_RED             7
#define ITEM_BAR_BLUE            8
#define ITEM_WILD                9/**< Wild */
//#define ITEM_SEVEN               9
//#define ITEM_WILD               10/**< Wild */

//Frame Random Define
#define ran_Item_Blank         0/**< Random indicator of Blank */
#define ran_Item_One_Bar       1/**< Random indicator of One Bar */
#define ran_Item_Two_Bar       2/**< Random indicator of Two Bar */
#define ran_Item_Three_Bar     3/**< Random indicator of Three Bar */
#define ran_Item_Red_7         4/**< Random indicator of Red 7 */
#define ran_Item_Blue_7        5/**< Random indicator of Blue 7 */
#define ran_Item_Joker         6/**< Random indicator of Joker */
//

//Line Bingo Type Define
#define lb_None                0/**< Line award type none */
#define lb_Mix_Bar_Straight    1/**< Line award type Mix Bar Straight */
#define lb_One_Bar_Straight    2/**< Line award type One Bar Straight */
#define lb_Two_Bar_Straight    3/**< Line award type Two Bar Straight */
#define lb_Three_Bar_Straight  4/**< Line award type Three Bar Straight */
#define lb_Mix_7_Straight      5/**< Line award type Mix 7 Straight */
#define lb_Red_7_Straight      6/**< Line award type Red 7 Straight */
#define lb_Blue_7_Straight     7/**< Line award type Blue 7 Straight */
#define lb_Joker_Straight      8/**< Line award type Joker 7 Straight */
//

//Line Award Type Define (97 type)
#define LINE_AWARD_NONE            0/**< Line award type none */
#define LINE_AWARD_ONE_CHERRY      1/**< Line award type one cherry straight */
#define LINE_AWARD_TWO_CHERRY      2/**< Line award type two cherry straight */
#define LINE_AWARD_THREE_CHERRY    3/**< Line award type three cherry straight */
#define LINE_AWARD_ORANGE          4/**< Line award type orange straight */
#define LINE_AWARD_MIX_BAR         5/**< Line award type mix bar */
#define LINE_AWARD_MANGO           6/**< Line award type mango straight */
#define LINE_AWARD_BELL            7/**< Line award type bell straight */
#define LINE_AWARD_WATERMELON      8/**< Line award type watermelon straight */
#define LINE_AWARD_BAR_YELLOW      9/**< Line award type bar yellow straight */
#define LINE_AWARD_BAR_RED        10/**< Line award type bar red straight */
#define LINE_AWARD_BAR_BLUE       11/**< Line award type bar blue straight */
#define LINE_AWARD_WILD           12/**< Line award type wild */
//#define LINE_AWARD_SEVEN          12/**< Line award type seven straight */
//#define LINE_AWARD_WILD           13/**< Line award type wild */
//

//Side Item Define
#define side_Blank             0/**< Side item indicator of Blank */
#define side_Mix_Bar           1/**< Side item indicator of Mix Bar */
#define side_One_Bar           2/**< Side item indicator of One Bar */
#define side_Two_Bar           3/**< Side item indicator of Two Bar */
#define side_Three_Bar         4/**< Side item indicator of Three Bar */
#define side_Mix_7             5/**< Side item indicator of Mix 7 */
#define side_Red_7             6/**< Side item indicator of Red 7 */
#define side_Blue_7            7/**< Side item indicator of Blue 7 */
#define side_Joker             8/**< Side item indicator of Joker */
//

//FULL Frame Item Define(97 type for computing item count)
#define FULL_UNKNOW            0
#define FULL_CHERRY            1
#define FULL_ORANGE            2
#define FULL_MANGO             3
#define FULL_BELL              4
#define FULL_WATERMELON        5
#define FULL_BAR_YELLOW        6
#define FULL_BAR_RED           7
#define FULL_BAR_BLUE          8
#define FULL_WIND              9
//#define FULL_SEVEN             9
//#define FULL_WIND              10


//Side Bingo Type Define
#define sb_Blank               0/**< Side award type Blank */
#define sb_Mix_Bar             1/**< Side award type Mix Bar */
#define sb_One_Bar             2/**< Side award type One Bar */
#define sb_Two_Bar             3/**< Side award type Two Bar */
#define sb_Three_Bar           4/**< Side award type Three Bar */
#define sb_Mix_7               5/**< Side award type Mix 7 */
#define sb_Red_7               6/**< Side award type Red 7 */
#define sb_Blue_7              7/**< Side award type Blue 7 */
//

//FULL Frame Award Type Define
#define FULL_AWARD_UNKNOW      0
#define FULL_AWARD_ALL_FRUIT   1
#define FULL_AWARD_ANY_BAR     2
#define FULL_AWARD_ORANGE      3
#define FULL_AWARD_MANGO       4
#define FULL_AWARD_BELL        5
#define FULL_AWARD_WATERMELON  6
#define FULL_AWARD_BAR_YELLOW  7
#define FULL_AWARD_CHERRY      8
#define FULL_AWARD_BAR_RED     9
#define FULL_AWARD_BAR_BLUE   10
#define FULL_AWARD_WILD       11
//#define FULL_AWARD_SEVEN      11
//#define FULL_AWARD_WILD       12

//Scroll Stop Item Probability(fixed)
//Scroll Stop Random Base
#define _scroll_pro_fixed_random_Base    10000/**< Random base of fixed frame */
#define _scroll_pro_Mutable_random_Base  10000/**< Random base of mutable frame */
#define _double_award_random_base        10000/**< Random base of double game */
#ifdef MAIN_PRO_VER_A
//fixed Scroll 1
#define _scroll_1_pro_fixed_Blank      6200
  #define _scoroll_1_pro_fixed_step1    (_scroll_1_pro_fixed_Blank)
#define _scroll_1_pro_fixed_1Bar       700
  #define _scoroll_1_pro_fixed_step2    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar)
#define _scroll_1_pro_fixed_2Bar       700
  #define _scoroll_1_pro_fixed_step3    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar + _scroll_1_pro_fixed_2Bar)
#define _scroll_1_pro_fixed_3Bar       700
  #define _scoroll_1_pro_fixed_step4    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar + _scroll_1_pro_fixed_2Bar + _scroll_1_pro_fixed_3Bar)
#define _scroll_1_pro_fixed_Red7       700
  #define _scoroll_1_pro_fixed_step5    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar + _scroll_1_pro_fixed_2Bar + _scroll_1_pro_fixed_3Bar + _scroll_1_pro_fixed_Red7)
#define _scroll_1_pro_fixed_Blue7      700
  #define _scoroll_1_pro_fixed_step6    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar + _scroll_1_pro_fixed_2Bar + _scroll_1_pro_fixed_3Bar + _scroll_1_pro_fixed_Red7 + _scroll_1_pro_fixed_Blue7)
#define _scroll_1_pro_fixed_Joker      300
  #define _scoroll_1_pro_fixed_step7    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar + _scroll_1_pro_fixed_2Bar + _scroll_1_pro_fixed_3Bar + _scroll_1_pro_fixed_Red7 + _scroll_1_pro_fixed_Blue7 + _scroll_1_pro_fixed_Joker)

//fixed Scroll 2
#define _scroll_2_pro_fixed_Blank      5100
  #define _scoroll_2_pro_fixed_step1    (_scroll_2_pro_fixed_Blank)
#define _scroll_2_pro_fixed_1Bar       2300
  #define _scoroll_2_pro_fixed_step2    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar)
#define _scroll_2_pro_fixed_2Bar       1000
  #define _scoroll_2_pro_fixed_step3    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar + _scroll_2_pro_fixed_2Bar)
#define _scroll_2_pro_fixed_3Bar        800
  #define _scoroll_2_pro_fixed_step4    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar + _scroll_2_pro_fixed_2Bar + _scroll_2_pro_fixed_3Bar)
#define _scroll_2_pro_fixed_Red7        500
  #define _scoroll_2_pro_fixed_step5    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar + _scroll_2_pro_fixed_2Bar + _scroll_2_pro_fixed_3Bar + _scroll_2_pro_fixed_Red7)
#define _scroll_2_pro_fixed_Blue7       200
  #define _scoroll_2_pro_fixed_step6    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar + _scroll_2_pro_fixed_2Bar + _scroll_2_pro_fixed_3Bar + _scroll_2_pro_fixed_Red7 + _scroll_2_pro_fixed_Blue7)
#define _scroll_2_pro_fixed_Joker       100
  #define _scoroll_2_pro_fixed_step7    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar + _scroll_2_pro_fixed_2Bar + _scroll_2_pro_fixed_3Bar + _scroll_2_pro_fixed_Red7 + _scroll_2_pro_fixed_Blue7 + _scroll_2_pro_fixed_Joker)

//fixed Scroll 3
#define _scroll_3_pro_fixed_Blank      6000
  #define _scoroll_3_pro_fixed_step1    (_scroll_3_pro_fixed_Blank)
#define _scroll_3_pro_fixed_1Bar       1000
  #define _scoroll_3_pro_fixed_step2    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar)
#define _scroll_3_pro_fixed_2Bar       800
  #define _scoroll_3_pro_fixed_step3    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar + _scroll_3_pro_fixed_2Bar)
#define _scroll_3_pro_fixed_3Bar       600
  #define _scoroll_3_pro_fixed_step4    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar + _scroll_3_pro_fixed_2Bar + _scroll_3_pro_fixed_3Bar)
#define _scroll_3_pro_fixed_Red7       700
  #define _scoroll_3_pro_fixed_step5    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar + _scroll_3_pro_fixed_2Bar + _scroll_3_pro_fixed_3Bar + _scroll_3_pro_fixed_Red7)
#define _scroll_3_pro_fixed_Blue7      700
  #define _scoroll_3_pro_fixed_step6    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar + _scroll_3_pro_fixed_2Bar + _scroll_3_pro_fixed_3Bar + _scroll_3_pro_fixed_Red7 + _scroll_3_pro_fixed_Blue7)
#define _scroll_3_pro_fixed_Joker      200
  #define _scoroll_3_pro_fixed_step7    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar + _scroll_3_pro_fixed_2Bar + _scroll_3_pro_fixed_3Bar + _scroll_3_pro_fixed_Red7 + _scroll_3_pro_fixed_Blue7 + _scroll_3_pro_fixed_Joker)

//fixed Scroll 4
#define _scroll_4_pro_fixed_Blank      5000
  #define _scoroll_4_pro_fixed_step1    (_scroll_4_pro_fixed_Blank)
#define _scroll_4_pro_fixed_1Bar       2400
  #define _scoroll_4_pro_fixed_step2    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar)
#define _scroll_4_pro_fixed_2Bar       1100
  #define _scoroll_4_pro_fixed_step3    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar + _scroll_4_pro_fixed_2Bar)
#define _scroll_4_pro_fixed_3Bar        900
  #define _scoroll_4_pro_fixed_step4    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar + _scroll_4_pro_fixed_2Bar + _scroll_4_pro_fixed_3Bar)
#define _scroll_4_pro_fixed_Red7        300
  #define _scoroll_4_pro_fixed_step5    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar + _scroll_4_pro_fixed_2Bar + _scroll_4_pro_fixed_3Bar + _scroll_4_pro_fixed_Red7)
#define _scroll_4_pro_fixed_Blue7       200
  #define _scoroll_4_pro_fixed_step6    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar + _scroll_4_pro_fixed_2Bar + _scroll_4_pro_fixed_3Bar + _scroll_4_pro_fixed_Red7 + _scroll_4_pro_fixed_Blue7)
#define _scroll_4_pro_fixed_Joker       100
  #define _scoroll_4_pro_fixed_step7    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar + _scroll_4_pro_fixed_2Bar + _scroll_4_pro_fixed_3Bar + _scroll_4_pro_fixed_Red7 + _scroll_4_pro_fixed_Blue7 + _scroll_4_pro_fixed_Joker)

//fixed Scroll 5
#define _scroll_5_pro_fixed_Blank      4000
  #define _scoroll_5_pro_fixed_step1    (_scroll_5_pro_fixed_Blank)
#define _scroll_5_pro_fixed_1Bar       2100
  #define _scoroll_5_pro_fixed_step2    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar)
#define _scroll_5_pro_fixed_2Bar       1500
  #define _scoroll_5_pro_fixed_step3    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar + _scroll_5_pro_fixed_2Bar)
#define _scroll_5_pro_fixed_3Bar       1300
  #define _scoroll_5_pro_fixed_step4    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar + _scroll_5_pro_fixed_2Bar + _scroll_5_pro_fixed_3Bar)
#define _scroll_5_pro_fixed_Red7        600
  #define _scoroll_5_pro_fixed_step5    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar + _scroll_5_pro_fixed_2Bar + _scroll_5_pro_fixed_3Bar + _scroll_5_pro_fixed_Red7)
#define _scroll_5_pro_fixed_Blue7       300
  #define _scoroll_5_pro_fixed_step6    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar + _scroll_5_pro_fixed_2Bar + _scroll_5_pro_fixed_3Bar + _scroll_5_pro_fixed_Red7 + _scroll_5_pro_fixed_Blue7)
#define _scroll_5_pro_fixed_Joker       200
  #define _scoroll_5_pro_fixed_step7    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar + _scroll_5_pro_fixed_2Bar + _scroll_5_pro_fixed_3Bar + _scroll_5_pro_fixed_Red7 + _scroll_5_pro_fixed_Blue7 + _scroll_5_pro_fixed_Joker)

//fixed Scroll 6
#define _scroll_6_pro_fixed_Blank      5600
  #define _scoroll_6_pro_fixed_step1    (_scroll_6_pro_fixed_Blank)
#define _scroll_6_pro_fixed_1Bar       1500
  #define _scoroll_6_pro_fixed_step2    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar)
#define _scroll_6_pro_fixed_2Bar       1000
  #define _scoroll_6_pro_fixed_step3    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar + _scroll_6_pro_fixed_2Bar)
#define _scroll_6_pro_fixed_3Bar        800
  #define _scoroll_6_pro_fixed_step4    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar + _scroll_6_pro_fixed_2Bar + _scroll_6_pro_fixed_3Bar)
#define _scroll_6_pro_fixed_Red7        600
  #define _scoroll_6_pro_fixed_step5    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar + _scroll_6_pro_fixed_2Bar + _scroll_6_pro_fixed_3Bar + _scroll_6_pro_fixed_Red7)
#define _scroll_6_pro_fixed_Blue7       400
  #define _scoroll_6_pro_fixed_step6    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar + _scroll_6_pro_fixed_2Bar + _scroll_6_pro_fixed_3Bar + _scroll_6_pro_fixed_Red7 + _scroll_6_pro_fixed_Blue7)
#define _scroll_6_pro_fixed_Joker       100
  #define _scoroll_6_pro_fixed_step7    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar + _scroll_6_pro_fixed_2Bar + _scroll_6_pro_fixed_3Bar + _scroll_6_pro_fixed_Red7 + _scroll_6_pro_fixed_Blue7 + _scroll_6_pro_fixed_Joker)

//fixed Scroll 7
#define _scroll_7_pro_fixed_Blank      4800
  #define _scoroll_7_pro_fixed_step1    (_scroll_7_pro_fixed_Blank)
#define _scroll_7_pro_fixed_1Bar       2300
  #define _scoroll_7_pro_fixed_step2    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar)
#define _scroll_7_pro_fixed_2Bar       1100
  #define _scoroll_7_pro_fixed_step3    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar + _scroll_7_pro_fixed_2Bar)
#define _scroll_7_pro_fixed_3Bar        800
  #define _scoroll_7_pro_fixed_step4    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar + _scroll_7_pro_fixed_2Bar + _scroll_7_pro_fixed_3Bar)
#define _scroll_7_pro_fixed_Red7        600
  #define _scoroll_7_pro_fixed_step5    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar + _scroll_7_pro_fixed_2Bar + _scroll_7_pro_fixed_3Bar + _scroll_7_pro_fixed_Red7)
#define _scroll_7_pro_fixed_Blue7       300
  #define _scoroll_7_pro_fixed_step6    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar + _scroll_7_pro_fixed_2Bar + _scroll_7_pro_fixed_3Bar + _scroll_7_pro_fixed_Red7 + _scroll_7_pro_fixed_Blue7)
#define _scroll_7_pro_fixed_Joker       100
  #define _scoroll_7_pro_fixed_step7    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar + _scroll_7_pro_fixed_2Bar + _scroll_7_pro_fixed_3Bar + _scroll_7_pro_fixed_Red7 + _scroll_7_pro_fixed_Blue7 + _scroll_7_pro_fixed_Joker)

//fixed Scroll 8
#define _scroll_8_pro_fixed_Blank      6500
  #define _scoroll_8_pro_fixed_step1    (_scroll_8_pro_fixed_Blank)
#define _scroll_8_pro_fixed_1Bar       400
  #define _scoroll_8_pro_fixed_step2    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar)
#define _scroll_8_pro_fixed_2Bar       400
  #define _scoroll_8_pro_fixed_step3    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar + _scroll_8_pro_fixed_2Bar)
#define _scroll_8_pro_fixed_3Bar       400
  #define _scoroll_8_pro_fixed_step4    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar + _scroll_8_pro_fixed_2Bar + _scroll_8_pro_fixed_3Bar)
#define _scroll_8_pro_fixed_Red7       1000
  #define _scoroll_8_pro_fixed_step5    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar + _scroll_8_pro_fixed_2Bar + _scroll_8_pro_fixed_3Bar + _scroll_8_pro_fixed_Red7)
#define _scroll_8_pro_fixed_Blue7      1000
  #define _scoroll_8_pro_fixed_step6    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar + _scroll_8_pro_fixed_2Bar + _scroll_8_pro_fixed_3Bar + _scroll_8_pro_fixed_Red7 + _scroll_8_pro_fixed_Blue7)
#define _scroll_8_pro_fixed_Joker      300
  #define _scoroll_8_pro_fixed_step7    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar + _scroll_8_pro_fixed_2Bar + _scroll_8_pro_fixed_3Bar + _scroll_8_pro_fixed_Red7 + _scroll_8_pro_fixed_Blue7 + _scroll_8_pro_fixed_Joker)
#else
#ifdef MAIN_PRO_VER_B

//SCROLL 1
#define SCROLL_1_PROBABILITY_CHERRY       400
 #define SCROLL_1_PROBABILITY_STEP_1     (SCROLL_1_PROBABILITY_CHERRY)
#define SCROLL_1_PROBABILITY_ORANGE      2000
 #define SCROLL_1_PROBABILITY_STEP_2     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE)
#define SCROLL_1_PROBABILITY_MANGO       1700
 #define SCROLL_1_PROBABILITY_STEP_3     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO)
#define SCROLL_1_PROBABILITY_BELL        1500
 #define SCROLL_1_PROBABILITY_STEP_4     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO+SCROLL_1_PROBABILITY_BELL)
#define SCROLL_1_PROBABILITY_WATERMELON  1400
 #define SCROLL_1_PROBABILITY_STEP_5     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO+SCROLL_1_PROBABILITY_BELL+SCROLL_1_PROBABILITY_WATERMELON)
#define SCROLL_1_PROBABILITY_BAR_YELLOW  1000
 #define SCROLL_1_PROBABILITY_STEP_6     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO+SCROLL_1_PROBABILITY_BELL+SCROLL_1_PROBABILITY_WATERMELON+SCROLL_1_PROBABILITY_BAR_YELLOW)
#define SCROLL_1_PROBABILITY_BAR_RED     1000
 #define SCROLL_1_PROBABILITY_STEP_7     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO+SCROLL_1_PROBABILITY_BELL+SCROLL_1_PROBABILITY_WATERMELON+SCROLL_1_PROBABILITY_BAR_YELLOW+SCROLL_1_PROBABILITY_BAR_RED)
#define SCROLL_1_PROBABILITY_BAR_BLUE    850
 #define SCROLL_1_PROBABILITY_STEP_8     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO+SCROLL_1_PROBABILITY_BELL+SCROLL_1_PROBABILITY_WATERMELON+SCROLL_1_PROBABILITY_BAR_YELLOW+SCROLL_1_PROBABILITY_BAR_RED+SCROLL_1_PROBABILITY_BAR_BLUE)
#define SCROLL_1_PROBABILITY_WILD        150
 #define SCROLL_1_PROBABILITY_STEP_9     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO+SCROLL_1_PROBABILITY_BELL+SCROLL_1_PROBABILITY_WATERMELON+SCROLL_1_PROBABILITY_BAR_YELLOW+SCROLL_1_PROBABILITY_BAR_RED+SCROLL_1_PROBABILITY_BAR_BLUE+SCROLL_1_PROBABILITY_WILD)

//#define SCROLL_1_PROBABILITY_SEVEN       500
 //#define SCROLL_1_PROBABILITY_STEP_9     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO+SCROLL_1_PROBABILITY_BELL+SCROLL_1_PROBABILITY_WATERMELON+SCROLL_1_PROBABILITY_BAR_YELLOW+SCROLL_1_PROBABILITY_BAR_RED+SCROLL_1_PROBABILITY_BAR_BLUE+SCROLL_1_PROBABILITY_SEVEN)
//#define SCROLL_1_PROBABILITY_WILD        500
 //#define SCROLL_1_PROBABILITY_STEP_10    (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO+SCROLL_1_PROBABILITY_BELL+SCROLL_1_PROBABILITY_WATERMELON+SCROLL_1_PROBABILITY_BAR_YELLOW+SCROLL_1_PROBABILITY_BAR_RED+SCROLL_1_PROBABILITY_BAR_BLUE+SCROLL_1_PROBABILITY_SEVEN+SCROLL_1_PROBABILITY_WILD)

//SCROLL 2
#define SCROLL_2_PROBABILITY_CHERRY       500
 #define SCROLL_2_PROBABILITY_STEP_1     (SCROLL_2_PROBABILITY_CHERRY)
#define SCROLL_2_PROBABILITY_ORANGE      1300
 #define SCROLL_2_PROBABILITY_STEP_2     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE)
#define SCROLL_2_PROBABILITY_MANGO       1200
 #define SCROLL_2_PROBABILITY_STEP_3     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO)
#define SCROLL_2_PROBABILITY_BELL        2300
 #define SCROLL_2_PROBABILITY_STEP_4     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO+SCROLL_2_PROBABILITY_BELL)
#define SCROLL_2_PROBABILITY_WATERMELON  1400
 #define SCROLL_2_PROBABILITY_STEP_5     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO+SCROLL_2_PROBABILITY_BELL+SCROLL_2_PROBABILITY_WATERMELON)
#define SCROLL_2_PROBABILITY_BAR_YELLOW  1200
 #define SCROLL_2_PROBABILITY_STEP_6     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO+SCROLL_2_PROBABILITY_BELL+SCROLL_2_PROBABILITY_WATERMELON+SCROLL_2_PROBABILITY_BAR_YELLOW)
#define SCROLL_2_PROBABILITY_BAR_RED     1100
 #define SCROLL_2_PROBABILITY_STEP_7     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO+SCROLL_2_PROBABILITY_BELL+SCROLL_2_PROBABILITY_WATERMELON+SCROLL_2_PROBABILITY_BAR_YELLOW+SCROLL_2_PROBABILITY_BAR_RED)
#define SCROLL_2_PROBABILITY_BAR_BLUE    850
 #define SCROLL_2_PROBABILITY_STEP_8     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO+SCROLL_2_PROBABILITY_BELL+SCROLL_2_PROBABILITY_WATERMELON+SCROLL_2_PROBABILITY_BAR_YELLOW+SCROLL_2_PROBABILITY_BAR_RED+SCROLL_2_PROBABILITY_BAR_BLUE)
#define SCROLL_2_PROBABILITY_WILD        150
 #define SCROLL_2_PROBABILITY_STEP_9     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO+SCROLL_2_PROBABILITY_BELL+SCROLL_2_PROBABILITY_WATERMELON+SCROLL_2_PROBABILITY_BAR_YELLOW+SCROLL_2_PROBABILITY_BAR_RED+SCROLL_2_PROBABILITY_BAR_BLUE+SCROLL_2_PROBABILITY_WILD)

//#define SCROLL_2_PROBABILITY_SEVEN       500
 //#define SCROLL_2_PROBABILITY_STEP_9     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO+SCROLL_2_PROBABILITY_BELL+SCROLL_2_PROBABILITY_WATERMELON+SCROLL_2_PROBABILITY_BAR_YELLOW+SCROLL_2_PROBABILITY_BAR_RED+SCROLL_2_PROBABILITY_BAR_BLUE+SCROLL_2_PROBABILITY_SEVEN)
//#define SCROLL_2_PROBABILITY_WILD        500
 //#define SCROLL_2_PROBABILITY_STEP_10    (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO+SCROLL_2_PROBABILITY_BELL+SCROLL_2_PROBABILITY_WATERMELON+SCROLL_2_PROBABILITY_BAR_YELLOW+SCROLL_2_PROBABILITY_BAR_RED+SCROLL_2_PROBABILITY_BAR_BLUE+SCROLL_2_PROBABILITY_SEVEN+SCROLL_2_PROBABILITY_WILD)

//SCROLL 3
#define SCROLL_3_PROBABILITY_CHERRY       500
 #define SCROLL_3_PROBABILITY_STEP_1     (SCROLL_3_PROBABILITY_CHERRY)
#define SCROLL_3_PROBABILITY_ORANGE      1300
 #define SCROLL_3_PROBABILITY_STEP_2     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE)
#define SCROLL_3_PROBABILITY_MANGO       1200
 #define SCROLL_3_PROBABILITY_STEP_3     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO)
#define SCROLL_3_PROBABILITY_BELL        2300
 #define SCROLL_3_PROBABILITY_STEP_4     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO+SCROLL_3_PROBABILITY_BELL)
#define SCROLL_3_PROBABILITY_WATERMELON  1400
 #define SCROLL_3_PROBABILITY_STEP_5     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO+SCROLL_3_PROBABILITY_BELL+SCROLL_3_PROBABILITY_WATERMELON)
#define SCROLL_3_PROBABILITY_BAR_YELLOW  1200
 #define SCROLL_3_PROBABILITY_STEP_6     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO+SCROLL_3_PROBABILITY_BELL+SCROLL_3_PROBABILITY_WATERMELON+SCROLL_3_PROBABILITY_BAR_YELLOW)
#define SCROLL_3_PROBABILITY_BAR_RED     1100
 #define SCROLL_3_PROBABILITY_STEP_7     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO+SCROLL_3_PROBABILITY_BELL+SCROLL_3_PROBABILITY_WATERMELON+SCROLL_3_PROBABILITY_BAR_YELLOW+SCROLL_3_PROBABILITY_BAR_RED)
#define SCROLL_3_PROBABILITY_BAR_BLUE    850
 #define SCROLL_3_PROBABILITY_STEP_8     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO+SCROLL_3_PROBABILITY_BELL+SCROLL_3_PROBABILITY_WATERMELON+SCROLL_3_PROBABILITY_BAR_YELLOW+SCROLL_3_PROBABILITY_BAR_RED+SCROLL_3_PROBABILITY_BAR_BLUE)
#define SCROLL_3_PROBABILITY_WILD   	 150
 #define SCROLL_3_PROBABILITY_STEP_9     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO+SCROLL_3_PROBABILITY_BELL+SCROLL_3_PROBABILITY_WATERMELON+SCROLL_3_PROBABILITY_BAR_YELLOW+SCROLL_3_PROBABILITY_BAR_RED+SCROLL_3_PROBABILITY_BAR_BLUE+SCROLL_3_PROBABILITY_WILD)

//#define SCROLL_3_PROBABILITY_SEVEN   	 500
 //#define SCROLL_3_PROBABILITY_STEP_9     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO+SCROLL_3_PROBABILITY_BELL+SCROLL_3_PROBABILITY_WATERMELON+SCROLL_3_PROBABILITY_BAR_YELLOW+SCROLL_3_PROBABILITY_BAR_RED+SCROLL_3_PROBABILITY_BAR_BLUE+SCROLL_3_PROBABILITY_SEVEN)
//#define SCROLL_3_PROBABILITY_WILD        500
 //#define SCROLL_3_PROBABILITY_STEP_10    (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO+SCROLL_3_PROBABILITY_BELL+SCROLL_3_PROBABILITY_WATERMELON+SCROLL_3_PROBABILITY_BAR_YELLOW+SCROLL_3_PROBABILITY_BAR_RED+SCROLL_3_PROBABILITY_BAR_BLUE+SCROLL_3_PROBABILITY_SEVEN+SCROLL_3_PROBABILITY_WILD)

//SCROLL 4
#define SCROLL_4_PROBABILITY_CHERRY      500
 #define SCROLL_4_PROBABILITY_STEP_1     (SCROLL_4_PROBABILITY_CHERRY)
#define SCROLL_4_PROBABILITY_ORANGE      1300
 #define SCROLL_4_PROBABILITY_STEP_2     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE)
#define SCROLL_4_PROBABILITY_MANGO       1200
 #define SCROLL_4_PROBABILITY_STEP_3     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO)
#define SCROLL_4_PROBABILITY_BELL        2300
 #define SCROLL_4_PROBABILITY_STEP_4     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO+SCROLL_4_PROBABILITY_BELL)
#define SCROLL_4_PROBABILITY_WATERMELON  1400
 #define SCROLL_4_PROBABILITY_STEP_5     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO+SCROLL_4_PROBABILITY_BELL+SCROLL_4_PROBABILITY_WATERMELON)
#define SCROLL_4_PROBABILITY_BAR_YELLOW  1200
 #define SCROLL_4_PROBABILITY_STEP_6     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO+SCROLL_4_PROBABILITY_BELL+SCROLL_4_PROBABILITY_WATERMELON+SCROLL_4_PROBABILITY_BAR_YELLOW)
#define SCROLL_4_PROBABILITY_BAR_RED     1100
 #define SCROLL_4_PROBABILITY_STEP_7     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO+SCROLL_4_PROBABILITY_BELL+SCROLL_4_PROBABILITY_WATERMELON+SCROLL_4_PROBABILITY_BAR_YELLOW+SCROLL_4_PROBABILITY_BAR_RED)
#define SCROLL_4_PROBABILITY_BAR_BLUE    850
 #define SCROLL_4_PROBABILITY_STEP_8     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO+SCROLL_4_PROBABILITY_BELL+SCROLL_4_PROBABILITY_WATERMELON+SCROLL_4_PROBABILITY_BAR_YELLOW+SCROLL_4_PROBABILITY_BAR_RED+SCROLL_4_PROBABILITY_BAR_BLUE)
#define SCROLL_4_PROBABILITY_WILD        150
 #define SCROLL_4_PROBABILITY_STEP_9     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO+SCROLL_4_PROBABILITY_BELL+SCROLL_4_PROBABILITY_WATERMELON+SCROLL_4_PROBABILITY_BAR_YELLOW+SCROLL_4_PROBABILITY_BAR_RED+SCROLL_4_PROBABILITY_BAR_BLUE+SCROLL_4_PROBABILITY_WILD)

//#define SCROLL_4_PROBABILITY_SEVEN       500
 //#define SCROLL_4_PROBABILITY_STEP_9     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO+SCROLL_4_PROBABILITY_BELL+SCROLL_4_PROBABILITY_WATERMELON+SCROLL_4_PROBABILITY_BAR_YELLOW+SCROLL_4_PROBABILITY_BAR_RED+SCROLL_4_PROBABILITY_BAR_BLUE+SCROLL_4_PROBABILITY_SEVEN)
//#define SCROLL_4_PROBABILITY_WILD        500
 //#define SCROLL_4_PROBABILITY_STEP_10    (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO+SCROLL_4_PROBABILITY_BELL+SCROLL_4_PROBABILITY_WATERMELON+SCROLL_4_PROBABILITY_BAR_YELLOW+SCROLL_4_PROBABILITY_BAR_RED+SCROLL_4_PROBABILITY_BAR_BLUE+SCROLL_4_PROBABILITY_SEVEN+SCROLL_4_PROBABILITY_WILD)

//SCROLL 5
#define SCROLL_5_PROBABILITY_CHERRY      1000
 #define SCROLL_5_PROBABILITY_STEP_1     (SCROLL_5_PROBABILITY_CHERRY)
#define SCROLL_5_PROBABILITY_ORANGE      1800
 #define SCROLL_5_PROBABILITY_STEP_2     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE)
#define SCROLL_5_PROBABILITY_MANGO       1600
 #define SCROLL_5_PROBABILITY_STEP_3     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO)
#define SCROLL_5_PROBABILITY_BELL        1400
 #define SCROLL_5_PROBABILITY_STEP_4     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO+SCROLL_5_PROBABILITY_BELL)
#define SCROLL_5_PROBABILITY_WATERMELON  1200
 #define SCROLL_5_PROBABILITY_STEP_5     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO+SCROLL_5_PROBABILITY_BELL+SCROLL_5_PROBABILITY_WATERMELON)
#define SCROLL_5_PROBABILITY_BAR_YELLOW  1000
 #define SCROLL_5_PROBABILITY_STEP_6     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO+SCROLL_5_PROBABILITY_BELL+SCROLL_5_PROBABILITY_WATERMELON+SCROLL_5_PROBABILITY_BAR_YELLOW)
#define SCROLL_5_PROBABILITY_BAR_RED     1000
 #define SCROLL_5_PROBABILITY_STEP_7     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO+SCROLL_5_PROBABILITY_BELL+SCROLL_5_PROBABILITY_WATERMELON+SCROLL_5_PROBABILITY_BAR_YELLOW+SCROLL_5_PROBABILITY_BAR_RED)
#define SCROLL_5_PROBABILITY_BAR_BLUE    850
 #define SCROLL_5_PROBABILITY_STEP_8     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO+SCROLL_5_PROBABILITY_BELL+SCROLL_5_PROBABILITY_WATERMELON+SCROLL_5_PROBABILITY_BAR_YELLOW+SCROLL_5_PROBABILITY_BAR_RED+SCROLL_5_PROBABILITY_BAR_BLUE)
#define SCROLL_5_PROBABILITY_WILD        150
 #define SCROLL_5_PROBABILITY_STEP_9     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO+SCROLL_5_PROBABILITY_BELL+SCROLL_5_PROBABILITY_WATERMELON+SCROLL_5_PROBABILITY_BAR_YELLOW+SCROLL_5_PROBABILITY_BAR_RED+SCROLL_5_PROBABILITY_BAR_BLUE+SCROLL_5_PROBABILITY_WILD)

//#define SCROLL_5_PROBABILITY_SEVEN       500
 //#define SCROLL_5_PROBABILITY_STEP_9     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO+SCROLL_5_PROBABILITY_BELL+SCROLL_5_PROBABILITY_WATERMELON+SCROLL_5_PROBABILITY_BAR_YELLOW+SCROLL_5_PROBABILITY_BAR_RED+SCROLL_5_PROBABILITY_BAR_BLUE+SCROLL_5_PROBABILITY_SEVEN)
//#define SCROLL_5_PROBABILITY_WILD        500
 //#define SCROLL_5_PROBABILITY_STEP_10    (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO+SCROLL_5_PROBABILITY_BELL+SCROLL_5_PROBABILITY_WATERMELON+SCROLL_5_PROBABILITY_BAR_YELLOW+SCROLL_5_PROBABILITY_BAR_RED+SCROLL_5_PROBABILITY_BAR_BLUE+SCROLL_5_PROBABILITY_SEVEN+SCROLL_5_PROBABILITY_WILD)

//SCROLL 6
#define SCROLL_6_PROBABILITY_CHERRY      1000
 #define SCROLL_6_PROBABILITY_STEP_1     (SCROLL_6_PROBABILITY_CHERRY)
#define SCROLL_6_PROBABILITY_ORANGE      1800
 #define SCROLL_6_PROBABILITY_STEP_2     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE)
#define SCROLL_6_PROBABILITY_MANGO       1600
 #define SCROLL_6_PROBABILITY_STEP_3     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO)
#define SCROLL_6_PROBABILITY_BELL        1400
 #define SCROLL_6_PROBABILITY_STEP_4     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO+SCROLL_6_PROBABILITY_BELL)
#define SCROLL_6_PROBABILITY_WATERMELON  1200
 #define SCROLL_6_PROBABILITY_STEP_5     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO+SCROLL_6_PROBABILITY_BELL+SCROLL_6_PROBABILITY_WATERMELON)
#define SCROLL_6_PROBABILITY_BAR_YELLOW  1000
 #define SCROLL_6_PROBABILITY_STEP_6     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO+SCROLL_6_PROBABILITY_BELL+SCROLL_6_PROBABILITY_WATERMELON+SCROLL_6_PROBABILITY_BAR_YELLOW)
#define SCROLL_6_PROBABILITY_BAR_RED     1000
 #define SCROLL_6_PROBABILITY_STEP_7     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO+SCROLL_6_PROBABILITY_BELL+SCROLL_6_PROBABILITY_WATERMELON+SCROLL_6_PROBABILITY_BAR_YELLOW+SCROLL_6_PROBABILITY_BAR_RED)
#define SCROLL_6_PROBABILITY_BAR_BLUE    850
 #define SCROLL_6_PROBABILITY_STEP_8     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO+SCROLL_6_PROBABILITY_BELL+SCROLL_6_PROBABILITY_WATERMELON+SCROLL_6_PROBABILITY_BAR_YELLOW+SCROLL_6_PROBABILITY_BAR_RED+SCROLL_6_PROBABILITY_BAR_BLUE)
#define SCROLL_6_PROBABILITY_WILD        150
 #define SCROLL_6_PROBABILITY_STEP_9     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO+SCROLL_6_PROBABILITY_BELL+SCROLL_6_PROBABILITY_WATERMELON+SCROLL_6_PROBABILITY_BAR_YELLOW+SCROLL_6_PROBABILITY_BAR_RED+SCROLL_6_PROBABILITY_BAR_BLUE+SCROLL_6_PROBABILITY_WILD)

//#define SCROLL_6_PROBABILITY_SEVEN       500
 //#define SCROLL_6_PROBABILITY_STEP_9     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO+SCROLL_6_PROBABILITY_BELL+SCROLL_6_PROBABILITY_WATERMELON+SCROLL_6_PROBABILITY_BAR_YELLOW+SCROLL_6_PROBABILITY_BAR_RED+SCROLL_6_PROBABILITY_BAR_BLUE+SCROLL_6_PROBABILITY_SEVEN)
//#define SCROLL_6_PROBABILITY_WILD        500
 //#define SCROLL_6_PROBABILITY_STEP_10    (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO+SCROLL_6_PROBABILITY_BELL+SCROLL_6_PROBABILITY_WATERMELON+SCROLL_6_PROBABILITY_BAR_YELLOW+SCROLL_6_PROBABILITY_BAR_RED+SCROLL_6_PROBABILITY_BAR_BLUE+SCROLL_6_PROBABILITY_SEVEN+SCROLL_6_PROBABILITY_WILD)

//SCROLL 7
#define SCROLL_7_PROBABILITY_CHERRY      500
 #define SCROLL_7_PROBABILITY_STEP_1     (SCROLL_7_PROBABILITY_CHERRY)
#define SCROLL_7_PROBABILITY_ORANGE      1800
 #define SCROLL_7_PROBABILITY_STEP_2     (SCROLL_7_PROBABILITY_CHERRY+SCROLL_7_PROBABILITY_ORANGE)
#define SCROLL_7_PROBABILITY_MANGO       1600
 #define SCROLL_7_PROBABILITY_STEP_3     (SCROLL_7_PROBABILITY_CHERRY+SCROLL_7_PROBABILITY_ORANGE+SCROLL_7_PROBABILITY_MANGO)
#define SCROLL_7_PROBABILITY_BELL        1800
 #define SCROLL_7_PROBABILITY_STEP_4     (SCROLL_7_PROBABILITY_CHERRY+SCROLL_7_PROBABILITY_ORANGE+SCROLL_7_PROBABILITY_MANGO+SCROLL_7_PROBABILITY_BELL)
#define SCROLL_7_PROBABILITY_WATERMELON  1300
 #define SCROLL_7_PROBABILITY_STEP_5     (SCROLL_7_PROBABILITY_CHERRY+SCROLL_7_PROBABILITY_ORANGE+SCROLL_7_PROBABILITY_MANGO+SCROLL_7_PROBABILITY_BELL+SCROLL_7_PROBABILITY_WATERMELON)
#define SCROLL_7_PROBABILITY_BAR_YELLOW  1000
 #define SCROLL_7_PROBABILITY_STEP_6     (SCROLL_7_PROBABILITY_CHERRY+SCROLL_7_PROBABILITY_ORANGE+SCROLL_7_PROBABILITY_MANGO+SCROLL_7_PROBABILITY_BELL+SCROLL_7_PROBABILITY_WATERMELON+SCROLL_7_PROBABILITY_BAR_YELLOW)
#define SCROLL_7_PROBABILITY_BAR_RED     1000
 #define SCROLL_7_PROBABILITY_STEP_7     (SCROLL_7_PROBABILITY_CHERRY+SCROLL_7_PROBABILITY_ORANGE+SCROLL_7_PROBABILITY_MANGO+SCROLL_7_PROBABILITY_BELL+SCROLL_7_PROBABILITY_WATERMELON+SCROLL_7_PROBABILITY_BAR_YELLOW+SCROLL_7_PROBABILITY_BAR_RED)
#define SCROLL_7_PROBABILITY_BAR_BLUE    850
 #define SCROLL_7_PROBABILITY_STEP_8     (SCROLL_7_PROBABILITY_CHERRY+SCROLL_7_PROBABILITY_ORANGE+SCROLL_7_PROBABILITY_MANGO+SCROLL_7_PROBABILITY_BELL+SCROLL_7_PROBABILITY_WATERMELON+SCROLL_7_PROBABILITY_BAR_YELLOW+SCROLL_7_PROBABILITY_BAR_RED+SCROLL_7_PROBABILITY_BAR_BLUE)
#define SCROLL_7_PROBABILITY_WILD        150
 #define SCROLL_7_PROBABILITY_STEP_9     (SCROLL_7_PROBABILITY_CHERRY+SCROLL_7_PROBABILITY_ORANGE+SCROLL_7_PROBABILITY_MANGO+SCROLL_7_PROBABILITY_BELL+SCROLL_7_PROBABILITY_WATERMELON+SCROLL_7_PROBABILITY_BAR_YELLOW+SCROLL_7_PROBABILITY_BAR_RED+SCROLL_7_PROBABILITY_BAR_BLUE+SCROLL_7_PROBABILITY_WILD)

//#define SCROLL_7_PROBABILITY_SEVEN       500
 //#define SCROLL_7_PROBABILITY_STEP_9     (SCROLL_7_PROBABILITY_CHERRY+SCROLL_7_PROBABILITY_ORANGE+SCROLL_7_PROBABILITY_MANGO+SCROLL_7_PROBABILITY_BELL+SCROLL_7_PROBABILITY_WATERMELON+SCROLL_7_PROBABILITY_BAR_YELLOW+SCROLL_7_PROBABILITY_BAR_RED+SCROLL_7_PROBABILITY_BAR_BLUE+SCROLL_7_PROBABILITY_SEVEN)
//#define SCROLL_7_PROBABILITY_WILD        500
 //#define SCROLL_7_PROBABILITY_STEP_10    (SCROLL_7_PROBABILITY_CHERRY+SCROLL_7_PROBABILITY_ORANGE+SCROLL_7_PROBABILITY_MANGO+SCROLL_7_PROBABILITY_BELL+SCROLL_7_PROBABILITY_WATERMELON+SCROLL_7_PROBABILITY_BAR_YELLOW+SCROLL_7_PROBABILITY_BAR_RED+SCROLL_7_PROBABILITY_BAR_BLUE+SCROLL_7_PROBABILITY_SEVEN+SCROLL_7_PROBABILITY_WILD)

//SCROLL 8
#define SCROLL_8_PROBABILITY_CHERRY      1000
 #define SCROLL_8_PROBABILITY_STEP_1     (SCROLL_8_PROBABILITY_CHERRY)
#define SCROLL_8_PROBABILITY_ORANGE      1800
 #define SCROLL_8_PROBABILITY_STEP_2     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE)
#define SCROLL_8_PROBABILITY_MANGO       1600
 #define SCROLL_8_PROBABILITY_STEP_3     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO)
#define SCROLL_8_PROBABILITY_BELL        1400
 #define SCROLL_8_PROBABILITY_STEP_4     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL)
#define SCROLL_8_PROBABILITY_WATERMELON  1200
 #define SCROLL_8_PROBABILITY_STEP_5     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL+SCROLL_8_PROBABILITY_WATERMELON)
#define SCROLL_8_PROBABILITY_BAR_YELLOW  1000
 #define SCROLL_8_PROBABILITY_STEP_6     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL+SCROLL_8_PROBABILITY_WATERMELON+SCROLL_8_PROBABILITY_BAR_YELLOW)
#define SCROLL_8_PROBABILITY_BAR_RED     1000
 #define SCROLL_8_PROBABILITY_STEP_7     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL+SCROLL_8_PROBABILITY_WATERMELON+SCROLL_8_PROBABILITY_BAR_YELLOW+SCROLL_8_PROBABILITY_BAR_RED)
#define SCROLL_8_PROBABILITY_BAR_BLUE    850
 #define SCROLL_8_PROBABILITY_STEP_8     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL+SCROLL_8_PROBABILITY_WATERMELON+SCROLL_8_PROBABILITY_BAR_YELLOW+SCROLL_8_PROBABILITY_BAR_RED+SCROLL_8_PROBABILITY_BAR_BLUE)
#define SCROLL_8_PROBABILITY_WILD        150
 #define SCROLL_8_PROBABILITY_STEP_9     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL+SCROLL_8_PROBABILITY_WATERMELON+SCROLL_8_PROBABILITY_BAR_YELLOW+SCROLL_8_PROBABILITY_BAR_RED+SCROLL_8_PROBABILITY_BAR_BLUE+SCROLL_8_PROBABILITY_WILD)

//#define SCROLL_8_PROBABILITY_SEVEN       500
 //#define SCROLL_8_PROBABILITY_STEP_9     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL+SCROLL_8_PROBABILITY_WATERMELON+SCROLL_8_PROBABILITY_BAR_YELLOW+SCROLL_8_PROBABILITY_BAR_RED+SCROLL_8_PROBABILITY_BAR_BLUE+SCROLL_8_PROBABILITY_SEVEN)
//#define SCROLL_8_PROBABILITY_WILD        500
 //#define SCROLL_8_PROBABILITY_STEP_10    (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL+SCROLL_8_PROBABILITY_WATERMELON+SCROLL_8_PROBABILITY_BAR_YELLOW+SCROLL_8_PROBABILITY_BAR_RED+SCROLL_8_PROBABILITY_BAR_BLUE+SCROLL_8_PROBABILITY_SEVEN+SCROLL_8_PROBABILITY_WILD)

//SCROLL 9
#define SCROLL_9_PROBABILITY_CHERRY      1000
 #define SCROLL_9_PROBABILITY_STEP_1     (SCROLL_9_PROBABILITY_CHERRY)
#define SCROLL_9_PROBABILITY_ORANGE      1800
 #define SCROLL_9_PROBABILITY_STEP_2     (SCROLL_9_PROBABILITY_CHERRY+SCROLL_9_PROBABILITY_ORANGE)
#define SCROLL_9_PROBABILITY_MANGO       1600
 #define SCROLL_9_PROBABILITY_STEP_3     (SCROLL_9_PROBABILITY_CHERRY+SCROLL_9_PROBABILITY_ORANGE+SCROLL_9_PROBABILITY_MANGO)
#define SCROLL_9_PROBABILITY_BELL        1400
 #define SCROLL_9_PROBABILITY_STEP_4     (SCROLL_9_PROBABILITY_CHERRY+SCROLL_9_PROBABILITY_ORANGE+SCROLL_9_PROBABILITY_MANGO+SCROLL_9_PROBABILITY_BELL)
#define SCROLL_9_PROBABILITY_WATERMELON  1200
 #define SCROLL_9_PROBABILITY_STEP_5     (SCROLL_9_PROBABILITY_CHERRY+SCROLL_9_PROBABILITY_ORANGE+SCROLL_9_PROBABILITY_MANGO+SCROLL_9_PROBABILITY_BELL+SCROLL_9_PROBABILITY_WATERMELON)
#define SCROLL_9_PROBABILITY_BAR_YELLOW  1000
 #define SCROLL_9_PROBABILITY_STEP_6     (SCROLL_9_PROBABILITY_CHERRY+SCROLL_9_PROBABILITY_ORANGE+SCROLL_9_PROBABILITY_MANGO+SCROLL_9_PROBABILITY_BELL+SCROLL_9_PROBABILITY_WATERMELON+SCROLL_9_PROBABILITY_BAR_YELLOW)
#define SCROLL_9_PROBABILITY_BAR_RED     1000
 #define SCROLL_9_PROBABILITY_STEP_7     (SCROLL_9_PROBABILITY_CHERRY+SCROLL_9_PROBABILITY_ORANGE+SCROLL_9_PROBABILITY_MANGO+SCROLL_9_PROBABILITY_BELL+SCROLL_9_PROBABILITY_WATERMELON+SCROLL_9_PROBABILITY_BAR_YELLOW+SCROLL_9_PROBABILITY_BAR_RED)
#define SCROLL_9_PROBABILITY_BAR_BLUE    850
 #define SCROLL_9_PROBABILITY_STEP_8     (SCROLL_9_PROBABILITY_CHERRY+SCROLL_9_PROBABILITY_ORANGE+SCROLL_9_PROBABILITY_MANGO+SCROLL_9_PROBABILITY_BELL+SCROLL_9_PROBABILITY_WATERMELON+SCROLL_9_PROBABILITY_BAR_YELLOW+SCROLL_9_PROBABILITY_BAR_RED+SCROLL_9_PROBABILITY_BAR_BLUE)
#define SCROLL_9_PROBABILITY_WILD        150
 #define SCROLL_9_PROBABILITY_STEP_9     (SCROLL_9_PROBABILITY_CHERRY+SCROLL_9_PROBABILITY_ORANGE+SCROLL_9_PROBABILITY_MANGO+SCROLL_9_PROBABILITY_BELL+SCROLL_9_PROBABILITY_WATERMELON+SCROLL_9_PROBABILITY_BAR_YELLOW+SCROLL_9_PROBABILITY_BAR_RED+SCROLL_9_PROBABILITY_BAR_BLUE+SCROLL_9_PROBABILITY_WILD)

//#define SCROLL_8_PROBABILITY_SEVEN       500
 //#define SCROLL_8_PROBABILITY_STEP_9     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL+SCROLL_8_PROBABILITY_WATERMELON+SCROLL_8_PROBABILITY_BAR_YELLOW+SCROLL_8_PROBABILITY_BAR_RED+SCROLL_8_PROBABILITY_BAR_BLUE+SCROLL_8_PROBABILITY_SEVEN)
//#define SCROLL_8_PROBABILITY_WILD        500
 //#define SCROLL_8_PROBABILITY_STEP_10    (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL+SCROLL_8_PROBABILITY_WATERMELON+SCROLL_8_PROBABILITY_BAR_YELLOW+SCROLL_8_PROBABILITY_BAR_RED+SCROLL_8_PROBABILITY_BAR_BLUE+SCROLL_8_PROBABILITY_SEVEN+SCROLL_8_PROBABILITY_WILD)


//fixed Scroll 1
#define _scroll_1_pro_fixed_Blank      6000
  #define _scoroll_1_pro_fixed_step1    (_scroll_1_pro_fixed_Blank)
#define _scroll_1_pro_fixed_1Bar       800
  #define _scoroll_1_pro_fixed_step2    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar)
#define _scroll_1_pro_fixed_2Bar       800
  #define _scoroll_1_pro_fixed_step3    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar + _scroll_1_pro_fixed_2Bar)
#define _scroll_1_pro_fixed_3Bar       800
  #define _scoroll_1_pro_fixed_step4    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar + _scroll_1_pro_fixed_2Bar + _scroll_1_pro_fixed_3Bar)
#define _scroll_1_pro_fixed_Red7       600
  #define _scoroll_1_pro_fixed_step5    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar + _scroll_1_pro_fixed_2Bar + _scroll_1_pro_fixed_3Bar + _scroll_1_pro_fixed_Red7)
#define _scroll_1_pro_fixed_Blue7      700
  #define _scoroll_1_pro_fixed_step6    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar + _scroll_1_pro_fixed_2Bar + _scroll_1_pro_fixed_3Bar + _scroll_1_pro_fixed_Red7 + _scroll_1_pro_fixed_Blue7)
#define _scroll_1_pro_fixed_Joker      300
  #define _scoroll_1_pro_fixed_step7    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar + _scroll_1_pro_fixed_2Bar + _scroll_1_pro_fixed_3Bar + _scroll_1_pro_fixed_Red7 + _scroll_1_pro_fixed_Blue7 + _scroll_1_pro_fixed_Joker)

//fixed Scroll 2
#define _scroll_2_pro_fixed_Blank      4800
  #define _scoroll_2_pro_fixed_step1    (_scroll_2_pro_fixed_Blank)
#define _scroll_2_pro_fixed_1Bar       1500
  #define _scoroll_2_pro_fixed_step2    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar)
#define _scroll_2_pro_fixed_2Bar       1000
  #define _scoroll_2_pro_fixed_step3    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar + _scroll_2_pro_fixed_2Bar)
#define _scroll_2_pro_fixed_3Bar       1500
  #define _scoroll_2_pro_fixed_step4    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar + _scroll_2_pro_fixed_2Bar + _scroll_2_pro_fixed_3Bar)
#define _scroll_2_pro_fixed_Red7        600
  #define _scoroll_2_pro_fixed_step5    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar + _scroll_2_pro_fixed_2Bar + _scroll_2_pro_fixed_3Bar + _scroll_2_pro_fixed_Red7)
#define _scroll_2_pro_fixed_Blue7       500
  #define _scoroll_2_pro_fixed_step6    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar + _scroll_2_pro_fixed_2Bar + _scroll_2_pro_fixed_3Bar + _scroll_2_pro_fixed_Red7 + _scroll_2_pro_fixed_Blue7)
#define _scroll_2_pro_fixed_Joker       100
  #define _scoroll_2_pro_fixed_step7    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar + _scroll_2_pro_fixed_2Bar + _scroll_2_pro_fixed_3Bar + _scroll_2_pro_fixed_Red7 + _scroll_2_pro_fixed_Blue7 + _scroll_2_pro_fixed_Joker)

//fixed Scroll 3
#define _scroll_3_pro_fixed_Blank      5600
  #define _scoroll_3_pro_fixed_step1    (_scroll_3_pro_fixed_Blank)
#define _scroll_3_pro_fixed_1Bar       1200
  #define _scoroll_3_pro_fixed_step2    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar)
#define _scroll_3_pro_fixed_2Bar       1200
  #define _scoroll_3_pro_fixed_step3    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar + _scroll_3_pro_fixed_2Bar)
#define _scroll_3_pro_fixed_3Bar       800
  #define _scoroll_3_pro_fixed_step4    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar + _scroll_3_pro_fixed_2Bar + _scroll_3_pro_fixed_3Bar)
#define _scroll_3_pro_fixed_Red7       500
  #define _scoroll_3_pro_fixed_step5    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar + _scroll_3_pro_fixed_2Bar + _scroll_3_pro_fixed_3Bar + _scroll_3_pro_fixed_Red7)
#define _scroll_3_pro_fixed_Blue7      500
  #define _scoroll_3_pro_fixed_step6    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar + _scroll_3_pro_fixed_2Bar + _scroll_3_pro_fixed_3Bar + _scroll_3_pro_fixed_Red7 + _scroll_3_pro_fixed_Blue7)
#define _scroll_3_pro_fixed_Joker      200
  #define _scoroll_3_pro_fixed_step7    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar + _scroll_3_pro_fixed_2Bar + _scroll_3_pro_fixed_3Bar + _scroll_3_pro_fixed_Red7 + _scroll_3_pro_fixed_Blue7 + _scroll_3_pro_fixed_Joker)

//fixed Scroll 4
#define _scroll_4_pro_fixed_Blank      5800
  #define _scoroll_4_pro_fixed_step1    (_scroll_4_pro_fixed_Blank)
#define _scroll_4_pro_fixed_1Bar        900
  #define _scoroll_4_pro_fixed_step2    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar)
#define _scroll_4_pro_fixed_2Bar       1100
  #define _scoroll_4_pro_fixed_step3    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar + _scroll_4_pro_fixed_2Bar)
#define _scroll_4_pro_fixed_3Bar       1000
  #define _scoroll_4_pro_fixed_step4    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar + _scroll_4_pro_fixed_2Bar + _scroll_4_pro_fixed_3Bar)
#define _scroll_4_pro_fixed_Red7        600
  #define _scoroll_4_pro_fixed_step5    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar + _scroll_4_pro_fixed_2Bar + _scroll_4_pro_fixed_3Bar + _scroll_4_pro_fixed_Red7)
#define _scroll_4_pro_fixed_Blue7       500
  #define _scoroll_4_pro_fixed_step6    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar + _scroll_4_pro_fixed_2Bar + _scroll_4_pro_fixed_3Bar + _scroll_4_pro_fixed_Red7 + _scroll_4_pro_fixed_Blue7)
#define _scroll_4_pro_fixed_Joker       100
  #define _scoroll_4_pro_fixed_step7    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar + _scroll_4_pro_fixed_2Bar + _scroll_4_pro_fixed_3Bar + _scroll_4_pro_fixed_Red7 + _scroll_4_pro_fixed_Blue7 + _scroll_4_pro_fixed_Joker)

//fixed Scroll 5
#define _scroll_5_pro_fixed_Blank      6000
  #define _scoroll_5_pro_fixed_step1    (_scroll_5_pro_fixed_Blank)
#define _scroll_5_pro_fixed_1Bar        900
  #define _scoroll_5_pro_fixed_step2    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar)
#define _scroll_5_pro_fixed_2Bar       1000
  #define _scoroll_5_pro_fixed_step3    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar + _scroll_5_pro_fixed_2Bar)
#define _scroll_5_pro_fixed_3Bar       1000
  #define _scoroll_5_pro_fixed_step4    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar + _scroll_5_pro_fixed_2Bar + _scroll_5_pro_fixed_3Bar)
#define _scroll_5_pro_fixed_Red7        600
  #define _scoroll_5_pro_fixed_step5    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar + _scroll_5_pro_fixed_2Bar + _scroll_5_pro_fixed_3Bar + _scroll_5_pro_fixed_Red7)
#define _scroll_5_pro_fixed_Blue7       400
  #define _scoroll_5_pro_fixed_step6    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar + _scroll_5_pro_fixed_2Bar + _scroll_5_pro_fixed_3Bar + _scroll_5_pro_fixed_Red7 + _scroll_5_pro_fixed_Blue7)
#define _scroll_5_pro_fixed_Joker       100
  #define _scoroll_5_pro_fixed_step7    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar + _scroll_5_pro_fixed_2Bar + _scroll_5_pro_fixed_3Bar + _scroll_5_pro_fixed_Red7 + _scroll_5_pro_fixed_Blue7 + _scroll_5_pro_fixed_Joker)

//fixed Scroll 6
#define _scroll_6_pro_fixed_Blank      4600
  #define _scoroll_6_pro_fixed_step1    (_scroll_6_pro_fixed_Blank)
#define _scroll_6_pro_fixed_1Bar       1600
  #define _scoroll_6_pro_fixed_step2    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar)
#define _scroll_6_pro_fixed_2Bar       1400
  #define _scoroll_6_pro_fixed_step3    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar + _scroll_6_pro_fixed_2Bar)
#define _scroll_6_pro_fixed_3Bar       1100
  #define _scoroll_6_pro_fixed_step4    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar + _scroll_6_pro_fixed_2Bar + _scroll_6_pro_fixed_3Bar)
#define _scroll_6_pro_fixed_Red7        700
  #define _scoroll_6_pro_fixed_step5    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar + _scroll_6_pro_fixed_2Bar + _scroll_6_pro_fixed_3Bar + _scroll_6_pro_fixed_Red7)
#define _scroll_6_pro_fixed_Blue7       400
  #define _scoroll_6_pro_fixed_step6    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar + _scroll_6_pro_fixed_2Bar + _scroll_6_pro_fixed_3Bar + _scroll_6_pro_fixed_Red7 + _scroll_6_pro_fixed_Blue7)
#define _scroll_6_pro_fixed_Joker       200
  #define _scoroll_6_pro_fixed_step7    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar + _scroll_6_pro_fixed_2Bar + _scroll_6_pro_fixed_3Bar + _scroll_6_pro_fixed_Red7 + _scroll_6_pro_fixed_Blue7 + _scroll_6_pro_fixed_Joker)

//fixed Scroll 7
#define _scroll_7_pro_fixed_Blank      5700
  #define _scoroll_7_pro_fixed_step1    (_scroll_7_pro_fixed_Blank)
#define _scroll_7_pro_fixed_1Bar       1100
  #define _scoroll_7_pro_fixed_step2    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar)
#define _scroll_7_pro_fixed_2Bar       1000
  #define _scoroll_7_pro_fixed_step3    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar + _scroll_7_pro_fixed_2Bar)
#define _scroll_7_pro_fixed_3Bar       1100
  #define _scoroll_7_pro_fixed_step4    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar + _scroll_7_pro_fixed_2Bar + _scroll_7_pro_fixed_3Bar)
#define _scroll_7_pro_fixed_Red7        500
  #define _scoroll_7_pro_fixed_step5    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar + _scroll_7_pro_fixed_2Bar + _scroll_7_pro_fixed_3Bar + _scroll_7_pro_fixed_Red7)
#define _scroll_7_pro_fixed_Blue7       500
  #define _scoroll_7_pro_fixed_step6    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar + _scroll_7_pro_fixed_2Bar + _scroll_7_pro_fixed_3Bar + _scroll_7_pro_fixed_Red7 + _scroll_7_pro_fixed_Blue7)
#define _scroll_7_pro_fixed_Joker       100
  #define _scoroll_7_pro_fixed_step7    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar + _scroll_7_pro_fixed_2Bar + _scroll_7_pro_fixed_3Bar + _scroll_7_pro_fixed_Red7 + _scroll_7_pro_fixed_Blue7 + _scroll_7_pro_fixed_Joker)

//fixed Scroll 8
#define _scroll_8_pro_fixed_Blank      5400
  #define _scoroll_8_pro_fixed_step1    (_scroll_8_pro_fixed_Blank)
#define _scroll_8_pro_fixed_1Bar       1000
  #define _scoroll_8_pro_fixed_step2    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar)
#define _scroll_8_pro_fixed_2Bar       1000
  #define _scoroll_8_pro_fixed_step3    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar + _scroll_8_pro_fixed_2Bar)
#define _scroll_8_pro_fixed_3Bar       1000
  #define _scoroll_8_pro_fixed_step4    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar + _scroll_8_pro_fixed_2Bar + _scroll_8_pro_fixed_3Bar)
#define _scroll_8_pro_fixed_Red7       600
  #define _scoroll_8_pro_fixed_step5    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar + _scroll_8_pro_fixed_2Bar + _scroll_8_pro_fixed_3Bar + _scroll_8_pro_fixed_Red7)
#define _scroll_8_pro_fixed_Blue7      800
  #define _scoroll_8_pro_fixed_step6    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar + _scroll_8_pro_fixed_2Bar + _scroll_8_pro_fixed_3Bar + _scroll_8_pro_fixed_Red7 + _scroll_8_pro_fixed_Blue7)
#define _scroll_8_pro_fixed_Joker      200
  #define _scoroll_8_pro_fixed_step7    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar + _scroll_8_pro_fixed_2Bar + _scroll_8_pro_fixed_3Bar + _scroll_8_pro_fixed_Red7 + _scroll_8_pro_fixed_Blue7 + _scroll_8_pro_fixed_Joker)
	#endif
#endif
/*** ***/

/***Link Probability ***/
#ifdef MAIN_PRO_VER_A
//*SAMLL*/
//GL small Probability 90
#define gl_s_pro_90_82  190
#define gl_s_pro_90_84  (gl_s_pro_90_82 +200)
#define gl_s_pro_90_86  (gl_s_pro_90_84 +150)
#define gl_s_pro_90_88  (gl_s_pro_90_86 +125)
#define gl_s_pro_90_90  (gl_s_pro_90_88 +110)
#define gl_s_pro_90_92  (gl_s_pro_90_90 +75)
#define gl_s_pro_90_94  (gl_s_pro_90_92 +45)
#define gl_s_pro_90_96  (gl_s_pro_90_94 +10)
#define gl_s_pro_90_98  (gl_s_pro_90_96 +30)
#define gl_s_pro_90_100 (gl_s_pro_90_98 +5)
#define gl_s_pro_90_102 (gl_s_pro_90_100+20)
#define gl_s_pro_90_104 (gl_s_pro_90_102+15)
#define gl_s_pro_90_106 (gl_s_pro_90_104+10)
#define gl_s_pro_90_108 (gl_s_pro_90_106+10)
#define gl_s_pro_90_110 (gl_s_pro_90_108+5)
//GL small Probability 91
#define gl_s_pro_91_82  165
#define gl_s_pro_91_84  (gl_s_pro_91_82 +175)
#define gl_s_pro_91_86  (gl_s_pro_91_84 +180)
#define gl_s_pro_91_88  (gl_s_pro_91_86 +105)
#define gl_s_pro_91_90  (gl_s_pro_91_88 +80)
#define gl_s_pro_91_92  (gl_s_pro_91_90 +70)
#define gl_s_pro_91_94  (gl_s_pro_91_92 +60)
#define gl_s_pro_91_96  (gl_s_pro_91_94 +10)
#define gl_s_pro_91_98  (gl_s_pro_91_96 +50)
#define gl_s_pro_91_100 (gl_s_pro_91_98 +35)
#define gl_s_pro_91_102 (gl_s_pro_91_100+25)
#define gl_s_pro_91_104 (gl_s_pro_91_102+5)
#define gl_s_pro_91_106 (gl_s_pro_91_104+10)
#define gl_s_pro_91_108 (gl_s_pro_91_106+10)
#define gl_s_pro_91_110 (gl_s_pro_91_108+20)
//GL small Probability 92
#define gl_s_pro_92_82  175
#define gl_s_pro_92_84  (gl_s_pro_92_82 +130)
#define gl_s_pro_92_86  (gl_s_pro_92_84 +145)
#define gl_s_pro_92_88  (gl_s_pro_92_86 +125)
#define gl_s_pro_92_90  (gl_s_pro_92_88 +50)
#define gl_s_pro_92_92  (gl_s_pro_92_90 +65)
#define gl_s_pro_92_94  (gl_s_pro_92_92 +100)
#define gl_s_pro_92_96  (gl_s_pro_92_94 +50)
#define gl_s_pro_92_98  (gl_s_pro_92_96 +50)
#define gl_s_pro_92_100 (gl_s_pro_92_98 +10)
#define gl_s_pro_92_102 (gl_s_pro_92_100+10)
#define gl_s_pro_92_104 (gl_s_pro_92_102+15)
#define gl_s_pro_92_106 (gl_s_pro_92_104+25)
#define gl_s_pro_92_108 (gl_s_pro_92_106+25)
#define gl_s_pro_92_110 (gl_s_pro_92_108+25)
//GL small Probability 93
#define gl_s_pro_93_82  145
#define gl_s_pro_93_84  (gl_s_pro_93_82 +150)
#define gl_s_pro_93_86  (gl_s_pro_93_84 +60)
#define gl_s_pro_93_88  (gl_s_pro_93_86 +135)
#define gl_s_pro_93_90  (gl_s_pro_93_88 +125)
#define gl_s_pro_93_92  (gl_s_pro_93_90 +20)
#define gl_s_pro_93_94  (gl_s_pro_93_92 +50)
#define gl_s_pro_93_96  (gl_s_pro_93_94 +70)
#define gl_s_pro_93_98  (gl_s_pro_93_96 +80)
#define gl_s_pro_93_100 (gl_s_pro_93_98 +40)
#define gl_s_pro_93_102 (gl_s_pro_93_100+35)
#define gl_s_pro_93_104 (gl_s_pro_93_102+40)
#define gl_s_pro_93_106 (gl_s_pro_93_104+20)
#define gl_s_pro_93_108 (gl_s_pro_93_106+15)
#define gl_s_pro_93_110 (gl_s_pro_93_108+15)
//GL small Probability 94
#define gl_s_pro_94_82  110
#define gl_s_pro_94_84  (gl_s_pro_94_82 +120)
#define gl_s_pro_94_86  (gl_s_pro_94_84 +100)
#define gl_s_pro_94_88  (gl_s_pro_94_86 +60)
#define gl_s_pro_94_90  (gl_s_pro_94_88 +100)
#define gl_s_pro_94_92  (gl_s_pro_94_90 +60)
#define gl_s_pro_94_94  (gl_s_pro_94_92 +100)
#define gl_s_pro_94_96  (gl_s_pro_94_94 +60)
#define gl_s_pro_94_98  (gl_s_pro_94_96 +135)
#define gl_s_pro_94_100 (gl_s_pro_94_98 +25)
#define gl_s_pro_94_102 (gl_s_pro_94_100+45)
#define gl_s_pro_94_104 (gl_s_pro_94_102+35)
#define gl_s_pro_94_106 (gl_s_pro_94_104+25)
#define gl_s_pro_94_108 (gl_s_pro_94_106+10)
#define gl_s_pro_94_110 (gl_s_pro_94_108+15)

//*MID*/
//GL mid Probability 90
#define gl_m_pro_90_70  130
#define gl_m_pro_90_75  (gl_m_pro_90_70 +120)
#define gl_m_pro_90_80  (gl_m_pro_90_75 +135)
#define gl_m_pro_90_85  (gl_m_pro_90_80 +50)
#define gl_m_pro_90_90  (gl_m_pro_90_85 +75)
#define gl_m_pro_90_92  (gl_m_pro_90_90 +145)
#define gl_m_pro_90_94  (gl_m_pro_90_92 +20)
#define gl_m_pro_90_96  (gl_m_pro_90_94 +90)
#define gl_m_pro_90_98  (gl_m_pro_90_96 +100)
#define gl_m_pro_90_100 (gl_m_pro_90_98 +35)
#define gl_m_pro_90_103 (gl_m_pro_90_100+35)
#define gl_m_pro_90_107 (gl_m_pro_90_103+15)
#define gl_m_pro_90_110 (gl_m_pro_90_107+25)
#define gl_m_pro_90_115 (gl_m_pro_90_110+15)
#define gl_m_pro_90_125 (gl_m_pro_90_115+10)
//GL mid Probability 91
#define gl_m_pro_91_70  155
#define gl_m_pro_91_75  (gl_m_pro_91_70 +120)
#define gl_m_pro_91_80  (gl_m_pro_91_75 +55)
#define gl_m_pro_91_85  (gl_m_pro_91_80 +120)
#define gl_m_pro_91_90  (gl_m_pro_91_85 +50)
#define gl_m_pro_91_92  (gl_m_pro_91_90 +45)
#define gl_m_pro_91_94  (gl_m_pro_91_92 +85)
#define gl_m_pro_91_96  (gl_m_pro_91_94 +105)
#define gl_m_pro_91_98  (gl_m_pro_91_96 +115)
#define gl_m_pro_91_100 (gl_m_pro_91_98 +5)
#define gl_m_pro_91_103 (gl_m_pro_91_100+40)
#define gl_m_pro_91_107 (gl_m_pro_91_103+25)
#define gl_m_pro_91_110 (gl_m_pro_91_107+25)
#define gl_m_pro_91_115 (gl_m_pro_91_110+35)
#define gl_m_pro_91_125 (gl_m_pro_91_115+20)
//GL mid Probability 92
#define gl_m_pro_92_70  140
#define gl_m_pro_92_75  (gl_m_pro_92_70 +125)
#define gl_m_pro_92_80  (gl_m_pro_92_75 +105)
#define gl_m_pro_92_85  (gl_m_pro_92_80 +80)
#define gl_m_pro_92_90  (gl_m_pro_92_85 +40)
#define gl_m_pro_92_92  (gl_m_pro_92_90 +85)
#define gl_m_pro_92_94  (gl_m_pro_92_92 +45)
#define gl_m_pro_92_96  (gl_m_pro_92_94 +55)
#define gl_m_pro_92_98  (gl_m_pro_92_96 +65)
#define gl_m_pro_92_100 (gl_m_pro_92_98 +50)
#define gl_m_pro_92_103 (gl_m_pro_92_100+60)
#define gl_m_pro_92_107 (gl_m_pro_92_103+45)
#define gl_m_pro_92_110 (gl_m_pro_92_107+30)
#define gl_m_pro_92_115 (gl_m_pro_92_110+35)
#define gl_m_pro_92_125 (gl_m_pro_92_115+40)
//GL mid Probability 93
#define gl_m_pro_93_70  100
#define gl_m_pro_93_75  (gl_m_pro_93_70 +115)
#define gl_m_pro_93_80  (gl_m_pro_93_75 +60)
#define gl_m_pro_93_85  (gl_m_pro_93_80 +75)
#define gl_m_pro_93_90  (gl_m_pro_93_85 +115)
#define gl_m_pro_93_92  (gl_m_pro_93_90 +50)
#define gl_m_pro_93_94  (gl_m_pro_93_92 +75)
#define gl_m_pro_93_96  (gl_m_pro_93_94 +70)
#define gl_m_pro_93_98  (gl_m_pro_93_96 +105)
#define gl_m_pro_93_100 (gl_m_pro_93_98 +50)
#define gl_m_pro_93_103 (gl_m_pro_93_100+70)
#define gl_m_pro_93_107 (gl_m_pro_93_103+50)
#define gl_m_pro_93_110 (gl_m_pro_93_107+20)
#define gl_m_pro_93_115 (gl_m_pro_93_110+20)
#define gl_m_pro_93_125 (gl_m_pro_93_115+25)
//GL mid Probability 94
#define gl_m_pro_94_70  75
#define gl_m_pro_94_75  (gl_m_pro_94_70 +115)
#define gl_m_pro_94_80  (gl_m_pro_94_75 +70)
#define gl_m_pro_94_85  (gl_m_pro_94_80 +85)
#define gl_m_pro_94_90  (gl_m_pro_94_85 +110)
#define gl_m_pro_94_92  (gl_m_pro_94_90 +55)
#define gl_m_pro_94_94  (gl_m_pro_94_92 +80)
#define gl_m_pro_94_96  (gl_m_pro_94_94 +90)
#define gl_m_pro_94_98  (gl_m_pro_94_96 +70)
#define gl_m_pro_94_100 (gl_m_pro_94_98 +45)
#define gl_m_pro_94_103 (gl_m_pro_94_100+65)
#define gl_m_pro_94_107 (gl_m_pro_94_103+35)
#define gl_m_pro_94_110 (gl_m_pro_94_107+30)
#define gl_m_pro_94_115 (gl_m_pro_94_110+30)
#define gl_m_pro_94_125 (gl_m_pro_94_115+45)

//*BIG*/
//GL big Probability 90
#define gl_b_pro_90_70  130
#define gl_b_pro_90_72  (gl_b_pro_90_70 +75)
#define gl_b_pro_90_74  (gl_b_pro_90_72 +85)
#define gl_b_pro_90_76  (gl_b_pro_90_74 +60)
#define gl_b_pro_90_78  (gl_b_pro_90_76 +100)
#define gl_b_pro_90_80  (gl_b_pro_90_78 +75)
#define gl_b_pro_90_85  (gl_b_pro_90_80 +110)
#define gl_b_pro_90_90  (gl_b_pro_90_85 +65)
#define gl_b_pro_90_95  (gl_b_pro_90_90 +45)
#define gl_b_pro_90_100 (gl_b_pro_90_95 +70)
#define gl_b_pro_90_106 (gl_b_pro_90_100+55)
#define gl_b_pro_90_114 (gl_b_pro_90_106+25)
#define gl_b_pro_90_123 (gl_b_pro_90_114+55)
#define gl_b_pro_90_133 (gl_b_pro_90_123+25)
#define gl_b_pro_90_144 (gl_b_pro_90_133+25)
//GL big Probability 91
#define gl_b_pro_91_70  95
#define gl_b_pro_91_72  (gl_b_pro_91_70 +95)
#define gl_b_pro_91_74  (gl_b_pro_91_72 +95)
#define gl_b_pro_91_76  (gl_b_pro_91_74 +110)
#define gl_b_pro_91_78  (gl_b_pro_91_76 +50)
#define gl_b_pro_91_80  (gl_b_pro_91_78 +45)
#define gl_b_pro_91_85  (gl_b_pro_91_80 +80)
#define gl_b_pro_91_90  (gl_b_pro_91_85 +95)
#define gl_b_pro_91_95  (gl_b_pro_91_90 +105)
#define gl_b_pro_91_100 (gl_b_pro_91_95 +55)
#define gl_b_pro_91_106 (gl_b_pro_91_100+30)
#define gl_b_pro_91_114 (gl_b_pro_91_106+40)
#define gl_b_pro_91_123 (gl_b_pro_91_114+35)
#define gl_b_pro_91_133 (gl_b_pro_91_123+30)
#define gl_b_pro_91_144 (gl_b_pro_91_133+40)
//GL big Probability 92
#define gl_b_pro_92_70  110
#define gl_b_pro_92_72  (gl_b_pro_92_70 +75)
#define gl_b_pro_92_74  (gl_b_pro_92_72 +50)
#define gl_b_pro_92_76  (gl_b_pro_92_74 +60)
#define gl_b_pro_92_78  (gl_b_pro_92_76 +100)
#define gl_b_pro_92_80  (gl_b_pro_92_78 +85)
#define gl_b_pro_92_85  (gl_b_pro_92_80 +125)
#define gl_b_pro_92_90  (gl_b_pro_92_85 +45)
#define gl_b_pro_92_95  (gl_b_pro_92_90 +35)
#define gl_b_pro_92_100 (gl_b_pro_92_95 +85)
#define gl_b_pro_92_106 (gl_b_pro_92_100+90)
#define gl_b_pro_92_114 (gl_b_pro_92_106+40)
#define gl_b_pro_92_123 (gl_b_pro_92_114+25)
#define gl_b_pro_92_133 (gl_b_pro_92_123+40)
#define gl_b_pro_92_144 (gl_b_pro_92_133+35)
//GL big Probability 93
#define gl_b_pro_93_70  115
#define gl_b_pro_93_72  (gl_b_pro_93_70 +65)
#define gl_b_pro_93_74  (gl_b_pro_93_72 +60)
#define gl_b_pro_93_76  (gl_b_pro_93_74 +70)
#define gl_b_pro_93_78  (gl_b_pro_93_76 +80)
#define gl_b_pro_93_80  (gl_b_pro_93_78 +95)
#define gl_b_pro_93_85  (gl_b_pro_93_80 +100)
#define gl_b_pro_93_90  (gl_b_pro_93_85 +75)
#define gl_b_pro_93_95  (gl_b_pro_93_90 +45)
#define gl_b_pro_93_100 (gl_b_pro_93_95 +50)
#define gl_b_pro_93_106 (gl_b_pro_93_100+50)
#define gl_b_pro_93_114 (gl_b_pro_93_106+60)
#define gl_b_pro_93_123 (gl_b_pro_93_114+45)
#define gl_b_pro_93_133 (gl_b_pro_93_123+45)
#define gl_b_pro_93_144 (gl_b_pro_93_133+45)
//GL big Probability 94
#define gl_b_pro_94_70  55
#define gl_b_pro_94_72  (gl_b_pro_94_70 +50)
#define gl_b_pro_94_74  (gl_b_pro_94_72 +50)
#define gl_b_pro_94_76  (gl_b_pro_94_74 +50)
#define gl_b_pro_94_78  (gl_b_pro_94_76 +50)
#define gl_b_pro_94_80  (gl_b_pro_94_78 +90)
#define gl_b_pro_94_85  (gl_b_pro_94_80 +95)
#define gl_b_pro_94_90  (gl_b_pro_94_85 +95)
#define gl_b_pro_94_95  (gl_b_pro_94_90 +140)
#define gl_b_pro_94_100 (gl_b_pro_94_95 +140)
#define gl_b_pro_94_106 (gl_b_pro_94_100+65)
#define gl_b_pro_94_114 (gl_b_pro_94_106+45)
#define gl_b_pro_94_123 (gl_b_pro_94_114+25)
#define gl_b_pro_94_133 (gl_b_pro_94_123+25)
#define gl_b_pro_94_144 (gl_b_pro_94_133+25)
#else
#ifdef MAIN_PRO_VER_B
//*SAMLL*/
//GL small Probability 90
#define gl_s_pro_90_82  190
#define gl_s_pro_90_84  (gl_s_pro_90_82 +200)
#define gl_s_pro_90_86  (gl_s_pro_90_84 +150)
#define gl_s_pro_90_88  (gl_s_pro_90_86 +125)
#define gl_s_pro_90_90  (gl_s_pro_90_88 +110)
#define gl_s_pro_90_92  (gl_s_pro_90_90 +75)
#define gl_s_pro_90_94  (gl_s_pro_90_92 +45)
#define gl_s_pro_90_96  (gl_s_pro_90_94 +10)
#define gl_s_pro_90_98  (gl_s_pro_90_96 +30)
#define gl_s_pro_90_100 (gl_s_pro_90_98 +5)
#define gl_s_pro_90_102 (gl_s_pro_90_100+20)
#define gl_s_pro_90_104 (gl_s_pro_90_102+15)
#define gl_s_pro_90_106 (gl_s_pro_90_104+10)
#define gl_s_pro_90_108 (gl_s_pro_90_106+10)
#define gl_s_pro_90_110 (gl_s_pro_90_108+5)
//GL small Probability 91
#define gl_s_pro_91_82  165
#define gl_s_pro_91_84  (gl_s_pro_91_82 +175)
#define gl_s_pro_91_86  (gl_s_pro_91_84 +180)
#define gl_s_pro_91_88  (gl_s_pro_91_86 +105)
#define gl_s_pro_91_90  (gl_s_pro_91_88 +80)
#define gl_s_pro_91_92  (gl_s_pro_91_90 +70)
#define gl_s_pro_91_94  (gl_s_pro_91_92 +60)
#define gl_s_pro_91_96  (gl_s_pro_91_94 +10)
#define gl_s_pro_91_98  (gl_s_pro_91_96 +50)
#define gl_s_pro_91_100 (gl_s_pro_91_98 +35)
#define gl_s_pro_91_102 (gl_s_pro_91_100+25)
#define gl_s_pro_91_104 (gl_s_pro_91_102+5)
#define gl_s_pro_91_106 (gl_s_pro_91_104+10)
#define gl_s_pro_91_108 (gl_s_pro_91_106+10)
#define gl_s_pro_91_110 (gl_s_pro_91_108+20)
//GL small Probability 92
#define gl_s_pro_92_82  175
#define gl_s_pro_92_84  (gl_s_pro_92_82 +130)
#define gl_s_pro_92_86  (gl_s_pro_92_84 +145)
#define gl_s_pro_92_88  (gl_s_pro_92_86 +125)
#define gl_s_pro_92_90  (gl_s_pro_92_88 +50)
#define gl_s_pro_92_92  (gl_s_pro_92_90 +65)
#define gl_s_pro_92_94  (gl_s_pro_92_92 +100)
#define gl_s_pro_92_96  (gl_s_pro_92_94 +50)
#define gl_s_pro_92_98  (gl_s_pro_92_96 +50)
#define gl_s_pro_92_100 (gl_s_pro_92_98 +10)
#define gl_s_pro_92_102 (gl_s_pro_92_100+10)
#define gl_s_pro_92_104 (gl_s_pro_92_102+15)
#define gl_s_pro_92_106 (gl_s_pro_92_104+25)
#define gl_s_pro_92_108 (gl_s_pro_92_106+25)
#define gl_s_pro_92_110 (gl_s_pro_92_108+25)
//GL small Probability 93
#define gl_s_pro_93_82  145
#define gl_s_pro_93_84  (gl_s_pro_93_82 +150)
#define gl_s_pro_93_86  (gl_s_pro_93_84 +60)
#define gl_s_pro_93_88  (gl_s_pro_93_86 +135)
#define gl_s_pro_93_90  (gl_s_pro_93_88 +125)
#define gl_s_pro_93_92  (gl_s_pro_93_90 +20)
#define gl_s_pro_93_94  (gl_s_pro_93_92 +50)
#define gl_s_pro_93_96  (gl_s_pro_93_94 +70)
#define gl_s_pro_93_98  (gl_s_pro_93_96 +80)
#define gl_s_pro_93_100 (gl_s_pro_93_98 +40)
#define gl_s_pro_93_102 (gl_s_pro_93_100+35)
#define gl_s_pro_93_104 (gl_s_pro_93_102+40)
#define gl_s_pro_93_106 (gl_s_pro_93_104+20)
#define gl_s_pro_93_108 (gl_s_pro_93_106+15)
#define gl_s_pro_93_110 (gl_s_pro_93_108+15)
//GL small Probability 94
#define gl_s_pro_94_82  110
#define gl_s_pro_94_84  (gl_s_pro_94_82 +120)
#define gl_s_pro_94_86  (gl_s_pro_94_84 +100)
#define gl_s_pro_94_88  (gl_s_pro_94_86 +60)
#define gl_s_pro_94_90  (gl_s_pro_94_88 +100)
#define gl_s_pro_94_92  (gl_s_pro_94_90 +60)
#define gl_s_pro_94_94  (gl_s_pro_94_92 +100)
#define gl_s_pro_94_96  (gl_s_pro_94_94 +60)
#define gl_s_pro_94_98  (gl_s_pro_94_96 +135)
#define gl_s_pro_94_100 (gl_s_pro_94_98 +25)
#define gl_s_pro_94_102 (gl_s_pro_94_100+45)
#define gl_s_pro_94_104 (gl_s_pro_94_102+35)
#define gl_s_pro_94_106 (gl_s_pro_94_104+25)
#define gl_s_pro_94_108 (gl_s_pro_94_106+10)
#define gl_s_pro_94_110 (gl_s_pro_94_108+15)

//*MID*/
//GL mid Probability 90
#define gl_m_pro_90_70  130
#define gl_m_pro_90_75  (gl_m_pro_90_70 +120)
#define gl_m_pro_90_80  (gl_m_pro_90_75 +135)
#define gl_m_pro_90_85  (gl_m_pro_90_80 +50)
#define gl_m_pro_90_90  (gl_m_pro_90_85 +75)
#define gl_m_pro_90_92  (gl_m_pro_90_90 +145)
#define gl_m_pro_90_94  (gl_m_pro_90_92 +20)
#define gl_m_pro_90_96  (gl_m_pro_90_94 +90)
#define gl_m_pro_90_98  (gl_m_pro_90_96 +100)
#define gl_m_pro_90_100 (gl_m_pro_90_98 +35)
#define gl_m_pro_90_103 (gl_m_pro_90_100+35)
#define gl_m_pro_90_107 (gl_m_pro_90_103+15)
#define gl_m_pro_90_110 (gl_m_pro_90_107+25)
#define gl_m_pro_90_115 (gl_m_pro_90_110+15)
#define gl_m_pro_90_125 (gl_m_pro_90_115+10)
//GL mid Probability 91
#define gl_m_pro_91_70  155
#define gl_m_pro_91_75  (gl_m_pro_91_70 +120)
#define gl_m_pro_91_80  (gl_m_pro_91_75 +55)
#define gl_m_pro_91_85  (gl_m_pro_91_80 +120)
#define gl_m_pro_91_90  (gl_m_pro_91_85 +50)
#define gl_m_pro_91_92  (gl_m_pro_91_90 +45)
#define gl_m_pro_91_94  (gl_m_pro_91_92 +85)
#define gl_m_pro_91_96  (gl_m_pro_91_94 +105)
#define gl_m_pro_91_98  (gl_m_pro_91_96 +115)
#define gl_m_pro_91_100 (gl_m_pro_91_98 +5)
#define gl_m_pro_91_103 (gl_m_pro_91_100+40)
#define gl_m_pro_91_107 (gl_m_pro_91_103+25)
#define gl_m_pro_91_110 (gl_m_pro_91_107+25)
#define gl_m_pro_91_115 (gl_m_pro_91_110+35)
#define gl_m_pro_91_125 (gl_m_pro_91_115+20)
//GL mid Probability 92
#define gl_m_pro_92_70  140
#define gl_m_pro_92_75  (gl_m_pro_92_70 +125)
#define gl_m_pro_92_80  (gl_m_pro_92_75 +105)
#define gl_m_pro_92_85  (gl_m_pro_92_80 +80)
#define gl_m_pro_92_90  (gl_m_pro_92_85 +40)
#define gl_m_pro_92_92  (gl_m_pro_92_90 +85)
#define gl_m_pro_92_94  (gl_m_pro_92_92 +45)
#define gl_m_pro_92_96  (gl_m_pro_92_94 +55)
#define gl_m_pro_92_98  (gl_m_pro_92_96 +65)
#define gl_m_pro_92_100 (gl_m_pro_92_98 +50)
#define gl_m_pro_92_103 (gl_m_pro_92_100+60)
#define gl_m_pro_92_107 (gl_m_pro_92_103+45)
#define gl_m_pro_92_110 (gl_m_pro_92_107+30)
#define gl_m_pro_92_115 (gl_m_pro_92_110+35)
#define gl_m_pro_92_125 (gl_m_pro_92_115+40)
//GL mid Probability 93
#define gl_m_pro_93_70  100
#define gl_m_pro_93_75  (gl_m_pro_93_70 +115)
#define gl_m_pro_93_80  (gl_m_pro_93_75 +60)
#define gl_m_pro_93_85  (gl_m_pro_93_80 +75)
#define gl_m_pro_93_90  (gl_m_pro_93_85 +115)
#define gl_m_pro_93_92  (gl_m_pro_93_90 +50)
#define gl_m_pro_93_94  (gl_m_pro_93_92 +75)
#define gl_m_pro_93_96  (gl_m_pro_93_94 +70)
#define gl_m_pro_93_98  (gl_m_pro_93_96 +105)
#define gl_m_pro_93_100 (gl_m_pro_93_98 +50)
#define gl_m_pro_93_103 (gl_m_pro_93_100+70)
#define gl_m_pro_93_107 (gl_m_pro_93_103+50)
#define gl_m_pro_93_110 (gl_m_pro_93_107+20)
#define gl_m_pro_93_115 (gl_m_pro_93_110+20)
#define gl_m_pro_93_125 (gl_m_pro_93_115+25)
//GL mid Probability 94
#define gl_m_pro_94_70  75
#define gl_m_pro_94_75  (gl_m_pro_94_70 +115)
#define gl_m_pro_94_80  (gl_m_pro_94_75 +70)
#define gl_m_pro_94_85  (gl_m_pro_94_80 +85)
#define gl_m_pro_94_90  (gl_m_pro_94_85 +110)
#define gl_m_pro_94_92  (gl_m_pro_94_90 +55)
#define gl_m_pro_94_94  (gl_m_pro_94_92 +80)
#define gl_m_pro_94_96  (gl_m_pro_94_94 +90)
#define gl_m_pro_94_98  (gl_m_pro_94_96 +70)
#define gl_m_pro_94_100 (gl_m_pro_94_98 +45)
#define gl_m_pro_94_103 (gl_m_pro_94_100+65)
#define gl_m_pro_94_107 (gl_m_pro_94_103+35)
#define gl_m_pro_94_110 (gl_m_pro_94_107+30)
#define gl_m_pro_94_115 (gl_m_pro_94_110+30)
#define gl_m_pro_94_125 (gl_m_pro_94_115+45)

//*BIG*/
//GL big Probability 90
#define gl_b_pro_90_70  155
#define gl_b_pro_90_72  (gl_b_pro_90_70 +100)
#define gl_b_pro_90_74  (gl_b_pro_90_72 +115)
#define gl_b_pro_90_76  (gl_b_pro_90_74 +50)
#define gl_b_pro_90_78  (gl_b_pro_90_76 +105)
#define gl_b_pro_90_80  (gl_b_pro_90_78 +60)
#define gl_b_pro_90_85  (gl_b_pro_90_80 +110)
#define gl_b_pro_90_90  (gl_b_pro_90_85 +55)
#define gl_b_pro_90_95  (gl_b_pro_90_90 +45)
#define gl_b_pro_90_100 (gl_b_pro_90_95 +50)
#define gl_b_pro_90_106 (gl_b_pro_90_100+40)
#define gl_b_pro_90_114 (gl_b_pro_90_106+15)
#define gl_b_pro_90_123 (gl_b_pro_90_114+50)
#define gl_b_pro_90_133 (gl_b_pro_90_123+25)
#define gl_b_pro_90_144 (gl_b_pro_90_133+25)
//GL big Probability 91
#define gl_b_pro_91_70  115
#define gl_b_pro_91_72  (gl_b_pro_91_70 +120)
#define gl_b_pro_91_74  (gl_b_pro_91_72 +105)
#define gl_b_pro_91_76  (gl_b_pro_91_74 +80)
#define gl_b_pro_91_78  (gl_b_pro_91_76 +60)
#define gl_b_pro_91_80  (gl_b_pro_91_78 +45)
#define gl_b_pro_91_85  (gl_b_pro_91_80 +80)
#define gl_b_pro_91_90  (gl_b_pro_91_85 +110)
#define gl_b_pro_91_95  (gl_b_pro_91_90 +90)
#define gl_b_pro_91_100 (gl_b_pro_91_95 +50)
#define gl_b_pro_91_106 (gl_b_pro_91_100+25)
#define gl_b_pro_91_114 (gl_b_pro_91_106+40)
#define gl_b_pro_91_123 (gl_b_pro_91_114+15)
#define gl_b_pro_91_133 (gl_b_pro_91_123+30)
#define gl_b_pro_91_144 (gl_b_pro_91_133+35)
//GL big Probability 92
#define gl_b_pro_92_70  130
#define gl_b_pro_92_72  (gl_b_pro_92_70 +75)
#define gl_b_pro_92_74  (gl_b_pro_92_72 +65)
#define gl_b_pro_92_76  (gl_b_pro_92_74 +60)
#define gl_b_pro_92_78  (gl_b_pro_92_76 +105)
#define gl_b_pro_92_80  (gl_b_pro_92_78 +80)
#define gl_b_pro_92_85  (gl_b_pro_92_80 +105)
#define gl_b_pro_92_90  (gl_b_pro_92_85 +90)
#define gl_b_pro_92_95  (gl_b_pro_92_90 +35)
#define gl_b_pro_92_100 (gl_b_pro_92_95 +70)
#define gl_b_pro_92_106 (gl_b_pro_92_100+60)
#define gl_b_pro_92_114 (gl_b_pro_92_106+45)
#define gl_b_pro_92_123 (gl_b_pro_92_114+20)
#define gl_b_pro_92_133 (gl_b_pro_92_123+35)
#define gl_b_pro_92_144 (gl_b_pro_92_133+25)
//GL big Probability 93
#define gl_b_pro_93_70  130
#define gl_b_pro_93_72  (gl_b_pro_93_70 +65)
#define gl_b_pro_93_74  (gl_b_pro_93_72 +80)
#define gl_b_pro_93_76  (gl_b_pro_93_74 +100)
#define gl_b_pro_93_78  (gl_b_pro_93_76 +80)
#define gl_b_pro_93_80  (gl_b_pro_93_78 +100)
#define gl_b_pro_93_85  (gl_b_pro_93_80 +45)
#define gl_b_pro_93_90  (gl_b_pro_93_85 +30)
#define gl_b_pro_93_95  (gl_b_pro_93_90 +100)
#define gl_b_pro_93_100 (gl_b_pro_93_95 +50)
#define gl_b_pro_93_106 (gl_b_pro_93_100+40)
#define gl_b_pro_93_114 (gl_b_pro_93_106+60)
#define gl_b_pro_93_123 (gl_b_pro_93_114+40)
#define gl_b_pro_93_133 (gl_b_pro_93_123+40)
#define gl_b_pro_93_144 (gl_b_pro_93_133+40)
//GL big Probability 94
#define gl_b_pro_94_70  100
#define gl_b_pro_94_72  (gl_b_pro_94_70 +65)
#define gl_b_pro_94_74  (gl_b_pro_94_72 +60)
#define gl_b_pro_94_76  (gl_b_pro_94_74 +60)
#define gl_b_pro_94_78  (gl_b_pro_94_76 +55)
#define gl_b_pro_94_80  (gl_b_pro_94_78 +85)
#define gl_b_pro_94_85  (gl_b_pro_94_80 +100)
#define gl_b_pro_94_90  (gl_b_pro_94_85 +95)
#define gl_b_pro_94_95  (gl_b_pro_94_90 +95)
#define gl_b_pro_94_100 (gl_b_pro_94_95 +95)
#define gl_b_pro_94_106 (gl_b_pro_94_100+55)
#define gl_b_pro_94_114 (gl_b_pro_94_106+35)
#define gl_b_pro_94_123 (gl_b_pro_94_114+30)
#define gl_b_pro_94_133 (gl_b_pro_94_123+40)
#define gl_b_pro_94_144 (gl_b_pro_94_133+30)
#endif
#endif

#endif /* PROBABILITYDEFINE_H_ */
