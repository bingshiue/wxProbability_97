/**
 * @file gameLogicType.h
 * @brief Declare game logic structure type.
 *
 */

#ifndef GAMELOGICTYPE_H_
#define GAMELOGICTYPE_H_

extern unsigned int  MaingameProM[3][15][7];
extern unsigned int  MaingameProDownM[5][7];
extern unsigned int  MaingameProUpM[5][7];
extern unsigned int  LinkMaingameProM[3][5][15];
extern unsigned int  LineBingoTypeM[9];
extern unsigned int  LineAwardTypeOddsMapping[13];
extern unsigned long FullFrameAwardTypeMapping[11][10];/**< 97 type full frame award mapping table */
extern unsigned int  DoUpM[6][2];
extern unsigned int  DoDownM[6][2];

using namespace std;
#include <iostream>
#include <map>
#include <string>
#include "../preprocessor/preprocessor.h"
/*
#ifndef __arm__
#include "../opengl/gltexture2d.h"
#else
#include "../opengles/gltexture2d.h"
#endif
*/
#include "../mersenne_twister/mt_random.h"
#include "../probability/probabilityDefine.h"
#include "../probability/probabilityEnum.h"
#include "../probability/probabilityType.h"
#include "gameSettingValueType.h"
#include "gameUtility.h"

/*
extern SPRITESHEETOBJECT slot1;
extern SPRITESHEETOBJECT slot2;
extern SPRITESHEETOBJECT slot3;
extern SPRITESHEETOBJECT slot4;
extern SPRITESHEETOBJECT slot5;
extern SPRITESHEETOBJECT slot_move;
extern SPRITESHEETOBJECT slot_item_cherry;
extern SPRITESHEETOBJECT slot_item_orange;
extern SPRITESHEETOBJECT slot_item_mango;
extern SPRITESHEETOBJECT slot_item_bell;
extern SPRITESHEETOBJECT slot_item_watermelon;
extern SPRITESHEETOBJECT slot_item_bar_yellow;
extern SPRITESHEETOBJECT slot_item_bar_red;
extern SPRITESHEETOBJECT slot_item_bar_blue;
extern SPRITESHEETOBJECT slot_item_seven;
extern SPRITESHEETOBJECT slot_item_wild;
*/

#ifdef DEBUG_OUTPUT_AWARD_DETAIL
//std::map<string,unsigned long> lineAwardRecord;
static std::map<string,unsigned long> fullAwardRecordMap;
#endif

/**
 * @brief Structure of Rectangle.
 */
typedef struct Rectangle{
	unsigned int x;/**< X position */
	unsigned int y;/**< Y position */
	unsigned int w;/**< Rectangle width */
	unsigned int h;/**< Rectangle height */

	/**
	 * @brief Constructor.
	 */
	Rectangle(){
		this->x=0;
		this->y=0;
		this->w=0;
		this->h=0;
	}

	/**
	 * @brief Constructor.
	 * @param _x X position
	 * @param _y Y position
	 * @param _w Width
	 * @param _h Height
	 */
	Rectangle(unsigned int _x,unsigned int _y,unsigned int _w,unsigned int _h){
		this->x=_x;
		this->y=_y;
		this->w=_w;
		this->h=_h;
	}
	/**
	 * @brief Set rectangle.
	 * @param _x X position
	 * @param _y Y position
	 * @param _w Width
	 * @param _h Height
	 */
	void setRectangle(unsigned int _x,unsigned int _y,unsigned int _w,unsigned int _h){
		this->x=_x;
		this->y=_y;
		this->w=_w;
		this->h=_h;
	}

}RECTANGLE;

/**
 * @brief Game's parameter about coins(credits,wager,win,save,paid etc...).
 */
typedef struct GameCredits{
   unsigned long credits;/**< Game's credits */
   unsigned long wager;/**< Game's wager */
   unsigned long win;/**< Game's win */
   unsigned long save;/**< Game's save */
   unsigned long paid;/**< Game's paid */
   unsigned long ddownwin;/**< Double Game's win */
   unsigned long slotwin;/**< Double Game's slot win */
   unsigned long collectable;/**< Double Game's collectable */
   unsigned long trylucky;/**< Double Game's try lucky */
   unsigned long trylucky_times;/**< Double Game's try lucky times */
   unsigned long jp1;/**< Jackpot 1 */
   unsigned long jp2;/**< Jackpot 2 */
   unsigned long jp3;/**< Jackpot 3 */
   unsigned long temp_jp1;/**< Temp Jackpot 1 */
   unsigned long temp_jp2;/**< Temp Jackpot 2 */
   unsigned long temp_jp3;/**< Temp Jackpot 3 */
   unsigned long designate_jp;/**< Designated JP by master */

   unsigned long previous_credits;/**< Game's previous credits */
   unsigned long previous_wager;/**< Game's previous wager */
   unsigned long previous_win;/**< Game's previous win */
   unsigned long previous_save;/**< Game's previous save */
   unsigned long previous_paid;/**< Game's previous paid */
   unsigned long previous_ddownwin;/**< Double Game's previous win */
   unsigned long previous_slotwin;/**< Double Game's previous slot win */
   unsigned long previous_collectable;/**< Double Game's previous collectable */
   unsigned long previous_trylucky;/**< Double Game's previous try lucky */
   unsigned long previous_trylucky_times;/**< Double Game's previous try lucky times */
   unsigned long previous_jp1;/**< previous Jackpot 1 */
   unsigned long previous_jp2;/**< previous Jackpot 2 */
   unsigned long previous_jp3;/**< previous Jackpot 3 */

   /**
    * @brief Reset All Member Parameters.
    */
   void reSet(){
      this->credits = 0;
      this->previous_credits     = this->credits + 1;
      this->wager   = 0;
      this->previous_wager       = this->wager + 1;
      this->win     = 0;
      this->previous_win         = this->win   + 1;
      this->save    = 0;
      this->previous_save        = this->save  + 1;
      this->paid    = 0;
      this->previous_paid        = this->paid  + 1;
      this->ddownwin= 0;
      this->previous_ddownwin    = this->ddownwin + 1;
      this->slotwin = 0;
      this->previous_slotwin     = this->slotwin + 1;
      this->collectable = 0;
      this->previous_collectable = this->collectable + 1;
      this->trylucky = 0;
      this->previous_trylucky    = this->trylucky + 1;
      this->trylucky_times = 1;
      this->previous_trylucky_times = this->trylucky_times + 1;
      this->jp1 = 0;
      this->previous_jp1 = this->jp1 + 1;
      this->jp2 = 0;
      this->previous_jp2 = this->jp2 + 1;
      this->jp3 = 0;
      this->previous_jp3 = this->jp3 + 1;
      this->designate_jp = 0;
   }
}GAMECREDITS;

typedef int (*FrameProTypeFunc)(MTRANDOM*,PROBABILITYCONTROL*);/**< Type Define For Each Frame Probability Type(fixed or Mutable) */

extern int _FrameProTypeFixed_1(MTRANDOM* mt,PROBABILITYCONTROL* pctrl);
extern int _FrameProTypeFixed_2(MTRANDOM* mt,PROBABILITYCONTROL* pctrl);
extern int _FrameProTypeFixed_3(MTRANDOM* mt,PROBABILITYCONTROL* pctrl);
extern int _FrameProTypeFixed_4(MTRANDOM* mt,PROBABILITYCONTROL* pctrl);
extern int _FrameProTypeFixed_5(MTRANDOM* mt,PROBABILITYCONTROL* pctrl);
extern int _FrameProTypeFixed_6(MTRANDOM* mt,PROBABILITYCONTROL* pctrl);
extern int _FrameProTypeFixed_7(MTRANDOM* mt,PROBABILITYCONTROL* pctrl);
extern int _FrameProTypeFixed_8(MTRANDOM* mt,PROBABILITYCONTROL* pctrl);
extern int _FrameProTypeMutable(MTRANDOM* mt,PROBABILITYCONTROL* pctrl);

/**
 * @brief Indicate single frame.
 */
