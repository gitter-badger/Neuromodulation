/* Created by Language version: 6.2.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__tmGlut_M1RH_D1
#define _nrn_initial _nrn_initial__tmGlut_M1RH_D1
#define nrn_cur _nrn_cur__tmGlut_M1RH_D1
#define _nrn_current _nrn_current__tmGlut_M1RH_D1
#define nrn_jacob _nrn_jacob__tmGlut_M1RH_D1
#define nrn_state _nrn_state__tmGlut_M1RH_D1
#define _net_receive _net_receive__tmGlut_M1RH_D1 
#define state state__tmGlut_M1RH_D1 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define tau1_ampa _p[0]
#define tau2_ampa _p[1]
#define tau1_nmda _p[2]
#define tau2_nmda _p[3]
#define nmda_ratio _p[4]
#define e _p[5]
#define tau _p[6]
#define tauR _p[7]
#define tauF _p[8]
#define U _p[9]
#define u0 _p[10]
#define ca_ratio_ampa _p[11]
#define ca_ratio_nmda _p[12]
#define mg _p[13]
#define failRate _p[14]
#define maxModA_AMPA _p[15]
#define levelA _p[16]
#define maxModB_AMPA _p[17]
#define modA _p[18]
#define maxModA_NMDA _p[19]
#define modB _p[20]
#define maxModB_NMDA _p[21]
#define levelB _p[22]
#define failRateA _p[23]
#define failRateB _p[24]
#define use_stp _p[25]
#define i _p[26]
#define i_ampa _p[27]
#define i_nmda _p[28]
#define g _p[29]
#define g_ampa _p[30]
#define g_nmda _p[31]
#define A_ampa _p[32]
#define B_ampa _p[33]
#define C_ampa _p[34]
#define A_nmda _p[35]
#define B_nmda _p[36]
#define C_nmda _p[37]
#define ical _p[38]
#define ical_ampa _p[39]
#define ical_nmda _p[40]
#define factor_ampa _p[41]
#define factor_nmda _p[42]
#define x _p[43]
#define DA_ampa _p[44]
#define DB_ampa _p[45]
#define DC_ampa _p[46]
#define DA_nmda _p[47]
#define DB_nmda _p[48]
#define DC_nmda _p[49]
#define v _p[50]
#define _g _p[51]
#define _tsav _p[52]
#define _nd_area  *_ppvar[0]._pval
#define _ion_ical	*_ppvar[2]._pval
#define _ion_dicaldv	*_ppvar[3]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 /* declaration of user functions */
 static double _hoc_modulationB_AMPA();
 static double _hoc_modulationA_AMPA();
 static double _hoc_modulationB_NMDA();
 static double _hoc_modulationA_NMDA();
 static double _hoc_urand();
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(_ho) Object* _ho; { void* create_point_process();
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt();
 static double _hoc_loc_pnt(_vptr) void* _vptr; {double loc_point_process();
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(_vptr) void* _vptr; {double has_loc_point();
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(_vptr)void* _vptr; {
 double get_loc_point_process(); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 "modulationB_AMPA", _hoc_modulationB_AMPA,
 "modulationA_AMPA", _hoc_modulationA_AMPA,
 "modulationB_NMDA", _hoc_modulationB_NMDA,
 "modulationA_NMDA", _hoc_modulationA_NMDA,
 "urand", _hoc_urand,
 0, 0
};
#define modulationB_AMPA modulationB_AMPA_tmGlut_M1RH_D1
#define modulationA_AMPA modulationA_AMPA_tmGlut_M1RH_D1
#define modulationB_NMDA modulationB_NMDA_tmGlut_M1RH_D1
#define modulationA_NMDA modulationA_NMDA_tmGlut_M1RH_D1
#define urand urand_tmGlut_M1RH_D1
 extern double modulationB_AMPA( _threadargsproto_ );
 extern double modulationA_AMPA( _threadargsproto_ );
 extern double modulationB_NMDA( _threadargsproto_ );
 extern double modulationA_NMDA( _threadargsproto_ );
 extern double urand( _threadargsproto_ );
 /* declare global and static user variables */
#define tau3_nmda tau3_nmda_tmGlut_M1RH_D1
 double tau3_nmda = 212.116;
#define tau3_ampa tau3_ampa_tmGlut_M1RH_D1
 double tau3_ampa = 64.295;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "U", 0, 1,
 "u0", 0, 1,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "tau3_ampa_tmGlut_M1RH_D1", "ms",
 "tau3_nmda_tmGlut_M1RH_D1", "ms",
 "tau1_ampa", "ms",
 "tau2_ampa", "ms",
 "tau1_nmda", "ms",
 "tau2_nmda", "ms",
 "nmda_ratio", "1",
 "e", "mV",
 "tau", "ms",
 "tauR", "ms",
 "tauF", "ms",
 "U", "1",
 "u0", "1",
 "mg", "mM",
 "A_ampa", "uS",
 "B_ampa", "uS",
 "C_ampa", "uS",
 "A_nmda", "uS",
 "B_nmda", "uS",
 "C_nmda", "uS",
 "i", "nA",
 "i_ampa", "nA",
 "i_nmda", "nA",
 "g", "uS",
 "g_ampa", "uS",
 "g_nmda", "uS",
 0,0
};
 static double A_nmda0 = 0;
 static double A_ampa0 = 0;
 static double B_nmda0 = 0;
 static double B_ampa0 = 0;
 static double C_nmda0 = 0;
 static double C_ampa0 = 0;
 static double delta_t = 0.01;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "tau3_ampa_tmGlut_M1RH_D1", &tau3_ampa_tmGlut_M1RH_D1,
 "tau3_nmda_tmGlut_M1RH_D1", &tau3_nmda_tmGlut_M1RH_D1,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[4]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "6.2.0",
"tmGlut_M1RH_D1",
 "tau1_ampa",
 "tau2_ampa",
 "tau1_nmda",
 "tau2_nmda",
 "nmda_ratio",
 "e",
 "tau",
 "tauR",
 "tauF",
 "U",
 "u0",
 "ca_ratio_ampa",
 "ca_ratio_nmda",
 "mg",
 "failRate",
 "maxModA_AMPA",
 "levelA",
 "maxModB_AMPA",
 "modA",
 "maxModA_NMDA",
 "modB",
 "maxModB_NMDA",
 "levelB",
 "failRateA",
 "failRateB",
 "use_stp",
 0,
 "i",
 "i_ampa",
 "i_nmda",
 "g",
 "g_ampa",
 "g_nmda",
 0,
 "A_ampa",
 "B_ampa",
 "C_ampa",
 "A_nmda",
 "B_nmda",
 "C_nmda",
 0,
 0};
 static Symbol* _cal_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 53, _prop);
 	/*initialize range parameters*/
 	tau1_ampa = 0.819;
 	tau2_ampa = 4.626;
 	tau1_nmda = 1.729;
 	tau2_nmda = 34.413;
 	nmda_ratio = 0.5;
 	e = 0;
 	tau = 3;
 	tauR = 100;
 	tauF = 800;
 	U = 0.3;
 	u0 = 0;
 	ca_ratio_ampa = 0.005;
 	ca_ratio_nmda = 0.1;
 	mg = 1;
 	failRate = 0;
 	maxModA_AMPA = 1;
 	levelA = 0;
 	maxModB_AMPA = 1;
 	modA = 0;
 	maxModA_NMDA = 1;
 	modB = 0;
 	maxModB_NMDA = 1;
 	levelB = 0;
 	failRateA = 0;
 	failRateB = 0;
 	use_stp = 1;
  }
 	_prop->param = _p;
 	_prop->param_size = 53;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 5, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_cal_sym);
 	_ppvar[2]._pval = &prop_ion->param[3]; /* ical */
 	_ppvar[3]._pval = &prop_ion->param[4]; /* _ion_dicaldv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _net_receive(Point_process*, double*, double);
 static void _net_init(Point_process*, double*, double);
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _tmglut_M1RH_D1_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("cal", 2.0);
 	_cal_sym = hoc_lookup("cal_ion");
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 1,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 53, 5);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "cal_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cal_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 pnt_receive[_mechtype] = _net_receive;
 pnt_receive_init[_mechtype] = _net_init;
 pnt_receive_size[_mechtype] = 5;
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 tmGlut_M1RH_D1 /home/miseno/Documents/GitHub/Neuromodulation/examples/dSPN/x86_64/tmglut_M1RH_D1.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Glutamatergic synapse with short-term plasticity (stp)";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[6], _dlist1[6];
 static int state(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   DA_ampa = - A_ampa / tau1_ampa ;
   DB_ampa = - B_ampa / tau2_ampa ;
   DC_ampa = - C_ampa / tau3_ampa ;
   DA_nmda = - A_nmda / tau1_nmda ;
   DB_nmda = - B_nmda / tau2_nmda ;
   DC_nmda = - C_nmda / tau3_nmda ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 DA_ampa = DA_ampa  / (1. - dt*( ( - 1.0 ) / tau1_ampa )) ;
 DB_ampa = DB_ampa  / (1. - dt*( ( - 1.0 ) / tau2_ampa )) ;
 DC_ampa = DC_ampa  / (1. - dt*( ( - 1.0 ) / tau3_ampa )) ;
 DA_nmda = DA_nmda  / (1. - dt*( ( - 1.0 ) / tau1_nmda )) ;
 DB_nmda = DB_nmda  / (1. - dt*( ( - 1.0 ) / tau2_nmda )) ;
 DC_nmda = DC_nmda  / (1. - dt*( ( - 1.0 ) / tau3_nmda )) ;
 return 0;
}
 /*END CVODE*/
 static int state (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
    A_ampa = A_ampa + (1. - exp(dt*(( - 1.0 ) / tau1_ampa)))*(- ( 0.0 ) / ( ( - 1.0 ) / tau1_ampa ) - A_ampa) ;
    B_ampa = B_ampa + (1. - exp(dt*(( - 1.0 ) / tau2_ampa)))*(- ( 0.0 ) / ( ( - 1.0 ) / tau2_ampa ) - B_ampa) ;
    C_ampa = C_ampa + (1. - exp(dt*(( - 1.0 ) / tau3_ampa)))*(- ( 0.0 ) / ( ( - 1.0 ) / tau3_ampa ) - C_ampa) ;
    A_nmda = A_nmda + (1. - exp(dt*(( - 1.0 ) / tau1_nmda)))*(- ( 0.0 ) / ( ( - 1.0 ) / tau1_nmda ) - A_nmda) ;
    B_nmda = B_nmda + (1. - exp(dt*(( - 1.0 ) / tau2_nmda)))*(- ( 0.0 ) / ( ( - 1.0 ) / tau2_nmda ) - B_nmda) ;
    C_nmda = C_nmda + (1. - exp(dt*(( - 1.0 ) / tau3_nmda)))*(- ( 0.0 ) / ( ( - 1.0 ) / tau3_nmda ) - C_nmda) ;
   }
  return 0;
}
 
