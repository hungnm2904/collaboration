//
//  BELogInView.h
//  CSBMUI
//
//  Created by Loc Nguyen on 6/26/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CSBMUI/CSBMUIConstants.h>

typedef NS_OPTIONS(NSInteger, BELogInFields) {
  /** No fields. */
  BELogInFieldsNone = 0,
  /** Username and password fields. */
  BELogInFieldsUsernameAndPassword = 1 << 0,
  /** Forgot password button. */
  BELogInFieldsPasswordForgotten = 1 << 1,
  /** Login button. */
  BELogInFieldsLogInButton = 1 << 2,
  /** Button to login with Facebook. */
  BELogInFieldsFacebook = 1 << 3,
  /** Button to login with Twitter. */
  BELogInFieldsTwitter = 1 << 4,
  /** Signup Button. */
  BELogInFieldsSignUpButton = 1 << 5,
  /** Dismiss Button. */
  BELogInFieldsDismissButton = 1 << 6,
  
  /** Default value. Combines Username, Password, Login, Signup, Forgot Password and Dismiss buttons. */
  BELogInFieldsDefault = (BELogInFieldsUsernameAndPassword |
                          BELogInFieldsLogInButton |
                          BELogInFieldsSignUpButton |
                          BELogInFieldsPasswordForgotten |
                          BELogInFieldsDismissButton)
};

extern NSString *const BELogInViewUsernameFieldAccessibilityIdentifier;
extern NSString *const BELogInViewPasswordFieldAccessibilityIdentifier;
extern NSString *const BELogInViewLogInButtonAccessibilityIdentifier;
extern NSString *const BELogInViewSignUpButtonAccessibilityIdentifier;
extern NSString *const BELogInViewPasswordForgottenButtonAccessibilityIdentifier;
extern NSString *const BELogInViewTwitterButtonAccessibilityIdentifier;
extern NSString *const BELogInViewFacebookButtonAccessibilityIdentifier;
extern NSString *const BELogInViewDismissButtonAccessibilityIdentifier;

@class BETextField;

@interface BELogInView : UIScrollView
- (instancetype)initWithFields:(BELogInFields)fields;

/**
 The view controller that will present this view.
 
 Used to lay out elements correctly when the presenting view controller has translucent elements.
 */
@property (nullable, nonatomic, weak) UIViewController *presentingViewController;

///--------------------------------------
/// @name Customizing the Logo
///--------------------------------------

/// The logo. By default, it is the Parse logo.
@property (nullable, nonatomic, strong) UIView *logo;

///--------------------------------------
/// @name Configure Username Behaviour
///--------------------------------------

/**
 If email should be used to log in, instead of username
 
 By default, this is set to `NO`.
 */
@property (nonatomic, assign) BOOL emailAsUsername;

///--------------------------------------
/// @name Log In Elements
///--------------------------------------

/**
 The bitmask which specifies the enabled log in elements in the view.
 */
@property (nonatomic, assign, readonly) BELogInFields fields;

/**
 The username text field. It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) BETextField *usernameField;

/**
 The password text field. It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) BETextField *passwordField;

/**
 The password forgotten button. It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) UIButton *passwordForgottenButton;

/**
 The log in button. It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) UIButton *logInButton;

/**
 The Facebook button. It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) UIButton *facebookButton;

/**
 The Twitter button. It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) UIButton *twitterButton;

/**
 The sign up button. It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) UIButton *signUpButton;

/**
 It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) UIButton *dismissButton;

/**
 The facebook/twitter login label.
 
 @deprecated This property is deprecated and will always be nil.
 */
@property (nullable, nonatomic, strong, readonly) UILabel *externalLogInLabel __attribute__(CSBM_UI_DEPRECATED("This property is deprecated and will always be nil."));

/**
 The sign up label.
 
 @deprecated This property is deprecated and will always be nil.
 */
@property (nullable, nonatomic, strong, readonly) UILabel *signUpLabel __attribute__(CSBM_UI_DEPRECATED("This property is deprecated and will always be nil."));
@end
