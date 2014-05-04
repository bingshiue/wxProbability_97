/**
 * @file gameDefine.h
 * @brief define game header.
 *
 */

#ifndef GAMEDEFINE_H_
#define GAMEDEFINE_H_

#include "../preprocessor/preprocessor.h"
#include "gameEnum.h"

/***** Setting Data Index Count *****/
#define SYSTEM_SETTING_TOTAL_INDEX_COUNT        22/**< System setting total index count */
#define PROBABILITY_SETTING_TOTAL_INDEX_COUNT    8/**< Probability setting total index count */
#define REWARDS_SETTING_TOTAL_INDEX_COUNT        6/**< Rewards setting total index count */
#define LINK_SETTING_TOTAL_INDEX_COUNT           2/**< link setting total index count */
#define TIME_SETTING_TOTAL_INDEX_COUNT           6/**< Time setting total index count */

/***** System Setting Data Default Value *****/

#define default_Coin_Value             10               /**< Default coin value */
#define default_KeyInKeyOut           100               /**< Default key in/out */
#define default_MaxBetSet    default_Coin_Value*8       /**< Default max bet set */
#define default_MinBetSet               1               /**< Default minimal bet set */
#define default_Hopper_Max_Pay    Disable               /**< Default hopper max pay */
#define default_Credit_Up_Limit      5000               /**< Default credit up limit */
#define default_Credit_In_Limit      1000               /**< Default credit in limit */
#define default_DDown_Of_Max_Win     2500               /**< Default double down max win */
#define default_Double_Down_Kind  DDownKind_Auto        /**< Default double down return kind */
#define default_Double_Kind       DDown_None            /**< Default double down kind */
#define default_Game_Level        Game_Level_Mid        /**< Default game level */
#define default_coin_acceptor        Enable             /**< Default coin Acceptor */
#define default_bill_acceptor        Disable            /**< Default bill Acceptor */
#define default_coin_in_limit        2000               /**< Default coin In Limit */
#define default_key_in_limit         4000               /**< Default key In LImit */
#define default_bet_unit                1               /**< Default bet Unit */
#define default_hopper_setting       hopper_NO          /**< Default hopper NC/NO */

#ifdef Fast_Run_Test
    #define default_Quick_Collect     QuickCollect_ON   /**< Default quick collect */
#else
    #define default_Quick_Collect     QuickCollect_OFF  /**< Default quick collect */
#endif

#define default_Reel_Spin_Speed   Reel_Spin_Speed_Normal/**< Default slot reel speed */
#define default_Frame_Color       Frame_Color_White     /**< Default color of Frame */
#define default_Screen_Color      Screen_Color_Black    /**< Default color of BackGround */
#ifdef Fast_Run_Test
#define	default_KEYINOUT_FUNC     KeyInOut_Func_ON   /**< Default key in/out function */
#else
 #if   default_Connect_Func_OnOff==Link_Function_ON
   #define	default_KEYINOUT_FUNC    KeyInOut_Func_OFF   /**< Default key in/out function */
 #elif default_Connect_Func_OnOff==Link_Function_OFF
   #define	default_KEYINOUT_FUNC     KeyInOut_Func_ON   /**< Default key in/out function */
 #endif
#endif
#define default_Scroll_Offset_Delta_Time_Slow           1/**< main game slot offset time slow */
#define default_Scroll_Offset_Delta_Pixel_Slow          5/**< main game slot offset pixel slow step 1 */
#define default_Scroll_Offset_Delta_Pixel_Step2_Slow    1/**< main game slot offset pixel slow step 2 */

#define default_Scroll_Offset_Delta_Time_Normal         1/**< main game slot offset time normal */
#define default_Scroll_Offset_Delta_Pixel_Normal       10/**< main game slot offset pixel normal step 1 */
#define default_Scroll_Offset_Delta_Pixel_Step2_Normal  1/**< main game slot offset pixel normal step 2 */

#define default_Scroll_Offset_Delta_Time_Fast           1/**< main game slot offset time fast */
#define default_Scroll_Offset_Delta_Pixel_Fast         20/**< main game slot offset pixel fast step 1 */
#define default_Scroll_Offset_Delta_Pixel_Step2_Fast    2/**< main game slot offset pixel fast step 2 */

/***** Probability Setting Data Default Value *****/

#define default_pro_MainPro               97/**< Default main game probability */
#define default_pro_MainPro_Link          97/**< Default main game probability(link function is on) */
#define default_pro_DoublePro             97/**< Default double game probability */
#define default_pro_JackPot1_Default    3000/**< Default JACKPOT 1 default */
#define default_pro_JackPot2_Default    2000/**< Default JACKPOT 2 default */
#define default_pro_JackPot3_Default    1000/**< Default JACKPOT 3 default */
#define default_pro_JackPot1_Max       15000/**< Default JACKPOT 1 max value */
#define default_pro_JackPot2_Max        5000/**< Default JACKPOT 2 max value */
#define default_pro_JackPot3_Max        3000/**< Default JACKPOT 3 max value */

/*** Bonus Setting Data Default Value ***/

#define  default_JokerOver4_OnOff            Bonu_Type_OFF/**< Default main game JokerOver4  On/Off setting */
#define  default_Blue7Over6_OnOff            Bonu_Type_OFF/**< Default main game Blue7Over6  On/Off setting */
#define  default_Red7Over6_OnOff             Bonu_Type_OFF/**< Default main game Red7Over6   On/Off setting */
#define  default_Bar3Over6_OnOff             Bonu_Type_OFF/**< Default main game Bar3Ov er6  On/Off setting */
#define  default_DDown_JokerX3_OnOff         Bonu_Type_OFF/**< Default double down JokerX3 On/Off setting */
#define  default_DDown_7PlusBlue7_OnOff      Bonu_Type_OFF/**< Default double down 7 and Blue 7 X3(including Joker) On/Off setting */

