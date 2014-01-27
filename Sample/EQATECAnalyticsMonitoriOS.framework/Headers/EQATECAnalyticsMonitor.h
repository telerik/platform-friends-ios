/////////////////////////////////////////////////////////////////////////////////
//
//                     P R O P R I E T A R Y   R I G H T S
//
//           COPYRIGHT (C) EQATEC A/S - DENMARK - WWW.EQATEC.COM
//                             ALL RIGHTS RESERVED
//
//          THIS SOFTWARE MODULE REMAINS THE PROPERTY OF EQATEC A/S.
//          THE SOFTWARE MUST NOT BE DISCLOSED, SPLIT, OR MERGED IN ANY
//          FORM WITHOUT PRIOR APPROVAL BY EQATEC A/S IN WRITING.
//
//          THIS SOURCE CODE AND ALL RESULTING INTERMEDIATE FILES
//          ARE CONFIDENTIAL AND PROPRIETARY TRADE SECRETS OF EQATEC A/S.
//
//          THE SOURCE CODE CONTAINED WITHIN THIS FILE AND ALL RELATED
//          FILES OR ANY PORTION OF ITS CONTENTS SHALL AT NO TIME BE
//          COPIED, TRANSFERRED, SOLD, DISTRIBUTED, OR OTHERWISE MADE
//          AVAILABLE TO OTHER INDIVIDUALS WITHOUT EXPRESS WRITTEN CONSENT
//          AND PERMISSION FROM EQATEC A/S.
//
//          CONSULT THE END USER LICENSE AGREEMENT FOR INFORMATION ON
//          ADDITIONAL RESTRICTIONS AND RIGHTS.
//
///////////////////////////////////////////////////////////////////////////////////

#import <Foundation/Foundation.h>

#define EQATEC_ANALYTICS_MONITOR_VERSION "3.2.60"

// forward declarations
@protocol EQATECLogAnalyticsMonitor;
@protocol EQATECStorage;
@class EQATECAnalyticsMonitor;
@class EQATECAnalyticsMonitorSettings;
@class EQATECAnalyticsMonitorCapabilities;
@class EQATECAnalyticsMonitorStatus;
@class EQATECStorageDataDescriptor;
@class EQATECProxyConfiguration;


/// The main interface for the analytics monitor which can be obtained with a call to 
/// monitorWithProductId:version: or monitorWithSettings:.
/// The monitor will not collect data before a call to start has been performed.
/// 
/// For more on the features of the EQATEC Analytics service please
/// refer to the [EQATEC Analytics website](http://www.telerik.com/analytics).
///
/// DocSet documentation is available at these URLs:
/// http://api.eqatec.com/analytics/ios/docset/EQATECAnalyticsMonitoriOS.atom
/// http://api.eqatec.com/analytics/macos/docset/EQATECAnalyticsMonitorMacOS.atom
///
@interface EQATECAnalyticsMonitor : NSObject

/// Create an EQATECAnalyticsMonitor instance using the default settings.
///
/// This sample shows how to start the Analytics monitor.
///
///     // Create EQATECAnalyticsMonitor
///     EQATECAnalyticsMonitor *mon = [EQATECAnalyticsMonitor monitorWithProductId:@"YOUR_PRODUCT_KEY_HERE" version:@"1.2.3.4"];
///
///     // Your program here....//
///
///     // Stop monitor
///     [mon stop];
/// 
/// @param productId the product ID in Guid-form, eg "XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX"
/// @param version the product version in numeric form, eg "3.4" or "2.7.332.3451"
/// @return an instance of the EQATECAnalyticsMonitor
+ (EQATECAnalyticsMonitor *)monitorWithProductId:(NSString *)productId version:(NSString *)version;

/// Create an EQATECAnalyticsMonitor instance using the customized settings in the EQATECAnalyticsMonitorSettings instance.
///
/// This sample shows how to start the Analytics monitor.
/// 
///     // Create EQATECAnalyticsMonitor from settings
///     settings = [EQATECAnalyticsMonitorSettings settingsWithProductId:@"YOUR_PRODUCT_KEY_HERE" version:@"1.2.3.4"];
///     mon = [EQATECAnalyticsMonitor monitorWithSettings:settings];
///
///     // Your program here....//
///
///     // Stop monitor
///     [mon stop];
/// 
/// @param settings the settings to use for constructing the monitor
/// @return an instance of the EQATECAnalyticsMonitor
+ (EQATECAnalyticsMonitor *)monitorWithSettings:(EQATECAnalyticsMonitorSettings *)settings;

