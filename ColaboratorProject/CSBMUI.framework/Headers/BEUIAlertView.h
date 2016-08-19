//
//  BEUIAlertView.h
//  CSBMUI-iOS
//
//  Created by Loc Nguyen on 6/25/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void(^BEUIAlertViewCompletion)(NSUInteger selectedOtherButtonIndex);
typedef void(^BEUIAlertViewTextFieldCompletion)(UITextField *textField, NSUInteger selectedOtherButtonIndex);
typedef void(^BEUIAlertViewTextFieldCustomizationHandler)(UITextField *textField);

@interface BEUIAlertView : NSObject

+ (void)presentAlertInViewController:(UIViewController *)viewController
                           withTitle:(NSString *)title
                             message:(nullable NSString *)message
                   cancelButtonTitle:(NSString *)cancelButtonTitle
                   otherButtonTitles:(nullable NSArray *)otherButtonTitles
                          completion:(nullable BEUIAlertViewCompletion)completion;

+ (void)presentAlertInViewController:(UIViewController *)viewController
                           withTitle:(NSString *)title
                             message:(nullable NSString *)message
       textFieldCustomizationHandler:(BEUIAlertViewTextFieldCustomizationHandler)textFieldCustomizationHandler
                   cancelButtonTitle:(NSString *)cancelButtonTitle
                   otherButtonTitles:(nullable NSArray *)otherButtonTitles
                          completion:(nullable BEUIAlertViewTextFieldCompletion)completion;

///--------------------------------------
#pragma mark - Convenience
///--------------------------------------

+ (void)presentAlertInViewController:(UIViewController *)viewController
                           withTitle:(NSString *)title
                               error:(NSError *)error;
+ (void)presentAlertInViewController:(UIViewController *)viewController
                           withTitle:(NSString *)title
                             message:(nullable NSString *)message;
@end
