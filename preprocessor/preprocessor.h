/**
 * @file preprocessor.h
 * @brief PreProcessor define.
 *
 */

#ifndef PREPROCESSOR_H_
#define PREPROCESSOR_H_

#ifndef __arm__
#define FPS_CONTROL/**< FPS Control */
#endif

#define ENABLE_KEYBOARD_INPUT/**< Enable keyboard input */

//#define DEBUG_OUTPUT_AWARD_DETAIL/**< Debug output award detail */

//#define DEBUG_MAINGAME_SPECIFIED_ITEM/**< Debug main game specified item */

#ifdef __arm__
#define USE_DIRECTFB_INPUT_MODULE/**< Use directFB input module */
#endif

/*--- Version control ---*/
#define Release_Version/**< Official Release Version */
#ifndef Release_Version
#define Fast_Run_Test/**< Fast Run Test Version */
#define DebugInfo/**< Output debug information on screen */
#endif

/*--- Select game image type ---*/
//#define PIC_ORIGINAL/**< Image type is classic type */
#ifndef PIC_ORIGINAL
	//#define PIC_OCEAN/**< Image type is ocean world type */
		#ifdef PIC_OCEAN
			#define PIC_OCEAN_CHS/**< Image type is ocean world CHS type */
	    #endif

    #if !defined(PIC_ORIGINAL) && !defined(PIC_OCEAN)
        #define PIC_FRUIT/**< Image type is fruit king type */
	#endif
#endif

/*--- Game option setting ---*/

#define Genuine_Compute_Score/**< Genuine style of computing main game score,If you don't know how it works don't comment it out */

#define Max_Win_Limit/**< Max Win => (MaxBet) * 100000(Blue7 * 9 )  */

/*--- Probability module setting ---*/
//#define MAIN_PRO_VER_A/**< Probability module A */
#ifndef MAIN_PRO_VER_A
	#define MAIN_PRO_VER_B/**< Probability Version B */
#endif

//#define DOUBLEUP_PRO_VER_A/**< Double up game probability module A */
#ifndef DOUBLEUP_PRO_VER_A
	#define DOUBLEUP_PRO_VER_B/**< Double up game probability module B */
#endif

/*--- Test module(can't appear in release version) ---*/
#ifndef Release_Version
//#define TEST_MAIN_GAME_COMPUTE_SCORE  false/**< Test main game compute score */
//#define WONDER_MEDIA_TEST             false/**< Requested by WonderMedia(2010/10) */
#endif


#endif /* PREPROCESSOR_H_ */