#define  default_JokerOver4_OnOff_link       Bonu_Type_OFF/**< Default main game JokerOver4  On/Off setting(when link) */
#define  default_Blue7Over6_OnOff_link       Bonu_Type_OFF/**< Default main game Blue7Over6  On/Off setting(when link) */
#define  default_Red7Over6_OnOff_link        Bonu_Type_OFF/**< Default main game Red7Over6   On/Off setting(when link) */
#define  default_Bar3Over6_OnOff_link        Bonu_Type_OFF/**< Default main game Bar3Ov er6  On/Off setting(when link) */
#define  default_DDown_JokerX3_OnOff_link    Bonu_Type_OFF/**< Default double down Joker X3 On/Off setting(when link) */
#define  default_DDown_7PlusBlue7_OnOff_link Bonu_Type_OFF/**< Default double down 7 and Blue 7 X3(including Joker) On/Off setting(when link) */

/*** Connect Setting Data Default Value ***/

#define default_Connect_Func_OnOff   Link_Function_OFF/**< Link function On/Off */
#define default_LINKID                               2/**< Link ID */
#define default_Max_id                              20/**< Max link count */

/*** width & height of each frame ***/
#if defined(PIC_ORIGINAL) || defined(PIC_OCEAN)
#define SINGLE_FRAME_WIDTH           240/**< Width of single frame */
#define SINGLE_FRAME_HEIGHT          154/**< Height of single frame */
#define DEF_OFFSET_LINE             1257/**< Default offset line when CGA ram clear */
#define DEF_OFFSET_RECT_Y            793/**< Default offset of Y axis */
#else
#define SINGLE_FRAME_WIDTH           236/**< Width of single frame */
#define SINGLE_FRAME_HEIGHT          156/**< Height of single frame */
#define DEF_OFFSET_LINE               50/**< Default offset line when CGA ram clear */
#define DEF_OFFSET_RECT_Y             50/**< Default offset of Y axis */
#endif
/*** ERROR TYPE DEFINE ***/

#define ERR_NONE	             0/**< None error */
#define ERR_COIN_IN	         1/**< Coin-in error */
#define ERR_COIN_OUT	         2/**< Coin-out error */
#define ERR_NO_COIN   	         3/**< No coin in coin-in */
#define ERR_SYS_OVER	         4/**< System Over */
#define ERR_DOUBLE_OVER	     5/**< Double Down Over */
#define ERR_MEMORY	             6/**< Memory error */
#define ERR_LINK_ID             7/**< Link id error */
#define ERR_LINK_COINVALUE      8/**< Link coin value error */
#define ERR_NO_LINK             9/**< Link break */
#define ERR_COIN_IN_LIMIT      10/**< Coin in limit error */
#define ERR_KEY_IN_LIMIT       11/**< Key in limit error */
#define ERR_HOPPER_MAX_PAY     12/**< Hopper max pay error */

/*** Password key input mapping define ***/

#define PWD_STOP1               1/**< Password of stop 1 key */
#define PWD_STOP2               2/**< Password of stop 2 key */
#define PWD_STOP3               3/**< Password of stop 3 key */
#define PWD_STOP4               4/**< Password of stop 4 key */
#define PWD_STOP5               5/**< Password of stop 5 key */
#define PWD_BIG                 6/**< Password of big key */
#define PWD_BEBA                7/**< Password of double up key */
#define PWD_SMALL               8/**< Password of small key */
#define PWD_START               9/**< Password of start key */
#define PWD_BET                 0/**< Password of bet key */

/***** Idol Information Appear Time *****/
#define IDLEINFO_APPEAR_TIME        90000/**< Time of idle appear */

#if defined(PIC_ORIGINAL) || defined(PIC_OCEAN)
#define SLOT_1_X  132+5/**< main game's slot 1 x position */
#define SLOT_1_Y   94+3/**< main game's slot 1 y position */

#define SLOT_2_X  387+5/**< main game's slot 2 x position */
#define SLOT_2_Y   94+3/**< main game's slot 2 y position */

#define SLOT_3_X  642+5/**< main game's slot 3 x position */
#define SLOT_3_Y   94+3/**< main game's slot 3 y position */

#define SLOT_4_X  132+5/**< main game's slot 4 x position */
#define SLOT_4_Y  259+3/**< main game's slot 4 y position */

#define SLOT_5_X  387+5/**< main game's slot 5 x position */
#define SLOT_5_Y  259+3/**< main game's slot 5 y position */

#define SLOT_6_X  642+5/**< main game's slot 6 x position */
#define SLOT_6_Y  259+3/**< main game's slot 6 y position */

#define SLOT_7_X  132+5/**< main game's slot 7 x position */
#define SLOT_7_Y  424+3/**< main game's slot 7 y position */

#define SLOT_8_X  387+5/**< main game's slot 8 x position */
#define SLOT_8_Y  424+3/**< main game's slot 8 y position */

#define SLOT_9_X  642+5/**< main game's slot 9 x position */
#define SLOT_9_Y  424+3/**< main game's slot 9 y position */
#else
#define SLOT_1_X   135/**< main game's slot 1 x position */
#define SLOT_1_Y   157/**< main game's slot 1 y position */

#define SLOT_2_X   383/**< main game's slot 2 x position */
#define SLOT_2_Y   157/**< main game's slot 2 y position */

#define SLOT_3_X   631/**< main game's slot 3 x position */
#define SLOT_3_Y   157/**< main game's slot 3 y position */

