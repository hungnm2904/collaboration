//
//  BETableViewCell.h
//  CSBMUI
//
//  Created by Loc Nguyen on 6/26/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CSBMUI/CSBMUIConstants.h>
#import "BEImageView.h"

@interface BETableViewCell : UITableViewCell
@property (nullable, nonatomic, strong, readonly) BEImageView *imageView;
@end