/// Call to start the monitor. When started the monitor will begin collecting data from the
/// calls and send them asynchronously to the EQATEC Analytics servers on background threads.
/// The start method is non-blocking.
- (void)start;

/// Call to stop the monitor. Call will attempt to save any pending state
/// to the storage and send the final tracking data to the servers. 
/// 
/// This call will attempt to send the final tracking data to the servers on a background thread and
/// by wait for completion of this monitor processing for up to 2 seconds. If you do not want to wait for up to 2 seconds
/// for the completion of this operation, please consider using the overload to this function, stop:.
- (void)stop;

/// Call to stop the monitor. The monitor will attempt to save any pending state
/// to the storage and send the final tracking data to the servers. The waitForCompletion can be specified
/// to allow for the thread to wait for completion of data persistence and transmission. If the monitor cannot complete
/// before the specified time the call will return.
/// 
/// This call will attempt to send the final tracking data to the servers on a background thread and
/// by providing a waitForCompletion timeout you increase the chance that the monitor is able to
/// completion the transmission while the runtime and threadpools are still operational. If no timeout is specified
/// the monitor's background threads and network connections may be removed as part of the process termination and thereby
/// leaving data in the cache to be delivered on the next startup.
///
/// @param waitForCompletion The time to wait for the stop to complete successfully. Use 0 to avoid waiting for completion.
- (void)stopWithTimeout:(NSTimeInterval)waitForCompletion;

/// Call to track an exception that occured in the application.
/// 
/// @param exception The exception to be tracked
- (void)trackException:(NSException *)exception;

/// Call to track an exception that occured in the application.
/// 
/// @param exception The exception to be tracked
/// @param contextMessage Information about the action being performed when the exception occurred in addition to time stamp and exception message, type and stack trace which are logged automatically
- (void)trackException:(NSException *)exception message:(NSString *)contextMessage;

/// Call to track an exception that occured in the application.
/// 
/// @param exception The exception to be tracked
/// @param format A formatting string containing the information about the action being performed when the exception occurred in addition to time stamp and exception message, type and stack trace which are logged automatically
/// @param ... Arguments matching the specified format, in printf-style
- (void)trackException:(NSException *)exception withFormat:(NSString *)format, ...;

/// Call to track an exception that occured in the application.
/// 
/// @param exception The exception to be tracked
/// @param format A formatting string containing the information about the action being performed when the exception occurred in addition to time stamp and exception message, type and stack trace which are logged automatically
/// @param varg va_list containing zero or more objects to format
- (void)trackException:(NSException *)exception withFormat:(NSString *)format arguments:(va_list)varg;

/// Call to imitate that an NSException has occured in the application. This method is only made available
/// to satisfy certain integration scenarios where the monitor is being used in a context where there are
/// no native NSException objects available and the user needs to imitate a real NSException. For instance, when
/// the monitor library is used by a hybrid mobile application written in Javascript, any exceptions that
/// occur in that mobile application will be Javascript-objects and not NSException, and this method can
/// then be used to log the information present in the Javascript-exception-object as if it came from a
/// real NSException object.
///
/// @param type a made-up name for the "type" of exception, e.g. "InvalidArgumentException"
/// @param reason a textual description of the reason for the exception, e.g. "unrecognized key in dictionary"
/// @param stacktrace the location of the error in whatever format makes sense to you, e.g. "MyFunc" or "Main SomeFunc SomeOtherFunc"
/// @param contextMessage Information about the action being performed when the exception occurred, e.g. "while looking up user X"
-(void)trackExceptionRawMessage:(NSString *)type reason:(NSString*)reason stacktrace:(NSString*)stacktrace message:(NSString*)contextMessage;

/// Register a feature usage. Features can be structured in a hieracy using dot-notation.
/// For example use "export" to track all export operations as one, or use "export.html"
/// and "export.pdf" to track exports to html and pdf seperately such that they can be compared.
///
/// Do not, however, use freeform text, such as the name of file being exported to, as the featureName.
/// 
/// @param featureName The name of the feature. If it is null or empty the request is ignored.
- (void)trackFeature:(NSString *)featureName;

