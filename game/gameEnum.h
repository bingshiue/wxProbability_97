/**
 * @file gameEnum.h
 * @brief define game enumeration.
 *
 */

#ifndef GAMEENUM_H_
#define GAMEENUM_H_

#include "../preprocessor/preprocessor.h"

/**
 * @brief Which image using by every Frame.
 */
enum ScrollImageType{
    Type1       = 0,           /**< Type 1 */
	Type2       = 1,           /**< Type 2 */
	Type3       = 2,           /**< Type 3 */
	Type4       = 3,           /**< Type 4 */
	Type5       = 4            /**< Type 5 */
};

/**
 * @brief Special Bonus Animation.
 */
enum SpecialAnimeType{
	Type_none   = 0,           /**< No Special Bonus Animation */
	Type_Red_7  = 1,           /**< Special Bonus Animation of Red 7 Straight */
	Type_Blue_7 = 2,           /**< Special Bonus Animation of Blue 7 Straight */
	Type_JOKER  = 3            /**< Special Bonus Animation of Joker Straight */
};

/**
 * @brief JackPot Kind.
 */
enum JacPotKind{
    jacKind_None = 0,          /**< JackPot Kind Default */
    jacKind_jp1  = 1,          /**< JackPot Kind 1 */
    jacKind_jp2  = 2,          /**< JackPot Kind 2 */
    jacKind_jp3  = 3           /**< JackPot Kind 3 */
};

/**
 * @brief Get JacPot Scores Type.
 */
enum GetJacpotType{
	jac_AddToCredit        = 0,/**< Add JacPot Scores To Credit Directly */
	jac_PressKeyoutToClear = 1 /**< Press Key-Out Key To Clear JacPot Scores(Don't Add To Credit) */
};

/**
 * @brief Bonus Setting Type.
 */
enum BonusSettingMaster{
	DonotListenToMaster    = 0,/**< Follow Slave's  Setting Value */
	ListenToMaster         = 1 /**< Follow Master's Setting Value */
};

/**
 * @brief Special Information Render Pattern.
 */
enum SpInfoRenderPattern{
	SPPATTERN_Clr          = 0,/**< Pattern Clear */
	SPPATTERN_1            = 1,/**< Pattern 1 */
	SPPATTERN_2            = 2 /**< Pattern 2 */
};
/*
 * @brief MOTT Mode.
 */
enum MottMode{
	mott_key_in  = 0,/**< MOTT Key In */
	mott_key_out = 1,/**< MOTT Key Out */
	mott_coin_in = 2,/**< MOTT Coin In */
	mott_coin_out= 3 /**< MOTT Coin Out */
};
/*
 * @brief Scroll Status ENUM.
 */
enum ScrollStatus{
	scroll_Stop      = 0,/**< Stop      Status */
	scroll_Normal    = 1,/**< Normal    Status */
	scroll_Temp      = 2,/**< TEMP      Status */
	scroll_PreChange = 3,/**< PreChange Status */
	scroll_ToStop    = 4,/**< ToStop    Status */
	scroll_Temp2     = 5,/**< TEMP2     Status */
};

/**
 * @brief Double down return kind.
 */
enum DoubleDownKind{
     DDownKind_Standard  = 0,/**< Standard Type Manual */
     DDownKind_Auto      = 1 /**< Auto Mode */
};
/**
 * @brief Double down kind.
 */
enum DoubleDown{
	 DDown_None          = 0,/**< No double down game */
	 DDown_OneTime       = 1,/**< Can only play one turn */
	 DDown_Half          = 2,/**< Allow half style */
	 DDown_Over100000    = 3 /**< Over 100000 coins can't enter double down game */
};

/**
 * @brief quick collect.
 */
enum QuickCollect{
     QuickCollect_OFF = 0,/**< quick collect off */
     QuickCollect_ON  = 1 /**< quick collect on */
};
/**
 * @brief Reel spin speed.
 */
enum ReelSpinSpeed{
	 Reel_Spin_Speed_Slow   = 0,/**< slow */
	 Reel_Spin_Speed_Normal = 1,/**< normal */
	 Reel_Spin_Speed_Fast   = 2 /**< fast */
};
/**
 * @brief Color of Frame.
 */
