//
//  BEActivityIndicatorCollectionReusableView.h
//  CSBMUI-iOS
//
//  Created by Loc Nguyen on 6/25/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BEActivityIndicatorCollectionReusableView : UICollectionReusableView
@property (nonatomic, strong, readonly) UILabel *textLabel;

@property (nonatomic, assign, getter=isAnimating) BOOL animating;

- (void)addTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)controlEvents;
- (void)removeTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)controlEvents;
@end
