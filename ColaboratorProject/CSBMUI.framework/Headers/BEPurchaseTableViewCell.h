//
//  BEPurchaseTableViewCell.h
//  CSBMUI
//
//  Created by Loc Nguyen on 6/26/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import "BETableViewCell.h"

#import <UIKit/UIKit.h>
#import <CSBMUI/CSBMUIConstants.h>
#import "BETableViewCell.h"

typedef NS_ENUM(uint8_t, BEPurchaseTableViewCellState) {
  /** Normal state of the cell. */
  BEPurchaseTableViewCellStateNormal = 0,
  /** Downloading state of the cell. */
  BEPurchaseTableViewCellStateDownloading,
  /** State of the cell, when the product was downloaded. */
  BEPurchaseTableViewCellStateDownloaded
};

@interface BEPurchaseTableViewCell : BETableViewCell
/**
 State of the cell.
 @see `BEPurchaseTableViewCellState`
 */
@property (nonatomic, assign) BEPurchaseTableViewCellState state;

/**
 Label where price of the product is displayed.
 */
@property (nullable, nonatomic, strong, readonly) UILabel *priceLabel;

/**
 Progress view that is shown, when the product is downloading.
 */
@property (nullable, nonatomic, strong, readonly) UIProgressView *progressView;
@end
