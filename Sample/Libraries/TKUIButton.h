//
//  TKUIButton.h
//  EverliveSDK Sample
//
//  Created by Mehfuz Hossain on 7/30/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIColor+Custom.h"

@protocol TKUIButtonDelegate <NSObject>

@required
-(void) buttonClicked:(id)sender;

@end

@interface TKUIButton : UIView<UIGestureRecognizerDelegate>


@property (nonatomic, strong) UIImage *icon;
@property (nonatomic, strong) UIColor *tintColor;
@property (nonatomic, strong) NSString *text;

@property (nonatomic, assign) id<TKUIButtonDelegate> delegate;


@end
