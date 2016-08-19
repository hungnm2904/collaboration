//
//  BEImageView.h
//  CSBMUI-iOS
//
//  Created by Loc Nguyen on 6/25/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <CSBM/PFConstants.h>
#import <CSBMUI/CSBMUIConstants.h>

typedef void(^BEImageViewImageResultBlock)(UIImage *__nullable image,  NSError *__nullable error);

@class BFTask<__covariant BFGenericType>;
@class BEFile;

@interface BEImageView : UIImageView
/**
 The remote file on Parse's server that stores the image.
 
 @warning Note that the download does not start until `-loadInBackground:` is called.
 */
@property (nullable, nonatomic, strong) BEFile *file;

/**
 Initiate downloading of the remote image.
 
 Once the download completes, the remote image will be displayed.
 
 @return The task, that encapsulates the work being done.
 */
- (BFTask<UIImage *> *)loadInBackground;

/**
 Initiate downloading of the remote image.
 
 Once the download completes, the remote image will be displayed.
 
 @param completion the completion block.
 */
- (void)loadInBackground:(nullable BEImageViewImageResultBlock)completion;

/**
 Initiate downloading of the remote image.
 
 Once the download completes, the remote image will be displayed.
 
 @param completion the completion block.
 @param progressBlock called with the download progress as the image is being downloaded.
 Will be called with a value of 100 before the completion block is called.
 */
- (void)loadInBackground:(nullable BEImageViewImageResultBlock)completion
           progressBlock:(nullable void (^)(int percentDone))progressBlock;
@end
