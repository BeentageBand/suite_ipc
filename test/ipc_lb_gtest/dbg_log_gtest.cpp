/*=====================================================================================*/
/**
 * dbg_log_gtest.cpp
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#undef Dbg_FID
#define Dbg_FID Dbg_FID_Def(GTEST_FID,0)
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "gtest/gtest.h"
#include "ipc.h"
#include "dbg_log.h"
/*=====================================================================================* 
 * Standard Includes
 *=====================================================================================*/

/*=====================================================================================* 
 * Local X-Macros
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Define Macros
 *=====================================================================================*/


/*=====================================================================================* 
 * Local Type Definitions
 *=====================================================================================*/
 
/*=====================================================================================* 
 * Local Function Prototypes
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Object Definitions
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Object Definitions
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Inline-Function Like Macros
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Function Definitions
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Function Definitions
 *=====================================================================================*/
TEST(Dbg_Log, Info)
{
   Dbg_Verbose("Log Verbose %s %d", "\"String\"", 200);
   Dbg_Info("Log Info %s %d", "\"String\"", 200);
   Dbg_Warn("Log Warn %s %d", "\"String\"", 200);
   Dbg_Fault("Log Fault %s %d", "\"String\"", 200);
}
/*=====================================================================================* 
 * dbg_log_gtest.cpp
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
