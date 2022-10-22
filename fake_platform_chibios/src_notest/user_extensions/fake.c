/*
    This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
    If a copy of the MPL was not distributed with this file,
    You can obtain one at https://mozilla.org/MPL/2.0/.

    Copyright (C) 2022 Daniel Jerolm
*/

/*
    Fake implementation of a subset of the functions usually offered by the platform/runtime below GPCC.
    The subset is selected according to the requirements of GPCC that must be fulfilled to compile GPCC sources.

    Of course all offered functions ARE FAKEs and WILL NOT perform any meaningful operation and may even produce wrong
    results. Their only purpose is to allow compiling GPCC sources without presence of the platform/runtime.
    Of course any created artifact (e.g. a GPCC library) is of no use too and will not perform the intended operation.
*/


/*
    In a real productive implementation, the functions shall provide the resolution and a reading of the following
    clocks:
    - A coarse realtime clock. It shall provide UTC time based on the system tick (e.g. 1ms).
    - A precise realtime clock. It shall provide UTC time with the highest feasible precision. On some platforms,
      reading this clock may be more expensive than reading the coarse version of this clock.
    - A coarse monotonic clock. It shall provide the time passed by since the system has booted based on the system tick
      (e.g. 1ms). __This shall be the same clock like the one used by ChibiOS/RT to specify timeouts for condition__
      __variables, semaphores etc.__
    - A precise monotonic clock. It shall provide the time passed by since the system has booted with the highest
      feasible precision. On some platforms, reading this clock may be more expensive than reading the coarse version of
      this clock.

    The requried functions are inspired by POSIX functionality. Search the web for `clock_getres()`, `clock_gettime()`,
    `CLOCK_REALTIME`, `CLOCK_REALTIME_COARSE`, `CLOCK_MONOTONIC` and `CLOCK_MONOTONIC_COARSE`.
*/

#include <chClockAndTime.h>

void ch_clock_getres_realtime_coarse(struct timespec* ts)
{
  (void)ts;
}

void ch_clock_getres_realtime(struct timespec* ts)
{
  (void)ts;
}

void ch_clock_getres_monotonic_coarse(struct timespec* ts)
{
  (void)ts;
}

void ch_clock_getres_monotonic(struct timespec* ts)
{
  (void)ts;
}

void ch_clock_gettime_realtime_coarse(struct timespec* ts)
{
  (void)ts;
}

void ch_clock_gettime_realtime(struct timespec* ts)
{
  (void)ts;
}

void ch_clock_gettime_monotonic_coarse(struct timespec* ts)
{
  (void)ts;
}

void ch_clock_gettime_monotonic(struct timespec* ts)
{
  (void)ts;
}
