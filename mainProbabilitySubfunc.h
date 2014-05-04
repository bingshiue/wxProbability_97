/**
 * @file mainProbabilitySubfunc.h
 *
 */

#ifndef MAINPROBABILITYSUBFUNC_H_
#define MAINPROBABILITYSUBFUNC_H_

#include "preprocessor/preprocessor.h"
#include "mersenne_twister/mt_random.h"
#include "probability/probabilityDefine.h"
#include "probability/probabilityType.h"

//Auto KeyIn KeyOut Setting
unsigned int AutoKeyInOutSetting[10][3]={
		{  10, 300,  1},
		{ 300, 500,  2},
		{ 500, 700,  3},
		{ 700, 800,  5},
		{ 800,1000, 16},
		{1000,1200, 20},
		{1200,1500, 50},
		{1500,1700,100},
		{1700,1800,150},
		{1800,1900,200}
};

//Probability Step Structure
PROBABILITYSTEP slot1Step;
PROBABILITYSTEP slot2Step;
PROBABILITYSTEP slot3Step;
PROBABILITYSTEP slot4Step;
PROBABILITYSTEP slot5Step;
PROBABILITYSTEP slot6Step;
PROBABILITYSTEP slot7Step;
PROBABILITYSTEP slot8Step;
PROBABILITYSTEP slot9Step;

//Key In Maximum Value
unsigned long keyInMaxValue;

int Slot1Probability(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_fixed_random_Base);

    if(ram < slot1Step.step1)
       return ITEM_CHERRY;
    else if(ram >=slot1Step.step1 && ram <slot1Step.step2)
       return ITEM_ORANGE;
    else if(ram >=slot1Step.step2 && ram <slot1Step.step3)
       return ITEM_MANGO;
    else if(ram >=slot1Step.step3 && ram <slot1Step.step4)
       return ITEM_BELL;
    else if(ram >=slot1Step.step4 && ram <slot1Step.step5)
       return ITEM_WATERMELON;
    else if(ram >=slot1Step.step5 && ram <slot1Step.step6)
       return ITEM_BAR_YELLOW;
    else if(ram >=slot1Step.step6 && ram <slot1Step.step7)
       return ITEM_BAR_RED;
    else if(ram >=slot1Step.step7 && ram <slot1Step.step8)
       return ITEM_BAR_BLUE;
    else if(ram >=slot1Step.step8 && ram <slot1Step.step9)
       return ITEM_WILD;

    return ITEM_UNKNOW;
}

int Slot2Probability(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_fixed_random_Base);

    if(ram < slot2Step.step1)
       return ITEM_CHERRY;
    else if(ram >=slot2Step.step1 && ram <slot2Step.step2)
       return ITEM_ORANGE;
    else if(ram >=slot2Step.step2 && ram <slot2Step.step3)
       return ITEM_MANGO;
    else if(ram >=slot2Step.step3 && ram <slot2Step.step4)
       return ITEM_BELL;
    else if(ram >=slot2Step.step4 && ram <slot2Step.step5)
       return ITEM_WATERMELON;
    else if(ram >=slot2Step.step5 && ram <slot2Step.step6)
       return ITEM_BAR_YELLOW;
    else if(ram >=slot2Step.step6 && ram <slot2Step.step7)
       return ITEM_BAR_RED;
    else if(ram >=slot2Step.step7 && ram <slot2Step.step8)
       return ITEM_BAR_BLUE;
    else if(ram >=slot2Step.step8 && ram <slot2Step.step9)
       return ITEM_WILD;

    return ITEM_UNKNOW;
}

int Slot3Probability(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_fixed_random_Base);

    if(ram < slot3Step.step1)
       return ITEM_CHERRY;
    else if(ram >=slot3Step.step1 && ram <slot3Step.step2)
       return ITEM_ORANGE;
    else if(ram >=slot3Step.step2 && ram <slot3Step.step3)
       return ITEM_MANGO;
    else if(ram >=slot3Step.step3 && ram <slot3Step.step4)
       return ITEM_BELL;
    else if(ram >=slot3Step.step4 && ram <slot3Step.step5)
       return ITEM_WATERMELON;
    else if(ram >=slot3Step.step5 && ram <slot3Step.step6)
       return ITEM_BAR_YELLOW;
    else if(ram >=slot3Step.step6 && ram <slot3Step.step7)
       return ITEM_BAR_RED;
    else if(ram >=slot3Step.step7 && ram <slot3Step.step8)
       return ITEM_BAR_BLUE;
    else if(ram >=slot3Step.step8 && ram <slot3Step.step9)
       return ITEM_WILD;

    return ITEM_UNKNOW;
}

int Slot4Probability(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_fixed_random_Base);

    if(ram < slot4Step.step1)
       return ITEM_CHERRY;
    else if(ram >=slot4Step.step1 && ram <slot4Step.step2)
       return ITEM_ORANGE;
    else if(ram >=slot4Step.step2 && ram <slot4Step.step3)
       return ITEM_MANGO;
    else if(ram >=slot4Step.step3 && ram <slot4Step.step4)
       return ITEM_BELL;
    else if(ram >=slot4Step.step4 && ram <slot4Step.step5)
       return ITEM_WATERMELON;
    else if(ram >=slot4Step.step5 && ram <slot4Step.step6)
       return ITEM_BAR_YELLOW;
    else if(ram >=slot4Step.step6 && ram <slot4Step.step7)
       return ITEM_BAR_RED;
    else if(ram >=slot4Step.step7 && ram <slot4Step.step8)
       return ITEM_BAR_BLUE;
    else if(ram >=slot4Step.step8 && ram <slot4Step.step9)
       return ITEM_WILD;

    return ITEM_UNKNOW;
}