typedef struct SingleFrame{
  //SpriteSheetObject* slotMoveSheetObject;/**< Slot Move Sprite Sheet Object */
  //SpriteSheetObject* itemSheetObject[10];/**< Slot Item Sprite Sheet Object */

  FrameProTypeFunc frameProTypeFunc;/**< Frame's probability function */
  RECTANGLE     rect;/**< Clip rectangle */
  unsigned int  type;/**< Scroll type(Item older type) */
  unsigned int  pos_X;/**< X position */
  unsigned int  pos_Y;/**< Y position */
  unsigned int  pic_Num;/**< Picture number */
  unsigned int  offset_line;/**< Offset line */
  unsigned int  stopItem;/**< Stop item */
  unsigned int  stopItemFromSerialPort;/**< Stop item via serial port */
  unsigned int  StopLine[13];/**< Stop line           { 97,217, 329, 445, 561, 677, 793, 909, 1025, 1141, 1257, 1373, 1489 } */
  unsigned int  PreChangeLine[7];/**< Pre-Change line {     75,      155,      235,      315,        395,        475,  555 } */
  unsigned int  NextStopLine;/**< Next stop line */
  unsigned int  StopFlag;/**< Stop flag */
  unsigned int  Loop;/**< Loop times */
  unsigned int  SideBingoFlag;/**< Side bingo flag */
  unsigned int  LineBingoFlag;/**< Line bingo flag */
  unsigned int  AnimeIndex;/**< Animation index */
  unsigned int  AnimeLoop;/**< Animation loop times */
  unsigned int  ConvertItemToStopLine[13];/**< Convert item to stop line */
  unsigned int  board_pos_X;/**< X position of board */
  unsigned int  board_pos_Y;/**< Y position of board */
  unsigned int  board_pic_Num;/**< Picture number of board */
  unsigned int  board_bg_pos_X;/**< X position of board BG */
  unsigned int  board_bg_pos_Y;/**< Y position of board BG */
  unsigned int  board_bg_pic_Num;/**< Picture number of board BG */
  unsigned int  stopMusicChannel;/**< Channel of stop effect */
  unsigned int  scrollStatus;/**< Scroll status */
           int  tempScrollValue;/**< Temporal scroll value */
  unsigned int  GetItemRecord[10];/**< Get Item Record */

  SingleFrame(void){
	  /*
	  this->itemSheetObject[ITEM_UNKNOW]     = NULL;
	  this->itemSheetObject[ITEM_CHERRY]     = &slot_item_cherry;
	  this->itemSheetObject[ITEM_ORANGE]     = &slot_item_orange;
	  this->itemSheetObject[ITEM_MANGO]      = &slot_item_mango;
	  this->itemSheetObject[ITEM_BELL]       = &slot_item_bell;
	  this->itemSheetObject[ITEM_WATERMELON] = &slot_item_watermelon;
	  this->itemSheetObject[ITEM_BAR_YELLOW] = &slot_item_bar_yellow;
	  this->itemSheetObject[ITEM_BAR_RED]    = &slot_item_bar_red;
	  this->itemSheetObject[ITEM_BAR_BLUE]   = &slot_item_bar_blue;
	  //this->itemSheetObject[ITEM_SEVEN]      = &slot_item_seven;
	  this->itemSheetObject[ITEM_WILD]       = &slot_item_wild;
	  */
  }

  /**
   * @brief Set Scroll type.
   * @param type Type of scroll
   */
  void setScrollType(unsigned int type){
        this->type = type;

        switch(this->type){
        case Type_Fixed_1:
          this->frameProTypeFunc = _FrameProTypeFixed_1;
      	    break;

        case Type_Fixed_2:
          this->frameProTypeFunc = _FrameProTypeFixed_2;
      	    break;

        case Type_Fixed_3:
          this->frameProTypeFunc = _FrameProTypeFixed_3;
      	    break;

        case Type_Fixed_4:
          this->frameProTypeFunc = _FrameProTypeFixed_4;
      	    break;

        case Type_Fixed_5:
          this->frameProTypeFunc = _FrameProTypeFixed_5;
      	    break;

        case Type_Fixed_6:
          this->frameProTypeFunc = _FrameProTypeFixed_6;
      	    break;

        case Type_Fixed_7:
          this->frameProTypeFunc = _FrameProTypeFixed_7;
      	    break;

        case Type_Fixed_8:
          this->frameProTypeFunc = _FrameProTypeFixed_8;
      	    break;

        case Type_Mutable:
          this->frameProTypeFunc = _FrameProTypeMutable;
            break;
#if TEST_MAIN_GAME_COMPUTE_SCORE==1
        case Type_Test:
		  this->frameProTypeFunc = _FrameProTypeTest;
        	break;
#endif

        };
  }
  /**
   * @brief Get Stop Frame.
   * @param mt Mersenne Twister Algorithm
   * @param pctrl Probability Controller
   * @retval Stop frame
   */
  int getStopFrame(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){

      this->stopItem = this->frameProTypeFunc(mt,pctrl);

	  //Get Stop Item From Serial Port
      //this->stopItem = this->stopItemFromSerialPort;

      this->GetItemRecord[this->stopItem]++;
      return this->stopItem;
  }
  /**
   * @brief Reset stop line.
   */
  void resetStopLine(){
#if defined(PIC_ORIGINAL) || defined(PIC_OCEAN)
	    this->StopLine[0] = 97;
		for(unsigned int i=1; i<sizeof(this->StopLine)/sizeof(this->StopLine[0]); i++){
		     this->StopLine[i] = this->StopLine[i-1] + 116;
        }
#else
	    this->StopLine[0] = 110;
		for(unsigned int i=1; i<sizeof(this->StopLine)/sizeof(this->StopLine[0]); i++){
		     this->StopLine[i] = this->StopLine[i-1] + 125;//(i%2==0) ?  this->StopLine[i-1] + 100 : this->StopLine[i-1] + 130;
        }
#endif
  }
  /**
   * @brief Reset Pre-ChangeLine.
   */
  void resetPreChangeLine(){
		this->PreChangeLine[0] = 75;
		for(unsigned int i=1; i<sizeof(this->PreChangeLine)/sizeof(this->PreChangeLine[0]); i++){
		    this->PreChangeLine[i] = this->PreChangeLine[i-1] + 80;
        }
  }
  /**
   * @brief Reset convert item to stop line.
   * @param scrollType Scroll's type
   */
  void resetConvertItemToStopLine(int scrollType){
	  switch(scrollType){

	  case Type1://Slot 1
          ConvertItemToStopLine[0]  = Item_One_Bar;
          ConvertItemToStopLine[1]  = Item_Blank_1;
		  ConvertItemToStopLine[2]  = Item_Joker;
		  ConvertItemToStopLine[3]  = Item_Blank_2;
		  ConvertItemToStopLine[4]  = Item_Blue_7;
		  ConvertItemToStopLine[5]  = Item_Blank_3;
		  ConvertItemToStopLine[6]  = Item_Red_7;
		  ConvertItemToStopLine[7]  = Item_Blank_4;
		  ConvertItemToStopLine[8]  = Item_Three_Bar;
		  ConvertItemToStopLine[9]  = Item_Blank_5;
		  ConvertItemToStopLine[10] = Item_Two_Bar;
		  ConvertItemToStopLine[11] = Item_Blank_6;
		  ConvertItemToStopLine[12] = Item_One_Bar;
		  break;

	  case Type2://Slot 2
          ConvertItemToStopLine[0]  = Item_Blue_7;
          ConvertItemToStopLine[1]  = Item_Blank_1;
		  ConvertItemToStopLine[2]  = Item_One_Bar;
		  ConvertItemToStopLine[3]  = Item_Blank_2;
		  ConvertItemToStopLine[4]  = Item_Red_7;
		  ConvertItemToStopLine[5]  = Item_Blank_3;
		  ConvertItemToStopLine[6]  = Item_Two_Bar;
		  ConvertItemToStopLine[7]  = Item_Blank_4;
		  ConvertItemToStopLine[8]  = Item_Joker;
		  ConvertItemToStopLine[9]  = Item_Blank_5;
		  ConvertItemToStopLine[10] = Item_Three_Bar;
		  ConvertItemToStopLine[11] = Item_Blank_6;
		  ConvertItemToStopLine[12] = Item_Blue_7;
		  break;

	  case Type3://Slot 3
          ConvertItemToStopLine[0]  = Item_Two_Bar;
          ConvertItemToStopLine[1]  = Item_Blank_1;
		  ConvertItemToStopLine[2]  = Item_Red_7;
		  ConvertItemToStopLine[3]  = Item_Blank_2;
		  ConvertItemToStopLine[4]  = Item_Three_Bar;
		  ConvertItemToStopLine[5]  = Item_Blank_3;
		  ConvertItemToStopLine[6]  = Item_Joker;
		  ConvertItemToStopLine[7]  = Item_Blank_4;
		  ConvertItemToStopLine[8]  = Item_One_Bar;
		  ConvertItemToStopLine[9]  = Item_Blank_5;
		  ConvertItemToStopLine[10] = Item_Blue_7;
		  ConvertItemToStopLine[11] = Item_Blank_6;
		  ConvertItemToStopLine[12] = Item_Two_Bar;
		  break;

	  case Type4://Slot 4
          ConvertItemToStopLine[0]  = Item_Joker;
          ConvertItemToStopLine[1]  = Item_Blank_1;
		  ConvertItemToStopLine[2]  = Item_Three_Bar;
		  ConvertItemToStopLine[3]  = Item_Blank_2;
		  ConvertItemToStopLine[4]  = Item_Two_Bar;
		  ConvertItemToStopLine[5]  = Item_Blank_3;
		  ConvertItemToStopLine[6]  = Item_Blue_7;
		  ConvertItemToStopLine[7]  = Item_Blank_4;
		  ConvertItemToStopLine[8]  = Item_Red_7;
		  ConvertItemToStopLine[9]  = Item_Blank_5;
		  ConvertItemToStopLine[10] = Item_One_Bar;
		  ConvertItemToStopLine[11] = Item_Blank_6;
		  ConvertItemToStopLine[12] = Item_Joker;
		  break;

	  case Type5://Slot 5
          ConvertItemToStopLine[0]  = Item_Three_Bar;
          ConvertItemToStopLine[1]  = Item_Blank_1;
		  ConvertItemToStopLine[2]  = Item_Blue_7;
		  ConvertItemToStopLine[3]  = Item_Blank_2;
		  ConvertItemToStopLine[4]  = Item_Joker;
		  ConvertItemToStopLine[5]  = Item_Blank_3;
		  ConvertItemToStopLine[6]  = Item_One_Bar;
		  ConvertItemToStopLine[7]  = Item_Blank_4;
		  ConvertItemToStopLine[8]  = Item_Two_Bar;
		  ConvertItemToStopLine[9]  = Item_Blank_5;
		  ConvertItemToStopLine[10] = Item_Red_7;
		  ConvertItemToStopLine[11] = Item_Blank_6;
		  ConvertItemToStopLine[12] = Item_Three_Bar;
		  break;

	  default:
		  break;
	  }
  }
  /**
   * @brief Get stop line by item.
   * @param item Stop item
   * @retval Stop line
   */
  int  getStopLineFromItem(unsigned int item){
	   this->NextStopLine = 50;
	   return 50;
#if 0
       int result = -1;
       int convertRanToReal[6] = { Item_One_Bar,Item_Two_Bar,Item_Three_Bar,Item_Red_7,Item_Blue_7,Item_Joker};
       int temp=0;

       switch(item){

       case ran_Item_Blank:
           temp = (((rand()%6))*2) + 1;
           this->NextStopLine = this->StopLine[temp];
           return this->StopLine[temp];
    	   break;
       case ran_Item_One_Bar:
       case ran_Item_Two_Bar:
       case ran_Item_Three_Bar:
       case ran_Item_Red_7:
       case ran_Item_Blue_7:
       case ran_Item_Joker:
    	   /*
    	   for(unsigned int i=sizeof(this->ConvertItemToStopLine)/sizeof(this->ConvertItemToStopLine[0])-1; i>0; i--){
               if(this->ConvertItemToStopLine[i]==(unsigned int)convertRanToReal[item-1]){
            	  this->NextStopLine = this->StopLine[i];
                  return this->StopLine[i];
               }
           }
           */
    	   for(unsigned int i=0;i < sizeof(this->ConvertItemToStopLine)/sizeof(this->ConvertItemToStopLine[0]); i++){
               if(this->ConvertItemToStopLine[i]==(unsigned int)convertRanToReal[item-1]){
            	  this->NextStopLine = this->StopLine[i];
                  return this->StopLine[i];
               }
           }
    	   break;

       default:
    	   break;
       }

	   return result;
#endif
  }

}SINGLEFRAME;

/**
 * @brief Indicate single line.
 */
typedef struct Line{
  unsigned char bingoFrame[3];/**< Three frames of line */
  unsigned long bet;/**< line's bet */
  unsigned long win;/**< line's win */
  bool          bingoFlag;/**< line's bingo flag */
  unsigned char bingotype;/**< line's bingo type */
  unsigned int* lineBingoTypeM;/**< Line odds mapping table */
  unsigned char jokerSum;/**< Sum of joker */
  unsigned int  pos_X;/**< line's X position */
  unsigned int  pos_Y;/**< line's Y position */
  unsigned int  pic_N;/**< line's bet picture number */
  unsigned long AwardRecord[13];/**< Award Record */

  /**
   * @brief Reset line's parameters of rendering.
   * @param x X position
   * @param y Y position
   * @param n n Picture's number
   */
  void resetLineRenderPara(int x,int y,int n){
	  this->pos_X = x;
	  this->pos_Y = y;
	  this->pic_N = n;;
  }
  /**
   * @brief Reset all member parameters.
   */
  void reset(){
	  this->bet  =  0;
	  this->bingoFlag = false;
	  this->bingotype = lb_None;
	  this->lineBingoTypeM = LineAwardTypeOddsMapping;//LineBingoTypeM;
	  this->jokerSum = 0;
	  for(unsigned int i=0; i<sizeof(bingoFrame)/sizeof(bingoFrame[0]); i++){
		  this->bingoFrame[i] = 0;
	  }
	  for(unsigned int i=0; i<sizeof(AwardRecord)/sizeof(AwardRecord[0]);i++){
		  this->AwardRecord[i]=0;
	  }
  }
  /**
   * @brief Set up three frames of line.
   * @param f1 frame 1
   * @param f2 frame 2
   * @param f3 frame 3
   */
  void setBingoFrame(int f1,int f2,int f3){
	  this->bingoFrame[0] = f1;
	  this->bingoFrame[1] = f2;
	  this->bingoFrame[2] = f3;
  }

  unsigned int getWildTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_WILD){
			  times++;
		  }
	  }

	  return times;
  }
  /*
  unsigned int getSevenTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_SEVEN){
			  times++;
		  }
	  }

	  return times;
  }
  */

  unsigned int getBarBlueTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_BAR_BLUE){
			  times++;
		  }
	  }

	  return times;
  }

  unsigned int getBarRedTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_BAR_RED){
			  times++;
		  }
	  }

	  return times;
  }

  unsigned int getBarYellowTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_BAR_YELLOW){
			  times++;
		  }
	  }

	  return times;
  }

  unsigned int getWaterMelonTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_WATERMELON){
			  times++;
		  }
	  }

	  return times;
  }

  unsigned int getBellTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_BELL){
			  times++;
		  }
	  }

	  return times;
  }

  unsigned int getMangoTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_MANGO){
			  times++;
		  }
	  }

	  return times;
  }

  unsigned int getMixBarTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_BAR_YELLOW || sf[this->bingoFrame[i]].stopItem==ITEM_BAR_RED ||
		     sf[this->bingoFrame[i]].stopItem==ITEM_BAR_BLUE){
			  times++;
		  }
	  }

	  return times;
  }

  unsigned int getOrangeTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_ORANGE){
			  times++;
		  }
	  }

	  return times;
  }

  unsigned int getCherryTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_CHERRY){
			  times++;
		  }
	  }

	  return times;
  }

