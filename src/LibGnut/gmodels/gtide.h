
/**
*
* @verbatim
    History
    2012-11-05  JD: created

  @endverbatim
* Copyright (c) 2018 G-Nut Software s.r.o. (software@gnutsoftware.com)
*
* @file       gtide.h
* @brief      Purpose: implements tides
*.
* @author     JD
* @version    1.0.0
* @date       2012-11-05
*
*/

#ifndef GTIDE_H
#define GTIDE_H


#include <vector>

#ifdef BMUTEX
#include <boost/thread/mutex.hpp>
#endif

#include "gdata/gdata.h"
#include "gutils/gconst.h"
#include "gutils/gtime.h"
#include "gutils/gmutex.h"
#include "gutils/gtriple.h"
#include "gmodels/gephplan.h"
#include "gall/gallotl.h"
#include "gexport/ExportLibGnut.h"

using namespace std;

namespace gnut {

	/** @brief class for t_gtide. */
	class LibGnut_LIBRARY_EXPORT t_gtide
	{

	public:
		/** @brief constructor 1. */
		t_gtide(t_glog* l);
		virtual ~t_gtide();

		void   glog(t_glog* l) { _log = l; }
		/** @brief set OTL. */
		virtual void setOTL(t_gallotl* gallotl);
		/** @brief solid earth tides. */
		virtual t_gtriple tide_searth(const t_gtime& epo, t_gtriple& xyz);       // solid earth tides
		/** @brief pole tides. */
		virtual t_gtriple tide_pole();                                           // pole tides
		/** @brief ocean tide loading. */
		virtual t_gtriple load_ocean(const t_gtime& epoch, const string& site, const t_gtriple& xRec);  // ocean tide loading
		/** @brief atmospheric tide loading. */
		virtual t_gtriple load_atmosph();                                        // atmospheric tide loading

	protected:
		t_gephplan   _planEph; ///< plan eph
		t_gallotl*   _gotl;    ///< all otl
		t_gmutex     _mutex;   ///< mutex
		t_glog*      _log;     ///< log pointer

#ifdef BMUTEX
		boost::mutex _mutex;
#endif   
	};

} // namespace

#endif