/// Register the start of a feature usage. Use this with TrackFeatureStop to track
/// how long a feature is used.
///
/// Features can be structured in a hieracy using dot-notation.
/// For example use "export" to track all export operations as one, or use "export.html"
/// and "export.pdf" to track exports to html and pdf seperately such that they can be compared.
///
/// Do not, however, use freeform text, such as the name of file being exported to, as the featureName.
/// 
/// @param featureName The name of the feature. If it is null and empty the request is ignored.
- (void)trackFeatureStart:(NSString *)featureName;

/// Stops an ongoing timing of a feature from any previous call to trackFeatureStart without
/// registering a timing. Use this call if the feature being tracked did not complete as expected, e.g.
/// was interupted by an exception. The call can safely be made even if no trackFeatureStart has
/// been made.
/// 
/// @param featureName The name of the feature. If it is null and empty the request is ignored.
/// @return total time tracked for this feature or 0 if timing was not tracked
- (NSTimeInterval)trackFeatureStop:(NSString *)featureName;

/// Stops an ongoing timing of a feature from any previous call to trackFeatureStart with similar
/// featureName without
/// registering the time spent. Use this call if the feature being tracked did not complete as expected, e.g.
/// was interupted by an exception. The call can safely be made even if no trackFeatureStart has
/// been made.
/// 
/// @param featureName The name of the feature. If it is null and empty the request is ignored.
- (void)trackFeatureCancel:(NSString *)featureName;

/// Register a value on a specific feature.
/// 
/// @param featureName The name of the feature. If it is null and empty the request is ignored.
/// @param trackedValue The value to track
- (void)trackFeatureValue:(NSString *)featureName value:(long)trackedValue;

/// Explicitly force a synchonization of the current information with the analytics server.
/// This call is not expected to be used in a standard setup but may be helpful in 
/// occasionally connected scenarios. If you created the monitor instance by explicitly setting [EQATECAnalyticsMonitorSettings synchronizeAutomatically]
/// to NO this is how you can force the monitor to synchronize.
- (void)forceSync;

/// Associate an installation ID with the current usage session, and with no associated installation properties.
///
/// @param installationId The installation ID to associate with the current session
- (void)setInstallationInfo:(NSString *)installationId;

/// Associate an installation ID and a dictionary of installation properties with the current usage session.
///
/// @param installationId The installation ID to associate with the current session
/// @param propertyDictionary The dictionary containing the key-value pairs for the installation properties of the current session
- (void)setInstallationInfo:(NSString *)installationId properties:(NSDictionary *)propertyDictionary;

/// Access the current status for the monitor.
@property(readonly) EQATECAnalyticsMonitorStatus *status;

@end


/// Protocol used for receiving log messages from an EQATECAnalyticsMonitor instance. The logging delegate can be
/// specified on the EQATECAnalyticsMonitorSettings object which passed into the
/// [EQATECAnalyticsMonitor monitorWithSettings:] convenience method.
@protocol EQATECLogAnalyticsMonitor <NSObject>

/// Logging a message. This will be called for informative messages internally in the analytics
/// monitor, such as "Monitor started". These are not error messages but messages on specific
/// actions that is being performed.
/// 
/// @param message Describes the action being performed
- (void)didLogMessage:(NSString *)message;


/// Logging an error. This will be called when an error occurs
/// internally in the analytics monitor. The [NSError localizedDescription] will contain
/// a human readable message describing the error.
/// 
/// @param error Describes the error
- (void)didFailWithError:(NSError *)error;

@end


/// A default implementation of the logging interface that will use NSLog. The output
/// can therefore be viewed directly in the XCode output console.
///
/// Example:
/// This sample shows how to create the default logger and use it in the settings.
/// 
///     settings = [EQATECAnalyticsMonitorSettings settingsWithProductId:version]:@"YOUR_PRODUCTID_HERE" version:@"1.2.3"];
///     [settings setLoggingDelegate:[EQATECTraceLogger traceLogger]];
///     [EQATECAnalyticsMonitor monitorWithSettings:settings];
///
@interface EQATECTraceLogger : NSObject <EQATECLogAnalyticsMonitor>

/// Creates an instance of a logger that will print logging output from the monitor using NSLog.
+ (EQATECTraceLogger*)traceLogger;

@end



