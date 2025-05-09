/**
*
* @verbatim
    History
    2015-12-17  JD: created

  @endverbatim
* Copyright (c) 2018 G-Nut Software s.r.o. (software@gnutsoftware.com)
*
* @file        gtimesync.h
* @brief       Purpose: sync/filter epochs.
* @author      JD
* @version     1.0.0
* @date        2015-12-17
*
*/

#ifndef GSYNC_H
#define GSYNC_H 

#include <cmath>

#include "gio/glog.h"
#include "gutils/gtime.h"
#include "gexport/ExportLibGnut.h"

using namespace std;

namespace gnut
{
    /** @brief time synchronization. */
    LibGnut_LIBRARY_EXPORT bool time_sync(const t_gtime& epo, double smp, double scl, t_glog* glog);
} // namespace

#endif // # GSYNC_H
