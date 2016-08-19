//
//  BEImage.h
//  CSBMUI-iOS
//
//  Created by Loc Nguyen on 6/25/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BEImage : UIImage
+ (UIImage *)imageWithColor:(UIColor *)color;
+ (UIImage *)imageWithColor:(UIColor *)color cornerRadius:(CGFloat)cornerRadius;

+ (UIImage *)imageNamed:(NSString *)name;
@end
