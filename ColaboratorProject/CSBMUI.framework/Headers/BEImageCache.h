//
//  BEImageCache.h
//  CSBMUI-iOS
//
//  Created by Loc Nguyen on 6/25/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface BEImageCache : NSCache
+ (instancetype)sharedCache;

- (void)setImage:(UIImage *)image forURL:(NSURL *)url;
- (UIImage *)imageForURL:(NSURL *)url;
@end
