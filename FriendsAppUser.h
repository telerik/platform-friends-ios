//
//  FriendsAppUser.h
//  EverliveSDK Sample
//
//  Created by Pavel Pavlov on 12/20/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import <EverliveSDK/EverliveSDK.h>

@interface FriendsAppUser : EVUser
@property (nonatomic, strong) NSString *about;
@property (nonatomic, strong) NSDate *birthDate;
@property (nonatomic, strong) NSString *gender;
@end
