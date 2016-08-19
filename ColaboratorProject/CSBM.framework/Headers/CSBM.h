/**
 * Copyright (c) 2015-present, Parse, LLC.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <Foundation/Foundation.h>

#import <CSBM/CSBMClientConfiguration.h>
#import <CSBM/BEACL.h>
#import <CSBM/BEAnalytics.h>
#import <CSBM/BEAnonymousUtils.h>
#import <CSBM/PFAnonymousUtils+Deprecated.h>
#import <CSBM/BECloud.h>
#import <CSBM/PFCloud+Deprecated.h>
#import <CSBM/PFCloud+Synchronous.h>
#import <CSBM/BEConfig.h>
#import <CSBM/PFConfig+Synchronous.h>
#import <CSBM/PFConstants.h>
#import <CSBM/BEFile.h>
#import <CSBM/PFFile+Deprecated.h>
#import <CSBM/PFFile+Synchronous.h>
#import <CSBM/BEGeoPoint.h>
#import <CSBM/BEObject.h>
#import "BEObject+Subclass.h"
#import <CSBM/PFObject+Synchronous.h>
#import <CSBM/PFObject+Deprecated.h>
#import <CSBM/BEQuery.h>
#import <CSBM/PFQuery+Synchronous.h>
#import <CSBM/PFQuery+Deprecated.h>
#import <CSBM/BERelation.h>
#import <CSBM/BERole.h>
#import <CSBM/BESession.h>
#import <CSBM/PFSubclassing.h>
#import <CSBM/BEUser.h>
#import <CSBM/PFUser+Synchronous.h>
#import <CSBM/PFUser+Deprecated.h>
#import <CSBM/PFUserAuthenticationDelegate.h>

#if TARGET_OS_IOS

#import <CSBM/BEInstallation.h>
#import <CSBM/BENetworkActivityIndicatorManager.h>
#import <CSBM/BEPush.h>
#import <CSBM/PFPush+Synchronous.h>
#import <CSBM/PFPush+Deprecated.h>
#import <CSBM/BEProduct.h>
#import <CSBM/BEPurchase.h>

#elif PF_TARGET_OS_OSX

#import <CSBM/PFInstallation.h>
#import <CSBM/PFPush.h>
#import <CSBM/PFPush+Synchronous.h>
#import <CSBM/PFPush+Deprecated.h>

#elif TARGET_OS_TV

#import <CSBM/PFProduct.h>
#import <CSBM/PFPurchase.h>

#endif

NS_ASSUME_NONNULL_BEGIN

/**
 The `Parse` class contains static functions that handle global configuration for the Parse framework.
 */
@interface CSBM : NSObject

///--------------------------------------
#pragma mark - Connecting to Parse
///--------------------------------------

/**
 Sets the applicationId and clientKey of your application.

 @param applicationId The application id of your Parse application.
 @param clientKey The client key of your Parse application.
 */
+ (void)setApplicationId:(NSString *)applicationId clientKey:(NSString *)clientKey;

/**
 Sets the configuration to be used for the Parse SDK.

 @note Re-setting the configuration after having previously sent requests through the SDK results in undefined behavior.

 @param configuration The new configuration to set for the SDK.
 */
+ (void)initializeWithConfiguration:(CSBMClientConfiguration *)configuration;

/**
 Gets the current configuration in use by the Parse SDK.

 @return The current configuration in use by the SDK. Returns nil if the SDK has not been initialized yet.
 */
+ (nullable CSBMClientConfiguration *)currentConfiguration;

/**
 The current application id that was used to configure Parse framework.
 */
+ (NSString *)getApplicationId;

/**
 The current client key that was used to configure Parse framework.
 */
+ (nullable NSString *)getClientKey;

///--------------------------------------
#pragma mark - Enabling Local Datastore
///--------------------------------------

/**
 Enable pinning in your application. This must be called before your application can use
 pinning. The recommended way is to call this method before `+setApplicationId:clientKey:`.
 */
+ (void)enableLocalDatastore PF_TV_UNAVAILABLE;

