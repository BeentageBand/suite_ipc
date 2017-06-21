/*=====================================================================================*/
/**
 * ipc_gtest.cpp
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#define CLASS_IMPLEMENTATION
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "gtest/gtest.h"
#include "ipc_gtest.h"
#include "task_ext.h"
#include "ipc.h"
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

static IPC_Mail_Id_T Gtest_Mailist[] =
{
      IPC_GTEST_SUBS
};
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
TEST(Init, tasks)
{
   static Task_T test = Task();
   static IPC_Gtest_Worker_T w1 = IPC_Gtest_Worker();
   static IPC_Gtest_Worker_T w2 = IPC_Gtest_Worker();

   test.vtbl->ctor(&test, GTEST_FWK_WORKER);
   w1.vtbl->ctor(&w1, IPC_GTEST_1_WORKER, 64);
   w2.vtbl->ctor(&w2, IPC_GTEST_2_WORKER, 64);

   Task_register_to_process(NULL);
   IPC_create_mailbox(64, 256);
   IPC_task_ready();

   w1.Worker.Task.vtbl->run(&w1.Worker.Task);
   w2.Worker.Task.vtbl->run(&w2.Worker.Task);
}

TEST(Retrieve_mail, mail)
{
   Mail_T * mail = NULL;

   for(uint8_t i = 2; i; --i)
   {
      mail = IPC_retreive_mail(IPC_RETRIEVE_TOUT_MS);
      ASSERT_FALSE(NULL == mail);
      EXPECT_EQ(mail->mail_id, IPC_GTEST_EV);
   }

}

TEST(Retrieve_Mail, timeout)
{
   IPC_Timestamp_T timestamp = IPC_RETRIEVE_TOUT_MS + IPC_timestamp();
   Mail_T * mail = IPC_retreive_mail(IPC_RETRIEVE_TOUT_MS);

   EXPECT_TRUE(IPC_time_elapsed(timestamp));
   ASSERT_TRUE(NULL == mail);
}

TEST(Publish, mail)
{
   IPC_publish(IPC_GTEST_SUBS, NULL, 0);

   if(IPC_subscribe_mail_list(Gtest_Mailist, sizeof(Gtest_Mailist)) )
   {
      Mail_T * mail = NULL;

      for(uint8_t i = 2; i; --i)
      {
         mail = IPC_retreive_from_mail_list(Gtest_Mailist,
               sizeof(Gtest_Mailist), IPC_RETRIEVE_TOUT_MS);
         ASSERT_FALSE(NULL == mail);
         EXPECT_EQ(mail->mail_id, IPC_GTEST_SUBS);
      }
      mail = IPC_retreive_from_mail_list(Gtest_Mailist,
                     sizeof(Gtest_Mailist), IPC_RETRIEVE_TOUT_MS);
      ASSERT_TRUE(NULL == mail);

      bool_t success = IPC_unsubscribe_mail_list(Gtest_Mailist, sizeof(Gtest_Mailist));
      ASSERT_TRUE(success);
   }
   else
   {
      FAIL();
   }
}


TEST(Shutdown, mail)
{
   IPC_broadcast(WORKER_SHUTDOWN, NULL, 0);
}

/*=====================================================================================* 
 * ipc_gtest.cpp
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
