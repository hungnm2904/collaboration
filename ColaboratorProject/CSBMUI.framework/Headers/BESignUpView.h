//
//  BESignUpView.h
//  CSBMUI
//
//  Created by Loc Nguyen on 6/26/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CSBMUI/CSBMUIConstants.h>
typedef NS_OPTIONS(NSInteger, BESignUpFields) {
  /** Username and password fields. */
  BESignUpFieldsUsernameAndPassword = 0,
  /** Email field. */
  BESignUpFieldsEmail = 1 << 0,
  /** This field can be used for something else. */
  BESignUpFieldsAdditional = 1 << 1,
  /** Sign Up Button */
  BESignUpFieldsSignUpButton = 1 << 2,
  /** Dismiss Button */
  BESignUpFieldsDismissButton = 1 << 3,
  /** Default value. Combines Username, Password, Email, Sign Up and Dismiss Buttons. */
  BESignUpFieldsDefault = (BESignUpFieldsUsernameAndPassword |
                           BESignUpFieldsEmail |
                           BESignUpFieldsSignUpButton |
                           BESignUpFieldsDismissButton)
};


extern NSString *const BESignUpViewUsernameFieldAccessibilityIdentifier;
extern NSString *const BESignUpViewEmailFieldAccessibilityIdentifier;
extern NSString *const BESignUpViewPasswordFieldAccessibilityIdentifier;
extern NSString *const BESignUpViewAdditionalFieldAccessibilityIdentifier;
extern NSString *const BESignUpViewSignUpButtonAccessibilityIdentifier;
extern NSString *const BESignUpViewDismissButtonAccessibilityIdentifier;

@class BETextField;

@interface BESignUpView : UIScrollView
///--------------------------------------
/// @name Creating SignUp View
///--------------------------------------

/**
 Initializes the view with the specified sign up elements.
 
 @param fields A bitmask specifying the sign up elements which are enabled in the view
 
 @return An initialized `PFSignUpView` object or `nil` if the object couldn't be created.
 
 @see PFSignUpFields
 */
- (instancetype)initWithFields:(BESignUpFields)fields;

/**
 The view controller that will present this view.
 
 Used to lay out elements correctly when the presenting view controller has translucent elements.
 */
@property (nullable, nonatomic, weak) UIViewController *presentingViewController;

///--------------------------------------
/// @name Customizing the Logo
///--------------------------------------

/**
 The logo. By default, it is the Parse logo.
 */
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
/// @name Sign Up Elements
///--------------------------------------

/**
 The bitmask which specifies the enabled sign up elements in the view
 */
@property (nonatomic, assign, readonly) BESignUpFields fields;

/**
 The username text field.
 */
@property (nullable, nonatomic, strong, readonly) BETextField *usernameField;

/**
 The password text field.
 */
@property (nullable, nonatomic, strong, readonly) BETextField *passwordField;

/**
 The email text field. It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) BETextField *emailField;

/**
 The additional text field. It is `nil` if the element is not enabled.
 
 This field is intended to be customized.
 */
@property (nullable, nonatomic, strong, readonly) BETextField *additionalField;

/**
 The sign up button. It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) UIButton *signUpButton;

/**
 The dismiss button. It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) UIButton *dismissButton;

@end
