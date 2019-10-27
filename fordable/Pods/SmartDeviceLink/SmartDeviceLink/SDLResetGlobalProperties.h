//  SDLResetGlobalProperties.h
//


#import "SDLRPCRequest.h"

#import "SDLGlobalProperty.h"

/**
 * Resets the passed global properties to their default values as defined by
 * SDL
 * <p>
 * The HELPPROMPT global property default value is generated by SDL consists of
 * the first vrCommand of each Command Menu item defined at the moment PTT is
 * pressed<br/>
 * The TIMEOUTPROMPT global property default value is the same as the HELPPROMPT
 * global property default value
 * <p>
 * <b>HMILevel needs to be FULL, LIMITED or BACKGROUND</b>
 * </p>
 *
 * Since SmartDeviceLink 1.0
 * See SetGlobalProperties
 */

NS_ASSUME_NONNULL_BEGIN

@interface SDLResetGlobalProperties : SDLRPCRequest

- (instancetype)initWithProperties:(NSArray<SDLGlobalProperty> *)properties;

/**
 * An array of one or more GlobalProperty enumeration elements
 * indicating which global properties to reset to their default value
 */
@property (strong, nonatomic) NSArray<SDLGlobalProperty> *properties;

@end

NS_ASSUME_NONNULL_END