int Slot5Probability(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_fixed_random_Base);

    if(ram < slot5Step.step1)
       return ITEM_CHERRY;
    else if(ram >=slot5Step.step1 && ram <slot5Step.step2)
       return ITEM_ORANGE;
    else if(ram >=slot5Step.step2 && ram <slot5Step.step3)
       return ITEM_MANGO;
    else if(ram >=slot5Step.step3 && ram <slot5Step.step4)
       return ITEM_BELL;
    else if(ram >=slot5Step.step4 && ram <slot5Step.step5)
       return ITEM_WATERMELON;
    else if(ram >=slot5Step.step5 && ram <slot5Step.step6)
       return ITEM_BAR_YELLOW;
    else if(ram >=slot5Step.step6 && ram <slot5Step.step7)
       return ITEM_BAR_RED;
    else if(ram >=slot5Step.step7 && ram <slot5Step.step8)
       return ITEM_BAR_BLUE;
    else if(ram >=slot5Step.step8 && ram <slot5Step.step9)
       return ITEM_WILD;

    return ITEM_UNKNOW;
}

int Slot6Probability(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_fixed_random_Base);

    if(ram < slot6Step.step1)
       return ITEM_CHERRY;
    else if(ram >=slot6Step.step1 && ram <slot6Step.step2)
       return ITEM_ORANGE;
    else if(ram >=slot6Step.step2 && ram <slot6Step.step3)
       return ITEM_MANGO;
    else if(ram >=slot6Step.step3 && ram <slot6Step.step4)
       return ITEM_BELL;
    else if(ram >=slot6Step.step4 && ram <slot6Step.step5)
       return ITEM_WATERMELON;
    else if(ram >=slot6Step.step5 && ram <slot6Step.step6)
       return ITEM_BAR_YELLOW;
    else if(ram >=slot6Step.step6 && ram <slot6Step.step7)
       return ITEM_BAR_RED;
    else if(ram >=slot6Step.step7 && ram <slot6Step.step8)
       return ITEM_BAR_BLUE;
    else if(ram >=slot6Step.step8 && ram <slot6Step.step9)
       return ITEM_WILD;

    return ITEM_UNKNOW;
}

int Slot7Probability(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_fixed_random_Base);

    if(ram < slot7Step.step1)
       return ITEM_CHERRY;
    else if(ram >=slot7Step.step1 && ram <slot7Step.step2)
       return ITEM_ORANGE;
    else if(ram >=slot7Step.step2 && ram <slot7Step.step3)
       return ITEM_MANGO;
    else if(ram >=slot7Step.step3 && ram <slot7Step.step4)
       return ITEM_BELL;
    else if(ram >=slot7Step.step4 && ram <slot7Step.step5)
       return ITEM_WATERMELON;
    else if(ram >=slot7Step.step5 && ram <slot7Step.step6)
       return ITEM_BAR_YELLOW;
    else if(ram >=slot7Step.step6 && ram <slot7Step.step7)
       return ITEM_BAR_RED;
    else if(ram >=slot7Step.step7 && ram <slot7Step.step8)
       return ITEM_BAR_BLUE;
    else if(ram >=slot7Step.step8 && ram <slot7Step.step9)
       return ITEM_WILD;

    return ITEM_UNKNOW;
}

int Slot8Probability(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_fixed_random_Base);

    if(ram < slot8Step.step1)
       return ITEM_CHERRY;
    else if(ram >=slot8Step.step1 && ram <slot8Step.step2)
       return ITEM_ORANGE;
    else if(ram >=slot8Step.step2 && ram <slot8Step.step3)
       return ITEM_MANGO;
    else if(ram >=slot8Step.step3 && ram <slot8Step.step4)
       return ITEM_BELL;
    else if(ram >=slot8Step.step4 && ram <slot8Step.step5)
       return ITEM_WATERMELON;
    else if(ram >=slot8Step.step5 && ram <slot8Step.step6)
       return ITEM_BAR_YELLOW;
    else if(ram >=slot8Step.step6 && ram <slot8Step.step7)
       return ITEM_BAR_RED;
    else if(ram >=slot8Step.step7 && ram <slot8Step.step8)
       return ITEM_BAR_BLUE;
    else if(ram >=slot8Step.step8 && ram <slot8Step.step9)
       return ITEM_WILD;

    return ITEM_UNKNOW;
}

int Slot9Probability(MTRANDOM* mt,PROBABILITYCONTROL* pctrl){
    int ram = 0;
    ram = mt->getRandomLong(_scroll_pro_fixed_random_Base);

    if(ram < slot9Step.step1)
       return ITEM_CHERRY;
    else if(ram >=slot9Step.step1 && ram <slot9Step.step2)
       return ITEM_ORANGE;
    else if(ram >=slot9Step.step2 && ram <slot9Step.step3)
       return ITEM_MANGO;
    else if(ram >=slot9Step.step3 && ram <slot9Step.step4)
       return ITEM_BELL;
    else if(ram >=slot9Step.step4 && ram <slot9Step.step5)
       return ITEM_WATERMELON;
    else if(ram >=slot9Step.step5 && ram <slot9Step.step6)
       return ITEM_BAR_YELLOW;
    else if(ram >=slot9Step.step6 && ram <slot9Step.step7)
       return ITEM_BAR_RED;
    else if(ram >=slot9Step.step7 && ram <slot9Step.step8)
       return ITEM_BAR_BLUE;
    else if(ram >=slot9Step.step8 && ram <slot9Step.step9)
       return ITEM_WILD;

    return ITEM_UNKNOW;
}


#endif /* MAINPROBABILITYSUBFUNC_H_ */
