//
//  Activities.h
//  EverliveSDK Sample
//
//  Created by Mehfuz Hossain on 7/30/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import <EverliveSDK/EverliveSDK.h>

@interface Activity : EVObject

@property (nonatomic, strong) NSString *text;
@property (nonatomic, strong) NSData *picture;
@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) EVUser *user;

@end