#define SLOT_4_X   135/**< main game's slot 4 x position */
#define SLOT_4_Y   325/**< main game's slot 4 y position */

#define SLOT_5_X   383/**< main game's slot 5 x position */
#define SLOT_5_Y   325/**< main game's slot 5 y position */

#define SLOT_6_X   631/**< main game's slot 6 x position */
#define SLOT_6_Y   325/**< main game's slot 6 y position */

#define SLOT_7_X   135/**< main game's slot 7 x position */
#define SLOT_7_Y   493/**< main game's slot 7 y position */

#define SLOT_8_X   383/**< main game's slot 8 x position */
#define SLOT_8_Y   493/**< main game's slot 8 y position */

#define SLOT_9_X   631/**< main game's slot 9 x position */
#define SLOT_9_Y   493/**< main game's slot 9 y position */
#endif

#define Frame_1_PIC   1/**< main game's slot(frame) 1 image index */
#define Frame_2_PIC   2/**< main game's slot(frame) 2 image index */
#define Frame_3_PIC   3/**< main game's slot(frame) 3 image index */
#define Frame_4_PIC   4/**< main game's slot(frame) 4 image index */
#define Frame_5_PIC   5/**< main game's slot(frame) 5 image index */
#define Frame_6_PIC   4/**< main game's slot(frame) 6 image index */
#define Frame_7_PIC   3/**< main game's slot(frame) 7 image index */
#define Frame_8_PIC   2/**< main game's slot(frame) 8 image index */
#define Frame_9_PIC   1/**< main game's slot(frame) 9 image index */

#define MG_CREDITS_UP_X  767/**< main game's credits up x position */
#define MG_CREDITS_UP_Y  659/**< main game's credits up y position */

#define MG_CREDITS_X 831/**< main game's credits x position */
#define MG_CREDITS_Y 659/**< main game's credits y position */

#define MG_WAGER_X   31/**< main game's wager x position */
#define MG_WAGER_Y  659/**< main game's wager y position */

#define MG_WIN_X     31/**< main game's win x position */
#define MG_WIN_Y    684/**< main game's win y position */

#define MG_PAID_X    31/**< main game's paid x position */
#define MG_PAID_Y   710/**< main game's paid y position */

#define MG_SAVE_X    31/**< main game's save x position */
#define MG_SAVE_Y   710/**< main game's save y position */

#define KEY_COIN_OUT_X    740/**< main game's key/coin out x position */
#define KEY_COIN_OUT_Y    710/**< main game's key/coin out y position */

//Credits Information Position
#if defined(PIC_ORIGINAL) || defined(PIC_OCEAN)
#define MG_CREDITS_NUM_POS_X   971/**< main game's credits number x position */
#define MG_CREDITS_NUM_POS_Y   683/**< main game's credits number y position */

#define MG_WAGER_NUM_POS_X     194/**< main game's wager number x position */
#define MG_WAGER_NUM_POS_Y     658/**< main game's wager number y position */

#define MG_WIN_NUM_POS_X       194/**< main game's win number x position */
#define MG_WIN_NUM_POS_Y       683/**< main game's win number y position */

//#define SAVE_NUM_POS_X      194/**< main game's save number x position */
//#define SAVE_NUM_POS_Y      708/**< main game's save number y position */

#define MG_PAID_NUM_POS_X      194/**< main game's paid number x position */
#define MG_PAID_NUM_POS_Y      708/**< main game's paid number y position */

#define KEY_COIN_OUT_NUM_POS_X   971/**< main game's key/coin out number x position */
#define KEY_COIN_OUT_NUM_POS_Y   708/**< main game's key/coin out number y position */
#else

#define PIC_INDEX_CREDIT_NUMBER     66/**< picture index of credit number */
    #define PIC_CREDIT_NUMBER_ONE_DIGIT_WIDTH      25/**< width of credit number one digit */
#define PIC_INDEX_WAGER_NUMBER      66/**< picture index of wager number */
    #define PIC_WAGER_NUMBER_ONE_DIGIT_WIDTH       25/**< width of wager number one digit */
#define PIC_INDEX_WIN_NUMBER        66/**< picture index of win number */
    #define PIC_WIN_NUMBER_ONE_DIGIT_WIDTH         25/**< width of win number one digit */
#define PIC_INDEX_PAID_NUMBER       66/**< picture index of paid number */
    #define PIC_PAID_NUMBER_ONE_DIGIT_WIDTH        25/**< width of paid number one digit */
#define PIC_INDEX_KEYINOUT_NUMBER   50/**< picture index of keyin/out number */
    #define PIC_KEYINOUT_NUMBER_ONE_DIGIT_WIDTH    25/**< width of keyin/out number one digit */

#define MG_CREDITS_NUM_POS_X   955/**< main game's credits number x position */
#define MG_CREDITS_NUM_POS_Y   722/**< main game's credits number y position */

#define MG_WAGER_NUM_POS_X     539/**< main game's wager number x position */
#define MG_WAGER_NUM_POS_Y     722/**< main game's wager number y position */

#define MG_WIN_NUM_POS_X       293/**< main game's win number x position */
#define MG_WIN_NUM_POS_Y       722/**< main game's win number y position */

#define MG_PAID_NUM_POS_X      194/**< main game's paid number x position */
#define MG_PAID_NUM_POS_Y      708/**< main game's paid number y position */

#define KEY_COIN_OUT_NUM_POS_X   640/**< main game's key/coin out number x position */
#define KEY_COIN_OUT_NUM_POS_Y   670/**< main game's key/coin out number y position */
#endif