#if 0
  /**
   * @brief Get count of joker.
   * @param sf Single frame
   * @retval Count of joker
   */
  unsigned int getJokerSingleTimes(SingleFrame* sf){
	  unsigned int times=0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ran_Item_Joker){
			  times++;
		  }
	  }
	  this->jokerSum = times;
	  return times;
  }
  /**
   * @brief Get count of blue 7.
   * @param sf Single frame
   * @retval Count of blue 7
   */
  unsigned int getBlue7SingleTimes(SingleFrame* sf){
	  unsigned int times=0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ran_Item_Blue_7){
			  times++;
		  }
	  }
	  return times;
  }
  /**
   * @brief Get count of red 7.
   * @param sf Single frame
   * @retval Count of red 7
   */
  unsigned int getRed7SingleTimes(SingleFrame* sf){
	  unsigned int times=0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ran_Item_Red_7){
			  times++;
		  }
	  }
	  return times;
  }
  /**
   * @brief Get count of mix 7.
   * @param sf Single frame
   * @retval Count of mix 7
   */
  unsigned int getMix7SingleTimes(SingleFrame* sf){
	  unsigned int times=0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ran_Item_Red_7 || sf[this->bingoFrame[i]].stopItem==ran_Item_Blue_7){
			  times++;
		  }
	  }
	  return times;
  }
  /**
   * @brief Get count of three bar.
   * @param sf Single frame
   * @retval Count of three bar
   */
  unsigned int getThreeBarSingleTimes(SingleFrame* sf){
	  unsigned int times=0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ran_Item_Three_Bar){
			  times++;
		  }
	  }
	  return times;
  }
  /**
   * @brief Get count of two bar.
   * @param sf Single frame
   * @retval Count of two bar
   */
  unsigned int getTwoBarSingleTimes(SingleFrame* sf){
	  unsigned int times=0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ran_Item_Two_Bar){
			  times++;
		  }
	  }
	  return times;
  }
  /**
   * @brief Get count of one bar.
   * @param sf Single frame
   * @retval Count of one bar
   */
  unsigned int getOneBarSingleTimes(SingleFrame* sf){
	  unsigned int times=0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ran_Item_One_Bar){
			  times++;
		  }
	  }
	  return times;
  }
  /**
   * @brief Get count of mix bar.
   * @param sf Single frame
   * @retval Count of mix bar
   */
  unsigned int getMixBarSingleTimes(SingleFrame* sf){
	  unsigned int times=0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ran_Item_One_Bar || sf[this->bingoFrame[i]].stopItem==ran_Item_Two_Bar || sf[this->bingoFrame[i]].stopItem==ran_Item_Three_Bar ){
			  times++;
		  }
	  }
	  return times;
  }
#endif
  /**
   * @brief Is line bingo.
   * @param sf Single frame
   * @retval true:bingo false:none
   */
  bool isLineBingo(SingleFrame* sf){


	  bool result = false;

      if(this->getWildTimes(sf) == 3){// Seven Straight
    	  this->bingotype = LINE_AWARD_WILD;

      }//else if(this->getSevenTimes(sf) + this->getWildTimes(sf) == 3){// Seven Straight
    	  //this->bingotype = LINE_AWARD_SEVEN;

      //}
       else if(this->getBarBlueTimes(sf) + this->getWildTimes(sf) == 3){// Bar(blue) straight
    	  this->bingotype = LINE_AWARD_BAR_BLUE;

      }else if(this->getBarRedTimes(sf) + this->getWildTimes(sf) == 3){// Bar(red) straight
    	  this->bingotype = LINE_AWARD_BAR_RED;

      }else if(this->getBarYellowTimes(sf) + this->getWildTimes(sf) == 3){// Bar(yellow) straight
    	  this->bingotype = LINE_AWARD_BAR_YELLOW;

      }else if(this->getWaterMelonTimes(sf) + this->getWildTimes(sf) == 3){// Watermelon straight
    	  this->bingotype = LINE_AWARD_WATERMELON;

      }else if(this->getBellTimes(sf) + this->getWildTimes(sf) == 3){// Bell straight
    	  this->bingotype = LINE_AWARD_BELL;

      }else if(this->getMangoTimes(sf) + this->getWildTimes(sf) == 3){// Mango straight
    	  this->bingotype = LINE_AWARD_MANGO;

      }else if(this->getMixBarTimes(sf) + this->getWildTimes(sf) == 3){// Mix bar straight
    	  this->bingotype = LINE_AWARD_MIX_BAR;

      }else if(this->getOrangeTimes(sf) + this->getWildTimes(sf) == 3){// Orange straight
    	  this->bingotype = LINE_AWARD_ORANGE;

      }else if(this->getCherryTimes(sf) + this->getWildTimes(sf) == 3){// Three cherry straight
    	  this->bingotype = LINE_AWARD_THREE_CHERRY;

      }else if(this->getCherryTimes(sf) + this->getWildTimes(sf) == 2){// Two cherry straight
    	  if((sf[this->bingoFrame[0]].stopItem == ITEM_CHERRY || sf[this->bingoFrame[0]].stopItem == ITEM_WILD)
    		  && (sf[this->bingoFrame[1]].stopItem == ITEM_CHERRY || sf[this->bingoFrame[1]].stopItem == ITEM_WILD)){
    		  this->bingotype = LINE_AWARD_TWO_CHERRY;
    	  }else if((sf[this->bingoFrame[0]].stopItem == ITEM_CHERRY || sf[this->bingoFrame[0]].stopItem == ITEM_WILD)
    			   && (sf[this->bingoFrame[2]].stopItem == ITEM_CHERRY || sf[this->bingoFrame[2]].stopItem == ITEM_WILD)){
    		  this->bingotype = LINE_AWARD_ONE_CHERRY;
    	  }

      }else if(this->getCherryTimes(sf) + this->getWildTimes(sf) == 1){// One cherry straight
    	  if(sf[this->bingoFrame[0]].stopItem == ITEM_CHERRY || sf[this->bingoFrame[0]].stopItem == ITEM_WILD ){
    		  this->bingotype = LINE_AWARD_ONE_CHERRY;
    	  }
      }


      if(this->bingotype != LINE_AWARD_NONE){
    	  result = true;
      }

      AwardRecord[this->bingotype]++;

	  return result;

#if 0
      bool result=false;

      if(this->getJokerSingleTimes(sf)==3){                                         //Joker Straight
          this->bingotype = lb_Joker_Straight;
          result=true;
          return  result;
      }else if(this->getBlue7SingleTimes(sf)+this->getJokerSingleTimes(sf)==3){     //Blue 7 Straight
          this->bingotype = lb_Blue_7_Straight;
          result=true;
          return  result;
      }else if(this->getRed7SingleTimes(sf)+this->getJokerSingleTimes(sf)==3){      //Red  7 Straight
          this->bingotype = lb_Red_7_Straight;
          result=true;
          return  result;
      }else if(this->getMix7SingleTimes(sf)+this->getJokerSingleTimes(sf)==3){      //Mix  7 Straight
          this->bingotype = lb_Mix_7_Straight;
          result=true;
          return  result;
      }else if(this->getThreeBarSingleTimes(sf)+this->getJokerSingleTimes(sf)==3){  //Three bar Straight
          this->bingotype = lb_Three_Bar_Straight;
          result=true;
          return  result;
      }else if(this->getTwoBarSingleTimes(sf)+this->getJokerSingleTimes(sf)==3){    //TWo   bar Straight
          this->bingotype = lb_Two_Bar_Straight;
          result=true;
          return  result;
      }else if(this->getOneBarSingleTimes(sf)+this->getJokerSingleTimes(sf)==3){    //One   bar Straight
          this->bingotype = lb_One_Bar_Straight;
          result=true;
          return  result;
      }else if(this->getMixBarSingleTimes(sf)+this->getJokerSingleTimes(sf)==3){    //Mix   bar Straight
          this->bingotype = lb_Mix_Bar_Straight;
          result=true;
          return  result;
      }else{
          this->bingotype = lb_None;
          result=false;
          return  result;
      }

	  return false;
#endif
  }
  /**
   * @brief Compute line's score.
   * @param sf Single frame
   * @retval Score
   */
  unsigned long computeLineScore(SingleFrame* sf){
	  unsigned long score=0;

      if(this->isLineBingo(sf)==false || this->bet==0){
    	 this->win = 0;
         return score;
      }else{//When Bingo Set LineBingoFlag True
    	 for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
    		 sf[this->bingoFrame[i]].LineBingoFlag = true;
    	 }
      }

      this->win = this->bet * this->lineBingoTypeM[this->bingotype];
	  score = this->win;
      //DOUBLES WINNING COMBINATION EXCEPT "Joker Joker Joker"
	  if( this->bingotype != lb_Joker_Straight){
		  for(unsigned int i=this->jokerSum; i>0; i--){
			  score *= 2;
		  }
      }

	  return score;
  }

}LINE;

/**
 * @brief Indicates single side item.
 */
typedef struct SideItem{
  unsigned long bet;/**< Side item's bet */
  unsigned char item;/**< Item kind */
  unsigned int  pos_X;/**< Side item's X position */
  unsigned int  pos_Y;/**< Side item's Y position */
  unsigned int  pic_N;/**< Side item's Picture number */

  /**
   * @brief Reset side item parameters of rendering.
   * @param x Position X
   * @param y Position Y
   * @param n Picture's number
   */
  void resetSideRenderPara(int x,int y,int n){
	 this->pos_X = x;
	 this->pos_Y = y;
	 this->pic_N = n;
  }
  /**
   * @brief Rest bet and item.
   */
  void reset(){
	  this->bet  = 0;
	  this->item = 0;
  }

}SIDEITEM;

/**
 * @brief Main game frame.
 */
