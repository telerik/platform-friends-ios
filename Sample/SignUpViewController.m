//
//  SignUpViewController.m
//  EverliveSDK Sample
//
//  Created by Mehfuz Hossain on 8/7/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import "SignUpViewController.h"
#import <EverliveSDK/EverliveSDK.h>
#import "FriendsAppUser.h"

@interface SignUpViewController ()

@property (nonatomic, strong) NSArray *items;

@end

@implementation SignUpViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
  
    self.registerButton.text = @"Register";
    self.navigationItem.title = @"Sign Up";
    self.registerButton.delegate = self;
    self.birthDateTextField.delegate = self;
}

- (void) viewWillAppear:(BOOL)animated{
    [[self navigationController] setNavigationBarHidden:NO animated:YES];
    if(self.dateController && self.dateController.datePicker){
        NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
        [dateFormatter setDateStyle:NSDateFormatterMediumStyle];
        self.birthDateTextField.text = [dateFormatter stringFromDate:self.dateController.datePicker.date];
    }
}

- (void)buttonClicked:(id)sender
{
    if ([sender isEqual:self.registerButton]){
        self.hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    self.hud.labelText = @"Please wait";
    //We inherit EVUser in order to add some additional fields such as birth date, about and gender.
    FriendsAppUser *newUser = [[FriendsAppUser alloc]init];
        
        [newUser setUsername:_usernameTextField.text];
        [newUser setPassword:_passwordTextField.text];
        [newUser setDisplayName:_nameTextField.text];
        [newUser setEmail:_emailTextField.text];
        [newUser setAbout:self.aboutTextField.text];
        if(self.genderSegmentedControl.selectedSegmentIndex!= -1){
            [newUser setGender: [self.genderSegmentedControl titleForSegmentAtIndex:self.genderSegmentedControl.selectedSegmentIndex]];
        }
        [newUser setBirthDate:self.dateController.datePicker.date];
       
        [newUser signUp:^(EVUser *user, NSError *error) {
            if (error == nil){
               [self.hud hide:YES];
                [EVUser loginWithUsername:user.username password:_passwordTextField.text block:^(EVUser *user, NSError *error) {
                    [self performSegueWithIdentifier:@"ShowActivities" sender:self];
                }];
            }
            else{
                [self.hud hide:YES];
                UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Registration Failed" message:error.domain delegate:self cancelButtonTitle:nil otherButtonTitles:@"Ok", nil];
                [alert show];
            }
        }];
    }
}

//Preventing direct text input of birth date. Using date input instead.
- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField{
    if(textField == self.birthDateTextField){
        [self performSegueWithIdentifier:@"dateSegue" sender:self];
        return NO;
    }
    
    return YES;
}


-(void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    self.dateController = [segue destinationViewController];
}


@end
