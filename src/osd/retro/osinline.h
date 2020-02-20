/*
empty
*/
//============================================================
//
//  osinline.h - GNU C inline functions
//
//============================================================

//============================================================
//
//  osinline.h - GNU C inline functions
//
//============================================================

#ifndef __OSINLINE__
#define __OSINLINE__

//============================================================
//  INLINE FUNCTIONS
//============================================================


#ifndef YieldProcessor
#define YieldProcessor() do {} while (0)
#define osd_yield_processor() YieldProcessor()
#endif


#include "eminline.h"

#endif /* __OSINLINE__ */
