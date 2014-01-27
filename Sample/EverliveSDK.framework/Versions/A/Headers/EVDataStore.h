//
//  EVStore.h
//  EverliveSDK
//
//  Created by Mehfuz Hossain on 7/19/13.
//  Copyright (c) 2013 Telerik Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EverliveSDK.h"

/*!
 An Everlive framework object that is the local abstraction of the store in Everlive cloud. 
 */
@interface EVDataStore : NSObject

@property (readonly, nonatomic) NSString* appKey;

/*! 
 Returns the shared instance of the local data store.
*/
+ (id)sharedInstance;

/*!
 Retrieves the EVObject with the specified id in background.
 @param aClass The EVObject type to retreive.
 @param uniqueId The id of the item
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
- (void)fetch:(Class)aClass uniqueId:(NSString*)uniqueId block:(EVObjectFetchResultBlock)block;

/*!
 Retrieves the EVObject with the specified id in background
 @param aClass The EVObject type to retrieve
 @param uniqueId The id of the item
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void)requestCompletedWithResult:(NSArray*)result error:(NSError*)error. error will be nill on success.
 */
- (void)fetch:(Class)aClass uniqueId:(NSString*)uniqueId target:(id)target selector:(SEL)selector;

/*!
 Retrieves all the EVObject in background.
 @param aClass The EVObject type to retreive.
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
- (void)fetchAll:(Class)aClass block:(EVObjectFetchResultBlock)block;

/*!
 Retrieves all the EVObject in background.
 @param aClass The EVObject type to retreive.
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void)requestCompletedWithResult:(NSArray*)result error:(NSError*)error. error will be nill on success.
 */
- (void)fetchAll:(Class)aClass target:(id)target selector:(SEL)selector;

/*!
 Creates a new EVObject in background.
 @param object The object to be created.
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
- (void)create:(id)object block:(EVObjectResultBlock)block;

/*!
 Saves a new EVObject in background.
 @param object The object instance to be created in everlive.
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void)requestCompletedWithResult:(id)result error:(NSError*)error. error will be nill on success.
 */
- (void)create:(id) object target:(id) target selector:(SEL)selector;

/*!
 updates the EVObject in background.
 @param object The object instance to be updated in everlive.
 @param object The object instance to be updated in everlive.
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
- (void)update:(id)object block:(EVObjectResultBlock)block;

/*!
 updates the EVObject in background.
 @param object The object instance to be updated in everlive.
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void)requestCompletedWithResult:(BOOL)success error:(NSError*)error. error will be nill on success.
 */
- (void)update:(id)object target:(id) target selector:(SEL)selector;

/*!
 updates the EVObject in background.
 @param object The object instance to be updated in everlive.
 @param predicate The filers to be applied
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
- (void)update:(id)object withPredicate:(NSPredicate*)predicate block:(EVObjectResultBlock)block;


/*!
 Removes the EVObject in background.
 @param object The object to be deleted.
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
- (void)remove:(id)object block:(EVObjectResultBlock)block;

/*!
 Removes the EVObject in background.
 @param object The object instance to be removed from everlive.
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void)requestCompletedWithResult:(BOOL)success error:(NSError*)error. error will be nill on success.
 */
- (void)remove:(id)object target:(id)target selector:(SEL)selector;

/*!
 Removes the EVObject in background.
 @param aClass The EVObject type.
 @param predicate The filers to be applied.
 @param block The block to execute. The block should have the following argument signature:(void)requestCompletedWithResult(BOOL success, NSError *error)
 */
- (void)remove:(Class)aClass withPredicate:(NSPredicate*)predicate block:(EVObjectResultBlock)block;

/*!
 Retrieves an array of objects that meet the criteria specified by a given fetch request.
 @param request A fetch request that specifies the search criteria for the fetch.
 @param block The block to execute. The block should have the following argument signature: (NSArray *result, NSError *error)
 */
-(void)executeFetchRequest:(EVFetchRequest*)request block:(EVObjectFetchResultBlock) block;

/*!
 Retrieves an array of objects that meet the criteria specified by a given fetch request.
 @param request A fetch request that specifies the search criteria for the fetch.
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void)requestCompletedWithResult:(NSArray*)result error:(NSError*)error. error will be nill on success. */
-(void)executeFetchRequest:(EVFetchRequest*)request target:(id)target selector:(SEL)selector;

/*!
 Retrieves the count of objects that meet the criteria specified by a given fetch request.
 @param request A fetch request that specifies the search criteria for the fetch.
 @param block The block to execute. The block should have the following argument signature: (NSUInteger result, NSError *error)
 */
-(void)countForFetchRequest:(EVFetchRequest*)request block:(EVScalarResultBlock) block;

/*!
 Retrieves the count of objects that meet the criteria specified by a given fetch request.
 @param request A fetch request that specifies the search criteria for the fetch.
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void)requestCompletedWithResult:(NSUInteger)result error:(NSError*)error. error will be nill on success. */
-(void)countForFetchRequest:(EVFetchRequest*)request target:(id)target selector:(SEL)selector;

@end
