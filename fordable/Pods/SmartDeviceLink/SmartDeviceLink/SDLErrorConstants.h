//
//  SDLErrorConstants.h
//  SmartDeviceLink-iOS
//
//  Created by Joel Fischer on 8/8/16.
//  Copyright © 2016 smartdevicelink. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Errors associated with the SDLManager class.
 */
typedef NS_ENUM(NSInteger, SDLManagerError) {
    /**
     *  An RPC request failed to send.
     */
    SDLManagerErrorRPCRequestFailed = -1,
    /**
     *  Some action was attempted that requires a connection to the remote head unit.
     */
    SDLManagerErrorNotConnected = -2,
    /**
     *  Some action was attempted before the ready state was reached.
     */
    SDLManagerErrorNotReady = -3,
    /**
     *  The remote system encountered an unknown error.
     */
    SDLManagerErrorUnknownRemoteError = -4,
    /**
     *  One or more of the sub-managers failed to start.
     */
    SDLManagerErrorManagersFailedToStart = -5,
    /**
     *  Registering with the remote system failed.
     */
    SDLManagerErrorRegistrationFailed = -6,
    /**
     *  Registering with the remote system was successful, but had a warning.
     */
    SDLManagerErrorRegistrationSuccessWithWarning = -7,
    /**
     *  Request operations were cancelled before they could be sent
     */
    SDLManagerErrorCancelled = -8
};

/**
 *  Errors associated with the SDLFileManager class.
 */
typedef NS_ENUM(NSInteger, SDLFileManagerError) {
    /**
     *  A file attempted to send, but a file with that name already exists on the remote head unit, and the file was not configured to overwrite.
     */
    SDLFileManagerErrorCannotOverwrite = -1,
    /**
     *  A file was attempted to be accessed but it does not exist.
     */
    SDLFileManagerErrorNoKnownFile = -2,
    /**
     *  The file manager attempted to start but encountered an error.
     */
    SDLFileManagerErrorUnableToStart = -3,
    /**
     *  The file manager was unable to send this file.
     */
    SDLFileManagerErrorUnableToUpload = -4,
    /**
     *  The file manager could not find the local file.
     */
    SDLFileManagerErrorFileDoesNotExist = -5,
    /*
     *  The file upload was canceled.
     */
    SDLFileManagerUploadCanceled = -6,
    /*
     *  One or more of multiple files being uploaded or deleted failed.
     */
    SDLFileManagerMultipleFileUploadTasksFailed = -7,
    /*
     *  One or more of multiple files being uploaded or deleted failed.
     */
    SDLFileManagerMultipleFileDeleteTasksFailed = -8,
    /*
     *  The file data is nil or empty.
     */
    SDLFileManagerErrorFileDataMissing = -9,
    /*
     *  The file is a static icon, which cannot be uploaded
     */
    SDLFileManagerErrorStaticIcon = -10,
};

/**
 Errors associated with the ScreenManager class

 - SDLTextAndGraphicManagerErrorPendingUpdateSuperseded: A pending update was superseded by a newer requested update. The old update will not be sent
 */
typedef NS_ENUM(NSInteger, SDLTextAndGraphicManagerError) {
    SDLTextAndGraphicManagerErrorPendingUpdateSuperseded = -1
};

/**
 Errors associated with the ScreenManager class

 - SDLSoftButtonManagerErrorPendingUpdateSuperseded: A pending update was superseded by a newer requested update. The old update will not be sent
 */
typedef NS_ENUM(NSInteger, SDLSoftButtonManagerError) {
    SDLSoftButtonManagerErrorPendingUpdateSuperseded = -1
};

/**
 Errors associated with the ScreenManager class

 - SDLMenuManagerErrorRPCsFailed: Sending menu-related RPCs returned an error from the remote system
 */
typedef NS_ENUM(NSInteger, SDLMenuManagerError) {
    SDLMenuManagerErrorRPCsFailed = -1
};

typedef NS_ENUM(NSInteger, SDLChoiceSetManagerError) {
    SDLChoiceSetManagerErrorPendingPresentationDeleted = -1,
    SDLChoiceSetManagerErrorDeletionFailed = -2,
    SDLChoiceSetManagerErrorUploadFailed = -3,
    SDLChoiceSetManagerErrorFailedToCreateMenuItems = -4,
    SDLChoiceSetManagerErrorInvalidState = -5
};

/**
 *  Errors associated with transport.
 */
typedef NS_ENUM(NSInteger, SDLTransportError) {
    /**
     *  Connection cannot be established due to a reason not listed here.
     */
    SDLTransportErrorUnknown = -1,
    /**
     *  TCP connection is refused.
     *  Probably specified port number is invalid, or SDL Core is not running on the head unit.
     */
    SDLTransportErrorConnectionRefused = -2,
    /**
     *  TCP connection cannot be established within given time.
     *  Probably because of wrong IP address, or the connection may be blocked by a firewall.
     */
    SDLTransportErrorConnectionTimedOut = -3,
    /**
     *  TCP connection cannot be established since network is down.
     *  Probably the phone is not connected to the correct network.
     */
    SDLTransportErrorNetworkDown = -4,
};

/**
 *  Errors associated with store.
 */
typedef NS_ENUM(NSInteger, SDLRPCStoreError) {
    /**
     *  In dictionary stored value with unexpected type
     */
    SDLRPCStoreErrorGetInvalidObject = -1,
};
