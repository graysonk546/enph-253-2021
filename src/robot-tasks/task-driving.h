#ifndef TASK_DRIVING
#define TASK_DRIVING

/*******************************************************************************
*                               Standard Libraries
*******************************************************************************/

#include <pt.h>
#include <pt-sem.h>

/*******************************************************************************
*                               Header Files
*******************************************************************************/

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

/*******************************************************************************
*                               Functions
*******************************************************************************/

/*******************************************************************************
 * Requires: None
 * Effects:  Returns robot_status_t indicating state of initialization
 * Modifies: None
 * ****************************************************************************/
robot_status_t taskDriving_init();

/*******************************************************************************
 * Requires: None
 * Effects:  Returns a robot_task_t pointer to the driving task
 * Modifies: None
 * ****************************************************************************/
robot_task_t* taskDriving_getTask();

#endif // TASK_DRIVING