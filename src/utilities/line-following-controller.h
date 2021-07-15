#ifndef LINE_FOLLOWING_CONTROLLER
#define LINE_FOLLOWING_CONTROLLER

/*******************************************************************************
*                               Standard Libraries
*******************************************************************************/

#include <stdint.h>

/*******************************************************************************
*                               Header Files
*******************************************************************************/

#include "line-follower.h"
#include "robot-core/reflectance.h"
#include "robot-core/dc-motor-two.h"
#include "line-follower.h"
#include "util-vars.h"

/*******************************************************************************
*                               Static Functions
*******************************************************************************/

/*******************************************************************************
*                               Constants
*******************************************************************************/

/*******************************************************************************
*                               Structures
*******************************************************************************/

typedef enum {
    FAR_LEFT = -5, 
    SLIGHT_LEFT = -1,
    NO_ERROR = 0,
    SLIGHT_RIGHT = 1, 
    FAR_RIGHT = 5
} line_following_error_t;

typedef struct {
    int gain;
    int kp;
    int ki;
    int kd;
} pid_constant_t;

/*******************************************************************************
*                               Variables
*******************************************************************************/

/*******************************************************************************
*                               Functions
*******************************************************************************/

robot_status_t lineFollowingController_init(reflectance_t* sensor1,
                                            reflectance_t* sensor2,
                                            dc_motor_two_t* motor1,
                                            dc_motor_two_t* motor2);

robot_status_t lineFollowingController_spinOnce();

#endif // LINE_FOLLOWING_CONTROLLER