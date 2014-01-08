//
//  DetailViewController.m
//  EverliveSDK
//
//  Created by Mehfuz Hossain on 6/25/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import "DetailViewController.h"
#import "MBProgressHUD.h"

@interface DetailViewController ()

@property (nonatomic, strong) MBProgressHUD *hud;

@end

@implementation DetailViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.navigationItem.title = @"Activity";
    self.dateLabel.textColor = [UIColor lightGrayColor];
    
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"MM.dd.yyyy"];
    [dateFormatter setTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:0]];
    self.dateLabel.text = [dateFormatter stringFromDate: [NSDate date]];

    self.displayNameLabel.text = self.activity.user.displayName;
   
    self.textView.text = self.activity.text;
    
    if (self.activity.picture != nil){
        [self.pictureImageView setImage:[UIImage imageWithData:self.activity.picture]];
    }
    self.pictureImageView.layer.cornerRadius = self.pictureImageView.frame.size.width /2;
    self.pictureImageView.layer.masksToBounds = YES;
}

- (IBAction)deletePost:(id)sender
{
    UIAlertView *alertView = [[UIAlertView alloc]initWithTitle:nil message:NSLocalizedString(@"CONFIRM_DELETE_POST", nil) delegate:self cancelButtonTitle:@"Cancel" otherButtonTitles:@"Confirm", nil];
    
    [alertView show];
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger) buttonIndex
{
    if (buttonIndex == 1){
        self.hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
        self.hud.labelText = @"Deleting...";

        [self.activity remove:^(BOOL success, NSError *error) {
            [self.hud hide:YES];
            [self.delegate postIsDeleted];
            [self.navigationController popViewControllerAnimated:YES];
        }];
    }
}
@end
