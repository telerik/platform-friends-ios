//
//  EVResponse.h
//  EverliveSDK
//
//  Created by Mehfuz Hossain on 6/24/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EVResponse : NSObject

@property id result;
@property NSData *rawData;

+ (id)initWithData:(NSData*)data;
- (id)resultWithKindOfClass:(Class)class;
- (NSNumber*)scalarResult;

@end
