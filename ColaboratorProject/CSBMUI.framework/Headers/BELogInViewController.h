//
//  BELogInViewController.h
//  CSBMUI
//
//  Created by Loc Nguyen on 6/26/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <CSBMUI/CSBMUIConstants.h>
#import <CSBM/PFConstants.h>
#import "BELogInView.h"

@class BESignUpViewController;
@class BEUser;
@protocol BELogInViewControllerDelegate;

@interface BELogInViewController : UIViewController <UITextFieldDelegate>
///--------------------------------------
/// @name Configuring Log In Elements
///--------------------------------------

/**
 A bitmask specifying the log in elements which are enabled in the view.
 
 @see PFLogInFields
 */
@property (nonatomic, assign) BELogInFields fields;


/**
 The log in view. It contains all the enabled log in elements.
 
 @see PFLogInView
 */
@property (nullable, nonatomic, strong, readonly) BELogInView *logInView;

///--------------------------------------
/// @name Configuring Log In Behaviors
///--------------------------------------

/**
 The delegate that responds to the control events of `PFLogInViewController`.
 
 @see PFLogInViewControllerDelegate
 */
@property (nullable, nonatomic, weak) id<BELogInViewControllerDelegate> delegate;

/**
 The facebook permissions that Facebook log in requests for.
 
 If unspecified, the default is basic facebook permissions.
 */
@property (nullable, nonatomic, copy) NSArray<NSString *> *facebookPermissions;

/**
 The sign up controller if sign up is enabled.
 
 Use this to configure the sign up view, and the transition animation to the sign up view.
 The default is a sign up view with a username, a password, a dismiss button and a sign up button.
 */
@property (nullable, nonatomic, strong) BESignUpViewController *signUpController;

/**
 Whether to prompt for the email as username on the login view.
 
 If set to `YES`, we'll prompt for the email in the username field.
 This property value propagates to the attached `signUpController`.
 By default, this is set to `NO`.
 */
@property (nonatomic, assign) BOOL emailAsUsername;

@end

///--------------------------------------
/// @name Notifications
///--------------------------------------

/**
 The notification is posted immediately after the log in succeeds.
 */
extern NSString *const BELogInSuccessNotification;

/**
 The notification is posted immediately after the log in fails.
 If the delegate prevents the log in from starting, the notification is not sent.
 */
extern NSString *const BELogInFailureNotification;

/**
 The notification is posted immediately after the log in is cancelled.
 */
extern NSString *const BELogInCancelNotification;

///--------------------------------------
/// @name PFLogInViewControllerDelegate
///--------------------------------------

/**
 The `PFLogInViewControllerDelegate` protocol defines methods a delegate of a `PFLogInViewController` should implement.
 All methods of this protocol are optional.
 */
@protocol BELogInViewControllerDelegate <NSObject>

@optional

///--------------------------------------
/// @name Customizing Behavior
///--------------------------------------

/**
 Sent to the delegate to determine whether the log in request should be submitted to the server.
 
 @param logInController The login view controller that is requesting the data.
 @param username the username the user tries to log in with.
 @param password the password the user tries to log in with.
 
 @return A `BOOL` indicating whether the log in should proceed.
 */
- (BOOL)logInViewController:(BELogInViewController *)logInController
shouldBeginLogInWithUsername:(NSString *)username
                   password:(NSString *)password;

///--------------------------------------
/// @name Responding to Actions
///--------------------------------------

/**
 Sent to the delegate when a `PFUser` is logged in.
 
 @param logInController The login view controller where login finished.
 @param user `PFUser` object that is a result of the login.
 */
- (void)logInViewController:(BELogInViewController *)logInController didLogInUser:(BEUser *)user;

/**
 Sent to the delegate when the log in attempt fails.
 
 If you implement this method, PFLoginViewController will not automatically show its default
 login failure alert view. Instead, you should show your custom alert view in your implementation.
 
 @param logInController The login view controller where login failed.
 @param error `NSError` object representing the error that occured.
 */
- (void)logInViewController:(BELogInViewController *)logInController didFailToLogInWithError:(nullable NSError *)error;

/**
 Sent to the delegate when the log in screen is cancelled.
 
 @param logInController The login view controller where login was cancelled.
 */
- (void)logInViewControllerDidCancelLogIn:(BELogInViewController *)logInController;
@end
