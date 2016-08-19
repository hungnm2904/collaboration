//
//  BEQueryTableViewController.h
//  CSBMUI
//
//  Created by Loc Nguyen on 6/26/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CSBM/PFConstants.h>
#import <CSBMUI/CSBMUIConstants.h>
@class BFTask<__covariant BFGenericType>;
@class BEObject;
@class BEQuery;
@class BETableViewCell;

@interface BEQueryTableViewController : UITableViewController <UITableViewDataSource, UITableViewDelegate>
///--------------------------------------
/// @name Creating a PFQueryTableViewController
///--------------------------------------

/**
 Initializes with a class name of the `PFObject` that will be associated with this table.
 
 @param style The UITableViewStyle for the table
 @param className The class name of the instances of `PFObject` that this table will display.
 
 @return An initialized `PFQueryTableViewController` object or `nil` if the object couldn't be created.
 */
- (instancetype)initWithStyle:(UITableViewStyle)style
                    className:(nullable NSString *)className NS_DESIGNATED_INITIALIZER;

/**
 Initializes with a class name of the PFObjects that will be associated with this table.
 
 @param className The class name of the instances of `PFObject` that this table will display.
 
 @return An initialized `PFQueryTableViewController` object or `nil` if the object couldn't be created.
 */
- (instancetype)initWithClassName:(nullable NSString *)className;

///--------------------------------------
/// @name Configuring Behavior
///--------------------------------------

/**
 The class name of the `PFObject` this table will use as a datasource.
 */
@property (nullable, nonatomic, copy) IBInspectable NSString *parseClassName;

/**
 The key to use to display for the cell text label.
 
 This won't apply if you override `-tableView:cellForRowAtIndexPath:object:`
 */
@property (nullable, nonatomic, copy) IBInspectable NSString *textKey;

/**
 The key to use to display for the cell image view.
 
 This won't apply if you override `-tableView:cellForRowAtIndexPath:object:`
 */
@property (nullable, nonatomic, copy) IBInspectable NSString *imageKey;

/**
 The image to use as a placeholder for the cell images.
 
 This won't apply if you override `-tableView:cellForRowAtIndexPath:object:`
 */
@property (nullable, nonatomic, strong) IBInspectable UIImage *placeholderImage;

/**
 Whether the table should use the default loading view. Default - `YES`.
 */
@property (nonatomic, assign) IBInspectable BOOL loadingViewEnabled;

/**
 Whether the table should use the built-in pull-to-refresh feature. Default - `YES`.
 */
@property (nonatomic, assign) IBInspectable BOOL pullToRefreshEnabled;

/**
 Whether the table should use the built-in pagination feature. Default - `YES`.
 */
@property (nonatomic, assign) IBInspectable BOOL paginationEnabled;

/**
 The number of objects to show per page. Default - `25`.
 */
@property (nonatomic, assign) IBInspectable NSUInteger objectsPerPage;

/**
 Whether the table is actively loading new data from the server.
 */
@property (nonatomic, assign, getter=isLoading) BOOL loading;

///--------------------------------------
/// @name Responding to Events
///--------------------------------------

/**
 Called when objects will loaded from Parse. If you override this method, you must
 call [super objectsWillLoad] in your implementation.
 */
- (void)objectsWillLoad;

/**
 Called when objects have loaded from Parse. If you override this method, you must
 call [super objectsDidLoad:] in your implementation.
 @param error The Parse error from running the PFQuery, if there was any.
 */
- (void)objectsDidLoad:(nullable NSError *)error;

///--------------------------------------
/// @name Accessing Results
///--------------------------------------

/**
 The array of instances of `PFObject` that is used as a data source.
 */
@property (nullable, nonatomic, copy, readonly) NSArray<__kindof BEObject *> *objects;

/**
 Returns an object at a particular indexPath.
 
 The default impementation returns the object at `indexPath.row`.
 If you want to return objects in a different indexPath order, like for sections, override this method.
 
 @param indexPath The indexPath.
 
 @return The object at the specified index
 */
- (nullable BEObject *)objectAtIndexPath:(nullable NSIndexPath *)indexPath;

/**
 Removes an object at the specified index path, animated.
 */
- (void)removeObjectAtIndexPath:(nullable NSIndexPath *)indexPath;

/**
 Removes an object at the specified index path, with or without animation.
 */
- (void)removeObjectAtIndexPath:(nullable NSIndexPath *)indexPath animated:(BOOL)animated;

/**
 Removes all objects at the specified index paths, animated.
 */
- (void)removeObjectsAtIndexPaths:(nullable NSArray<NSIndexPath *> *)indexPaths;

/**
 Removes all objects at the specified index paths, with or without animation.
 */
- (void)removeObjectsAtIndexPaths:(nullable NSArray<NSIndexPath *> *)indexPaths animated:(BOOL)animated;

/**
 Clears the table of all objects.
 */
- (void)clear;

/**
 Clears the table and loads the first page of objects.
 
 @return An awaitable task that completes when the reload succeeds
 */
- (BFTask<NSArray<__kindof BEObject *> *> *)loadObjects;

/**
 Loads the objects of the className at the specified page and appends it to the
 objects already loaded and refreshes the table.
 
 @param page The page of objects to load.
 @param clear Whether to clear the table after receiving the objects
 
 @return An awaitable task that completes when the reload succeeds
 */
- (BFTask<NSArray<__kindof BEObject *> *> *)loadObjects:(NSInteger)page clear:(BOOL)clear;

/**
 Loads the next page of objects, appends to table, and refreshes.
 */
- (void)loadNextPage;

///--------------------------------------
/// @name Querying
///--------------------------------------

/**
 Override to construct your own custom PFQuery to get the objects.
 @result PFQuery that loadObjects will use to the objects for this table.
 */
- (BEQuery *)queryForTable;

///--------------------------------------
/// @name Data Source Methods
///--------------------------------------

/**
 Override this method to customize each cell given a PFObject that is loaded.
 
 If you don't override this method, it will use a default style cell and display either
 the first data key from the object, or it will display the key as specified with `textKey`, `imageKey`.
 
 @warning The cell should inherit from `PFTableViewCell` which is a subclass of `UITableViewCell`.
 
 @param tableView The table view object associated with this controller.
 @param indexPath The indexPath of the cell.
 @param object The PFObject that is associated with the cell.
 
 @return The cell that represents this object.
 */
- (nullable BETableViewCell *)tableView:(UITableView *)tableView
                  cellForRowAtIndexPath:(NSIndexPath *)indexPath
                                 object:(nullable BEObject *)object;

/**
 Override this method to customize the cell that allows the user to load the
 next page when pagination is turned on.
 
 @param tableView The table view object associated with this controller.
 @param indexPath The indexPath of the cell.
 
 @return The cell that allows the user to paginate.
 */
- (nullable BETableViewCell *)tableView:(UITableView *)tableView cellForNextPageAtIndexPath:(NSIndexPath *)indexPath;
@end