static void _net_receive (_pnt, _args, _lflag) Point_process* _pnt; double* _args; double _lflag; 
{  double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _thread = (Datum*)0; _nt = (_NrnThread*)_pnt->_vnt;   _p = _pnt->_prop->param; _ppvar = _pnt->_prop->dparam;
  if (_tsav > t){ extern char* hoc_object_name(); hoc_execerror(hoc_object_name(_pnt->ob), ":Event arrived out of order. Must call ParallelContext.set_maxstep AFTER assigning minimum NetCon.delay");}
 _tsav = t; {
   double _lweight_ampa , _lweight_nmda ;
 if ( _args[0] <= 0.0 ) {
     
/*VERBATIM*/
        return;
 }
   if ( urand ( _threadargs_ ) > failRate * ( failRateA * modA * levelA + failRateB * modB * levelB ) ) {
     _args[2] = _args[2] * exp ( - ( t - _args[4] ) / tauR ) ;
     _args[2] = _args[2] + ( _args[1] * ( exp ( - ( t - _args[4] ) / tau ) - exp ( - ( t - _args[4] ) / tauR ) ) / ( tau / tauR - 1.0 ) ) ;
     _args[1] = _args[1] * exp ( - ( t - _args[4] ) / tau ) ;
     x = 1.0 - _args[1] - _args[2] ;
     if ( tauF > 0.0 ) {
       _args[3] = _args[3] * exp ( - ( t - _args[4] ) / tauF ) ;
       _args[3] = _args[3] + U * ( 1.0 - _args[3] ) ;
       }
     else {
       _args[3] = U ;
       }
     if ( use_stp > 0.0 ) {
       _lweight_ampa = _args[0] * x * _args[3] / U ;
       }
     else {
       _lweight_ampa = _args[0] ;
       }
     _lweight_nmda = _lweight_ampa * nmda_ratio ;
       if (nrn_netrec_state_adjust && !cvode_active_){
    /* discon state adjustment for cnexp case (rate uses no local variable) */
    double __state = A_ampa;
    double __primary = (A_ampa + _lweight_ampa * factor_ampa) - __state;
     __primary += ( 1. - exp( 0.5*dt*( ( - 1.0 ) / tau1_ampa ) ) )*( - ( 0.0 ) / ( ( - 1.0 ) / tau1_ampa ) - __primary );
    A_ampa += __primary;
  } else {
 A_ampa = A_ampa + _lweight_ampa * factor_ampa ;
       }
   if (nrn_netrec_state_adjust && !cvode_active_){
    /* discon state adjustment for cnexp case (rate uses no local variable) */
    double __state = B_ampa;
    double __primary = (B_ampa + _lweight_ampa * factor_ampa) - __state;
     __primary += ( 1. - exp( 0.5*dt*( ( - 1.0 ) / tau2_ampa ) ) )*( - ( 0.0 ) / ( ( - 1.0 ) / tau2_ampa ) - __primary );
    B_ampa += __primary;
  } else {
 B_ampa = B_ampa + _lweight_ampa * factor_ampa ;
       }
   if (nrn_netrec_state_adjust && !cvode_active_){
    /* discon state adjustment for cnexp case (rate uses no local variable) */
    double __state = A_nmda;
    double __primary = (A_nmda + _lweight_nmda * factor_nmda) - __state;
     __primary += ( 1. - exp( 0.5*dt*( ( - 1.0 ) / tau1_nmda ) ) )*( - ( 0.0 ) / ( ( - 1.0 ) / tau1_nmda ) - __primary );
    A_nmda += __primary;
  } else {
 A_nmda = A_nmda + _lweight_nmda * factor_nmda ;
       }
   if (nrn_netrec_state_adjust && !cvode_active_){
    /* discon state adjustment for cnexp case (rate uses no local variable) */
    double __state = B_nmda;
    double __primary = (B_nmda + _lweight_nmda * factor_nmda) - __state;
     __primary += ( 1. - exp( 0.5*dt*( ( - 1.0 ) / tau2_nmda ) ) )*( - ( 0.0 ) / ( ( - 1.0 ) / tau2_nmda ) - __primary );
    B_nmda += __primary;
  } else {
 B_nmda = B_nmda + _lweight_nmda * factor_nmda ;
       }
 _args[1] = _args[1] + x * _args[3] ;
     _args[4] = t ;
     }
   } }
 
