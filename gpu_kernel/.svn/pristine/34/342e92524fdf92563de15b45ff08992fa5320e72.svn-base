//
//

#ifndef _STDADX_H_
#define _STDADX_H_

#define __LINUX_PUNGGOL_CROSS__ 1

#ifndef __LINUX_PUNGGOL_CROSS__

#include <stdlib.h>
#include <intsafe.h>

#include <Pungo/Debug.h>

#define DRIVER_NAME L"PungoKernel"
#define DRIVER_TYPE 3

#if !defined(bool)
#define bool char
#define true 1
#define false 0
#endif


#else

#include <linux/kernel.h>	/* memset*/

#define UINT32_MAX 0xffffffff	//ScrewCompensation.c
//http://blog.chinaunix.net/uid-26833883-id-3282967.html
#define UInt32x32To64(a, b) ((unsigned long long)(((unsigned long long)((unsigned int)(a))) * ((unsigned int)(b))))//閽堝32浣嶆搷浣滅郴缁?
//#define UInt32x32To64(a, b) (a * b)//閽堝32浣嶆搷浣滅郴缁?//ScrewCompensation.c
#define _countof(array) (sizeof(array)/sizeof(array[0]))//鐢ㄦ潵璁＄畻涓€涓潤鎬佸垎閰嶇殑鏁扮粍涓殑鍏冪礌鐨勪釜鏁帮紝鑰宻izeof鏄敤鏉ヨ绠楀瓧鑺傛暟銆?

#define ASSERT(expr) \
	if (!(expr)) { \
	printk("Assertion failed! %s,%s,%s,line=%d\n", \
#expr, __FILE__, __func__, __LINE__); \
	}	//ScrewCompensation.c


#if 0
#define JOIN( X , Y ) JOIN_AGIN( X, Y )

#define JOIN_AGIN(X,Y) X##Y

typedef static_assert(e)\
	typedef char JOIN(assert_failed_at_line,__LINE___) [(e)?1:-1]
#endif



/************************************Debug*********************************************************/
#define DEBUG	//open debug message
#undef DEBUG

#ifdef DEBUG
#define PRINTK(fmt, arg...)		printk(KERN_DEBUG fmt, ##arg)
#else
#define TRACE(fmt, arg...)		printk(KERN_WARNING fmt, ##arg)
#endif

#define RTL_SOFT_VERIFY(_exp)         ((_exp) ? 1 : 0)
#define RTL_SOFT_ASSERT(x) ASSERT(x)

/************************************typedef*********************************************************/
typedef unsigned char			BYTE;	//1
typedef	BYTE					UINT8;	//1
typedef unsigned short 			WORD;	//2
typedef WORD 					UINT16;	//2
typedef unsigned int			UINT32;	//4
typedef signed int  			INT32;	//4
typedef unsigned long			DWORD;	//4
typedef unsigned long long		UINT64;	//8
typedef signed long long 		INT64;	//8
typedef long long 				__int64;//8


extern int error;


#endif//__LINUX_PUNGGOL_CROSS__
#endif
