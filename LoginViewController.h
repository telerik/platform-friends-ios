//
//  LoginViewController.h
//  EverliveSDK
//
//  Created by Mehfuz Hossain on 7/5/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import "TKUITextField.h"
#import <EverliveSDK/EverliveSDK.h>
#import <FacebookSDK/FacebookSDK.h>
#import "MBProgressHUD.h"
#import "TKUIButton.h"
#import <LiveSDK/LiveConnectClient.h>
#import <GooglePlus/GooglePlus.h>
#import <EQATECAnalyticsMonitoriOS/EQATECAnalyticsMonitor.h>

@interface LoginViewController : UIViewController<TKUIButtonDelegate, UIAlertViewDelegate, LiveAuthDelegate, GPPSignInDelegate>

@property (nonatomic, strong) MBProgressHUD *hud;
@property (strong, nonatomic) LiveConnectClient *liveClient;


@property (strong, nonatomic) IBOutlet UILabel *usernameLabel;
@property (strong, nonatomic) IBOutlet TKUITextField *usernameTextField;
@property (strong, nonatomic) IBOutlet TKUITextField *passwordTextField;


@property (strong, nonatomic) IBOutlet UILabel *passwordLabel;

@property (strong, nonatomic) IBOutlet TKUIButton *googleLoginButton;
@property (strong, nonatomic) IBOutlet TKUIButton *liveIDLoginButton;
@property (strong, nonatomic) IBOutlet TKUIButton *adfsLoginButton;
@property (strong, nonatomic) IBOutlet TKUIButton *signUpButton;
@property (strong, nonatomic) IBOutlet TKUIButton *facebookLoginButton;
@property (strong, nonatomic) IBOutlet TKUIButton *loginButton;


@property (strong, nonatomic) IBOutlet UIScrollView *scrollView;
@property (strong, nonatomic) IBOutlet UIView *footerView;
@property (weak, nonatomic) IBOutlet UIView *groupedView;

@property (strong, nonatomic) EQATECAnalyticsMonitor *monitor;

@end