typedef struct MainGameFrame{

	Line line[8];/**< Line */
	SideItem sideItem[8];/**< Side item */
	SingleFrame singleFrame[9];/**< Single frame */
	unsigned int _stopedFrameTimes;/**< Stopping frame count */
    unsigned char sp_anime_type;/**< Special animation type */
    unsigned char sp_anime_pic_index;/**< Special animation picture index */
    unsigned char sp_anime_pic_index2;/**< Special animation picture index 2 */
    unsigned char sp_anime_pic_index3;/**< Special animation picture index 3 */
    unsigned char sp_anime_pic_index4;/**< Special animation picture index 4 */
    unsigned char sp_anime_pic_index5;/**< Special animation picture index 5 */
    unsigned char sp_anime_playing;/**< Special animation playing ? */
    unsigned char finalStopItem[9];/**< Final stop item */
    int           preStates;/**< For Saving Main Game Previous States */
    unsigned char renderKeyOutPaid;/**< Render Key out paid */
    unsigned long temp_total_out;/**< Temporal total out */
    unsigned char stopActiveSoundFlag;/**< Stop active sound flag */
    unsigned long bet;/**< bet */
    unsigned long FullFrameAwardRecord[11][10];/**< Full Frame Award Record */

    /**
     * @brief Reset all member parameters.
     */
	void ramClearReset(){
		//Line ReSet
		for(unsigned int i=0; i<sizeof(line)/sizeof(line[0]); i++){
			line[i].reset();
		}
		line[0].setBingoFrame(3,4,5);
		//line[1].setBingoFrame(6,7,8);//fixed by SHIE BINGSHIUE 2011-04-11
		//line[2].setBingoFrame(0,1,2);//fixed by SHIE BINGSHIUE 2011-04-11
		//line[3].setBingoFrame(2,4,6);//fixed by SHIE BINGSHIUE 2011-04-11
		//line[4].setBingoFrame(0,4,8);//fixed by SHIE BINGSHIUE 2011-04-11
		line[1].setBingoFrame(0,1,2);//fixed by SHIE BINGSHIUE 2011-04-11
		line[2].setBingoFrame(6,7,8);//fixed by SHIE BINGSHIUE 2011-04-11
		line[3].setBingoFrame(0,4,8);//fixed by SHIE BINGSHIUE 2011-04-11
		line[4].setBingoFrame(6,4,2);//fixed by SHIE BINGSHIUE 2011-04-11
		line[5].setBingoFrame(0,3,6);
		line[6].setBingoFrame(1,4,7);
		line[7].setBingoFrame(2,5,8);
		line[0].resetLineRenderPara(LINE_1_WAGER_INFO_X,LINE_1_WAGER_INFO_Y,LINE_1_WAGER_INFO_N);
		line[1].resetLineRenderPara(LINE_2_WAGER_INFO_X,LINE_2_WAGER_INFO_Y,LINE_2_WAGER_INFO_N);
		line[2].resetLineRenderPara(LINE_3_WAGER_INFO_X,LINE_3_WAGER_INFO_Y,LINE_3_WAGER_INFO_N);
		line[3].resetLineRenderPara(LINE_4_WAGER_INFO_X,LINE_4_WAGER_INFO_Y,LINE_4_WAGER_INFO_N);
		line[4].resetLineRenderPara(LINE_5_WAGER_INFO_X,LINE_5_WAGER_INFO_Y,LINE_5_WAGER_INFO_N);
		line[5].resetLineRenderPara(LINE_6_WAGER_INFO_X,LINE_6_WAGER_INFO_Y,LINE_6_WAGER_INFO_N);
		line[6].resetLineRenderPara(LINE_7_WAGER_INFO_X,LINE_7_WAGER_INFO_Y,LINE_7_WAGER_INFO_N);
		line[7].resetLineRenderPara(LINE_8_WAGER_INFO_X,LINE_8_WAGER_INFO_Y,LINE_8_WAGER_INFO_N);
        //SideItem ReSet
		for(unsigned int i=0; i<sizeof(sideItem)/sizeof(sideItem[0]); i++){
			sideItem[i].reset();
		}
		sideItem[0].item = side_Blank;
		sideItem[1].item = side_Mix_Bar;
		sideItem[2].item = side_One_Bar;
		sideItem[3].item = side_Two_Bar;
		sideItem[4].item = side_Three_Bar;
		sideItem[5].item = side_Mix_7;
		sideItem[6].item = side_Red_7;
		sideItem[7].item = side_Blue_7;
		sideItem[0].resetSideRenderPara(ITEM_1_WAGER_INFO_X,ITEM_1_WAGER_INFO_Y,ITEM_1_WAGER_INFO_N);
		sideItem[1].resetSideRenderPara(ITEM_2_WAGER_INFO_X,ITEM_2_WAGER_INFO_Y,ITEM_2_WAGER_INFO_N);
		sideItem[2].resetSideRenderPara(ITEM_3_WAGER_INFO_X,ITEM_3_WAGER_INFO_Y,ITEM_3_WAGER_INFO_N);
		sideItem[3].resetSideRenderPara(ITEM_4_WAGER_INFO_X,ITEM_4_WAGER_INFO_Y,ITEM_4_WAGER_INFO_N);
		sideItem[4].resetSideRenderPara(ITEM_5_WAGER_INFO_X,ITEM_5_WAGER_INFO_Y,ITEM_5_WAGER_INFO_N);
		sideItem[5].resetSideRenderPara(ITEM_6_WAGER_INFO_X,ITEM_6_WAGER_INFO_Y,ITEM_6_WAGER_INFO_N);
		sideItem[6].resetSideRenderPara(ITEM_7_WAGER_INFO_X,ITEM_7_WAGER_INFO_Y,ITEM_7_WAGER_INFO_N);
		sideItem[7].resetSideRenderPara(ITEM_8_WAGER_INFO_X,ITEM_8_WAGER_INFO_Y,ITEM_8_WAGER_INFO_N);
        //SingleFrame ReSet
        //Frame[0]
#if TEST_MAIN_GAME_COMPUTE_SCORE==1
		singleFrame[0].setScrollType(Type_Test);
#else
		singleFrame[0].setScrollType(Type_Fixed_6);
#endif
		//singleFrame[0].slotMoveSheetObject =  &slot_move;
		singleFrame[0].pos_X        =           SLOT_1_X;
		singleFrame[0].pos_Y        =           SLOT_1_Y;
		singleFrame[0].pic_Num      =        Frame_1_PIC;
		singleFrame[0].offset_line  =    DEF_OFFSET_LINE;
		singleFrame[0].stopItem     =        ITEM_CHERRY;
		singleFrame[0].NextStopLine =                  0;
		singleFrame[0].StopFlag     =             false;
		singleFrame[0].Loop         =                  0;
		singleFrame[0].SideBingoFlag=             false;
		singleFrame[0].LineBingoFlag=             false;
		singleFrame[0].resetStopLine();
		singleFrame[0].resetConvertItemToStopLine(Type1);
		singleFrame[0].board_pos_X  =           SLOT_1_X;
		singleFrame[0].board_pos_Y  =           SLOT_1_Y;
		singleFrame[0].board_pic_Num=                  6;
		singleFrame[0].board_bg_pos_X =         SLOT_1_X;
		singleFrame[0].board_bg_pos_Y =         SLOT_1_Y;
		singleFrame[0].board_bg_pic_Num =              7;
		singleFrame[0].rect.x = 0;
		singleFrame[0].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[0].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[0].rect.h = SINGLE_FRAME_HEIGHT;

		//Frame[1]
#if TEST_MAIN_GAME_COMPUTE_SCORE==1
		singleFrame[1].setScrollType(Type_Test);
#else
		singleFrame[1].setScrollType(Type_Fixed_7);
#endif
		//singleFrame[1].slotMoveSheetObject =  &slot_move;
		singleFrame[1].pos_X        =           SLOT_2_X;
		singleFrame[1].pos_Y        =   		SLOT_2_Y;
		singleFrame[1].pic_Num      =   	 Frame_2_PIC;
		singleFrame[1].offset_line  =    DEF_OFFSET_LINE;
		singleFrame[1].stopItem     =        ITEM_ORANGE;
		singleFrame[1].NextStopLine =                  0;
		singleFrame[1].StopFlag     =             false;
		singleFrame[1].Loop         =                  0;
		singleFrame[1].SideBingoFlag=             false;
		singleFrame[1].LineBingoFlag=             false;
		singleFrame[1].resetStopLine();
		singleFrame[1].resetConvertItemToStopLine(Type2);
		singleFrame[1].board_pos_X  =           SLOT_2_X;
		singleFrame[1].board_pos_Y  =           SLOT_2_Y;
		singleFrame[1].board_pic_Num=                  6;
		singleFrame[1].board_bg_pos_X =         SLOT_2_X;
		singleFrame[1].board_bg_pos_Y =         SLOT_2_Y;
		singleFrame[1].board_bg_pic_Num =              7;
		singleFrame[1].rect.x = 0;
		singleFrame[1].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[1].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[1].rect.h = SINGLE_FRAME_HEIGHT;
		//Frame[2]
#if TEST_MAIN_GAME_COMPUTE_SCORE==1
		singleFrame[2].setScrollType(Type_Test);
#else
		singleFrame[2].setScrollType(Type_Fixed_8);
#endif
		//singleFrame[2].slotMoveSheetObject =  &slot_move;
		singleFrame[2].pos_X        =           SLOT_3_X;
		singleFrame[2].pos_Y        =           SLOT_3_Y;
		singleFrame[2].pic_Num      =        Frame_3_PIC;
		singleFrame[2].offset_line  =    DEF_OFFSET_LINE;
		singleFrame[2].stopItem     =         ITEM_MANGO;
		singleFrame[2].NextStopLine =                  0;
		singleFrame[2].StopFlag     =             false;
		singleFrame[2].Loop         =                  0;
		singleFrame[2].SideBingoFlag=             false;
		singleFrame[2].LineBingoFlag=             false;
		singleFrame[2].resetStopLine();
		singleFrame[2].resetConvertItemToStopLine(Type3);
		singleFrame[2].board_pos_X  =           SLOT_3_X;
		singleFrame[2].board_pos_Y  =           SLOT_3_Y;
		singleFrame[2].board_pic_Num=                  6;
		singleFrame[2].board_bg_pos_X =         SLOT_3_X;
		singleFrame[2].board_bg_pos_Y =         SLOT_3_Y;
		singleFrame[2].board_bg_pic_Num =              7;
		singleFrame[2].rect.x = 0;
		singleFrame[2].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[2].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[2].rect.h = SINGLE_FRAME_HEIGHT;
		//Frame[3]
#if TEST_MAIN_GAME_COMPUTE_SCORE==1
		singleFrame[3].setScrollType(Type_Test);
#else
		singleFrame[3].setScrollType(Type_Fixed_4);
#endif
		//singleFrame[3].slotMoveSheetObject =  &slot_move;
		singleFrame[3].pos_X        =   		SLOT_4_X;
		singleFrame[3].pos_Y        =   		SLOT_4_Y;
		singleFrame[3].pic_Num      =        Frame_4_PIC;
		singleFrame[3].offset_line  =    DEF_OFFSET_LINE;
		singleFrame[3].stopItem     =          ITEM_BELL;
		singleFrame[3].NextStopLine =                  0;
		singleFrame[3].StopFlag     =             false;
		singleFrame[3].Loop         =                  0;
		singleFrame[3].SideBingoFlag=             false;
		singleFrame[3].LineBingoFlag=             false;
		singleFrame[3].resetStopLine();
		singleFrame[3].resetConvertItemToStopLine(Type4);
		singleFrame[3].board_pos_X  =      		SLOT_4_X;
		singleFrame[3].board_pos_Y  =      		SLOT_4_Y;
		singleFrame[3].board_pic_Num=                  6;
		singleFrame[3].board_bg_pos_X =         SLOT_4_X;
		singleFrame[3].board_bg_pos_Y =         SLOT_4_Y;
		singleFrame[3].board_bg_pic_Num =              7;
		singleFrame[3].rect.x = 0;
		singleFrame[3].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[3].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[3].rect.h = SINGLE_FRAME_HEIGHT;
		//Frame[4]
#if TEST_MAIN_GAME_COMPUTE_SCORE==1
		singleFrame[4].setScrollType(Type_Test);
#else
		singleFrame[4].setScrollType(Type_Fixed_4);//Type_Mutable);
#endif
		//singleFrame[4].slotMoveSheetObject =  &slot_move;
		singleFrame[4].pos_X        =   		SLOT_5_X;
		singleFrame[4].pos_Y        =   		SLOT_5_Y;
		singleFrame[4].pic_Num      =        Frame_5_PIC;
		singleFrame[4].offset_line  =    DEF_OFFSET_LINE;
		singleFrame[4].stopItem     =    ITEM_WATERMELON;
		singleFrame[4].NextStopLine =                  0;
		singleFrame[4].StopFlag     =             false;
		singleFrame[4].Loop         =                  0;
		singleFrame[4].SideBingoFlag=             false;
		singleFrame[4].LineBingoFlag=             false;
		singleFrame[4].resetStopLine();
		singleFrame[4].resetConvertItemToStopLine(Type4);//Type5);
		singleFrame[4].board_pos_X  =      		SLOT_5_X;
		singleFrame[4].board_pos_Y  =           SLOT_5_Y;
		singleFrame[4].board_pic_Num=                  6;
		singleFrame[4].board_bg_pos_X =         SLOT_5_X;
		singleFrame[4].board_bg_pos_Y =         SLOT_5_Y;
		singleFrame[4].board_bg_pic_Num =              7;
		singleFrame[4].rect.x = 0;
		singleFrame[4].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[4].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[4].rect.h = SINGLE_FRAME_HEIGHT;
		//Frame[5]
#if TEST_MAIN_GAME_COMPUTE_SCORE==1
		singleFrame[5].setScrollType(Type_Test);
#else
		singleFrame[5].setScrollType(Type_Fixed_5);
#endif
		//singleFrame[5].slotMoveSheetObject =  &slot_move;
		singleFrame[5].pos_X        =           SLOT_6_X;
		singleFrame[5].pos_Y        =           SLOT_6_Y;
		singleFrame[5].pic_Num      =        Frame_6_PIC;
		singleFrame[5].offset_line  =    DEF_OFFSET_LINE;
		singleFrame[5].stopItem     =    ITEM_BAR_YELLOW;
		singleFrame[5].NextStopLine =                  0;
		singleFrame[5].StopFlag     =             false;
		singleFrame[5].Loop         =                  0;
		singleFrame[5].SideBingoFlag=             false;
		singleFrame[5].LineBingoFlag=             false;
		singleFrame[5].resetStopLine();
		singleFrame[5].resetConvertItemToStopLine(Type4);
		singleFrame[5].board_pos_X  =      		SLOT_6_X;
		singleFrame[5].board_pos_Y  =      		SLOT_6_Y;
		singleFrame[5].board_pic_Num=                  6;
		singleFrame[5].board_bg_pos_X =         SLOT_6_X;
		singleFrame[5].board_bg_pos_Y =         SLOT_6_Y;
		singleFrame[5].board_bg_pic_Num =              7;
		singleFrame[5].rect.x = 0;
		singleFrame[5].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[5].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[5].rect.h = SINGLE_FRAME_HEIGHT;
		//Frame[6]
#if TEST_MAIN_GAME_COMPUTE_SCORE==1
		singleFrame[6].setScrollType(Type_Test);
#else
		singleFrame[6].setScrollType(Type_Fixed_1);
#endif
		//singleFrame[6].slotMoveSheetObject =  &slot_move;
		singleFrame[6].pos_X        =           SLOT_7_X;
		singleFrame[6].pos_Y        =   		SLOT_7_Y;
		singleFrame[6].pic_Num      =   	 Frame_7_PIC;
		singleFrame[6].offset_line  =    DEF_OFFSET_LINE;
		singleFrame[6].stopItem     =       ITEM_BAR_RED;
		singleFrame[6].NextStopLine =                  0;
		singleFrame[6].StopFlag     =             false;
		singleFrame[6].Loop         =                  0;
		singleFrame[6].SideBingoFlag=             false;
		singleFrame[6].LineBingoFlag=             false;
		singleFrame[6].resetStopLine();
		singleFrame[6].resetConvertItemToStopLine(Type3);
		singleFrame[6].board_pos_X  =      		SLOT_7_X;
		singleFrame[6].board_pos_Y  =      		SLOT_7_Y;
		singleFrame[6].board_pic_Num=                  6;
		singleFrame[6].board_bg_pos_X =         SLOT_7_X;
		singleFrame[6].board_bg_pos_Y =         SLOT_7_Y;
		singleFrame[6].board_bg_pic_Num =              7;
		singleFrame[6].rect.x = 0;
		singleFrame[6].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[6].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[6].rect.h = SINGLE_FRAME_HEIGHT;
		//Frame[7]
#if TEST_MAIN_GAME_COMPUTE_SCORE==1
		singleFrame[7].setScrollType(Type_Test);
#else
		singleFrame[7].setScrollType(Type_Fixed_2);
#endif
		//singleFrame[7].slotMoveSheetObject =  &slot_move;
		singleFrame[7].pos_X        =   		SLOT_8_X;
		singleFrame[7].pos_Y        =   		SLOT_8_Y;
		singleFrame[7].pic_Num      =        Frame_8_PIC;
		singleFrame[7].offset_line  =    DEF_OFFSET_LINE;
		singleFrame[7].stopItem     =      ITEM_BAR_BLUE;
		singleFrame[7].NextStopLine =                  0;
		singleFrame[7].StopFlag     =             false;
		singleFrame[7].Loop         =                  0;
		singleFrame[7].SideBingoFlag=             false;
		singleFrame[7].LineBingoFlag=             false;
		singleFrame[7].resetStopLine();
		singleFrame[7].resetConvertItemToStopLine(Type2);
		singleFrame[7].board_pos_X  =      		SLOT_8_X;
		singleFrame[7].board_pos_Y  =      		SLOT_8_Y;
		singleFrame[7].board_pic_Num=                  6;
		singleFrame[7].board_bg_pos_X =         SLOT_8_X;
		singleFrame[7].board_bg_pos_Y =         SLOT_8_Y;
		singleFrame[7].board_bg_pic_Num =              7;
		singleFrame[7].rect.x = 0;
		singleFrame[7].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[7].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[7].rect.h = SINGLE_FRAME_HEIGHT;
		//Frame[8]
#if TEST_MAIN_GAME_COMPUTE_SCORE==1
		singleFrame[8].setScrollType(Type_Test);
#else
		singleFrame[8].setScrollType(Type_Fixed_3);
#endif
		//singleFrame[8].slotMoveSheetObject =  &slot_move;
		singleFrame[8].pos_X        =   		SLOT_9_X;
		singleFrame[8].pos_Y        =   		SLOT_9_Y;
		singleFrame[8].pic_Num      =        Frame_9_PIC;
		singleFrame[8].offset_line  =    DEF_OFFSET_LINE;
		singleFrame[8].stopItem     =        ITEM_CHERRY;
		singleFrame[8].NextStopLine =                  0;
		singleFrame[8].StopFlag     =             false;
		singleFrame[8].Loop         =                  0;
		singleFrame[8].SideBingoFlag=             false;
		singleFrame[8].LineBingoFlag=             false;
		singleFrame[8].resetStopLine();
		singleFrame[8].resetConvertItemToStopLine(Type1);
		singleFrame[8].board_pos_X  =      		SLOT_9_X;
		singleFrame[8].board_pos_Y  =      		SLOT_9_Y;
		singleFrame[8].board_pic_Num=                  6;
		singleFrame[8].board_bg_pos_X =         SLOT_9_X;
		singleFrame[8].board_bg_pos_Y =         SLOT_9_Y;
		singleFrame[8].board_bg_pic_Num =              7;
		singleFrame[8].rect.x = 0;
		singleFrame[8].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[8].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[8].rect.h = SINGLE_FRAME_HEIGHT;
		//
		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
			this->singleFrame[i].AnimeIndex=0;
			this->singleFrame[i].AnimeLoop =0;
			this->singleFrame[i].resetPreChangeLine();
			this->singleFrame[i].scrollStatus = scroll_Stop;
		}
		//
		_stopedFrameTimes  = 0;
		sp_anime_type      = Type_none;
		sp_anime_pic_index = 0;
		sp_anime_pic_index2= 0;
		sp_anime_pic_index3= 0;
		sp_anime_pic_index4= 0;
		sp_anime_pic_index5= 0;
		sp_anime_playing   = 0;
		//
		//for(unsigned int i=0; i<sizeof(this->hanabi)/sizeof(this->hanabi[0]); i++){
			//this->hanabi[i].reset();
		//}
		//
		for(unsigned char i=0; i<sizeof(finalStopItem)/sizeof(finalStopItem[0]); i++){
			 finalStopItem[i] = 0;
		}
		//
		preStates = 0;
		renderKeyOutPaid = false;
		temp_total_out = 0;
		//
		singleFrame[0].stopMusicChannel = 7;
		singleFrame[1].stopMusicChannel = 8;
		singleFrame[2].stopMusicChannel = 9;
		singleFrame[3].stopMusicChannel = 10;
		singleFrame[4].stopMusicChannel = 11;
		singleFrame[5].stopMusicChannel = 12;
		singleFrame[6].stopMusicChannel = 13;
		singleFrame[7].stopMusicChannel = 14;
		singleFrame[8].stopMusicChannel = 15;

		this->stopActiveSoundFlag = false;

		for(unsigned int i=0; i<sizeof(FullFrameAwardRecord)/sizeof(FullFrameAwardRecord[0]); i++){
			for(unsigned int k=0; k<sizeof(FullFrameAwardRecord[0])/sizeof(FullFrameAwardRecord[0][0]); k++){
				FullFrameAwardRecord[i][k]=0;
			}
		}

		for(unsigned int i=0;i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]);i++){
			for(unsigned int j=0; j<sizeof(this->singleFrame[0].GetItemRecord)/sizeof(this->singleFrame[0].GetItemRecord[0]);j++){
				this->singleFrame[i].GetItemRecord[j]=0;
			}
		}
	}
    /**
     * @brief Compute side item's score.
     * @retval Side item's winning score
     */
	unsigned long computeSideItemScore(){
		static unsigned int allFruitTimes = 0;
	    //unsigned char tmp_item_times[9]={0,0,0,0,0,0,0,0,0};
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
		string fullAwardName[12]= {
				"",
				"FULL_AWARD_ALL_FRUIT",
				"FULL_AWARD_ANY_BAR",
				"FULL_AWARD_ORANGE",
				"FULL_AWARD_MANGO",
				"FULL_AWARD_BELL",
			    "FULL_AWARD_WATERMELON",
			    "FULL_AWARD_BAR_YELLOW",
			    "FULL_AWARD_CHERRY",
			    "FULL_AWARD_BAR_RED",
			    "FULL_AWARD_BAR_BLUE",
			    //"FULL_AWARD_SEVEN",
			    "FULL_AWARD_WILD"
		};
#endif
		//unsigned char tmp_item_times[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
		unsigned char tmp_item_times[12]={0,0,0,0,0,0,0,0,0,0,0,0};
	    unsigned long tmp_score=0;

	    //get all fruit times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_CHERRY || this->singleFrame[i].stopItem == ITEM_ORANGE ||
	    	   this->singleFrame[i].stopItem == ITEM_MANGO  || this->singleFrame[i].stopItem == ITEM_WATERMELON || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_ALL_FRUIT]++;
	    	}
	    }

	    //get any bar times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_BAR_YELLOW || this->singleFrame[i].stopItem == ITEM_BAR_RED ||
	    	   this->singleFrame[i].stopItem == ITEM_BAR_BLUE || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_ANY_BAR]++;
	    	}
	    }

	    //get orange times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_ORANGE || this->singleFrame[i].stopItem == ITEM_WILD ){
	    		tmp_item_times[FULL_AWARD_ORANGE]++;
	    	}
	    }

	    //get mango times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_MANGO || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_MANGO]++;
	    	}
	    }

	    //get bell times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_BELL || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_BELL]++;
	    	}
	    }

	    //get watermelon times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_WATERMELON || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_WATERMELON]++;
	    	}
	    }

	    //get bar yellow times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_BAR_YELLOW || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_BAR_YELLOW]++;
	    	}
	    }

	    //get cherry times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_CHERRY){
	    		tmp_item_times[FULL_AWARD_CHERRY]++;
	    	}
	    }

	    //get bar red times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_BAR_RED || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_BAR_RED]++;
	    	}
	    }

	    //get bar blue times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_BAR_BLUE || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_BAR_BLUE]++;
	    	}
	    }

	    /*
	    //get seven times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_SEVEN || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_SEVEN]++;
	    	}
	    }
	    */

	    //get wild times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_WILD]++;
	    	}
	    }

