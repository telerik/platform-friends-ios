//
//  ADFSLoginViewController.h
//  EverliveSDK Sample
//
//  Created by Pavel Pavlov on 12/19/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TKUIButton.h"
#import "TKUITextField.h"
#import "MBProgressHUD.h"

@interface ADFSLoginViewController : UIViewController<TKUIButtonDelegate>
@property (strong, nonatomic) IBOutlet TKUIButton *loginWithADFSButton;
@property (strong, nonatomic) IBOutlet TKUITextField *usernameTextField;
@property (strong, nonatomic) IBOutlet TKUITextField *passwordTextField;
@property (nonatomic, strong) MBProgressHUD *hud;

@end
