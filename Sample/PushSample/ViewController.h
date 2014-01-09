//
//  ViewController.h
//  PushSample
//
//  Created by Mehfuz Hossain on 9/25/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TKUIButton.h"

@interface ViewController : UIViewController<TKUIButtonDelegate, UIAlertViewDelegate>

@property (strong, nonatomic) IBOutlet TKUIButton *pushButton;

@end
