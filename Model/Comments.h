//
//  Comments.h
//  EverliveSDK Sample
//
//  Created by Mehfuz Hossain on 7/30/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import <EverliveSDK/EverliveSDK.h>

@interface Comments : EVObject

@property (nonatomic, strong) NSString *comment;
@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSString *activityId;

@end