/// A storage protocol for loading and save data for a given product ID. This protocol can be
/// specified on the EQATECAnalyticsMonitorSettings instance in order to better
/// control where the monitor persists data.
///
/// Creating and utilizing a custom implementation of this interface may be relevant if you require
/// special handling of where the monitor saves data. This could be relevant for e.g. embedded devices
/// or for situation where there is a need to explicitly know where the data is being stored.
@protocol EQATECStorage <NSObject>

/// Save data for a given product ID
/// 
/// @param data The data to save
/// @param descriptor The storage descriptor
- (void)saveSessionData:(NSData*)data ofType:(EQATECStorageDataDescriptor*)descriptor;

/// Returns existing data for the product. If no data is available, implementors should
/// return nil or empty.
/// 
/// @param descriptor The storage descriptor
- (NSData *)savedSessionDataOfType:(EQATECStorageDataDescriptor*)descriptor;

/// Returns any abandoned session data that can be found for a given product.
/// 
/// This method is called repeatedly by the monitor to retrieve old data that has
/// been abandoned from previous sessions from the same product. Abandoned data
/// is consumed by the currently running monitor and delivered to the server. If no
/// abandoned data exists, implementors should return nil or empty.
///
/// @param productId The product ID
- (NSData *)readAbandonedSessionDataForProductId:(NSString *)productId;

@end


/// Defines the storage types
enum
{
  /// Internal policy data
  EQATECStorageDataTypePolicy = 0,

  /// Statistical data
  EQATECStorageDataTypeStatistics = 1,

  /// Session data
  EQATECStorageDataTypeSessionData = 2,
};
typedef NSInteger EQATECStorageDataType;


/// Provides a definition of storage data
@interface EQATECStorageDataDescriptor : NSObject

/// The product id of this data
@property(readonly) NSString *productId;

/// The type of data that is stored
@property(readonly) EQATECStorageDataType datatype;

@end


/// A default implementation of the storage protocol.
@interface EQATECFileStorage : NSObject <EQATECStorage>

/// Creates a new filestorage that stores data in the specified folder. The rootPath
/// parameter must be an absolute file path.
///
/// Make sure that the application has permissions to access the folder. If the folder does not
/// exist the monitor will attempt to create the folder when started.
///
/// @param rootPath The absolute path to the root folder where data should be stored
+ (EQATECFileStorage *)storageWithURL:(NSURL *)rootPath;

/// Creates a new filestorage that stores data in the specified folder and isolates the data using the unique user identification
/// provided. Isolating users can be useful in e.g. multi-user environments such as terminal systems where the
/// users are executing application in the same environment but should their data should be separated.
///
/// Make sure that the application has permissions to access the folder. If the folder does not
/// exist the monitor will attempt to create the folder when started.
///
/// @param rootPath The absolute path to the root folder where data should be stored
/// @param uniqueUserId The identification used to form the path isolation
+ (EQATECFileStorage *)storageWithURL:(NSURL *)rootPath id:(NSString *)uniqueUserId;

@end


// We prefer using well-known Cocoa types in the API (NSString, NSData etc) but the
// location-type struct is in a framework that is not usually included in apps, the
// CoreLocation framework.
// Therefore we duplicate that framework's definition of CLLocationCoordinate2D so it
// is available for API users, regardless of whether they are using the CoreLocation
// framework or not.
#ifndef __CORELOCATION__
typedef double CLLocationDegrees;
typedef struct
{
	CLLocationDegrees latitude;
	CLLocationDegrees longitude;
} CLLocationCoordinate2D;
#endif



/// Class containing the settings used for constructing the EQATECAnalyticsMonitor instance. Instances
/// are preloaded with default settings which can be adjusted before the instance is being passed to 
/// the [EQATECAnalyticsMonitor monitorWithSettings:] convenience method.
@interface EQATECAnalyticsMonitorSettings : NSObject

/// Construct the default settings corresponding to a given productId and version.
///
/// @param productId The product ID in Guid-form, eg "XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX"
/// @param version The product version in numeric form, eg "3.4" or "2.7.332.3451"
+ (EQATECAnalyticsMonitorSettings *)settingsWithProductId:(NSString *)productId version:(NSString *)version;

/// Specifies the ID of the product.
@property(readonly) NSString *productId;

/// Specifies the version of the software, that should be used for version checking.
@property(copy, nonatomic) NSString *version;