//Main Game Each Line & Each Item Wager Information
#if defined(PIC_ORIGINAL) || defined(PIC_OCEAN)
#define LINE_1_WAGER_INFO_X  37+25/**< main game's line 1 wager x position  */
#define LINE_1_WAGER_INFO_Y    322/**< main game's line 1 wager y position */
#define LINE_1_WAGER_INFO_N     15/**< main game's line 1 image index */

#define LINE_2_WAGER_INFO_X  37+25/**< main game's line 2 wager x position */
#define LINE_2_WAGER_INFO_Y    487/**< main game's line 2 wager y position */
#define LINE_2_WAGER_INFO_N     15/**< main game's line 2 image index */

#define LINE_3_WAGER_INFO_X  37+25/**< main game's line 3 wager x position */
#define LINE_3_WAGER_INFO_Y    157/**< main game's line 3 wager y position */
#define LINE_3_WAGER_INFO_N     15/**< main game's line 3 image index */

#define LINE_4_WAGER_INFO_X  37+25/**< main game's line 4 wager x position */
#define LINE_4_WAGER_INFO_Y    591/**< main game's line 4 wager y position */
#define LINE_4_WAGER_INFO_N     15/**< main game's line 4 image index */

#define LINE_5_WAGER_INFO_X  37+25/**< main game's line 5 wager x position */
#define LINE_5_WAGER_INFO_Y     51/**< main game's line 5 wager y position */
#define LINE_5_WAGER_INFO_N     15/**< main game's line 5 image index */

#define LINE_6_WAGER_INFO_X  232+25/**< main game's line 6 wager x position */
#define LINE_6_WAGER_INFO_Y      47/**< main game's line 6 wager y position */
#define LINE_6_WAGER_INFO_N      15/**< main game's line 6 image index */

#define LINE_7_WAGER_INFO_X  487+25/**< main game's line 7 wager x position */
#define LINE_7_WAGER_INFO_Y      47/**< main game's line 7 wager y position */
#define LINE_7_WAGER_INFO_N      15/**< main game's line 7 image index */

#define LINE_8_WAGER_INFO_X  742+25/**< main game's line 8 wager x position */
#define LINE_8_WAGER_INFO_Y      47/**< main game's line 8 wager y position */
#define LINE_8_WAGER_INFO_N      15/**< main game's line 8 image index */

#define ITEM_1_WAGER_INFO_X  968+13/**< main game's item 1 wager x position */
#define ITEM_1_WAGER_INFO_Y     555/**< main game's item 1 wager y position */
#define ITEM_1_WAGER_INFO_N      16/**< main game's item 1 wager image index */

#define ITEM_2_WAGER_INFO_X  968+13/**< main game's item 2 wager x position */
#define ITEM_2_WAGER_INFO_Y     497/**< main game's item 2 wager y position */
#define ITEM_2_WAGER_INFO_N      16/**< main game's item 2 wager image index */

#define ITEM_3_WAGER_INFO_X  968+13/**< main game's item 3 wager x position */
#define ITEM_3_WAGER_INFO_Y     439/**< main game's item 3 wager y position */
#define ITEM_3_WAGER_INFO_N      16/**< main game's item 3 wager image index */

#define ITEM_4_WAGER_INFO_X  968+13/**< main game's item 4 wager x position */
#define ITEM_4_WAGER_INFO_Y     381/**< main game's item 4 wager y position */
#define ITEM_4_WAGER_INFO_N      16/**< main game's item 4 wager image index */

#define ITEM_5_WAGER_INFO_X  968+13/**< main game's item 5 wager x position */
#define ITEM_5_WAGER_INFO_Y     323/**< main game's item 5 wager y position */
#define ITEM_5_WAGER_INFO_N      16/**< main game's item 5 wager image index */

#define ITEM_6_WAGER_INFO_X  968+13/**< main game's item 6 wager x position */
#define ITEM_6_WAGER_INFO_Y     265/**< main game's item 6 wager y position */
#define ITEM_6_WAGER_INFO_N      16/**< main game's item 6 wager image index */

#define ITEM_7_WAGER_INFO_X  968+13/**< main game's item 7 wager x position */
#define ITEM_7_WAGER_INFO_Y     207/**< main game's item 7 wager y position */
#define ITEM_7_WAGER_INFO_N      16/**< main game's item 7 wager image index */

#define ITEM_8_WAGER_INFO_X  968+13/**< main game's item 8 wager x position */
#define ITEM_8_WAGER_INFO_Y     149/**< main game's item 8 wager y position */
#define ITEM_8_WAGER_INFO_N      16/**< main game's item 8 wager image index */
#else
#define LINE_1_WAGER_INFO_X     84/**< main game's line 1 wager x position  */
#define LINE_1_WAGER_INFO_Y    388/**< main game's line 1 wager y position */
#define LINE_1_WAGER_INFO_N     67/**< main game's line 1 image index */

#define LINE_2_WAGER_INFO_X     84/**< main game's line 3 wager x position */
#define LINE_2_WAGER_INFO_Y    220/**< main game's line 3 wager y position */
#define LINE_2_WAGER_INFO_N     67/**< main game's line 3 image index */

#define LINE_3_WAGER_INFO_X     84/**< main game's line 2 wager x position */
#define LINE_3_WAGER_INFO_Y    556/**< main game's line 2 wager y position */
#define LINE_3_WAGER_INFO_N     67/**< main game's line 2 image index */

#define LINE_4_WAGER_INFO_X     84/**< main game's line 5 wager x position */
#define LINE_4_WAGER_INFO_Y    115/**< main game's line 5 wager y position */
#define LINE_4_WAGER_INFO_N     67/**< main game's line 5 image index */

