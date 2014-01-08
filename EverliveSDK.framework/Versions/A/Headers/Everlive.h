//
//  Everlive.h
//  EverliveSDKSample
//
//  Created by Mehfuz Hossain on 7/15/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EVConstants.h"

/*!
 An Everlive entry point framework object that bootstraps the local representation of the Everlive cloud based on appllicaiton key either from info.plist file or the key set by user explicitly.
 */
@interface Everlive : NSObject

@property (strong, nonatomic) NSString *appKey;
@property (strong, nonatomic) NSString *masterKey;
@property (strong, nonatomic) NSString *apiServerUrl;

/*!
 Returns the shared instance of your application.
 */
+ (id)sharedInstance;

/*
 Sets the device token required to send push notification to a registered device.
 */
+ (void)setDeviceToken:(NSData*)deviceToken;

/*!
 Sets the application key for your applicaiton.
 @param appKey The application key for your Everlive application.
 */
+ (void)setApplicationKey:(NSString*)appKey;

/*!
 Sets the API server URL.
 @param url the API server URL.
 */
+ (void)setServerUrl:(NSString*)url;

/*!
 Registers the device in Everlive cloud to receive push notification.
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
- (void)registerDevice:(EVObjectResultBlock)block;

/*!
 Registers the device in Everlive cloud to receive push notification
 @param parameters The additional parameters can be used to send notiticaiton to a device based on filter values.
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
- (void)registerDeviceWithParameters:(NSDictionary*)parameters block:(EVObjectResultBlock)block;

/*!
 Removes the device from Everlive cloud.
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
- (void)removeDevice:(EVObjectResultBlock)block;

/*!
 Handles push notification message sent from Everlive application.
 @param notification The dictionary contains the notification details.
 */
+ (void)handlePush:(NSDictionary*)notification;

@end