/// The logging interface used for exposing internal messages.
/// 
/// You can provide your own implementation of the EQATECLogAnalyticsMonitor interface in 
/// order to receive the internal logging messages from constructed monitors, or you can
/// create a convenient default logger by using [EQATECTraceLogger traceLogger].
@property(retain, nonatomic) id<EQATECLogAnalyticsMonitor> loggingDelegate;

/// The storage interface used internally in the analytics monitor
/// for saving and loading state. 
/// 
/// Consider providing your own implementation of the EQATECStorage interface if
/// your application requires special handling when storing data.
@property(retain, nonatomic) id<EQATECStorage> storageDelegate;

/// The interval with which we autosave the internal statistics. The default
/// is one minute. If set to 0, no autosave is performed.
@property(nonatomic) NSTimeInterval storageSaveInterval;

/// Override the default uri for the server. For most standard purposes there is no
/// need to provide your own uri for the server as the monitor provides a default uri
/// which will contact the server correctly.
/// 
/// You may require to specify this server uri if the network setup for your
/// end users are non-standard. Also be aware that the usesSSL property is
/// is ignored when explicitly specifying the server uri.
@property(copy, nonatomic)  NSString *serverUri;

/// Use this flag to enable the test mode for this installation.
/// This might for example allow you to test version announcements
/// before relasing it to customers.
/// 
/// The precise behavior for the isTestMode property may change over time but
/// is provided to explicitly enable certain test scenarios for developers.
@property(nonatomic) BOOL isTestMode;

/// Use this flag to specify if the monitor automatically should synchronize data 
/// to the server or it should only synchronize manually on explicit calls to [EQATECAnalyticsMonitor forceSync].
/// The default value is YES as the monitor will automatically synchronize data to the
/// server without the clients have to call [EQATECAnalyticsMonitor forceSync].
@property(nonatomic) BOOL synchronizesAutomatically;

/// Explicitly set a limit on the daily network utilization of the monitor. The utilization
/// is accumulated based on the size of the payload for both upstream and downstream data and 
/// is enforce on a daily basis. 
/// 
/// The monitor will not honor a limit lower than 10 kb since the 
/// monitor must be able to contact the server with at least a mimimum of payload. If you do not want the monitor to contact the 
/// server you should not call [EQATECAnalyticsMonitor start] on the monitor instance.
@property(nonatomic) int dailyNetworkUtilizationInKB;

/// Explicitly set a size limit on the data save to persistent storage by the monitor. The size
/// is calculated each time the monitor persists to storage and if the size limit is exceeded it
/// will attempt to persist less data. 
/// 
/// The monitor will not honor a limit lower than 1 kb since the monitor requires to
/// store at least a minimal amount of metadata.
@property(nonatomic) int maxStorageSizeInKB;

/// Used to specify configuration of proxy.
/// The default value is "proxy disabled".
@property(readonly, nonatomic) EQATECProxyConfiguration *proxyConfig;

/// The location of the monitor as GPS coordinates. Use this property if you have access to GPS 
/// coordinates for the location of the application. If provided, these coordinates
/// will be delivered to the servers as part of the data payload.
@property(nonatomic) CLLocationCoordinate2D location;

/// Uses https traffic against the servers unless the serverUri has been explicitly
/// specified to non-https. By default this property is NO.
/// 
/// If the serverUri property has has been specified explicitly this property
/// is ignored. The validation of the certificate from the servers are handled by the underlying
/// operating system. For some platforms this may present a problem since
/// they have limited support for wild-card certificates.
@property(nonatomic) BOOL usesSSL;

@end



/// Exposing the current capabilities of the analytics monitor instance that may influence
/// how the data you pass into the EQATECAnalyticsMonitor instance are handled. 
/// 
/// Note that the capabilities may change at runtime after e.g. interaction with the EQATEC Analytics servers.
@interface EQATECAnalyticsMonitorCapabilities : NSObject

/// Get the maximum allowed length of a log message. Longer messages will be truncated.
@property(readonly) int maxLengthOfLogMessage;

/// Get the maximum allowed size of the context message associated with an exception in a call to
/// [EQATECAnalyticsMonitor trackException:message:]. Longer context messages will be truncated.
@property(readonly) int maxLengthOfExceptionContextMessage;

