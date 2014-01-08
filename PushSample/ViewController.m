//
//  ViewController.m
//  PushSample
//
//  Created by Mehfuz Hossain on 9/25/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import "ViewController.h"
#import "MBProgressHUD.h"

#define ENABLE_NOTIFICATION_TEXT @"Register"
#define DISABLE_NOTIFICATION_TEXT @"Disable Notifications"

@interface ViewController ()

@property (setter = registered:) BOOL isRegistered;
@property (nonatomic, strong) MBProgressHUD *hud;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.pushButton.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:@"login-pattern.png"]];
    self.pushButton.delegate = self;
    self.view.backgroundColor = [UIColor blackColor];
    self.pushButton.text = ENABLE_NOTIFICATION_TEXT;
    
    _hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    _hud.labelText = @"Please wait...";

    [_hud hide:YES];
}

- (void)buttonClicked:(id)sender
{
    if (!self.isRegistered){
        [_hud show:YES];
        
        NSDictionary *dictionary = [NSDictionary dictionaryWithObjectsAndKeys:@"Friends",@"appName", nil];
        
        [[Everlive sharedInstance]registerDeviceWithParameters:dictionary block:^(BOOL success, NSError *error) {
            [_hud hide:YES];
            [self.pushButton setText:DISABLE_NOTIFICATION_TEXT];
            [self.pushButton setNeedsDisplay];
            [self registered:YES];
        }];
    }
    else{
        UIAlertView *alerView = [[UIAlertView alloc]initWithTitle:Nil message:@"Are you sure you want to remove the device" delegate:self cancelButtonTitle:@"Cancel" otherButtonTitles:@"Ok", nil];
        [alerView show];
    }
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if (buttonIndex == 1){
        [_hud show:YES];
        [self registered:NO];
        [[Everlive sharedInstance]removeDevice:^(BOOL success, NSError *error) {
            [_hud hide:YES];
            self.pushButton.text = ENABLE_NOTIFICATION_TEXT;
            [self.pushButton setNeedsDisplay];
        }];
    }
}

@end
