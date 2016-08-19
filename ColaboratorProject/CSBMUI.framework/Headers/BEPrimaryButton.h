//
//  BEPrimaryButton.h
//  CSBMUI-iOS
//
//  Created by Loc Nguyen on 6/25/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BEPrimaryButton : UIButton
@property (nonatomic, assign, getter=isLoading) BOOL loading;

- (instancetype)initWithBackgroundImageColor:(UIColor *)color NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
@end
