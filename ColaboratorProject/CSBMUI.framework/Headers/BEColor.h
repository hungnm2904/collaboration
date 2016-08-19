//
//  BEColor.h
//  CSBMUI-iOS
//
//  Created by Loc Nguyen on 6/25/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BEColor : UIColor
///--------------------------------------
/// @name Common
///--------------------------------------

+ (UIColor *)commonBackgroundColor;

///--------------------------------------
/// @name TextFields
///--------------------------------------

+ (UIColor *)textFieldBackgroundColor;
+ (UIColor *)textFieldTextColor;
+ (UIColor *)textFieldPlaceholderColor;
+ (UIColor *)textFieldSeparatorColor;

///--------------------------------------
/// @name Buttons
///--------------------------------------

+ (UIColor *)loginButtonBackgroundColor;
+ (UIColor *)signupButtonBackgroundColor;
+ (UIColor *)facebookButtonBackgroundColor;
+ (UIColor *)twitterButtonBackgroundColor;
@end