enum FrameColor{
     Frame_Color_White              = 0,/**< Frame color white */
	 Frame_Color_Yellow             = 1,/**< Frame color yellow */
	 Frame_Color_Green              = 2,/**< Frame color green */
	 Frame_Color_Blue               = 3,/**< Frame color blue */
	 Frame_Color_Purple             = 4,/**< Frame color purple */
	 Frame_Color_Pink               = 5 /**< Frame color pink */
};
/**
 * @brief Color of BackGround.
 */
enum ScreenColor{
	 Screen_Color_Black             = 0,/**< BackGround color black */
	 Screen_Color_Brown             = 1,/**< BackGround color brown */
	 Screen_Color_Green             = 2,/**< BackGround color green */
	 Screen_Color_Light_Green       = 3,/**< BackGround color light green */
	 Screen_Color_Blue              = 4,/**< BackGround color blue */
	 Screen_Color_Purple            = 5 /**< BackGround color purple */
};

/**
 * @brief Key In/Out Function.
 */
enum KEYINOUTFUNC{
	 KeyInOut_Func_OFF = 0,/**< Key In/Out Function off */
	 KeyInOut_Func_ON  = 1 /**< Key In/Out Function on */
};

/**
 * @brief Generic Enable Disable ENUM.
 */
enum GenericEnableDisable{
	 Disable = 0,/**< disable */
	 Enable  = 1,/**< enable */
};
/**
 * @brief hopper setting NO/NC.
 */
enum HOPPERSETTING{
	 hopper_NO = 0,/**< NO */
	 hopper_NC = 1,/**< NC */
};

/**
 * @brief Bonus Setting On/Off ENUM.
 */
enum BONUSSETTINGONOFF{
	 Bonu_Type_OFF = 0,/**< Bonus type on */
	 Bonu_Type_ON  = 1 /**< Bonus type off */
};

/**
 * @brief LINK FUNCTION On/Off.
 */
enum LINKFUNCONOFF{
     Link_Function_OFF = 0,/**< Link function on */
	 Link_Function_ON  = 1 /**< Link function off */
};

/**
 * @brief DoubleUP Key Mode.
 */
enum DOUBLEUPKEYMOD{
	Start = 0,/**< start */
	Score = 1,/**< score */
	None  = 2 /**< none */
};

/**
 * @brief MainGameCreditsInfo Task Item Draw Flag Enumeration.
 */
enum MAINGAMECREDITSINFOITEMFLAG{
    main_item_none                =  0x00000000,/**< none */
	main_item_credits             =  0x00000001,/**< draw credits */
    main_item_wager               =  0x00000010,/**< draw wager */
    main_item_win                 =  0x00000100,/**< draw win */
    main_item_paid                =  0x00001000,/**< draw paid */
    main_item_keyout_coinout_paid =  0x00010000,/**< draw key-out or coin-out paid */
    main_item_all                 =  0x00011111,/**< draw all */
};

/**
 * @brief DoubleGameCreditsInfo Task Item Draw Flag Enumeration.
 */
enum DOUBLEGAMECREDITSINFOITEMFLAG{
    dg_item_none       =  0x00000000,/**< none */
    dg_item_credits    =  0x00000001,/**< draw credits */
    dg_item_wager      =  0x00000010,/**< draw wager */
    dg_item_win        =  0x00000100,/**< draw win */
    dg_item_paid       =  0x00001000,/**< draw paid */
    dg_item_save       =  0x00010000,/**< draw save */
    dg_item_slotwin    =  0x00100000,/**< draw slot win */
    dg_item_collectable=  0x01000000,/**< draw collectable */
    dg_item_trylucky   =  0x10000000,/**< draw try lucky */
#if defined(PIC_ORIGINAL) || defined(PIC_OCEAN)
    dg_item_initial    =  dg_item_credits | dg_item_wager | dg_item_slotwin | dg_item_collectable | dg_item_trylucky,/**< initial */
#else
    dg_item_initial    =  dg_item_credits | dg_item_wager | dg_item_win | dg_item_slotwin | dg_item_collectable | dg_item_trylucky | dg_item_save,/**< initial */
#endif
    dg_item_all        =  0x11111111,/**< draw all */

};

/**
 * @brief DoubleGameInfo Task Item Draw Flag Enumeration.
 */
