
/* ----------------------------------------------------------------------
 * G-Nut - GNSS software development library
 * 
  (c) 2018 G-Nut Software s.r.o. (software@gnutsoftware.com)
  This file is part of the G-Nut C++ library.
 
-*/

#include "gprod/gprodcrd.h"

using namespace std;

namespace gnut {

// constructor
// ----------
t_gprodcrd::t_gprodcrd(const t_gtime& t, shared_ptr<t_gobj> pt)
 : t_gprod(t, pt)
{ 
   gtrace("t_gprodcrd::t_gprodcrd");
   
   id_type(POS);
   id_group(GRP_PRODUCT);   
}

// destructor
// --------------
t_gprodcrd::~t_gprodcrd()
{
}


// add xyz
// --------------------------
void t_gprodcrd::xyz(const t_gtriple& xyz)
{
   _xyz = xyz;
}

// get xyz
// --------------------------
t_gtriple t_gprodcrd::xyz() const
{
   return _xyz;
}

// add xyz rms
// -------------------------
void t_gprodcrd::xyz_rms(const t_gtriple& xyz_rms)
{
   _xyz_rms = xyz_rms;
}

// get xyz rms
// -------------------------
t_gtriple t_gprodcrd::xyz_rms() const
{
   return _xyz_rms;
}

// get xyz var
// -------------------------
t_gtriple t_gprodcrd::xyz_var() const
{
   t_gtriple var(_xyz_rms[0]*_xyz_rms[0],
		 _xyz_rms[1]*_xyz_rms[1],
 	 	 _xyz_rms[2]*_xyz_rms[2]);
   
   return var;
}
 
// add apr
// --------------------------
void t_gprodcrd::apr(const t_gtriple& apr)
{
   _apr = apr;
}

// get apr
// --------------------------
t_gtriple t_gprodcrd::apr() const
{
   return _apr;
}

// add apr rms
// -------------------------
void t_gprodcrd::apr_rms(const t_gtriple& apr_rms)
{
   _apr_rms = apr_rms;
}

// get apr rms
// -------------------------
t_gtriple t_gprodcrd::apr_rms() const
{
   return _apr_rms;
}

// get apr var
// -------------------------
t_gtriple t_gprodcrd::apr_var() const
{
   t_gtriple var(_apr_rms[0]*_apr_rms[0],
		 _apr_rms[1]*_apr_rms[1],
 	 	 _apr_rms[2]*_apr_rms[2]);
   
   return var;
}   
   
// add cov
// -------------------------
void t_gprodcrd::cov(COV_TYPE type, double& cov)
{
   switch (type) {	
    case  COV_XY : _xy_cov = cov; break;
    case  COV_XZ : _xz_cov = cov; break;
    case  COV_YZ : _yz_cov = cov; break;	    
    default      : _xy_cov = _xz_cov = _yz_cov = 0.0;
   }
}

// get xyz rms
// -------------------------
double t_gprodcrd::cov(COV_TYPE type) const
{
   switch (type) {
    case  COV_XY : return _xy_cov; break;
    case  COV_XZ : return _xz_cov; break;
    case  COV_YZ : return _yz_cov; break;	    
    default      : return 0.0;
   }
}
   
} // namespace
