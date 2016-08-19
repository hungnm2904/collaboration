//
//  CSBMUIConstants.h
//  CSBMUI
//
//  Created by Loc Nguyen on 6/26/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <Availability.h>
#import <TargetConditionals.h>

#ifndef CSBMUI_CSBMUIConstants_h
#define CSBMUI_CSBMUIConstants_h

///--------------------------------------
/// @name Deprecated Macros
///--------------------------------------

#ifndef CSBM_UI_DEPRECATED
#  ifdef __deprecated_msg
#    define CSBM_UI_DEPRECATED(_MSG) (deprecated(_MSG))
#  else
#    ifdef __deprecated
#      define CSBM_UI_DEPRECATED(_MSG) (deprecated)
#    else
#      define CSBM_UI_DEPRECATED(_MSG)
#    endif
#  endif
#endif

#endif
