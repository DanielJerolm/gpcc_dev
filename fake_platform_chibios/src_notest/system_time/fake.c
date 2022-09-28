/*
    Fake implementation of a subset of the functions usually offered by the platform/runtime below GPCC.
    The subset is selected according to the requirements of GPCC that must be fulfilled to compile GPCC sources.

    Of course all offered functions ARE FAKEs and WILL NOT perform any meaningful operation and may even produce wrong
    results. Their only purpose is to allow compiling GPCC sources without presence of the platform/runtime.
    Of course any created artifact (e.g. a GPCC library) is of no use too and will not perform the intended operation.


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

#include <platform/system_time/system_time.h>
#include <errno.h>
#include <time.h>

void platform_SYSTIME_getres(struct timespec* ts)
{
  (void)ts;
}

void platform_SYSTIME_getres_precise(struct timespec* ts)
{
  (void)ts;
}

void platform_SYSTIME_getres_monotonic(struct timespec* ts)
{
  (void)ts;
}

void platform_SYSTIME_getres_monotonic_precise(struct timespec* ts)
{
  (void)ts;
}

void platform_SYSTIME_gettime(struct timespec* ts)
{
  (void)ts;
}

void platform_SYSTIME_gettime_precise(struct timespec* ts)
{
  (void)ts;
}

void platform_SYSTIME_gettime_monotonic(struct timespec* ts)
{
  (void)ts;
}

void platform_SYSTIME_gettime_monotonic_precise(struct timespec* ts)
{
  (void)ts;
}

#if 0
int clock_settime(clockid_t clock_id, const struct timespec *tp)
{
  (void)tp;
  switch (clock_id)
  {
    case CLOCK_REALTIME:
      return 0;

    default:
      errno = EINVAL;
      return -1;
  }
}

int clock_gettime(clockid_t clock_id, struct timespec *tp)
{
  (void)tp;
  switch (clock_id)
  {
    case CLOCK_REALTIME:
    case CLOCK_MONOTONIC_COARSE:
      return 0;

    default:
      errno = EINVAL;
      return -1;
  }

}
int clock_getres(clockid_t clock_id, struct timespec *res)
{

}
#endif