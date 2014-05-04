/**
 * @file gameSettingValueType.h
 * @brief declare game structure type.
 *
 */

#ifndef GAMESETTINGVALUETYPE_H_
#define GAMESETTINGVALUETYPE_H_

#include "../preprocessor/preprocessor.h"
#include "../probability/probabilityEnum.h"
#include "gameDefine.h"
#include "gameEnum.h"

/**
 * @brief Double Game Run Time Setting.
 */
typedef struct DoubleGameRunTime{

	unsigned int _enable;
	unsigned int _runToDead;

	/**
	 * @brief Constructor.
	 */
	DoubleGameRunTime(){
		this->_enable = 1;
		this->_runToDead = 0;
	}

	/**
	 * @Reset.
	 */
	void Reset(void){
		this->_enable = 1;
		this->_runToDead = 0;
	}

}DOUBLEGAMERUNTIME;

/**
 * @brief System Setting Data Structure.
 */
typedef struct SystemSettingData{
   unsigned int  _CoinValue;/**< Coin value */
   unsigned int  _KeyInKeyOut;/**< Key IN/OUT value */
   unsigned int  _MaxBet;/**< Max bet */
   unsigned int  _MinBet;/**< Minimal bet */
   unsigned int  _HoperMaxPay;/**< Hopper max pay */
   unsigned int  _CreditUpLimit;/**< Credit up limit */
   unsigned int  _CreditInLimit;/**< Credit in limit */
   unsigned int  _DDWNOfOverMaxWin;/**< Double down over max win value */
   unsigned int  _DoubleDownKind;/**< Double down return type */
   unsigned int  _DoubleDown;/**< Double down type */
   unsigned int  _GameLevel;/**< Game level */
   unsigned int  _GameLevel_Link;/**< Game level(linking) */
   unsigned int  _QuickCollect;/**< Quick collect */
   unsigned int  _ReelSpinSpeed;/**< Reel spin speed */
   unsigned int  _FrameColor;/**< Frame color */
   unsigned int  _ScreenColor;/**< Screen color */
   unsigned int  _KeyInOutFunction;/**< Key IN/OUT function */
   unsigned int  _Scroll_Offset_Delta_Time;/**< Scroll offset delta time */
   unsigned int  _Scroll_Offset_Delta_Pixel;/**< Scroll offset delta pixel */
   unsigned int  _Scroll_Offset_Delta_Pixel_Step2;/**< Scroll offset delta pixel step 2 */
   unsigned int  _CoinAcceptor;/**< Coin acceptor */
   unsigned int  _BillAcceptor;/**< Bill acceptor */
   unsigned int  _CoinInLimit;/**< Coin in limit */
   unsigned int  _KeyInLimit;/**< Key in limit */
   unsigned int  _BetUnit;/**< Bet unit */
   unsigned int  _HopperSetting;/**< Hopper setting(NC/NO) */

   /**
    * @brief Reset all member.
    */
   void clearRamReset(){
	   _CoinValue         = default_Coin_Value;
	   _KeyInKeyOut       = default_KeyInKeyOut;
	   _MaxBet            = default_MaxBetSet;
	   _MinBet            = default_MinBetSet;
	   _HoperMaxPay       = default_Hopper_Max_Pay;
	   _CreditUpLimit     = default_Credit_Up_Limit;
	   _CreditInLimit     = default_Credit_In_Limit;
	   _DDWNOfOverMaxWin  = default_DDown_Of_Max_Win;
	   _DoubleDownKind    = default_Double_Down_Kind;
	   _DoubleDown        = default_Double_Kind;
	   _GameLevel         = default_Game_Level;
	   _GameLevel_Link    = default_Game_Level;
	   _QuickCollect      = default_Quick_Collect;
	   _ReelSpinSpeed     = default_Reel_Spin_Speed;
	    this->setReelSpinInnerValue(_ReelSpinSpeed);
	   _FrameColor        = default_Frame_Color;
	   _ScreenColor       = default_Screen_Color;
	   _KeyInOutFunction  = default_KEYINOUT_FUNC;
       _CoinAcceptor      = default_coin_acceptor;
	   _BillAcceptor      = default_bill_acceptor;
	   _CoinInLimit       = default_coin_in_limit;
	   _KeyInLimit        = default_key_in_limit;
	   _BetUnit           = default_bet_unit;
	   _HopperSetting     = default_hopper_setting;
   }

   /**
    * @brief Set reel spin inner value.
    */
   void setReelSpinInnerValue(int super){
	   switch(super){
	   case Reel_Spin_Speed_Slow:
		   _Scroll_Offset_Delta_Time        = default_Scroll_Offset_Delta_Time_Slow;//
		   _Scroll_Offset_Delta_Pixel       = default_Scroll_Offset_Delta_Pixel_Slow;//
		   _Scroll_Offset_Delta_Pixel_Step2 = default_Scroll_Offset_Delta_Pixel_Step2_Slow;//
		   break;
	   case Reel_Spin_Speed_Normal:
		   _Scroll_Offset_Delta_Time        = default_Scroll_Offset_Delta_Time_Normal;//
		   _Scroll_Offset_Delta_Pixel       = default_Scroll_Offset_Delta_Pixel_Normal;//
		   _Scroll_Offset_Delta_Pixel_Step2 = default_Scroll_Offset_Delta_Pixel_Step2_Normal;//
		   break;
	   case Reel_Spin_Speed_Fast:
		   _Scroll_Offset_Delta_Time        = default_Scroll_Offset_Delta_Time_Fast;//
		   _Scroll_Offset_Delta_Pixel       = default_Scroll_Offset_Delta_Pixel_Fast;//
		   _Scroll_Offset_Delta_Pixel_Step2 = default_Scroll_Offset_Delta_Pixel_Step2_Fast;//
		   break;
	   default:
		   break;
	   }
   }
}SYSTEMSETTINGDATA;