/// Get the maximum allowed bandwidth utilization for the monitor per day measured in kilobytes. This setting can be
/// altered before constructing the monitor instance by using the [EQATECAnalyticsMonitorSettings dailyNetworkUtilizationInKB]
/// property.
@property(readonly) int maxAllowedBandwidthUsagePerDayInKB;

/// Get the maximum allowed length of a feature name as used in [EQATECAnalyticsMonitor trackFeature:], [EQATECAnalyticsMonitor trackFeatureStart:],
/// [EQATECAnalyticsMonitor trackFeatureStop:] or [EQATECAnalyticsMonitor trackFeatureCancel:].
@property(readonly) int maxLengthOfFeatureName;

/// Get the maximum number of installation properties stored with a given installation id.
@property(readonly) int maxNumberOfInstallationProperties;

/// Get the maximum size of an installation property key.
@property(readonly) int maxKeySizeOfInstallationPropertyKey;

/// Get the maximum size of the data written to storage from the monitor. This size altered before 
/// constructing the monitor instance by using the [EQATECAnalyticsMonitorSettings maxStorageSizeInKB]
/// property.
@property(readonly) int maxStorageSizeInKB;

/// Get the maximum size of the installationid accepted in [EQATECAnalyticsMonitor setInstallationInfo:]. Values
/// that are too long are truncated.
@property(readonly) int maxInstallationIDSize;

@end



/// Enum for the currently known connectivity.
enum
{
  /// No attempts have been made to contact the server so the connectivity
  /// status is unknown at the moment.
  EQATECConnectivityStatusUnknown = 0,

  /// The last attempt at delivering data to the server was succesful.
  EQATECConnectivityStatusConnected = 1,

  /// The last attempt at delivering data to the server was not successful.
  EQATECConnectivityStatusDisconnected = 2,
};
typedef NSInteger EQATECConnectivityStatus;



/// Class encapsulating the current status of an EQATECAnalyticsMonitor instance.
/// 
/// Note that most of these status properties only makes sense if the monitor has been started.
@interface EQATECAnalyticsMonitorStatus : NSObject

/// Get the capabilities of the current analytics monitor. The capabilities instance
/// will allow callers to adjust certain call parameters to not violate the limitations
/// of the current monitor, e.g. to not send log messages that are longer than accepted.
///
/// @see EQATECAnalyticsMonitorCapabilities
@property (readonly) EQATECAnalyticsMonitorCapabilities *capabilities;
  
/// Get whether the monitor is currently started.
@property(readonly) BOOL isStarted;
  
/// Get the total runtime for the monitor. Will return 0 if monitor is not started.
@property(readonly) NSTimeInterval runTime;
  
/// Get the current value of the cookie identifier for the monitor.
/// 
/// Note that this value may be nil if the monitor is not started or if no cookie id has been assigned to this device yet.
@property(readonly) NSString *cookieId;

/// Get the current connectivity status for the monitor. This value will reflect the current internal
/// status of the connectivity of the monitor to the server.
///
/// Note that this status is not a snapshot of general connectivity to the server but merely 
/// reflects the state of the last data delivery attempt to the server. Also note that if the monitor
/// is configured to not synchronize automatically (using the [EQATECAnalyticsMonitorSettings synchronizesAutomatically] property)
/// this status is not updated until the monitor has been explicitly set to synchronize data (using the [EQATECAnalyticsMonitor forceSync] method)
@property(readonly) EQATECConnectivityStatus connectivityStatus;

@end



/// Container for proxy configuration. Apply the proxy configuration on the EQATECAnalyticsMonitorSettings
/// object passed into the [EQATECAnalyticsMonitor monitorWithSettings:] call in order to
/// have the monitor use specific proxy settings.
@interface EQATECProxyConfiguration : NSObject

/// Specify a host name string for the proxy, e.g. "MyProxyServer".
///
/// Default proxy functionality (taken from the underlying OS) is applied if host
/// is null or empty.
@property(copy, nonatomic) NSString *host;

/// Specify a port for the proxy, e.g. 8080.
///
/// Default proxy functionality (taken from the underlying OS) is applied if host
/// is null or empty.
@property(nonatomic) unsigned short port;

/// Specify the user name used in the proxy connection.
/// The system will connect without username/password if userName is null or empty.
@property(copy, nonatomic) NSString *userName;

/// Specify the password used in the proxy connection.
/// The system will connect without username/password if password is null or empty.
@property(copy, nonatomic) NSString *password;

@end