#if 0
	    //get blank times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ran_Item_Blank){
	    		tmp_item_times[side_Blank]++;
	    	}
	    }
	    //get One Bar times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ran_Item_One_Bar){
	    		tmp_item_times[side_One_Bar]++;
	    	}
	    }
	    //get Two Bar times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ran_Item_Two_Bar){
	    		tmp_item_times[side_Two_Bar]++;
	    	}
	    }
	    //get Three Bar times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ran_Item_Three_Bar){
	    		tmp_item_times[side_Three_Bar]++;
	    	}
	    }
	    //get Red 7 times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ran_Item_Red_7){
	    		tmp_item_times[side_Red_7]++;
	    	}
	    }
	    //get Blue 7 times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ran_Item_Blue_7){
	    		tmp_item_times[side_Blue_7]++;
	    	}
	    }
        //get joker times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ran_Item_Joker){
	    		tmp_item_times[side_Joker]++;
	    	}
	    }
	    //get Mix Bar times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(HaveMixCheckBar(tmp_item_times[side_Joker],tmp_item_times[side_One_Bar],tmp_item_times[side_Two_Bar],tmp_item_times[side_Three_Bar])){
				if(this->singleFrame[i].stopItem == ran_Item_One_Bar || this->singleFrame[i].stopItem == ran_Item_Two_Bar || this->singleFrame[i].stopItem == ran_Item_Three_Bar){
					tmp_item_times[side_Mix_Bar]++;
				}
	    	}
	    }
	    //get Mix 7 times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(HaveMixCheck7(tmp_item_times[side_Joker],tmp_item_times[side_Red_7],tmp_item_times[side_Blue_7])){
				if(this->singleFrame[i].stopItem == ran_Item_Red_7 || this->singleFrame[i].stopItem == ran_Item_Blue_7){
					tmp_item_times[side_Mix_7]++;
				}
	    	}
	    }

	    //Compute Item Times Add Joker Times
	    for(unsigned int i=0; i<sizeof(tmp_item_times)/sizeof(tmp_item_times[0])-1; i++){
#ifdef Genuine_Compute_Score
	    	if(true)//tmp_item_times[i] >= 0)
#else
	    	if(tmp_item_times[i] >  0)
#endif

	    	{
	    		tmp_item_times[i]+=tmp_item_times[side_Joker];
	    	}
	    }
