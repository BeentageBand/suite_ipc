/*=====================================================================================*/
/**
 * ipc_gtest_worker.c
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#define CLASS_IMPLEMENTATION
#undef Dbg_FID
#define Dbg_FID Dbg_FID_Def(IPC_FID,0)
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "dbg_log.h"
#include "ipc.h"
#include "ipc_gtest_worker.h"
/*=====================================================================================* 
 * Standard Includes
 *=====================================================================================*/

/*=====================================================================================* 
 * Local X-Macros
 *=====================================================================================*/
#undef CLASS_VIRTUAL_METHODS
#define CLASS_VIRTUAL_METHODS(_ovr) \
   _ovr(Worker,on_start) \
   _ovr(Worker,on_loop) \
   _ovr(Worker,on_stop) \
/*=====================================================================================* 
 * Local Define Macros
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Type Definitions
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Function Prototypes
 *=====================================================================================*/
static void IPC_Gtest_Worker_ctor(IPC_Gtest_Worker_T * const this, IPC_Task_Id_T const tid, uint32_t const mailbox_size);
static void IPC_Gtest_Worker_on_start(Worker_T * const super);
static void IPC_Gtest_Worker_on_loop(Worker_T * const super);
static void IPC_Gtest_Worker_on_stop(Worker_T * const super);
/*=====================================================================================* 
 * Local Object Definitions
 *=====================================================================================*/
CLASS_DEFINITION
/*=====================================================================================* 
 * Exported Object Definitions
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Inline-Function Like Macros
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Function Definitions
 *=====================================================================================*/
void IPC_Gtest_Worker_init(void)
{
   CHILD_CLASS_INITIALIZATION
   IPC_Gtest_Worker_Vtbl.ctor = IPC_Gtest_Worker_ctor;
}

void IPC_Gtest_Worker_shut(void) {}

void IPC_Gtest_Worker_Dtor(Object_T * const obj)
{
}
/*=====================================================================================* 
 * Exported Function Definitions
 *=====================================================================================*/
void IPC_Gtest_Worker_ctor(IPC_Gtest_Worker_T * const this, IPC_Task_Id_T const tid, uint32_t const mailbox_size)
{
   this->Worker.vtbl->ctor(&this->Worker, tid, mailbox_size);
}

void IPC_Gtest_Worker_on_start(Worker_T * const super)
{
   IPC_Gtest_Worker_T * const this = _dynamic_cast(IPC_Gtest_Worker, super);
   Isnt_Nullptr(this, );
   Dbg_Warn("IPC_Gtest_Worker_on_start %d", this->Worker.Task.tid);
}

void IPC_Gtest_Worker_on_loop(Worker_T * const super)
{
   IPC_Gtest_Worker_T * const this = _dynamic_cast(IPC_Gtest_Worker, super);
   Isnt_Nullptr(this, );
   Dbg_Warn("IPC_Gtest_Worker_on_loop %d", this->Worker.Task.tid);

   uint32_t timestamp = IPC_Timestamp() + 1000U;

   while(!IPC_Time_Elapsed(timestamp)){}
}

void IPC_Gtest_Worker_on_stop(Worker_T * const super)
{
   IPC_Gtest_Worker_T * const this = _dynamic_cast(IPC_Gtest_Worker, super);
   Isnt_Nullptr(this, );
   Dbg_Warn("IPC_Gtest_Worker_on_stop %d", this->Worker.Task.tid);
}
/*=====================================================================================* 
 * ipc_gtest_worker.c
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/