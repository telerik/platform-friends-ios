//
//  EVFile.h
//  EverliveSDK
//
//  Created by Mehfuz Hossain on 8/8/13.
//  Copyright (c) 2013 Telerik Inc. All rights reserved.
//

#import <EverliveSDK/EverliveSDK.h>

/*!
 An Everlive file object that is the local representation of the file stored in Everlive cloud.
 */
@interface EVFile : EVObject

@property (nonatomic, strong) NSString *filename;
@property (nonatomic, strong) NSString *contentType;
@property (nonatomic, strong) NSString *uri;
@property (nonatomic, strong) NSData *data;

/*!
 Returns the metadata information and the file data for the file with this id
 @param fileId The unique id for the file.
 @param block The block to execute. The block should have the following argument signature: (EVFile *file, NSError *error)
 */
+ (void)file:(id)fileId block:(EVFileResult)block;

/*!
 Returns the metadata information for the file with this id, including the file data
 @param fileId The unique id for the file.
 @param block The block to execute. The block should have the following argument signature: (EVFile *file, NSError *error)
 */
+(void)metadata:(id)fileId block:(EVFileResult)block;

/*!
 Returns the file metadata and the file data from everlive
 @param name The name of the file to retrieve.
 @param block The block to execute. The block should have the following argument signature: (EVFile *file, NSError *error)
 */
+ (void)fileWithName:(NSString*)name block:(EVObjectFetchResultBlock)block;

/*!
 Returns the file metadata from everlive
 @param name The name of the file to retrieve.
 @param block The block to execute. The block should have the following argument signature: (EVFile *file, NSError *error)
 */
+ (void)metadataWithName:(NSString*)name block:(EVObjectFetchResultBlock)block;

/*!
 Returns a new file instance.
 @param name The name of the file to retrieve.
 @param data The content of the file.
 @param contentType The content type of the file. If nil then it will try to resolve the content type based on byte representation (beta).
 */
+ (id)fileWithName:(NSString*)name data:(NSData*)data contentType:(NSString*)contentType;

/*!
 Saves the file to everlive.
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
- (void)save:(EVObjectResultBlock)block;

/*!
 Deletes the file from everlive. Must be authenticated to perform the operation.
 @param block The block to execute. The block should have the following argument signature: (EVUser *user, NSError *error)
 */
- (void)remove:(EVObjectResultBlock)block;

@end
