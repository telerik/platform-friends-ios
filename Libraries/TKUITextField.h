//
//  TKUITextField.h
//  TextBox_Demo
//
//  Created by Mehfuz Hossain on 4/11/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TKUITextField;

@protocol TKUITextFieldDelegate <NSObject>

@required
- (TKUITextField*) textFieldAtIndex:(int)index;
- (int) numberOfTextFields;

@end

@interface TKUITextField : UITextField<UITextFieldDelegate>

@property (nonatomic) BOOL required;
@property (nonatomic, strong) UIToolbar *toolbar;
@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) UIView *parentView;

@property (nonatomic, assign) id<TKUITextFieldDelegate> textFieldDelegate;

- (BOOL) validate;
- (void)initTextFields;

@end
