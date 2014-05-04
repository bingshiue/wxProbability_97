/**
 * @file probabilityEnum.h
 * @brief Define probability Enumeration.
 *
 */

#ifndef PROBABILITYENUM_H_
#define PROBABILITYENUM_H_

#include "../preprocessor/preprocessor.h"

/**
 * @brief Probability Control Type of each Frame.
 */
enum ScrollProbability{
    Type_Fixed_1  = 0,        /**< Fix Type 1 */
    Type_Fixed_2  = 1,        /**< Fix Type 2 */
	Type_Fixed_3  = 2,        /**< Fix Type 3 */
	Type_Fixed_4  = 3,        /**< Fix Type 4 */
	Type_Fixed_5  = 4,        /**< Fix Type 5 */
	Type_Fixed_6  = 5,        /**< Fix Type 6 */
	Type_Fixed_7  = 6,        /**< Fix Type 7 */
	Type_Fixed_8  = 7,        /**< Fix Type 8 */
	Type_Mutable  = 8         /**< Mutable Type */
#if TEST_MAIN_GAME_COMPUTE_SCORE==1
   ,Type_Test = 9             /**< For Test Main Game Compute Score */
#endif
};

/**
 * @brief Probability Control Status.
 */
enum ProbabilityControlStatus
{
	status_normal = 0,         /**< Probability Control Status is Normal */
	status_up     = 1,         /**< Probability Control Status is Up */
	status_down   = 2,         /**< Probability Control Status is Down */
	status_link   = 3          /**< Probability Control Status is Link Mode */
};

/**
 * @brief game level.
 */
enum GameLevel{
	 Game_Level_Small = 0,/**< game level small */
	 Game_Level_Mid   = 1,/**< game level middle */
	 Game_Level_Big   = 2 /**< game level big */
};


#endif /* PROBABILITYENUM_H_ */