#endif
	    //Save Final Stop Item
		for(unsigned char i=0; i<sizeof(finalStopItem)/sizeof(finalStopItem[0]); i++){
			 //finalStopItem[i] = tmp_item_times[i];
		}
	    //
	    //
		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
			this->singleFrame[i].SideBingoFlag = false;
		}
	    //

		/*** Compute total full frame score ***/
		for(unsigned int i=sizeof(tmp_item_times)/sizeof(tmp_item_times[0])-1,exit=0; i>0 && exit==0; i--){
			switch(i){

			case FULL_AWARD_UNKNOW:
				break;
			case FULL_AWARD_ALL_FRUIT:
            	if(tmp_item_times[FULL_AWARD_ALL_FRUIT] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_ALL_FRUIT-1][tmp_item_times[FULL_AWARD_ALL_FRUIT]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_ALL_FRUIT);
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecordMap.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_ALL_FRUIT],FullFrameAwardTypeMapping[FULL_AWARD_ALL_FRUIT-1][tmp_item_times[FULL_AWARD_ALL_FRUIT]] * this->bet));
                   cout<< "ALL Fruit Times : "<< ++allFruitTimes << endl;
#endif
                   FullFrameAwardRecord[FULL_AWARD_ALL_FRUIT-1][9]++;
            	}
				break;
			case FULL_AWARD_ANY_BAR:
            	if(tmp_item_times[FULL_AWARD_ANY_BAR] == 9 &&
            	   tmp_item_times[FULL_AWARD_BAR_YELLOW] != 9 &&
            	   tmp_item_times[FULL_AWARD_BAR_RED]    != 9 &&
            	   tmp_item_times[FULL_AWARD_BAR_BLUE]   != 9 &&
            	   this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_ANY_BAR-1][tmp_item_times[FULL_AWARD_ANY_BAR]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_ANY_BAR);
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecordMap.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_ANY_BAR],FullFrameAwardTypeMapping[FULL_AWARD_ANY_BAR-1][tmp_item_times[FULL_AWARD_ANY_BAR]] * this->bet));
#endif
                   FullFrameAwardRecord[FULL_AWARD_ANY_BAR-1][9]++;
            	}
				break;
			case FULL_AWARD_ORANGE:
            	if(tmp_item_times[FULL_AWARD_ORANGE] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_ORANGE-1][tmp_item_times[FULL_AWARD_ORANGE]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_ORANGE);
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecordMap.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_ORANGE],FullFrameAwardTypeMapping[FULL_AWARD_ORANGE-1][tmp_item_times[FULL_AWARD_ORANGE]] * this->bet));
#endif
                   FullFrameAwardRecord[FULL_AWARD_ORANGE-1][9]++;
            	}
				break;

			case FULL_AWARD_MANGO:
            	if(tmp_item_times[FULL_AWARD_MANGO] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_MANGO-1][tmp_item_times[FULL_AWARD_MANGO]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_MANGO);
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecordMap.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_MANGO],FullFrameAwardTypeMapping[FULL_AWARD_MANGO-1][tmp_item_times[FULL_AWARD_MANGO]] * this->bet));
#endif
                   FullFrameAwardRecord[FULL_AWARD_MANGO-1][9]++;
            	}
				break;
			case FULL_AWARD_BELL:
            	if(tmp_item_times[FULL_AWARD_BELL] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_BELL-1][tmp_item_times[FULL_AWARD_BELL]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_BELL);
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecordMap.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_BELL],FullFrameAwardTypeMapping[FULL_AWARD_BELL-1][tmp_item_times[FULL_AWARD_BELL]] * this->bet));
#endif
                   FullFrameAwardRecord[FULL_AWARD_BELL-1][9]++;
            	}
				break;
			case FULL_AWARD_WATERMELON:
            	if(tmp_item_times[FULL_AWARD_WATERMELON] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_WATERMELON-1][tmp_item_times[FULL_AWARD_WATERMELON]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_WATERMELON);
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecordMap.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_WATERMELON],FullFrameAwardTypeMapping[FULL_AWARD_WATERMELON-1][tmp_item_times[FULL_AWARD_WATERMELON]] * this->bet));
#endif
                   FullFrameAwardRecord[FULL_AWARD_WATERMELON-1][9]++;
            	}
				break;
			case FULL_AWARD_BAR_YELLOW:
            	if(tmp_item_times[FULL_AWARD_BAR_YELLOW] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_BAR_YELLOW-1][tmp_item_times[FULL_AWARD_BAR_YELLOW]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_BAR_YELLOW);
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   cout<< "This bet = " << this->bet << endl;
                   fullAwardRecordMap.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_BAR_YELLOW],FullFrameAwardTypeMapping[FULL_AWARD_BAR_YELLOW-1][tmp_item_times[FULL_AWARD_BAR_YELLOW]] * this->bet));
#endif
                   FullFrameAwardRecord[FULL_AWARD_BAR_YELLOW-1][9]++;
            	}
				break;
			case FULL_AWARD_CHERRY:
            	if(tmp_item_times[FULL_AWARD_CHERRY] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_CHERRY-1][tmp_item_times[FULL_AWARD_CHERRY]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_CHERRY);
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecordMap.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_CHERRY],FullFrameAwardTypeMapping[FULL_AWARD_CHERRY-1][tmp_item_times[FULL_AWARD_CHERRY]] * this->bet));
#endif
                   FullFrameAwardRecord[FULL_AWARD_CHERRY-1][9]++;
            	}
				break;
			case FULL_AWARD_BAR_RED:
            	if(tmp_item_times[FULL_AWARD_BAR_RED] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_BAR_RED-1][tmp_item_times[FULL_AWARD_BAR_RED]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_BAR_RED);
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecordMap.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_BAR_RED],FullFrameAwardTypeMapping[FULL_AWARD_BAR_RED-1][tmp_item_times[FULL_AWARD_BAR_RED]] * this->bet));
#endif
                   FullFrameAwardRecord[FULL_AWARD_BAR_RED-1][9]++;
            	}
				break;
			case FULL_AWARD_BAR_BLUE:
            	if(tmp_item_times[FULL_AWARD_BAR_BLUE] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_BAR_BLUE-1][tmp_item_times[FULL_AWARD_BAR_BLUE]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_BAR_BLUE);
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecordMap.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_BAR_BLUE],FullFrameAwardTypeMapping[FULL_AWARD_BAR_BLUE-1][tmp_item_times[FULL_AWARD_BAR_BLUE]] * this->bet));
#endif
                   FullFrameAwardRecord[FULL_AWARD_BAR_BLUE-1][9]++;
            	}
				break;
			/*
			case FULL_AWARD_SEVEN:
            	if(tmp_item_times[FULL_AWARD_SEVEN] >= 2 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_SEVEN-1][tmp_item_times[FULL_AWARD_SEVEN]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_SEVEN);
                   //exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   this->fullAwardRecord.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_SEVEN],FullFrameAwardTypeMapping[FULL_AWARD_SEVEN-1][tmp_item_times[FULL_AWARD_SEVEN]] * this->bet));
#endif
            	}
				break;
			*/
			case FULL_AWARD_WILD:
            	if(tmp_item_times[FULL_AWARD_WILD] >= 3 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_WILD-1][tmp_item_times[FULL_AWARD_WILD]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_WILD);
                   if(tmp_item_times[FULL_AWARD_WILD] == 9){
                	   exit=1;
                   }
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecordMap.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_WILD],FullFrameAwardTypeMapping[FULL_AWARD_WILD-1][tmp_item_times[FULL_AWARD_WILD]] * this->bet));
#endif
                   FullFrameAwardRecord[FULL_AWARD_WILD-1][tmp_item_times[FULL_AWARD_WILD]]++;
            	}
				break;

			default:
				break;
			}
		}

