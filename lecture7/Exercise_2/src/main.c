/*!
   @brief Exercise_2 - Create project on base OS Protothreads using a functions PT_WAIT_UNTIL, PT_SCHEDULE
   @author Dmytro Lytvyniuk
   @date January
   @warning This program was created for educational purposes.
 */
#include <windows.h>
#include "../inc/pt.h"
#include <stdio.h>

static struct pt proto1, proto2;

static int PROTOTHREAD_1_flag, PROTOTHREAD_2_flag;

/*
 * The first protothread function.
 */
static int PROTOTHREAD_1(struct pt *pt)
{

  PT_BEGIN(pt);

  while(1) {
    /*! Wait flag. */
    PT_WAIT_UNTIL(pt, PROTOTHREAD_2_flag != 0);
    printf("Running protothread 1 \n");
    sleep(2);

    PROTOTHREAD_2_flag = 0;
    PROTOTHREAD_1_flag = 1;
  }
  PT_END(pt);
}

static int PROTOTHREAD_2(struct pt *pt)
{
  PT_BEGIN(pt);

  while(1) {
    /*! Let the other protothread run. */
    PROTOTHREAD_2_flag = 1;

    /* Wait set its flag. */
    PT_WAIT_UNTIL(pt, PROTOTHREAD_1_flag != 0);

    printf("Running protothread 2 \n");
    sleep(2);

    PROTOTHREAD_1_flag = 0; // reset
  }
  PT_END(pt);
}

int main(void)
{
  PT_INIT(&proto1);
  PT_INIT(&proto2);

  while(1) {

    PT_SCHEDULE(PROTOTHREAD_1(&proto1));
    PT_SCHEDULE(PROTOTHREAD_2(&proto2));

  }
}
