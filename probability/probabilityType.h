/**
 * @file probabilityType.h
 * @brief Declare probability type.
 *
 */

#ifndef PROBABILITYTYPE_H_
#define PROBABILITYTYPE_H_

#include "../preprocessor/preprocessor.h"
#include "../probability/probabilityEnum.h"
#include "../game/gameEnum.h"
#include "../game/gameRecordType.h"

extern unsigned int  MaingameProM[3][15][7];
extern unsigned int  MaingameProDownM[5][7];
extern unsigned int  MaingameProUpM[5][7];
extern unsigned int  LinkMaingameProM[3][5][15];
extern unsigned int  LineBingoTypeM[9];
extern unsigned long SideBingoTypeM[8][7];
extern unsigned int  DoUpM[6][2];
extern unsigned int  DoDownM[6][2];

/**
 * @brief Probability Step Structure.
 */
typedef struct ProbabilityStep{
	int step1;/**< step 1 */
	int step2;/**< step 2 */
	int step3;/**< step 3 */
	int step4;/**< step 4 */
	int step5;/**< step 5 */
	int step6;/**< step 6 */
	int step7;/**< step 7 */
	int step8;/**< step 8 */
	int step9;/**< step 9 */

	/**
	 * @brief Constructor.
	 */
	ProbabilityStep(){
		step1=0;
		step2=0;
		step3=0;
		step4=0;
		step5=0;
		step6=0;
		step7=0;
		step8=0;
		step9=0;
	}

	/**
	 * @brief Reset all member parameter.
	 */
	void reset(void){
		step1=0;
		step2=0;
		step3=0;
		step4=0;
		step5=0;
		step6=0;
		step7=0;
		step8=0;
		step9=0;
	}

}PROBABILITYSTEP;

/**
 * @brief Double Game Probability Step Structure.
 */
typedef struct DoubleProStep{
	int step1;
	int step2;
	int step3;
	int step4;

	/**
	 * @brief Constructor.
	 */
	DoubleProStep(){
		step1=DEF_DPRO_STEP_1;
		step2=DEF_DPRO_STEP_2;
		step3=DEF_DPRO_STEP_3;
		step4=DEF_DPRO_STEP_4;
	}

	/**
	 * @brief Reset all member parameter.
	 */
	void reset(void){
		step1=DEF_DPRO_STEP_1;
		step2=DEF_DPRO_STEP_2;
		step3=DEF_DPRO_STEP_3;
		step4=DEF_DPRO_STEP_4;
	}

}DOUBLEPROSTEP;


/**
 * @brief Double Game Continue Setting Structure.
 */
typedef struct DoubleContinue{
	int probability[15];

	/**
	 * @brief Constructor.
	 */
	DoubleContinue(){
		for(unsigned int i=0; i<sizeof(this->probability)/sizeof(this->probability[0]); i++ ){
			this->probability[i]=DEF_DCONTINUE;
		}
	}

	/**
	 * @brief Reset all member parameter.
	 */
	void reset(void){
		for(unsigned int i=0; i<sizeof(this->probability)/sizeof(this->probability[0]); i++ ){
			this->probability[i]=DEF_DCONTINUE;
		}
	}

}DOUBLECONTINUE;


/**
 * @brief Status change recorder.
 */
typedef struct StatusChangeRecorder{
	unsigned int  _preStatus;/**< Previous status */
	unsigned int  _nextStatus;/**< Next status */
	unsigned long _now_play_scores;/**< Now play scores */
	unsigned long _now_win_scores;/**< Now win scores */
	long          _rValue;/**< R value */
	float         _delta;/**< Delta value */

	/**
	 * @brief Reset All Member Parameters.
	 */
	void ramClearReset(){
		this->_preStatus        = status_normal;
		this->_nextStatus       = status_normal;
		this->_now_play_scores  = 0;
		this->_now_win_scores   = 0;
		this->_rValue           = 0.0f;
		this->_delta            = 0.0f;
	}

}STATUSCHANGERECOEDER;

/**
 * @brief Probability Control Structure.
 */