/**
 * @brief Probability Setting Data Structure.
 */
typedef struct ProbabilitySettingData{
 double           _MainProSetting;/**< Main game probability setting */
 double           _MainProSetting_Link;/**< Main game probability setting(Linking) */
 double           _DoubleProSetting;/**< Double down game probability setting */
 unsigned int    _JackPot1_Setting_Default;/**< JACPOT1 default value */
 unsigned int    _JackPot2_Setting_Default;/**< JACPOT2 default value */
 unsigned int    _JackPot3_Setting_Default;/**< JACPOT3 default value */
 unsigned int    _JackPot1_Setting_Max;/**< JACPOT1 max value */
 unsigned int    _JackPot2_Setting_Max;/**< JACPOT2 max value */
 unsigned int    _JackPot3_Setting_Max;/**< JACPOT3 max value */

 unsigned char   _GetJacpotType;/**< Type of getting JACKPOT(Auto/Manual) */

 double*           D_ProSetting;/**< Fixed probability pointer of double down game */
 unsigned int     D_ProSetting_Value;/**< Fixed probability value of double down game */

 /**
  * @brief Reset All Member Parameters.
  */
 void clearRamReset(){
	 _MainProSetting           =  default_pro_MainPro;
	 _MainProSetting_Link      =  default_pro_MainPro_Link;
	 _DoubleProSetting         =  default_pro_DoublePro;
	 _JackPot1_Setting_Default =  default_pro_JackPot1_Default;
	 _JackPot2_Setting_Default =  default_pro_JackPot2_Default;
	 _JackPot3_Setting_Default =  default_pro_JackPot3_Default;
	 _JackPot1_Setting_Max     =  default_pro_JackPot1_Max;
	 _JackPot2_Setting_Max     =  default_pro_JackPot2_Max;
	 _JackPot3_Setting_Max     =  default_pro_JackPot3_Max;

	 _GetJacpotType            =  jac_AddToCredit;

	 D_ProSetting_Value=101;
	 D_ProSetting=&_DoubleProSetting;

 }
}PROBABILITYSETTINGDATA;

/**
 * @brief Bonus Setting Data Structure.
 */
