//
//  AddTodoViewController.m
//  EverliveSDK
//
//  Created by Mehfuz Hossain on 6/25/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import "NewActivityViewController.h"
#import "UIColor+Custom.h"
#import "Activity.h"
#import "MBProgressHUD.h"

@interface NewActivityViewController()
{
    NSString *placeHolderText;
    CGSize keyboardSize;
}

@property (nonatomic, strong) MBProgressHUD *hud;

@end

@implementation NewActivityViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.activityTextArea.delegate = self;
    self.displayNameLabel.text = [EVUser currentUser].displayName;
    self.navigationItem.title = @"New Activity";
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Post" style:UIBarButtonItemStyleBordered target:self action:@selector(newActivity:)];
}

- (void)newActivity:(id)sender
{
    Activity *activity = [[Activity alloc]init];
    
    if (![self.activityTextArea.text isEqualToString:@""]){
        
        activity.text = self.activityTextArea.text;
        activity.userId = [EVUser currentUser].id;
        
        self.hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
        self.hud.labelText = @"Please wait";

        [activity create:^(BOOL success, NSError *error) {
            [self.hud hide:YES];
            if (success){
                [self.navigationController popViewControllerAnimated:YES];
            }
        }];
    }
}

-(BOOL)textViewShouldBeginEditing:(UITextView *)textView{
  
    self.placeHolderLabel.hidden = true;
    
    return YES;
}

@end