typedef struct ProbabilityControl{
 GAMEREC*       _rangerec;/**< Range record */
 GAMEREC*       _totalrec;/**< Total record */
 unsigned long* _totalPlayScore;/**< Total play score */
 unsigned long* _totalWinScore;/**< Total win score */
 unsigned char  _isCanCheckR;/**< Is can check R value */
 unsigned int   _status;/**< Status */
 unsigned int*  _linkSetting;/**< Link setting */
 unsigned int   _rlinkSetting;/**< Previous link setting */
 unsigned int*  _glSetting_link;/**< Game level setting(linking) */
 unsigned int   _rglSetting_link;/**< Previous game level setting(linking) */
 double*         _mainProSet_link;/**< Main game probability setting(linking) */
 double          _rmainProSet_link;/**< Previous main game probability setting(linking) */
 unsigned int*  _glSetting;/**< Game level setting */
 unsigned int   _rglSetting;/**< Previous game level setting */
 double*         _mainProSet;/**< Main game probability setting */
 double          _rmainProSet;/**< Previous main game probability setting */
 unsigned int*  _coinSet;/**< Coin set */
 unsigned int   _rcoinSet;/**< Previous coin set */
 unsigned int   _indexOfRunning;/**< index of running */
 unsigned int   _timesOfRunning;/**< Times of running */
 unsigned int   _checkRCount;/**< Count of checking R value */
 unsigned int   __normalM[15];/**< Normal probability mapping */
 unsigned int   __upM[5];/**< Up probability mapping */
 unsigned int   __downM[5];/**< Down probability mapping */
 unsigned int   __linkM[15];/**< Link probability mapping */
 double          __linkMainProSetChange[7];/**< Link main game probability change record */
 unsigned int   _ReceivelinkIntFlag;/**< Receiver link command interrupt flag */
 unsigned long  _sectionClearScore;/**< Clear score of section */
 unsigned int   _totalUpTimes;/**< Total up times(In section) */
 unsigned int   _totalDownTimes;/**< Total down times(In section) */
 unsigned long  _totalUpGameTimes;/**<  Total up game times(In section) */
 unsigned long  _totalDownGameTimes;/**< Total down game times(In section) */
 unsigned long  _MaxUpGameTimes;/**< Max times of one up status */
 unsigned long  _MaxDownGameTimes;/**< Max times of one down status */
 unsigned int   _runTimesToMaster;/**< Run times to master */
 unsigned char  _nextStatusFromMaster;/**< Next status from master */
 unsigned long  _AllUpGTimes;/**< All up games */
 unsigned long  _AllDownGTimes;/**< All down games */
 unsigned long  _totalClearSectionTimes;/**< Total clear section times */
 unsigned char  _previousStopItem[9];/**< Previous stop item */
 StatusChangeRecorder scRecord[3];/**< probability status change record */

/**
 * @brief Reset All Member Parameters.
 */
 void _RamClearReset(
		               GAMEREC*      rangerec,         //Section Game Record
		               GAMEREC*      totalrec,         //Total Game Record for Get Correct Data when Link Function Change
		               unsigned int* linkSetting,    //Link Setting Value
		               unsigned int* link_gl,        //Ver.link   GL Setting Value
		               double*        link_mainProSet,//Ver.link   Main Probability Setting Value
		               unsigned int* gl,             //Ver.single GL Setting Value
		               double*        mainProSet,     //Ver.single Main Probability Setting Value
		               unsigned int* coinSet         //Coin Set Value
		               )
 {
	 //Ver.LINK or Ver.SINGLE
	 _linkSetting = linkSetting;            //連線功能設定值(現在)
	 _rlinkSetting = *_linkSetting;         //連線功能設定值(上次)
	 //GL Ver.link
	 _glSetting_link = link_gl;             //連線時遊戲起伏設定值(現在)
	 _rglSetting_link = *_glSetting_link;   //連線時遊戲起伏設定值(上次)
	 //Main Probability Set Ver.link
	 _mainProSet_link = link_mainProSet;    //連線時機率設定值(現在)
	 _rmainProSet_link = *_mainProSet_link; //連線時機率設定值(上次)
	 //GL Ver.single
	 _glSetting = gl;                       //單機時遊戲起伏設定值(現在)
	 _rglSetting = *_glSetting;             //單機時遊戲起伏設定值(上次)
	 //Main Probability Set Ver.single
	 _mainProSet = mainProSet;              //單機時機率設定值(現在)
	 _rmainProSet = *_mainProSet;           //單機時機率設定值(上次)
	 //Coin Value Set
	 _coinSet = coinSet;                    //幣值設定值(現在)
	 _rcoinSet = *_coinSet;                 //幣值設定值(上次)
	 //
	 _rangerec = rangerec;                  //區段遊戲記錄記憶(大局清帳使用)
	 _totalrec = totalrec;                  //
	 //
	 _totalPlayScore = (&rangerec->bet);    //區段總玩分數(大局清帳使用)
	 //
	 _totalWinScore =  (&rangerec->won);    //區段總贏分數(大局清帳使用)
	 //
	 _isCanCheckR = false;                  //是否可以檢查R值(內部使用)

	 //When Ver.single Clear Ram Reset _status = status_normal,or _status = status_link
	 if(*linkSetting==Link_Function_ON){
		 //設定機率控制為連線模式
		 _status = status_link;
		 //設定暫存陣列(機率抽選籤筒)
		 _setTempMForStatusChange();
	 }else{
		 //設定機率控制為單機模式
		 _status = status_normal;
		 //設定暫存陣列(機率抽選籤筒)
		 _setTempMForStatusChange();
	 }
	 //
	 __linkMainProSetChange[0] = 96;
	 __linkMainProSetChange[1] = 96.5;
	 __linkMainProSetChange[2] = 97;
	 __linkMainProSetChange[3] = 97.5;
	 __linkMainProSetChange[4] = 98;
	 __linkMainProSetChange[5] = 98.5;
	 __linkMainProSetChange[6] = 99;
	 //
	 _sectionClearScore =  300000 + (rand()%10000);//srandNext(3000000,4000000);
	 //
	 _ReceivelinkIntFlag = false;
	 //
	 _totalUpTimes  =   0;
	 _totalDownTimes =  0;
	 _totalUpGameTimes = 0;
	 _totalDownGameTimes = 0;
	 _MaxUpGameTimes = 0;
	 _MaxDownGameTimes = 0;
	 _AllUpGTimes    = 0;
	 _AllDownGTimes  = 0;
	 _totalClearSectionTimes = 0;
	 //
	 _runTimesToMaster = 0;
	 //
	 _nextStatusFromMaster = 0;
	 //
	 _checkRCount = 0;
	 //
	 for(unsigned int i=0; i<sizeof(scRecord)/sizeof(scRecord[0]); i++){
		 scRecord[i].ramClearReset();
	 }

 }
 /**
  * @brief Get Link Setting Value.
  * @retval Link setting
  */
 unsigned int _getLinkSetting(){
     return (*this->_linkSetting);
 }
 /**
  * @brief Link Probability Refresh.
  */
 void _linkProMRefresh(){
	 unsigned int tmp =0;
	 unsigned int k   =_linkMainProSetChange(*this->_mainProSet_link);

	 for(unsigned int i=0; i<sizeof(__linkM)/sizeof(__linkM[0]); i++){
        tmp = rand()%10000;//srandNext(0,9999);
        for(unsigned j=0; j<sizeof(LinkMaingameProM[0][0])/sizeof(LinkMaingameProM[0][0][0]); j++){
        	if( tmp < LinkMaingameProM[*this->_glSetting_link][k][j] * 10 ){
        		__linkM[i] = j;
        		break;
        	}
        }
	 }
 }
 /**
  * @brief Compute R Value.
  * @retval R value
  */
 long computeR(){
	 return (  *_totalWinScore - (unsigned long)((float)*_totalPlayScore * ((float)*_mainProSet /(float)100))  );
 }
 /**
  * @brief Set temporal parameters for status changing.
  */
 void _setTempMForStatusChange(){
	 _indexOfRunning = 0;               //執行中籤筒索引值
	 _timesOfRunning = 5 + rand()%6;//srandNext(5,10); //執行中籤筒局數

	 switch(_status){
	 case status_normal://單機時正常狀態
         for(unsigned int i=0; i<sizeof(__normalM)/sizeof(__normalM[0]); i++){
        	 __normalM[i] = rand()%15;//srandNext(0,14);
         }
		 break;
	 case status_up://上拉狀態
         for(unsigned int i=0; i<sizeof(__upM)/sizeof(__upM[0]); i++){
        	 __upM[i] = rand()%5;//srandNext(0,4);
         }
		 break;
	 case status_down://下拉狀態
         for(unsigned int i=0; i<sizeof(__downM)/sizeof(__downM[0]); i++){
        	 __downM[i] = rand()%5;//srandNext(0,4);
         }
		 break;
	 case status_link://連線狀態
         this->_linkProMRefresh();
		 break;

	 default:
		 break;
	 }
 }
 /**
  * @brief Normal status check.
  */
 void _status_normal_check(){
	 _isCanCheckR = false;
   if(_checkRCount >= 3){// 10/02/03

	   if( *_totalPlayScore > (unsigned long)((float)1500000 * ((float)*_coinSet/(float)100) * 6 ) ){
#ifdef MAIN_PRO_VER_A
		   if( (float)((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 )  - (float)(*_mainProSet) > 2.0f )
#else
#ifdef MAIN_PRO_VER_B
		   if( (float)((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 )  - (float)(*_mainProSet) > 1.5f )
#endif
#endif
		   {
				_status = status_down;
				_setTempMForStatusChange();
				_SaveStatusChange(status_normal,_status,*_totalPlayScore,*_totalWinScore,computeR(),(((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 )  - (float)(*_mainProSet)));
		   }
#ifdef MAIN_PRO_VER_A
		   else if( (float)(*_mainProSet) - (float)((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 ) > 1.5f )
#else
#ifdef MAIN_PRO_VER_B
		   else if( (float)(*_mainProSet) - (float)((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 ) > 1.0f )
#endif
#endif
		   {
				_status = status_up;
				_setTempMForStatusChange();
				_SaveStatusChange(status_normal,_status,*_totalPlayScore,*_totalWinScore,computeR(),(((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 )  - (float)(*_mainProSet)));
		   }
	   }else if( *_totalPlayScore > (unsigned long)((float)1000000 * ((float)*_coinSet/(float)100) * 6 ) && *_totalPlayScore <= (unsigned long)((float)1500000 * ((float)*_coinSet/(float)100) * 6 )){
		   if(computeR() > (long)((float)40000 * ((float)*_coinSet/(float)100) * 3 )){
			   if(_isCanPullDown(this->_totalClearSectionTimes)==true){
				   _status = status_down;
				   _setTempMForStatusChange();
				   _SaveStatusChange(status_normal,_status,*_totalPlayScore,*_totalWinScore,computeR(),(((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 )  - (float)(*_mainProSet)));
			   }
		   }else if(computeR() < (long)((float)-15000 * ((float)*_coinSet/(float)100) * 3 )){//2010/01/25
			   if(_isCanPullUp(this->_totalClearSectionTimes)==true){
				   _status = status_up;
				   _setTempMForStatusChange();
				   _SaveStatusChange(status_normal,_status,*_totalPlayScore,*_totalWinScore,computeR(),(((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 )  - (float)(*_mainProSet)));
			   }
		   }
	   }else{
		   if(computeR() > (long)((float)30000 * ((float)*_coinSet/(float)100) * 3 )){
			   if(_isCanPullDown(this->_totalClearSectionTimes)==true){
				   _status = status_down;
				   _setTempMForStatusChange();
				   _SaveStatusChange(status_normal,_status,*_totalPlayScore,*_totalWinScore,computeR(),(((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 )  - (float)(*_mainProSet)));
			   }
		   }else if(computeR() < (long)((float)-15000 * ((float)*_coinSet/(float)100) * 3 )){//2010/01/25
			   if(_isCanPullUp(this->_totalClearSectionTimes)==true){
				   _status = status_up;
				   _setTempMForStatusChange();
				   _SaveStatusChange(status_normal,_status,*_totalPlayScore,*_totalWinScore,computeR(),(((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 )  - (float)(*_mainProSet)));
			   }
		   }
	   }

	   _checkRCount = 0;
   }

   //For Record Up&Down Times
   if(_status == status_up){
	   _totalUpTimes++;
	   _totalUpGameTimes = 0;
   }else if(_status == status_down){
	   _totalDownTimes++;
	   _totalDownGameTimes = 0;
   }
   //
   if(_status == status_normal){
	   _setTempMForStatusChange();
   }
 }
 /**
  * @brief Up status check.
  */
 void _status_up_check(){

	   if( *_totalPlayScore > (unsigned long)((float)1500000 * ((float)*_coinSet/(float)100) * 6 ) ){
#ifdef MAIN_PRO_VER_A
		   if( /* Abs((int)((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100)  - (float)(*_mainProSet)) < 1.0f ||*/ (float)(*_mainProSet) - ((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 ) < 0.5f )
#else
#ifdef MAIN_PRO_VER_B
		   if( /* Abs((int)((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100)  - (float)(*_mainProSet)) < 1.0f ||*/ (float)(*_mainProSet) - ((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 ) <=0.0f )
#endif
#endif
		   {
			  _status = status_normal;
			  _setTempMForStatusChange();
	          _SaveStatusChange(status_up,_status,*_totalPlayScore,*_totalWinScore,computeR(),(((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 )  - (float)(*_mainProSet)));
		   }
	   }else if( *_totalPlayScore > (unsigned long)((float)1000000 * ((float)*_coinSet/(float)100) * 6 ) && *_totalPlayScore <= (unsigned long)((float)1500000 * ((float)*_coinSet/(float)100) * 6 )){//2010/01/25
	       if(computeR() > (long)((float)2000 * ((float)*_coinSet/(float)100) * 3 )){
	    	   _status = status_normal;
	    	   _setTempMForStatusChange();
	    	   _SaveStatusChange(status_up,_status,*_totalPlayScore,*_totalWinScore,computeR(),(((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 )  - (float)(*_mainProSet)));
	       }
	   }else{//2010/01/25
	       if(computeR() > (long)((float)2000 * ((float)*_coinSet/(float)100) * 3 )){
	    	   _status = status_normal;
	    	   _setTempMForStatusChange();
	    	   _SaveStatusChange(status_up,_status,*_totalPlayScore,*_totalWinScore,computeR(),(((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 )  - (float)(*_mainProSet)));
	       }
	   }

	   _AllUpGTimes++;
	   _totalUpGameTimes++;
	   if(_totalUpGameTimes > _MaxUpGameTimes){
		  _MaxUpGameTimes = _totalUpGameTimes;
	   }
 }
 /**
  * @brief Down status check.
  */
 void _status_down_check(){
	   if( *_totalPlayScore > (unsigned long)((float)1500000 * ((float)*_coinSet/(float)100) * 6 ) ){
#ifdef MAIN_PRO_VER_A
		   if( /* Abs((float)((float)(*_totalWinScore) / (float)(*_totalPlayScor) * 100 )  - (float)(*_mainProSet) < 1.0f) || */ (float)(*_mainProSet) - ((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 )  > 0.5f )
#else
#ifdef MAIN_PRO_VER_B
		   if( /* Abs((float)((float)(*_totalWinScore) / (float)(*_totalPlayScor) * 100 )  - (float)(*_mainProSet) < 1.0f) || */ (float)(*_mainProSet) - ((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 )  >=0.0f )
#endif
#endif
		   {
	            _status = status_normal;
	            _setTempMForStatusChange();
	            _SaveStatusChange(status_down,_status,*_totalPlayScore,*_totalWinScore,computeR(),(((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 )  - (float)(*_mainProSet)));
		   }
	   }else if( *_totalPlayScore > (unsigned long)((float)1000000 * ((float)*_coinSet/(float)100) * 6 ) && *_totalPlayScore <= (unsigned long)((float)1500000 * ((float)*_coinSet/(float)100) * 6 )){
	       if(computeR() < (long)((float)20000 * ((float)*_coinSet/(float)100) * 3 )){
	    	   _status = status_normal;
	    	   _setTempMForStatusChange();
	    	   _SaveStatusChange(status_down,_status,*_totalPlayScore,*_totalWinScore,computeR(),(((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 )  - (float)(*_mainProSet)));
	       }
	   }else{
	       if(computeR() < (long)((float)10000 * ((float)*_coinSet/(float)100) * 3 )){
	    	   _status = status_normal;
	    	   _setTempMForStatusChange();
	    	   _SaveStatusChange(status_down,_status,*_totalPlayScore,*_totalWinScore,computeR(),(((float)(*_totalWinScore) / (float)(*_totalPlayScore) * 100 )  - (float)(*_mainProSet)));
	       }
	   }

	   _AllDownGTimes++;
	   _totalDownGameTimes++;
	   if(_totalDownGameTimes > _MaxDownGameTimes){
		  _MaxDownGameTimes = _totalDownGameTimes;
	   }
 }
 /**
  * @brief Link normal status check.
  */
 void _status_link_check(){
      if(_ReceivelinkIntFlag==true){
    	 //_CheckSettingValume();
	     _ChangeLinkStatus();
    	 _ReceivelinkIntFlag = false;
      }
 }
 /**
  * @brief Link up status check.
  */
 void _status_link_up_check(){
     if(_ReceivelinkIntFlag==true){
    	//_CheckSettingValume();
	    _ChangeLinkStatus();
    	_ReceivelinkIntFlag = false;
     }else{
  	   _AllUpGTimes++;
  	   _totalUpGameTimes++;
  	   if(_totalUpGameTimes > _MaxUpGameTimes){
  		  _MaxUpGameTimes = _totalUpGameTimes;
  	   }
     }
 }
 /**
  * @brief Link down status check.
  */
 void _status_link_down_check(){
     if(_ReceivelinkIntFlag==true){
    	//_CheckSettingValume();
	    _ChangeLinkStatus();
      	_ReceivelinkIntFlag = false;
     }else{
  	   _AllDownGTimes++;
  	   _totalDownGameTimes++;
  	   if(_totalDownGameTimes > _MaxDownGameTimes){
  		  _MaxDownGameTimes = _totalDownGameTimes;
  	   }
     }
 }
 /**
  * @brief Check Setting Value.
  */
 void _CheckSettingValume(){

     //if Link Status Change
	 if(_rlinkSetting != *_linkSetting){

		 switch(*_linkSetting)
		 {
		 case Link_Function_ON:  //No Link -> Link
             _status = status_link;
             _setTempMForStatusChange();
             _rangerec->reset();
             (*_rangerec) = (*_totalrec);
             _rangerec->bet += 100000;
             _rangerec->won += (unsigned long)((float)100000 * ((float)(*this->_mainProSet_link) / (float)100));
             _checkRCount = 0;
			 break;

		 case Link_Function_OFF://Link -> No Link
             _status = status_normal;
             _setTempMForStatusChange();
             _rangerec->reset();
             (*_rangerec) = (*_totalrec);
             _checkRCount = 0;
			 break;

		 default:
			 break;
		 }

		_rlinkSetting = *_linkSetting;
		return;
	 }
	 //

	 //if Link Status Don't Change
	 //Ver.Link
	 if( _getLinkSetting()==Link_Function_ON ){
		 //Main Probability Set Ver.link & GL Ver.link
		 if(_rmainProSet_link != *_mainProSet_link || _rglSetting_link != *_glSetting_link ){
             _status = status_link;
             _setTempMForStatusChange();
             //_rangerec->reset();
			 _rmainProSet_link = *_mainProSet_link;
			 _rglSetting_link  = *_glSetting_link;
		 }
	 }
	 //Ver.Single
	 else{
		 //GL Ver.single
		 if(_rglSetting != *_glSetting){
			 //Do nothing
			_rglSetting =  *_glSetting;
		 }
		 //Main Probability Set Ver.single & Coin Value Set

		 if(_rmainProSet != *_mainProSet || _rcoinSet != *_coinSet){
             _status = status_normal;
             _setTempMForStatusChange();
             //_rangerec->reset();
			 _rmainProSet = *_mainProSet;
			 _rcoinSet = *_coinSet;
		 }
	 }
 }
 /**
  * @brief Called By Link Interrupt Function.
  * @param nextStatusFromMaster Next status from master
  */
 void _linkInterrupt(unsigned int nextStatusFromMaster){
	   _nextStatusFromMaster = nextStatusFromMaster;
	   _ReceivelinkIntFlag = true;

	   //For Record Up&Down Times
	   if(_nextStatusFromMaster == status_up){
		   _totalUpTimes++;
		   _totalUpGameTimes = 0;
	   }else if(_nextStatusFromMaster == status_down){
		   _totalDownTimes++;
		   _totalDownGameTimes = 0;
	   }
 }
 /**
  * @brief Called By Link Interrupt Function.
  * @param nextStatusFromMaster Next status from master
  * @param _mainProSetFromMaster Next main game probability setting from master
  * @param _glFromMaster Next game level from master
  */
 void _linkInterrupt(unsigned int nextStatusFromMaster,unsigned char _mainProSetFromMaster,unsigned char _glFromMaster){
	   _nextStatusFromMaster   = nextStatusFromMaster;
	   *this->_mainProSet_link = __linkMainProSetChange[_mainProSetFromMaster];
       *this->_glSetting_link  = _glFromMaster;
	   _ReceivelinkIntFlag = true;

	   //For Record Up&Down Times
	   if(_nextStatusFromMaster == status_up){
		   _totalUpTimes++;
		   _totalUpGameTimes = 0;
	   }else if(_nextStatusFromMaster == status_down){
		   _totalDownTimes++;
		   _totalDownGameTimes = 0;
	   }
 }
 /**
  * @brief Check status.
  */
 void _CheckStatus(){

	 //
	 if( (*_totalPlayScore > (unsigned long)((float)_sectionClearScore * ((float)*_coinSet/(float)100 )) * (float)6 ) && _getLinkSetting()!=Link_Function_ON ){
		 _status = status_normal;
		 _isCanCheckR = true;
		 _rangerec->reset();
		 _sectionClearScore = 3000000 + (rand()%1000000);//srandNext(3000000,4000000);
		 _totalClearSectionTimes++;
	 }
	 //

	 switch(this->_status){

	 case status_normal:
         if(_isCanCheckR == true){
        	 this->_status_normal_check();
         }
		 break;

	 case status_up:
		 if(_getLinkSetting()==Link_Function_OFF){
			 this->_status_up_check();
		 }else{
			 this->_status_link_up_check();
		 }
		 break;

	 case status_down:
		 if(_getLinkSetting()==Link_Function_OFF){
			 this->_status_down_check();
		 }else{
			 this->_status_link_down_check();
		 }
		 break;

	 case status_link:
		 this->_status_link_check();

		 break;

	 default:

		 break;

	 }

	 if(_getLinkSetting()==Link_Function_ON){
		 _runTimesToMaster++;
	 }
 }
 /**
  * @brief Run probability control.
  */
 void _RunProbabilityControl(){

	 switch(this->_status){

	 case status_normal:
         if( _timesOfRunning > 0 ){
        	  _timesOfRunning--;
         }else{
        	 _indexOfRunning++;
        	 if(_indexOfRunning  > 14 ){
        		 _indexOfRunning %= 15;
        		 _checkRCount++;// 10/02/03
        		 if(*_totalPlayScore > (unsigned long)((float)1000 * ((float)*_coinSet/(float)100) * 6 )){
        			 _isCanCheckR = true;
        		 }
        	 }
        	 _timesOfRunning = 5 + (rand()%6);//srandNext(5,10);
         }
		 break;

	 case status_up:
         if( _timesOfRunning > 0 ){
        	  _timesOfRunning--;
         }else{
        	 _indexOfRunning++;
        	 if(_indexOfRunning  > 4 ){
        		 _indexOfRunning %= 5;
        	 }
        	 _timesOfRunning = 5 + (rand()%6);//srandNext(5,10);
         }
		 break;

	 case status_down:
         if( _timesOfRunning > 0 ){
        	  _timesOfRunning--;
         }else{
        	 _indexOfRunning++;
        	 if(_indexOfRunning  > 4 ){
        		_indexOfRunning %= 5;
        	 }
        	 _timesOfRunning = 5 + (rand()%6);//srandNext(5,10);
         }

		 break;
	 case status_link:
         if( _timesOfRunning > 0 ){
        	  _timesOfRunning--;
         }else{
        	 _indexOfRunning++;
        	 if(_indexOfRunning  > 14 ){
        		 _indexOfRunning %= 15;
        		 this->_linkProMRefresh();
        	 }
        	 _timesOfRunning = 5 + (rand()%6);//srandNext(5,10);
         }
		 break;

	 default:

		 break;
	 }

 }
 /**
  * @brief Set link main game probability.
  * @param mainpro Main game probability
  */
 unsigned int _linkMainProSetChange(unsigned int mainpro){
	 unsigned int ret=0;

	 for(unsigned int i=0; i<sizeof(__linkMainProSetChange)/sizeof(__linkMainProSetChange[0]); i++){
         if(mainpro ==__linkMainProSetChange[i]){
        	ret = i;
        	break;
         }
     }

	 return ret;
 }
 /**
  * @brief Change link status.
  */
 void _ChangeLinkStatus(){
     _status = (int)this->_nextStatusFromMaster;
     _setTempMForStatusChange();
 }
 /**
  * @brief Is can pull up.
  * @param totalClearSectionTimes Total section times
  * @retval true: Pull Up false: Don't Pull Up
  */
 unsigned char _isCanPullUp(unsigned long totalClearSectionTimes){
	 unsigned char result = true;
	 unsigned char whichIndex = 0;
	 unsigned int  tmp = 0;
	 whichIndex = rand()%6;  //randi(6);
	 tmp        = rand()%100;//randi(100);

	 if( totalClearSectionTimes > 0 ){
		 if( tmp >= DoUpM[whichIndex][0]){
			 result = false;
		 }else{
			 result = true;
		 }
	 }else{//First Section
		 if( tmp >= DoUpM[0][0]){
			 result = false;
		 }else{
			 result = true;
		 }
	 }

	 return result;
 }
 /**
  * @brief Is can pull down.
  * @param totalClearSectionTimes Total section times
  * @retval true: Pull Down false: Don't Pull Down
  */
 unsigned char _isCanPullDown(unsigned long totalClearSectionTimes){
	 unsigned char result = true;
	 unsigned char whichIndex = 0;
	 unsigned int  tmp = 0;
	 whichIndex = rand()%6;  //randi(6);
	 tmp        = rand()%100;//randi(100);

	 if( totalClearSectionTimes > 0 ){
		 if( tmp >= DoDownM[whichIndex][0]){
			 result = false;
		 }else{
			 result = true;
		 }
	 }else{//First Section
	 	 if( tmp >= DoDownM[0][0]){
			 result = false;
		 }else{
			 result = true;
		 }
	 }

	 return result;
 }
 /**
  * @brief Save Status Change For Hide Accounting mode.
  * @param preStatus Previous status
  * @param nextStatus Next status
  * @param nowPlayScores Now play scores
  * @param nowWinScores Now win scores
  * @param rValue R value
  * @param delta Delta
  */
 void _SaveStatusChange(unsigned int preStatus,unsigned int nextStatus,unsigned long nowPlayScores,unsigned long nowWinScores,float rValue,float delta ){
      //
	  this->scRecord[2] = this->scRecord[1];
      this->scRecord[1] = this->scRecord[0];
      //Save it
      this->scRecord[0]._preStatus = preStatus;
	  this->scRecord[0]._nextStatus= nextStatus;
	  this->scRecord[0]._now_play_scores= nowPlayScores;
	  this->scRecord[0]._now_win_scores= nowWinScores;
	  this->scRecord[0]._rValue= rValue;
	  this->scRecord[0]._delta= delta;
 }
 /**
  * @brief Every game loop check.
  */
 void _EveryLoopCheck(){
	 this->_CheckSettingValume();
	 this->_CheckStatus();
	 this->_RunProbabilityControl();
 }

}PROBABILITYCONTROL;




#endif /* PROBABILITYTYPE_H_ */

