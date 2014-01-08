//
//  UIColor+Custom.h
//  EverliveSDK Sample
//
//  Created by Mehfuz Hossain on 7/31/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import <UIKit/UIKit.h>

#define UIColorFromRGB(rgbValue) [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

@interface UIColor (Custom)

@end
