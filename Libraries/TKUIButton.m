//
//  TKUIButton.m
//  EverliveSDK Sample
//
//  Created by Mehfuz Hossain on 7/30/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import "TKUIButton.h"
#import <QuartzCore/QuartzCore.h>


@interface TKUIButton()

@property (nonatomic, strong) UITapGestureRecognizer *tapGesture;

@end

@implementation TKUIButton

// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    for (UIView *subview in self.subviews)
        [subview removeFromSuperview];
    
    UIView *view = [[UIView alloc] initWithFrame: rect];
 
    UIImageView  *imageView = [[UIImageView alloc]initWithImage:self.icon];
    
 [imageView setFrame:CGRectMake((self.bounds.size.width/2) - imageView.frame.size.width/2,(self.bounds.size.height/2) -imageView.frame.size.height/2, imageView.frame.size.width, imageView.frame.size.height)];
    
    [view addSubview:imageView];
    
    UILabel *label = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, self.bounds.size.width, self.bounds.size.height)];
    
    label.textColor = [UIColor whiteColor];
    label.backgroundColor = [UIColor clearColor];
  
    label.textAlignment = NSTextAlignmentCenter;
    label.text = self.text;
    
    label.font = [UIFont fontWithName:@"HelveticaNeue" size:15];
    
    [view addSubview:label];
    
    self.layer.cornerRadius = 2;
    self.layer.masksToBounds = YES;
    
    
    [self addSubview:view];
    
}

-(void)awakeFromNib
{
    _tapGesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(buttonTapped:)];
    [self addGestureRecognizer:_tapGesture];
}

- (void)buttonTapped:(UITapGestureRecognizer*)gesture
{
    if (self.delegate) [self.delegate buttonClicked:self];
}

- (UIColor *)lighterColor:(UIColor*)color
{
    float h, s, b, a;
    if ([color getHue:&h saturation:&s brightness:&b alpha:&a])
        return [UIColor colorWithHue:h saturation:s brightness:b * 0.9 alpha:a];
    return nil;
}


@end
