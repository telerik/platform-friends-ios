	//
//  ADFSLoginViewController.m
//  EverliveSDK Sample
//
//  Created by Pavel Pavlov on 12/19/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import "ADFSLoginViewController.h"
#import <EverliveSDK/EverliveSDK.h>

@interface ADFSLoginViewController ()

@end

@implementation ADFSLoginViewController


- (void)viewDidLoad
{
    [super viewDidLoad];
	
    self.loginWithADFSButton.text = @"Login with Active Directory";
    self.loginWithADFSButton.delegate = self;
}

- (void) viewWillAppear:(BOOL)animated{
    [[self navigationController] setNavigationBarHidden:NO animated:YES];
}

- (void)buttonClicked:(id)sender
{
            if([_usernameTextField validate] && [_passwordTextField validate]){
                self.hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
                self.hud.labelText = @"Please wait";
    
                [EVUser loginWithAdfs:_usernameTextField.text password:_passwordTextField.text block:^(EVUser *user, NSError *error) {
                    [self loginUser:user error:error];
                }];
            }
    
}

- (void)loginUser:(EVUser*)user error:(NSError*)error
{
    [self.hud hide:YES];
    
    if (error == nil && [user isAuthenticated]){
        [self.navigationItem setTitle:@"Log out"];
        [self performSegueWithIdentifier:@"ShowActivities1" sender:self];
    }
    else{
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Login not successful" message:error.domain delegate:self cancelButtonTitle:nil otherButtonTitles:@"Ok", nil];
        [alert show];
    }
}
@end
