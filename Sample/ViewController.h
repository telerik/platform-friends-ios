//
//  ViewController.h
//  EverliveSDK
//
//  Created by Mehfuz Hossain on 6/23/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DetailViewController.h"

@interface ViewController : UIViewController<UITableViewDataSource, UITableViewDelegate, DetailViewControllerDelegate>
@property (strong, nonatomic) IBOutlet UITableView *activitiesTableView;

@property UIActivityIndicatorView *activity;
@property (strong, nonatomic) IBOutlet UIScrollView *scrollView;

@end
