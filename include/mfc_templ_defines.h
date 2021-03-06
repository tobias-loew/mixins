// Usage is granted as specified in the following "Boost Software License - Version 1.0", but usage and / or distribution and / or selling as a or as part of a commercial Fortran to C / C++ translation - tool and / or translation - service is prohibited.
// 
// 
// Boost Software License - Version 1.0 - August 17th, 2003
// 
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license(the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third - parties to whom the Software is furnished to
// do so, all subject to the following :
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine - executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON - INFRINGEMENT.IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

/*=============================================================================
Copyright (c) 2019 Tobias Loew

Distributed under the Boost Software License, Version 1.0. (See above or at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/


#pragma once

///////////////////////////////////////////////////////////////////////////////
//
// mfc_templ_defines.h
// 
// inline versions of MFC's message-map macros that work within template-class
// (but also work in non-template classes)
// usage:
// 
// template<...>
// class derived : public base {
// 
// public:
//     using this_type = derived;
//     using base_type = base;
// 
//     ...
// 
//     BEGIN_MESSAGE_MAP_INLINE(this_type, base_type)
//         ON_WM_...
//     END_MESSAGE_MAP_INLINE()
// };
//
// // no DECLARE_MESSAGE_MAP... or IMPLEMENT_MESSAGE_MAP... needed!
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// definition for MESSAGE_MAP:

// the original, non-template version
/**********************************************

#define BEGIN_MESSAGE_MAP(theClass, baseClass) \
	PTM_WARNING_DISABLE \
	const AFX_MSGMAP* theClass::GetMessageMap() const \
		{ return GetThisMessageMap(); } \
	const AFX_MSGMAP* PASCAL theClass::GetThisMessageMap() \
	{ \
		typedef theClass ThisClass;						   \
		typedef baseClass TheBaseClass;					   \
		static const AFX_MSGMAP_ENTRY _messageEntries[] =  \
		{

#define END_MESSAGE_MAP() \
		{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } \
	}; \
		static const AFX_MSGMAP messageMap = \
		{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] }; \
		return &messageMap; \
	}								  \
	PTM_WARNING_RESTORE

*************************************************/

#ifndef POINTER_CAST_WARNING_DISABLE

#define POINTER_CAST_WARNING_DISABLE \
	__pragma(warning( push )) \
	__pragma(warning( disable : 4407 ))
#define POINTER_CAST_WARNING_RESTORE \
	__pragma(warning( pop ))

#endif


#ifndef PTM_WARNING_DISABLE

#define PTM_WARNING_DISABLE \
	__pragma(warning( push )) \
	__pragma(warning( disable : 4867 ))
#define PTM_WARNING_RESTORE \
	__pragma(warning( pop ))

#endif


#define STATIC_ASSERT_CCMDTARGET_IS_FIRST_BASE(theClass) \
    static_assert(offsetof(theClass, CCmdTarget::m_dwRef) == offsetof(CCmdTarget, m_dwRef), "")


// class inline version
#define BEGIN_MESSAGE_MAP_INLINE(theClass, baseClass) \
    protected: \
	PTM_WARNING_DISABLE \
    POINTER_CAST_WARNING_DISABLE                                            \
	virtual const AFX_MSGMAP* GetMessageMap() const \
		{ return GetThisMessageMap(); } \
	static const AFX_MSGMAP* PASCAL GetThisMessageMap() \
	{ \
        static_assert(offsetof(theClass, CCmdTarget::m_dwRef) == offsetof(CCmdTarget, m_dwRef), "");\
		typedef theClass ThisClass;						   \
		typedef baseClass TheBaseClass;					   \
		__pragma(warning(push))							   \
		__pragma(warning(disable: 4640)) /* message maps can only be called by single threaded message pump */ \
		static const AFX_MSGMAP_ENTRY _messageEntries[] =  \
		{



#define END_MESSAGE_MAP_INLINE() \
		{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } \
	}; \
		static const AFX_MSGMAP messageMap = \
		{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] }; \
		return &messageMap; \
	}								  \
    POINTER_CAST_WARNING_RESTORE \
    PTM_WARNING_RESTORE 


#define BEGIN_MESSAGE_MAP_INLINE_THIS_BASE() BEGIN_MESSAGE_MAP_INLINE(this_type, base_type)



