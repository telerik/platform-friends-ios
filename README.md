---
title: Telerik Friends Sample App for iOS
slug: sample-backend-services-friends-ios
position: 1
publish: true
page_title: Telerik Friends Sample App for iOS | Telerik Platform
description: 
tags: Sample App, Application, iOS, Objective-C, iPhone, iPad, BaaS, mBaaS, Social, Analytics, Social Login
---

# Friends Sample App for iOS

* [Overview](#overview)
* [Requirements](#requirements)
* [Configuration](#configuration)
* [Running the Sample](#running-the-sample)

## Overview

This repository contains the Telerik Friends app for iOS. It is a sample mobile app demonstrating how to integrate a large gamut of Telerik Platform services into a native iOS mobile application.

The Telerik Friends sample app showcases these features and SDKs:

- Cloud data access (Telerik Backend Services)
- Working with files (Telerik Backend Services)
- User registration and authentication (Telerik Backend Services)
- Authentication with social login providers (Facebook, Google, etc.) (Telerik Backend Services)
- Using custom user account fields (Telerik Backend Services)
- Basic app analytics (Telerik Analytics)
- Tracking feature usage (Telerik Analytics)

To implement all the features listed above, the sample app utilizes the following Telerik products and SDKs:

- Telerik Backend Services - this is where all data, files, and user accounts are stored in the cloud
- Telerik Backend Services iOS SDK - to connect the app to Telerik Backend Services
- Telerik Analytics - used to store analytics data in the cloud
- Telerik Analytics iOS SDK - to connect the app with Telerik Analytics

## Requirements

Before you begin, you need to ensure that you have the following:

- **An active Telerik Platform account**
Ensure that you can log in to a Telerik Platform account. This can be a free trial account. Depending on your license you may not be able to use all app features. For more information on what is included in the different editions, check out the pricing page. All features included in the sample app work during the free trial period.

- **Compatible XCode version**  
XCode 5 or or later must be installed on your Mac.

## Configuration

The Friends sample app comes fully functional, but to see it in action you must link it to your own Telerik Platform account.

What you need to set:

### API Key for Telerik Backend Services

This is a unique string that links the sample mobile app to a project in Telerik Backend Services where all the data is read from/saved. When creating the project, you must base it on the Friends sample Backend Services project that has all the necessary data prepopulated.

You must use this project's API key. To set it in the app:

1. Open the `EverliveSDKSample-Info.plist` file.
2. Find the `EverliveAPIKey` key and set its value to the API Key of your Friends Backend Services project.

> If you happen to break the structure of the automatically generated Friends sample project, you can delete it and a fresh instance will be created again for you automatically. Alternatively, you could create a new project and choose to start from a Friends template, instead of starting from a blank project.

### (Optional) Project Key for Telerik Analytics

This is a unique string that links the sample mobile app to a Telerik Analytics project in your account. If you do not set this the sample will still work, but no analytics data will be collected.
	
1. Open the `EverliveSDKSample-Info.plist` file.
2. Find the `analyticsProductID` key and set its value to the Project Key of your Friends Analytics project.

### (Optional) Facebook App ID
To demonstrate social login, we've pre-initialized the sample to use a purpose-built Facebook app by Telerik. However, you still need to enable Facebook integration in the Telerik Platform portal:

1. Go to your app.
2. Click the Backend Services project that you are using.
3. Navigate to **Users > Authentication**.
4. Ensure that the Facebook box is checked.

> Note that if you intend to use the code for a production app you need to set up your own Facebook application and adjust the Facebook app ID as follows:
	
1. Open the `EverliveSDKSample-Info.plist` file.
2. Find the `FacebookAppID` key and set its value to your Facebook app ID.

### (Optional) Google Client ID

To demonstrate social login, we've pre-initialized the sample to use a Google Client ID owned by Telerik. However, you still need to enable Google integration in the Telerik Platform portal:

1. Go to your app.
2. Click the Backend Services project that you are using.
3. Navigate to **Users > Authentication**.
4. Ensure that the Google box is checked.

> Note that if you intend to use the code for a production app you need to set up your own Google Client ID and adjust the code as follows:

1. Open the `EverliveSDKSample-Info.plist` file.
2. Find the `GoogleClientID` key and set its value to your Google Client ID.

### (Optional) Microsoft Account

To demonstrate social login, we've pre-initialized the sample to use a  Microsoft Account Client ID owned by Telerik. However, you still need to enable Microsoft Account integration in the Telerik Platform portal:

1. Go to your app.
2. Click the Backend Services project that you are using.
3. Navigate to **Users > Authentication**.
4. Click the Windows Live check box.

> Note that if you intend to use the code for a production app you need to set up your own Microsoft Account Client ID and adjust the code as follows:

1. Open the `EverliveSDKSample-Info.plist` file.
2. Find the `LiveIDClientID` key and set its value to your Microsoft Account app ID.

### HTTPS Connections

By default the Friends Sample is configured to use HTTP. If you want to switch to HTTPS, update the `UseHTTPS` setting in `EverliveSDKSample-Info.plist` to `true`.

## Running the Sample

Once the app is configured as described in the previous section, you can run it either on a real device or in the simulator from within Xcode.

> Ensure that the emulator or the device that you are using has Internet connectivity when running the sample.

## Screenshots
???











   





