//
//  EVGeoPoint.h
//  EverliveSDK
//
//  Created by Dimitar Dimitrov on 9/16/13.
//  Copyright (c) 2013 Telerik Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EVGeoPoint : NSObject

@property (nonatomic) double Latitude;
@property (nonatomic) double Longitude;

-(NSMutableDictionary*)getSerializedObject;
@end
