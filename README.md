
# Telerik Friends Sample App for iOS

<a id="top"></a>
* [Overview](#overview)
* [Screenshots](#screenshots)
* [Requirements](#requirements)
* [Configuration](#configuration)
* [Running the Sample](#running-the-sample)

# Overview

This repository contains the Telerik Friends app for iOS. It is a sample mobile app demonstrating how to integrate a wide range of Telerik Platform services into a native iOS mobile application.

The Telerik Friends sample app showcases these features and SDKs:

- [Cloud data](http://docs.telerik.com/platform/backend-services/ios/data/introduction) access (Telerik Backend Services)
- Working with [files](http://docs.telerik.com/platform/backend-services/ios/files/introduction) (Telerik Backend Services)
- User [registration](http://docs.telerik.com/platform/backend-services/ios/users/users-register) and [authentication](http://docs.telerik.com/platform/backend-services/ios/users/users-authenticate) (Telerik Backend Services)
- Authentication with [social login](http://docs.telerik.com/platform/backend-services/ios/users/social-login/introduction) providers (Facebook, Google, etc.) (Telerik Backend Services)
- Using custom user account fields (Telerik Backend Services)
- Basic [app analytics](http://docs.telerik.com/platform/analytics/getting-started/introduction) (Telerik Analytics)
- Tracking [feature use](http://docs.telerik.com/platform/analytics/client/reports/feature-use) (Telerik Analytics)

To implement all the features listed above, the sample app utilizes the following Telerik products and SDKs:

- [Telerik Backend Services iOS SDK](http://docs.telerik.com/platform/backend-services/ios/getting-started-ios-sdk)&mdash;to connect the app to Telerik Backend Services
- [Telerik Analytics iOS SDK](http://docs.telerik.com/platform/analytics/sdk/ios/)&mdash;to connect the app with Telerik Analytics

# Screenshots

Login Screen|Activity Stream|Activity Details
---|---|---
![Login Screen](https://raw.githubusercontent.com/telerik/platform-friends-ios/master/screenshots/ios-login-screen.png)|![Activities stream view](https://raw.githubusercontent.com/telerik/platform-friends-ios/master/screenshots/ios-activities-stream.png)|![Activity details view](https://raw.githubusercontent.com/telerik/platform-friends-ios/master/screenshots/ios-activity-details.png)

# Requirements

Before you begin, you need to ensure that you have the following:

- **An active Telerik Platform account**
Ensure that you can log in to a Telerik Platform account. This can be a free trial account. Depending on your license you may not be able to use all app features. For more information on what is included in the different editions, check out the pricing page. All features included in the sample app work during the free trial period.

- **A Compatible XCode version**  
XCode 5 or or later must be installed on your Mac.

# Configuration

The Friends sample app comes fully functional, but to see it in action you must link it to your own Telerik Platform account.

1. Log in to the Telerik Platform portal.
2. Create a new Hybrid or NativeScript app.<br>
	You will only use the backend of the app.
3. Click the **Data** tab and then click **Enable and populate with sample data**.<br>
	Sample content types with data required for the app to run is automatically created for you. The button also enables the **Users** service where user accounts for the app are precreated.
3. Click the **Settings** tab.
4. Take note of your **App ID**.

> If you happen to break the structure of the automatically generated Friends data, you can delete the app and start over.

## App ID for Telerik Platform

This is a unique string that links the sample mobile app to your Telerik Platform account where all the data is read from/saved. To set it in the app code:

1. Open the `EverliveSDKSample-Info.plist` file.
2. Find the `EverliveAPIKey` key and set its value to the App ID of your Telerik Platform app.

## (Optional) Project Key for Telerik Analytics

This is a unique string that links the sample mobile app to the Analytics part of your Telerik Platform app. If you do not set this the sample will still work, but no analytics data will be collected.
	
1. In the Telerik Platform portal, go to your app.
2. Click the **Analytics** tab and then click **Enable**.
3. Go to **Analytics > Settings > Options** and take note of your **Project Key**.
4. Open the `EverliveSDKSample-Info.plist` file.
5. Find the `analyticsProductID` key and set its value to the **Project Key** that you acquired earlier.

## (Optional) Facebook App ID

To demonstrate social login, we have preinitialized the sample to use a purpose-built Facebook app by Telerik. However, you still need to enable Facebook integration in the Telerik Platform portal:

1. In the Telerik Platform portal, go to your app.
3. Navigate to **Users > Authentication**.
4. Ensure that the **Facebook** box is checked.

> Note that if you intend to use the code for a production app you need to set up your own Facebook application and adjust the Facebook app ID as follows:
	
1. Open the `EverliveSDKSample-Info.plist` file.
2. Find the `FacebookAppID` key and set its value to your Facebook app ID.

## (Optional) Google Client ID

To demonstrate social login, we have preinitialized the sample to use a Google Client ID owned by Telerik. However, you still need to enable Google integration in the Telerik Platform portal:

1. In the Telerik Platform portal, go to your app.
3. Navigate to **Users > Authentication**.
4. Ensure that the **Google** box is checked.

> Note that if you intend to use the code for a production app you need to set up your own Google Client ID and adjust the code as follows:

1. Open the `EverliveSDKSample-Info.plist` file.
2. Find the `GoogleClientID` key and set its value to your Google Client ID.

## (Optional) Microsoft Account

To demonstrate social login, we have preinitialized the sample to use a  Microsoft Account Client ID owned by Telerik. However, you still need to enable Microsoft Account integration in the Telerik Platform portal:

1. In the Telerik Platform portal, go to your app.
3. Navigate to **Users > Authentication**.
4. Ensure that the **Windows Live** box is checked.

> Note that if you intend to use the code for a production app you need to set up your own Microsoft Account Client ID and adjust the code as follows:

1. Open the `EverliveSDKSample-Info.plist` file.
2. Find the `LiveIDClientID` key and set its value to your Microsoft Account app ID.

## HTTPS Connections

By default the Friends Sample is configured to use HTTP. If you want to switch to HTTPS, update the `UseHTTPS` setting in `EverliveSDKSample-Info.plist` to `true`.

# Running the Sample

Once the app is configured as described in the previous section, you can run it either on a real device or in the simulator from within Xcode.

> Ensure that the emulator or the device that you are using has Internet connectivity when running the sample.

