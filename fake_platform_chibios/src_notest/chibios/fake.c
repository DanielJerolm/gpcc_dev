/*
    Fake implementation of a subset of functions usually offered by ChibiOS/RT.
    The subset is selected according to the requirements of GPCC that must be fulfilled to compile GPCC sources.

    Of course all offered functions ARE FAKEs and WILL NOT perform any meaningful operations and will not produce any
    valid result. Their only purpose is to allow compiling GPCC sources without presence of a real ChibiOS/RT operating
    system. Of course any created artifact (e.g. a GPCC library) is of no use too and will not perform the intended
    operation.


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

#include <ch.h>

static uint8_t dummy = 0U;

// ----------------------------------------------------------------------------
// Selected function declarations
// ----------------------------------------------------------------------------
void chSysHalt(const char *reason)
{
  (void)reason;
  while (true) {};
}

// ----------------------------------------------------------------------------
// Selected functions related to threads
// ----------------------------------------------------------------------------
thread_t* chThdGetSelfX(void)
{
  return (thread_t*)(&dummy);
}

tprio_t chThdGetPriorityX(void)
{
  return NORMALPRIO;
}

thread_t *chThdCreateStatic(void *wsp, size_t size, tprio_t prio, tfunc_t pf, void *arg)
{
  (void)size;
  (void)prio;
  (void)pf;
  (void)arg;
  return (thread_t*)wsp;
}

msg_t chThdWait(thread_t *tp)
{
  (void)tp;
  return MSG_OK;
}

void chThdSleep(sysinterval_t time)
{
  (void)time;
}

void chThdExit(msg_t msg)
{
  (void)msg;
}

void chRegSetThreadName(const char *name)
{
  (void)name;
}

bool queue_notempty(const threads_queue_t *tqp)
{
  (void)tqp;
  return false;
}

// ----------------------------------------------------------------------------
// Selected functions related to mutexes
// ----------------------------------------------------------------------------
void chMtxObjectInit(mutex_t *mp)
{
  (void)mp;
}

void chMtxLock(mutex_t *mp)
{
  (void)mp;
}

void chMtxLockS(mutex_t *mp)
{
  (void)mp;
}

bool chMtxTryLock(mutex_t *mp)
{
  (void)mp;
  return true;
}

bool chMtxTryLockS(mutex_t *mp)
{
  (void)mp;
  return true;
}

void chMtxUnlock(mutex_t *mp)
{
  (void)mp;
}

void chMtxUnlockS(mutex_t *mp)
{
  (void)mp;
}

void chMtxUnlockAll(void)
{
}

void chMtxUnlockAllS(void)
{
}

// ----------------------------------------------------------------------------
// Selected functions related to semaphores
// ----------------------------------------------------------------------------
void chSemObjectInit(semaphore_t *sp, cnt_t n)
{
  (void)sp;
  (void)n;
}

void chSemReset(semaphore_t *sp, cnt_t n)
{
  (void)sp;
  (void)n;
}

void chSemResetI(semaphore_t *sp, cnt_t n)
{
  (void)sp;
  (void)n;
}

msg_t chSemWait(semaphore_t *sp)
{
  (void)sp;
  return MSG_OK;
}

msg_t chSemWaitS(semaphore_t *sp)
{
  (void)sp;
  return MSG_OK;
}

msg_t chSemWaitTimeout(semaphore_t *sp, sysinterval_t timeout)
{
  (void)sp;
  (void)timeout;
  return MSG_OK;
}

msg_t chSemWaitTimeoutS(semaphore_t *sp, sysinterval_t timeout)
{
  (void)sp;
  (void)timeout;
  return MSG_OK;
}

void chSemSignal(semaphore_t *sp)
{
  (void)sp;
}

void chSemSignalI(semaphore_t *sp)
{
  (void)sp;
}

void chSemAddCounterI(semaphore_t *sp, cnt_t n)
{
  (void)sp;
  (void)n;
}

msg_t chSemSignalWait(semaphore_t *sps, semaphore_t *spw)
{
  (void)sps;
  (void)spw;
  return MSG_OK;
}

// ----------------------------------------------------------------------------
// Selected functions related to condition variables
// ----------------------------------------------------------------------------
void chCondObjectInit(condition_variable_t *cp)
{
  (void)cp;
}

void chCondSignal(condition_variable_t *cp)
{
  (void)cp;
}

void chCondSignalI(condition_variable_t *cp)
{
  (void)cp;
}

void chCondBroadcast(condition_variable_t *cp)
{
  (void)cp;
}

void chCondBroadcastI(condition_variable_t *cp)
{
  (void)cp;
}

msg_t chCondWait(condition_variable_t *cp)
{
  (void)cp;
  return MSG_OK;
}

msg_t chCondWaitS(condition_variable_t *cp)
{
  (void)cp;
  return MSG_OK;
}

msg_t chCondWaitTimeout(condition_variable_t *cp, sysinterval_t timeout)
{
  (void)cp;
  (void)timeout;
  return MSG_OK;
}

msg_t chCondWaitTimeoutS(condition_variable_t *cp, sysinterval_t timeout)
{
  (void)cp;
  (void)timeout;
  return MSG_OK;
}

void chThdSleepMilliseconds(uint32_t msec)
{
  (void)msec;
}