static void _net_init(Point_process* _pnt, double* _args, double _lflag) {
       double* _p = _pnt->_prop->param;
    Datum* _ppvar = _pnt->_prop->dparam;
    Datum* _thread = (Datum*)0;
    _NrnThread* _nt = (_NrnThread*)_pnt->_vnt;
 _args[1] = 0.0 ;
   _args[2] = 0.0 ;
   _args[3] = u0 ;
   _args[4] = t ;
   }
 
double urand ( _threadargsproto_ ) {
   double _lurand;
 _lurand = scop_random ( 1.0 ) ;
   
return _lurand;
 }
 
static double _hoc_urand(void* _vptr) {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  urand ( _p, _ppvar, _thread, _nt );
 return(_r);
}
 
double modulationA_NMDA ( _threadargsproto_ ) {
   double _lmodulationA_NMDA;
 _lmodulationA_NMDA = 1.0 + modA * ( maxModA_NMDA - 1.0 ) * levelA ;
   
return _lmodulationA_NMDA;
 }
 
static double _hoc_modulationA_NMDA(void* _vptr) {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  modulationA_NMDA ( _p, _ppvar, _thread, _nt );
 return(_r);
}
 
double modulationB_NMDA ( _threadargsproto_ ) {
   double _lmodulationB_NMDA;
 _lmodulationB_NMDA = 1.0 + modB * ( maxModB_NMDA - 1.0 ) * levelB ;
   
return _lmodulationB_NMDA;
 }
 