#define LINE_5_WAGER_INFO_X     84/**< main game's line 4 wager x position */
#define LINE_5_WAGER_INFO_Y    660/**< main game's line 4 wager y position */
#define LINE_5_WAGER_INFO_N     67/**< main game's line 4 image index */

#define LINE_6_WAGER_INFO_X     268/**< main game's line 6 wager x position */
#define LINE_6_WAGER_INFO_Y     115/**< main game's line 6 wager y position */
#define LINE_6_WAGER_INFO_N      67/**< main game's line 6 image index */

#define LINE_7_WAGER_INFO_X     518/**< main game's line 7 wager x position */
#define LINE_7_WAGER_INFO_Y     115/**< main game's line 7 wager y position */
#define LINE_7_WAGER_INFO_N      67/**< main game's line 7 image index */

#define LINE_8_WAGER_INFO_X     765/**< main game's line 8 wager x position */
#define LINE_8_WAGER_INFO_Y     115/**< main game's line 8 wager y position */
#define LINE_8_WAGER_INFO_N      67/**< main game's line 8 image index */

#define ITEM_1_WAGER_INFO_X     994/**< main game's item 1 wager x position */
#define ITEM_1_WAGER_INFO_Y     681/**< main game's item 1 wager y position */
#define ITEM_1_WAGER_INFO_N      16/**< main game's item 1 wager image index */

#define ITEM_2_WAGER_INFO_X     994/**< main game's item 2 wager x position */
#define ITEM_2_WAGER_INFO_Y     604/**< main game's item 2 wager y position */
#define ITEM_2_WAGER_INFO_N      16/**< main game's item 2 wager image index */

#define ITEM_3_WAGER_INFO_X     994/**< main game's item 3 wager x position */
#define ITEM_3_WAGER_INFO_Y     527/**< main game's item 3 wager y position */
#define ITEM_3_WAGER_INFO_N      16/**< main game's item 3 wager image index */

#define ITEM_4_WAGER_INFO_X     994/**< main game's item 4 wager x position */
#define ITEM_4_WAGER_INFO_Y     451/**< main game's item 4 wager y position */
#define ITEM_4_WAGER_INFO_N      16/**< main game's item 4 wager image index */

#define ITEM_5_WAGER_INFO_X     994/**< main game's item 5 wager x position */
#define ITEM_5_WAGER_INFO_Y     374/**< main game's item 5 wager y position */
#define ITEM_5_WAGER_INFO_N      16/**< main game's item 5 wager image index */

#define ITEM_6_WAGER_INFO_X     994/**< main game's item 6 wager x position */
#define ITEM_6_WAGER_INFO_Y     297/**< main game's item 6 wager y position */
#define ITEM_6_WAGER_INFO_N      16/**< main game's item 6 wager image index */

#define ITEM_7_WAGER_INFO_X     994/**< main game's item 7 wager x position */
#define ITEM_7_WAGER_INFO_Y     220/**< main game's item 7 wager y position */
#define ITEM_7_WAGER_INFO_N      16/**< main game's item 7 wager image index */

#define ITEM_8_WAGER_INFO_X     994/**< main game's item 8 wager x position */
#define ITEM_8_WAGER_INFO_Y     143/**< main game's item 8 wager y position */
#define ITEM_8_WAGER_INFO_N      16/**< main game's item 8 wager image index */
#endif

#if defined(PIC_ORIGINAL) || defined(PIC_OCEAN)
#define MAIN_INFO_X  289/**< main game's information x position */
#define MAIN_INFO_Y  660/**< main game's information y position */
#else
#define MAIN_INFO_X  187/**< main game's information x position */
#define MAIN_INFO_Y  670/**< main game's information y position */
#endif

#ifdef PIC_FRUIT
#define PIC_HINT_ALL               23/**< picture index of hint_all */
#define TOTAL_INDEX_HINT_ALL       12/**< total index of hint_all */
#define INDEX_PLEASE_INSERT_COIN    0/**< internal index of please insert coin,bet or start */
#define INDEX_BET_OR_START          1/**< internal index of bet or start */
#define INDEX_DOUBLE_OR_COLLECT     2/**< internal index of double or collect */
#define INDEX_DOUBLE_HALF           3/**< internal index of double half or collect */
#define INDEX_GAME_OVER             4/**< internal index of game over */
#define INDEX_GOOD_LUCK             5/**< internal index of good luck */
#define INDEX_PUSH                  6/**< internal index of push! */
#define INDEX_SELECT_A_REEL         7/**< internal index of select a reel */
#define INDEX_WINNER                8/**< internal index of winner! */
#define INDEX_CONGRATULATIONS       9/**< internal index of congratulations! */
#define INDEX_YOU_WON_THE_JACKPOT  10/**< internal index of you won the jackpot!! */
#define INDEX_PAID                 11/**< internal index of paid */
#endif

#if defined(PIC_ORIGINAL) || defined(PIC_OCEAN)

#define CREDITS_UP_X  767/**< double game's credits up x position */
#define CREDITS_UP_Y  659/**< double game's credits up y position */

#define CREDITS_X 831/**< double game's credits x position */
#define CREDITS_Y 659/**< double game's credits y position */

#define WAGER_X   31/**< double game's wager x position */
#define WAGER_Y  659/**< double game's wager y position */

#define WIN_X     31/**< double game's win x position */
#define WIN_Y    684/**< double game's win y position */

#define PAID_X    31/**< double game's paid x position */
#define PAID_Y   710/**< double game's paid y position */

#define SAVE_X    31/**< double game's save x position */
#define SAVE_Y   710/**< double game's save y position */

