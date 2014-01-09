//
//  DetailViewController.h
//  EverliveSDK
//
//  Created by Mehfuz Hossain on 6/25/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TKShadowedView.h"
#import "Activity.h"


@protocol DetailViewControllerDelegate <NSObject>

@required
- (void)postIsDeleted;

@end

@interface DetailViewController : UIViewController<UIAlertViewDelegate>
@property (strong, nonatomic) IBOutlet UIImageView *pictureImageView;
@property (strong, nonatomic) IBOutlet UILabel *displayNameLabel;
@property (strong, nonatomic) IBOutlet UILabel *dateLabel;
@property (nonatomic, strong) Activity *activity;
@property (strong, nonatomic) IBOutlet UITextView *textView;

@property id<DetailViewControllerDelegate> delegate;

- (IBAction)deletePost:(id)sender;

@end
