---
title: iOS
slug: sample-friends-ios
meta_title: Friends Sample for iOS 
meta_description: Introduction to the Friends Sample App for iOS.
tags: friends, iOS, sample, platform, telerik, analytics, backend services, objectivec, objective-c
publish: true
ordinal: 2
---

This section is dedicated to the [Friends sample app](slug:sample-friends) for the **iOS** platform. You can download the source code project for this sample from [here](https://github.com/telerik/platform-friends-ios).

The same sample is also available for other platforms:

- [Android (native)]({{slug:sample-friends-android}})
- [Windows Phone (native)]({{slug:sample-friends-windows-phone}})
- [Hybrid]({{slug:sample-friends-hybrid}})
- [Web]({{slug:sample-friends-web}})

## Showcased features and SDKs

The Friends sample for iOS includes all the features described in the [introduction page](slug:sample-friends#showcased-features-sdks).

To implement all the features listed above, the sample app utilizes the following products and SDKs:

- {{telerik_backend_services}} iOS SDK - used to work with {{telerik_backend_services}}.
- {{telerik_analytics}} iOS SDK - used to work with {{telerik_analytics}}.

## Requirements

The following is a list of requirements for the sample app:

- **Active {{tap}} account**  
To use this sample app you must have an active {{tap}} account. Depending on your license you may not be able to use all features of the app. For more information on what is included in the different editions, please check out the pricing page for the respective product. All features included in the sample app will work in the free trial period.

- **Compatible XCode version**  
XCode 5 or  or later must be installed on your Mac.


## Configuring the sample app
The Friends sample app comes fully functional, but to see it in action you must link it to your own {{tap}} account.

What you need to set:

- **API key for {{telerik_backend_services}}**  
This links the sample mobile app to a project in {{telerik_backend_services}}. When you activate {{telerik_backend_services}} a Friends sample project is created for you automatically. It has necessary structure defined and some data pre-filled. You must use its API key.  
To set the API key go to the EverliveSDKSample-Info.plist file and set the EverliveAPIKey row.
> If you happen to break the structure of the automatically generated Friends sample project, you can delete it and a fresh instance will be created again for you automatically. Alternatively, you could create a new project and choose to start from a Friends template, instead of starting from a blank project.

- [optional] **API key for {{telerik_analytics}}**  
This step is optional, it links the sample mobile app to a {{telerik_analytics}} project in your account. If you do not set this the sample will still work, but no analytics data will collected.

- [optional] **Facebook app ID**  
The sample app allows users to register using their Facebook account. We've pre-initialized the sample to use a Facebook app created by Telerik for the purpose. If you want, you can set it to use your own Facebook application by adjusting the Facebook app ID.
TODO - where to set it

- [optional] **Google**  
The sample app allows users to register using their Google account. Please  replace the default setting in the EverliveSDKSample-Info.plist file.

- [optional] **Windows Live**  
The sample app allows users to register using their Live account. Please  replace the default setting in the EverliveSDKSample-Info.plist file.

By default the Friends Sample is configured to use HTTP. In case you wish to switch to HTTPS please update the 'UseHTTPS' setting in the EverliveSDKSample-Info.plist file to "YES".

## Running the sample app
Once the app is configured as described in the previous section, you can run it either on a real device or in the simulator from within XCode.

> Make sure the emulator or the device you use have working Internet connection when running the sample. Internet connection is necessary in order to connect to the cloud.
