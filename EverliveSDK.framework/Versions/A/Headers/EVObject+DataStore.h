//
//  EVObject+DataStore.h
//  EverliveSDK
//
//  Created by Mehfuz Hossain on 7/19/13.
//  Copyright (c) 2013 Telerik Inc. All rights reserved.
//

#import "EVObject.h"
#import "EVConstants.h"

@interface EVObject (DataStore)

/*!
 Retrieves all the EVObject in background.
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
+ (void)fetchAll:(EVObjectFetchResultBlock)block;
/*!
 Retrieves all the EVObject in background.
 @param target The object to call selector on
 @param selector The selector to call. It should have the following signature: (void)requestCompletedWithResult:(NSArray*)result error:(NSError*)error. error will be nill on success.
 */
+ (void)fetchAll:(id)target selector:(SEL)selector;

/*!
 Saves the EVObject in background.
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
- (void)create:(EVObjectResultBlock)block;

/*!
 Saves a new EVObject in background.
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void)requestCompletedWithResult:(NSArray*)result error:(NSError*)error. error will be nill on success.
 */
- (void)create:(id) target selector:(SEL)selector;

/*!
 Updates the EVObject in background.
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
- (void)update:(EVObjectResultBlock)block;

/*!
 updates the EVObject in background.
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void)requestCompletedWithResult:(NSArray*)result error:(NSError*)error. error will be nill on success.
 */
- (void)update:(id) target selector:(SEL)selector;

/*!
 Removes the EVObject in background.
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
- (void)remove:(EVObjectResultBlock)block;

/*!
 Removes the EVObject in background.
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void)requestCompletedWithResult:(NSArray*)result error:(NSError*)error. error will be nill on success.
 */
- (void)remove:(id)target selector:(SEL)selector;


@end
