//
//  Everlive.h
//  EverliveSDK
//
//  Created by Mehfuz Hossain on 6/23/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

/*!
 An Everlive framework object that is the local representation of the data stored in Everlive cloud.
 */
@interface EVObject : NSObject

@property (nonatomic, strong) NSString *id;
@property (nonatomic, strong) NSDate *createdAt;
@property (nonatomic, strong) NSDate *modifiedAt;
@property (nonatomic, strong) NSString *createdBy;
@property (nonatomic, strong) NSString *modifiedBy;

- (void)setWithResult:(NSDictionary *)result;
- (NSDictionary*)getEverlivePropertiesMapping;
- (NSArray*) getEverliveServerIgnoredProperties;
@end
