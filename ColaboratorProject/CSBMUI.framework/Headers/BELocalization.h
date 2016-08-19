//
//  BELocalization.h
//  CSBMUI-iOS
//
//  Created by Loc Nguyen on 6/25/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#ifndef CSBMUI_BELocalization_h
#define CSBMUI_BELocalization_h

#define BELocalizedString(key, comment) \
[[NSBundle bundleForClass:[self class]] localizedStringForKey:key value:nil table:@"CSBMUI"]

#endif
