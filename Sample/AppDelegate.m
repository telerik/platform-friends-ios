//
//  AppDelegate.m
//  EverliveSDK
//
//  Created by Mehfuz Hossain on 6/23/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import "AppDelegate.h"
#import <EverliveSDK/EverliveSDK.h>
#import <FacebookSDK/FacebookSDK.h>
#import "UIColor+Custom.h"
#import <GooglePlus/GooglePlus.h>


@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [self.window setTintColor:[UIColor whiteColor]];
    [[UINavigationBar appearance] setBackgroundImage:[UIImage new]
                                       forBarMetrics:UIBarMetricsDefault];
    [[UINavigationBar appearance] setShadowImage:[[UIImage alloc] init]];
    [[UINavigationBar appearance] setBackgroundColor:UIColorFromRGB(0x34495E)];
    
    [[UINavigationBar appearance] setTitleTextAttributes:@{NSForegroundColorAttributeName : [UIColor whiteColor]}];
    [[UIApplication sharedApplication]setStatusBarStyle:UIStatusBarStyleLightContent];
    
    bool useHttps = [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"UseHTTPS"] boolValue];
    
    if(useHttps){
        [Everlive setServerUrl:@"https://api.everlive.com/v1"];
    }
    
    return YES;
}
							
- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    
    return [GPPURLHandler handleURL:url
                  sourceApplication:sourceApplication
                         annotation:annotation];
}

@end