typedef struct BonusSettingData{
  unsigned char  _JokerOver4_OnOff;/**< MainGame JokerOver4  On/Off Setting */
  unsigned char  _Blue7Over6_OnOff;/**< MainGame Blue7Over6  On/Off Setting */
  unsigned char  _Red7Over6_OnOff;/**< MainGame Red7Over6   On/Off Setting */
  unsigned char  _Bar3Over6_OnOff;/**< MainGame Bar3Ov er6  On/Off Setting */
  unsigned char  _DDown_JokerX3_OnOff;/**< Double Down Joker X3 On/Off Setting */
  unsigned char  _DDown_7PlusBlue7_OnOff;/**< Double Down 7 and Blue 7 X3(including Joker) On/Off Setting */

  unsigned char  _JokerOver4_OnOff_link;/**< MainGame JokerOver4  On/Off Setting(when link) */
  unsigned char  _Blue7Over6_OnOff_link;/**< MainGame Blue7Over6  On/Off Setting(when link) */
  unsigned char  _Red7Over6_OnOff_link;/**< MainGame Red7Over6   On/Off Setting(when link) */
  unsigned char  _Bar3Over6_OnOff_link;/**< MainGame Bar3Ov er6  On/Off Setting(when link) */
  unsigned char  _DDown_JokerX3_OnOff_link;/**< Double Down Joker X3 On/Off Setting(when link) */
  unsigned char  _DDown_7PlusBlue7_OnOff_link;/**< Double Down 7 and Blue 7 X3(including Joker) On/Off Setting(when link) */

  /**
   * @brief Reset All Member Parameters.
   */
  void clearRamReset(){
	  _JokerOver4_OnOff         = default_JokerOver4_OnOff;
	  _Blue7Over6_OnOff         = default_Blue7Over6_OnOff;
	  _Red7Over6_OnOff          = default_Red7Over6_OnOff;
	  _Bar3Over6_OnOff          = default_Bar3Over6_OnOff;
	  _DDown_JokerX3_OnOff      = default_DDown_JokerX3_OnOff;
	  _DDown_7PlusBlue7_OnOff   = default_DDown_7PlusBlue7_OnOff;

	  _JokerOver4_OnOff_link       = default_JokerOver4_OnOff_link;
	  _Blue7Over6_OnOff_link       = default_Blue7Over6_OnOff_link;
	  _Red7Over6_OnOff_link        = default_Red7Over6_OnOff_link;
	  _Bar3Over6_OnOff_link        = default_Bar3Over6_OnOff_link;
	  _DDown_JokerX3_OnOff_link    = default_DDown_JokerX3_OnOff_link;
	  _DDown_7PlusBlue7_OnOff_link = default_DDown_7PlusBlue7_OnOff_link;
  }

}BONUSSETTINGDATA;

/**
 * @brief Connect Setting.
 */
typedef struct{
	unsigned int  _LinkFuncOnOff;/**< Link function ON/OFF */
	unsigned char _LinkID;/**< Link ID */
	unsigned char _MaxLinkMount;/**< Max Link count */

	/**
	 * @brief Reset All Member Parameters.
	 */
	void clearRamReset(){
		_LinkFuncOnOff = default_Connect_Func_OnOff; // 1.連線功能開啟關閉
		_LinkID        = default_LINKID;             // 2.連線ID
		_MaxLinkMount  = default_Max_id;             // 3.最大連線台數
	}

}CONNECTSETTING;
/**
 * @brief Time Setting.
 */
typedef struct{
    unsigned int _year;
    unsigned int _month;
    unsigned int _date;
    unsigned int _week;
    unsigned int _hour;
    unsigned int _minute;

	/**
	 * @brief Reset All Member Parameters.
	 */
    void reset(){
    	this->_year  = 0;
    	this->_month = 0;
    	this->_date  = 0;
    	this->_week  = 0;
    	this->_hour  = 0;
    	this->_minute= 0;
    }

}TIMESETTING;


#endif /* GAMETYPE_H_ */

