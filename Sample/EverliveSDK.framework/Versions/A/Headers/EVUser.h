//
//  EVUser.h
//  EverliveSDKSample
//
//  Created by Mehfuz Hossain on 7/15/13.
//  Copyright (c) 2013 Telerik AD. All rights reserved.
//

#import "Everlive.h"
#import "EVObject.h"

/*!
 An Everlive user object that is the local representation of the user persisted to the Everlive cloud.
 */
@interface EVUser : EVObject<NSCoding>

@property (nonatomic, strong) NSString* accessToken;
@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, strong) NSString *displayName;
@property (nonatomic, strong) NSString *email;

/*!
 Returns all users from everlive.
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
+ (void)allUsers:(EVObjectFetchResultBlock)block;


/*!
 Returns the specific user.
 @param userId The id against which the user will be retrieved. 
 @param block The block to execute. The block should have the following argument signature: (EVUser *user, NSError *error)
 */
+ (void)fetchUser:(id)userId block:(EVUserResultBlock)block;


/*!
 Returns the user for email.
 @param email The email to get the user for.
 @param block The block to execute. The block should have the following argument signature: (EVUser *user, NSError *error)
 */
+ (void)fetchUserWithEmail:(NSString*)email block:(EVUserResultBlock)block;

/*!
 Returns information about the currently logged in user
 @param accessToken The access token that should be passed for authentication of the request.
 @param block The block to execute. The block should have the following argument signature: (EVUser *user, NSError *error)
 */
+ (void)fetchWithAccessToken:(NSString*)accessToken block:(EVUserResultBlock)block;

/*!
 Sets a new password for the user with the specified username by using the secret question and secret answer
 @param username The username identifying the user
 @param secretQuestionId The secret question ID of the user
 @param secretAnswer The answer to the secret question
 @param newPassword The new password to set
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
+ (void)setNewPassword:(NSString*)username withSecretQuestionId:(NSString*)secretQuestionId andSecretAnswer:(NSString*)secretAnswer newPassword:(NSString*)newPassword block:(EVObjectResultBlock)block;

/*!
 Sets a new password for the user with the specified reset code
 @param resetCode The reset code
 @param newPassword The new password to set
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
+(void)setNewPasswordWithResetCode:(NSString*)resetCode newPassword:(NSString*)newPassword block:(EVObjectResultBlock)block;

/*!
 Resends the verification email for the user with the specified ID
 @param userId The id of the user
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
+(void)resendVerificationEmailWithUserId:(id)userId block:(EVObjectResultBlock)block;

/*!
 Resends the verification email for the user with the specified username
 @param username The username for which to send verification email
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
+(void)resendVerificationEmailWithUsername:(NSString*)username block:(EVObjectResultBlock)block;

/*!
 Return the current logged in user from disk.
 */
+ (EVUser*)currentUser;

/*!
 Changes the password of the specified user.
 @param username The username of the user.
 @param oldPassword The old password of the user.
 @param newPassword The new password of the user.
 @param block The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
+(void)changePassword:(NSString*)username oldPassword:(NSString*)oldPassword newPassword:(NSString*)newPassword block:(EVObjectResultBlock)block;

/*!
 Makes an asynchronous request to log in a user with specified credentials.
 @param username The username of the user.
 @param password The password of the user.
 @param block The block to execute. The block should have the following argument signature: (EVUser *user, NSError *error)
 */
+ (void)loginWithUsername:(NSString*)username password:(NSString*)password block:(EVUserResultBlock)block;

/*!
 Makes an asynchronous request to log in a user with facebook access token.
 @param accessToken The access token obtained from Facebook.
 @param block The block to execute. The block should have the following argument signature: (EVUser *user, NSError *error)
 */
+ (void)loginWithFacebook:(NSString*) accessToken block:(EVUserResultBlock)block;


