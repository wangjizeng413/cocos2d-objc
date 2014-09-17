#import <Foundation/Foundation.h>
#import "CCPackageDownloadDelegate.h"

@class CCPackage;
@protocol CCPackageDownloadManagerDelegate;


@interface CCPackageDownloadManager : NSObject <CCPackageDownloadDelegate>

/**
 *  The download folder path for all downloads
 */
@property (nonatomic, copy) NSString *downloadPath;

/**
 *  If downloads should be resumed if partial downloads found
 *  Default is NO
 */
@property (nonatomic) BOOL resumeDownloads;

/**
 *  If a downloaded file should be overwritten in case the download is started over
 *  Default is NO
 */
@property (nonatomic) BOOL overwriteFinishedDownloads;

/**
 *  Download manager's delegate
 */
@property (nonatomic, weak) id <CCPackageDownloadManagerDelegate> delegate;

/**
 *  Creates a new download for a given package.
 *  A package cannot be enqueued twice as long as it is being downloaded already.
 *
 *  @param package The package that should be downloaded
 */
- (void)enqueuePackageForDownload:(CCPackage *)package;

/**
 *  Cancels a download of a given package. Downloaded file will be deleted.
 *
 *  @param package The package that should be cancelled
 */
- (void)cancelDownloadOfPackage:(CCPackage *)package;

/**
 *  Pause a download of a given package.
 *
 *  @param package The package that should be paused
 */
- (void)pauseDownloadOfPackage:(CCPackage *)package;

/**
 *  Resumes the download of a package given the host accepts range requests.
 *
 *  @param package The package that should be resumed
 */
- (void)resumeDownloadOfPackage:(CCPackage *)package;

/**
 *  Pauses all package downloads already enqueued.
 */
- (void)pauseAllDownloads;

/**
 *  Resumes all package downloads already enqueued.
 */
- (void)resumeAllDownloads;

@end