/*
    This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
    If a copy of the MPL was not distributed with this file,
    You can obtain one at https://mozilla.org/MPL/2.0/.

    Copyright (C) 2022 Daniel Jerolm
*/

/*
    Fake header offering a subset of the functions usually offered by the platform/runtime below GPCC.
    The subset is selected according to the requirements of GPCC that must be fulfilled to compile GPCC sources.

    Of course all offered functions ARE FAKEs and WILL NOT perform any meaningful operation and may even produce wrong
    results. Their only purpose is to allow compiling GPCC sources without presence of the platform/runtime.
    Of course any created artifact (e.g. a GPCC library) is of no use too and will not perform the intended operation.
*/

#ifndef SYSTEM_TIME_H_202205202239
#define SYSTEM_TIME_H_202205202239

#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

  void ch_clock_getres_realtime_coarse(struct timespec* ts);
  void ch_clock_getres_realtime(struct timespec* ts);
  void ch_clock_getres_monotonic_coarse(struct timespec* ts);
  void ch_clock_getres_monotonic(struct timespec* ts);

  void ch_clock_gettime_realtime_coarse(struct timespec* ts);
  void ch_clock_gettime_realtime(struct timespec* ts);
  void ch_clock_gettime_monotonic_coarse(struct timespec* ts);
  void ch_clock_gettime_monotonic(struct timespec* ts);

#ifdef __cplusplus
}
#endif

#endif // SYSTEM_TIME_H_202205202239