#ifdef DEBUG_OUTPUT_AWARD_DETAIL

		std::map<string,unsigned long>::iterator fullAwardNameIterator;
		fullAwardNameIterator = fullAwardRecordMap.begin();

		for(;fullAwardNameIterator!=fullAwardRecordMap.end();fullAwardNameIterator++){
			//printf("FULL Frame Award Type is : %s, Win is %ld \n",(*fullAwardNameIterator).first.c_str(),(*fullAwardNameIterator).second);
			cout<< (*fullAwardNameIterator).first.c_str() << " " << (*fullAwardNameIterator).second << endl;
		}

		fullAwardRecordMap.clear();

#endif

#if 0
	    //*****Compute Total Score*****//
        for(unsigned int i=0; i<sizeof(tmp_item_times)/sizeof(tmp_item_times[0])-1; i++){
            //Take Score
        	switch(i){
        	case sb_Blank:
            	if(tmp_item_times[sb_Blank] == 9 && this->sideItem[i].bet > 0 ){
                   tmp_score += SideBingoTypeM[sb_Blank][tmp_item_times[sb_Blank]-3] * this->sideItem[i].bet;
                   this->setSideBingoFlag(sb_Blank);
                }
        		break;
        	case sb_Mix_Bar:
            	if(tmp_item_times[sb_Mix_Bar] >= 6 && this->sideItem[i].bet > 0 ){
                   tmp_score += SideBingoTypeM[sb_Mix_Bar][tmp_item_times[sb_Mix_Bar]-3] * this->sideItem[i].bet;
                   this->setSideBingoFlag(sb_Mix_Bar);
                }
        		break;
        	case sb_One_Bar :
            	if(tmp_item_times[sb_One_Bar] >= 4 && this->sideItem[i].bet > 0 ){
                   tmp_score += SideBingoTypeM[sb_One_Bar][tmp_item_times[sb_One_Bar]-3] * this->sideItem[i].bet;
                   this->setSideBingoFlag(sb_One_Bar);
                }
        		break;
        	case sb_Two_Bar :
            	if(tmp_item_times[sb_Two_Bar] >= 4 && this->sideItem[i].bet > 0 ){
                   tmp_score += SideBingoTypeM[sb_Two_Bar][tmp_item_times[sb_Two_Bar]-3] * this->sideItem[i].bet;
                   this->setSideBingoFlag(sb_Two_Bar);
                }
        		break;
        	case sb_Three_Bar :
            	if(tmp_item_times[sb_Three_Bar] >= 4 && this->sideItem[i].bet > 0 ){
                   tmp_score += SideBingoTypeM[sb_Three_Bar][tmp_item_times[sb_Three_Bar]-3] * this->sideItem[i].bet;
                   this->setSideBingoFlag(sb_Three_Bar);
                }
        		break;
        	case sb_Mix_7 :
            	if(tmp_item_times[sb_Mix_7] >= 3 && this->sideItem[i].bet > 0 ){
                   tmp_score += SideBingoTypeM[sb_Mix_7][tmp_item_times[sb_Mix_7]-3] * this->sideItem[i].bet;
                   this->setSideBingoFlag(sb_Mix_7);
                }
        		break;
        	case sb_Red_7:
            	if(tmp_item_times[sb_Red_7] >= 3 && this->sideItem[i].bet > 0 ){
                   tmp_score += SideBingoTypeM[sb_Red_7][tmp_item_times[sb_Red_7]-3] * this->sideItem[i].bet;
                   this->setSideBingoFlag(sb_Red_7);
                }
        		break;
        	case sb_Blue_7:
            	if(tmp_item_times[sb_Blue_7] >= 3 && this->sideItem[i].bet > 0 ){
                   tmp_score += SideBingoTypeM[sb_Blue_7][tmp_item_times[sb_Blue_7]-3] * this->sideItem[i].bet;
                   this->setSideBingoFlag(sb_Blue_7);
                }
        		break;
        	default:
        		break;
        	}
        }

        //Compute Double Times by Joker
        for(unsigned int i=tmp_item_times[side_Joker]; i>0; i--){
        	    tmp_score *= 2;
        }
#endif
	    return tmp_score;
	}
    /**
     * @brief Get total win.
     * @retval Total win
     */
	unsigned long getTotalWin(SYSTEMSETTINGDATA* _systemSettingData){

	    string lineAwardName[13] = {
			"LINE_AWARD_NONE",
			"LINE_AWARD_ONE_CHERRY",
			"LINE_AWARD_TWO_CHERRY",
			"LINE_AWARD_THREE_CHERRY",
			"LINE_AWARD_ORANGE",
			"LINE_AWARD_MIX_BAR",
			"LINE_AWARD_MANGO",
			"LINE_AWARD_BELL",
			"LINE_AWARD_WATERMELON",
			"LINE_AWARD_BAR_YELLOW",
			"LINE_AWARD_BAR_RED",
			"LINE_AWARD_BAR_BLUE",
			//"LINE_AWARD_SEVEN",
			"LINE_AWARD_WILD",
	    };

#ifdef Max_Win_Limit

#ifdef DEBUG_OUTPUT_AWARD_DETAIL
	    printf("---------------------- AWARD DETAIL OUTPUT ----------------------\n");
#endif
	    unsigned long totalwin = 0;
		for(unsigned int i=0; i<sizeof(this->line)/sizeof(this->line[0]); i++){
		    totalwin += this->line[i].computeLineScore(this->singleFrame);
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
		    if(this->line[i].bingotype != LINE_AWARD_NONE){
		    	printf("Line %d award type is : %s, Win is %ld \n",i+1,lineAwardName[this->line[i].bingotype].c_str(),this->line[i].win);
		    }
#endif

		}
		totalwin += this->computeSideItemScore();
		if(totalwin > (((unsigned long)_systemSettingData->_MaxBet/8) * (100000)) ){
			totalwin = (((unsigned long)_systemSettingData->_MaxBet/8) * (100000));
		}

#ifdef DEBUG_OUTPUT_AWARD_DETAIL
		printf("Total win is : %ld \n",totalwin);
		printf("-----------------------------------------------------------------\n");
#endif

		return totalwin;

#else
		unsigned long tmp = 0;
		for(unsigned int i=0; i<sizeof(this->line)/sizeof(this->line[0]); i++){
		    tmp += this->line[i].computeLineScore(this->singleFrame);
		}
		return this->computeSideItemScore() + tmp;
#endif
	}
    /**
     * @brief Reset scroll parameters for re-starting.
     * @retval 0:success others:failure
     */
	unsigned int reStartScrollPara(){

		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
			this->singleFrame[i].Loop = 0;
			this->singleFrame[i].StopFlag = false;
			this->singleFrame[i].LineBingoFlag = false;
			this->singleFrame[i].SideBingoFlag = false;
			this->singleFrame[i].AnimeIndex= 0;
			this->singleFrame[i].AnimeLoop = 0;
			this->singleFrame[i].scrollStatus = scroll_Stop;//scroll_Normal;
		}

		for(unsigned int i=0; i<sizeof(this->line)/sizeof(this->line[0]); i++){
			this->line[i].bingoFlag = false;
			this->line[i].bingotype = lb_None;
			this->line[i].jokerSum  = 0;
		}

		return 0;
	}
    /**
     * @brief Get total link or side item bingo frames .
     * @retval Count
     */
	unsigned int getTotalLinkOrSideBingoFrame(){
		unsigned int result=0;
		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
			if(this->singleFrame[i].SideBingoFlag==true || this->singleFrame[i].LineBingoFlag==true){
			   result++;
			}
		}

		return result;
	}
    /**
     * @brief Check special animation.
     * @retval 0:success others:failure
     */
	unsigned int checkSpecialAnime(){
		this->sp_anime_type = Type_none;
		this->sp_anime_playing = false;
		this->sp_anime_pic_index = 0;
		this->sp_anime_pic_index2= 0;
		this->sp_anime_pic_index3= 0;
		this->sp_anime_pic_index4= 0;
		this->sp_anime_pic_index5= 0;

		//for(unsigned int i=0; i<sizeof(this->hanabi)/sizeof(this->hanabi[0]); i++){
			//this->hanabi[i].reset();
		//}

		for(unsigned int i=0; i<sizeof(this->line)/sizeof(this->line[0]); i++){
		    if(this->line[i].bingotype == lb_Joker_Straight){
		       this->sp_anime_type = Type_JOKER;
		       this->sp_anime_playing = true;
		       return 0;
		    }else if(this->line[i].bingotype == lb_Blue_7_Straight){
		       this->sp_anime_type = Type_Blue_7;
		       this->sp_anime_playing = true;
		       return 0;
		    }else if(this->line[i].bingotype == lb_Red_7_Straight){
			   this->sp_anime_type = Type_Red_7;
			   this->sp_anime_playing = true;
			   //this->hanabi[0].isCanPlay = true;
			   return 0;
			}
		}

		return 0;
	}
    /**
     * @brief Set side bingo flag.
     * @param sideBingoType Side item bingo type
     * @retval 0:success others:failure
     */
	unsigned int setSideBingoFlag(unsigned int sideBingoType){

		switch(sideBingoType){

		case FULL_AWARD_UNKNOW:
			break;
		case FULL_AWARD_ALL_FRUIT:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_CHERRY || this->singleFrame[i].stopItem == ITEM_ORANGE ||
    			   this->singleFrame[i].StopFlag == ITEM_MANGO  || this->singleFrame[i].stopItem == ITEM_WATERMELON || this->singleFrame[i].stopItem == ITEM_WILD ){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_ORANGE:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_ORANGE || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_ANY_BAR:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_BAR_YELLOW || this->singleFrame[i].stopItem == ITEM_BAR_RED ||
    			   this->singleFrame[i].StopFlag == ITEM_BAR_BLUE || this->singleFrame[i].stopItem == ITEM_WILD ){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_MANGO:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_MANGO || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_BELL:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_BELL || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_WATERMELON:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_WATERMELON || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_CHERRY:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_CHERRY || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_BAR_YELLOW:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_BAR_YELLOW || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_BAR_RED:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_BAR_RED || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_BAR_BLUE:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_BAR_BLUE || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		/*
		case FULL_AWARD_SEVEN:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_SEVEN || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		*/
		case FULL_AWARD_WILD:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
#if 0
    	case sb_Blank:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ran_Item_Blank || this->singleFrame[i].stopItem == ran_Item_Joker ){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
    		break;
    	case sb_Mix_Bar:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ran_Item_One_Bar || this->singleFrame[i].stopItem == ran_Item_Two_Bar || this->singleFrame[i].stopItem == ran_Item_Three_Bar ||
    			   this->singleFrame[i].stopItem == ran_Item_Joker){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
    		break;
    	case sb_One_Bar :
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ran_Item_One_Bar ||
    			   this->singleFrame[i].stopItem == ran_Item_Joker){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
    		break;
    	case sb_Two_Bar :
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ran_Item_Two_Bar ||
    			   this->singleFrame[i].stopItem == ran_Item_Joker){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
    		break;
    	case sb_Three_Bar :
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ran_Item_Three_Bar ||
    			   this->singleFrame[i].stopItem == ran_Item_Joker){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
    		break;
    	case sb_Mix_7 :
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ran_Item_Red_7 || this->singleFrame[i].stopItem == ran_Item_Blue_7 ||
    			   this->singleFrame[i].stopItem == ran_Item_Joker){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
    		break;
    	case sb_Red_7:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ran_Item_Red_7 ||
    			   this->singleFrame[i].stopItem == ran_Item_Joker){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
    		break;
    	case sb_Blue_7:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ran_Item_Blue_7 ||
    			   this->singleFrame[i].stopItem == ran_Item_Joker){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
    		break;
#endif
		default:
			break;
		}

		return 0;
	}
    /**
     * @brief Get if all frame's status are normal.
     * @retval true:normal false:not normal
     */
	unsigned char getIfAllFrameStatusNormal(){
		//unsigned char retval;

		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
			if(this->singleFrame[i].scrollStatus != scroll_Normal){
				return false;
			}
		}

        return true;
	}

}MAINGAMEFRAME;