static double _hoc_modulationB_NMDA(void* _vptr) {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  modulationB_NMDA ( _p, _ppvar, _thread, _nt );
 return(_r);
}
 
double modulationA_AMPA ( _threadargsproto_ ) {
   double _lmodulationA_AMPA;
 _lmodulationA_AMPA = 1.0 + modA * ( maxModA_AMPA - 1.0 ) * levelA ;
   
return _lmodulationA_AMPA;
 }
 
static double _hoc_modulationA_AMPA(void* _vptr) {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  modulationA_AMPA ( _p, _ppvar, _thread, _nt );
 return(_r);
}
 
double modulationB_AMPA ( _threadargsproto_ ) {
   double _lmodulationB_AMPA;
 _lmodulationB_AMPA = 1.0 + modB * ( maxModB_AMPA - 1.0 ) * levelB ;
   
return _lmodulationB_AMPA;
 }
 
static double _hoc_modulationB_AMPA(void* _vptr) {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  modulationB_AMPA ( _p, _ppvar, _thread, _nt );
 return(_r);
}
 
static int _ode_count(int _type){ return 6;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 6; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_cal_sym, _ppvar, 2, 3);
   nrn_update_ion_pointer(_cal_sym, _ppvar, 3, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  A_nmda = A_nmda0;
  A_ampa = A_ampa0;
  B_nmda = B_nmda0;
  B_ampa = B_ampa0;
  C_nmda = C_nmda0;
  C_ampa = C_ampa0;
 {
   double _ltp_ampa , _ltp_nmda ;
 A_ampa = 0.0 ;
   B_ampa = 0.0 ;
   C_ampa = 0.0 ;
   _ltp_ampa = 1.628 ;
   factor_ampa = - exp ( - _ltp_ampa / tau1_ampa ) + exp ( - _ltp_ampa / tau2_ampa ) + exp ( - _ltp_ampa / tau3_ampa ) ;
   factor_ampa = 1.0 / factor_ampa ;
   A_nmda = 0.0 ;
   B_nmda = 0.0 ;
   C_nmda = 0.0 ;
   _ltp_nmda = 5.137 ;
   factor_nmda = - exp ( - _ltp_nmda / tau1_nmda ) + exp ( - _ltp_nmda / tau2_nmda ) + exp ( - _ltp_nmda / tau3_nmda ) ;
   factor_nmda = 1.0 / factor_nmda ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _tsav = -1e20;
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   double _litot_nmda , _litot_ampa , _lmggate ;
 _lmggate = 1.0 / ( 1.0 + exp ( - 0.062 * v ) * ( mg / 2.62 ) ) ;
   g_nmda = ( B_nmda - A_nmda ) * modulationA_NMDA ( _threadargs_ ) * modulationB_NMDA ( _threadargs_ ) ;
   _litot_nmda = g_nmda * ( v - e ) * _lmggate ;
   ical_nmda = ca_ratio_nmda * _litot_nmda ;
   i_nmda = _litot_nmda - ical_nmda ;
   g_ampa = ( B_ampa - A_ampa ) * modulationA_AMPA ( _threadargs_ ) * modulationB_AMPA ( _threadargs_ ) ;
   _litot_ampa = g_ampa * ( v - e ) ;
   ical_ampa = ca_ratio_ampa * _litot_ampa ;
   i_ampa = _litot_ampa - ical_ampa ;
   ical = ical_nmda + ical_ampa ;
   g = g_ampa + g_nmda ;
   i = i_ampa + i_nmda ;
   }
 _current += i;
 _current += ical;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dical;
  _dical = ical;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dicaldv += (_dical - ical)/.001 * 1.e2/ (_nd_area);
 	}
 _g = (_g - _rhs)/.001;
  _ion_ical += ical * 1.e2/ (_nd_area);
 _g *=  1.e2/(_nd_area);
 _rhs *= 1.e2/(_nd_area);
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
 {   state(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(A_ampa) - _p;  _dlist1[0] = &(DA_ampa) - _p;
 _slist1[1] = &(B_ampa) - _p;  _dlist1[1] = &(DB_ampa) - _p;
 _slist1[2] = &(C_ampa) - _p;  _dlist1[2] = &(DC_ampa) - _p;
 _slist1[3] = &(A_nmda) - _p;  _dlist1[3] = &(DA_nmda) - _p;
 _slist1[4] = &(B_nmda) - _p;  _dlist1[4] = &(DB_nmda) - _p;
 _slist1[5] = &(C_nmda) - _p;  _dlist1[5] = &(DC_nmda) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
