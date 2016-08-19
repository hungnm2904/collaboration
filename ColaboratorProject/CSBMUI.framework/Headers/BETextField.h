//
//  BETextField.h
//  CSBMUI-iOS
//
//  Created by Loc Nguyen on 6/25/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CSBMUI/CSBMUIConstants.h>

typedef NS_OPTIONS(uint8_t, BETextFieldSeparatorStyle){
  /** No separators are visible. */
  BETextFieldSeparatorStyleNone = 0,
  /** Separator on top of the text field. */
  BETextFieldSeparatorStyleTop = 1 << 0,
  /** Separator at the bottom of the text field. */
  BETextFieldSeparatorStyleBottom = 1 << 1
};
@interface BETextField : UITextField
/**
 Separator style bitmask that should be applied to this textfield.
 
 Default: `BETextFieldSeparatorStyleNone`
 
 @see BETextFieldSeparatorStyle
 */
@property (nonatomic, assign) BETextFieldSeparatorStyle separatorStyle;

/**
 Color that should be used for the separators, if they are visible.
 
 Default: `227,227,227,1.0`.
 */
@property (nullable, nonatomic, strong) UIColor *separatorColor UI_APPEARANCE_SELECTOR;

/**
 This method is a convenience initializer that sets both `frame` and `separatorStyle` for an instance of `BETextField.`
 
 @param frame          The frame rectangle for the view, measured in points.
 @param separatorStyle Initial separator style to use.
 
 @return An initialized instance of `BETextField` or `nil` if it couldn't be created.
 */
- (instancetype)initWithFrame:(CGRect)frame separatorStyle:(BETextFieldSeparatorStyle)separatorStyle;
@end