#define SLOT_WIN_X  848/**< double game's slot win x position */
#define SLOT_WIN_Y  144/**< double game's slot win y position */

#define COLLECTABLE_X  848/**< double game's collectable x position */
#define COLLECTABLE_Y  165/**< double game's collectable y position */

#define TRY_LUCKY_X  848/**< double game's try lucky x position */
#define TRY_LUCKY_Y  186/**< double game's try lucky y position */

#define TRY_LUCKY_TIMES_X   595/**< double game's try lucky times x position */
#define TRY_LUCKY_TIMES_Y   186/**< double game's try lucky times y position */

#define CREDITS_NUM_POS_X   971/**< double game's credit number x position */
#define CREDITS_NUM_POS_Y   683/**< double game's credit number y position */

#define WAGER_NUM_POS_X     194/**< double game's wager number x position */
#define WAGER_NUM_POS_Y     658/**< double game's wager number y position */

#define WIN_NUM_POS_X       194/**< double game's win number x position */
#define WIN_NUM_POS_Y       683/**< double game's win number y position */

#define SAVE_NUM_POS_X      194/**< double game's save number x position */
#define SAVE_NUM_POS_Y      708/**< double game's save number y position */

#define PAID_NUM_POS_X      194/**< double game's paid number x position */
#define PAID_NUM_POS_Y      708/**< double game's paid number y position */

#define SLOT_PLAY_X         674/**< double game's slot play x position */
#define SLOT_PLAY_Y         259/**< double game's slot play y position */

#define DOUBLE_INFO_X       669/**< double game's first time information x position */
#define DOUBLE_INFO_Y       259/**< double game's first time information y position */

#define PLAYER_SELECT_LEFT_X     187/**< double game's select left x position */
#define PLAYER_SELECT_LEFT_Y     592/**< double game's select left y position */

#define PLAYER_SELECT_CENTER_X   442/**< double game's select middle x position */
#define PLAYER_SELECT_CENTER_Y   592/**< double game's select middle y position */

#define PLAYER_SELECT_RIGHT_X    697/**< double game's select right x position */
#define PLAYER_SELECT_RIGHT_Y    592/**< double game's select right y position */

#define HALF_DOUBLE_X       230/**< double game's half x position */
#define HALF_DOUBLE_Y       708/**< double game's half y position */

#define SLOT_PIC_1_X        674/**< double game's mini-slot 1 x position */
#define SLOT_PIC_1_Y        275/**< double game's mini-slot 1 y position */

#define SLOT_PIC_2_X        737/**< double game's mini-slot 2 x position */
#define SLOT_PIC_2_Y        275/**< double game's mini-slot 2 y position */

#define SLOT_PIC_3_X        800/**< double game's mini-slot 3 x position */
#define SLOT_PIC_3_Y        275/**< double game's mini-slot 3 y position */

#define SLOT_PIC_4_X        674/**< double game's mini-slot 4 x position */
#define SLOT_PIC_4_Y        318/**< double game's mini-slot 4 y position */

#define SLOT_PIC_5_X        737/**< double game's mini-slot 5 x position */
#define SLOT_PIC_5_Y        318/**< double game's mini-slot 5 y position */

#define SLOT_PIC_6_X        800/**< double game's mini-slot 6 x position */
#define SLOT_PIC_6_Y        318/**< double game's mini-slot 6 y position */

#define SLOT_PIC_7_X        674/**< double game's mini-slot 7 x position */
#define SLOT_PIC_7_Y        361/**< double game's mini-slot 7 y position */

#define SLOT_PIC_8_X        737/**< double game's mini-slot 8 x position */
#define SLOT_PIC_8_Y        361/**< double game's mini-slot 8 y position */

#define SLOT_PIC_9_X        800/**< double game's mini-slot 9 x position */
#define SLOT_PIC_9_Y        361/**< double game's mini-slot 9 y position */

#define SP_LIST_1_X         174/**< double game's special bonus list 1 x position */
#define SP_LIST_1_Y         322/**< double game's special bonus list 1 y position */

#define SP_LIST_2_X         174/**< double game's special bonus list 2 x position */
#define SP_LIST_2_Y         292/**< double game's special bonus list 2 y position */

#define SP_LIST_3_X         174/**< double game's special bonus list 3 x position */
#define SP_LIST_3_Y         262/**< double game's special bonus list 3 y position */

#define SP_LIST_4_X         174/**< double game's special bonus list 4 x position */
#define SP_LIST_4_Y         232/**< double game's special bonus list 4 y position */

#define SP_LIST_5_X         174/**< double game's special bonus list 5 x position */
#define SP_LIST_5_Y         202/**< double game's special bonus list 5 y position */

#define SP_LIST_6_X         174/**< double game's special bonus list 6 x position */
#define SP_LIST_6_Y         172/**< double game's special bonus list 6 y position */

#define SP_LIST_7_X         174/**< double game's special bonus list 7 x position */
#define SP_LIST_7_Y         142/**< double game's special bonus list 7 y position */

#define SP_LIST_1_NUM_X     340/**< double game's special bonus list number 1 x position */
#define SP_LIST_1_NUM_Y     328/**< double game's special bonus list number 1 y position */

#define SP_LIST_2_NUM_X     340/**< double game's special bonus list number 2 x position */
#define SP_LIST_2_NUM_Y     298/**< double game's special bonus list number 2 y position */

#define SP_LIST_3_NUM_X     340/**< double game's special bonus list number 3 x position */
#define SP_LIST_3_NUM_Y     268/**< double game's special bonus list number 3 y position */

#define SP_LIST_4_NUM_X     340/**< double game's special bonus list number 4 x position */
#define SP_LIST_4_NUM_Y     238/**< double game's special bonus list number 4 y position */