/**
 Flag that indicates whether Local Datastore is enabled.

 @return `YES` if Local Datastore is enabled, otherwise `NO`.
 */
+ (BOOL)isLocalDatastoreEnabled PF_TV_UNAVAILABLE;

///--------------------------------------
#pragma mark - Enabling Extensions Data Sharing
///--------------------------------------

/**
 Enables data sharing with an application group identifier.

 After enabling - Local Datastore, `PFUser.+currentUser`, `PFInstallation.+currentInstallation` and all eventually commands
 are going to be available to every application/extension in a group that have the same Parse applicationId.

 @warning This method is required to be called before `+setApplicationId:clientKey:`.

 @param groupIdentifier Application Group Identifier to share data with.
 */
+ (void)enableDataSharingWithApplicationGroupIdentifier:(NSString *)groupIdentifier PF_EXTENSION_UNAVAILABLE("Use `enableDataSharingWithApplicationGroupIdentifier:containingApplication:`.") PF_WATCH_UNAVAILABLE PF_TV_UNAVAILABLE;

/**
 Enables data sharing with an application group identifier.

 After enabling - Local Datastore, `PFUser.+currentUser`, `PFInstallation.+currentInstallation` and all eventually commands
 are going to be available to every application/extension in a group that have the same Parse applicationId.

 @warning This method is required to be called before `+setApplicationId:clientKey:`.
 This method can only be used by application extensions.

 @param groupIdentifier Application Group Identifier to share data with.
 @param bundleIdentifier Bundle identifier of the containing application.
 */
+ (void)enableDataSharingWithApplicationGroupIdentifier:(NSString *)groupIdentifier
                                  containingApplication:(NSString *)bundleIdentifier PF_WATCH_UNAVAILABLE PF_TV_UNAVAILABLE;

/**
 Application Group Identifier for Data Sharing.

 @return `NSString` value if data sharing is enabled, otherwise `nil`.
 */
+ (NSString *)applicationGroupIdentifierForDataSharing PF_WATCH_UNAVAILABLE PF_TV_UNAVAILABLE;

/**
 Containing application bundle identifier for Data Sharing.

 @return `NSString` value if data sharing is enabled, otherwise `nil`.
 */
+ (NSString *)containingApplicationBundleIdentifierForDataSharing PF_WATCH_UNAVAILABLE PF_TV_UNAVAILABLE;

#if TARGET_OS_IOS

///--------------------------------------
#pragma mark - Configuring UI Settings
///--------------------------------------

/**
 Set whether to show offline messages when using a Parse view or view controller related classes.

 @param enabled Whether a `UIAlertView` should be shown when the device is offline
 and network access is required from a view or view controller.

 @deprecated This method has no effect.
 */
+ (void)offlineMessagesEnabled:(BOOL)enabled PARSE_DEPRECATED("This method is deprecated and has no effect.");

/**
 Set whether to show an error message when using a Parse view or view controller related classes
 and a Parse error was generated via a query.

 @param enabled Whether a `UIAlertView` should be shown when an error occurs.

 @deprecated This method has no effect.
 */
+ (void)errorMessagesEnabled:(BOOL)enabled PARSE_DEPRECATED("This method is deprecated and has no effect.");

#endif

///--------------------------------------
#pragma mark - Logging
///--------------------------------------

/**
 Sets the level of logging to display.

 By default:
 - If running inside an app that was downloaded from iOS App Store - it is set to `PFLogLevelNone`
 - All other cases - it is set to `PFLogLevelWarning`

 @param logLevel Log level to set.
 @see PFLogLevel
 */
+ (void)setLogLevel:(PFLogLevel)logLevel;

/**
 Log level that will be displayed.

 By default:

 - If running inside an app that was downloaded from iOS App Store - it is set to `PFLogLevelNone`
 - All other cases - it is set to `PFLogLevelWarning`

 @return A `PFLogLevel` value.
 @see PFLogLevel
 */
+ (PFLogLevel)logLevel;

@end

NS_ASSUME_NONNULL_END
