//
//  BEQueryCollectionViewController.h
//  CSBMUI
//
//  Created by Loc Nguyen on 6/26/16.
//  Copyright © 2016 Loc Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <CSBM/PFConstants.h>
#import <CSBMUI/CSBMUIConstants.h>
@class BFTask<__covariant BFGenericType>;
@class BECollectionViewCell;
@class BEObject;
@class BEQuery;

@interface BEQueryCollectionViewController : UICollectionViewController <UICollectionViewDelegateFlowLayout>
/**
 The class name of the `PFObject` this collection will use as a datasource.
 */
@property (nullable, nonatomic, copy) IBInspectable NSString *parseClassName;

/**
 Whether the collection should use the default loading view. Default - `YES`.
 */
@property (nonatomic, assign) IBInspectable BOOL loadingViewEnabled;

/**
 Whether the collection should use the built-in pull-to-refresh feature. Default - `YES`.
 */
@property (nonatomic, assign) IBInspectable BOOL pullToRefreshEnabled;

/**
 Whether the collection should use the built-in pagination feature. Default - `YES`.
 */
@property (nonatomic, assign) IBInspectable BOOL paginationEnabled;

/**
 The number of objects to show per page. Default - `25`.
 */
@property (nonatomic, assign) IBInspectable NSUInteger objectsPerPage;

/**
 Whether the collection is actively loading new data from the server.
 */
@property (nonatomic, assign, getter=isLoading) BOOL loading;

///--------------------------------------
/// @name Creating a PFQueryCollectionViewController
///--------------------------------------

/**
 Initializes a view controller with a `UICollectionViewFlowLayout` and a class name
 of `PFObject` that will be associated with this collection.
 
 @param className The class name of the instances of `PFObject` that this table will display.
 
 @return An initialized `PFQueryCollectionViewController` object or `nil` if the object couldn't be created.
 */
- (instancetype)initWithClassName:(nullable NSString *)className;

/**
 Initializes a view controller with a class name of `PFObject` that will be associated with this collection.
 
 @param layout    Layout for collection view to use.
 @param className The class name of the instances of `PFObject` that this table will display.
 
 @return An initialized `PFQueryCollectionViewController` object or `nil` if the object couldn't be created.
 */
- (instancetype)initWithCollectionViewLayout:(UICollectionViewLayout *)layout
                                   className:(nullable NSString *)className NS_DESIGNATED_INITIALIZER;

///--------------------------------------
/// @name Responding to Events
///--------------------------------------

/**
 Called when objects will be loaded from Parse. If you override this method, you must
 call [super objectsWillLoad] in your implementation.
 */
- (void)objectsWillLoad NS_REQUIRES_SUPER;

/**
 Called when objects have loaded from Parse. If you override this method, you must
 call [super objectsDidLoad:] in your implementation.
 @param error The Parse error from running the PFQuery, if there was any.
 */
- (void)objectsDidLoad:(nullable NSError *)error NS_REQUIRES_SUPER;

///--------------------------------------
/// @name Accessing Results
///--------------------------------------

/**
 The array of instances of `PFObject` that is used as a data source.
 */
@property (nonatomic, copy, readonly) NSArray<__kindof BEObject *> *objects;

/**
 Returns an object at a particular indexPath.
 
 The default impementation returns the object at `indexPath.item`.
 If you want to return objects in a different indexPath order, like for sections, override this method.
 
 @param indexPath An instance of `NSIndexPath`.
 
 @return The object at the specified indexPath.
 */
- (nullable BEObject *)objectAtIndexPath:(nullable NSIndexPath *)indexPath;

/**
 Removes an object at the specified index path, animated.
 */
- (void)removeObjectAtIndexPath:(nullable NSIndexPath *)indexPath;

/**
 Removes all objects at the specified index paths, animated.
 */
- (void)removeObjectsAtIndexPaths:(nullable NSArray<NSIndexPath *> *)indexes;

///--------------------------------------
/// @name Loading Data
///--------------------------------------

/**
 Clears the collection view and loads the first page of objects.
 
 @return An awaitable task that completes when the reload succeeds
 */
- (BFTask<NSArray<__kindof BEObject *> *> *)loadObjects;

/**
 Loads the objects of the `PFObject.parseClassName` at the specified page and appends it to the
 objects already loaded and refreshes the collection.
 
 @param page  The page of objects to load.
 @param clear Whether to clear the collection view after receiving the objects.
 
 @return An awaitable task that completes when the reload succeeds
 */
- (BFTask<NSArray<__kindof BEObject *> *> *)loadObjects:(NSInteger)page clear:(BOOL)clear;

/**
 Loads the next page of objects, appends to table, and refreshes.
 */
- (void)loadNextPage;

/**
 Clears the collection view of all objects.
 */
- (void)clear;

///--------------------------------------
/// @name Querying
///--------------------------------------

/**
 Override to construct your own custom `PFQuery` to get the objects.
 
 @return An instance of `PFQuery` that `-loadObjects` method will use to the objects for this collection.
 */
- (BEQuery *)queryForCollection;

///--------------------------------------
/// @name Data Source Methods
///--------------------------------------

/**
 Override this method to customize each cell given a `PFObject` that is loaded.
 
 @warning The cell should inherit from `PFCollectionViewCell` which is a subclass of `UICollectionViewCell`.
 
 @param collectionView The collection view object associated with this controller.
 @param indexPath      The indexPath of the cell.
 @param object         The `PFObject` that is associated with the cell.
 
 @return The cell that represents this object.
 */
- (nullable BECollectionViewCell *)collectionView:(UICollectionView *)collectionView
                           cellForItemAtIndexPath:(NSIndexPath *)indexPath
                                           object:(nullable BEObject *)object;

/**
 Override this method to customize the view that allows the user to load the
 next page when pagination is turned on.
 
 @param collectionView The collection view object associated with this controller.
 
 @return The view that allows the user to paginate.
 */
- (nullable UICollectionReusableView *)collectionViewReusableViewForNextPageAction:(UICollectionView *)collectionView;
@end
