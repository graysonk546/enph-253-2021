
/*******************************************************************************
*                               Standard Libraries
*******************************************************************************/

#include <pt.h>
#include <pt-sem.h>
#include <Arduino.h>

/*******************************************************************************
*                               Header Files
*******************************************************************************/

#include "task-driving.h"
#include "robot-core/dc-motor.h"
#include "utilities/util-vars.h"

/*******************************************************************************
*                               Static Functions
*******************************************************************************/

/*******************************************************************************
*                               Constants
*******************************************************************************/

/*******************************************************************************
*                               Structures
*******************************************************************************/

/*******************************************************************************
*                               Variables
*******************************************************************************/

#ifdef UNO
static robot_task_t taskDriving =
{
    taskDriving.taskMutex,
    taskDriving.taskThread,
    taskDriving.taskId = ROBOT_DRIVING
};
#elif STM32
static robot_task_t taskDriving =
{
    .taskId = ROBOT_DRIVING
};
#else
static robot_task_t taskDriving = 
{
    .taskId = ROBOT_DRIVING
};
#endif

/*******************************************************************************
*                               Functions
*******************************************************************************/

robot_status_t taskDriving_init()
{
    if (dcMotor_init() != ROBOT_OK)
    {
        return ROBOT_ERR;
    }
    // Initialize the driving task pt thread
    PT_INIT(&taskDriving.taskThread);
    // Initialize the driving task pt sem
    PT_SEM_INIT(&taskDriving.taskMutex, 0);
    return ROBOT_OK;
}

robot_task_t* taskDriving_getTask()
{
    return &taskDriving;
}