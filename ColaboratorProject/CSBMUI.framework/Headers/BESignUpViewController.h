//
//  BESignUpViewController.h
//  CSBMUI
//
//  Created by Loc Nguyen on 6/26/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <CSBMUI/CSBMUIConstants.h>
#import <CSBM/PFConstants.h>
#import "BESignUpView.h"

@class BEUser;
@protocol BESignUpViewControllerDelegate;

@interface BESignUpViewController : UIViewController <UITextFieldDelegate, UIScrollViewDelegate>
///--------------------------------------
/// @name Configuring Sign Up Elements
///--------------------------------------

/**
 A bitmask specifying the log in elements which are enabled in the view.
 
 @see PFSignUpFields
 */
@property (nonatomic, assign) BESignUpFields fields;

/**
 The sign up view. It contains all the enabled log in elements.
 
 @see PFSignUpView
 */
@property (nullable, nonatomic, strong, readonly) BESignUpView *signUpView;

///--------------------------------------
/// @name Configuring Sign Up Behaviors
///--------------------------------------

/**
 The delegate that responds to the control events of `PFSignUpViewController`.
 
 @see PFSignUpViewControllerDelegate
 */
@property (nullable, nonatomic, weak) id<BESignUpViewControllerDelegate> delegate;

/**
 Minimum required password length for user signups, defaults to `0`.
 */
@property (nonatomic, assign) NSUInteger minPasswordLength;

/**
 Whether to use the email as username on the attached `signUpView`.
 
 If set to `YES`, we'll hide the email field, prompt for the email in
 the username field, and save the email into both username and email
 fields on the new `PFUser` object. By default, this is set to `NO`.
 */
@property (nonatomic, assign) BOOL emailAsUsername;

@end

///--------------------------------------
/// @name Notifications
///--------------------------------------

/**
 The notification is posted immediately after the sign up succeeds.
 */
extern NSString *const BESignUpSuccessNotification;

/**
 The notification is posted immediately after the sign up fails.
 
 If the delegate prevents the sign up to start, the notification is not sent.
 */
extern NSString *const BESignUpFailureNotification;

/**
 The notification is posted immediately after the user cancels sign up.
 */
extern NSString *const BESignUpCancelNotification;

///--------------------------------------
/// @name PFSignUpViewControllerDelegate
///--------------------------------------

/**
 The `PFLogInViewControllerDelegate` protocol defines methods a delegate of a `PFSignUpViewController` should implement.
 All methods of this protocol are optional.
 */
@protocol BESignUpViewControllerDelegate <NSObject>

@optional

///--------------------------------------
/// @name Customizing Behavior
///--------------------------------------

/**
 Sent to the delegate to determine whether the sign up request should be submitted to the server.
 
 @param signUpController The signup view controller that is requesting the data.
 @param info An `NSDictionary` instance which contains all sign up information that the user entered.
 
 @return A `BOOL` indicating whether the sign up should proceed.
 */
- (BOOL)signUpViewController:(BESignUpViewController *)signUpController shouldBeginSignUp:(NSDictionary<NSString *, NSString *> *)info;

///--------------------------------------
/// @name Responding to Actions
///--------------------------------------

/**
 Sent to the delegate when a `PFUser` is signed up.
 
 @param signUpController The signup view controller where signup finished.
 @param user `PFUser` object that is a result of the sign up.
 */
- (void)signUpViewController:(BESignUpViewController *)signUpController didSignUpUser:(BEUser *)user;

/**
 Sent to the delegate when the sign up attempt fails.
 
 @param signUpController The signup view controller where signup failed.
 @param error `NSError` object representing the error that occured.
 */
- (void)signUpViewController:(BESignUpViewController *)signUpController didFailToSignUpWithError:(nullable NSError *)error;

/**
 Sent to the delegate when the sign up screen is cancelled.
 
 @param signUpController The signup view controller where signup was cancelled.
 */
- (void)signUpViewControllerDidCancelSignUp:(BESignUpViewController *)signUpController;
@end

