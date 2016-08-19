//
//  BEActivityIndicatorTableViewCell.h
//  CSBMUI-iOS
//
//  Created by Loc Nguyen on 6/25/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BETableViewCell.h"

@interface BEActivityIndicatorTableViewCell : BETableViewCell
@property (nonatomic, assign, getter=isAnimating) BOOL animating;
@end
