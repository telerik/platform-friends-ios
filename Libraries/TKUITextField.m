//
//  TKUITextField.m
//  TextBox_Demo
//
//  Created by Mehfuz Hossain on 4/11/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import "TKUITextField.h"
#import <QuartzCore/QuartzCore.h>

@interface TKUITextField()
{
    UITextField *textRect;
}


@property (nonatomic) BOOL keyboardIsShown;
@property (nonatomic) CGSize keyboardSize;
@property (nonatomic) BOOL hasScrollView;
@property (nonatomic) BOOL invalid;

@property (nonatomic) BOOL isToolBarCommand;

@property (nonatomic , strong) UIBarButtonItem *prevousBarButton;
@property (nonatomic , strong) UIBarButtonItem *nextBarButton;

@property (nonatomic, strong) NSMutableArray *textFields;

@end

@implementation TKUITextField

@synthesize required;
@synthesize scrollView;
@synthesize toolbar;
@synthesize keyboardIsShown;
@synthesize keyboardSize;
@synthesize invalid;
@synthesize isToolBarCommand;
@synthesize prevousBarButton;
@synthesize nextBarButton;


- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    
    if (self){
        [self setup];
    }
    
    return self;
}

- (void) awakeFromNib{
    [super awakeFromNib];
    [self setup];
}

- (void)setup
{
    self.delegate = self;
   
    [self setTintColor:[UIColor blackColor]];
    
    toolbar = [[UIToolbar alloc] init];
    toolbar.frame = CGRectMake(0, 0, self.window.frame.size.width, 44);
    // set style
    [toolbar setBarStyle:UIBarStyleBlackTranslucent];
    
    self.prevousBarButton = [[UIBarButtonItem alloc] initWithTitle:@"Previous" style:UIBarButtonItemStyleBordered target:self action:@selector(previousButtonIsClicked:)];
    self.nextBarButton = [[UIBarButtonItem alloc] initWithTitle:@"Next" style:UIBarButtonItemStyleBordered target:self action:@selector(nextButtonIsClicked:)];
    
    UIBarButtonItem *flexBarButton = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace target:nil action:nil];
    
    UIBarButtonItem *doneBarButton = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(doneButtonIsClicked:)];
    
    NSArray *barButtonItems = @[self.prevousBarButton, self.nextBarButton, flexBarButton, doneBarButton];
    
    toolbar.items = barButtonItems;
    
    self.textFields = [[NSMutableArray alloc]init];
    
    [self initTextFields];
}

- (void)initTextFields
{
    int index = 0;
    if ([self.textFields count] == 0){
        for(UIView *view in self.superview.subviews){
            if ([view isKindOfClass:[TKUITextField class]]){
                TKUITextField *textField = (TKUITextField*)view;
                textField.tag = index;
                [self.textFields addObject:textField];
                index++;
            }
        }
    }
}

- (void) doneButtonIsClicked:(id)sender{
    [self resignFirstResponder];
    isToolBarCommand = YES;
}

-(void) keyboardDidShow:(NSNotification *) notification {
    if (textRect == nil) return;
    if (keyboardIsShown) return;
    if (![textRect isKindOfClass:[TKUITextField class]]) return;
    
    NSDictionary* info = [notification userInfo];
    
    NSValue *aValue = [info objectForKey:UIKeyboardFrameBeginUserInfoKey];
    keyboardSize = [aValue CGRectValue].size;
    
    [self scrollToField];
    
    self.keyboardIsShown = YES;
    
}

-(void) keyboardWillHide:(NSNotification *) notification {
    
    NSTimeInterval duration = [[[notification userInfo] valueForKey:UIKeyboardAnimationDurationUserInfoKey] doubleValue];
    
    [UIView animateWithDuration:duration animations:^{
         if (!isToolBarCommand)
             [self.scrollView setContentOffset:CGPointMake(0, 0) animated:NO];
     }];
    
    keyboardIsShown = NO;
    
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}


- (void) nextButtonIsClicked:(id)sender{
    NSInteger tagIndex = self.tag;
    TKUITextField *textField =  [self.textFields objectAtIndex:++tagIndex];
    isToolBarCommand = YES;
    [self resignFirstResponder];
    [textField becomeFirstResponder];
}


- (void) previousButtonIsClicked:(id)sender{
    NSInteger tagIndex = self.tag;
    
    TKUITextField *textField =  [self.textFields objectAtIndex:--tagIndex];
    
    isToolBarCommand = YES;
    
    [textField becomeFirstResponder];
    [self resignFirstResponder];
}

- (void)setBarButtonNeedsDisplay:(NSInteger) index{
    prevousBarButton.enabled = index > 0;
    nextBarButton.enabled = index + 1 < [self.textFields count];
}

- (void)textFieldDidBeginEditing:(UITextField *)textField{
    
    textRect = textField;
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardDidShow:)
                                                 name:UIKeyboardDidShowNotification
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardWillHide:)
                                                 name:UIKeyboardWillHideNotification
                                               object:nil];
    
    [self setBarButtonNeedsDisplay:textField.tag];
    
    if ([self.superview.superview isKindOfClass:[UIScrollView class]] && self.scrollView == nil){
        self.scrollView = (UIScrollView*)self.superview.superview;
    }
    
    self.inputAccessoryView = toolbar;
    isToolBarCommand = NO;
}

- (void)textFieldDidEndEditing:(UITextField *)textField{
    [self validate];
    textRect = nil;
}

- (void)scrollToField{
    CGRect textFieldRect = self.superview.frame;
    textFieldRect.origin.y += textRect.frame.origin.y + textRect.frame.size.height;
    
    CGRect aRect = self.window.bounds;
    aRect.size.height -= keyboardSize.height + self.toolbar.frame.size.height;
   
    if (!CGRectContainsPoint(aRect, textFieldRect.origin) ) {
        CGPoint scrollPoint = CGPointMake(0.0, self.superview.frame.origin.y + textRect.frame.origin.y + textRect.frame.size.height - aRect.size.height);
        [scrollView setContentOffset:scrollPoint animated:YES];
    }
}

- (BOOL) validate{
    if (required && [self.text isEqualToString:@""]){
        self.backgroundColor = [UIColor colorWithRed:255 green:0 blue:0 alpha:0.5];
        return NO;
    }
    
    return YES;
}


@end