/**
 * @brief Double down game frame.
 */
typedef struct{
 	Line line;/**< In Double Up Game Only Have One Line */
	SingleFrame singleFrame[4];/**< In Double Up Game Have Four Frame [0]:dealer [1]:player left [2]:player center [3]:player right */
	bool selectedFrame[3];/**< Indicate which frame be selected */
	unsigned long lineWin;/**< Line win */
	unsigned int playerSelected;/**< Which frame player selected */
	unsigned char gameResult;/**< One turn result */

	/**
	 * @brief Reset all member parameters.
	 */
	void ramClearReset(){
		// Reset Selected Frame
        this->reSetPlayerSelectStatus();
		// Line Parameters Reset
        this->line.reset();
        // Set Line Bingo Frame
        this->line.setBingoFrame(1,2,3);
        // Set Line Render Parameters(in fact,we no need to set it in DOUBLEFRAME,but we initial these parameters)
        this->line.resetLineRenderPara(1,1,1);


        //SingleFrame ReSet
        //Frame[0] : dealer
#if TEST_MAIN_GAME_COMPUTE_SCORE==1
		singleFrame[0].setScrollType(Type_Test);
#else
		singleFrame[0].setScrollType(Type_Fixed_6);
#endif
		//singleFrame[0].slotMoveSheetObject =        &slot1;
		singleFrame[0].pos_X        =        DG_SLOT_1_X;
		singleFrame[0].pos_Y        =        DG_SLOT_1_Y;
		singleFrame[0].pic_Num      =        Frame_1_PIC;
		singleFrame[0].offset_line  =        	    1257;
		singleFrame[0].stopItem     =                  0;
		singleFrame[0].NextStopLine =                  0;
		singleFrame[0].StopFlag     =             false;
		singleFrame[0].Loop         =                  0;
		singleFrame[0].SideBingoFlag=             false;
		singleFrame[0].LineBingoFlag=             false;
		singleFrame[0].resetStopLine();
		singleFrame[0].resetConvertItemToStopLine(Type1);
		singleFrame[0].board_pos_X  =        DG_SLOT_1_X;
		singleFrame[0].board_pos_Y  =        DG_SLOT_1_Y;
		singleFrame[0].board_pic_Num=                  6;
		singleFrame[0].board_bg_pos_X =      DG_SLOT_1_X;
		singleFrame[0].board_bg_pos_Y =      DG_SLOT_1_Y;
		singleFrame[0].board_bg_pic_Num =              7;
		singleFrame[0].rect.x = 0;
		singleFrame[0].rect.y = 793;
		singleFrame[0].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[0].rect.h = SINGLE_FRAME_HEIGHT;
		//Frame[1] : player left
#if TEST_MAIN_GAME_COMPUTE_SCORE==1
		singleFrame[1].setScrollType(Type_Test);
#else
		singleFrame[1].setScrollType(Type_Fixed_7);
#endif
		//singleFrame[1].slotMoveSheetObject =        &slot2;
		singleFrame[1].pos_X        =        DG_SLOT_2_X;
		singleFrame[1].pos_Y        =        DG_SLOT_2_Y;
		singleFrame[1].pic_Num      =   	 Frame_2_PIC;
		singleFrame[1].offset_line  =        	    1257;
		singleFrame[1].stopItem     =                  0;
		singleFrame[1].NextStopLine =                  0;
		singleFrame[1].StopFlag     =             false;
		singleFrame[1].Loop         =                  0;
		singleFrame[1].SideBingoFlag=             false;
		singleFrame[1].LineBingoFlag=             false;
		singleFrame[1].resetStopLine();
		singleFrame[1].resetConvertItemToStopLine(Type2);
		singleFrame[1].board_pos_X  =        DG_SLOT_2_X;
		singleFrame[1].board_pos_Y  =        DG_SLOT_2_Y;
		singleFrame[1].board_pic_Num=                  6;
		singleFrame[1].board_bg_pos_X =      DG_SLOT_2_X;
		singleFrame[1].board_bg_pos_Y =      DG_SLOT_2_Y;
		singleFrame[1].board_bg_pic_Num =              7;
		singleFrame[1].rect.x = 0;
		singleFrame[1].rect.y = 793;
		singleFrame[1].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[1].rect.h = SINGLE_FRAME_HEIGHT;
		//Frame[2] : player center
#if TEST_MAIN_GAME_COMPUTE_SCORE==1
		singleFrame[2].setScrollType(Type_Test);
#else
		singleFrame[2].setScrollType(Type_Fixed_8);
#endif
		//singleFrame[2].slotMoveSheetObject =        &slot3;
		singleFrame[2].pos_X        =        DG_SLOT_3_X;
		singleFrame[2].pos_Y        =        DG_SLOT_3_Y;
		singleFrame[2].pic_Num      =        Frame_3_PIC;
		singleFrame[2].offset_line  =        	    1257;
		singleFrame[2].stopItem     =                  0;
		singleFrame[2].NextStopLine =                  0;
		singleFrame[2].StopFlag     =             false;
		singleFrame[2].Loop         =                  0;
		singleFrame[2].SideBingoFlag=             false;
		singleFrame[2].LineBingoFlag=             false;
		singleFrame[2].resetStopLine();
		singleFrame[2].resetConvertItemToStopLine(Type3);
		singleFrame[2].board_pos_X  =        DG_SLOT_3_X;
		singleFrame[2].board_pos_Y  =        DG_SLOT_3_Y;
		singleFrame[2].board_pic_Num=                  6;
		singleFrame[2].board_bg_pos_X =      DG_SLOT_3_X;
		singleFrame[2].board_bg_pos_Y =      DG_SLOT_3_Y;
		singleFrame[2].board_bg_pic_Num =              7;
		singleFrame[2].rect.x = 0;
		singleFrame[2].rect.y = 793;
		singleFrame[2].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[2].rect.h = SINGLE_FRAME_HEIGHT;
		//Frame[3] : player right
#if TEST_MAIN_GAME_COMPUTE_SCORE==1
		singleFrame[3].setScrollType(Type_Test);
#else
		singleFrame[3].setScrollType(Type_Fixed_4);
#endif
		//singleFrame[3].slotMoveSheetObject =        &slot4;
		singleFrame[3].pos_X        =        DG_SLOT_4_X;
		singleFrame[3].pos_Y        =   	 DG_SLOT_4_Y;
		singleFrame[3].pic_Num      =        Frame_4_PIC;
		singleFrame[3].offset_line  =        	    1257;
		singleFrame[3].stopItem     =                  0;
		singleFrame[3].NextStopLine =                  0;
		singleFrame[3].StopFlag     =             false;
		singleFrame[3].Loop         =                  0;
		singleFrame[3].SideBingoFlag=             false;
		singleFrame[3].LineBingoFlag=             false;
		singleFrame[3].resetStopLine();
		singleFrame[3].resetConvertItemToStopLine(Type4);
		singleFrame[3].board_pos_X  =      	 DG_SLOT_4_X;
		singleFrame[3].board_pos_Y  =      	 DG_SLOT_4_Y;
		singleFrame[3].board_pic_Num=                  6;
		singleFrame[3].board_bg_pos_X =      DG_SLOT_4_X;
		singleFrame[3].board_bg_pos_Y =      DG_SLOT_4_Y;
		singleFrame[3].board_bg_pic_Num =              7;
		singleFrame[3].rect.x = 0;
		singleFrame[3].rect.y = 793;
		singleFrame[3].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[3].rect.h = SINGLE_FRAME_HEIGHT;

	}

	/*
	 * @brief Reset player's selection status.
	 */
	void reSetPlayerSelectStatus(){
	    for(int i=0; i<3; i++){
	       selectedFrame[i] = dg_frame_not_selected;
	    }
	}

	/**
	 * @brief Reset scroll parameters for re-starting
	 * @retval Success or not
	 */
	unsigned int reStartScrollPara(){
		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
			this->singleFrame[i].Loop = 0;
			this->singleFrame[i].StopFlag = false;
			this->singleFrame[i].LineBingoFlag = false;
			this->singleFrame[i].SideBingoFlag = false;
			this->singleFrame[i].AnimeIndex= 0;
			this->singleFrame[i].AnimeLoop = 0;
			this->singleFrame[i].scrollStatus = scroll_Stop;//scroll_Normal;
		}

		this->line.bingoFlag = false;
		this->line.bingotype = lb_None;
		this->line.jokerSum  = 0;

		return 0;
	}

	/**
	 * @brief Get double down game's result.
	 * @retval Result
	 */
	int getDGameResult(){
		/*
		unsigned int selectedIndex=0;
		int result = dg_result_unknow;

        // Get Selected Index First
        for(int i=0; i<3; i++){
           if(this->selectedFrame[i]==dg_frame_selected){
               selectedIndex = i;
               break;
           }
        }

        // Start Compare Item
		// 1.push
		if(this->singleFrame[0].stopItem == this->singleFrame[selectedIndex+1].stopItem){
           result = dg_result_push;
		}else if(this->singleFrame[0].stopItem < this->singleFrame[selectedIndex+1].stopItem){
		   result = dg_result_player_win;
		}else if(this->singleFrame[0].stopItem > this->singleFrame[selectedIndex+1].stopItem){
		   result = dg_result_dealer_win;
		}

		return result;
		*/
		return 0;
	}


}DOUBLEGAMEFRAME;

#endif /* GAMELOGICTYPE_H_ */

