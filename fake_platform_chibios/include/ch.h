/*
    Fake header offering a subset of the definitions, types and functions usually offered by ChibiOS/RT.
    The subset is selected according to the requirements of GPCC that must be fulfilled to compile GPCC sources.

    Of course all offered definitions, types, macros, and functions ARE FAKEs and WILL NOT perform any meaningful
    operations. Especially types, macros and defines may differ completely from the "productive" orginal definitions
    from ChibiOS/RT and may even produce wrong results. Their only purpose is to allow compiling GPCC sources without
    presence of a real ChibiOS/RT operating system. Of course any created artifact (e.g. a GPCC library) is of no use
    too and will not perform the intended operation.


    Copyright (C) 2022 Daniel Jerolm

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

    Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the
    distribution.

    Neither the name of the author nor the names of his contributors
    may be used to endorse or promote products derived from this
    software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
    A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
    OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef CH_H_202205201927
#define CH_H_202205201927

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------
// Selected definitions from ChibiOS/RT user configuration
// ----------------------------------------------------------------------------
#define CH_CFG_ST_FREQUENCY     1000

// ----------------------------------------------------------------------------
// Selected data types and definitions from "port"
// ----------------------------------------------------------------------------
#define PORT_WORKING_AREA_ALIGN 4

typedef uint32_t                sysinterval_t;
typedef uint32_t                tprio_t;
typedef int32_t                 msg_t;
typedef int32_t                 cnt_t;
typedef uint64_t                stkalign_t;

// ----------------------------------------------------------------------------
// Selected general definitions from "ch.h" and nested headers
// ----------------------------------------------------------------------------
#define IDLEPRIO                (tprio_t)1
#define LOWPRIO                 (tprio_t)2
#define NORMALPRIO              (tprio_t)128
#define HIGHPRIO                (tprio_t)255

#define MSG_OK                  (msg_t)0
#define MSG_TIMEOUT             (msg_t)-1

#define TIME_MAX_INTERVAL       ((sysinterval_t)-2)

#define CH_DBG_STACK_FILL_VALUE 0x55

// ----------------------------------------------------------------------------
// Selected data types and defintions related to threads
// ----------------------------------------------------------------------------
typedef void (*tfunc_t)(void *p);

struct ch_thread
{
  tprio_t               prio;
  stkalign_t*           wabase;
  struct ch_mutex       *mtxlist;
};

typedef struct ch_thread thread_t;

struct ch_threads_queue
{
  thread_t              *next;
  thread_t              *prev;
};

typedef struct ch_threads_queue threads_queue_t;

#define THD_WORKING_AREA_SIZE(n) (sizeof(thread_t) + n)

// ----------------------------------------------------------------------------
// Selected data types and definitions releated to mutexes
// ----------------------------------------------------------------------------
typedef struct ch_mutex mutex_t;

struct ch_mutex
{
  thread_t              *owner;
};

// ----------------------------------------------------------------------------
// Selected data types and definitions related to semaphores
// ----------------------------------------------------------------------------
typedef struct ch_semaphore
{
  threads_queue_t       queue;
} semaphore_t;

// ----------------------------------------------------------------------------
// Selected data types and definitions related to condition variables
// ----------------------------------------------------------------------------
typedef struct condition_variable
{
  threads_queue_t       queue;
} condition_variable_t;

// ----------------------------------------------------------------------------
// Selected definitions related to address alignment
// ----------------------------------------------------------------------------
#define MEM_ALIGN_NEXT(p, a) (p)


#ifdef __cplusplus
extern "C" {
#endif

  // ----------------------------------------------------------------------------
  // Selected function declarations
  // ----------------------------------------------------------------------------
  void chSysHalt(const char *reason);

  // ----------------------------------------------------------------------------
  // Selected function declarations related to threads
  // ----------------------------------------------------------------------------
  thread_t* chThdGetSelfX(void);
  tprio_t chThdGetPriorityX(void);

  thread_t *chThdCreateStatic(void *wsp, size_t size, tprio_t prio, tfunc_t pf, void *arg);
  msg_t chThdWait(thread_t *tp);
  void chThdSleep(sysinterval_t time);
  void chThdExit(msg_t msg);
  void chRegSetThreadName(const char *name);

  bool queue_notempty(const threads_queue_t *tqp);

  // ----------------------------------------------------------------------------
  // Selected function declarations related to mutexes
  // ----------------------------------------------------------------------------
  void chMtxObjectInit(mutex_t *mp);
  void chMtxLock(mutex_t *mp);
  void chMtxLockS(mutex_t *mp);
  bool chMtxTryLock(mutex_t *mp);
  bool chMtxTryLockS(mutex_t *mp);
  void chMtxUnlock(mutex_t *mp);
  void chMtxUnlockS(mutex_t *mp);
  void chMtxUnlockAll(void);
  void chMtxUnlockAllS(void);

  // ----------------------------------------------------------------------------
  // Selected function declarations related to semaphores
  // ----------------------------------------------------------------------------
  void chSemObjectInit(semaphore_t *sp, cnt_t n);
  void chSemReset(semaphore_t *sp, cnt_t n);
  void chSemResetI(semaphore_t *sp, cnt_t n);
  msg_t chSemWait(semaphore_t *sp);
  msg_t chSemWaitS(semaphore_t *sp);
  msg_t chSemWaitTimeout(semaphore_t *sp, sysinterval_t timeout);
  msg_t chSemWaitTimeoutS(semaphore_t *sp, sysinterval_t timeout);
  void chSemSignal(semaphore_t *sp);
  void chSemSignalI(semaphore_t *sp);
  void chSemAddCounterI(semaphore_t *sp, cnt_t n);
  msg_t chSemSignalWait(semaphore_t *sps, semaphore_t *spw);

  // ----------------------------------------------------------------------------
  // Selected function declarations related to condition variables
  // ----------------------------------------------------------------------------
  void chCondObjectInit(condition_variable_t *cp);
  void chCondSignal(condition_variable_t *cp);
  void chCondSignalI(condition_variable_t *cp);
  void chCondBroadcast(condition_variable_t *cp);
  void chCondBroadcastI(condition_variable_t *cp);
  msg_t chCondWait(condition_variable_t *cp);
  msg_t chCondWaitS(condition_variable_t *cp);
  msg_t chCondWaitTimeout(condition_variable_t *cp, sysinterval_t timeout);
  msg_t chCondWaitTimeoutS(condition_variable_t *cp, sysinterval_t timeout);

#ifdef __cplusplus
}
#endif

#endif // CH_H_202205201927