/*!
 Makes an asynchrounous request to log in a user with live id access token
 @param accessToken The access token obtained from LiveId
 @param block The block to execute. The block should have the following argument signature: (EVUser *user, NSError *error)
 */
+ (void)loginWithLiveId:(NSString*) accessToken block:(EVUserResultBlock)block;

/*!
 Makes an asynchrounous request to log in a user with google access token
 @param accessToken The access token obtained from LiveId
 @param block The block to execute. The block should have the following argument signature: (EVUser *user, NSError *error)
 */
+ (void)loginWithGoogle:(NSString*) accessToken block:(EVUserResultBlock)block;

/*!
 Links the everlive account with a Facebook account
 @param userId The Id of the user
 @param accessToken The access token from the external provider
 @param block The block to execute
 */
+(void)linkFacebookAccount:(NSString*)userId accessToken:(NSString*)accessToken block:(EVObjectResultBlock)block;

/*!
Links the everlive account with an ADFS account
@param userId The Id of the user
@param accessToken The access token from the external provider
@param block The block to execute
*/
+ (void)linkAdfsAccount:(NSString *)userId accessToken:(NSString *)accessToken block:(EVObjectResultBlock)block;

/*!
 Links the everlive account with a LiveID account
 @param userId The Id of the user
 @param accessToken The access token from the external provider
 @param block The block to execute
 */
+(void)linkLiveIdAccount:(NSString*)userId accessToken:(NSString*)accessToken block:(EVObjectResultBlock)block;

/*!
 Links the everlive account with a Google account
 @param userId The Id of the user
 @param accessToken The access token from the external provider
 @param block The block to execute
 */
+(void)linkGoogleAccount:(NSString*)userId accessToken:(NSString*)accessToken block:(EVObjectResultBlock)block;

/*!
 Unlinks the everlive user account and the Facebook account
 @param userId The user id
 @param block The block to execute
 */
+(void) unlinkFacebookAccount:(NSString*)userId block:(EVObjectResultBlock)block;

/*!
 Unlinks the everlive user account and the Adfs account
 @param userId The user id
 @param block The block to execute
 */
+ (void)unlinkAdfsAccount:(NSString *)userId block:(EVObjectResultBlock)block;

/*!
 Unlinks the everlive user account and the LiveID account
 @param userId The user id
 @param block The block to execute
 */
+(void) unlinkLiveIdAccount:(NSString*)userId block:(EVObjectResultBlock)block;

/*!
 Unlinks the everlive user account and the Google account
 @param userId The user id
 @param block The block to execute
 */
+(void) unlinkGoogleAccount:(NSString*)userId block:(EVObjectResultBlock)block;

/*!
 Makes an asynchrounous request to log in a user with an ADFS access token
 @param accessToken The access token obtained from the Active Directory
 @param block The block to execute. The block should have the following argument signature: (EVUser *user, NSError *error)
 */
+(void)loginWithAdfs:(NSString *)accessToken block:(EVUserResultBlock)block;

/*!
 Makes an asynchrounous request to log in a user with ADFS with username and password.
 @param username The username for the Active Directory
 @param password The password for the Active Directory
 @param block The block to execute. The block should have the following argument signature: (EVUser *user, NSError *error)
 */
+(void)loginWithAdfs:(NSString*)username password:(NSString*) password block:(EVUserResultBlock)block;

/*!
 Logs out the currenlty logged in user on disk.
 */
+ (void)logOut;

/*!
 Signs up the user. Make sure that username and password are set. This will also enforce that the username isn't already taken.
 @param block The block to execute. The block should have the following argument signature: (EVUser *user, NSError *error)
 */
- (void)signUp:(EVUserResultBlock) block;

/*!
 Removes the user from everlive. Must be authenticated to remove a user.
 @param block The block to execute. The block should have the following argument signature: (EVUser *user, NSError *error)
 */
- (void)remove:(EVObjectResultBlock)block;

/*!
 Checks if the current user is logged in.
 */
- (BOOL)isAuthenticated;

@end
