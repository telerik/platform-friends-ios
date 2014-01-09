//
//  ViewController.m
//  EverliveSDK
//
//  Created by Mehfuz Hossain on 6/23/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import "ViewController.h"
#import "Activity.h"
#import "UIColor+Custom.h"
#import "MBProgressHUD.h"
#import <QuartzCore/QuartzCore.h>
#import "NewActivityViewController.h"

@interface ViewController ()

@property (nonatomic, strong) NSMutableArray *activities;
@property (nonatomic, strong) MBProgressHUD *hud;
@property BOOL skipReload;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
   
    self.activities = [[NSMutableArray alloc]init];
    
    UIButton *addBarButton = [UIButton buttonWithType:UIButtonTypeInfoLight];
    
    UIImage *image = [UIImage imageNamed:@"icon-add.png"];
   
    [addBarButton setFrame:CGRectMake(0, 0, image.size.width, image.size.height)];
    
    [addBarButton setImage:image forState:UIControlStateNormal];
    [addBarButton addTarget:self action:@selector(addNewTodo:)
       forControlEvents:UIControlEventTouchUpInside];
    
    UIBarButtonItem *addButtonItem =[[UIBarButtonItem alloc] initWithCustomView:addBarButton];
  
    self.navigationItem.rightBarButtonItem= addButtonItem;
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Log out" style:UIBarButtonItemStyleBordered target:self action:@selector(logout:)];

    self.navigationItem.title = @"Activities";
    
    self.activitiesTableView.dataSource = self;
    self.activitiesTableView.delegate = self;
    self.activitiesTableView.backgroundColor = [UIColor clearColor];
    
}

- (void) viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    [[self navigationController] setNavigationBarHidden:NO animated:YES];
    
    if (self.skipReload)
        return;
    
    [self.activities removeAllObjects];
    [self.activitiesTableView reloadData];
    if ([[EVUser currentUser] isAuthenticated]){

        self.hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
        self.hud.labelText = @"Please wait";
        
        [Activity fetchAll:^(NSArray *result, NSError *error) {
            
            __block int completed = 1;
            
            for (int index = 0; index < [result count]; index++)
            {
                Activity *activity = [result objectAtIndex:index];
                
                [EVUser fetchUser:activity.userId block:^(EVUser *user, NSError *error) {
                    activity.user = user;
                    [EVFile fileWithName:[NSString stringWithFormat:@"%@.jpg", user.displayName] block:^(NSArray *files, NSError *error) {
                        EVFile *file = [files objectAtIndex:0];
                        activity.picture = file.data;
                        [self.activities addObject:activity];
                        
                        if (completed == [result count]){
                            [self.hud hide:YES];
                            
                            NSSortDescriptor *createdDateDescriptor = [[NSSortDescriptor alloc] initWithKey:@"createdAt" ascending:NO];
                            [self.activities sortUsingDescriptors:@[createdDateDescriptor]];
                            [self.activitiesTableView reloadData];
                        }
                        completed++;
                    }];
                }];
            }
           
        }];
    }
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    self.skipReload = NO;
}

- (void)addNewTodo:(id)sender
{
    [self performSegueWithIdentifier:@"NewActivity" sender:self];
}
- (void)logout:(id)sender
{
    [EVUser logOut];
    [self.navigationController popToRootViewControllerAnimated:YES];
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return tableView.rowHeight;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.activities count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSString *activityIdentifier = @"Activity";
    Activity *activity = [self.activities objectAtIndex:indexPath.item];
    
    UITableViewCell  * cell = [tableView dequeueReusableCellWithIdentifier:activityIdentifier];
    
    if (cell == nil){
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:activityIdentifier];
        cell.accessoryType = UITableViewCellAccessoryNone;
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        [cell setBackgroundColor:[UIColor clearColor]];
    }
    
    for (int index = 0; index < [cell.contentView.subviews count]; index++)
        [[[cell.contentView subviews]objectAtIndex:index] removeFromSuperview];
    
    CGRect rect =  [tableView rectForRowAtIndexPath:indexPath];
   
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, rect.size.width, 150)];
    
    view.backgroundColor = [UIColor whiteColor];
    
    
    UIImageView *pictureImageView = [[UIImageView alloc] initWithFrame:CGRectMake(15, 15, 50, 50)];
    
    
    if (activity.picture != nil){
        [pictureImageView setImage:[UIImage imageWithData:activity.picture]];
    }
    else{
        UIImage * image= [UIImage imageNamed:@"avatar.png"];
        [pictureImageView setImage:image];
    }
    
    pictureImageView.layer.cornerRadius = pictureImageView.frame.size.width /2;
    pictureImageView.layer.masksToBounds = YES;
    [view addSubview:pictureImageView];
    
    UIFont *font = [UIFont fontWithName:@"HelveticaNeue" size:15];
    
    UIView *titleView = [[UIView alloc]initWithFrame:CGRectMake(0, 0, view.frame.size.width, 50)];
    UILabel *titleLabel = [[UILabel alloc]initWithFrame:CGRectMake(70, 15, titleView.frame.size.width - 10, [@"x" sizeWithAttributes:@{NSFontAttributeName:font}].height)];
    
    [titleLabel setFont:[UIFont systemFontOfSize:17]];
    [titleLabel setTextColor:[UIColor colorWithRed:53/255.0 green:152/255.0 blue:219/255.0 alpha:1]];
    
    titleLabel.text = activity.user.displayName;
  
    [titleView addSubview:titleLabel];
    
    font = [UIFont fontWithName:@"HelveticaNeue" size:13];
    
    UILabel *dateLabel = [[UILabel alloc] initWithFrame:CGRectMake(rect.size.width - 100, titleLabel.frame.origin.y +2, 120, [@"x" sizeWithAttributes:@{NSFontAttributeName:font}].height)];
    
    [dateLabel setFont:font];
    
    dateLabel.textColor = [UIColor lightGrayColor];
    
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"MMM dd,yyyy"];
    [dateFormatter setTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:0]];
    
    dateLabel.text = [dateFormatter stringFromDate: activity.createdAt];
 
    [titleView addSubview:dateLabel];
    
   

    [view addSubview:titleView];
    
    UILabel *label = [[UILabel alloc]initWithFrame:CGRectMake(70, 15, view.frame.size.width - 70, 100)];
    
    font = [UIFont fontWithName:@"HelveticaNeue" size:14];
    
    [label setNumberOfLines:0];
    [label setFont:font];
    [label setTextColor:[UIColor colorWithRed:52/255.0 green:73/255.0 blue:94/255.0 alpha:1]];
    label.text = activity.text;
    
    [view addSubview:label];
    
    [view.layer setShadowColor:[UIColor blackColor].CGColor];
    [view.layer setShadowOpacity:0.8];
    [view.layer setShadowOffset:CGSizeMake(1.0, 1.0)];
    
    [cell.contentView addSubview:view];
    
    return cell;
}

- (void) tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [self performSegueWithIdentifier:@"DetailView" sender:self];
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([segue.identifier isEqualToString:@"DetailView"]){
        DetailViewController *detailViewControlelr =  [segue destinationViewController];
        
        detailViewControlelr.delegate = self;
        
        NSIndexPath *indexPath = self.activitiesTableView.indexPathForSelectedRow;
        Activity *activity = [self.activities objectAtIndex:indexPath.item];
        detailViewControlelr.activity = activity;
        self.skipReload = YES;
    }
}

- (void)postIsDeleted
{
    self.skipReload = NO;
}


@end
