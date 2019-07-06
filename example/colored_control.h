#pragma once

#include "mfc_templ_defines.h"

// set fore- and background colors of mfc-controls

template<typename Base>
class colored_control : public Base {

public:
    using this_type = colored_control;
    using base_type = Base;

    COLORREF get_fg_color() const { return m_fg_color; }
    void set_fg_color(COLORREF value) { m_fg_color = value; }

    COLORREF get_bg_color() const { return m_bg_color; }
    void set_bg_color(COLORREF value) { 
        m_bg_color = value; 
        m_brush.DeleteObject();
    }

protected:

    COLORREF    m_fg_color = RGB(0,0,0);
    COLORREF    m_bg_color = RGB(255, 255, 255);
    CBrush      m_brush;

    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
    {
        if (!m_brush.m_hObject) {
            m_brush.CreateSolidBrush(m_bg_color);
        }
        HBRUSH hRet = m_brush;

        pDC->SetBkColor(m_bg_color);
        pDC->SetTextColor(m_fg_color);

        return hRet;
    }


    BEGIN_MESSAGE_MAP_INLINE(this_type, base_type)
        ON_WM_CTLCOLOR()
    END_MESSAGE_MAP_INLINE()
};