enum DOUBLEGAMEINFOITEMFLAG{
    dg_info_item_none         =  0x00000000,/**< none */
    dg_info_item_slotplay     =  0x00000001,/**< draw slot play */
    dg_info_item_info         =  0x00000010,/**< draw information */
    dg_info_item_underinfo    =  0x00000100,/**< draw under information */
    dg_info_item_playerselect =  0x00001000,/**< player select */
    dg_info_item_halfdouble   =  0x00010000,/**< half double */
    dg_info_item_initial      =  dg_info_item_slotplay | dg_info_item_underinfo | dg_info_item_halfdouble,/**< initial */
    dg_info_item_all          =  0x00011111,/**< draw all */
};

/**
 * @brief Main BG Draw Type Task Enumeration.
 *
 * @author SHIE-BINGSHIUE
 * @date 2010-09-08
 */
enum MAINBGDRAWTYPE{
    main_bg_draw_type_auto_delete = 0,/**< Draw full size,then auto delete */
    main_bg_draw_type_no_auto_delete,/**< Draw full size,but don't auto delete */
    main_bg_draw_type_limit_rectangle,/**< Draw clip-rectangle,then auto delete */
};

/**
 * @brief Double BG Draw Type Task Enumeration.
 *
 * @author SHIE-BINGSHIUE
 * @date 2010-09-08
 */
enum DOUBLEBGDRAWTYPE{
	double_bg_draw_type_auto_delete = 0,/**< Draw full size,then auto delete */
	double_bg_draw_type_no_auto_delete,/**< Draw full size,but don't auto delete */
	double_bg_draw_type_limit_rectangle,/**< Draw clip-rectangle,then auto delete */
};

/**
 * @brief Double down player select.
 */
enum DDownPlayerSelect{
	select_left   = 0,
	select_middle = 1,
	select_right  = 2,
};

/**
 * @brief Main Game Step Enumeration.
 *
 * @author SHIE-BINGSHIUE
 * @date 2010-08-19
 */
enum MAINGAMESTEP{
	main_step_StandBy   = 0,/**< Standby */
	main_step_SlotStartPrepare,/**< Prepare for starting slot */
	//main_step_SlotStart_Step1,
	//main_step_SlotStart_Step2,
	//main_step_SlotStart_Step3,
    //main_step_SlotStop,
	main_step_SlotScroll,/**< Slot scroll */
    main_step_WaitNoWin,/**< Wait if no win */
    main_step_WaitIfWin,/**< Wait if win */
    main_step_CheckSPAnime_1,/**< Check Animation 1 */
    main_step_CheckSPAnime_2,/**< Check Animation 2 */
    main_step_CheckResult,/**< Check this turn win or not */
    main_step_SlotWinning,/**< Winning */
    main_step_AddWinningCredits,/**< Add scores */
    main_step_EnterDDownOrNot,/**< Enter Double Down or not */
    main_step_JackpotSync,/**< Get Jackpot Synchronize */
    main_step_GetJackpot,/**< Get Jackpot Action */
    main_step_JackpotEnd,/**< Get Jackpot End */
    main_step_CallAttend,/**< Call Attendance */
    main_step_SlotStopToCGA,/**< Tell CGA Slot Stop */
    main_step_OneTurnEndToCGA,/**< Tell CGA One Turn End */
    main_step_AddWinToCreditOver,/**< Tell CGA Add Win To Credit Over */

};

/**
 * @brief Double Game Step Enumeration.
 *
 * @author SHIE-BINGSHIUE
 * @data 2010-09-08
 */
enum DOUBLEGAMESTEP{
    dg_step_StandBy     = 0,/**< Standby */
    dg_step_SlotStartprepare,/**< Prepare for starting slot */
    dg_step_SlotStart_Step1,/**< Start Step 1 */
    dg_step_SlotStart_Step2,/**< Start Step 2 */
    dg_step_SlotStop_Dealer,/**< Stop of dealer */
    dg_step_SlotReel_WaitUtilGet3Item,/**< Wait until get 3 item */
    dg_step_SlotStop_Not_Selected,/**< Stop item that not be selected */
    dg_step_SlotStop_Player,/**< Stop item player selected */
    dg_step_RequestResult,/**< Request for One turn result */
    dg_step_CheckResult,/**< Check result */
    dg_step_SlotAnimation,/**< Slot animation */
    dg_step_AfterAnimation,/**< After slot animation */
    dg_step_SlotWinning,/**< Winning */
    dg_step_SlotLosing,/**< Losing */
    dg_step_SlotPushing,/**< Pushing */
    dg_step_AddWinningScoreToCredits,/**< Add winning scores to credits */
    dg_step_LosingWaitToEnd,/**< Lose game, wait for returning main game */
    dg_step_ReturnToMainGame,/**< Return to Main Game */
    dg_step_AddWinToCreditOver,/**< Tell CGA Add Win To Credit Over */
};

