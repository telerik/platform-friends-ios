//
//  NSUserDefaults+Custom.h
//  EverliveSDK
//
//  Created by Mehfuz Hossain on 8/5/13.
//  Copyright (c) 2013 Telerik Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSUserDefaults (Custom)

- (void)setCustomObject:(id) obj forKey:(NSString*) key;
- (id) customObjectForKey:(NSString*) key;

@end
