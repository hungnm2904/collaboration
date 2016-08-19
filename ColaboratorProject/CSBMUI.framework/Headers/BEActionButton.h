//
//  BEActionButton.h
//  CSBMUI-iOS
//
//  Created by Loc Nguyen on 6/25/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(uint8_t, BEActionButtonStyle)
{
  BEActionButtonStyleNormal,
  BEActionButtonStyleWide
};

@class BEActionButtonConfiguration;

@interface BEActionButton : UIButton

@property (nonatomic, assign, getter=isLoading) BOOL loading;

@property (nonatomic, assign) BEActionButtonStyle buttonStyle;

///--------------------------------------
/// @name Class
///--------------------------------------

+ (NSString *)titleForButtonStyle:(BEActionButtonStyle)buttonStyle;

///--------------------------------------
/// @name Init
///--------------------------------------

- (instancetype)initWithConfiguration:(BEActionButtonConfiguration *)configuration
                          buttonStyle:(BEActionButtonStyle)buttonStyle NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

@end

@interface BEActionButtonConfiguration : NSObject

@property (nonatomic, strong, readonly) UIColor *backgroundImageColor;
@property (nonatomic, strong, readonly) UIImage *image;

- (instancetype)initWithBackgroundImageColor:(UIColor *)backgroundImageColor
                                       image:(UIImage *)image NS_DESIGNATED_INITIALIZER;

- (void)setTitle:(NSString *)title forButtonStyle:(BEActionButtonStyle)style;
- (NSString *)titleForButtonStyle:(BEActionButtonStyle)style;

@end
