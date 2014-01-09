//
//  TKGrayView.m
//  EverliveSDK Sample
//
//  Created by Mehfuz Hossain on 10/24/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import "TKGrayView.h"
#import "UIColor+Custom.h"

@implementation TKGrayView

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        [self setBackgroundColor:[UIColor clearColor]];
    }
    return self;
}

- (void)layoutSublayersOfLayer:(CALayer *)layer
{
    CALayer *backgroundLayer = [CALayer layer];
    
    [backgroundLayer setFrame:CGRectMake(0, 0, self.frame.size.width, self.frame.size.height)];
    [backgroundLayer setBackgroundColor:UIColorFromRGB(0xF0F0F0).CGColor];
    
    [layer addSublayer:backgroundLayer];
    
    CALayer *rightBorder = [CALayer layer];
    
    rightBorder.frame = CGRectMake(backgroundLayer.frame.size.width - 1, 0, 1, self.frame.size.height);
    
    rightBorder.backgroundColor = UIColorFromRGB(0xe0e0e0).CGColor;
    
    [layer addSublayer:rightBorder];
    
    for(UIView *view in self.subviews){
        [self bringSubviewToFront:view];
    }
}



@end