/**
 * @brief Demo Step Enumeration.
 */
enum DEMOSTEP{
	demo_step_drawbg = 0,/**< step draw background */
	demo_step_nemo   = 1,/**< step draw nemo */
	demo_step_dora   = 2,/**< step draw dora */
	demo_step_logo   = 3,/**< step draw logo */
	demo_step_odds   = 4,/**< step draw odds */
	demo_step_del    = 5,/**< step delete */
};

/**
 * @brief Main Game Slot Draw Mode.
 */
enum MAINSLOTDRAWMODE{
	main_SlotDraw_Mode_Normal = 0,/**< Draw mode normal */
	main_SlotDraw_Mode_BingoAnime,/**< Draw mode animation */
	main_SlotDraw_Mode_AutoDelete,/**< Draw mode delete automatically */
};

/**
 * @brief Double Game Slot Draw Mode.
 */
enum DOUBLESLOTDRAWMODE{
	dg_SlotDraw_Mode_Normal = 0,/**< Draw mode normal */
	dg_SlotDraw_Mode_BingoAnime,/**< Draw mode animation */
	dg_SlotDraw_Mode_AutoDelete,/**< Draw mode delete automatically */
};

/**
 * @brief Double Game Frame Select Status Enumeration.
 */
enum DOUBLEGAMEFRAMESELECT{
    dg_frame_not_selected = 0,/**< not selected */
	dg_frame_selected	  = 1,/**< selected */
};

/**
 * @brief Idol Information Kind Enumeration.
 */
enum IDOLINFOKIND{
	idol_info_draw_kind_1 = 0,/**< draw kind 1 */
	idol_info_draw_kind_2,    /**< draw kind 2 */
};

/**
 * @brief Auto Play MODE Enumeration.
 */
enum AUTOPLAYMODE{
	auto_play_mode_none = 0,/**< Don't auto play */
	auto_play_mode_normal,  /**< Normal auto play mode */
};

/**
 * @brief Double Down Game Result.
 */
enum DOUBLEDOWNRESULT{
    ddown_result_not_play = 8,/**< Not Play yet */
	ddown_result_win     =  9,/**< Win */
    ddown_result_push    = 10,/**< Push(Tie) */
    ddown_result_lose    = 11,/**< Lose */
};

/**
 * @brief Error Type.
 */
enum ERRORTYPE{
	err_type_system_over = 0,/**< System Over Max Win */
	err_type_ddown_over,/**< Double-Up Over Max Win */
	err_type_memory,/**< Memory Error */
	err_type_coin_in,/**< Coin-In Error */
	err_type_coin_out,/**< Coin-Out Error */
	err_type_coin_value,/**< Coin Value Error */
	err_type_id,/**< ID Error */
	err_type_network,/**< Network Disconnect */
};

/**
 * @brief Jackpot Bonus Draw Type.
 */
enum JACKPOTBONUSDRAWTYPE{
	jackpot_bonus_draw_type_normal = 0,/**< Draw all bonus */
    jackpot_bonus_draw_type_blink  = 1,/**< Only Draw bingo bonus blink */
};

/**
 * @brief Odds Running Status.
 */
enum ODDSRUNNINGSTATUS{
	odds_status_maingame_to_odds = 0,/**< maingame to odds */
	odds_status_odds_to_maingame,/**< odds to maingame */
};

/**
 * @brief JACKPOT Display Mode.
 */
enum JACKPOTDISPLAYMODE{
	jackpot_display_mode_random    = 0,/**< type random */
	jackpot_display_mode_designate = 1,/**< type designate by master */
};


#endif /* GAMEENUM_H_ */
