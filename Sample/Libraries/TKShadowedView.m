//
//  TKShadowedView.m
//  EverliveSDK Sample
//
//  Created by Mehfuz Hossain on 8/6/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import "TKShadowedView.h"
#import <QuartzCore/QuartzCore.h>

@implementation TKShadowedView

- (void)awakeFromNib
{
    [super awakeFromNib];
    [self.layer setShadowColor:[UIColor blackColor].CGColor];
    [self.layer setShadowOpacity:0.8];
    [self.layer setShadowOffset:CGSizeMake(1.0, 1.0)];
}

@end
