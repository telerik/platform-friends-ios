//
//  SignUpViewController.h
//  EverliveSDK Sample
//
//  Created by Mehfuz Hossain on 8/7/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TKUIButton.h"
#import "TKUITextField.h"
#import "MBProgressHUD.h"
#import "DateViewController.h"

@interface SignUpViewController : UIViewController<TKUIButtonDelegate, UITextFieldDelegate>
@property (strong, nonatomic) IBOutlet TKUIButton *registerButton;
@property (strong, nonatomic) IBOutlet TKUITextField *nameTextField;
@property (strong, nonatomic) IBOutlet TKUITextField *usernameTextField;
@property (strong, nonatomic) IBOutlet TKUITextField *passwordTextField;
@property (strong, nonatomic) IBOutlet TKUITextField *emailTextField;
@property (strong, nonatomic) IBOutlet TKUITextField *birthDateTextField;
@property (strong, nonatomic) IBOutlet TKUITextField *aboutTextField;
@property (strong, nonatomic) DateViewController *dateController;
@property (nonatomic, strong) MBProgressHUD *hud;
@property (strong, nonatomic) IBOutlet UISegmentedControl *genderSegmentedControl;


@end
