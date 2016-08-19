/**
 * Copyright (c) 2015-present, Parse, LLC.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <CSBM/PFConstants.h>
#import <CSBM/BEObject.h>

/**
 This category lists all methods of `BEObject` that are deprecated and will be removed in the near future.
 */
@interface BEObject (Deprecated)

///--------------------------------------
#pragma mark - Saving Objects
///--------------------------------------

/**
 Saves the `BEObject` asynchronously and calls the given callback.

 @param target The object to call selector on.
 @param selector The selector to call.
 It should have the following signature: `(void)callbackWithResult:(NSNumber *)result error:(NSError *)error`.
 `error` will be `nil` on success and set if there was an error.
 `[result boolValue]` will tell you whether the call succeeded or not.

 @deprecated Please use `BEObject.-saveInBackgroundWithBlock:` instead.
 */
- (void)saveInBackgroundWithTarget:(nullable id)target
                          selector:(nullable SEL)selector PARSE_DEPRECATED("Please use `BEObject.-saveInBackgroundWithBlock:` instead.");

///--------------------------------------
#pragma mark - Saving Many Objects
///--------------------------------------

/**
 Saves a collection of objects all at once *asynchronously* and calls a callback when done.

 @param objects The array of objects to save.
 @param target The object to call selector on.
 @param selector The selector to call.
 It should have the following signature: `(void)callbackWithResult:(NSNumber *)number error:(NSError *)error`.
 `error` will be `nil` on success and set if there was an error.
 `[result boolValue]` will tell you whether the call succeeded or not.

 @deprecated Please use `BEObject.+saveAllInBackground:block:` instead.
 */
+ (void)saveAllInBackground:(nullable NSArray<BEObject *> *)objects
                     target:(nullable id)target
                   selector:(nullable SEL)selector PARSE_DEPRECATED("Please use `BEObject.+saveAllInBackground:block:` instead.");

///--------------------------------------
#pragma mark - Getting an Object
///--------------------------------------

/**
 *Asynchronously* refreshes the `BEObject` and calls the given callback.

 @param target The target on which the selector will be called.
 @param selector The selector to call.
 It should have the following signature: `(void)callbackWithResult:(BEObject *)refreshedObject error:(NSError *)error`.
 `error` will be `nil` on success and set if there was an error.
 `refreshedObject` will be the `BEObject` with the refreshed data.

 @deprecated Please use `BEObject.-fetchInBackgroundWithBlock:` instead.
 */
- (void)refreshInBackgroundWithTarget:(nullable id)target
                             selector:(nullable SEL)selector PARSE_DEPRECATED("Please use `BEObject.-fetchInBackgroundWithBlock:` instead.");

/**
 Fetches the `BEObject *asynchronously* and calls the given callback.

 @param target The target on which the selector will be called.
 @param selector The selector to call.
 It should have the following signature: `(void)callbackWithResult:(BEObject *)refreshedObject error:(NSError *)error`.
 `error` will be `nil` on success and set if there was an error.
 `refreshedObject` will be the `BEObject` with the refreshed data.

 @deprecated Please use `BEObject.-fetchInBackgroundWithBlock:` instead.
 */
- (void)fetchInBackgroundWithTarget:(nullable id)target
                           selector:(nullable SEL)selector PARSE_DEPRECATED("Please use `BEObject.-fetchInBackgroundWithBlock:` instead.");

/**
 Fetches the BEObject's data asynchronously if `dataAvailable` is `NO`, then calls the callback.

 @param target The target on which the selector will be called.
 @param selector The selector to call.
 It should have the following signature: `(void)callbackWithResult:(BEObject *)fetchedObject error:(NSError *)error`.
 `error` will be `nil` on success and set if there was an error.
 `refreshedObject` will be the `BEObject` with the refreshed data.

 @deprecated Please use `BEObject.-fetchIfNeededInBackgroundWithBlock:` instead.
 */
- (void)fetchIfNeededInBackgroundWithTarget:(nullable id)target
                                   selector:(nullable SEL)selector PARSE_DEPRECATED("Please use `BEObject.-fetchIfNeededInBackgroundWithBlock:` instead.");

///--------------------------------------
#pragma mark - Getting Many Objects
///--------------------------------------

/**
 Fetches all of the `BEObject` objects with the current data from the server *asynchronously*
 and calls the given callback.

 @param objects The list of objects to fetch.
 @param target The target on which the selector will be called.
 @param selector The selector to call.
 It should have the following signature: `(void)callbackWithResult:(NSArray *)fetchedObjects error:(NSError *)error`.
 `error` will be `nil` on success and set if there was an error.
 `fetchedObjects` will the array of `BEObject` objects that were fetched.

 @deprecated Please use `BEObject.+fetchAllInBackground:block:` instead.
 */
+ (void)fetchAllInBackground:(nullable NSArray<BEObject *> *)objects
                      target:(nullable id)target
                    selector:(nullable SEL)selector PARSE_DEPRECATED("Please use `BEObject.+fetchAllInBackground:block:` instead.");

/**
 Fetches all of the BEObjects with the current data from the server *asynchronously*
 and calls the given callback.

 @param objects The list of objects to fetch.
 @param target The target on which the selector will be called.
 @param selector The selector to call.
 It should have the following signature: `(void)callbackWithResult:(NSArray *)fetchedObjects error:(NSError *)error`.
 `error` will be `nil` on success and set if there was an error.
 `fetchedObjects` will the array of `BEObject` objects that were fetched.

 @deprecated Please use `BEObject.+fetchAllIfNeededInBackground:block:` instead.
 */
+ (void)fetchAllIfNeededInBackground:(nullable NSArray<BEObject *> *)objects
                              target:(nullable id)target
                            selector:(nullable SEL)selector PARSE_DEPRECATED("Please use `BEObject.+fetchAllIfNeededInBackground:block:` instead.");

///--------------------------------------
#pragma mark - Deleting an Object
///--------------------------------------

/**
 Deletes the `BEObject` *asynchronously* and calls the given callback.

 @param target The object to call selector on.
 @param selector The selector to call.
 It should have the following signature: `(void)callbackWithResult:(NSNumber *)result error:(NSError *)error`.
 `error` will be `nil` on success and set if there was an error.
 `[result boolValue]` will tell you whether the call succeeded or not.

 @deprecated Please use `BEObject.-deleteInBackgroundWithBlock:` instead.
 */
- (void)deleteInBackgroundWithTarget:(nullable id)target
                            selector:(nullable SEL)selector PARSE_DEPRECATED("Please use `BEObject.-deleteInBackgroundWithBlock:` instead.");

///--------------------------------------
#pragma mark - Deleting Many Objects
///--------------------------------------

/**
 Deletes a collection of objects all at once *asynchronously* and calls a callback when done.

 @param objects The array of objects to delete.
 @param target The object to call selector on.
 @param selector The selector to call.
 It should have the following signature: `(void)callbackWithResult:(NSNumber *)number error:(NSError *)error`.
 `error` will be `nil` on success and set if there was an error.
 `[result boolValue]` will tell you whether the call succeeded or not.

 @deprecated Please use `BEObject.+deleteAllInBackground:block:` instead.
 */
+ (void)deleteAllInBackground:(nullable NSArray<BEObject *> *)objects
                       target:(nullable id)target
                     selector:(nullable SEL)selector PARSE_DEPRECATED("Please use `BEObject.+deleteAllInBackground:block:` instead.");

@end