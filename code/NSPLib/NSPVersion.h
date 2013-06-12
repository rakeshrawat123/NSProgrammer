//
//  NSPVersion.h
//  Library
//
//  Created by Nolan O'Brien on 5/20/13.
//  Copyright (c) 2013 NSProgrammer.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/** NSPVersion is a class for encapsulating version componenets */
@interface NSPVersion : NSObject <NSCoding>

/** init NSPVersion with an empty set of version components (versionComponentCount == 0) */
- (id) init;
/** init NSPVersion with a string decomposed by "." */
- (id) initWithString:(NSString*)versionStr;
/** init NSPVersion with an array of components.  Components will be read as NSNumbers, their integerValue or intValue, or as 0 if they are an object without an integerValue/intValue method */
- (id) initWithComponents:(NSArray*)components;
/** init NSPVersion with 4 version components
    \param major The major version.  The 6 of 6.0.1.2
    \param minor The minor version.  The 0 of 6.0.1.2
    \param revision The revision version.  The 1 of 6.0.1.2
    \param build The build version. The 2 of 6.0.1.2
 */
- (id) initWithMajorVersion:(NSUInteger)major
               minorVersion:(NSUInteger)minor
            revisionVersion:(NSUInteger)revision
               buildVersion:(NSUInteger)build;

/** See initWithString: */
+ (NSPVersion*) versionWithString:(NSString*)versionStr;
/** See initWithComponents: */
+ (NSPVersion*) versionWithComponents:(NSArray*)components;
/** See initWithMajorVersion:minorVersion:revisionVersion:buildVersion: */
+ (NSPVersion*) versionWithMajorVersion:(NSUInteger)major
                           minorVersion:(NSUInteger)minor
                        revisionVersion:(NSUInteger)revision
                           buildVersion:(NSUInteger)build;

/** Convenience static method for getting the application's version 
    \returns an NSPVersion with the application's version */
+ (NSPVersion*) appVersion;

/** \returns An array of NSNumbers representing all of the version components */
@property (nonatomic, strong, readonly) NSArray* versionComponents;

/** \returns the number of version components in the object */
- (NSUInteger) versionComponentCount;
/** \param the index of the version component
    \returns the value of the version component at the provided index.  0 if index is out of bounds. */
- (NSUInteger) versionComponentAtIndex:(NSUInteger)index;
/** \returns the 0th version component */
- (NSUInteger) majorVersion;
/** \returns the 1st version component */
- (NSUInteger) minorVersion;
/** \returns the 2nd version component */
- (NSUInteger) revisionVersion;
/** \returns the 3rd version component */
- (NSUInteger) buildVersion;

/** \returns the string representation of the version (ex// @"6.0.1.2") */
- (NSString*) stringValue;
- (NSString*) description;

/** \param otherVersion the version to compare against
    \returns an NSComparisonResult */
- (NSComparisonResult) compare:(NSPVersion*)otherVersion;
- (BOOL) isEqual:(id)object;
- (BOOL) isLessThan:(NSPVersion*)otherVersion;
- (BOOL) isGreaterThan:(NSPVersion*)otherVersion;
- (BOOL) isLessThanOrEqual:(NSPVersion*)otherVersion;
- (BOOL) isGreaterThanOrEqual:(NSPVersion*)otherVersion;

@end

@interface NSPVersion (OSVersion)
/** Convenience static mehtod for getting the OS' version 
    \returns the OS Version */
+ (NSPVersion*) osVersion;
@end

