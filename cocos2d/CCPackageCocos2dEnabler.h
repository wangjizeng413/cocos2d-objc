#import <Foundation/Foundation.h>

@interface CCPackageCocos2dEnabler : NSObject

/**
 *  Enables packages by adding to cocos2d's search path and loading sprite sheets and filename lookups.
 *  Note: This method won't check a package's status and it is meant to be used for initialization
 *  of packages on startup by the CCPackagesManager.
 *
 *  @param packages An array of CCPackage instance to be enabled
 */
- (void)enablePackages:(NSArray *)packages;

/**
 *  Disables packages by removing them fromcocos2d's search path after that reloading sprite sheets and filename lookups
 *  of remaining search paths.
 *  Note: This method won't check a package's status and it is meant to be used for initialization
 *  of packages on startup by the CCPackagesManager.
 *
 *  @param packages An array of CCPackage instance to be disabled
 */
- (void)disablePackages:(NSArray *)array;

@end