//
//  EVConstants.h
//  EverliveSDKSample
//
//  Created by Mehfuz Hossain on 7/15/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//


#import <Foundation/Foundation.h>

@class EVUser;
@class EVResponse;
@class EVFile;

typedef void (^EVResultBlock)(EVResponse *response, NSError *error);

typedef void (^EVObjectFetchResultBlock)(NSArray *result, NSError *error);
typedef void (^EVUserResultBlock)(EVUser *user, NSError *error);
typedef void (^EVObjectResultBlock)(BOOL success, NSError *error);
typedef void (^EVScalarResultBlock)(NSUInteger result, NSError *error);
typedef void (^EVFileResult)(EVFile *result, NSError *error);

extern NSString* const kEverliveServer;
extern NSString* const kEverliveAppId;
extern NSString* const kEverliveMasterKey;
NSString* const kAdfsSoapMessageTemplate;

