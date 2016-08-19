//
//  BECollectionViewCell.h
//  CSBMUI
//
//  Created by Loc Nguyen on 6/26/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CSBMUI/CSBMUIConstants.h>
@class BEImageView;
@class BEObject;

@interface BECollectionViewCell : UICollectionViewCell
/**
 A simple lazy-loaded label for the collection view cell.
 */
@property (nonatomic, strong, readonly) UILabel *textLabel;

/**
 The lazy-loaded imageView of the collection view cell.
 
 @see PFImageView
 */
@property (nonatomic, strong, readonly) BEImageView *imageView;

/**
 This method should update all the relevant information inside a subclass of `PFCollectionViewCell`.
 
 This method is automatically called by `PFQueryCollectionViewController` whenever the cell
 should display new information. By default this method does nothing.
 
 @param object An instance of `PFObject` to update from.
 */
- (void)updateFromObject:(nullable BEObject *)object;
@end
