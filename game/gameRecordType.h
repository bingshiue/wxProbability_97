/**
 * @file gameRecordType.h
 * @brief Declare game record type.
 *
 */

#ifndef GAMERECORDTYPE_H_
#define GAMERECORDTYPE_H_

#include "../preprocessor/preprocessor.h"

/**
 * @brief Game credits recorder.
 */
typedef struct GameRec{
	unsigned long in;/**< Total in coins */
	unsigned long out;/**< Total out coins */
	unsigned long key_in;/**< Total key in coins */
	unsigned long key_out;/**< Total key out coins */
	unsigned long coin_in;/**< Total coin in coins */
	unsigned long coin_out;/**< Total coin out coins */

    unsigned long mc_open;/**< Total key in coins from master */
    unsigned long mc_clear;/**< Total key out coins from master */

	unsigned long bet;/**< Total bet scores */
	unsigned long won;/**< Total win scores */

	unsigned long played;/**< Total play times */
	unsigned long hit;/**< Total hit times */

	unsigned long sysover;/**< Total system over times */
	unsigned long doubleover;/**< Total double game over times */

	unsigned int  jp1Times;/**< Total JP1 times */
	unsigned long jp1Score;/**< Total JP1 scores */
	unsigned int  jp2Times;/**< Total JP2 times */
	unsigned long jp2Score;/**< Total JP2 scores */
	unsigned int  jp3Times;/**< Total JP3 times */
	unsigned long jp3Score;/**< Total JP3 scores */

	unsigned long fullFrameRecord[12];/**< Full Frame Award Record */

	unsigned int  DoubleTotalPlayedScores;/**< Double game total played scores */
	unsigned int  DoubleTotalWonScores;/**< Double game total won scores */
	unsigned int  DoubleTotalPlayedTimes;/**< Double game total played times */
	unsigned int  DoubleTotalWonTimes;/**< Double game total won times */
	unsigned int  DoubleMaxConsecutivePassTimes;/**< Double game max consecutive  */

	/**
	 * @brief Reset All Member Parameters.
	 */
	void reset(){
		in=0;
		out=0;
		key_in=0;
		key_out=0;
		coin_in=0;
		coin_out=0;

		mc_open=0;
		mc_clear=0;

		bet=0;
		won=0;

		played=0;
		hit=0;

		sysover=0;
		doubleover=0;

		jp1Times=0; //JP 1 Times
		jp1Score=0; //JP 1 Score
		jp2Times=0; //JP 2 Times
		jp2Score=0; //JP 2 Score
		jp3Times=0; //JP 3 Times
		jp3Score=0; //JP 3 Score

		for(unsigned int i=0; i<sizeof(fullFrameRecord)/sizeof(fullFrameRecord[0]); i++){
			fullFrameRecord[i] = 0;
		}

		DoubleTotalPlayedScores=0;
		DoubleTotalWonScores=0;
		DoubleTotalPlayedTimes=0;
		DoubleTotalWonTimes=0;
		DoubleMaxConsecutivePassTimes=0;
	}

	/**
	 * @brief Reset member parameters while coin set changing.
	 */
	void ChangeCoin(){
		bet=0;
		won=0;

		played=0;
		hit=0;

		sysover=0;
		doubleover=0;

		jp1Times=0; //JP 1 Times
		jp1Score=0; //JP 1 Score
		jp2Times=0; //JP 2 Times
		jp2Score=0; //JP 2 Score
		jp3Times=0; //JP 3 Times
		jp3Score=0; //JP 3 Score
	}

}GAMEREC;

/**
 * @brief Accounting double game record SIZEOF=9.
 *
 * @author SHIE-BINGSHIUE
 * @date 2010-09-28
 */
typedef struct{
	unsigned char d_item[4];
	unsigned char d_mod;
	unsigned long d_bonus;

	void reset(){
		for(int i=0;i<4;++i){
			d_item[i]=255;
		}
		d_mod=0;
		d_bonus=0;
	}
}GAMEREC_DOUBLE;
/**
 * @brief Accounting main record SIZEOF=21.
 *
 * @author SHIE-BINGSHIUE
 * @date 2010-09-28
 */
typedef struct{
	unsigned char line[8];
	unsigned char item[9];
	unsigned long slotwin;

	void reset(){
		line[1]=0;
		line[2]=0;
		line[3]=0;
		line[4]=0;
		line[5]=0;
		line[6]=0;
		line[7]=0;
		line[0]=0;

		item[1]=0;
		item[2]=0;
		item[3]=0;
		item[4]=0;
		item[5]=0;
		item[6]=0;
		item[7]=0;
		item[8]=0;
		item[0]=0;

		slotwin=0;
	}

}LAST_SLOTREC;
/**
 * @brief Accounting LAST game record
 *
 * @author SHIE-BINGSHIUE
 * @date 2010-09-28
 */
typedef struct{
	LAST_SLOTREC slot;
	GAMEREC_DOUBLE REC[5];

	unsigned long wager;
	unsigned long win;

	void reset(){
		for(int i=0;i<5;++i){
			REC[i].reset();
		}
		slot.reset();


		wager=0;
		win=0;
	}
}LAST_GAMEREC;
/**
 * @brief RTC Time saving structure.
 *
 * @author SHIE-BINGSHIUE
 * @date 2010-09-30
 */
typedef struct{
	unsigned char year;
	unsigned char month;
	unsigned char day;
	unsigned char hours;
	unsigned char minutes;
	unsigned char sec;

	void reste(){
		this->year    = 0;
		this->month   = 0;
		this->day     = 0;
		this->hours   = 0;
		this->minutes = 0;
	    this->sec     = 0;
	}

}SAVERTC;

/**
 * @brief Double game award record.
 */
typedef struct DGameAwardRec{
	unsigned int X0;
	unsigned int X2;
	unsigned int X4;
	unsigned int X6;

	/**
	 * @brief Constructor.
	 */
	DGameAwardRec(){
		this->X0 = 0;
		this->X2 = 0;
		this->X4 = 0;
		this->X6 = 0;
	}

	/**
	 * @brief Reset.
	 */
	void Reset(){
		this->X0 = 0;
		this->X2 = 0;
		this->X4 = 0;
		this->X6 = 0;
	}

}DGAMEAWARDREC;


#endif /* GAMERECORDTYPE_H_ */
