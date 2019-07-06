#pragma once

#include "mfc_templ_defines.h"

// converts added strings to lowercase

template<typename Base>
class lowercase_combobox : public Base {

public:
    using this_type = lowercase_combobox;
    using base_type = Base;


protected:


    afx_msg LRESULT OnAddstring(WPARAM wParam, LPARAM lParam)
    {
		CString text(reinterpret_cast<LPCTSTR>(lParam));
		text.MakeLower();
        return DefWindowProc(CB_ADDSTRING, wParam, reinterpret_cast<LPARAM>((LPCTSTR)text));
    }


    BEGIN_MESSAGE_MAP_INLINE(this_type, base_type)
        ON_MESSAGE(CB_ADDSTRING, &OnAddstring)
    END_MESSAGE_MAP_INLINE()
};
