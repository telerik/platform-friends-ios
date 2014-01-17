
The **Friends Demo App** is a native iOS application providing some sample code illustrating how to achieve common tasks using the **native Everlive iOS SDK**. 
### Demonstrated features
By running the Friends sample app you may see the following Everlive features in action:

- simple login
- social login (Google, Facebook, Live ID , Active Directory)
- registering new users
- basic CREATE, RETRIEVE, UPDATE and DELETE operations
- working with different data types such as strings, numbers, dates, images etc.
- working with files.

### Quick start
- Download the ZIP and open the  EverliveSDK Sample.xcodeproj inXcode.
- Set  the **EverliveAPIKey** value in the **EverliveSDKSample-Info.plist** file. The value should match the API key of the Friends Sample application created by default in your Everlive account.
- Build and run the application. In case you do not have registered users yet you may do it from within the app.

### Social Authentication
For your convenience the .plist file  is pre-configured with profile settings for the following  OAuth providers:

- FaceBook
- Google
- LiveID.

***In a real case scenario you would wish to work with Google, Facebook or LiveID account of yours. Please replace  the demo  settings in the .plist file with your account settings.***

### HTTPS:

By default the Friends Sample is configured to use HTTP. In case you wish to switch to HTTPS please update the **UseHTTPS** setting in the .plist file to "YES".

###Analytics:

The Friends application contains some sample code demonstrating how to track your features usages features.
In the Friends sample app for illustrative purposes  the usage of the social login buttons (Facebook, Google, LiveID, ADFS) is being tracked. To be able to monitor and analyse the usage of these features from within your Telerik account please be sure to update **analyticsProductID** setting with your analytics product ID. 

###Using the application:
The initial screen offers you several alternatives to login:

- Regular login: Just  enter a valid username and password  and tap Login.
- Login With External authentication providers: Tapping on an icon ( Facebook , Google, LiveID, ADFS ) will lead you to a login screen for the relevant authentication provider. 

After successful login you will be redirected to a screen with list of Activities where you may perform basic CRUD operations.
