#ifndef XDATA_H
#define XDATA_H

#include <QString>
#include <functional>

#include "XLogManagement.h"
#include "XObjectManagement.h"

namespace XData
{
#define VS(x) static inline QString x = #x
#define VC(x) static inline const char* x = #x
#define ClassName(value) static inline QString className = value

    struct Forms
    {
        enum
        {
            FORM_LOADING
        };
    };

    //==============================================================================
    struct PageParent
    {
        VC(close);
        VC(open);
    };

    struct obj_page_example : PageParent
    {
        ClassName("obj_page_example");

        VS(setData);
    };

}

#endif // XDATA_H
