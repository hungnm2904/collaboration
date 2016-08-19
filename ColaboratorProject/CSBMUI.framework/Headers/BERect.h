//
//  BERect.h
//  CSBMUI-iOS
//
//  Created by Loc Nguyen on 6/25/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

extern CGRect BERectMakeWithOriginSize(CGPoint origin, CGSize size);
extern CGRect BERectMakeWithOrigin(CGPoint origin);
extern CGRect BERectMakeWithSize(CGSize size);

extern CGRect BERectMakeWithSizeCenteredInRect(CGSize size, CGRect rect);
extern CGSize BESizeMin(CGSize size1, CGSize size2);