
//
//  NewActivityViewController.h
//  EverliveSDK
//
//  Created by Mehfuz Hossain on 6/25/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TKUITextField.h"

@interface NewActivityViewController : UIViewController<UITextViewDelegate>
@property (strong, nonatomic) IBOutlet UILabel *displayNameLabel;
@property (strong, nonatomic) IBOutlet UITextView *activityTextArea;

@property (strong, nonatomic) IBOutlet UILabel *placeHolderLabel;

@end