#define SP_LIST_5_NUM_X     340/**< double game's special bonus list number 5 x position */
#define SP_LIST_5_NUM_Y     208/**< double game's special bonus list number 5 y position */

#define SP_LIST_6_NUM_X     340/**< double game's special bonus list number 6 x position */
#define SP_LIST_6_NUM_Y     178/**< double game's special bonus list number 6 y position */

#define SP_LIST_7_NUM_X     340/**< double game's special bonus list number 7 x position */
#define SP_LIST_7_NUM_Y     148/**< double game's special bonus list number 7 y position */

#define DG_INFO_X           289/**< double game's information x position */
#define DG_INFO_Y           660/**< double game's information y position */

#define DG_SLOT_1_X       387+5/**< double game's slot 1 x position */
#define DG_SLOT_1_Y       259+3/**< double game's slot 1 y position */

#define DG_SLOT_2_X       132+5/**< double game's slot 2 x position */
#define DG_SLOT_2_Y       424+3/**< double game's slot 2 y position */

#define DG_SLOT_3_X       387+5/**< double game's slot 3 x position */
#define DG_SLOT_3_Y       424+3/**< double game's slot 3 y position */

#define DG_SLOT_4_X       642+5/**< double game's slot 4 x position */
#define DG_SLOT_4_Y       424+3/**< double game's slot 4 y position */

#else

#define CREDITS_UP_X  767/**< double game's credits up x position */
#define CREDITS_UP_Y  659/**< double game's credits up y position */

#define CREDITS_X 831/**< double game's credits x position */
#define CREDITS_Y 659/**< double game's credits y position */

#define WAGER_X   31/**< double game's wager x position */
#define WAGER_Y  659/**< double game's wager y position */

#define WIN_X     31/**< double game's win x position */
#define WIN_Y    684/**< double game's win y position */

#define PAID_X    31/**< double game's paid x position */
#define PAID_Y   710/**< double game's paid y position */

#define SAVE_X    31/**< double game's save x position */
#define SAVE_Y   710/**< double game's save y position */

#define SLOT_WIN_X  837/**< double game's slot win x position */
#define SLOT_WIN_Y  128/**< double game's slot win y position */

#define COLLECTABLE_X  837/**< double game's collectable x position */
#define COLLECTABLE_Y  165/**< double game's collectable y position */

#define TRY_LUCKY_X  837/**< double game's try lucky x position */
#define TRY_LUCKY_Y  201/**< double game's try lucky y position */

#define TRY_LUCKY_TIMES_X   589/**< double game's try lucky times x position */
#define TRY_LUCKY_TIMES_Y   205/**< double game's try lucky times y position */

#define CREDITS_NUM_POS_X   955/**< double game's credit number x position */
#define CREDITS_NUM_POS_Y   722/**< double game's credit number y position */

#define WAGER_NUM_POS_X     539/**< double game's wager number x position */
#define WAGER_NUM_POS_Y     722/**< double game's wager number y position */

#define WIN_NUM_POS_X       293/**< double game's win number x position */
#define WIN_NUM_POS_Y       722/**< double game's win number y position */

#define SAVE_NUM_POS_X      837/**< double game's save number x position */
#define SAVE_NUM_POS_Y      238/**< double game's save number y position */

#define PAID_NUM_POS_X      194/**< double game's paid number x position */
#define PAID_NUM_POS_Y      708/**< double game's paid number y position */

#define DG_PIC_INDEX_CREDIT_NUMBER                          66/**< picture index of credit number */
#define DG_PIC_CREDIT_NUMBER_ONE_DIGIT_WIDTH                25/**< width of credit number one digit */

#define DG_PIC_INDEX_WAGER_NUMBER                           66/**< picture index of wager number */
#define DG_PIC_WAGER_NUMBER_ONE_DIGIT_WIDTH                 25/**< width of wager number one digit */

#define DG_PIC_INDEX_WIN_NUMBER                             66/**< picture index of win number */
#define DG_PIC_WIN_NUMBER_ONE_DIGIT_WIDTH                   25/**< width of win number one digit */

#define DG_PIC_INDEX_SLOT_WIN_NUMBER                        66/**< picture index of slot win number */
#define DG_PIC_SLOT_WIN_NUMBER_ONE_DIGIT_WIDTH              25/**< width of slot win number one digit */

#define DG_PIC_INDEX_COLLECTABLE_NUMBER                     49/**< picture index of collectable number */
#define DG_PIC_COLLECTABLE_NUMBER_ONE_DIGIT_WIDTH           25/**< width of collectable number one digit */

#define DG_PIC_INDEX_TRY_LUCKY_TIMES_NUMBER                 69/**< picture index of try lucky times number */
#define DG_PIC_TRY_LUCKY_TIMES_NUMBER_ONE_DIGIT_WIDTH       22/**< width of try lucky times number one digit */

#define DG_PIC_INDEX_TRY_LUCKY_NUMBER                       50/**< picture index of try lucky number */
#define DG_PIC_TRY_LUCKY_NUMBER_ONE_DIGIT_WIDTH             25/**< width of try lucky number one digit */

#define DG_PIC_INDEX_SAVE_NUMBER                            48/**< picture index of save number */
#define DG_PIC_SAVE_NUMBER_ONE_DIGIT_WIDTH                  25/**< width of save number one digit */

#define DG_PIC_INDEX_SP_NUMBER                              70/**< picture index of special number */
#define DG_PIC_SP_NUMBER_ONE_DIGIT_WIDTH                    22/**< width of special number one digit */

#define SLOT_PLAY_X         630/**< double game's slot play x position */
#define SLOT_PLAY_Y         298/**< double game's slot play y position */

