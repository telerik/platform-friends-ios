//
//  EVDevice.h
//  EverliveSDK
//
//  Created by Mehfuz Hossain on 9/23/13.
//  Copyright (c) 2013 Telerik Inc. All rights reserved.
//

#import "EverliveSDK.h"

@interface EVDevice : EVObject

+ (void)fetchWithHardwareId:(NSString*)uuid block:(EVObjectFetchResultBlock)block;
+ (void)registerWithTokenData:(NSData*)tokenData hardwareId:(NSString*)hardwareId parameters:(NSDictionary*)parameters block:(EVObjectResultBlock)block;
+ (void)removeWithHardwareId:(NSString*)hardwareId block:(EVObjectResultBlock)block;

@end