#define DOUBLE_INFO_X       629/**< double game's first time information x position */
#define DOUBLE_INFO_Y       323/**< double game's first time information y position */

#define PLAYER_SELECT_LEFT_X     191/**< double game's select left x position */
#define PLAYER_SELECT_LEFT_Y     630/**< double game's select left y position */

#define PLAYER_SELECT_CENTER_X   439/**< double game's select middle x position */
#define PLAYER_SELECT_CENTER_Y   630/**< double game's select middle y position */

#define PLAYER_SELECT_RIGHT_X    687/**< double game's select right x position */
#define PLAYER_SELECT_RIGHT_Y    630/**< double game's select right y position */

#define HALF_DOUBLE_X       684/**< double game's half x position */
#define HALF_DOUBLE_Y       274/**< double game's half y position */

#define SLOT_PIC_1_X        632/**< double game's mini-slot 1 x position */
#define SLOT_PIC_1_Y        326/**< double game's mini-slot 1 y position */

#define SLOT_PIC_2_X        714/**< double game's mini-slot 2 x position */
#define SLOT_PIC_2_Y        326/**< double game's mini-slot 2 y position */

#define SLOT_PIC_3_X        792/**< double game's mini-slot 3 x position */
#define SLOT_PIC_3_Y        326/**< double game's mini-slot 3 y position */

#define SLOT_PIC_4_X        632/**< double game's mini-slot 4 x position */
#define SLOT_PIC_4_Y        380/**< double game's mini-slot 4 y position */

#define SLOT_PIC_5_X        714/**< double game's mini-slot 5 x position */
#define SLOT_PIC_5_Y        380/**< double game's mini-slot 5 y position */

#define SLOT_PIC_6_X        792/**< double game's mini-slot 6 x position */
#define SLOT_PIC_6_Y        380/**< double game's mini-slot 6 y position */

#define SLOT_PIC_7_X        632/**< double game's mini-slot 7 x position */
#define SLOT_PIC_7_Y        433/**< double game's mini-slot 7 y position */

#define SLOT_PIC_8_X        714/**< double game's mini-slot 8 x position */
#define SLOT_PIC_8_Y        433/**< double game's mini-slot 8 y position */

#define SLOT_PIC_9_X        792/**< double game's mini-slot 9 x position */
#define SLOT_PIC_9_Y        433/**< double game's mini-slot 9 y position */

#define SP_LIST_1_X         192/**< double game's special bonus list 1 x position */
#define SP_LIST_1_Y         378/**< double game's special bonus list 1 y position */

#define SP_LIST_2_X         192/**< double game's special bonus list 2 x position */
#define SP_LIST_2_Y         337/**< double game's special bonus list 2 y position */

#define SP_LIST_3_X         192/**< double game's special bonus list 3 x position */
#define SP_LIST_3_Y         296/**< double game's special bonus list 3 y position */

#define SP_LIST_4_X         192/**< double game's special bonus list 4 x position */
#define SP_LIST_4_Y         255/**< double game's special bonus list 4 y position */

#define SP_LIST_5_X         192/**< double game's special bonus list 5 x position */
#define SP_LIST_5_Y         214/**< double game's special bonus list 5 y position */

#define SP_LIST_6_X         192/**< double game's special bonus list 6 x position */
#define SP_LIST_6_Y         173/**< double game's special bonus list 6 y position */

#define SP_LIST_7_X         192/**< double game's special bonus list 7 x position */
#define SP_LIST_7_Y         132/**< double game's special bonus list 7 y position */

#define SP_LIST_1_NUM_X     347/**< double game's special bonus list number 1 x position */
#define SP_LIST_1_NUM_Y     378/**< double game's special bonus list number 1 y position */

#define SP_LIST_2_NUM_X     347/**< double game's special bonus list number 2 x position */
#define SP_LIST_2_NUM_Y     337/**< double game's special bonus list number 2 y position */

#define SP_LIST_3_NUM_X     347/**< double game's special bonus list number 3 x position */
#define SP_LIST_3_NUM_Y     296/**< double game's special bonus list number 3 y position */

#define SP_LIST_4_NUM_X     347/**< double game's special bonus list number 4 x position */
#define SP_LIST_4_NUM_Y     255/**< double game's special bonus list number 4 y position */

#define SP_LIST_5_NUM_X     347/**< double game's special bonus list number 5 x position */
#define SP_LIST_5_NUM_Y     214/**< double game's special bonus list number 5 y position */

#define SP_LIST_6_NUM_X     347/**< double game's special bonus list number 6 x position */
#define SP_LIST_6_NUM_Y     173/**< double game's special bonus list number 6 y position */

#define SP_LIST_7_NUM_X     347/**< double game's special bonus list number 7 x position */
#define SP_LIST_7_NUM_Y     132/**< double game's special bonus list number 7 y position */

#define DG_INFO_X           187/**< double game's information x position */
#define DG_INFO_Y           670/**< double game's information y position */

#define DG_SLOT_1_X         383/**< double game's slot 1 x position */
#define DG_SLOT_1_Y         325/**< double game's slot 1 y position */

#define DG_SLOT_2_X         135/**< double game's slot 2 x position */
#define DG_SLOT_2_Y         493/**< double game's slot 2 y position */

#define DG_SLOT_3_X         383/**< double game's slot 3 x position */
#define DG_SLOT_3_Y         493/**< double game's slot 3 y position */

#define DG_SLOT_4_X         631/**< double game's slot 4 x position */
#define DG_SLOT_4_Y         493/**< double game's slot 4 y position */

#endif


#endif /* GAMEDEFINE_H_ */

